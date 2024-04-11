/*
 * Copyright (c) 2023-2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sedi_dma_ann_1p0.h"
#include "sedi_driver_pm.h"

#include "sedi_soc_regs.h"
#include <sedi_driver_dma.h>
#include <sedi_driver_ipc.h>
#include "sedi_driver_core.h"

#define DMA_RS0 0       /* root space for common memory */
#define DMA_RS1 1       /* root space for csme memory */
#define DMA_RS3 3       /* root space for IMR memory */
#define DT_IS_IN_DRAM (1 << 0)
#define SR_IS_IN_DRAM (1 << 1)

#define DMA_WRITE_ENABLE(i) (BIT(i) | BIT(DMA_CHANNEL_NUM + i))
#define DMA_WRITE_DISABLE(i) BIT(DMA_CHANNEL_NUM + i)
#define GET_MSB(data64) ((uint32_t)(data64 >> 32))
#define GET_LSB(data64) ((uint32_t)(data64))

/*driver version*/
static const sedi_driver_version_t driver_version = { SEDI_DMA_API_VERSION,
						      SEDI_DMA_DRIVER_VERSION };

typedef enum {
	SEDI_CONFIG_DMA_TRANS_TYPE = SEDI_CONFIG_DMA_CONTROL_ID_MAX,
	SEDI_CONFIG_DMA_LL_HEADER
} dma_inner_control_code;

/*!
 * DMA Transfer Type, inner usage
 */
typedef enum {
	DMA_TYPE_SINGLE,                /**< Single block mode. */
	DMA_TYPE_MULTI_CONT,            /**< Contiguous multiblock mode. */
	DMA_TYPE_MULTI_LL,              /**< Link list multiblock mode. */
	DMA_TYPE_MULTI_LL_CIRCULAR,     /**< Link list multiblock mode with
					  cyclic operation. */
	DMA_TYPE_MAX
} dma_transfer_type_t;

/* driver capabilities */
static sedi_dma_capabilities_t driver_capabilities[SEDI_DMA_NUM] = { 0 };

/* channel config*/
typedef struct {
	uint8_t config_applied;
	uint8_t tf_mode;
	uint8_t sr_mem_type;
	uint8_t dt_mem_type;
	uint8_t sr_msb;
	uint8_t dt_msb;
	uint8_t burst_length;
	uint8_t sr_width;
	uint8_t dt_width;
	uint8_t direction;
	uint8_t handshake_polarity;
	uint8_t peripheral_direction;
	uint16_t handshake_device_id;
	dma_linked_list_item_t *linked_list_header;
} channel_config_t;

/* dma runtime context information */
typedef struct {
	channel_config_t channel_config[DMA_CHANNEL_NUM];
	sedi_dma_event_cb_t cb_event[DMA_CHANNEL_NUM];  /*event callback*/
	void *cb_param[DMA_CHANNEL_NUM];                /*event callback*/
	sedi_dma_status_t status[DMA_CHANNEL_NUM];      /*status flags*/
	uint32_t done_byte[DMA_CHANNEL_NUM];            /*the transferred byte*/
	dma_linked_list_item_t *next_llp[DMA_CHANNEL_NUM];
	uint32_t flags[DMA_CHANNEL_NUM];            /*control and state flags*/
	uint8_t vnn_status;
	uint8_t power_status;
	/*other private runtime data*/
} dma_context_t;

/*resources data structure*/
typedef struct {
	dma_ann_1p0_regs_t *regs; /* register interface*/
	/*other private data can go here,  DMA related information etc. */
} dma_resources_t;

static dma_context_t dma_context[SEDI_DMA_NUM] = { 0 };

static const dma_resources_t resources[SEDI_DMA_NUM] = {
	{ .regs = (dma_ann_1p0_regs_t *)SEDI_IREG_BASE(DMA, 0) },
};

sedi_driver_version_t sedi_dma_get_version(void)
{
	return driver_version;
}

int sedi_dma_get_capabilities(IN sedi_dma_t dma_device,
			      INOUT sedi_dma_capabilities_t *cap)
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
	config->sr_msb = 0;
	config->dt_msb = 0;
	config->burst_length = DMA_BURST_TRANS_LENGTH_MAX;
	config->sr_width = DMA_TRANS_WIDTH_MAX;
	config->dt_width = DMA_TRANS_WIDTH_MAX;
	config->direction = DMA_DIRECTION_MAX;
	config->handshake_device_id = 0;
	config->linked_list_header = NULL;
	config->config_applied = 0;
}

/*  mask  channel interrupt */
static void mask_channel_interrupt(IN sedi_dma_t dma_device, IN int channel_id)
{
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;

	regs->int_reg.mask_tfr_low = DMA_WRITE_DISABLE(channel_id);
	regs->int_reg.mask_block_low = DMA_WRITE_DISABLE(channel_id);
	regs->int_reg.mask_src_trans_low = DMA_WRITE_DISABLE(channel_id);
	regs->int_reg.mask_dst_trans_low = DMA_WRITE_DISABLE(channel_id);
	regs->int_reg.mask_err_low = DMA_WRITE_DISABLE(channel_id);
}

/* clear channel interrupt */
static void clear_channel_interrupt(IN sedi_dma_t dma_device, IN int channel_id)
{
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;

	regs->int_reg.clear_tfr_low = BIT(channel_id);
	regs->int_reg.clear_block_low = BIT(channel_id);
	regs->int_reg.clear_src_trans_low = BIT(channel_id);
	regs->int_reg.clear_dst_trans_low = BIT(channel_id);
	regs->int_reg.clear_err_low = BIT(channel_id);
}

/* enable channel interrupt */
static void unmask_channel_interrupt(IN sedi_dma_t dma_device,
				     IN int channel_id)
{
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;

	regs->int_reg.mask_tfr_low = DMA_WRITE_ENABLE(channel_id);
	regs->int_reg.mask_err_low = DMA_WRITE_ENABLE(channel_id);
}

int32_t sedi_dma_init(IN sedi_dma_t dma_device, IN int channel_id,
		      IN sedi_dma_event_cb_t cb, INOUT void *param)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	/* init default config context */
	channel_config_t *config =
		&(dma_context[dma_device].channel_config[channel_id]);
	dma_set_default_channel_config(config);
	/*add callback*/
	dma_context[dma_device].cb_event[channel_id] = cb;
	dma_context[dma_device].cb_param[channel_id] = param;

	mask_channel_interrupt(dma_device, channel_id);
	clear_channel_interrupt(dma_device, channel_id);
	dma_context[dma_device].status[channel_id].busy = 0;
	dma_context[dma_device].status[channel_id].bus_error = 0;

	return SEDI_DRIVER_OK;
}

int32_t sedi_dma_uninit(IN sedi_dma_t dma_device, IN int channel_id)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	dma_context[dma_device].cb_event[channel_id] = NULL;

	mask_channel_interrupt(dma_device, channel_id);
	dma_context[dma_device].status[channel_id].busy = 0;
	dma_context[dma_device].status[channel_id].bus_error = 0;
	return SEDI_DRIVER_OK;
}

static void config_snoop(sedi_dma_t dma_device, int channel_id)
{
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;
	volatile dma_chan_reg_t *chan_regs = &(regs->chan_reg[channel_id]);
	volatile dma_misc_regs_t *misc_regs = &(regs->dev_misc_reg);

	/* snoop */
	misc_regs->dma_regaccess_chid = channel_id;

	SET_BITS(chan_regs->cfg_low, WR_SNP_LOC, WR_SNP_LEN, 0);
	SET_BITS(chan_regs->cfg_low, RD_SNP_LOC, RD_SNP_LEN, 0);
	SET_BITS(chan_regs->cfg_low, RD_LLP_SNP_LOC, RD_LLP_SNP_LEN, 1);
	SET_BITS(chan_regs->cfg_low, RD_STAT_SNP_LOC, RD_STAT_SNP_LEN, 1);
	SET_BITS(chan_regs->cfg_low, WR_STAT_SNP_LOC, WR_STAT_SNP_LEN, 1);
	SET_BITS(chan_regs->cfg_low, WR_CTLHI_SNP_LOC, WR_CTLHI_SNP_LEN, 1);
	SET_BITS(misc_regs->dma_ctl_ch[channel_id], RD_NON_SNOOP_LOC,
		 RD_NON_SNOOP_LEN, 1);
	SET_BITS(misc_regs->dma_ctl_ch[channel_id], WR_NON_SNOOP_LOC,
		 WR_NON_SNOOP_LEN, 1);
	SET_BITS(misc_regs->dma_ctl_ch[channel_id], NON_SNOOP_LOC,
		 NON_SNOOP_LEN, 1);
}

int32_t sedi_dma_set_power(IN sedi_dma_t dma_device, IN int channel_id,
			   IN sedi_power_state_t state)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	sedi_devid_t devid = SEDI_DEVID_DMA0 + dma_device;

	switch (state) {
	case SEDI_POWER_FULL:
		if (dma_context[dma_device].power_status == 0) {
			sedi_pm_set_device_power(devid, SEDI_POWER_FULL);
		}
		dma_context[dma_device].power_status |= BIT(channel_id);
		config_snoop(dma_device, channel_id);
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
		return SEDI_DRIVER_ERROR_PARAMETER;
	}
	return SEDI_DRIVER_OK;
}

static int32_t sedi_dma_control_aux(IN sedi_dma_t dma_device, IN int channel_id,
				    IN uint32_t control_id, IN uint32_t arg)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	channel_config_t *config =
		&(dma_context[dma_device].channel_config[channel_id]);

	switch (control_id) {
	case SEDI_CONFIG_DMA_TRANS_TYPE:
		DBG_CHECK(arg < DMA_TYPE_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->tf_mode = arg;
		break;
	case SEDI_CONFIG_DMA_SR_MEM_TYPE:
		DBG_CHECK(arg < DMA_MEM_TYPE_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->sr_mem_type = arg;
		break;
	case SEDI_CONFIG_DMA_DT_MEM_TYPE:
		DBG_CHECK(arg < DMA_MEM_TYPE_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->dt_mem_type = arg;
		break;
	case SEDI_CONFIG_DMA_LL_SR_MSB:
		config->sr_msb = arg;
		break;
	case SEDI_CONFIG_DMA_LL_DT_MSB:
		config->dt_msb = arg;
		break;
	case SEDI_CONFIG_DMA_DIRECTION:
		DBG_CHECK(arg < DMA_DIRECTION_MAX, SEDI_DRIVER_ERROR_PARAMETER);
		config->direction = arg;
		break;
	case SEDI_CONFIG_DMA_BURST_LENGTH:
		DBG_CHECK(arg < DMA_BURST_TRANS_LENGTH_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		config->burst_length = arg;
		break;
	case SEDI_CONFIG_DMA_SR_TRANS_WIDTH:
		DBG_CHECK(arg < DMA_TRANS_WIDTH_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		config->sr_width = arg;
		break;
	case SEDI_CONFIG_DMA_DT_TRANS_WIDTH:
		DBG_CHECK(arg < DMA_TRANS_WIDTH_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		config->dt_width = arg;
		break;
	case SEDI_CONFIG_DMA_HS_DEVICE_ID:
		config->handshake_device_id = arg;
		break;
	case SEDI_CONFIG_DMA_HS_DEVICE_ID_PER_DIR:
		config->peripheral_direction = arg;
		break;
	case SEDI_CONFIG_DMA_HS_POLARITY:
		DBG_CHECK(arg < DMA_HS_PER_RTX_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		config->handshake_polarity = arg;
		break;
	case SEDI_CONFIG_DMA_LL_HEADER:
		DBG_CHECK((arg), SEDI_DRIVER_ERROR_PARAMETER);
		config->linked_list_header = (dma_linked_list_item_t *)arg;
		break;
	default:
		return SEDI_DRIVER_ERROR_PARAMETER;
	}
	config->config_applied = 0;
	return SEDI_DRIVER_OK;
}

int32_t sedi_dma_control(IN sedi_dma_t dma_device, IN int channel_id,
			 IN uint32_t control_id, IN uint32_t arg)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(control_id < SEDI_CONFIG_DMA_CONTROL_ID_MAX,
		  SEDI_DRIVER_ERROR_PARAMETER);

	return sedi_dma_control_aux(dma_device, channel_id, control_id, arg);
}

int sedi_dma_get_status(IN sedi_dma_t dma_device, IN int channel_id,
			OUT sedi_dma_status_t *status)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	*status = dma_context[dma_device].status[channel_id];
	return SEDI_DRIVER_OK;
}

/*config misc and other registers, as an adding for ctrl register*/
static int32_t dma_apply_other_regs(volatile dma_misc_regs_t *misc_regs,
				    volatile dma_chan_reg_t *chan_regs,
				    channel_config_t *config, int channel_id)
{
	uint8_t sr_rs = DMA_RS0;
	uint8_t dt_rs = DMA_RS0;
	uint8_t dma_mem_trans_mode = 0;

	/* peripheral related registers*/
	if (config->direction != DMA_MEMORY_TO_MEMORY) {
		/* config check */
		DBG_CHECK(config->peripheral_direction < DMA_HS_PER_RTX_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		DBG_CHECK(config->handshake_polarity < DMA_HS_POLARITY_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		/* hardware handshake only*/
		/* select peripheral rx/tx to link up with dma*/
		SET_BITS(misc_regs->dma_xbar_sel[channel_id], RX_TX_LOC,
			 RX_TX_LEN, config->peripheral_direction);
		/* select peripheral device to connect with dma req wire*/
		SET_BITS(misc_regs->dma_xbar_sel[channel_id], DEVID_LOC,
			 DEVID_LEN, config->handshake_device_id);
		/* set handshaking polarity */
		SET_BITS(chan_regs->cfg_low, DST_HS_POL_LOC, DST_HS_POL_LEN,
			 config->handshake_polarity);
		SET_BITS(chan_regs->cfg_low, SRC_HS_POL_LOC, SRC_HS_POL_LEN,
			 config->handshake_polarity);
		SET_BITS(chan_regs->cfg_low, HSHAKE_NP_WR_LOC, HSHAKE_NP_WR_LEN,
			 1U);
		/* fill channel id to DST/SRC_PER reg*/
		SET_BITS(chan_regs->cfg_high, SRC_PER_LOC, SRC_PER_LEN,
			 channel_id);
		SET_BITS(chan_regs->cfg_high, DST_PER_LOC, DST_PER_LEN,
			 channel_id);
	}
	/* memory type related registers config*/
	/* source is memory*/
	if ((config->direction == DMA_MEMORY_TO_PERIPHERAL) ||
	    (config->direction == DMA_MEMORY_TO_MEMORY)) {
		DBG_CHECK(config->sr_mem_type < DMA_MEM_TYPE_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		if (config->sr_mem_type == DMA_UMA_MEM) {
			sr_rs = DMA_RS3;
		}
		if (config->sr_mem_type != DMA_SRAM_MEM) {
			dma_mem_trans_mode |= SR_IS_IN_DRAM;
		}
	}
	/* destination is memory*/
	if ((config->direction == DMA_PERIPHERAL_TO_MEMORY) ||
	    (config->direction == DMA_MEMORY_TO_MEMORY)) {
		DBG_CHECK(config->dt_mem_type < DMA_MEM_TYPE_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		if (config->dt_mem_type == DMA_UMA_MEM) {
			dt_rs = DMA_RS3;
		}
		if (config->dt_mem_type != DMA_SRAM_MEM) {
			dma_mem_trans_mode |= DT_IS_IN_DRAM;
		}
	}
	/*set root space and memory type*/
	SET_BITS(misc_regs->dma_ctl_ch[channel_id], WR_RS_LOC, WR_RS_LEN,
		 dt_rs);
	SET_BITS(misc_regs->dma_ctl_ch[channel_id], RD_RS_LOC, RD_RS_LEN,
		 sr_rs);
	SET_BITS(misc_regs->dma_ctl_ch[channel_id], M2M_TYPE_LOC, M2M_TYPE_LEN,
		 dma_mem_trans_mode);

	/* fill higher 32bit of 64bit addr */
	misc_regs->iosf_addr_fillin_dma_ch[channel_id] = config->sr_msb;
	misc_regs->iosf_dest_addr_fillin_dma_ch[channel_id] = config->dt_msb;
	return SEDI_DRIVER_OK;
}

static int32_t dma_channel_apply_config(IN sedi_dma_t dma_device,
					IN int channel_id)
{
	int32_t ret;
	channel_config_t *config =
		&(dma_context[dma_device].channel_config[channel_id]);
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;
	volatile dma_chan_reg_t *chan_regs = &(regs->chan_reg[channel_id]);
	volatile dma_misc_regs_t *misc_regs = &(regs->dev_misc_reg);

	/*return if no need to config*/
	if (config->config_applied == 1) {
		return SEDI_DRIVER_OK;
	}

	DBG_CHECK(config->tf_mode < DMA_TYPE_MAX, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(config->direction < DMA_DIRECTION_MAX,
		  SEDI_DRIVER_ERROR_PARAMETER);
	misc_regs->dma_regaccess_chid = channel_id;
	if (config->tf_mode == DMA_TYPE_SINGLE) {
		/* single block mode config, mainly config ctrl_low reg*/
		DBG_CHECK(config->burst_length < DMA_BURST_TRANS_LENGTH_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		DBG_CHECK(config->sr_width < DMA_TRANS_WIDTH_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		DBG_CHECK(config->dt_width < DMA_TRANS_WIDTH_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		DBG_CHECK(config->peripheral_direction < DMA_HS_PER_RTX_MAX,
			  SEDI_DRIVER_ERROR_PARAMETER);
		/*set dest and src burst size */
		SET_BITS(chan_regs->ctrl_low, DEST_MSIZE_LOC, SRC_MSIZE_LEN,
			 config->burst_length);
		SET_BITS(chan_regs->ctrl_low, SRC_MSIZE_LOC, SRC_MSIZE_LEN,
			 config->burst_length);
		/*source and destination transfer width */
		SET_BITS(chan_regs->ctrl_low, DST_TR_WIDTH_LOC,
			 DST_TR_WIDTH_LEN, config->dt_width);
		SET_BITS(chan_regs->ctrl_low, SRC_TR_WIDTH_LOC,
			 SRC_TR_WIDTH_LEN, config->sr_width);

		/*transfer  direction */
		SET_BITS(chan_regs->ctrl_low, TT_FC_LOC, TT_FC_LEN,
			 config->direction);

		/* Set increment*/
		switch (config->direction) {
		case DMA_PERIPHERAL_TO_MEMORY:
			SET_BITS(chan_regs->ctrl_low, SINC_LOC, SINC_LEN,
				 DMA_INCREMENT_NO_CHANGE);
			SET_BITS(chan_regs->ctrl_low, DINC_LOC, DINC_LEN,
				 DMA_INCREMENT_INC);
			break;
		case DMA_MEMORY_TO_MEMORY:
			SET_BITS(chan_regs->ctrl_low, SINC_LOC, SINC_LEN,
				 DMA_INCREMENT_INC);
			SET_BITS(chan_regs->ctrl_low, DINC_LOC, DINC_LEN,
				 DMA_INCREMENT_INC);
			break;
		case DMA_MEMORY_TO_PERIPHERAL:
			SET_BITS(chan_regs->ctrl_low, DINC_LOC, DINC_LEN,
				 DMA_INCREMENT_NO_CHANGE);
			SET_BITS(chan_regs->ctrl_low, SINC_LOC, SINC_LEN,
				 DMA_INCREMENT_INC);
			break;
		case DMA_PERIPHERAL_TO_PERIPHERAL:
			SET_BITS(chan_regs->ctrl_low, DINC_LOC, DINC_LEN,
				 DMA_INCREMENT_NO_CHANGE);
			SET_BITS(chan_regs->ctrl_low, SINC_LOC, SINC_LEN,
				 DMA_INCREMENT_NO_CHANGE);
			break;
		default:
			return SEDI_DRIVER_ERROR_PARAMETER;
		}
		chan_regs->llp_low = 0;
	} else if (config->tf_mode == DMA_TYPE_MULTI_LL) {
		DBG_CHECK(config->linked_list_header != NULL,
			  SEDI_DRIVER_ERROR_PARAMETER);
		chan_regs->llp_low = (uint32_t)config->linked_list_header;
	}

	/*config misc and other registers, as an adding for ctrl register*/
	ret = dma_apply_other_regs(misc_regs, chan_regs, config, channel_id);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	if ((config->sr_mem_type != DMA_SRAM_MEM) ||
	    (config->dt_mem_type != DMA_SRAM_MEM)) {
		dma_vnn_req(dma_device, channel_id);
	}

	config->config_applied = 1;
	return SEDI_DRIVER_OK;
}

int dma_fill_linkedlist(INOUT dma_linked_list_item_t *ll_p,
			IN uint32_t src_addr, IN uint32_t dst_addr,
			IN uint32_t block_size, uint32_t ctrl_low,
			IN dma_linked_list_item_t *ll_p_next)
{
	DBG_CHECK(ll_p != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(src_addr != 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(dst_addr != 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(block_size <= DMA_MAX_BLOCK_SIZE,
		  SEDI_DRIVER_ERROR_PARAMETER);

	ll_p->src_addr = src_addr;
	ll_p->dst_addr = dst_addr;
	ll_p->ctrl_low.raw = ctrl_low;
	SET_BITS(ll_p->ctrl_high.raw, BLOCK_TS_LOC, BLOCK_TS_LEN, block_size);
	ll_p->next_ll_p = ll_p_next;
	return SEDI_DRIVER_OK;
}

int dma_fill_sc_linkedlist(INOUT dma_linked_list_item_t *llp,
			   IN uint8_t count, IN uint32_t ctrl_reg_low,
			   IN sc_attr_t *attr)
{
	DBG_CHECK(llp != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(attr != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(count > 0, SEDI_DRIVER_ERROR_PARAMETER);

	int ret;
	dma_linked_list_item_t *ll_tmp = (dma_linked_list_item_t *)llp;
	uint32_t src = attr->src_addr;
	uint32_t dst = attr->dst_addr;

	for (int i = 0; i < count - 1; i++) {
		ret = dma_fill_linkedlist(ll_tmp + i, src, dst,
					   attr->block_size,
					   ctrl_reg_low, ll_tmp + i + 1);
		if (ret != SEDI_DRIVER_OK) {
			return ret;
		}
		if (attr->is_scatter) {
			if (attr->need_reload == 0) {
				src += attr->block_size;
			}
			dst += (attr->interval);
		} else {
			if (attr->need_reload == 0) {
				dst += attr->block_size;
			}
			src += (attr->interval);
		}
	}
	ret = dma_fill_linkedlist(ll_tmp + count - 1, src, dst,
				  attr->block_size, ctrl_reg_low, NULL);
	return ret;
}

static int32_t sedi_dma_start_transfer_aux(sedi_dma_t dma_device,
					   int channel_id, uint32_t sr_addr,
					   uint32_t dest_addr, uint32_t length)
{
	int32_t ret;
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;
	volatile dma_chan_reg_t *chan_regs = &(regs->chan_reg[channel_id]);
	channel_config_t *config =
		&(dma_context[dma_device].channel_config[channel_id]);

	if (regs->misc_reg.chan_en_low & BIT(channel_id)) {
		return SEDI_DRIVER_ERROR_BUSY;
	}
	/* channel config*/
	ret = dma_channel_apply_config(dma_device, channel_id);
	if (ret != SEDI_DRIVER_OK) {
		dma_context[dma_device].status[channel_id].busy = 0;
		return ret;
	}
	if (config->tf_mode == DMA_TYPE_SINGLE) {
		chan_regs->sar_low = sr_addr;
		chan_regs->dar_low = dest_addr;
		SET_BITS(chan_regs->ctrl_high, BLOCK_TS_LOC, BLOCK_TS_LEN,
			 length);
		SET_BITS(chan_regs->ctrl_low, INT_EN_LOC, INT_EN_LEN, 1);
	} else if (config->tf_mode == DMA_TYPE_MULTI_LL) {
		SET_BITS(chan_regs->ctrl_low, LLP_DST_EN_LOC, LLP_DST_EN_LEN,
			 1);
		SET_BITS(chan_regs->ctrl_low, LLP_SRC_EN_LOC, LLP_SRC_EN_LEN,
			 1);
	}

	dma_set_default_channel_config(config);
	/* enable interrupt */
	unmask_channel_interrupt(dma_device, channel_id);

	/* enable channel*/
	regs->misc_reg.cfg_low = 1;
	SET_BITS(chan_regs->cfg_low, CH_DRAIN_LOC, CH_DRAIN_LEN, 0);
	SET_BITS(chan_regs->cfg_low, CH_SUSP_LOC, CH_SUSP_LEN, 0);
	regs->misc_reg.chan_en_low = DMA_WRITE_ENABLE(channel_id);
	return SEDI_DRIVER_OK;
}

int32_t sedi_dma_start_transfer(IN sedi_dma_t dma_device, IN int channel_id,
				IN uint64_t sr_addr, IN uint64_t dest_addr,
				IN uint32_t length)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(sr_addr > 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(dest_addr > 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK((length <= DMA_MAX_BLOCK_SIZE) && (length > 0),
		  SEDI_DRIVER_ERROR_PARAMETER);

	if (dma_context[dma_device].status[channel_id].busy == 1) {
		return SEDI_DRIVER_ERROR_BUSY;
	}
	dma_context[dma_device].status[channel_id].busy = 1;
	dma_context[dma_device].status[channel_id].bus_error = 0;

	sedi_dma_control_aux(dma_device, channel_id, SEDI_CONFIG_DMA_TRANS_TYPE,
			     DMA_TYPE_SINGLE);
	/* pass higher 32 bit of address*/
	sedi_dma_control_aux(dma_device, channel_id, SEDI_CONFIG_DMA_LL_SR_MSB,
			     GET_MSB(sr_addr));
	sedi_dma_control_aux(dma_device, channel_id, SEDI_CONFIG_DMA_LL_DT_MSB,
			     GET_MSB(dest_addr));

	return sedi_dma_start_transfer_aux(dma_device, channel_id,
					   GET_LSB(sr_addr), GET_LSB(dest_addr),
					   length);
}

int32_t sedi_dma_start_ll_transfer(IN sedi_dma_t dma_device, IN int channel_id,
				   IN dma_linked_list_item_t *linkedlist_header)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(linkedlist_header != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	int32_t ret;

	if (dma_context[dma_device].status[channel_id].busy == 1) {
		return SEDI_DRIVER_ERROR_BUSY;
	}
	dma_context[dma_device].status[channel_id].busy = 1;
	dma_context[dma_device].status[channel_id].bus_error = 0;
	/* channel config*/
	sedi_dma_control_aux(dma_device, channel_id, SEDI_CONFIG_DMA_TRANS_TYPE,
			     DMA_TYPE_MULTI_LL);
	sedi_dma_control_aux(dma_device, channel_id, SEDI_CONFIG_DMA_LL_HEADER,
			     (uint32_t)linkedlist_header);

	ret = sedi_dma_start_transfer_aux(dma_device, channel_id, 0, 0, 0);

	return ret;
}

static void dma_transfer_post(sedi_dma_t dma_device, int channel_id)
{
	channel_config_t *config =
		&(dma_context[dma_device].channel_config[channel_id]);
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;
	volatile dma_chan_reg_t *chan_regs = &(regs->chan_reg[channel_id]);

	/* get status*/
	dma_context[dma_device].done_byte[channel_id] =
		GET_BITS(chan_regs->ctrl_high, BLOCK_TS_LOC, BLOCK_TS_LEN);
	dma_context[dma_device].next_llp[channel_id] =
		(dma_linked_list_item_t *)chan_regs->llp_low;

	/* disable dma channel*/
	regs->misc_reg.chan_en_low = DMA_WRITE_DISABLE(channel_id);
	while (regs->misc_reg.chan_en_low & BIT(channel_id)) {
	}

	/* mask and clear interrupt*/
	clear_channel_interrupt(dma_device, channel_id);
	mask_channel_interrupt(dma_device, channel_id);

	dma_vnn_dereq(dma_device, channel_id);
	dma_set_default_channel_config(config);
	dma_context[dma_device].status[channel_id].busy = 0;
}

/* Polling mode is only used in single-block mode */
int32_t sedi_dma_start_transfer_polling(IN sedi_dma_t dma_device,
					IN int channel_id, IN uint64_t sr_addr,
					IN uint64_t dest_addr,
					IN uint32_t length)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(length <= DMA_MAX_BLOCK_SIZE, SEDI_DRIVER_ERROR_PARAMETER);

	uint32_t ret;
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;
	volatile dma_chan_reg_t *chan_regs = &(regs->chan_reg[channel_id]);
	sedi_dma_event_cb_t cb = dma_context[dma_device].cb_event[channel_id];
	void *usr_param = dma_context[dma_device].cb_param[channel_id];

	if (dma_context[dma_device].status[channel_id].busy == 1) {
		return SEDI_DRIVER_ERROR_BUSY;
	}
	dma_context[dma_device].status[channel_id].busy = 1;
	dma_context[dma_device].status[channel_id].bus_error = 0;

	sedi_dma_control_aux(dma_device, channel_id, SEDI_CONFIG_DMA_TRANS_TYPE,
			     DMA_TYPE_SINGLE);

	/* pass higher 32 bit of address*/
	sedi_dma_control_aux(dma_device, channel_id, SEDI_CONFIG_DMA_LL_SR_MSB,
			     GET_MSB(sr_addr));
	sedi_dma_control_aux(dma_device, channel_id, SEDI_CONFIG_DMA_LL_DT_MSB,
			     GET_MSB(dest_addr));

	ret = dma_channel_apply_config(dma_device, channel_id);
	if (ret != SEDI_DRIVER_OK) {
		dma_context[dma_device].status[channel_id].busy = 0;
		return ret;
	}

	chan_regs->sar_low = GET_LSB(sr_addr);
	chan_regs->dar_low = GET_LSB(dest_addr);
	SET_BITS(chan_regs->ctrl_high, BLOCK_TS_LOC, BLOCK_TS_LEN, length);

	/* disable and clear interrupt */
	mask_channel_interrupt(dma_device, channel_id);
	clear_channel_interrupt(dma_device, channel_id);

	/* enable channel*/
	regs->misc_reg.cfg_low = 1;
	regs->misc_reg.chan_en_low = DMA_WRITE_ENABLE(channel_id);

	while (1) {
		if (regs->misc_reg.chan_en_low & BIT(channel_id)) {
			continue;
		}
		if (regs->int_reg.raw_err_low & BIT(channel_id)) {
			dma_transfer_post(dma_device, channel_id);
			dma_context[dma_device].status[channel_id].bus_error =
				1;
			if (cb != NULL) {
				cb(dma_device, channel_id,
				   SEDI_DMA_EVENT_BUS_ERROR, usr_param);
			}
			return SEDI_DRIVER_ERROR_TRANSFER;
		} else {
			dma_transfer_post(dma_device, channel_id);
			if (cb != NULL) {
				cb(dma_device, channel_id,
				   SEDI_DMA_EVENT_TRANSFER_DONE, usr_param);
			}
			return SEDI_DRIVER_OK;
		}
	}
	return SEDI_DRIVER_OK;
}

int32_t sedi_dma_abort_transfer(IN sedi_dma_t dma_device, IN int channel_id)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;
	volatile dma_chan_reg_t *chan_regs = &(regs->chan_reg[channel_id]);

	if (dma_context[dma_device].status[channel_id].busy == 0) {
		return SEDI_DRIVER_OK;
	}

	SET_BITS(chan_regs->cfg_low, CH_SUSP_LOC, CH_SUSP_LEN, 1);
	SET_BITS(chan_regs->cfg_low, CH_DRAIN_LOC, CH_DRAIN_LEN, 1);

	while ((chan_regs->cfg_low & BIT(FIFO_EMPTY_LOC)) == 0) {
	}

	dma_transfer_post(dma_device, channel_id);
	return SEDI_DRIVER_OK;
}

int32_t sedi_dma_get_done_status(IN sedi_dma_t dma_device, IN int channel_id,
				 OUT uint32_t *done_bytes,
				 OUT dma_linked_list_item_t **next_llp)
{
	DBG_CHECK(dma_device < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(channel_id < DMA_CHANNEL_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	if (dma_context[dma_device].status[channel_id].busy == 1) {
		return SEDI_DRIVER_ERROR_BUSY;
	}

	if (done_bytes) {
		*done_bytes = dma_context[dma_device].done_byte[channel_id];
	}
	if (next_llp) {
		*next_llp = dma_context[dma_device].next_llp[channel_id];
	}
	return SEDI_DRIVER_OK;
}

void dma_isr(IN sedi_dma_t dma_device)
{
	volatile dma_ann_1p0_regs_t *regs = resources[dma_device].regs;
	sedi_dma_event_cb_t cb;
	void *usr_param;
	uint32_t tfr_status = regs->int_reg.status_tfr_low;
	uint32_t err_status = regs->int_reg.status_err_low;

	for (int channel_id = 0; channel_id < DMA_CHANNEL_NUM; channel_id++) {
		cb = dma_context[dma_device].cb_event[channel_id];
		usr_param = dma_context[dma_device].cb_param[channel_id];
		if (tfr_status & BIT(channel_id)) {
			dma_transfer_post(dma_device, channel_id);
			if (cb != NULL) {
				cb(dma_device, channel_id,
				   SEDI_DMA_EVENT_TRANSFER_DONE, usr_param);
			}
		}
		if (err_status & BIT(channel_id)) {
			dma_transfer_post(dma_device, channel_id);
			dma_context[dma_device].status[channel_id].bus_error =
				1;
			if (cb != NULL) {
				cb(dma_device, channel_id,
				   SEDI_DMA_EVENT_BUS_ERROR, usr_param);
			}
		}
	}
}
