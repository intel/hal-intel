/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/dma.h>
#include "iut.h"
#if defined(CONFIG_CACHE_MANAGEMENT)
#include <zephyr/cache.h>
#else
#include "sedi_driver_core.h"
#endif
#include "sedi_driver_rtc.h"

#define DT_DRV_COMPAT intel_sedi_dma

__pinned_noinit static char __aligned(64) tx_data[4096];
__pinned_noinit static char __aligned(64) rx_data[4096];
static K_SEM_DEFINE(dma_sem, 0, 1);
static int dma_status;

static void test_done(const struct device *dev, void *user_data, uint32_t channel, int status)
{
	ARG_UNUSED(dev);
	ARG_UNUSED(user_data);

	if (status != 0) {
		iut_case_print("DMA ch[%d] transfer error, status = %d\n", channel, status);
	}
	dma_status = status;
	k_sem_give(&dma_sem);
}

static int test_dma_m2m(int argc, char **argv)
{
	struct dma_config dma_cfg = {0};
	struct dma_block_config dma_block_cfg = {
		.block_size = sizeof(tx_data),
		.source_address = (uint32_t)&tx_data,
		.dest_address = (uint32_t)&rx_data,
	};
	uint32_t test_len;
	uint32_t blen = 8; /* burst length */
	const struct device *const dma = DEVICE_DT_GET(DT_DRV_INST(0));
	uint64_t us = sedi_rtc_get_us();

	TEST_ASSERT_TRUE(dma != NULL);

	if (argc) {
		blen = (uint32_t)strtoul(argv[0], NULL, 0);
	}
	iut_case_print("Run with blen=%u\n", blen);

	for (uint32_t i = 0; i < sizeof(tx_data); i++) {
		tx_data[i] = (char)i;
	}
#if defined(CONFIG_CACHE_MANAGEMENT)
	sys_cache_data_flush_range(tx_data, sizeof(tx_data));
#else
	sedi_core_inv_clean_dcache_by_addr((uint32_t *)tx_data, sizeof(tx_data));
#endif

	dma_cfg.channel_direction = MEMORY_TO_MEMORY;
	dma_cfg.source_data_size = 1;
	dma_cfg.dest_data_size = 1;
	dma_cfg.source_burst_length = blen;
	dma_cfg.dest_burst_length = blen;
	dma_cfg.dma_callback = test_done;
	dma_cfg.complete_callback_en = 1;
	dma_cfg.error_callback_dis = 1;
	dma_cfg.block_count = 1;
	dma_cfg.head_block = &dma_block_cfg;

	for (test_len = 1; test_len <= sizeof(tx_data); test_len++) {
		dma_block_cfg.block_size = test_len;

		for (uint32_t chan_id = 0; chan_id < DT_INST_PROP(0, dma_channels); chan_id++) {
			memset(rx_data, 0, sizeof(rx_data));

#if defined(CONFIG_CACHE_MANAGEMENT)
			sys_cache_data_flush_range(rx_data, sizeof(rx_data));
#else
			sedi_core_inv_clean_dcache_by_addr((uint32_t *)rx_data, sizeof(rx_data));
#endif

			TEST_ASSERT_TRUE(!dma_config(dma, chan_id, &dma_cfg));
			TEST_ASSERT_TRUE(!dma_start(dma, chan_id));

			TEST_ASSERT_TRUE(!k_sem_take(&dma_sem, K_MSEC(1000)));
			TEST_ASSERT_TRUE(dma_status == 0);
			TEST_ASSERT_TRUE(!memcmp(tx_data, rx_data, test_len));
			TEST_ASSERT_TRUE(!dma_stop(dma, chan_id));
		}
	}
	us = sedi_rtc_get_us() - us;
	iut_case_print("Test Done after %u | %u us\n", (uint32_t)(us >> 32), (uint32_t)us);

	return IUT_ERR_OK;
}

DEFINE_IUT_CASE(dma_m2m, dma, IUT_ATTRI_NONE);
