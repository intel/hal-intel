/*
 * Copyright (c) 2024 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/logging/log_backend.h>
#include <zephyr/logging/log_core.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/logging/log_msg.h>
#include <zephyr/logging/log_output.h>
#include <zephyr/logging/log_backend_std.h>
#include <zephyr/sys/__assert.h>
#include <sedi_driver_i2c.h>

static uint32_t log_format_current = CONFIG_LOG_BACKEND_I2C_OUTPUT_DEFAULT;
static uint8_t log_i2c_buf[CONFIG_LOG_I2C_MAX_MSG_LEN];
static bool panic_mode;
static uint8_t i2c_bus;

static int log_i2c_char_out(uint8_t *data, size_t length, void *ctx)
{
	ARG_UNUSED(ctx);

	__ASSERT_NO_MSG(length > 0 && length <= CONFIG_LOG_I2C_MAX_MSG_LEN);

	sedi_i2c_master_poll_write(i2c_bus, CONFIG_LOG_I2C_DEV_ADDR,
				data, length, false);

	return length;
}

LOG_OUTPUT_DEFINE(log_output_i2c, log_i2c_char_out,
		log_i2c_buf, CONFIG_LOG_I2C_MAX_MSG_LEN);

static void log_i2c_panic(struct log_backend const *const backend)
{
	ARG_UNUSED(backend);

	panic_mode = true;
	sedi_i2c_control(i2c_bus, SEDI_I2C_ABORT_TRANSFER, 0);
	log_backend_std_panic(&log_output_i2c);
}

static void log_i2c_dropped(const struct log_backend *const backend,
		uint32_t cnt)
{
	ARG_UNUSED(backend);

	log_backend_std_dropped(&log_output_i2c, cnt);
}

static void process(const struct log_backend *const backend,
		union log_msg_generic *msg)
{
	uint32_t flags = log_backend_std_get_flags();
	log_format_func_t log_output_func = log_format_func_t_get(log_format_current);

	log_output_func(&log_output_i2c, &msg->log, flags);
}

static int format_set(const struct log_backend *const backend, uint32_t log_type)
{
	log_format_current = log_type;
	return 0;
}

static void log_backend_i2c_init(const struct log_backend *const backend)
{
#if DT_HAS_CHOSEN(zephyr_log_i2c)
	uint32_t cfg = I2C_SPEED_SET(I2C_SPEED_FAST) | I2C_MODE_CONTROLLER;
	int ret = i2c_configure(DEVICE_DT_GET(DT_CHOSEN(zephyr_log_i2c)), cfg);

	if (ret) {
		goto disable;
	}

	i2c_bus = DT_PROP(DT_CHOSEN(zephyr_log_i2c), peripheral_id);
	panic_mode = false;

	return;

disable:
#endif
	/* No specified log i2c device or device not ready */
	log_backend_disable(backend);
}

static const struct log_backend_api log_backend_i2c_api = {
	.process = process,
	.panic = log_i2c_panic,
	.init = log_backend_i2c_init,
	.dropped = IS_ENABLED(CONFIG_LOG_MODE_IMMEDIATE) ? NULL : log_i2c_dropped,
	.format_set = format_set,
};

LOG_BACKEND_DEFINE(log_backend_i2c, log_backend_i2c_api,
		IS_ENABLED(CONFIG_LOG_BACKEND_I2C_AUTOSTART));
