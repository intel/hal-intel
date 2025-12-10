/*
 * Copyright (c) 2025 Intel Corporation.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "iut.h"
#include "sedi_driver_dma.h"
#include "sedi_driver_pm.h"
#include "sedi_ipc_regs.h"
#include "sedi_soc_regs.h"
#include <string.h>

#define IMR_DMA_DEVID   SEDI_DMA_0
#define IMR_DMA_CHANNEL 0

#define IMR_TEST_MODE_COPY_OUT        0
#define IMR_TEST_MODE_ZERO_OUT        1
#define IMR_TEST_MODE_IN_COMPARE      2
#define IMR_TEST_MODE_IN_ZERO_COMPARE 3

static char tx_data[4096] __attribute__((section(".noinit")));
static char rx_data[4096] __attribute__((section(".noinit")));

static int _imr_dma_copy(uint32_t sram_addr, uint32_t len, bool is_in)
{
	uint32_t src_mem_type;
	uint32_t dst_mem_type;
	int ret = 0;
	sedi_power_state_t dma_power;
	uint64_t src_addr, dst_addr;
	static uint64_t imr_start, imr_end;

	if (imr_end == 0) {
		imr_start = SEDI_IREG_GET(IPC, CSME, UMA_BASE_LOW_AGENT) +
			    ((uint64_t)SEDI_IREG_GET(IPC, CSME, UMA_BASE_HIGH_AGENT) << 32);
		imr_end = SEDI_IREG_GET(IPC, CSME, UMA_LIMIT_LOW_AGENT) +
			  ((uint64_t)SEDI_IREG_GET(IPC, CSME, UMA_LIMIT_HIGH_AGENT) << 32);
		iut_case_print("IMR: %llx ~ %llx\n", imr_start, imr_end);
	}

	if (len > (uint64_t)(imr_end - imr_start)) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	if (is_in) {
		src_mem_type = DMA_UMA_MEM;
		src_addr = imr_end - len;
		dst_mem_type = DMA_SRAM_MEM;
		dst_addr = (uint64_t)sram_addr;
	} else {
		src_mem_type = DMA_SRAM_MEM;
		src_addr = (uint64_t)sram_addr;
		dst_mem_type = DMA_UMA_MEM;
		dst_addr = imr_end - len;
	}

	dma_power = sedi_pm_get_device_power(SEDI_DEVID_DMA0);
	if (dma_power != SEDI_POWER_FULL) {
		sedi_pm_set_device_power(SEDI_DEVID_DMA0, SEDI_POWER_FULL);
	}

	sedi_dma_chan_init(IMR_DMA_DEVID, IMR_DMA_CHANNEL, NULL, NULL);
	sedi_dma_control(IMR_DMA_DEVID, IMR_DMA_CHANNEL, SEDI_CONFIG_DMA_DIRECTION,
			 DMA_MEMORY_TO_MEMORY);
	sedi_dma_control(IMR_DMA_DEVID, IMR_DMA_CHANNEL, SEDI_CONFIG_DMA_SR_MEM_TYPE, src_mem_type);
	sedi_dma_control(IMR_DMA_DEVID, IMR_DMA_CHANNEL, SEDI_CONFIG_DMA_DT_MEM_TYPE, dst_mem_type);
	sedi_dma_control(IMR_DMA_DEVID, IMR_DMA_CHANNEL, SEDI_CONFIG_DMA_SR_TRANS_WIDTH,
			 DMA_TRANS_WIDTH_32);
	sedi_dma_control(IMR_DMA_DEVID, IMR_DMA_CHANNEL, SEDI_CONFIG_DMA_DT_TRANS_WIDTH,
			 DMA_TRANS_WIDTH_32);
	sedi_dma_control(IMR_DMA_DEVID, IMR_DMA_CHANNEL, SEDI_CONFIG_DMA_BURST_LENGTH,
			 DMA_BURST_TRANS_LENGTH_32);

	__asm__ volatile("\twbinvd\n");
	ret = sedi_dma_start_transfer_polling(IMR_DMA_DEVID, IMR_DMA_CHANNEL, src_addr, dst_addr,
					      len);

	sedi_dma_abort_transfer(IMR_DMA_DEVID, IMR_DMA_CHANNEL);
	if (dma_power != SEDI_POWER_FULL) {
		sedi_pm_set_device_power(SEDI_DEVID_DMA0, dma_power);
	}

	return ret;
}

static int imr_copy_in(uint32_t sram_addr, uint32_t len)
{
	return _imr_dma_copy(sram_addr, len, true);
}

static int imr_copy_out(uint32_t sram_addr, uint32_t len)
{
	return _imr_dma_copy(sram_addr, len, false);
}

static int _test_sedi_imr(uint32_t mode, char *_tx_data, char *_rx_data, uint32_t len)
{
	int ret;

	for (uint32_t i = 0; i < len; i++) {
		if ((mode == IMR_TEST_MODE_ZERO_OUT) || (mode == IMR_TEST_MODE_IN_ZERO_COMPARE)) {
			_tx_data[i] = 0;
		} else {
			_tx_data[i] = (char)i;
		}
	}

	if (mode <= IMR_TEST_MODE_ZERO_OUT) {
		ret = imr_copy_out((uint32_t)&_tx_data[0], len);
		TEST_ASSERT_TRUE(ret == 0);
	}

	memset(&_rx_data[0], 0xff, len);
	ret = imr_copy_in((uint32_t)&_rx_data[0], len);
	TEST_ASSERT_TRUE(ret == 0);

	TEST_ASSERT_TRUE(!memcmp(&_tx_data[0], &_rx_data[0], len));

	return 0;
}

/* usage: iut run sedi_dma_imr [mode] [len] */
static int test_sedi_dma_imr(int argc, char **argv)
{
	uint32_t mode = IMR_TEST_MODE_COPY_OUT;
	uint32_t len = sizeof(tx_data);

	if (argc) {
		mode = (uint32_t)strtoul(argv[0], NULL, 0);
		if (mode > IMR_TEST_MODE_IN_ZERO_COMPARE) {
			iut_case_print("Unsupported mode: %u\n", mode);
			TEST_ASSERT_TRUE(0);
		}
	}
	if (argc > 1) {
		len = (uint32_t)strtoul(argv[1], NULL, 0);
		if (len > sizeof(tx_data)) {
			iut_case_print("Unsupported length: %u\n", len);
			TEST_ASSERT_TRUE(0);
		}
	}

	iut_case_print("Run IMR test: mode=%u, len=%u\n", mode, len);

	return _test_sedi_imr(mode, &tx_data[sizeof(tx_data) - len],
			&rx_data[sizeof(rx_data) - len], len);
}

DEFINE_IUT_CASE(sedi_dma_imr, sedi.dma, IUT_ATTRI_AUTORUN);

static int test_sedi_dma_imr_stress(int argc, char **argv)
{
	int ret = 0;

	for (uint32_t len = 4; len < sizeof(tx_data); len++) {
		ret = _test_sedi_imr(IMR_TEST_MODE_COPY_OUT, &tx_data[sizeof(tx_data) - len],
				     &rx_data[sizeof(rx_data) - len], len);
		if (ret) {
			iut_case_print("Stress test failed: ret=%d, len=%u\n", ret, len);
			break;
		}

		if (!(len % 64)) {
			iut_case_print("......................................."
				".........................\n");
		}
	}

	return ret;
}

DEFINE_IUT_CASE(sedi_dma_imr_stress, sedi.dma, IUT_ATTRI_AUTORUN);
