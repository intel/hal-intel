/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sedi_driver_core.h"
#include <sedi_driver_common.h>
#include <sedi_ipc_regs.h>
#include <sedi_driver_ipc.h>

#define SEDI_IPC_API_VERSION 0
/* driver version */
#define SEDI_IPC_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

#define IPC_REG_SB_LOCAL2PMC_DRBL 0x1804
#define IPC_REG_SB_LOCAL2PMC_MSG 0x1808
#define IPC_REG_SB_PMC2LOCAL_DRBL_MIRROR 0x1888
#define IPC_REG_SB_PMC2LOCAL_DRBL_MIRROR 0x1888

#define IPC_REG_SB_LOCAL2CSE_CSR 0x3c
#define IPC_REG_SB_LOCAL2CSE_DRBL 0x0
#define IPC_REG_SB_LOCAL2CSE_MSG 0x40
#define IPC_REG_SB_CSE2LOCAL_DRBL_MIRROR 0x4

#ifdef SEDI_SB_SUPPORT
#define SEDI_SIDEBAND_PMC SEDI_SIDEBAND_0
#define SEDI_SIDEBAND_CSE SEDI_SIDEBAND_0
#endif

/*driver version*/
static const sedi_driver_version_t driver_version = { SEDI_IPC_API_VERSION,
						      SEDI_IPC_DRIVER_VERSION };
/* sideband params for non-host interfaces */
#ifdef SEDI_SB_SUPPORT
typedef struct {
	sedi_sideband_t dev;
	sb_port_t port;
	uint32_t csr_peer_addr;
	uint32_t drbl_peer_addr;
	uint32_t msg_peer_addr;
	uint32_t drbl_mirror_peer_addr;
} sideband_param_t;
#else
typedef struct {
} sideband_param_t;
#endif

/* ipc resource information */
typedef struct {
	sedi_ipc_regs_t *reg_base_addr;
	vnn_id_t read_vnn;
	vnn_id_t write_vnn;
	sideband_param_t *sb;
} ipc_resource_t;

/*ipc runtime context information */
typedef struct {
	bool initialized;
	uint32_t csr_saved;
	sedi_ipc_event_cb_t cb_event; /*event callback*/
	uint32_t in_msg_count; /* for debug usage*/
	uint32_t out_msg_count; /* for debug usage*/
	/* user parameters for event callback other private runtime data*/
	void *usr_params;
} ipc_context_t;

static sedi_ipc_capabilities_t driver_capabilities[SEDI_IPC_NUM] = { 0 };

#ifdef SEDI_SB_SUPPORT
static sideband_param_t pmc_sb = { .dev = SEDI_SIDEBAND_PMC,
				   .port = SB_PMC,
				   .csr_peer_addr = IPC_REG_SB_LOCAL2PMC_CSR,
				   .drbl_peer_addr = IPC_REG_SB_LOCAL2PMC_DRBL,
				   .msg_peer_addr = IPC_REG_SB_LOCAL2PMC_MSG,
				   .drbl_mirror_peer_addr = IPC_REG_SB_PMC2LOCAL_DRBL_MIRROR };
static sideband_param_t cse_sb = { .dev = SEDI_SIDEBAND_CSE,
				   .port = SB_CSME,
				   .csr_peer_addr = IPC_REG_SB_LOCAL2CSE_CSR,
				   .drbl_peer_addr = IPC_REG_SB_LOCAL2CSE_DRBL,
				   .msg_peer_addr = IPC_REG_SB_LOCAL2CSE_MSG,
				   .drbl_mirror_peer_addr = IPC_REG_SB_CSE2LOCAL_DRBL_MIRROR };
#endif

static const ipc_resource_t ipc_resource[SEDI_IPC_NUM] = {
#ifdef SEDI_SB_SUPPORT
	{ .reg_base_addr = (sedi_ipc_regs_t *)SEDI_REG_BASE(IPC_HOST),
	  .read_vnn = VNN_ID_IPC_HOST_R,
	  .write_vnn = VNN_ID_IPC_HOST_W,
	  .sb = NULL },
	{ .reg_base_addr = (sedi_ipc_regs_t *)SEDI_REG_BASE(IPC_CSME),
	  .read_vnn = VNN_ID_IPC_CSE_R,
	  .write_vnn = VNN_ID_IPC_CSE_W,
	  .sb = &cse_sb },
	{ .reg_base_addr = (sedi_ipc_regs_t *)SEDI_REG_BASE(IPC_PMC),
	  .read_vnn = VNN_ID_IPC_PMC_R,
	  .write_vnn = VNN_ID_IPC_PMC_W,
	  .sb = &pmc_sb },
#else
	{ .reg_base_addr = (sedi_ipc_regs_t *)SEDI_REG_BASE(IPC_HOST),
	  .read_vnn = VNN_ID_IPC_HOST_R,
	  .write_vnn = VNN_ID_IPC_HOST_W },
	{ .reg_base_addr = (sedi_ipc_regs_t *)SEDI_REG_BASE(IPC_CSME),
	  .read_vnn = VNN_ID_IPC_CSE_R,
	  .write_vnn = VNN_ID_IPC_CSE_W },
	{ .reg_base_addr = (sedi_ipc_regs_t *)SEDI_REG_BASE(IPC_PMC),
	  .read_vnn = VNN_ID_IPC_PMC_R,
	  .write_vnn = VNN_ID_IPC_PMC_W },
#endif
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

int32_t sedi_ipc_get_capabilities(IN sedi_ipc_t ipc_device, INOUT sedi_ipc_capabilities_t *cap)
{
	DBG_CHECK(ipc_device < SEDI_IPC_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	/* IPC is always available */
	driver_capabilities[ipc_device].is_available = 1;
	*cap = driver_capabilities[ipc_device];
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_init(IN sedi_ipc_t ipc_device, IN sedi_ipc_event_cb_t cb, INOUT void *param)
{
	DBG_CHECK(ipc_device < SEDI_IPC_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;
	vnn_id_t write_vnn = ipc_resource[ipc_device].write_vnn;

	ipc_contexts[ipc_device].initialized = false;
	ipc_contexts[ipc_device].csr_saved = 0;
	ipc_contexts[ipc_device].cb_event = cb;
	ipc_contexts[ipc_device].usr_params = param;
	ipc_contexts[ipc_device].in_msg_count = 0;
	ipc_contexts[ipc_device].out_msg_count = 0;

#ifdef SEDI_SB_SUPPORT
	sideband_param_t *sb = ipc_resource[ipc_device].sb;

	if (sb) {
		sedi_sideband_init(sb->dev);
	}
#endif
	if (SEDI_PREG_RBFV_IS_SET(IPC, ISH2AGENT_DOORBELL_AGENT, BUSY, 1,
				&regs->ish2agent_doorbell_agent)) {
		PM_VNN_DRIVER_REQ(write_vnn);
		SEDI_PREG_RBFV_SET(IPC, ISH2AGENT_DOORBELL_AGENT, BUSY, 0,
				&regs->ish2agent_doorbell_agent);
		PM_VNN_DRIVER_DEREQ(write_vnn);
	}
	ipc_contexts[ipc_device].initialized = true;

	if (SEDI_PREG_RBFV_IS_SET(IPC, ISH_IPC_BUSY_CLEAR_AGENT,
				ISH2AGENT_BUSY_CLEAR, 1,
				&regs->ish_ipc_busy_clear_agent)) {
		/*set 1 to clear this interrupt*/
		SEDI_PREG_RBFV_SET(IPC, ISH_IPC_BUSY_CLEAR_AGENT,
				ISH2AGENT_BUSY_CLEAR, 1, &regs->ish_ipc_busy_clear_agent);
	}
	/* Enable Msg in, busyClean and out Interrupt */
	SEDI_PREG_RBFV_SET(IPC, PIMR_AGENT2ISH, AGENT2ISH_DB, 1, &regs->pimr_agent2ish);
	SEDI_PREG_RBFV_SET(IPC, PIMR_AGENT2ISH, ISH2AGENT_BC, 1, &regs->pimr_agent2ish);
	SEDI_PREG_RBFV_SET(IPC, PIMR_ISH2AGENT, ISH2AGENT_DB, 1, &regs->pimr_ish2agent);
	SEDI_PREG_RBFV_SET(IPC, CIM_AGENT, CH_INTR_MASK, 0, &regs->cim_agent);

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_uninit(IN sedi_ipc_t ipc_device)
{
	DBG_CHECK(ipc_device < SEDI_IPC_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;

	/* disable Msg in, busyClean and out Interrupt  */
	SEDI_PREG_RBFV_SET(IPC, PIMR_AGENT2ISH, AGENT2ISH_DB, 0, &regs->pimr_agent2ish);
	SEDI_PREG_RBFV_SET(IPC, PIMR_AGENT2ISH, ISH2AGENT_BC, 0, &regs->pimr_agent2ish);

	ipc_contexts[ipc_device].cb_event = NULL;
	ipc_contexts[ipc_device].initialized = false;
#ifdef SEDI_SB_SUPPORT
	sideband_param_t *sb = ipc_resource[ipc_device].sb;

	if (sb) {
		sedi_sideband_uninit(sb->dev);
	}
#endif
	return SEDI_DRIVER_OK;
}

/*
 * IPC is an always-on IP, no power operation available for IPC,
 * keep API for future
 */
int32_t sedi_ipc_set_power(IN sedi_ipc_t ipc_device, IN sedi_power_state_t state)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	PARAM_UNUSED(state);

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_write_msg(IN sedi_ipc_t ipc_device, IN uint8_t *msg, IN int32_t size)
{
	int ret, i;
	uint32_t tail = 0;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;
	sideband_param_t *sb = ipc_resource[ipc_device].sb;

	DBG_CHECK((size <= IPC_DATA_LEN_MAX) && (size >= 0), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(msg != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	if (sb) {
#ifdef SEDI_SB_SUPPORT
		/* for CSE and PMC, use sideband */
		for (i = 0; i < size; i = i + 4) {
			sedi_sideband_send(sb->dev, sb->port, SEDI_SIDEBAND_ACTION_WRITE,
					   sb->msg_peer_addr + i, *((uint32_t *)(msg + i)));
		}
#endif
	} else {
		/* write data in 32-bit*/
		for (i = 0; i < (size >> 2); i++) {
			regs->ish2agent_msg_agent[i] = *((uint32_t *)msg + i);
		}
		/* write data in 8-bit for the rest*/
		if (size % sizeof(uint32_t)) {
			for (i = ((size >> 2) << 2); i < size; i++) {
				tail += msg[i] << ((i % 4) << 3);
			}
			regs->ish2agent_msg_agent[size >> 2] = tail;
		}
	}
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_write_dbl(IN sedi_ipc_t ipc_device, IN uint32_t doorbell)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	vnn_id_t write_vnn = ipc_resource[ipc_device].write_vnn;
	sideband_param_t *sb = ipc_resource[ipc_device].sb;
	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;

	if (sb) {
		regs->ish2agent_doorbell_agent = doorbell;
#ifdef SEDI_SB_SUPPORT
		sedi_sideband_send(sb->dev, sb->port, SEDI_SIDEBAND_ACTION_WRITE,
				   sb->drbl_peer_addr, doorbell);
#endif
	} else {
		/* IPC to HOST */
		PM_VNN_DRIVER_REQ(write_vnn);
		regs->ish2agent_doorbell_agent = doorbell;
		if (SEDI_PREG_RBFV_IS_SET(IPC, ISH2AGENT_DOORBELL_AGENT, BUSY, 0,
					(uint32_t *)&doorbell)) {
			PM_VNN_DRIVER_DEREQ(write_vnn);
		}
	}

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_write_csr(IN sedi_ipc_t ipc_device, IN uint32_t csr)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	sideband_param_t *sb = ipc_resource[ipc_device].sb;

	if (sb) {
#ifdef SEDI_SB_SUPPORT
		sedi_sideband_send(sb->dev, sb->port, SEDI_SIDEBAND_ACTION_WRITE, sb->csr_peer_addr,
				   csr);
#endif
	}

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_csr(IN sedi_ipc_t ipc_device, OUT uint32_t *csr)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	if (csr) {
		*csr = ipc_contexts[ipc_device].csr_saved;
	} else {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_msg(IN sedi_ipc_t ipc_device, OUT uint8_t *msg, IN int32_t size)
{
	int ret, i;
	uint32_t tail = 0;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;

	DBG_CHECK((size <= IPC_DATA_LEN_MAX) && (size >= 0), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(msg != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	/* read data in 32-bit*/
	for (i = 0; i < (size >> 2); i++) {
		*((uint32_t *)msg + i) = regs->agent2ish_msg_agent[i];
	}

	/* read data in 8-bit for the rest*/
	if (size % sizeof(uint32_t)) {
		tail = regs->agent2ish_msg_agent[size >> 2];
	}
	for (i = ((size >> 2) << 2); i < size; i++) {
		msg[i] = *((uint8_t *)&tail + i % sizeof(uint32_t));
	}
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_dbl(IN sedi_ipc_t ipc_device, OUT uint32_t *doorbell)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;
	*doorbell = regs->agent2ish_doorbell_agent;
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_send_ack_drbl(IN sedi_ipc_t ipc_device, IN uint32_t ack)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	sideband_param_t *sb = ipc_resource[ipc_device].sb;

	if (SEDI_PREG_RBFV_IS_SET(IPC, ISH2AGENT_DOORBELL_AGENT, BUSY, 1, (uint32_t *)&ack)) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;
	vnn_id_t read_vnn = ipc_resource[ipc_device].read_vnn;

	regs->agent2ish_doorbell_agent = ack;
	if (sb) {
#ifdef SEDI_SB_SUPPORT
		/* the peer is PMC or CSE */
		sedi_sideband_send(sb->dev, sb->port, SEDI_SIDEBAND_ACTION_WRITE,
				   sb->drbl_mirror_peer_addr, ack);
#endif
	} else {
		/* the peer is host */
		PM_VNN_DRIVER_DEREQ(read_vnn);
	}
	SEDI_PREG_RBFV_SET(IPC, PIMR_AGENT2ISH, AGENT2ISH_DB, 1, &regs->pimr_agent2ish);
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_ack_drbl(IN sedi_ipc_t ipc_device, OUT uint32_t *ack)
{
	int ret;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	DBG_CHECK(ack != NULL, ret);
	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;

	*ack = regs->ish2agent_doorbell_agent;

	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_send_ack_msg(IN sedi_ipc_t ipc_device, IN uint8_t *msg, IN int32_t size)
{
	int ret, i;
	uint32_t tail = 0;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;

	DBG_CHECK((size <= IPC_DATA_LEN_MAX) && (size >= 0), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(msg != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	/* write data in 32-bit*/
	for (i = 0; i < (size >> 2); i++) {
		regs->agent2ish_msg_agent[i] = *((uint32_t *)msg + i);
	}
	/* write data in 8-bit for the rest*/
	if (size % sizeof(uint32_t)) {
		for (i = ((size >> 2) << 2); i < size; i++) {
			tail += msg[i] << ((i % 4) << 3);
		}
		regs->agent2ish_msg_agent[size >> 2] = tail;
	}
	return SEDI_DRIVER_OK;
}

int32_t sedi_ipc_read_ack_msg(IN sedi_ipc_t ipc_device, OUT uint8_t *msg, IN int32_t size)
{
	int ret, i;
	uint32_t tail;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;

	DBG_CHECK((size <= IPC_DATA_LEN_MAX) && (size >= 0), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(msg != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	if (ipc_device == SEDI_IPC_HOST) {
		/* read data in 32-bit*/
		for (i = 0; i < (size >> 2); i++) {
			*((uint32_t *)msg + i) = regs->ish2agent_msg_agent[i];
		}
		/* read data in 8-bit for the rest*/
		if (size % sizeof(uint32_t)) {
			tail = regs->ish2agent_msg_agent[size >> 2];
		}
		for (i = ((size >> 2) << 2); i < size; i++) {
			msg[i] = *((uint8_t *)&tail + i % sizeof(uint32_t));
		}
	} else {
#ifdef SEDI_SB_SUPPORT
		sideband_param_t *sb = ipc_resource[ipc_device].sb;

		for (i = 0; i < size; i = i + 4) {
			sedi_sideband_send(sb->dev, sb->port, SEDI_SIDEBAND_ACTION_READ,
					   sb->msg_peer_addr + i, 0);
			sedi_sideband_wait_ack(sb->dev, sb->port, SEDI_SIDEBAND_ACTION_READ,
					       (uint32_t *)(msg + i));
		}
#endif
	}

	return SEDI_DRIVER_OK;
}
/* IPC ISR process function */

void sedi_ipc_isr(IN sedi_ipc_t ipc_device)
{
	int ret;
	volatile sedi_ipc_regs_t *regs = ipc_resource[ipc_device].reg_base_addr;

	ret = check_ipc_available(ipc_device);
	if (ret != SEDI_DRIVER_OK) {
		return;
	}

	/* check whether it is an inbound interrupt*/
	if (SEDI_PREG_RBFV_IS_SET(IPC, PISR_AGENT2ISH, AGENT2ISH_DB, 1, &regs->pisr_agent2ish) &&
			SEDI_PREG_RBFV_IS_SET(IPC, PIMR_AGENT2ISH, AGENT2ISH_DB, 1,
				&regs->pimr_agent2ish)) {
		/* mask interrupts before ack */
		SEDI_PREG_RBFV_SET(IPC, PIMR_AGENT2ISH, AGENT2ISH_DB, 0, &regs->pimr_agent2ish);
		if (ipc_device == SEDI_IPC_HOST) {
			PM_VNN_DRIVER_REQ(ipc_resource[ipc_device].read_vnn);
		}
		if (ipc_contexts[ipc_device].cb_event) {
			ipc_contexts[ipc_device].in_msg_count++;
			ipc_contexts[ipc_device].cb_event(ipc_device, SEDI_IPC_EVENT_MSG_IN,
							  ipc_contexts[ipc_device].usr_params);
		}
	}

	/* check whether it is an outbound interrupt*/
	if (SEDI_PREG_RBFV_IS_SET(IPC, ISH_IPC_BUSY_CLEAR_AGENT, ISH2AGENT_BUSY_CLEAR, 1,
				&regs->ish_ipc_busy_clear_agent)) {
		/*set 1 to clear this interrupt*/
		SEDI_PREG_RBFV_SET(IPC, ISH_IPC_BUSY_CLEAR_AGENT, ISH2AGENT_BUSY_CLEAR, 1,
				&regs->ish_ipc_busy_clear_agent);
		if ((ipc_contexts[ipc_device].initialized == true) &&
		    (ipc_contexts[ipc_device].cb_event)) {
			ipc_contexts[ipc_device].out_msg_count++;
			ipc_contexts[ipc_device].cb_event(ipc_device, SEDI_IPC_EVENT_MSG_PEER_ACKED,
							  ipc_contexts[ipc_device].usr_params);
		}
		if (ipc_device == SEDI_IPC_HOST) {
			PM_VNN_DRIVER_DEREQ(ipc_resource[ipc_device].write_vnn);
		}
	}

	/* check whether it is a csr interrupt */
	if ((ipc_device != SEDI_IPC_HOST) && (regs->agent2ish_csr_agent != 0)) {
		ipc_contexts[ipc_device].csr_saved = regs->agent2ish_csr_agent;
		/* write back to clear the interrupt */
		regs->agent2ish_csr_agent = ipc_contexts[ipc_device].csr_saved;
		if ((ipc_contexts[ipc_device].initialized == true) &&
		    (ipc_contexts[ipc_device].cb_event)) {
			ipc_contexts[ipc_device].cb_event(ipc_device, SEDI_IPC_EVENT_CSR_ACK,
							  ipc_contexts[ipc_device].usr_params);
		}
	}
}
