/*
 * Copyright (c) 2020-2024 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "i3c_hci.h"
#include "sedi_driver_pm.h"

#define HCI_INFO(...)           i3c_log(ctx, SEDI_I3C_LOG_INFO, __VA_ARGS__)
#define HCI_WARNING(...)        i3c_log(ctx, SEDI_I3C_LOG_WARNING, __VA_ARGS__)
#define HCI_ERR(...)            i3c_log(ctx, SEDI_I3C_LOG_ERR, __VA_ARGS__)
#define HCI_DEBUG(...)          i3c_log(ctx, SEDI_I3C_LOG_DEBUG, __VA_ARGS__)

/*
 *    bus speed(Hz)        Auto  100K  400K  1M   2M   4M   6M  8M  10M MAX
 *    high/low time(ns)
 */
static uint32_t htime[] = {1250, 5000, 1250, 500, 250, 130, 83, 63, 50, 50};
static uint32_t ltime[] = {1250, 5000, 1250, 500, 250, 130, 84, 64, 50, 50};

#define  TIME_TO_CNT(base_freq, time_ns)  (base_freq * (time_ns) / 1000)
#define  SPEED_TO_HCNT(base_freq, index)  TIME_TO_CNT(base_freq, htime[index])
#define  SPEED_TO_LCNT(base_freq, index)  TIME_TO_CNT(base_freq, ltime[index])

#define MODE_TO_REG_VALUE(value) ((value) >= SEDI_I3C_XFER_SDR0 ? \
	(value) - SEDI_I3C_XFER_SDR0 : (value))

sedi_i3c_context_t sedi_i3c_contexts[SEDI_I3C_NUM] = {0};

static void i3c_log(sedi_i3c_context_t *ctx, sedi_i3c_log_priority_t priority,
	const char *message, ...)
{
	if (!ctx->log_cb)
		return;

	va_list vargs;
	va_start(vargs, message);
	ctx->log_cb(priority, message, vargs);
	va_end(vargs);
}

static void i3c_udelay(sedi_i3c_context_t *ctx, uint32_t udelay)
{
	if (ctx->udelay_cb) {
		ctx->udelay_cb(udelay);
	} else {
		uint32_t tmp = 0;
		for (int i = 0; i < 10 * udelay; i++)
			tmp++;
	}
}

static int i3c_write_cmd_port(sedi_i3c_context_t *ctx, uint32_t cmd_low, uint32_t cmd_high)
{
	/* write low command first */
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	regs->command_queue_port = cmd_low;
	regs->command_queue_port = cmd_high;

	return SEDI_DRIVER_OK;
}

static uint32_t i3c_intr_read(sedi_i3c_context_t *ctx, intr_reg_t intr_reg)
{
	uint32_t intr = 0;
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	switch (intr_reg) {
	case INTR_REG_STATUS:
		intr = SEDI_PREG_GET(I3C, INTR_STATUS, &regs->intr_status);
		intr |= (SEDI_PREG_GET(I3C, PIO_INTR_STATUS, &regs->pio_intr_status) & PIO_INTR_MASK);
		break;
	case INTR_REG_STATUS_ENABLE:
		intr = SEDI_PREG_GET(I3C, INTR_STATUS_ENABLE, &regs->intr_status_enable);
		intr |= (SEDI_PREG_GET(I3C, PIO_INTR_STATUS_ENABLE, &regs->pio_intr_status_enable) & PIO_INTR_MASK);
		break;
	case INTR_REG_SIGNAL_ENABLE:
		intr = SEDI_PREG_GET(I3C, INTR_SIGNAL_ENABLE, &regs->intr_signal_enable);
		intr |= (SEDI_PREG_GET(I3C, PIO_INTR_SIGNAL_ENABLE, &regs->pio_intr_signal_enable) & PIO_INTR_MASK);
		break;
	case INTR_REG_FORCE:
		intr = SEDI_PREG_GET(I3C, INTR_FORCE, &regs->intr_force);
		intr |= (SEDI_PREG_GET(I3C, PIO_INTR_FORCE, &regs->pio_intr_force) & PIO_INTR_MASK);
		break;
	default:
		break;
	}

	return intr;
}

static void i3c_intr_write(sedi_i3c_context_t *ctx,
	intr_reg_t intr_reg, uint32_t value)
{
	uint32_t intr = value & INTR_MASK;
	uint32_t pio_intr = value & PIO_INTR_MASK;
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	switch (intr_reg) {
	case INTR_REG_STATUS:
		regs->intr_status = intr;
		regs->pio_intr_status = pio_intr;
		break;
	case INTR_REG_STATUS_ENABLE:
		regs->intr_status_enable = intr;
		regs->pio_intr_status_enable = pio_intr;
		break;
	case INTR_REG_SIGNAL_ENABLE:
		regs->intr_signal_enable = intr;
		regs->pio_intr_signal_enable = pio_intr;
		break;
	case INTR_REG_FORCE:
		regs->intr_force = intr;
		regs->pio_intr_force = pio_intr;
		break;
	default:
		break;
	}

	if (intr_reg == INTR_REG_STATUS_ENABLE) {
		ctx->restore_reg.intr_en[0] = intr;
		ctx->restore_reg.pio_intr_en[0] = pio_intr;
	} else if (intr_reg == INTR_REG_SIGNAL_ENABLE) {
		ctx->restore_reg.intr_en[1] = intr;
		ctx->restore_reg.pio_intr_en[1] = pio_intr;
	}
}

static void i3c_hci_hw_init(sedi_i3c_context_t *ctx)
{
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	/* reset HCI controller */
	regs->reset_control = DEVICE_RESET_ALL;
	i3c_udelay(ctx, 1000);
	regs->reset_control = DEVICE_SOFT_RESET;
	i3c_udelay(ctx, 1000);

	/* disable HCI controller */
	SEDI_PREG_RBF_SET(I3C, HC_CONTROL, BUS_ENABLE, 0, &regs->hc_control);

	i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, 0);

	/* clear interrupt status */
	i3c_intr_write(ctx, INTR_REG_STATUS, 0);
	SEDI_PREG_SET(I3C, HC_CONTROL, 0, &regs->hc_control);

	/* clear response queue */
	SEDI_PREG_GET(I3C, RESPONSE_QUEUE_PORT, &regs->response_queue_port);

	/* config i3c controller dynamic address */
	SEDI_PREG_RBF_SET(I3C, MASTER_DEVICE_ADDR, DYNAMIC_ADDR_VALID, 1, &regs->master_device_addr);
	SEDI_PREG_RBF_SET(I3C, MASTER_DEVICE_ADDR, DYNAMIC_ADDR, DYNAMIC_ADDRESS, &regs->master_device_addr);
	ctx->restore_reg.dev_addr = regs->master_device_addr;

	uint32_t dev_ctrl = regs->hc_control;

	dev_ctrl |= (SEDI_RBFVM(I3C, HC_CONTROL, IBA_INCLUDE, INCLUDED) |
			SEDI_RBFVM(I3C, HC_CONTROL, I2C_SLAVE_PRESENT, PRESENT));
	SEDI_PREG_SET(I3C, HC_CONTROL, dev_ctrl, &regs->hc_control);

	return;
}

static int i3c_detect_capabilites(sedi_i3c_context_t *ctx)
{
	int ret = SEDI_DRIVER_OK;
	uint32_t sec_offset;
	ext_cap_header_t cap_header = {0};
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	sec_offset = regs->hci_version;
	if (0 == sec_offset) {
		HCI_ERR("Invalid DEVICE_HCI_VERSION: 0\n");
	}

	HCI_DEBUG("Valid DEVICE_HCI_VERSION: 0\n");

	/* Get pio offset. */
	sec_offset = regs->pio_section_offset;
	if (0 == sec_offset || sec_offset > I3C_MMIO_MAX) {
		HCI_ERR("Invalid PIO section offset: 0\n");
		ret = SEDI_DRIVER_ERROR;
		goto exit;
	} else {
		ctx->pio_offset = sec_offset;
	}

	/* 2^SIZE DWORDS */
	ctx->tx_fifo_size = 2 << (SEDI_PREG_RBFV_GET(I3C, QUEUE_SIZE_CTRL,
				 TX_DATA_BUFFER_SIZE, &regs->queue_size_ctrl));
	ctx->rx_fifo_size = 2 << (SEDI_PREG_RBFV_GET(I3C, QUEUE_SIZE_CTRL,
				 RX_DATA_BUFFER_SIZE, &regs->queue_size_ctrl));


	/* Loop extended capabilities. */
	sec_offset = SEDI_PREG_RBFV_GET(I3C, EXTCAPS_SECTION_OFFSET,
			SECTION_OFFSET, &regs->extcaps_section_offset);
	if (0 == sec_offset || sec_offset > I3C_MMIO_MAX) {
		HCI_ERR("Invalid extended capabilities section offset: 0\n");
		ret = SEDI_DRIVER_ERROR;
		goto exit;
	}

	while (true) {
		if (sec_offset > I3C_MMIO_MAX) {
			break;
		}
		cap_header = (ext_cap_header_t)i3c_mmio_read(sec_offset);
		switch (cap_header.cap_id) {
		case EXT_CAP_INVALID:
			break;
		case EXT_CAP_DEBUG:
			ctx->debug_offset = sec_offset;
			HCI_DEBUG("Debug section detected, id = 0x%02X, offset = 0x%03X\n",
				EXT_CAP_DEBUG, sec_offset);
			break;
		case EXT_CAP_VENDER_C0:
			ctx->timing_offset = sec_offset;
			HCI_DEBUG("Timing section detected, id = 0x%02X, offset = 0x%03X\n",
				EXT_CAP_VENDER_C0, sec_offset);
			break;
		default:
			HCI_DEBUG("Ignore extended capability, id = 0x%02X, offset = 0x%03X\n",
				cap_header.cap_id, sec_offset);
			break;
		}

		if (EXT_CAP_INVALID == cap_header.cap_id)
			break;

		if (cap_header.cap_length > 0) {
			sec_offset += cap_header.cap_length * 4;
		} else {
			ret = SEDI_DRIVER_ERROR;
			goto exit;
		}
	}

	/* check section bases */
	if (ctx->debug_offset == 0 || ctx->timing_offset == 0) {
		HCI_ERR("capability missing\n");
		ret = SEDI_DRIVER_ERROR;
		goto exit;
	}

exit:
	return ret;
}

static void i3c_pio_timing_config(sedi_i3c_t bus)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	sedi_i3c_timing_config(bus, SEDI_TIMING_OD,  SEDI_I3C_SPEED_400KHZ, NULL);
	sedi_i3c_timing_config(bus, SEDI_TIMING_PP,  SEDI_I3C_SPEED_400KHZ, NULL);
	sedi_i3c_timing_config(bus, SEDI_TIMING_FM,  SEDI_I3C_SPEED_400KHZ, NULL);
	sedi_i3c_timing_config(bus, SEDI_TIMING_FMP, SEDI_I3C_SPEED_400KHZ, NULL);
	sedi_i3c_timing_config(bus, SEDI_TIMING_SS,  SEDI_I3C_SPEED_400KHZ, NULL);

	regs->bus_free_timing = I3C_MST_FREE_DEFAULT;
	ctx->restore_reg.bus_free_timing = I3C_MST_FREE_DEFAULT;
}

static void i3c_pio_mode_init(sedi_i3c_context_t *ctx)
{
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);
	/* set PIO mode Queue Threshold Control Register */
	uint32_t queue_thld_ctrl = SEDI_RBFM_VALUE(I3C, QUEUE_THLD_CTRL, CMD_EMPTY_BUF_THLD, CMD_DEFAULT) |
			SEDI_RBFM_VALUE(I3C, QUEUE_THLD_CTRL, RESP_BUF_THLD, 0) |
			SEDI_RBFM_VALUE(I3C, QUEUE_THLD_CTRL, IBI_DATA_THLD, IBI_DATA_DEFAULT) |
			SEDI_RBFM_VALUE(I3C, QUEUE_THLD_CTRL, IBI_STATUS_THLD, 0);

	regs->queue_thld_ctrl = queue_thld_ctrl;
	ctx->restore_reg.thld_ctrl[0] = queue_thld_ctrl;

	i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, 0);

	/* Clear PIO mode Data Buffer Threshold Control Register */
	regs->data_buffer_thld_ctrl = 0;
	ctx->restore_reg.thld_ctrl[1] = 0;

	/* enable all interrupt status */
	i3c_intr_write(ctx, INTR_REG_STATUS_ENABLE, INTR_STATUS_ALL_EN);

	return;
}

/* copy data from buf to cpu-endian u32 */
static uint32_t buf_to_u32(const uint8_t *buf, uint32_t len)
{
	uint32_t tmp = 0x0;
	int index = 0;

	if (len > 4 || !buf)
		return 0;

	while (index < len) {
		tmp |= (uint32_t)(buf[index] << (8 * index));
		index++;
	}

	return tmp;
}

/* copy data from cpu-endian u32 to buf */
static void u32_to_buf(uint8_t *buf, uint32_t val, uint32_t len)
{
	int index = 0;

	if (len > 4 || !buf)
		return;

	while (index < len) {
		buf[index] = (val >> (8 * index)) & 0xFF;
		index++;
	}
}

static void i3c_read_fifo(sedi_i3c_context_t *ctx)
{
	int rx_valid = 0;
	uint32_t rx_data;
	int copy_len;
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	while (ctx->buf_index < ctx->buf_len) {
		rx_valid = SEDI_PREG_RBFV_GET(I3C, DATA_BUFFER_STATUS_LEVEL,
				RX_BUF_LVL, &regs->data_buffer_status_level);
		if (!rx_valid)
			break;
		rx_data = regs->tx_data_port;
		copy_len = ctx->buf_len - ctx->buf_index >= 4 ? 4 : ctx->buf_len - ctx->buf_index;
		u32_to_buf(ctx->buf + ctx->buf_index, rx_data, copy_len);
		ctx->buf_index += copy_len;
	}

	return;
}

static void i3c_write_fifo(sedi_i3c_context_t *ctx)
{
	int tx_valid = 0;
	uint32_t tx_data;
	int copy_len;
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	while (ctx->buf_index < ctx->buf_len) {
		tx_valid = SEDI_PREG_RBFV_GET(I3C, DATA_BUFFER_STATUS_LEVEL,
				TX_BUF_FREE_LVL, &regs->data_buffer_status_level);
		if (!tx_valid)
			break;
		copy_len = ctx->buf_len - ctx->buf_index >= 4 ? 4 : ctx->buf_len - ctx->buf_index;
		tx_data = buf_to_u32(ctx->buf + ctx->buf_index, copy_len);
		regs->tx_data_port = tx_data;
		ctx->buf_index += copy_len;
	}
}

void i3c_update_resp_thld(sedi_i3c_context_t *ctx, uint8_t resp_thld)
{
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	/* value in register same with set value, just return */
	if ((SEDI_PREG_RBFV_GET(I3C, QUEUE_THLD_CTRL, RESP_BUF_THLD,
		&regs->queue_thld_ctrl)) == (resp_thld - 1)) {
		return;
	}

	SEDI_PREG_RBF_SET(I3C, QUEUE_THLD_CTRL, RESP_BUF_THLD, (resp_thld - 1),
			&regs->queue_thld_ctrl);

	return;
}

static void i3c_update_buffer_thld(sedi_i3c_context_t *ctx)
{
	uint8_t thld = 0x2;
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	if (!ctx->buf)
		return;

	if (ctx->buf_len - ctx->buf_index <= 32) /* 2 -> 8DW = 32bytes */
		thld = 0;
	else
		thld = 2;

	if (ctx->direction == SEDI_I3C_WRITE) {
		SEDI_PREG_RBF_SET(I3C, DATA_BUFFER_THLD_CTRL, TX_BUF_THLD, thld,
				&regs->data_buffer_thld_ctrl);
	} else {
		SEDI_PREG_RBF_SET(I3C, DATA_BUFFER_THLD_CTRL, RX_BUF_THLD, thld,
				&regs->data_buffer_thld_ctrl);
	}

	return;
}

/*
 * I3C controller loses DAT after entering/exiting clock gating
 * restore the DAT, otherwise all I3C transactions fail
 */
static void i3c_restore_dat(sedi_i3c_context_t *ctx)
{
	/* update DAT */
	for (int i = 0; i < SEDI_I3C_DEVICE_NUM_MAX; i++) {
		i3c_mmio_write(DEV_ADDR_TBL_START + 8 * i, ctx->restore_reg.dat_sec[i].low);
		i3c_mmio_write(DEV_ADDR_TBL_START + 8 * i + 4, ctx->restore_reg.dat_sec[i].high);
	}
	return;
}

static void i3c_reg_restore(sedi_i3c_context_t *ctx)
{
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	if (!ctx->initialized)
		return;

	i3c_restore_dat(ctx);

	/* update DEVICE_ADDR */
	regs->master_device_addr = ctx->restore_reg.dev_addr;

	/* update Interrupt register */
	regs->intr_status_enable = ctx->restore_reg.intr_en[0];
	regs->intr_signal_enable = ctx->restore_reg.intr_en[1];
	regs->pio_intr_status_enable = ctx->restore_reg.pio_intr_en[0];
	regs->pio_intr_signal_enable = ctx->restore_reg.pio_intr_en[1];

	/* update threshold control */
	regs->queue_thld_ctrl = ctx->restore_reg.thld_ctrl[0];
	regs->data_buffer_thld_ctrl = ctx->restore_reg.thld_ctrl[1];

	/* update timing */
	regs->scl_i3c_od_timing = ctx->restore_reg.od_timing;
	regs->scl_i3c_pp_timing = ctx->restore_reg.pp_timing;
	regs->scl_i2c_fm_timing = ctx->restore_reg.fm_timing;
	regs->scl_i2c_fmp_timing = ctx->restore_reg.fmp_timing;
	regs->scl_i2c_ss_timing = ctx->restore_reg.ss_timing;
	regs->bus_free_timing = ctx->restore_reg.bus_free_timing;
	regs->scl_ext_termn_lcnt_timing = ctx->restore_reg.termn_timing;

	/* update DEVICE_CTRL */
	regs->hc_control = ctx->restore_reg.dev_ctrl;
}

static void i3c_handle_ibi(sedi_i3c_context_t *ctx)
{
	uint32_t ibi_port;
	uint8_t addr, blen, wlen;
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);
	int index, i;
	int copy_len;

	ibi_port = regs->ibi_port;
	/* handled with NACK, nothing to do */
	if (ibi_port & IBI_STS) {
		return;
	}

	addr = (ibi_port >> 9) & 0x7f;
	blen = ibi_port & 0xff;
	wlen = (blen + 3) / 4;

	if (blen > SEDI_I3C_MAX_IBI_PAYLOAD_LEN) {
		/* clear IBI PORT data */
		for (i = 0; i < wlen; i++)
			SEDI_PREG_GET(I3C, IBI_PORT, &regs->ibi_port);
		return;
	}

	ctx->ibi.ibi_address = addr;
	ctx->ibi.ibi_len = blen;
	index = 0;
	for (i = 0; i < wlen; i++) {
		ibi_port = regs->ibi_port;
		copy_len = blen - index >= 4 ? 4 : blen - index;
		u32_to_buf(ctx->ibi.ibi_payload + index, ibi_port, copy_len);
		index += copy_len;
	}

	return;
}

#define DEFAULT_TERMN_LCNT	0x30000
int sedi_i3c_timing_config(sedi_i3c_t bus,
	sedi_i3c_timing_type_t type, sedi_i3c_speed_t speed,
	p_sedi_i3c_timing_t timing)
{
	uint32_t hcnt;
	uint32_t lcnt;
	uint32_t value;
	int ret = SEDI_DRIVER_OK;
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	if (timing && timing->l_time != 0 && timing->h_time != 0) {
		hcnt = TIME_TO_CNT(ctx->base_freq, timing->h_time);
		lcnt = TIME_TO_CNT(ctx->base_freq, timing->l_time);
	} else {
		hcnt = TIME_TO_CNT(ctx->base_freq, htime[speed]);
		lcnt = TIME_TO_CNT(ctx->base_freq, ltime[speed]);

		/* tune 1MHZ i2c speed a little slower */
		if (type == SEDI_TIMING_FMP && speed >= SEDI_I3C_SPEED_1MHZ) {
			lcnt = (lcnt * 12) / 10;
			hcnt = (hcnt * 12) / 10;
		}
	}

	if (lcnt < 5 || hcnt < 5) {
		HCI_ERR("%s(%d), lcnt %d and hcnt %d should be no less than 5 due to i3c controller restriction\n",
			__func__, __LINE__, lcnt, hcnt);
		return SEDI_DRIVER_ERROR;
	}

	value = I3C_SCL_TIMING(hcnt, lcnt);

	switch (type) {
	case SEDI_TIMING_OD:
		regs->scl_i3c_od_timing = value;
		regs->scl_ext_termn_lcnt_timing = (DEFAULT_TERMN_LCNT + 6);
		ctx->restore_reg.od_timing = value;
		ctx->restore_reg.termn_timing = (DEFAULT_TERMN_LCNT + 6);
		break;
	case SEDI_TIMING_PP:
		regs->scl_i3c_pp_timing = value;
		regs->scl_ext_termn_lcnt_timing = (DEFAULT_TERMN_LCNT + 6);
		ctx->restore_reg.pp_timing = value;
		ctx->restore_reg.termn_timing = (DEFAULT_TERMN_LCNT + 6);
		break;
	case SEDI_TIMING_FM:
		regs->scl_i2c_fm_timing = value;
		ctx->restore_reg.fm_timing = value;
		break;
	case SEDI_TIMING_FMP:
		regs->scl_i2c_fmp_timing = value;
		ctx->restore_reg.fmp_timing = value;
		break;
	case SEDI_TIMING_SS:
		regs->scl_i2c_ss_timing = value;
		ctx->restore_reg.ss_timing = value;
		break;
	default:
		ret = SEDI_DRIVER_ERROR_PARAMETER;
		goto exit;
	}

exit:
	return ret;
}

int sedi_i3c_context_init(IN sedi_i3c_t bus,
	IN uint32_t *base,
	IN sedi_i3c_log_cb_t log_cb,
	IN sedi_i3c_udelay_cb_t udelay_cb,
	IN sedi_i3c_event_cb_t event_cb,
	IN sedi_i3c_ibi_cb_t ibi_cb,
	IN void *prv_data)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];

	if (NULL == base)
		return SEDI_DRIVER_ERROR_PARAMETER;

	ctx->base = (uint32_t *)base;
	ctx->prv_data = (void *)prv_data;
	ctx->log_cb = log_cb;
	ctx->udelay_cb = udelay_cb;
	ctx->event_cb = event_cb;
	ctx->ibi_cb = ibi_cb;
	ctx->buf = (uint8_t *)0;
	ctx->direction = SEDI_I3C_DIRECTION_INVALID;

	ctx->base_freq = sedi_pm_get_lbw_clock() / 1000000;
	HCI_DEBUG("I3C base clock frequency from pm is %d\n", ctx->base_freq);

	return SEDI_DRIVER_OK;
}

int sedi_i3c_controller_init(sedi_i3c_t bus)
{
	int ret = SEDI_DRIVER_OK;
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];

	if (ctx->initialized)
		goto exit;

	ret = i3c_detect_capabilites(ctx);

	if (ret != SEDI_DRIVER_OK) {
		HCI_ERR("i3c_detect_capabilities error!\n");
		goto exit;
	};

	/* initialize other HW settings */
	i3c_hci_hw_init(ctx);

	i3c_pio_timing_config(bus);

	i3c_pio_mode_init(ctx);

	ctx->initialized = true;

exit:
	return ret;
}

void sedi_i3c_isr(sedi_i3c_t bus)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);
	uint32_t interrupts = 0;
	uint32_t event = 0;
	uint32_t response = 0;
	bool done = false;

	interrupts = i3c_intr_read(ctx, INTR_REG_STATUS);

	/* clear IRQ status */
	i3c_intr_write(ctx, INTR_REG_STATUS, interrupts);

	/* get masked interrupt status */
	interrupts &= i3c_intr_read(ctx, INTR_REG_SIGNAL_ENABLE);

	if (SEDI_PREG_RBFV_IS_SET(I3C, PIO_INTR_STATUS, RESP_READY_STAT, 1, &interrupts)) {
		response = regs->response_queue_port;
		event = ((response & RESP_ERR_STATUS_MASK) >> RESP_ERR_STATUS_SHIFT);
		done = true;
	}

	if (SEDI_PREG_RBFV_IS_SET(I3C, INTR_STATUS, HC_INTERNAL_ERR_STAT, 1, &interrupts)) {
		/* host controller non-recoverable internal error, reset? */
		event |= SEDI_I3C_EVENT_INTERNAL_ERR;
		done = true;
		goto exit;
	}

	if (SEDI_PREG_RBFV_IS_SET(I3C, PIO_INTR_STATUS, IBI_STATUS_THLD_STAT, 1, &interrupts)) {
		i3c_handle_ibi(ctx);
		ctx->ibi_cb(&ctx->ibi, ctx->prv_data);
	}

	if (SEDI_PREG_RBFV_IS_SET(I3C, PIO_INTR_STATUS, RX_THLD_STAT, 1, &interrupts) &&
			ctx->direction == SEDI_I3C_READ) {
		i3c_read_fifo(ctx);
		i3c_update_buffer_thld(ctx);
	}

	if (SEDI_PREG_RBFV_IS_SET(I3C, PIO_INTR_STATUS, TX_THLD_STAT, 1, &interrupts) &&
		ctx->direction == SEDI_I3C_WRITE) {
		i3c_write_fifo(ctx);
		i3c_update_buffer_thld(ctx);
		/* signal enable update */
		if (ctx->buf_index >= ctx->buf_len) {
			ctx->intr_signal_mask &= ~INTR_STATUS_TX_THLD_EN;
		}
	}

	/* if r/w finishes but without a ROC */
	if (ctx->buf && ctx->buf_index >= ctx->buf_len &&
		(ctx->position == SEDI_I3C_POS_CONTINUE || ctx->position == SEDI_I3C_POS_FIRST)) {
		/* go to next transfer */
		done = true;
		event = 0;
	}

exit:
	if (done) {
		ctx->event_cb(event, ctx->prv_data);
		ctx->intr_signal_mask = 0;
	}

	i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, ctx->intr_signal_mask);
}

uint32_t sedi_i3c_dat_entry_assembler(uint8_t static_addr, uint8_t dynamic_addr)
{
	return I3C_DAT_ENTRY_ASSEMBLER(static_addr, IBI_WITH_PAYLOAD,
			dynamic_addr == 0 ? SEDI_SIR_REJECT : SEDI_SIR_ACCEPT, SEDI_MR_ACCEPT,
			IBI_TIME_STAMPING_OFF, dynamic_addr, 0,
			dynamic_addr == 0 ? 1 : 0);
}

void sedi_i3c_set_dat_entry(sedi_i3c_t bus, int index, uint32_t low, uint32_t high)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];

	i3c_mmio_write(DEV_ADDR_TBL_START + 8 * index, low);
	i3c_mmio_write(DEV_ADDR_TBL_START + 8 * index + 4, high);
	ctx->restore_reg.dat_sec[index].low = low;
	ctx->restore_reg.dat_sec[index].high = high;
}

void sedi_i3c_get_dat_entry(sedi_i3c_t bus, int index, uint32_t *low, uint32_t *high)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];

	if (low) {
		*low = i3c_mmio_read(DEV_ADDR_TBL_START + 8 * index);
	}

	if (high) {
		*high = i3c_mmio_read(DEV_ADDR_TBL_START + 8 * index + 4);
	}
}

void sedi_i3c_get_dct_entry(sedi_i3c_t bus, int index,
	uint32_t *loc1, uint32_t *loc2, uint32_t *loc3, uint32_t *loc4)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];

	if (loc1)
		*loc1 = i3c_mmio_read(DEV_CHAR_TBL_START + index * 16);
	if (loc2)
		*loc2 = i3c_mmio_read(DEV_CHAR_TBL_START + index * 16 + 4);
	if (loc3)
		*loc3 = i3c_mmio_read(DEV_CHAR_TBL_START + index * 16 + 8);
	if (loc4)
		*loc4 = i3c_mmio_read(DEV_CHAR_TBL_START + index * 16 + 12);
}

int sedi_i3c_hci_enable(sedi_i3c_t bus, bool en)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	if (en) {
		SEDI_PREG_RBF_SET(I3C, HC_CONTROL, BUS_ENABLE, 1, &regs->hc_control);
	} else {
		SEDI_PREG_RBF_SET(I3C, HC_CONTROL, BUS_ENABLE, 0, &regs->hc_control);
	}

	ctx->restore_reg.dev_ctrl = regs->hc_control;

	return SEDI_DRIVER_OK;
}

int sedi_i3c_address_assign(sedi_i3c_t bus, int index, uint8_t count, bool is_daa)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	int ret = SEDI_DRIVER_OK;
	uint32_t cmd_low = 0;
	uint32_t cmd_high = 0;

	ctx->intr_signal_mask = INTR_STATUS_RESP_READY_EN | INTR_STATUS_TRX_ABT_EN \
		| INTR_STATUS_TRX_ERR_EN | INTR_STATUS_HC_INTERNAL_ERR_EN;
	i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, ctx->intr_signal_mask);

	cmd_low = I3C_CMD_AAC_ASSEMBLER(
		I3C_CMD_ATTR_ASSGN_CMD,
		I3C_CMD_ADDR_ASSGN_TID,
		is_daa ? I3C_CCC_ENTDAA : I3C_CCC_SETDASA,
		index,
		count,
		I3C_CMD_ROC_REQUIRED,
		I3C_CMD_TOC_STOP
	);

	HCI_DEBUG("%s(%d), dev_index:0x%x, cmd_type:%s, cmd_low:0x%x, num:%d\n",
			__func__, __LINE__, index, is_daa ? "ENTDAA" : "SETDASA", cmd_low, count);

	i3c_write_cmd_port(ctx, cmd_low, cmd_high);

	return ret;
}

int sedi_i3c_immediate_write(IN sedi_i3c_t bus,
	IN uint8_t dev_index, IN uint8_t cmd_code, IN sedi_i3c_xfer_mode_t mode,
	IN uint8_t *buf, IN int8_t length,
	IN sedi_i3c_position_t position)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	int ret = SEDI_DRIVER_OK;
	uint32_t cmd_low = 0;
	uint32_t cmd_high = 0;

	bool cp = 0;
	if (mode == SEDI_I3C_XFER_HDR_DDR || cmd_code != 0) {
		cp = 1;
	}

	if (length > 4) {
		ret = SEDI_DRIVER_ERROR_PARAMETER;
		goto exit;
	}

	ctx->position = position;

	ctx->intr_signal_mask = INTR_STATUS_RESP_READY_EN | INTR_STATUS_TRX_ABT_EN \
		| INTR_STATUS_TRX_ERR_EN | INTR_STATUS_HC_INTERNAL_ERR_EN;
	i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, ctx->intr_signal_mask);

	if (position == SEDI_I3C_POS_FIRST || position == SEDI_I3C_POS_CONTINUE) {
		cmd_low = I3C_CMD_IMM_ASSEMBLER(I3C_CMD_ATTR_IMMED_DATA_XFER, I3C_DIRECT_WR_TID, cmd_code, cp,
			dev_index, length, MODE_TO_REG_VALUE(mode), 0, 0, 0);
	} else {
		cmd_low = I3C_CMD_IMM_ASSEMBLER(I3C_CMD_ATTR_IMMED_DATA_XFER, I3C_DIRECT_WR_TID, cmd_code, cp,
			dev_index, length, MODE_TO_REG_VALUE(mode), 0, I3C_CMD_ROC_REQUIRED, I3C_CMD_TOC_STOP);
	}

	cmd_high = buf_to_u32(buf, length);

	HCI_DEBUG("%s(%d), cmd_low:0x%x, cmd_high:0x%x, cmd_code:0x%x, dev_index:0x%x\n",
			__func__, __LINE__, cmd_low, cmd_high, cmd_code, dev_index);

	ret = i3c_write_cmd_port(ctx, cmd_low, cmd_high);
	if (unlikely(ret)) {
		HCI_ERR("sedi_i3c_immediate_write error\n");
		return ret;
	}

	if (position == SEDI_I3C_POS_FIRST || position == SEDI_I3C_POS_CONTINUE) {
		ctx->event_cb(0, ctx->prv_data);
		ctx->intr_signal_mask = 0;
		i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, ctx->intr_signal_mask);
	}

exit:
	return ret;
}

int sedi_i3c_regular_xfer(sedi_i3c_t bus,
	uint8_t dev_index, uint8_t cmd_code, sedi_i3c_xfer_mode_t mode,
	uint8_t *buf, uint32_t length,
	sedi_i3c_direction_t direction,
	sedi_i3c_position_t position)
{
	int ret = SEDI_DRIVER_OK;
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	regular_cmd_desc_t cmd = {0};

	if (NULL == buf) {
		length = 0;
		if (0 == cmd_code) {
			ret = SEDI_DRIVER_ERROR_PARAMETER;
			goto exit;
		}
	}

	if (direction >= SEDI_I3C_DIRECTION_MAX) {
		ret = SEDI_DRIVER_ERROR_PARAMETER;
		goto exit;
	}

	ctx->buf = buf;
	ctx->buf_len = length;
	ctx->buf_index = 0;
	ctx->direction = direction;
	ctx->position = position;

	if (length > 0 && direction == SEDI_I3C_WRITE) {
		ctx->intr_signal_mask = INTR_STATUS_TX_THLD_EN
			| INTR_STATUS_RESP_READY_EN | INTR_STATUS_TRX_ABT_EN
			| INTR_STATUS_TRX_ERR_EN | INTR_STATUS_HC_INTERNAL_ERR_EN;
	} else if (length > 0 && direction == SEDI_I3C_READ) {
		ctx->intr_signal_mask = INTR_STATUS_RX_THLD_EN
			| INTR_STATUS_RESP_READY_EN | INTR_STATUS_TRX_ABT_EN
			| INTR_STATUS_TRX_ERR_EN | INTR_STATUS_HC_INTERNAL_ERR_EN;
	} else {
		ctx->intr_signal_mask = INTR_STATUS_RESP_READY_EN
			| INTR_STATUS_TRX_ABT_EN
			| INTR_STATUS_TRX_ERR_EN | INTR_STATUS_HC_INTERNAL_ERR_EN;
	}

	cmd.cmd_low.cmd_attr = I3C_CMD_ATTR_XFER;
	cmd.cmd_low.tid = I3C_CMD_RGL_XFER_TID;
	cmd.cmd_low.cmd = cmd_code;
	if (mode == SEDI_I3C_XFER_HDR_DDR || cmd_code != 0) {
		cmd.cmd_low.cp = 1;
	}
	cmd.cmd_low.dev_index = dev_index;
	cmd.cmd_low.mode = MODE_TO_REG_VALUE(mode);
	cmd.cmd_low.rnw = direction;
	if (position == SEDI_I3C_POS_SINGLE || position == SEDI_I3C_POS_LAST) {
		cmd.cmd_low.roc = 1;
		cmd.cmd_low.toc = 1;
	}

	cmd.cmd_high.data_length = length;

	HCI_DEBUG("%s(%d), cmd_low:0x%x, cmd_high:0x%x, cmd_code:0x%x, dev_index:0x%x\n",
			__func__, __LINE__, cmd.cmd_low.as_uint32, cmd.cmd_high.as_uint32,
			cmd_code, dev_index);

	ret = i3c_write_cmd_port(ctx, cmd.cmd_low.as_uint32, cmd.cmd_high.as_uint32);

	i3c_update_buffer_thld(ctx);
	i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, ctx->intr_signal_mask);

exit:
	return ret;
}

int sedi_i3c_combo_xfer(sedi_i3c_t bus,
	uint8_t dev_index, uint8_t cmd_code, sedi_i3c_xfer_mode_t mode,
	uint8_t *buf, uint32_t length,
	sedi_i3c_direction_t direction,
	sedi_i3c_position_t position)
{
	int ret = SEDI_DRIVER_OK;
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	uint32_t cmd_low = 0;
	uint32_t cmd_high = 0;
	bool cp = 0;

	if (buf == NULL) {
		length = 0;
		ret = SEDI_DRIVER_ERROR_PARAMETER;
		goto exit;
	}

	if (length < 2) {
		ret = SEDI_DRIVER_ERROR_PARAMETER;
		goto exit;
	}

	if (direction >= SEDI_I3C_DIRECTION_INVALID) {
		ret = SEDI_DRIVER_ERROR_PARAMETER;
		goto exit;
	}

	ctx->buf = buf + 1;
	ctx->buf_len = length - 1;
	ctx->buf_index = 0;
	ctx->direction = direction;
	ctx->position = position;

	if (direction == SEDI_I3C_WRITE) {
		/* TODO: add support later */
	} else if (direction == SEDI_I3C_READ) {
		ctx->intr_signal_mask = INTR_STATUS_RX_THLD_EN
			| INTR_STATUS_RESP_READY_EN | INTR_STATUS_TRX_ABT_EN
			| INTR_STATUS_TRX_ERR_EN | INTR_STATUS_HC_INTERNAL_ERR_EN;
	} else {
		/* not support */
	}

	if (mode == SEDI_I3C_XFER_HDR_DDR || cmd_code != 0) {
		cp = 1;
	}

	cmd_low = I3C_CMD_COMBO_ASSEMBLER(I3C_CMD_ATTR_WWR_COMBO_XFER, I3C_CMD_COMBO_XFER_TID, cmd_code, cp, dev_index,
			0, 0, MODE_TO_REG_VALUE(mode), direction, I3C_CMD_ROC_REQUIRED, I3C_CMD_TOC_STOP);
	cmd_high = (length - 1) << 16 | buf[0];

	HCI_DEBUG("%s(%d), cmd_low:0x%x, cmd_high:0x%x, cmd_code:0x%x, dev_index:0x%x\n",
			__func__, __LINE__, cmd_low, cmd_high, cmd_code, dev_index);

	ret = i3c_write_cmd_port(ctx, cmd_low, cmd_high);

	i3c_update_buffer_thld(ctx);
	i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, ctx->intr_signal_mask);

exit:
	return ret;
}

void sedi_i3c_on_power_ungate(sedi_i3c_t bus)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];

	i3c_reg_restore(ctx);
}

void sedi_i3c_on_power_gate(sedi_i3c_t bus)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];

	(void)ctx;
}

int sedi_i3c_controller_recover(sedi_i3c_t bus)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);
	int timeout = 100;
	int ret = SEDI_DRIVER_OK;

	/* disable hci before reset */
	SEDI_PREG_RBF_SET(I3C, HC_CONTROL, BUS_ENABLE, 0, &regs->hc_control);

	regs->reset_control = DEVICE_RESET_ALL;
	while ((regs->reset_control) & DEVICE_RESET_ALL) {
		if (--timeout == 0)
			break;
		i3c_udelay(ctx, 10);
	}

	/* reset timed out */
	if (timeout == 0) {
		ret = SEDI_DRIVER_ERROR;
		goto exit;
	}

	i3c_reg_restore(ctx);

	/* Resume I3C */
	SEDI_PREG_RBF_SET(I3C, HC_CONTROL, RESUME, 1, &regs->hc_control);

exit:
	return ret;
}

int32_t sedi_i3c_set_power(IN sedi_i3c_t bus,
			   IN sedi_power_state_t state)
{
	sedi_devid_t id = SEDI_DEVID_I3C0 + bus;
	int32_t ret = SEDI_DRIVER_OK;

	switch (state) {
	case SEDI_POWER_FULL:
		sedi_pm_set_device_power(id, state);
		sedi_i3c_controller_recover(bus);
		break;
	case SEDI_POWER_SUSPEND:
	case SEDI_POWER_FORCE_SUSPEND:
	case SEDI_POWER_LOW:
		break;
	case SEDI_POWER_OFF:
	default:
		ret = SEDI_DRIVER_ERROR_UNSUPPORTED;
		break;
	}

	return ret;
}

void sedi_i3c_register_dump(sedi_i3c_t bus)
{
    uint32_t reg_address = 0;
    sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
    HCI_DEBUG("I3C register dump:\n");

    /* dump registers 0 - 0x24C */
    while (reg_address <= 0x240) {
			HCI_DEBUG("%04X - %08X %08X %08X %08X\n",
			reg_address,
			i3c_mmio_read(reg_address),
			i3c_mmio_read(reg_address + 4),
			i3c_mmio_read(reg_address + 8),
			i3c_mmio_read(reg_address + 12));
			reg_address += 0x10;
    }

    return;
}

void sedi_i3c_ibi_enable(sedi_i3c_t bus, bool en)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	uint32_t interrupts = 0;

	interrupts = i3c_intr_read(ctx, INTR_REG_SIGNAL_ENABLE);
	if (en) {
		interrupts |= INTR_STATUS_IBI_THLD_EN;
	} else {
		interrupts &= ~INTR_STATUS_IBI_THLD_EN;
	}

	i3c_intr_write(ctx, INTR_REG_SIGNAL_ENABLE, interrupts);

	return;
}

void sedi_i3c_enable_i2c_xfer(sedi_i3c_t bus, bool en)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	sedi_i3c_regs_t *regs = (sedi_i3c_regs_t *)(ctx->base);

	uint32_t dev_ctrl = regs->hc_control;

	if (en == true) {
		SEDI_PREG_RBF_SET(I3C, HC_CONTROL, I2C_SLAVE_PRESENT, 1, &dev_ctrl);
		SEDI_PREG_RBF_SET(I3C, HC_CONTROL, IBA_INCLUDE, 0, &dev_ctrl);
	} else {
		SEDI_PREG_RBF_SET(I3C, HC_CONTROL, I2C_SLAVE_PRESENT, 0, &dev_ctrl);
		SEDI_PREG_RBF_SET(I3C, HC_CONTROL, IBA_INCLUDE, 1, &dev_ctrl);
	}

	regs->hc_control = dev_ctrl;
	return;
}

void sedi_i3c_set_timing_config(sedi_i3c_t bus, sedi_i3c_bus_info_t *info)
{
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	ctx->bus_info = *info;
}

int sedi_i3c_set_speed(sedi_i3c_t bus, sedi_i3c_speed_t speed)
{
	sedi_i3c_bus_data_t *i3c_timing;
	sedi_i3c_timing_t hw_timing = {0};
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];
	int ret = SEDI_DRIVER_OK;

	i3c_timing = &ctx->bus_info.i3c_od_scl;
	hw_timing.l_time = i3c_timing->lcnt;
	hw_timing.h_time = i3c_timing->hcnt;
	ret = sedi_i3c_timing_config(bus, SEDI_TIMING_OD,
		SEDI_I3C_SPEED_400KHZ, &hw_timing);

	i3c_timing = &ctx->bus_info.i3c_pp_scl;
	hw_timing.l_time = i3c_timing->lcnt;
	hw_timing.h_time = i3c_timing->hcnt;
	ret = sedi_i3c_timing_config(bus, SEDI_TIMING_PP,
		speed, &hw_timing);

	return ret;
}

int sedi_i2c_set_speed(sedi_i3c_t bus, sedi_i3c_speed_t speed)
{
	int ret = SEDI_DRIVER_OK;
	sedi_i3c_bus_data_t *i2c_timing;
	sedi_i3c_timing_t hw_timing = {0};
	sedi_i3c_context_t *ctx = &sedi_i3c_contexts[bus];

	if (speed > SEDI_I3C_SPEED_1MHZ) {
		ret = SEDI_DRIVER_ERROR_UNSUPPORTED;
		goto exit;
	}

	if (speed == SEDI_I3C_SPEED_1MHZ) {
		i2c_timing = &ctx->bus_info.i2c_fmp_scl;
	} else {
		i2c_timing = &ctx->bus_info.i2c_fm_scl;
	}

	hw_timing.l_time = i2c_timing->lcnt;
	hw_timing.h_time = i2c_timing->hcnt;
	/* sedi_i3c_timing_config will validate hw_timing */
	ret = sedi_i3c_timing_config(
		bus,
		/* TODO */
		speed == SEDI_I3C_SPEED_1MHZ ? SEDI_TIMING_FMP : SEDI_TIMING_FM,
		speed,
		&hw_timing);

exit:
	return ret;
}
