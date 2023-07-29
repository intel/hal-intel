/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "iut.h"
#include "sedi_driver_i2c.h"
#include "sedi_driver_rtc.h"
#include <zephyr/drivers/i2c.h>

#define DT_DRV_COMPAT intel_sedi_i2c

#define LOG_I2C_BUS       (0)
#define LOG_I2C_DEV_ADDR  (0x5e)
#define LOG_I2C_RETRY_CNT (3)
#define LOG_I2C_DATA_SIZE (128)

#define POLLING (1 << 0)
#define IRQ     (1 << 1)
#define ASYNC   (1 << 2)

static uint32_t get_sec(void)
{
	uint64_t start = sedi_rtc_get_us();

	return (uint32_t)(start / 1000 / 1000);
}

#if defined(CONFIG_I2C_ASYNC)
static int async_req;
static int async_rpl;
static int async_err;
static void async_cb(int result, void *userdata)
{
	async_rpl++;
}
#endif

static int impl_test_log_i2c(uint32_t sec_run, int mode, uint32_t *err_cnt)
{
	int ret;
	uint8_t data[LOG_I2C_DATA_SIZE];
	const struct device *i2c_dev = DEVICE_DT_GET(DT_DRV_INST(0));

	uint32_t sec_start = get_sec();
	int loop = 0;
	int retry = 0;
	uint32_t error = 0;

	uint32_t i2c_cfg = I2C_SPEED_SET(I2C_SPEED_FAST) | I2C_MODE_CONTROLLER;

	if (!i2c_dev) {
		return -ENODEV;
	}

	ret = i2c_configure(i2c_dev, i2c_cfg);
	if (ret) {
		return -EINVAL;
	}

	while (1) {
		for (int i = 0; i < sizeof(data) - 2; i++) {
			data[i] = ((loop + i) % 10) + 0x30;
		}
		data[sizeof(data) - 2] = '\n';
		data[sizeof(data) - 1] = '\r';

		if (mode & POLLING) {
			ret = sedi_i2c_master_poll_write(LOG_I2C_BUS, LOG_I2C_DEV_ADDR, data,
							 sizeof(data), false);
#if defined(CONFIG_I2C_ASYNC)
		} else if (mode & ASYNC) {
			struct i2c_msg msg;

			msg.buf = (uint8_t *)data;
			msg.len = sizeof(data);
			msg.flags = I2C_MSG_WRITE | I2C_MSG_STOP;
			ret = i2c_transfer_async(i2c_dev, &msg, 1, LOG_I2C_DEV_ADDR, async_cb,
						 (void *)loop);
			async_req++;
			if (ret == -EWOULDBLOCK) {
				k_sleep(K_MSEC(5));
				async_err++;
				ret = 0; /* recover async busy */
			}
#endif
		} else {
			ret = i2c_write(i2c_dev, data, sizeof(data), LOG_I2C_DEV_ADDR);
		}

		if (ret) {
			if (retry >= LOG_I2C_RETRY_CNT) {
				break;
			}

			retry++;
			error++;
			continue;
		}

		loop++;
		if (!(loop % 100)) {
			iut_print("\ttransfer %d-%d: error=%d\n", loop - 100, loop, error);
			retry = 0;
			*err_cnt += error;
			error = 0;
			k_msleep(100);

			if ((get_sec() - sec_start) >= sec_run) {
				break;
			}
		}
	}

	return ret;
}

static int test_log_i2c_polling(int argc, char **argv)
{
	uint32_t sec_run = 10;
	int ret;
	uint32_t err_cnt = 0;

	if (argc) {
		sec_run = (uint32_t)strtoul(argv[0], NULL, 0);
	}

	iut_case_print("starting to run %d seconds ...\n", sec_run);

	ret = impl_test_log_i2c(sec_run, POLLING, &err_cnt);

	iut_case_print("done, ret=%d, err_cnt=%u\n", ret, err_cnt);
	TEST_ASSERT_EQUAL(0, ret);

	return IUT_ERR_OK;
}
DEFINE_IUT_CASE(log_i2c_polling, logging, IUT_ATTRI_NONE);

static int test_log_i2c_irq(int argc, char **argv)
{
	uint32_t sec_run = 10;
	int ret;
	uint32_t err_cnt = 0;

	if (argc) {
		sec_run = (uint32_t)strtoul(argv[0], NULL, 0);
	}

	iut_case_print("starting to run %d seconds ...\n", sec_run);

	ret = impl_test_log_i2c(sec_run, IRQ, &err_cnt);

	iut_case_print("done, ret=%d, err_cnt=%u\n", ret, err_cnt);
	TEST_ASSERT_EQUAL(0, ret);

	return IUT_ERR_OK;
}
DEFINE_IUT_CASE(log_i2c_irq, logging, IUT_ATTRI_NONE);

#if defined(CONFIG_I2C_ASYNC)
static int test_log_i2c_async(int argc, char **argv)
{
	uint32_t sec_run = 10;
	int ret;
	uint32_t err_cnt = 0;

	if (argc) {
		sec_run = (uint32_t)strtoul(argv[0], NULL, 0);
	}

	async_err = 0;
	async_req = 0;
	async_rpl = 0;

	iut_case_print("starting to run %d seconds ...\n", sec_run);

	ret = impl_test_log_i2c(sec_run, ASYNC, &err_cnt);

	iut_case_print("done, ret=%d, err_cnt=%u\n", ret, err_cnt);
	iut_case_print("finish: async_req:%d, async_rpl:%d, async_err:%d\n", async_req, async_rpl,
		       async_err);

	TEST_ASSERT_EQUAL(0, ret);

	return IUT_ERR_OK;
}
DEFINE_IUT_CASE(log_i2c_async, logging, IUT_ATTRI_NONE);
#endif
