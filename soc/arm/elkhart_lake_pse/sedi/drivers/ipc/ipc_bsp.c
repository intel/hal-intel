/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "ipc_bsp.h"
#include "pm/pm_internal_if.h"
#include <sedi.h>
#include <sedi_driver_ipc.h>

#define SEDI_SIDEBAND_PMC SEDI_SIDEBAND_0

/*driver version*/
static const sedi_driver_version_t driver_version = { SEDI_IPC_API_VERSION,
						      SEDI_IPC_DRIVER_VERSION };

/*ipc resource information */
typedef struct {
	ipc_reg_t *reg_base_addr;
	vnn_id_t read_vnn;
	vnn_id_t write_vnn;
} ipc_resource_t;

/*ipc runtime context information */
typedef struct {
	bool initialized;
	sedi_ipc_event_cb_t cb_event;   /*event callback*/
	uint32_t in_msg_count;          /* for debug usage*/
	uint32_t out_msg_count;         /* for debug usage*/
	void *usr_params;               /* user parameters for event callback*/
					/*other private runtime data*/
} ipc_context_t;

static sedi_ipc_capabilities_t driver_capabilities[SEDI_IPC_NUM] = { 0 };

static const ipc_resource_t ipc_resource[SEDI_IPC_NUM] = {
	{ .reg_base_addr = (ipc_reg_t *)IPC_HOST_BASE,
	  .read_vnn = VNN_ID_IPC_HOST_R,
	  .write_vnn = VNN_ID_IPC_HOST_W },
	{ .reg_base_addr = (ipc_reg_t *)IPC_CSME_BASE,
	  .read_vnn = VNN_ID_IPC_CSE_R,
	  .write_vnn = VNN_ID_IPC_CSE_W },
	{ .reg_base_addr = (ipc_reg_t *)IPC_PMC_BASE,
	  .read_vnn = VNN_ID_IPC_PMC_R,
	  .write_vnn = VNN_ID_IPC_PMC_W }
};

/*driver contexts */
static ipc_context_t ipc_contexts[SEDI_IPC_NUM] = { 0 };

static int32_t check_ipc_available(IN sedi_ipc_t ipc_device)
{
	DBG_CHECK(ipc_device < SEDI_IPC_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	if (!ipc_contexts[ipc_device].initialized) {
		return SEDI_DRIVER_ERROR;
	}
	return SEDI_DRIVER_OK;
}

/********** IPC driver API implementation ***********/

sedi_driver_version_t sedi_ipc_get_version(void)
{
	return driver_version;
}

int32_t sedi_ipc_get_capabilities(IN sedi_ipc_t ipc_device,
				  INOUT sedi_ipc_capabilities_t *cap)
{
	DBG_CHECK(ipc_device < SEDI_IPC_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	/* IPC is always available to PSE*/
	driver_capabilities[ipc_device].is_available = 1;
	*cap = driver_capabilities[ipc_device];
	return SEDI_DRIVER_OK;
}
int32_t sedi_ipc_init(IN sedi_ipc_t ipc_device, IN sedi_ipc_event_cb_t cb,
		      INOUT void *param)
{
	DBG_CHECK(ipc_device < SEDI_IPC_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;
	vnn_id_t write_vnn = ipc_resource[ipc_device].write_vnn;

	ipc_contexts[ipc_device].initialized = false;
	ipc_contexts[ipc_device].cb_event = cb;
	ipc_contexts[ipc_device].usr_params = param;
	ipc_contexts[ipc_device].in_msg_count = 0;
	ipc_contexts[ipc_device].out_msg_count = 0;

	if (ipc_device == SEDI_IPC_PMC) {
		sedi_sideband_init(SEDI_SIDEBAND_PMC);
	}
	if ((regs->drbl_out & BIT(IPC_BUSY_BIT)) != 0) {
		regs->pimr_out &= ~BIT(IPC_INT_MASK_OUT_BIT);
		PM_VNN_DRIVER_REQ(write_vnn);
		regs->drbl_out = 0;
		PM_VNN_DRIVER_DEREQ(write_vnn);
	}
	ipc_contexts[ipc_device].initialized = true;

	if (regs->ipc_busy_clear_lh2ose) {
		/*set 1 to clear this interrupt*/
		regs->ipc_busy_clear_lh2ose = 1;
	}
	/* Enable Msg in, busyClean and out Interrupt */
	regs->pimr_in |= BIT(IPC_INT_MASK_IN_BIT) | BIT(IPC_INT_MASK_BC_BIT);
	regs->pimr_out |= BIT(IPC_INT_MASK_OUT_BIT);

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_uninit(IN sedi_ipc_t ipc_device)
{
	DBG_CHECK(ipc_device < SEDI_IPC_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;

	/* disable Msg in, busyClean and out Interrupt  */
	regs->pimr_in &= ~(BIT(IPC_INT_MASK_IN_BIT) | BIT(IPC_INT_MASK_BC_BIT));
	regs->pimr_out &= ~BIT(IPC_INT_MASK_OUT_BIT);

	ipc_contexts[ipc_device].cb_event = NULL;
	ipc_contexts[ipc_device].initialized = false;
	if (ipc_device == SEDI_IPC_PMC) {
		sedi_sideband_uninit(SEDI_SIDEBAND_PMC);
	}
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_set_power(IN sedi_ipc_t ipc_device,
			   IN sedi_power_state_t state)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);

	/* TODO: Add power control implementation after power flow is ok */
	PARAM_UNUSED(state);

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_write_msg(IN sedi_ipc_t ipc_device, IN uint8_t *msg,
			   IN int32_t size)
{
	int ret, i;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);

	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;

	DBG_CHECK((size <= IPC_DATA_LEN_MAX) && (size >= 0),
		  SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(msg != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	if (ipc_device == SEDI_IPC_HOST) {
		/* write data in 32-bit*/
		for (i = 0; i < (size >> 2); i++) {
			*((uint32_t *)regs->msgs_out + i) =
				*((uint32_t *)msg + i);
		}
		/* write data in 8-bit for the rest*/
		for (i = ((size >> 2) << 2); i < size; i++) {
			regs->msgs_out[i] = msg[i];
		}
	} else if (ipc_device == SEDI_IPC_PMC) {
		for (i = 0; i < size; i = i + 4) {
			sedi_sideband_send(SEDI_SIDEBAND_PMC, SB_PMC,
					   SEDI_SIDEBAND_ACTION_WRITE,
					   IPC_REG_SB_OSE2PMC_MSG + i,
					   *((uint32_t *)(msg + i)));
		}
	}
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_write_dbl(IN sedi_ipc_t ipc_device, IN uint32_t doorbell)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);
	vnn_id_t write_vnn = ipc_resource[ipc_device].write_vnn;

	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;

	if (ipc_device == SEDI_IPC_PMC) {
		regs->drbl_out = doorbell;
		sedi_sideband_send(SEDI_SIDEBAND_PMC, SB_PMC,
				   SEDI_SIDEBAND_ACTION_WRITE,
				   IPC_REG_SB_OSE2PMC_DRBL, doorbell);
	} else if (ipc_device == SEDI_IPC_HOST) {
		PM_VNN_DRIVER_REQ(write_vnn);
		regs->drbl_out = doorbell;
		if (!(doorbell & BIT(IPC_BUSY_BIT))) {
			PM_VNN_DRIVER_DEREQ(write_vnn);
		}
	}

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_msg(IN sedi_ipc_t ipc_device, OUT uint8_t *msg,
			  IN int32_t size)
{
	int ret, i;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);

	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;

	DBG_CHECK((size <= IPC_DATA_LEN_MAX) && (size >= 0),
		  SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(msg != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	/* read data in 32-bit*/
	for (i = 0; i < (size >> 2); i++) {
		*((uint32_t *)msg + i) = *((uint32_t *)regs->msgs_in + i);
	}
	/* read data in 8-bit for the rest*/
	for (i = ((size >> 2) << 2); i < size; i++) {
		msg[i] = regs->msgs_in[i];
	}
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_dbl(IN sedi_ipc_t ipc_device, OUT uint32_t *doorbell)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);

	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;
	*doorbell = regs->drbl_in;
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_send_ack_drbl(IN sedi_ipc_t ipc_device, IN uint32_t ack)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);

	if (ack & BIT(IPC_BUSY_BIT)) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;
	vnn_id_t read_vnn = ipc_resource[ipc_device].read_vnn;

	regs->drbl_in = ack;
	if (ipc_device == SEDI_IPC_PMC) {
		sedi_sideband_send(SEDI_SIDEBAND_PMC, SB_PMC,
				   SEDI_SIDEBAND_ACTION_WRITE,
				   IPC_REG_SB_PMC2OSE_DRBL_MIRROR, ack);
	}
	if (ipc_device == SEDI_IPC_HOST) {
		PM_VNN_DRIVER_DEREQ(read_vnn);
	}
	regs->pimr_in |= BIT(IPC_INT_MASK_IN_BIT);
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_ack_drbl(IN sedi_ipc_t ipc_device, OUT uint32_t *ack)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);
	DBG_CHECK(ack != NULL, ret);
	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;

	*ack = regs->drbl_out;

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_send_ack_msg(IN sedi_ipc_t ipc_device, IN uint8_t *msg,
			      IN int32_t size)
{
	int ret, i;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);

	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;

	DBG_CHECK((size <= IPC_DATA_LEN_MAX) && (size >= 0),
		  SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(msg != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	/* write data in 32-bit*/
	for (i = 0; i < (size >> 2); i++) {
		*((uint32_t *)regs->msgs_in + i) = *((uint32_t *)msg + i);
	}
	/* write data in 8-bit for the rest*/
	for (i = ((size >> 2) << 2); i < size; i++) {
		regs->msgs_in[i] = msg[i];
	}
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_ack_msg(IN sedi_ipc_t ipc_device, OUT uint8_t *msg,
			      IN int32_t size)
{
	int ret, i;

	ret = check_ipc_available(ipc_device);
	DBG_CHECK(ret == SEDI_DRIVER_OK, ret);

	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;

	DBG_CHECK((size <= IPC_DATA_LEN_MAX) && (size >= 0),
		  SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(msg != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	if (ipc_device == SEDI_IPC_HOST) {
		/* read data in 32-bit*/
		for (i = 0; i < (size >> 2); i++) {
			*((uint32_t *)msg + i) =
				*((uint32_t *)regs->msgs_out + i);
		}
		/* read data in 8-bit for the rest*/
		for (i = ((size >> 2) << 2); i < size; i++) {
			msg[i] = regs->msgs_out[i];
		}
	} else if (ipc_device == SEDI_IPC_PMC) {
		for (i = 0; i < size; i = i + 4) {
			sedi_sideband_send(SEDI_SIDEBAND_PMC, SB_PMC,
					   SEDI_SIDEBAND_ACTION_READ,
					   IPC_REG_SB_OSE2PMC_MSG + i, 0);
			sedi_sideband_wait_ack(SEDI_SIDEBAND_PMC, SB_PMC,
					       SEDI_SIDEBAND_ACTION_READ,
					       (uint32_t *)(msg + i));
		}
	}

	return SEDI_DRIVER_OK;
}
/* IPC ISR process function */

void sedi_ipc_isr(IN sedi_ipc_t ipc_device)
{
	int ret;
	uint32_t host_sts;
	volatile ipc_reg_t *regs = ipc_resource[ipc_device].reg_base_addr;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return;
	}
	if ((regs->pisr_in & BIT(IPC_INT_STAT_BIT)) &&
	    (regs->pimr_in & BIT(IPC_INT_MASK_IN_BIT))) {
		regs->pimr_in &= ~BIT(IPC_INT_MASK_IN_BIT);
		if (ipc_device == SEDI_IPC_HOST) {
			PM_VNN_DRIVER_REQ(ipc_resource[ipc_device].read_vnn);
		}
		if (ipc_contexts[ipc_device].cb_event) {
			ipc_contexts[ipc_device].in_msg_count++;
			ipc_contexts[ipc_device].cb_event(
				ipc_device, SEDI_IPC_EVENT_MSG_IN,
				ipc_contexts[ipc_device].usr_params);
		}
	}

	if (regs->ipc_busy_clear_lh2ose) {
		/*set 1 to clear this interrupt*/
		regs->ipc_busy_clear_lh2ose = 1;
		if ((ipc_contexts[ipc_device].initialized == true) &&
		    (ipc_contexts[ipc_device].cb_event)) {
			ipc_contexts[ipc_device].out_msg_count++;
			ipc_contexts[ipc_device].cb_event(
				ipc_device, SEDI_IPC_EVENT_MSG_PEER_ACKED,
				ipc_contexts[ipc_device].usr_params);
		}
		if (ipc_device == SEDI_IPC_HOST) {
			PM_VNN_DRIVER_DEREQ(ipc_resource[ipc_device].write_vnn);
		}
	}
	if (ipc_device == SEDI_IPC_HOST) {
		host_sts = read32(IPC_HOST_BASE + IPC_D0I3C_REG);
		if (host_sts & BIT(IPC_D0I3C_INT_BIT)) {
			write32(IPC_HOST_BASE + IPC_D0I3C_REG,
				host_sts);
			if (host_sts & BIT(IPC_D0I3C_STATUS_BIT)) {
				pm_set_s0ix_event(1);
			} else {
				pm_set_s0ix_event(0);
			}
		}
	}
}

sedi_dev_ownership_t sedi_get_dev_ownership(sedi_dev_table_t dev)
{
	DBG_CHECK(dev < PSE_DEV_MAX, NO_SUCH_DEV);

	uint8_t field;
	uint32_t reg_addr = IPC_HOST_BASE + IPC_OWNERSHIP_REG_OFFSET +
			    (dev >> IPC_OWNERSHIP_DEV_OFF);
	uint8_t reg = read8(reg_addr);

	if (dev & IPC_OWNERSHIP_DEV_MSK) {
		field = reg >> IPC_OWNERSHIP_BIT_FILED_LEN;
	} else {
		field = reg;
	}

	/* IPC always belongs to HOST*/
	if (dev == PSE_DEV_LHIPC) {
		field &= (~IPC_OWNERSHIP_OWNER_MASK);
		field |= IPC_DEV_OWNED_BY_HOST_BITS;
	}

	switch (field & IPC_OWNERSHIP_OWNER_MASK) {
	case IPC_DEV_OWNED_BY_PSE_BITS:
		return DEV_PSE_OWNED;
	case IPC_DEV_OWNED_BY_HOST_BITS:
		if ((field & IPC_OWNERSHIP_INTR_MASK) == IPC_HOST_DEV_MSI_INT) {
			return DEV_LH_OWNED_MSI;
		} else {
			return DEV_LH_OWNED_SB;
		}
	default:
		return DEV_NO_OWNER;
	}

	/* never run here */
	return NO_SUCH_DEV;
}
