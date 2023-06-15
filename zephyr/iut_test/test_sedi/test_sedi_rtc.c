/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "iut.h"
#include "sedi_driver_rtc.h"

static int test_rtc_inc(int argc, char **argv)
{
	uint32_t test_loops = 1000000;
	uint64_t cnt_rtc = 0;
	uint64_t us_rtc = 0;
	uint64_t us_start = 0;

	us_start = us_rtc = sedi_rtc_get_us();

	if (argc) {
		test_loops = (uint32_t)strtoul(argv[0], NULL, 0);
	}

	iut_case_print("test loops = %d\n", test_loops);

	for (uint32_t i = 0; i < test_loops; i++) {
		uint64_t cnt = sedi_rtc_get();
		uint64_t us = sedi_rtc_get_us();

		if (cnt < cnt_rtc) {
			iut_case_print("loop %d, cnt error, %llu->%llu\n",
					i, cnt_rtc, cnt);
			TEST_ASSERT_TRUE(0);
		}
		if (us < us_rtc) {
			iut_case_print("loop %d, us error, %llu->%llu\n",
					i, us_rtc, us);
			TEST_ASSERT_TRUE(0);
		}

		cnt_rtc = cnt;
		us_rtc = us;
	}


	iut_case_print("test exec time = %u us\n", (uint32_t)(us_rtc - us_start));
	return IUT_ERR_OK;
}
DEFINE_IUT_CASE(rtc_inc, sedi.rtc, IUT_ATTRI_AUTORUN);
