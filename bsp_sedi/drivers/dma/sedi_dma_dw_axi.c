/*
 * Copyright (c) 2020-2025 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <sedi_driver_pm.h>
#include <sedi_driver_dma.h>

#include "sedi_driver_core.h"
#include "sedi_dmac_regs.h"
#include "sedi_dma_regs.h"
#include "sedi_dma_misc_regs.h"
#include "sedi_soc_regs.h"
#include "sedi_soc_funcs.h"

#define PERI_SUPPORT        1
#define LINKED_LIST_SUPPORT 0
#ifndef DMA_PHY_CHAN_NUM
#define DMA_PHY_CHAN_NUM DMA_CHANNEL_NUM
#endif

#define SEDI_DMA_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

#define SEDI_DMA_POLL_UNTIL(_cond) SEDI_POLL_UNTIL((_cond), 1000)
/*driver version*/
static const sedi_driver_version_t driver_version = {SEDI_DMA_API_VERSION, SEDI_DMA_DRIVER_VERSION};

typedef enum {
	DMA_RS0 = 0,
	DMA_RS1 = 1,
	DMA_RS3 = 3,
} dma_root_space;
#define DT_IS_IN_DRAM (1)
#define SR_IS_IN_DRAM (2)

static int32_t sedi_dma_start_transfer_aux(sedi_dma_t dma_device, int channel_id, uint64_t sr_addr,
					   uint64_t dest_addr, uint32_t length, uint8_t polling);
static void dma_transfer_post(sedi_dma_t dev, int chn, uint64_t interrupt_status);

typedef enum {
	SEDI_CONFIG_DMA_TRANS_TYPE = SEDI_CONFIG_DMA_CONTROL_ID_MAX,
	SEDI_CONFIG_DMA_LL_HEADER
} dma_inner_control_code;

/*!
 * DMA Transfer Type, inner usage
 */
typedef enum {
	DMA_TYPE_SINGLE,            /* Single block mode. */
	DMA_TYPE_MULTI_CONT,        /* Contiguous multiblock mode. */
	DMA_TYPE_MULTI_LL,          /* Link list multiblock mode. */
	DMA_TYPE_MULTI_LL_CIRCULAR, /* Link list multiblock mode with cyclic operation. */
	DMA_TYPE_MAX
} dma_transfer_type_t;

/* driver capabilities */
static sedi_dma_capabilities_t driver_capabilities[SEDI_DMA_NUM] = {0};

/* channel config*/
typedef struct {
	uint8_t config_applied: 1;
	uint8_t tf_mode: 3;
	uint8_t sr_mem_type: 2;
	uint8_t dt_mem_type: 2;
	uint8_t burst_length: 4;
	uint8_t sr_width: 3;
	uint8_t dt_width: 3;
	uint8_t direction: 3;
	uint8_t handshake_polarity: 1;
	uint8_t peripheral_direction: 1;
	uint8_t reserved: 1;
	uint8_t handshake_device_id;
#ifdef LINKED_LIST_SUPPORT
	dma_linked_list_item_t *linked_list_header;
#endif
} channel_config_t;

/*dma runtime context information */
typedef struct {
	channel_config_t channel_config[DMA_CHANNEL_NUM];
	sedi_dma_event_cb_t cb_event[DMA_CHANNEL_NUM]; /*event callback*/
	void *cb_param[DMA_CHANNEL_NUM];               /*event callback*/
	sedi_dma_status_t status[DMA_CHANNEL_NUM];     /*status flags*/
	uint16_t done_byte[DMA_CHANNEL_NUM];           /*the transferred byte*/
#ifdef LINKED_LIST_SUPPORT
	dma_linked_list_item_t *next_llp[DMA_CHANNEL_NUM];
#endif
	uint8_t vnn_status;
	uint8_t power_status;
	/*other private runtime data*/
} dma_context_t;

/*resources data structure*/
typedef struct {
	__IO_RW sedi_dmac_regs_t *comm_reg_ptr;
	__IO_RW sedi_dma_regs_t *chan_reg_ptrs[DMA_CHANNEL_NUM];
	__IO_RW uint32_t *chan_misc_regs;
} dma_resources_t;

static dma_context_t dma_context[SEDI_DMA_NUM] = {0};
static dma_resources_t resources[SEDI_DMA_NUM] = {
	{ .comm_reg_ptr = (sedi_dmac_regs_t *)SEDI_IREG_BASE(DMA, 0) },
};

sedi_driver_version_t sedi_dma_get_version(void)
{
	return driver_version;
}

int sedi_dma_get_capabilities(IN sedi_dma_t dma_device, INOUT sedi_dma_capabilities_t *cap)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	if (sedi_dev_is_self_owned(SEDI_DEVID_DMA0 + dma_device)) {
		driver_capabilities[dma_device].is_available = 1;
	} else {
		driver_capabilities[dma_device].is_available = 0;
	}

	*cap = driver_capabilities[dma_device];
	return SEDI_DRIVER_OK;
}

static inline void dma_vnn_req(sedi_dma_t dma_device, int channel_id)
{
	unsigned int key = sedi_core_irq_lock();

	if (dma_context[dma_device].vnn_status == 0) {
		PM_VNN_DRIVER_REQ(VNN_ID_DMA0 + dma_device);
	}
	dma_context[dma_device].vnn_status |= BIT(channel_id);
	sedi_core_irq_unlock(key);
}

static inline void dma_vnn_dereq(sedi_dma_t dma_device, int channel_id)
{
	unsigned int key = sedi_core_irq_lock();

	if (dma_context[dma_device].vnn_status & (BIT(channel_id))) {
		dma_context[dma_device].vnn_status &= (~BIT(channel_id));
		if (dma_context[dma_device].vnn_status == 0) {
			PM_VNN_DRIVER_DEREQ(VNN_ID_DMA0 + dma_device);
		}
	}
	sedi_core_irq_unlock(key);
}

static void dma_set_default_channel_config(OUT channel_config_t *config)
{
	config->tf_mode = DMA_TYPE_MAX;
	config->sr_mem_type = DMA_SRAM_MEM;
	config->dt_mem_type = DMA_SRAM_MEM;
	config->burst_length = DMA_BURST_TRANS_LENGTH_MAX;
	config->sr_width = DMA_TRANS_WIDTH_MAX;
	config->dt_width = DMA_TRANS_WIDTH_MAX;
	config->direction = DMA_DIRECTION_MAX;
	config->handshake_device_id = 0;
#ifdef LINKED_LIST_SUPPORT
	config->linked_list_header = NULL;
#endif
	config->config_applied = 0;
}

#define CH_TFR_DONE_INTR                                                                           \
	SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_DMA_TFR_DONE_IntSignal,                        \
		   ENABLE_DMA_TFR_DONE_IntSignal)
#define CH_TFR_ERR_INTR                                                                            \
	(SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_DEC_ERR_IntSignal,                        \
		    ENABLE_SRC_DEC_ERR_IntSignal) |                                                \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_DST_DEC_ERR_IntSignal,                        \
		    ENABLE_DST_DEC_ERR_IntSignal) |                                                \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_SLV_ERR_IntSignal,                        \
		    ENABLE_SRC_SLV_ERR_IntSignal) |                                                \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_DST_SLV_ERR_IntSignal,                        \
		    ENABLE_DST_SLV_ERR_IntSignal) |                                                \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_RD_DEC_ERR_IntSignal,                     \
		    ENABLE_LLI_RD_DEC_ERR_IntSignal) |                                             \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_WR_DEC_ERR_IntSignal,                     \
		    ENABLE_LLI_WR_DEC_ERR_IntSignal) |                                             \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_RD_SLV_ERR_IntSignal,                     \
		    ENABLE_LLI_RD_SLV_ERR_IntSignal) |                                             \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_WR_SLV_ERR_IntSignal,                     \
		    ENABLE_LLI_WR_SLV_ERR_IntSignal) |                                             \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntSignal,       \
		    ENABLE_SHADOWREG_OR_LLI_INVALID_ERR_IntSignal) |                               \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_MULTIBLKTYPE_ERR_IntSignal,             \
		    ENABLE_SLVIF_MULTIBLKTYPE_ERR_IntSignal) |                                     \
	 SEDI_RBFVM(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_DEC_ERR_IntSignal,                      \
		    ENABLE_SLVIF_DEC_ERR_IntSignal))

/*  mask  channel interrupt */
static inline void mask_channel_interrupt(volatile sedi_dma_regs_t *chx_regs)
{
	/*
	 * per spec, keep intstatus_enablereg to track finish reason,
	 * clear intsignal_enablereg to mask interrupt source
	 */
	chx_regs->intsignal_enablereg = 0;
	chx_regs->intstatus_enablereg = CH_TFR_DONE_INTR | CH_TFR_ERR_INTR;
}

/* unmask channel interrupt */
static inline void unmask_channel_interrupt(volatile sedi_dma_regs_t *chx_regs)
{
	chx_regs->intsignal_enablereg = CH_TFR_DONE_INTR | CH_TFR_ERR_INTR;
	chx_regs->intstatus_enablereg = CH_TFR_DONE_INTR | CH_TFR_ERR_INTR;
}

/* clear channel interrupt */
static void clear_channel_interrupt(volatile sedi_dma_regs_t *chx_regs)
{
	chx_regs->intclearreg = chx_regs->intstatus;
}

static void sedi_dma_chan_regs_init(IN sedi_dma_t dma_device)
{
	uintptr_t chan_adrs = (uintptr_t)resources[dma_device].comm_reg_ptr
			+ SEDI_DMA_CHAN_REGS_OFF;

	for (uint32_t chan_id = 0; chan_id < DMA_CHANNEL_NUM; ++chan_id) {
		resources[dma_device].chan_reg_ptrs[chan_id] = (sedi_dma_regs_t *)chan_adrs;
		chan_adrs += SEDI_DMA_CHAN_REGS_WIDTH;
	}

	uintptr_t misc_adrs = (uintptr_t)resources[dma_device].comm_reg_ptr
			+ SEDI_DMA_MISC_REGS_OFF;

	resources[dma_device].chan_misc_regs = (uint32_t *)misc_adrs;
}

int32_t sedi_dma_init(IN sedi_dma_t dma_device, IN uintptr_t base)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	resources[dma_device].comm_reg_ptr = (volatile sedi_dmac_regs_t *)base;
	sedi_dma_chan_regs_init(dma_device);

	return SEDI_DRIVER_OK;
}

int32_t sedi_dma_chan_init(IN sedi_dma_t dma_device, IN int channel_id, IN sedi_dma_event_cb_t cb,
		      INOUT void *param)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	if ((uintptr_t)(resources[dma_device].chan_reg_ptrs[channel_id])
			<= (uintptr_t)(resources[dma_device].comm_reg_ptr)) {
		sedi_dma_chan_regs_init(dma_device);
	}

	/* init default config context */
	channel_config_t *config = &(dma_context[dma_device].channel_config[channel_id]);

	dma_set_default_channel_config(config);
	/*add callback*/
	dma_context[dma_device].cb_event[channel_id] = cb;
	dma_context[dma_device].cb_param[channel_id] = param;

	volatile sedi_dma_regs_t *chan_regs = resources[dma_device].chan_reg_ptrs[channel_id];

	mask_channel_interrupt(chan_regs);
	clear_channel_interrupt(chan_regs);
	dma_context[dma_device].status[channel_id].busy = 0;
	dma_context[dma_device].status[channel_id].bus_error = 0;

	return SEDI_DRIVER_OK;
}

int32_t sedi_dma_chan_uninit(IN sedi_dma_t dma_device, IN int channel_id)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	dma_context[dma_device].cb_event[channel_id] = NULL;

	mask_channel_interrupt(resources[dma_device].chan_reg_ptrs[channel_id]);
	dma_context[dma_device].status[channel_id].busy = 0;
	dma_context[dma_device].status[channel_id].bus_error = 0;
	return SEDI_DRIVER_OK;
}

int dma_fill_linkedlist(INOUT dma_linked_list_item_t *ll_p, IN uint32_t src_addr,
			IN uint32_t dst_addr, IN uint32_t block_size, uint32_t ctrl_low,
			IN dma_linked_list_item_t *ll_p_next)
{
	return 0;
}

int32_t sedi_dma_set_power(IN sedi_dma_t dma_device, IN int channel_id, IN sedi_power_state_t state)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	int32_t ret = SEDI_DRIVER_OK;
	unsigned int key = sedi_core_irq_lock();
	sedi_devid_t devid = SEDI_DEVID_DMA0 + dma_device;

	switch (state) {
	case SEDI_POWER_FULL:
		if (dma_context[dma_device].power_status == 0) {
			sedi_pm_set_device_power(devid, SEDI_POWER_FULL);
		}
		dma_context[dma_device].power_status |= BIT(channel_id);
		break;
	case SEDI_POWER_LOW:
	case SEDI_POWER_SUSPEND:
	case SEDI_POWER_FORCE_SUSPEND:
		sedi_dma_abort_transfer(dma_device, channel_id);
		if (dma_context[dma_device].power_status == 0) {
			break;
		}
		dma_context[dma_device].power_status &= (~BIT(channel_id));
		if (dma_context[dma_device].power_status == 0) {
			sedi_pm_set_device_power(devid, SEDI_POWER_SUSPEND);
		}
		break;
	case SEDI_POWER_OFF:
	default:
		ret = SEDI_DRIVER_ERROR_PARAMETER;
		break;
	}
	sedi_core_irq_unlock(key);

	return ret;
}

int32_t sedi_dma_control(IN sedi_dma_t dma_device, IN int channel_id, IN uint32_t control_id,
			 IN uint32_t arg)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(control_id < SEDI_CONFIG_DMA_CONTROL_ID_MAX, SEDI_DRIVER_ERROR_PARAMETER);

	channel_config_t *config = &(dma_context[dma_device].channel_config[channel_id]);

	switch (control_id) {
	case SEDI_CONFIG_DMA_SR_MEM_TYPE:
		DBG_CHECK(arg < DMA_MEM_TYPE_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->sr_mem_type = arg;
		break;
	case SEDI_CONFIG_DMA_DT_MEM_TYPE:
		DBG_CHECK(arg < DMA_MEM_TYPE_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->dt_mem_type = arg;
		break;
	case SEDI_CONFIG_DMA_DIRECTION:
		DBG_CHECK(arg < DMA_DIRECTION_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->direction = arg;
		break;
	case SEDI_CONFIG_DMA_BURST_LENGTH:
		DBG_CHECK(arg < DMA_BURST_TRANS_LENGTH_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->burst_length = arg;
		break;
	case SEDI_CONFIG_DMA_SR_TRANS_WIDTH:
		DBG_CHECK(arg < DMA_TRANS_WIDTH_128, SEDI_DRIVER_ERROR_PARAMETER);
		config->sr_width = arg;
		break;
	case SEDI_CONFIG_DMA_DT_TRANS_WIDTH:
		DBG_CHECK(arg < DMA_TRANS_WIDTH_128, SEDI_DRIVER_ERROR_PARAMETER);
		config->dt_width = arg;
		break;
#if PERI_SUPPORT
	case SEDI_CONFIG_DMA_HS_DEVICE_ID:
		config->handshake_device_id = arg;
		break;
	case SEDI_CONFIG_DMA_HS_DEVICE_ID_PER_DIR:
		config->peripheral_direction = arg;
		break;
	case SEDI_CONFIG_DMA_HS_POLARITY:
		DBG_CHECK(arg < DMA_HS_PER_RTX_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->handshake_polarity = arg;
		break;
#endif
#ifdef LINKED_LIST_SUPPORT
	case SEDI_CONFIG_DMA_LL_HEADER:
		DBG_CHECK((arg), SEDI_DRIVER_ERROR_PARAMETER);
		config->linked_list_header = (dma_linked_list_item_t *)arg;
		break;
#endif
	default:
		return SEDI_DRIVER_ERROR_PARAMETER;
	}
	config->config_applied = 0;
	return SEDI_DRIVER_OK;
}

int sedi_dma_get_status(IN sedi_dma_t dma_device, IN int channel_id, OUT sedi_dma_status_t *status)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	*status = dma_context[dma_device].status[channel_id];
	return SEDI_DRIVER_OK;
}

static int32_t dma_channel_apply_config(IN sedi_dma_t dma_device, IN int channel_id)
{
	channel_config_t *config = &(dma_context[dma_device].channel_config[channel_id]);
	volatile sedi_dma_regs_t *chan_regs = resources[dma_device].chan_reg_ptrs[channel_id];

	uint64_t chx_ctl = 0, chx_cfg = 0;

	/*return if no need to config*/
	if (config->config_applied == 1) {
		return SEDI_DRIVER_OK;
	}

	DBG_CHECK(config->direction < DMA_DIRECTION_MAX, SEDI_DRIVER_ERROR_PARAMETER);
	if (config->tf_mode == DMA_TYPE_SINGLE) {
		/* single block mode config check */
		DBG_CHECK(config->burst_length < DMA_BURST_TRANS_LENGTH_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		DBG_CHECK(config->sr_width < DMA_TRANS_WIDTH_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		DBG_CHECK(config->dt_width < DMA_TRANS_WIDTH_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		DBG_CHECK(config->peripheral_direction < DMA_HS_PER_RTX_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		/*set dest and src burst size */
		chx_ctl = SEDI_RBFM_VALUE(DMA, CTL, DST_MSIZE, config->burst_length) |
			  SEDI_RBFM_VALUE(DMA, CTL, SRC_MSIZE, config->burst_length) |
			  SEDI_RBFM_VALUE(DMA, CTL, DST_TR_WIDTH, config->dt_width) |
			  SEDI_RBFM_VALUE(DMA, CTL, SRC_TR_WIDTH, config->sr_width);
		chx_cfg = SEDI_RBFM_VALUE(DMA, CFG2, TT_FC, config->direction);

		if ((config->direction == DMA_PERIPHERAL_TO_MEMORY) ||
		    (config->direction == DMA_PERIPHERAL_TO_PERIPHERAL)) {
			chx_ctl |= SEDI_RBFVM(DMA, CTL, SINC, FIXED);
			chx_cfg |=
				SEDI_RBFM_VALUE(DMA, CFG2, SRC_PER, config->handshake_device_id) |
				SEDI_RBFM_VALUE(DMA, CFG2, SRC_HWHS_POL,
						config->handshake_polarity);
		}
		if ((config->direction == DMA_MEMORY_TO_PERIPHERAL) ||
		    (config->direction == DMA_PERIPHERAL_TO_PERIPHERAL)) {
			chx_ctl |= SEDI_RBFVM(DMA, CTL, DINC, FIXED);
			chx_cfg |=
				SEDI_RBFM_VALUE(DMA, CFG2, DST_PER, config->handshake_device_id) |
				SEDI_RBFM_VALUE(DMA, CFG2, DST_HWHS_POL,
						config->handshake_polarity);
		}
	}
#ifdef LINKED_LIST_SUPPORT
	else if (config->tf_mode == DMA_TYPE_MULTI_LL) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}
#endif
	else {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	chan_regs->ctl = chx_ctl;
	chan_regs->cfg2 = chx_cfg;

	uint32_t misc_ctl = 0;

	/* memory type related registers config*/
	/* source is memory*/
	if ((config->direction == DMA_MEMORY_TO_PERIPHERAL) ||
	    (config->direction == DMA_MEMORY_TO_MEMORY)) {
		if (config->sr_mem_type == DMA_UMA_MEM) {
			misc_ctl |= SEDI_RBFM_VALUE(DMA_MISC, CTL_CH, RD_RS, DMA_RS3);
		}
		if (config->sr_mem_type != DMA_SRAM_MEM) {
			misc_ctl |= SR_IS_IN_DRAM | SEDI_RBFVM(DMA_MISC, CTL_CH, RD_NON_SNOOP, 1);
		}
	}
	/* destination is memory*/
	if ((config->direction == DMA_PERIPHERAL_TO_MEMORY) ||
	    (config->direction == DMA_MEMORY_TO_MEMORY)) {
		if (config->dt_mem_type == DMA_UMA_MEM) {
			misc_ctl |= SEDI_RBFM_VALUE(DMA_MISC, CTL_CH, WR_RS, DMA_RS3);
		}
		if (config->dt_mem_type != DMA_SRAM_MEM) {
			misc_ctl |= DT_IS_IN_DRAM | SEDI_RBFVM(DMA_MISC, CTL_CH, WR_NON_SNOOP, 1);
		}
	}
	if ((config->sr_mem_type != DMA_SRAM_MEM) || (config->dt_mem_type != DMA_SRAM_MEM)) {
		dma_vnn_req(dma_device, channel_id);
	}

	resources[dma_device].chan_misc_regs[channel_id] = misc_ctl;

	config->config_applied = 1;
	return SEDI_DRIVER_OK;
}

#define DMA_MAX_BLOCK_SIZE (4096) /* ref ISH5p8 HAS */
int32_t sedi_dma_start_transfer(IN sedi_dma_t dma_device, IN int channel_id, IN uint64_t sr_addr,
				IN uint64_t dest_addr, IN uint32_t length)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(sr_addr > 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(dest_addr > 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(length > 0, SEDI_DRIVER_ERROR_PARAMETER);

	dma_context_t *ctx = &dma_context[dma_device];
	uint16_t sr_width = ctx->channel_config[channel_id].sr_width;

	if (length > (DMA_MAX_BLOCK_SIZE << sr_width)) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	if (ctx->status[channel_id].busy == 1) {
		return SEDI_DRIVER_ERROR_BUSY;
	}
	ctx->status[channel_id].busy = 1;
	ctx->status[channel_id].bus_error = 0;
	ctx->channel_config[channel_id].tf_mode = DMA_TYPE_SINGLE;
	return sedi_dma_start_transfer_aux(dma_device, channel_id, sr_addr, dest_addr, length, 0);
}

int32_t sedi_dma_start_transfer_polling(IN sedi_dma_t dma_device, IN int channel_id,
					IN uint64_t sr_addr, IN uint64_t dest_addr,
					IN uint32_t length)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(sr_addr > 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(dest_addr > 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(length > 0, SEDI_DRIVER_ERROR_PARAMETER);

	dma_context_t *ctx = &dma_context[dma_device];
	uint16_t sr_width = ctx->channel_config[channel_id].sr_width;

	if (length > (DMA_MAX_BLOCK_SIZE << sr_width)) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	if (ctx->status[channel_id].busy == 1) {
		return SEDI_DRIVER_ERROR_BUSY;
	}
	ctx->status[channel_id].busy = 1;
	ctx->status[channel_id].bus_error = 0;
	ctx->channel_config[channel_id].tf_mode = DMA_TYPE_SINGLE;
	return sedi_dma_start_transfer_aux(dma_device, channel_id, sr_addr, dest_addr, length, 1);
}

static inline int32_t cal_block_ts(channel_config_t *config, uint32_t length)
{
	uint32_t sr_width_in_byte = 1 << (config->sr_width);

	if (length % sr_width_in_byte) {
		return length >> config->sr_width;
	} else {
		return (length >> config->sr_width) - 1;
	}
}

static int32_t sedi_dma_start_transfer_aux(sedi_dma_t dma_device, int channel_id, uint64_t sr_addr,
					   uint64_t dest_addr, uint32_t length, uint8_t polling)
{
	int32_t ret = SEDI_DRIVER_OK;
	volatile sedi_dmac_regs_t *dmac_ptr = resources[dma_device].comm_reg_ptr;
	volatile sedi_dma_regs_t *chan_regs = resources[dma_device].chan_reg_ptrs[channel_id];
	channel_config_t *config = &(dma_context[dma_device].channel_config[channel_id]);

	if (dmac_ptr->chenreg & (1 << channel_id)) {
		return SEDI_DRIVER_ERROR_BUSY;
	}
	/* channel config*/
	ret = dma_channel_apply_config(dma_device, channel_id);
	if (ret != SEDI_DRIVER_OK) {
		dma_context[dma_device].status[channel_id].busy = 0;
		return ret;
	}
	if (config->tf_mode == DMA_TYPE_SINGLE) {
		chan_regs->sar = sr_addr;
		chan_regs->dar = dest_addr;
		chan_regs->block_ts = cal_block_ts(config, length);
	}
#ifdef LINKED_LIST_SUPPORT
	else if (config->tf_mode == DMA_TYPE_MULTI_LL) {
		/* TODO */
	}
#endif

	dmac_ptr->commonreg_intstatus_enablereg = 0;
	dmac_ptr->commonreg_intsignal_enablereg = 0;
	if (polling) {
		/* TODO: should be mask, but can't distinguish reason now */
		mask_channel_interrupt(chan_regs);
	} else {
		/* enable interrupt */
		unmask_channel_interrupt(chan_regs);
	}
	dmac_ptr->cfgreg = SEDI_RBFVM(DMAC, CFGREG, DMAC_EN, ENABLED) |
			   SEDI_RBFVM(DMAC, CFGREG, INT_EN, ENABLED);

	/* enable channel*/
	uint64_t chan_en_mask = SEDI_RBFVM(DMAC, CHENREG, CH1_EN, ENABLE_CH1) |
				SEDI_RBFVM(DMAC, CHENREG, CH1_EN_WE, ENABLE_WR_CH1_EN);
	chan_en_mask <<= channel_id;
	dmac_ptr->chenreg |= chan_en_mask;
	if (polling) {
		if (SEDI_DMA_POLL_UNTIL(!(dmac_ptr->chenreg & chan_en_mask)) != SEDI_DRIVER_OK) {
			ret = SEDI_DRIVER_ERROR;
		}
		dma_transfer_post(dma_device, channel_id, chan_regs->intstatus);
	} else {
		dma_set_default_channel_config(config);
	}
	return ret;
}

int32_t sedi_dma_abort_transfer(IN sedi_dma_t dma_device, IN int channel_id)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	int32_t ret = SEDI_DRIVER_OK;
	volatile uint64_t *chenreg_ptr = &resources[dma_device].comm_reg_ptr->chenreg;

	if (dma_context[dma_device].status[channel_id].busy == 0) {
		return SEDI_DRIVER_OK;
	}

	const uint64_t ch_susp_sts_test_bit = SEDI_RBFVM(DMAC, CHENREG, CH1_SUSP, ENABLE_CH1_SUSP)
					      << channel_id;
	*chenreg_ptr = ch_susp_sts_test_bit |
		       (SEDI_RBFVM(DMAC, CHENREG, CH1_SUSP_WE, ENABLE_WR_CH1_SUSP) << channel_id);
	/* Wait until the channel is suspended or timeout occurs */
	if (SEDI_DMA_POLL_UNTIL(!(*chenreg_ptr & ch_susp_sts_test_bit)) != SEDI_DRIVER_OK) {
		ret = SEDI_DRIVER_ERROR;
	}
	*chenreg_ptr = SEDI_RBFVM(DMAC, CHENREG, CH1_ABORT, ENABLE_CH1_ABORT) << channel_id;

	dma_transfer_post(dma_device, channel_id, 0);
	return ret;
}

int32_t sedi_dma_start_ll_transfer(IN sedi_dma_t dma_device, IN int channel_id,
				   IN dma_linked_list_item_t *linkedlist_header)
{
	return 0;
}

static void dma_transfer_post(sedi_dma_t dev, int chn, uint64_t interrupt_status)
{
	channel_config_t *config = &(dma_context[dev].channel_config[chn]);
	volatile sedi_dma_regs_t *chan_regs = resources[dev].chan_reg_ptrs[chn];
	sedi_dma_event_cb_t cb;
	void *usr_param;

	/* clear interrupt*/
	clear_channel_interrupt(chan_regs);

	dma_vnn_dereq(dev, chn);

	dma_set_default_channel_config(config);
	dma_context[dev].status[chn].busy = 0;

	cb = dma_context[dev].cb_event[chn];
	usr_param = dma_context[dev].cb_param[chn];
	if (interrupt_status & CH_TFR_DONE_INTR) {
		if (cb != NULL) {
			cb(dev, chn, SEDI_DMA_EVENT_TRANSFER_DONE, usr_param);
		}
	}
	if (interrupt_status & CH_TFR_ERR_INTR) {
		dma_context[dev].status[chn].bus_error = 1;
		if (cb != NULL) {
			cb(dev, chn, SEDI_DMA_EVENT_BUS_ERROR, usr_param);
		}
	}
}

void dma_isr(IN sedi_dma_t dev)
{
	uint64_t interrupt_status;
	volatile sedi_dmac_regs_t *dmac_ptr = resources[dev].comm_reg_ptr;

	for (int chn = 0; chn < DMA_PHY_CHAN_NUM; chn++) {
		interrupt_status = resources[dev].chan_reg_ptrs[chn]->intstatus;
		if (dmac_ptr->intstatusreg &
		    (SEDI_RBFVM(DMAC, INTSTATUSREG, CH1_IntStat, ACTIVE) << chn)) {
			if ((interrupt_status & CH_TFR_DONE_INTR) ||
			    (interrupt_status & CH_TFR_ERR_INTR)) {
				dma_transfer_post(dev, chn, interrupt_status);
			}
		}
	}
}
