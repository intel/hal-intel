/*
 * Copyright (c) 2023 - 2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sedi_driver_dma.h"
#include "sedi_driver_pm.h"
#include <sedi_driver_i2c.h>
#include <sedi_i2c_regs.h>
#include "sedi_driver_core.h"

#define I2C_MAX_BLOCK_TS (4096)

#define I2C_SDA_HOLD_DEFAULT (133)
#define I2C_FIFO_DEFAULT_WATERMARK (I2C_FIFO_DEPTH / 2U)

#define LBW_CLK_MHZ (sedi_pm_get_lbw_clock() / 1000000)

enum { I2C_SPEED_STANDARD = 0, I2C_SPEED_FAST, I2C_SPEED_FAST_PLUS, I2C_SPEED_HIGH, I2C_SPEED_MAX };

#define BSETS_ABORT_SOURCE_NO_ACK  \
	(SEDI_RBFVM(I2C, TX_ABRT_SOURCE, ABRT_7B_ADDR_NOACK, ACTIVE) | \
	 SEDI_RBFVM(I2C, TX_ABRT_SOURCE, ABRT_10ADDR1_NOACK, ACTIVE) | \
	 SEDI_RBFVM(I2C, TX_ABRT_SOURCE, ABRT_10ADDR2_NOACK, ACTIVE) | \
	 SEDI_RBFVM(I2C, TX_ABRT_SOURCE, ABRT_TXDATA_NOACK, ABRT_TXDATA_NOACK_GENERATED) | \
	 SEDI_RBFVM(I2C, TX_ABRT_SOURCE, ABRT_GCALL_NOACK, ABRT_GCALL_NOACK_GENERATED))

#define BSETS_INTR_ERROR  \
	(SEDI_RBFVM(I2C, INTR_STAT, R_RX_UNDER, ACTIVE) | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_RX_OVER, ACTIVE)  | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_TX_OVER, ACTIVE)  | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_TX_ABRT, ACTIVE))

#define BSETS_INTR_SEND  \
	(SEDI_RBFVM(I2C, INTR_STAT, R_TX_EMPTY, ACTIVE) | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_STOP_DET, ACTIVE) | \
	 BSETS_INTR_ERROR)

#define BSETS_INTR_RECV  \
	(SEDI_RBFVM(I2C, INTR_STAT, R_TX_EMPTY, ACTIVE) | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_RX_FULL, ACTIVE)  | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_STOP_DET, ACTIVE) | \
	 BSETS_INTR_ERROR)

#define BSETS_INTR_SLAVE  \
	(SEDI_RBFVM(I2C, INTR_STAT, R_RD_REQ, ACTIVE) | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_RX_FULL, ACTIVE) | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_STOP_DET, ACTIVE) | \
	 BSETS_INTR_ERROR  | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_START_DET, ACTIVE) | \
	 SEDI_RBFVM(I2C, INTR_STAT, R_RESTART_DET, ACTIVE))

#define BSETS_MASTER_DEFAULT  \
	(SEDI_RBFVM(I2C, CON, IC_SLAVE_DISABLE, SLAVE_DISABLED) | \
	 SEDI_RBFVM(I2C, CON, IC_RESTART_EN, ENABLED) | \
	 SEDI_RBFVM(I2C, CON, MASTER_MODE, ENABLED) | \
	 SEDI_RBFVM(I2C, CON, TX_EMPTY_CTRL, ENABLED))

typedef enum {
	I2C_DMA_DIRECTION_TX = 0,
	I2C_DMA_DIRECTION_RX = 1,
} i2c_dma_diretion_t;

struct i2c_context {
	uint32_t base;

	sedi_i2c_capabilities_t capability;
	sedi_i2c_status_t status;
	sedi_i2c_event_cb_t cb_event;

	uint8_t *buf;
	uint32_t buf_size;
	uint32_t buf_index;
	uint32_t rx_cmd_index;

	volatile uint8_t pending;

	uint32_t isr_flag;
	uint32_t isr_data;

	int tx_dma_dev;
	int tx_dma_chan;
	int tx_dma_handshake;
	int rx_dma_dev;
	int rx_dma_chan;
	int rx_dma_handshake;

	dma_memory_type_t tx_memory_type;
	dma_memory_type_t rx_memory_type;

	int speed;
	sedi_i2c_bus_clk_t *clk_info;
	sedi_i2c_bus_info_t bus_info;
};

static uint32_t regval_speed[I2C_SPEED_MAX] = {
	SEDI_RBFVM(I2C, CON, SPEED, STANDARD),
	SEDI_RBFVM(I2C, CON, SPEED, FAST),
	SEDI_RBFVM(I2C, CON, SPEED, FAST),
	SEDI_RBFVM(I2C, CON, SPEED, HIGH)
};

/*
 * For example, standard mode is 100KHz, 10000ns per period, 5000ns for
 * SCL low & high level.
 */
#define I2C_SS_SCL_HIGH 4500
#define I2C_SS_SCL_LOW 5100
#define I2C_FS_SCL_HIGH 690
#define I2C_FS_SCL_LOW 1650
#define I2C_FSP_SCL_HIGH 300
#define I2C_FSP_SCL_LOW 500
#define I2C_HS_SCL_HIGH 300
#define I2C_HS_SCL_LOW 500

#define I2C_CONTEXT_INIT(x)                                                                        \
	{                                                                                          \
		.base = SEDI_IREG_BASE(I2C, x), .speed = I2C_SPEED_FAST,                           \
		.tx_dma_handshake = DMA_HWID_I2C##x##_TX, .rx_dma_handshake = DMA_HWID_I2C##x##_RX,\
		.tx_memory_type = DMA_SRAM_MEM, .rx_memory_type = DMA_SRAM_MEM                     \
	}
struct i2c_context contexts[SEDI_I2C_NUM] = { I2C_CONTEXT_INIT(0), I2C_CONTEXT_INIT(1),
					      I2C_CONTEXT_INIT(2) };

#define SEDI_I2C_POLL_WAIT(_cond) SEDI_POLL_WAIT_MUTE((_cond), 100)

static void i2c_isr_complete(sedi_i2c_t i2c_device, bool is_error);

static void init_i2c_prescale(sedi_i2c_bus_info_t *bus_info)
{
	if (bus_info->std_clk.hcnt == 0) {

		bus_info->std_clk.sda_hold = LBW_CLK_MHZ * I2C_SDA_HOLD_DEFAULT / NS_PER_US;
		bus_info->fst_clk.sda_hold = LBW_CLK_MHZ * I2C_SDA_HOLD_DEFAULT / NS_PER_US;
		bus_info->fsp_clk.sda_hold = LBW_CLK_MHZ * I2C_SDA_HOLD_DEFAULT / NS_PER_US;
		bus_info->high_clk.sda_hold = LBW_CLK_MHZ * I2C_SDA_HOLD_DEFAULT / NS_PER_US;

		bus_info->std_clk.hcnt = LBW_CLK_MHZ * I2C_SS_SCL_HIGH / NS_PER_US;
		bus_info->fst_clk.hcnt = LBW_CLK_MHZ * I2C_FS_SCL_HIGH / NS_PER_US;
		bus_info->fsp_clk.hcnt = LBW_CLK_MHZ * I2C_FSP_SCL_HIGH / NS_PER_US;
		bus_info->high_clk.hcnt = LBW_CLK_MHZ * I2C_HS_SCL_HIGH / NS_PER_US;

		bus_info->std_clk.lcnt = LBW_CLK_MHZ * I2C_SS_SCL_LOW / NS_PER_US;
		bus_info->fst_clk.lcnt = LBW_CLK_MHZ * I2C_FS_SCL_LOW / NS_PER_US;
		bus_info->fsp_clk.lcnt = LBW_CLK_MHZ * I2C_FSP_SCL_LOW / NS_PER_US;
		bus_info->high_clk.lcnt = LBW_CLK_MHZ * I2C_HS_SCL_LOW / NS_PER_US;
	}
}

static void dw_i2c_enable(uint32_t base)
{
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;

	if (SEDI_PREG_RBFV_IS_SET(I2C, ENABLE_STATUS, IC_EN, ENABLED, &i2c->enable_status)) {
		return;
	}

	/* prevent tx empty interrupt after enable */
	i2c->intr_mask = 0;

	i2c->enable = SEDI_RBFVM(I2C, ENABLE, ENABLE, ENABLED);
	SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, ENABLE_STATUS, IC_EN, DISABLED,
				&i2c->enable_status));
}

static int dw_i2c_disable(uint32_t base)
{
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;

	/* If already disabled, return */
	if (SEDI_PREG_RBFV_IS_SET(I2C, ENABLE, ENABLE, DISABLED, &i2c->enable)) {
		return 0;
	}

	i2c->dma_cr = 0;
	i2c->intr_mask = 0;

	if (SEDI_PREG_RBFV_IS_SET(I2C, STATUS, MST_ACTIVITY, ACTIVE, &i2c->status)) {
		SEDI_PREG_RBFV_SET(I2C, ENABLE, ABORT, ENABLED, &i2c->enable);
		SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, ENABLE, ABORT, ENABLED,
					&i2c->enable));
	}

	SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, STATUS, MST_ACTIVITY, ACTIVE, &i2c->status));

	i2c->enable = 0;
	SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, ENABLE_STATUS, IC_EN, ENABLED,
				&i2c->enable_status));

	return 0;
}

static int dw_i2c_config_addr(uint32_t base, uint16_t slave_addr)
{
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;

	i2c->tar = SEDI_RBFM_VALUE(I2C, TAR, IC_TAR, slave_addr);
	if (slave_addr & SEDI_I2C_ADDRESS_10BIT) {
		SEDI_PREG_RBFV_SET(I2C, TAR, IC_10BITADDR_MASTER, ADDR_10BITS, &i2c->tar);
	}

	return 0;
}

static int dw_i2c_config_speed(uint32_t base, int speed,
		sedi_i2c_bus_clk_t *cfg)
{
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;

	if (SEDI_PREG_RBFV_IS_SET(I2C, ENABLE_STATUS, IC_EN, ENABLED, &i2c->enable_status)) {
		return -1;
	}

	i2c->con = BSETS_MASTER_DEFAULT | regval_speed[speed];

	/* config sda_hold if needed */
	if (cfg->sda_hold) {
		i2c->sda_hold = cfg->sda_hold;
	}

	switch (speed) {
	case I2C_SPEED_STANDARD:
		i2c->ss_scl_hcnt = cfg->hcnt;
		i2c->ss_scl_lcnt = cfg->lcnt;
		break;
	case I2C_SPEED_FAST:
	case I2C_SPEED_FAST_PLUS:
		i2c->fs_scl_hcnt = cfg->hcnt;
		i2c->fs_scl_lcnt = cfg->lcnt;
		break;
	case I2C_SPEED_HIGH:
		i2c->hs_scl_hcnt = cfg->hcnt;
		i2c->hs_scl_lcnt = cfg->lcnt;
		break;
	default:
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	return 0;
}

static int dw_i2c_config_txfifo(uint32_t base, uint32_t watermark)
{
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;

	SEDI_PREG_RBF_SET(I2C, TX_TL, TX_TL, watermark, &i2c->tx_tl);

	return 0;
}

static int dw_i2c_config_rxfifo(uint32_t base, uint32_t watermark)
{
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;

	SEDI_PREG_RBF_SET(I2C, RX_TL, RX_TL, watermark - 1, &i2c->rx_tl);

	return 0;
}

static int dw_i2c_poll_write(uint32_t base, const uint8_t *buffer, uint32_t length, bool pending)
{
	int ret;
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;

	uint32_t cmd = SEDI_RBFVM(I2C, DATA_CMD, CMD, WRITE);

	for (uint32_t i = 0; i < length; i++) {
		if ((i == length - 1) && (!pending)) {
			cmd |= SEDI_RBFVM(I2C, DATA_CMD, STOP, ENABLE);
		}

		i2c->data_cmd = buffer[i] | cmd;

		ret = SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, STATUS, TFNF, FULL,
					&i2c->status) && !(i2c->raw_intr_stat & BSETS_INTR_ERROR));
		if (ret) {
			return ret;
		}
		/* Check abort and error */
		if (i2c->raw_intr_stat & BSETS_INTR_ERROR) {
			return SEDI_DRIVER_ERROR_TRANSFER;
		}
	}

	/* Wait for end */
	ret = SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, STATUS, ACTIVITY, ACTIVE,
				&i2c->status));

	return ret;
}

static int dw_i2c_poll_read(uint32_t base, uint8_t *buffer, uint32_t length, bool pending)
{
	int ret;
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;
	uint32_t cmd = SEDI_RBFVM(I2C, DATA_CMD, CMD, READ);

	for (uint32_t i = 0; i < length; i++) {
		if ((i == length - 1) && (!pending)) {
			cmd |= SEDI_RBFVM(I2C, DATA_CMD, STOP, ENABLE);
		}

		i2c->data_cmd = cmd;

		ret = SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, STATUS, RFNE, EMPTY,
					&i2c->status) && !(i2c->raw_intr_stat & BSETS_INTR_ERROR));
		if (ret) {
			return ret;
		}
		/* Check abort and error*/
		if (i2c->raw_intr_stat & BSETS_INTR_ERROR) {
			return SEDI_DRIVER_ERROR_TRANSFER;
		}


		buffer[i] = (uint8_t)(i2c->data_cmd & 0xFF);
	}

	/* Wait for end */
	ret = SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, STATUS, ACTIVITY, ACTIVE,
				&i2c->status));

	return ret;
}

static inline void dw_i2c_irq_config(uint32_t base, uint32_t config)
{
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)base;

	i2c->intr_mask = config;
}

static uint32_t dw_i2c_clear_interrupt(uint32_t base)
{
	sedi_i2c_regs_t *i2c = (void *)base;
	uint32_t value;
	uint32_t stat;

	stat = i2c->intr_stat;

	value = i2c->clr_rx_under;
	value = i2c->clr_rx_over;
	value = i2c->clr_tx_over;
	value = i2c->clr_tx_abrt;
	value = i2c->clr_stop_det;
	value = i2c->clr_intr;
	PARAM_UNUSED(value);

	return stat;
}

static void dw_i2c_dma_enable(uint32_t base, int fifo_depth, int tx_only)
{
	sedi_i2c_regs_t *i2c = (void *)base;
	uint32_t dma_cr = SEDI_RBFVM(I2C, DMA_CR, TDMAE, ENABLED);

	SEDI_PREG_RBF_SET(I2C, TX_TL, TX_TL, fifo_depth, &i2c->tx_tl);
	i2c->dma_tdlr = SEDI_RBFM_VALUE(I2C, DMA_TDLR, DMATDL, fifo_depth);

	if (!tx_only) {
		SEDI_PREG_RBF_SET(I2C, RX_TL, RX_TL, fifo_depth - 1, &i2c->rx_tl);
		i2c->dma_rdlr = SEDI_RBFM_VALUE(I2C, DMA_RDLR, DMARDL, fifo_depth - 1);
		dma_cr |= SEDI_RBFVM(I2C, DMA_CR, RDMAE, ENABLED);
	}

	i2c->dma_cr = dma_cr;
}

/* force enter IDLE mode */
static void dw_i2c_abort(struct i2c_context *context)
{
	sedi_i2c_regs_t *i2c = (void *)context->base;
	uint32_t value;

	if (SEDI_PREG_RBFV_IS_SET(I2C, ENABLE, ENABLE, DISABLED, &i2c->enable)) {
		return;
	}

	i2c->dma_cr = 0;
	i2c->intr_mask = 0;

	SEDI_PREG_RBFV_SET(I2C, ENABLE, ABORT, ENABLED, &i2c->enable);

	/* Waiting for abort operation finished, HW can clear */
	SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_IS_SET(I2C, RAW_INTR_STAT, TX_ABRT, INACTIVE,
				&i2c->raw_intr_stat));
	while (SEDI_PREG_RBFV_GET(I2C, RXFLR, RXFLR, &i2c->rxflr) != 0) {
		value = i2c->data_cmd;
	}

	dw_i2c_irq_config(context->base, 0);

	dw_i2c_config_txfifo(context->base, 0);
	dw_i2c_config_rxfifo(context->base, 0);

	/* Clear the abort state */
	dw_i2c_clear_interrupt(context->base);
	PARAM_UNUSED(value);
}

static uint32_t dw_i2c_dr_address(uint32_t base)
{
	sedi_i2c_regs_t *i2c = (void *)base;

	return (uint32_t)&i2c->data_cmd;
}

static uint32_t dw_i2c_abort_analysis(uint32_t base)
{
	sedi_i2c_regs_t *i2c = (void *)base;
	uint32_t abort_src, event = SEDI_I2C_EVENT_TRANSFER_INCOMPLETE;

	abort_src = i2c->tx_abrt_source;

	if (abort_src & BSETS_ABORT_SOURCE_NO_ACK) {
		event |= SEDI_I2C_EVENT_ADDRESS_NACK;
	}

	if (SEDI_PREG_RBFV_IS_SET(I2C, TX_ABRT_SOURCE, ARB_LOST, ABRT_LOST_GENERATED, &abort_src)) {
		event |= SEDI_I2C_EVENT_ARBITRATION_LOST;
	}

	return event;
}

/* Used for sending cmd for I2C read operation */
static void i2c_ask_data(sedi_i2c_t i2c_device)
{
	struct i2c_context *context = &contexts[i2c_device];
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)(context->base);

	uint32_t tx_fifo_space = 0, rx_fifo_space = 0;
	uint32_t rx_pending = context->rx_cmd_index - context->buf_index;
	uint32_t size = context->buf_size - context->rx_cmd_index;
	uint32_t fifo_size = 0;
	uint32_t data = SEDI_RBFVM(I2C, DATA_CMD, CMD, READ);
	bool last_data = false;

	/* No need to send anymore */
	if (context->rx_cmd_index == context->buf_size) {
		return;
	}

	/* Decide how many space there are */
	if ((I2C_FIFO_DEPTH - SEDI_PREG_RBFV_GET(I2C, TXFLR, TXFLR, &i2c->txflr)) <= rx_pending) {
		return;
	}

	tx_fifo_space = I2C_FIFO_DEPTH - SEDI_PREG_RBFV_GET(I2C, TXFLR, TXFLR, &i2c->txflr) -
			rx_pending;

	/* To prevent RX FIFO overflow, need to make sure command number less
	 * than the space in RX FIFO.
	 */
	rx_fifo_space = I2C_FIFO_DEPTH - SEDI_PREG_RBFV_GET(I2C, RXFLR, RXFLR, &i2c->rxflr);

	if (tx_fifo_space < rx_fifo_space) {
		fifo_size = tx_fifo_space;
	} else {
		fifo_size = rx_fifo_space;
	}

	if (size <= fifo_size) {
		last_data = true;
	} else {
		size = fifo_size;
	}

	while (size > 0) {
		/* If it is first data, need RESTART */
		if (context->rx_cmd_index == 0) {
			data |= SEDI_RBFVM(I2C, DATA_CMD, RESTART, ENABLE);
		}

		/* Last data need STOP flag */
		if ((size == 1) && last_data && (!(context->pending))) {
			data |= SEDI_RBFVM(I2C, DATA_CMD, STOP, ENABLE);
			/*  Disable tx empty interrupt */
			i2c->intr_mask &= ~SEDI_RBFVM(I2C, INTR_MASK, M_TX_EMPTY, DISABLED);
		}

		i2c->data_cmd = data;
		context->rx_cmd_index++;
		size--;

		/* Reset data */
		data = SEDI_RBFVM(I2C, DATA_CMD, CMD, READ);
	}
}

static void i2c_send(sedi_i2c_t i2c_device)
{
	struct i2c_context *context = &contexts[i2c_device];
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)(context->base);

	uint32_t tx_fifo_space = 0;
	uint32_t size = context->buf_size - context->buf_index;
	uint32_t data = 0;
	uint8_t *buf = context->buf;
	bool last_data = false;

	if (context->buf_index == context->buf_size) {
		return;
	}

	/* Decide how many space there are */
	tx_fifo_space = I2C_FIFO_DEPTH - SEDI_PREG_RBFV_GET(I2C, TXFLR, TXFLR, &i2c->txflr);

	if (size <= tx_fifo_space) {
		last_data = true;
	} else {
		size = tx_fifo_space;
	}

	/* Not last data */
	while (size > 1) {
		data = buf[context->buf_index];
		i2c->data_cmd = data;
		size--;
		context->buf_index++;
	}

	/* Last data transfer  */
	data = buf[context->buf_index];

	/* If it is the last data for whole transfer */
	if (last_data) {
		/* NO need to send STOP, but need to change watermark
		 * to 0, this will have a interrupt while all data sent out
		 */
		if (context->pending) {
			SEDI_PREG_RBF_SET(I2C, TX_TL, TX_TL, 0, &i2c->tx_tl);
		} else {
			SEDI_PREG_RBFV_SET(I2C, DATA_CMD, STOP, ENABLE, &data);
			/* Disable tx empty interrupt */
			i2c->intr_mask &= ~SEDI_RBFVM(I2C, INTR_MASK, M_TX_EMPTY, DISABLED);
		}
	}

	i2c->data_cmd = data;
	context->buf_index++;
}

/******************************************************************************
 * SEDI interface
 *****************************************************************************/

#define SEDI_I2C_DRV_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(1, 0)
#define SEDI_I2C_DMA_CHANNEL_UNUSED (-1)

static const sedi_driver_version_t driver_version = { SEDI_I2C_API_VERSION, SEDI_I2C_DRV_VERSION };

static sedi_i2c_capabilities_t driver_capabilities[SEDI_I2C_NUM] = { 0 };
/* Used for I2C DMA Rx, peripheral to peripheral not support, from has 5.8 */
static uint8_t dma_cmd[I2C_MAX_BLOCK_TS] __attribute__((aligned(32)));

sedi_driver_version_t sedi_i2c_get_version(void)
{
	return driver_version;
}

int sedi_i2c_get_capabilities(IN sedi_i2c_t i2c_device, sedi_i2c_capabilities_t *cap)
{
	struct i2c_context *context = &contexts[i2c_device];
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)(context->base);

	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	if (sedi_dev_is_self_owned(SEDI_DEVID_I2C0 + i2c_device)) {
		driver_capabilities[i2c_device].is_available = 1;
	} else {
		driver_capabilities[i2c_device].is_available = 0;
	}

	driver_capabilities[i2c_device].rx_buffer_depth =
		SEDI_PREG_RBFV_GET(I2C, COMP_PARAM_1, RX_BUFFER_DEPTH, &i2c->comp_param_1) + 1;
	driver_capabilities[i2c_device].tx_buffer_depth =
		SEDI_PREG_RBFV_GET(I2C, COMP_PARAM_1, TX_BUFFER_DEPTH, &i2c->comp_param_1) + 1;
	driver_capabilities[i2c_device].dma =
		SEDI_PREG_RBFV_GET(I2C, COMP_PARAM_1, HAS_DMA, &i2c->comp_param_1);

	*cap = driver_capabilities[i2c_device];

	return SEDI_DRIVER_OK;
}

int32_t sedi_i2c_init(IN sedi_i2c_t i2c_device,
		IN sedi_i2c_event_cb_t cb_event, IN uint32_t base)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];

	if (!sedi_dev_is_self_owned(SEDI_DEVID_I2C0 + i2c_device)) {
		return SEDI_DRIVER_ERROR_NO_DEV;
	}

	context->cb_event = cb_event;
	context->tx_dma_chan = SEDI_I2C_DMA_CHANNEL_UNUSED;
	context->rx_dma_chan = SEDI_I2C_DMA_CHANNEL_UNUSED;

	init_i2c_prescale(&(context->bus_info));

	context->base = base;

	/* i2c default configuration */
	context->speed = I2C_SPEED_STANDARD;
	context->clk_info = &(context->bus_info.std_clk);

	/* read command for rx dma */
	dma_cmd[0] = (SEDI_RBFVM(I2C, DATA_CMD, CMD, READ) |
			SEDI_RBFVM(I2C, DATA_CMD, RESTART, ENABLE)) >> 8;
	for (int i = 1; i < I2C_MAX_BLOCK_TS; i++)
		dma_cmd[i] = SEDI_RBFVM(I2C, DATA_CMD, CMD, READ) >> 8;
	sedi_core_clean_dcache_by_addr((uint32_t *)(dma_cmd), sizeof(dma_cmd));

	return SEDI_DRIVER_OK;
}

int32_t sedi_i2c_uninit(IN sedi_i2c_t i2c_device)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];

	context->cb_event = NULL;

	return SEDI_DRIVER_OK;
}

int32_t sedi_i2c_set_power(IN sedi_i2c_t i2c_device, IN sedi_power_state_t state)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];
	sedi_devid_t id = SEDI_DEVID_I2C0 + i2c_device;
	int32_t ret = SEDI_DRIVER_OK;

	switch (state) {
	case SEDI_POWER_FULL:
		sedi_pm_set_device_power(id, state);
		dw_i2c_clear_interrupt(context->base);
		dw_i2c_irq_config(context->base, 0);
		dw_i2c_disable(context->base);
		dw_i2c_config_speed(context->base, context->speed,
			context->clk_info);
		break;
	case SEDI_POWER_SUSPEND:
	case SEDI_POWER_FORCE_SUSPEND:
	case SEDI_POWER_LOW:
		dw_i2c_irq_config(context->base, 0);
		sedi_pm_set_device_power(id, state);
		break;
	case SEDI_POWER_OFF:
	default:
		ret = SEDI_DRIVER_ERROR_UNSUPPORTED;
		break;
	}

	return ret;
}

static void callback_dma_transfer(const sedi_dma_t dma, const int chan,
		const int event, void *param)
{
	struct i2c_context *context = &contexts[(int)param];
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)(context->base);
	uint32_t i2c_event = SEDI_I2C_EVENT_TRANSFER_INCOMPLETE | SEDI_I2C_EVENT_DMA_ERROR;

	sedi_dma_set_power(dma, chan, SEDI_POWER_LOW);

	/* DMA error, go to end */
	if (event != SEDI_DMA_EVENT_TRANSFER_DONE) {
		context->status.event = i2c_event;
		i2c_isr_complete((sedi_i2c_t)param, true);
		return;
	}

	/* DMA tx_only or rx_cmd */
	if (context->tx_dma_chan == chan) {
		/* disable tx dma */
		context->tx_dma_chan = SEDI_I2C_DMA_CHANNEL_UNUSED;
		SEDI_PREG_RBFV_SET(I2C, DMA_CR, TDMAE, DISABLED, &i2c->dma_cr);

		/* sent last data by interrupt, with stop if not pending */
		uint32_t data = (context->rx_dma_chan != SEDI_I2C_DMA_CHANNEL_UNUSED)
				? SEDI_RBFVM(I2C, DATA_CMD, CMD, READ)
				: context->buf[context->buf_size - 1];
		SEDI_I2C_POLL_WAIT(SEDI_PREG_RBFV_GET(I2C, TXFLR, TXFLR, &i2c->txflr)
				== I2C_FIFO_DEPTH);
		i2c->data_cmd = data | (context->pending
				? 0 : (SEDI_RBFVM(I2C, DATA_CMD, STOP, ENABLE)));
		context->buf_index = context->buf_size;
	} else {
		/* disable rx dma */
		context->rx_dma_chan = SEDI_I2C_DMA_CHANNEL_UNUSED;
		SEDI_PREG_RBFV_SET(I2C, DMA_CR, RDMAE, DISABLED, &i2c->dma_cr);

		/* dma rx data complete */
		i2c_isr_complete((sedi_i2c_t)param, false);
	}
}

static int config_and_enable_dma_channel(sedi_i2c_t i2c_dev, int dma, int handshake, int chan,
					 uint32_t src, uint32_t dst, uint32_t len,
					 i2c_dma_diretion_t dir)
{
	int ret;
	int dma_dir = DMA_MEMORY_TO_PERIPHERAL;

	if (dir == I2C_DMA_DIRECTION_RX) {
		dma_dir = DMA_PERIPHERAL_TO_MEMORY;
	}

	ret = sedi_dma_init(dma, chan, callback_dma_transfer, (void *)i2c_dev);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_set_power(dma, chan, SEDI_POWER_FULL);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, chan, SEDI_CONFIG_DMA_BURST_LENGTH, DMA_BURST_TRANS_LENGTH_1);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, chan, SEDI_CONFIG_DMA_SR_TRANS_WIDTH, DMA_TRANS_WIDTH_8);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, chan, SEDI_CONFIG_DMA_DT_TRANS_WIDTH, DMA_TRANS_WIDTH_8);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, chan, SEDI_CONFIG_DMA_HS_DEVICE_ID, handshake);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, chan, SEDI_CONFIG_DMA_HS_POLARITY, DMA_HS_POLARITY_HIGH);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, chan, SEDI_CONFIG_DMA_DIRECTION, dma_dir);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_start_transfer(dma, chan, src, dst, len);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	return ret;
}

int32_t sedi_i2c_master_write_dma(IN sedi_i2c_t i2c_device, IN uint32_t addr, IN uint8_t *data,
	IN uint32_t num, IN bool pending, IN uint32_t dma_dev, IN uint32_t dma_chan)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != (addr & SEDI_RBFM(I2C, TAR, IC_TAR)), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(NULL != data, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)(context->base);

	/* dma max block ts 4095, need slicing if exceed, tbd */
	if (num <= SEDI_I2C_DMA_LENGTH_LIMIT || num > I2C_MAX_BLOCK_TS) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	if (context->status.busy) {
		return SEDI_DRIVER_ERROR_BUSY;
	}

	dw_i2c_disable(context->base);
	dw_i2c_clear_interrupt(context->base);
	dw_i2c_config_addr(context->base, addr);

	context->status.busy = 1U;
	context->status.direction = 0U;
	context->status.event = SEDI_I2C_EVENT_TRANSFER_NONE;
	context->pending = pending;
	context->buf = (void *)data;
	context->buf_size = num;
	context->buf_index = 0;
	context->tx_dma_dev = dma_dev;
	context->tx_dma_chan = dma_chan;

	i2c->intr_mask = BSETS_INTR_ERROR | SEDI_RBFVM(I2C, INTR_MASK, M_STOP_DET, DISABLED);

	config_and_enable_dma_channel(i2c_device, context->tx_dma_dev, context->tx_dma_handshake,
		context->tx_dma_chan, (uint32_t)data, dw_i2c_dr_address(context->base),
		num - 1, I2C_DMA_DIRECTION_TX);

	dw_i2c_dma_enable(context->base, 1, 1);
	i2c->enable = SEDI_RBFVM(I2C, ENABLE, ENABLE, ENABLED);

	return SEDI_DRIVER_OK;
}

int32_t sedi_i2c_master_read_dma(IN sedi_i2c_t i2c_device, IN uint32_t addr, OUT uint8_t *data,
	IN uint32_t num, IN bool pending, IN uint32_t rx_dma_dev, IN uint32_t rx_dma_chan,
	IN uint32_t cmd_dma_dev, IN uint32_t cmd_dma_chan)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != (addr & SEDI_RBFM(I2C, TAR, IC_TAR)), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(NULL != data, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)(context->base);

	/* dma max block ts 4095, need slicing if exceed, tbd */
	if (num <= SEDI_I2C_DMA_LENGTH_LIMIT || num > I2C_MAX_BLOCK_TS) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	if (context->status.busy) {
		return SEDI_DRIVER_ERROR_BUSY;
	}

	dw_i2c_disable(context->base);
	dw_i2c_clear_interrupt(context->base);
	dw_i2c_config_addr(context->base, addr);

	context->status.busy = 1U;
	context->status.direction = 1U;
	context->status.event = SEDI_I2C_EVENT_TRANSFER_NONE;
	context->pending = pending;
	context->buf = data;
	context->buf_size = num;
	context->buf_index = 0;
	context->rx_dma_dev = rx_dma_dev;
	context->rx_dma_chan = rx_dma_chan;
	context->tx_dma_dev = cmd_dma_dev;
	context->tx_dma_chan = cmd_dma_chan;

	i2c->intr_mask = BSETS_INTR_ERROR;

	/* RX: start read data transfer first */
	config_and_enable_dma_channel(i2c_device, context->rx_dma_dev, context->rx_dma_handshake,
		context->rx_dma_chan, dw_i2c_dr_address(context->base), (uint32_t)data,
		num, I2C_DMA_DIRECTION_RX);

	/* TX: write command for next read per request */
	config_and_enable_dma_channel(i2c_device, context->tx_dma_dev, context->tx_dma_handshake,
		context->tx_dma_chan, (uint32_t)dma_cmd, dw_i2c_dr_address(context->base) + 1,
		num - 1, I2C_DMA_DIRECTION_TX);

	dw_i2c_dma_enable(context->base, 1, 0);
	i2c->enable = SEDI_RBFVM(I2C, ENABLE, ENABLE, ENABLED);

	return SEDI_DRIVER_OK;
}

int32_t sedi_i2c_master_write_async(IN sedi_i2c_t i2c_device, IN uint32_t addr, IN uint8_t *data,
				    IN uint32_t num, IN bool pending)
{
	uint32_t irq = BSETS_INTR_SEND;

	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != (addr & SEDI_RBFM(I2C, TAR, IC_TAR)), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(NULL != data, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != num, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];

	if (context->status.busy) {
		return SEDI_DRIVER_ERROR_BUSY;
	}

	/* Clear all status first */
	dw_i2c_clear_interrupt(context->base);
	dw_i2c_config_addr(context->base, addr);

	/* Set watermark */
	if (num < I2C_FIFO_DEFAULT_WATERMARK) {
		/* If less than half FIFO, just set watermark to transfer size
		 */
		dw_i2c_config_txfifo(context->base, num);
	} else {
		dw_i2c_config_txfifo(context->base, I2C_FIFO_DEFAULT_WATERMARK);
	}

	/* Enable I2C */
	dw_i2c_enable(context->base);

	/* Set internal state */
	context->status.busy = 1U;
	context->status.direction = 0U;
	/* Reset event to default */
	context->status.event = SEDI_I2C_EVENT_TRANSFER_NONE;

	context->buf = (uint8_t *)data;
	context->buf_size = num;
	context->rx_cmd_index = 0;
	context->buf_index = 0;
	context->pending = pending;

	/* FIFO fill */
	i2c_send(i2c_device);
	if (context->buf_index == num && !pending)
		irq &= ~SEDI_RBFVM(I2C, INTR_MASK, M_TX_EMPTY, DISABLED);

	dw_i2c_irq_config(context->base, irq);

	return SEDI_DRIVER_OK;
}

int32_t sedi_i2c_master_read_async(IN sedi_i2c_t i2c_device, IN uint32_t addr, OUT uint8_t *data,
				   IN uint32_t num, IN bool pending)
{
	uint32_t irq = BSETS_INTR_RECV;

	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != (addr & SEDI_RBFM(I2C, TAR, IC_TAR)), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(NULL != data, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != num, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];

	if (context->status.busy) {
		return SEDI_DRIVER_ERROR_BUSY;
	}

	/* Clear all status first */
	dw_i2c_clear_interrupt(context->base);
	dw_i2c_config_addr(context->base, addr);

	/* Set watermark, receive needs both tx and rx */
	if (num < I2C_FIFO_DEFAULT_WATERMARK) {
		/* If less than half FIFO, just set watermark to transfer size
		 */
		dw_i2c_config_rxfifo(context->base, num);
		dw_i2c_config_txfifo(context->base, 0);
	} else {
		dw_i2c_config_rxfifo(context->base, I2C_FIFO_DEFAULT_WATERMARK);
		dw_i2c_config_txfifo(context->base, I2C_FIFO_DEFAULT_WATERMARK);
	}

	/* Enable I2C */
	dw_i2c_enable(context->base);

	context->status.busy = 1U;
	context->status.direction = 1U;
	/* Reset event to default */
	context->status.event = SEDI_I2C_EVENT_TRANSFER_NONE;

	context->buf = (uint8_t *)data;
	context->buf_size = num;
	context->buf_index = 0;
	context->rx_cmd_index = 0;
	context->pending = pending;

	/* FIFO fill */
	i2c_ask_data(i2c_device);
	if (context->rx_cmd_index == num && !pending)
		irq &= ~SEDI_RBFVM(I2C, INTR_MASK, M_TX_EMPTY, DISABLED);

	dw_i2c_irq_config(context->base, irq);

	return SEDI_DRIVER_OK;
}

int32_t sedi_i2c_master_poll_write(IN sedi_i2c_t i2c_device, IN uint32_t addr, IN uint8_t *data,
				   IN uint32_t num, IN bool pending)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != (addr & SEDI_RBFM(I2C, TAR, IC_TAR)), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(NULL != data, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != num, SEDI_DRIVER_ERROR_PARAMETER);

	int ret;
	struct i2c_context *context = &contexts[i2c_device];

	if (context->status.busy) {
		return SEDI_DRIVER_ERROR_BUSY;
	}

	/* Clear all status first */
	dw_i2c_clear_interrupt(context->base);
	dw_i2c_config_addr(context->base, addr);

	context->status.busy = 1U;
	context->status.direction = 0U;
	/* Reset event to default */
	context->status.event = SEDI_I2C_EVENT_TRANSFER_NONE;

	dw_i2c_enable(context->base);

	ret = dw_i2c_poll_write(context->base, data, num, pending);

	if (ret != 0) {
		context->status.event = dw_i2c_abort_analysis(context->base);
		dw_i2c_clear_interrupt(context->base);
		dw_i2c_disable(context->base);
	} else {
		context->status.event = SEDI_I2C_EVENT_TRANSFER_DONE;
	}
	context->status.busy = 0U;
	context->buf_index = num;

	return (ret == 0) ? SEDI_DRIVER_OK : SEDI_DRIVER_ERROR;
}

int32_t sedi_i2c_master_poll_read(IN sedi_i2c_t i2c_device, IN uint32_t addr, OUT uint8_t *data,
				  IN uint32_t num, IN bool pending)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != (addr & SEDI_RBFM(I2C, TAR, IC_TAR)), SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(NULL != data, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(0 != num, SEDI_DRIVER_ERROR_PARAMETER);

	int ret;
	struct i2c_context *context = &contexts[i2c_device];

	if (context->status.busy) {
		return SEDI_DRIVER_ERROR_BUSY;
	}

	/* Clear all status first */
	dw_i2c_clear_interrupt(context->base);
	dw_i2c_config_addr(context->base, addr);

	/* Enable I2C */
	dw_i2c_enable(context->base);

	context->status.busy = 1U;
	context->status.direction = 1U;
	/* Reset event to default */
	context->status.event = SEDI_I2C_EVENT_TRANSFER_DONE;

	ret = dw_i2c_poll_read(context->base, data, num, pending);

	if (ret != 0) {
		context->status.event = dw_i2c_abort_analysis(context->base);
		dw_i2c_clear_interrupt(context->base);
		dw_i2c_disable(context->base);
	}
	context->status.busy = 0U;
	context->buf_index = num;

	return (ret == 0) ? SEDI_DRIVER_OK : SEDI_DRIVER_ERROR;
}

int32_t sedi_i2c_get_data_count(IN sedi_i2c_t i2c_device)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];

	return context->buf_index;
}

int32_t sedi_i2c_control(IN sedi_i2c_t i2c_device, IN uint32_t control, IN uint32_t arg)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	int ret = 0;
	struct i2c_context *context = &contexts[i2c_device];

	switch (control) {
	case SEDI_I2C_BUS_SPEED:
		if (arg == SEDI_I2C_BUS_SPEED_STANDARD) {
			context->speed = I2C_SPEED_STANDARD;
			context->clk_info = &(context->bus_info.std_clk);
		} else if (arg == SEDI_I2C_BUS_SPEED_FAST) {
			context->speed = I2C_SPEED_FAST;
			context->clk_info = &(context->bus_info.fst_clk);
		} else if (arg == SEDI_I2C_BUS_SPEED_FAST_PLUS) {
			context->speed = I2C_SPEED_FAST_PLUS;
			context->clk_info = &(context->bus_info.fsp_clk);
		} else if (arg == SEDI_I2C_BUS_SPEED_HIGH) {
			context->speed = I2C_SPEED_HIGH;
			context->clk_info = &(context->bus_info.high_clk);
		} else {
			ret = SEDI_DRIVER_ERROR;
		}
		dw_i2c_disable(context->base);
		dw_i2c_config_speed(context->base, context->speed,
		       context->clk_info);
		break;

	/* force i2c enter IDLE mode */
	case SEDI_I2C_ABORT_TRANSFER:
		if (context->tx_dma_chan > SEDI_I2C_DMA_CHANNEL_UNUSED) {
			sedi_dma_abort_transfer(context->tx_dma_dev,
						context->tx_dma_chan);
			context->tx_dma_chan = SEDI_I2C_DMA_CHANNEL_UNUSED;
		}
		if (context->rx_dma_chan > SEDI_I2C_DMA_CHANNEL_UNUSED) {
			sedi_dma_abort_transfer(context->rx_dma_dev,
						context->rx_dma_chan);
			context->rx_dma_chan = SEDI_I2C_DMA_CHANNEL_UNUSED;
		}
		dw_i2c_abort(context);
		context->pending = 0;
		context->status.busy = 0;
		break;
	case SEDI_I2C_SET_TX_MEMORY_TYPE:
		context->tx_memory_type = arg;
		break;
	case SEDI_I2C_SET_RX_MEMORY_TYPE:
		context->rx_memory_type = arg;
		break;
	default:
		ret = SEDI_DRIVER_ERROR;
		break;
	}

	if (ret != 0) {
		return SEDI_DRIVER_ERROR;
	}

	return SEDI_DRIVER_OK;
}

int sedi_i2c_get_status(IN sedi_i2c_t i2c_device, sedi_i2c_status_t *status)
{
	DBG_CHECK(i2c_device < SEDI_I2C_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(NULL != status, SEDI_DRIVER_ERROR_PARAMETER);

	struct i2c_context *context = &contexts[i2c_device];

	*status = context->status;

	return SEDI_DRIVER_OK;
}

static void i2c_isr_recv(sedi_i2c_t i2c_device)
{
	struct i2c_context *context = &contexts[i2c_device];
	sedi_i2c_regs_t *i2c = (sedi_i2c_regs_t *)(context->base);
	uint32_t data_remain;

	/* Receive all data from FIFO */
	uint32_t size = SEDI_PREG_RBFV_GET(I2C, RXFLR, RXFLR, &i2c->rxflr);

	if (context->rx_cmd_index < size) {
		uint32_t dummy;

		while (size) {
			dummy = i2c->data_cmd;
			size--;
		}
		(void)dummy;

		return;
	}

	while (size > 0) {
		context->buf[context->buf_index] = SEDI_PREG_RBFV_GET(I2C,
				DATA_CMD, DAT, &i2c->data_cmd);
		context->buf_index++;
		size--;
	}

	/* If need to change watermark */
	data_remain = context->buf_size - context->buf_index;
	if ((data_remain <= SEDI_PREG_RBFV_GET(I2C, RX_TL, RX_TL, &i2c->rx_tl)) &&
			(data_remain != 0)) {
		SEDI_PREG_RBF_SET(I2C, RX_TL, RX_TL, data_remain - 1, &i2c->rx_tl);
	}
}

static void i2c_isr_complete(sedi_i2c_t i2c_device, bool is_error)
{
	struct i2c_context *context = &contexts[i2c_device];
	sedi_i2c_regs_t *regs = (void *)context->base;
	uint32_t val;

	dw_i2c_irq_config(context->base, 0);

	dw_i2c_config_txfifo(context->base, 0);
	dw_i2c_config_rxfifo(context->base, 0);

	if (context->status.event == SEDI_I2C_EVENT_TRANSFER_NONE) {
		if (is_error) {
			context->status.event = dw_i2c_abort_analysis(context->base);
		} else {
			context->status.event = SEDI_I2C_EVENT_TRANSFER_DONE;
		}
	}

	/* Flush FIFO */
	if (context->status.event != SEDI_I2C_EVENT_TRANSFER_DONE) {
		dw_i2c_disable(context->base);
	}

	context->pending = 0;
	context->status.busy = 0;

	/* Clear all interrupt, this will clear abort source register*/
	val = regs->clr_intr;
	dw_i2c_clear_interrupt(context->base);

	if (context->cb_event) {
		context->cb_event(context->status.event);
	}
	PARAM_UNUSED(val);
}

void sedi_i2c_isr_handler(IN sedi_i2c_t i2c_device)
{
	struct i2c_context *context = &contexts[i2c_device];
	sedi_i2c_regs_t *regs = (void *)context->base;
	uint32_t stat, val;

	/* Return if enter into isr unexpectedly */
	if (context->status.busy == 0) {
		return;
	}

	/* Get interrupt status */
	stat = regs->intr_stat;

	/* If error happened, go to end*/
	if (stat & BSETS_INTR_ERROR) {
		i2c_isr_complete(i2c_device, true);
		return;
	}

	/* check if there is a entity in rx fifo */
	if (SEDI_PREG_RBFV_IS_SET(I2C, INTR_STAT, R_RX_FULL, ACTIVE, &stat)) {
		i2c_isr_recv(i2c_device);
		/* For receive with no STOP, while all data received, ended */
		if ((context->buf_index == context->buf_size) && (context->pending)) {
			i2c_isr_complete(i2c_device, false);
			return;
		}
	}

	/* For transfer need STOP flag, use STOP as transfer end condition */
	if ((SEDI_PREG_RBFV_IS_SET(I2C, INTR_STAT, R_STOP_DET, ACTIVE, &stat)) &&
			(context->pending == 0)) {
		/* Clear stop detect interrupt */
		val = regs->clr_stop_det;
		i2c_isr_complete(i2c_device, false);
		return;
	}

	/* For send with no STOP, while TX FIFO empty, ended */
	if ((context->pending) && (context->buf_index == context->buf_size) &&
	    (SEDI_PREG_RBFV_IS_SET(I2C, INTR_STAT, R_TX_EMPTY, ACTIVE, &stat))) {
		i2c_isr_complete(i2c_device, false);
		return;
	}

	/* TX empty condition */
	if (SEDI_PREG_RBFV_IS_SET(I2C, INTR_STAT, R_TX_EMPTY, ACTIVE, &stat)) {
		/*If it is read operation, need to send cmd*/
		if (context->status.direction == 1) {
			i2c_ask_data(i2c_device);
		} else {
			i2c_send(i2c_device);
		}
	}
	PARAM_UNUSED(val);
}
