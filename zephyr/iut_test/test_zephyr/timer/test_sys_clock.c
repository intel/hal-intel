/*
 * Copyright (c) 2024 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "iut.h"
#include "sedi_driver_hpet.h"
#include "sedi_driver_rtc.h"
#include <zephyr/sys/time_units.h>
#include <zephyr/kernel.h>

static int test_sys_clock_freq(int argc, char **argv)
{
	uint32_t sec_run = 60;

	uint64_t us_rtc_start, cyc_rtc_start;
	uint64_t us_hpet_start, cyc_hpet_start;
	uint64_t cyc_sys_start;

	uint64_t us_rtc_end, cyc_rtc_end;
	uint64_t us_hpet_end, cyc_hpet_end;
	uint64_t cyc_sys_end;

	uint64_t us_rtc, cyc_rtc;
	uint64_t us_hpet, cyc_hpet;
	uint64_t us_sys, cyc_sys;
	uint32_t hz_rtc, hz_hpet, hz_sys;
	uint32_t psec_hpet;

	if (argc) {
		sec_run = (uint32_t)strtoul(argv[0], NULL, 0);
	}

	iut_case_print("to run %u seconds\n", sec_run);

	us_rtc_start = sedi_rtc_get_us();
	cyc_rtc_start = sedi_rtc_get();

	us_hpet_start = sedi_hpet_get_us();
	cyc_hpet_start = sedi_hpet_get_main_counter();

	cyc_sys_start = k_cycle_get_64();

	k_msleep(sec_run * 1000);

	us_rtc_end = sedi_rtc_get_us();
	cyc_rtc_end = sedi_rtc_get();

	us_hpet_end = sedi_hpet_get_us();
	cyc_hpet_end = sedi_hpet_get_main_counter();

	cyc_sys_end = k_cycle_get_64();

	us_rtc = (us_rtc_end - us_rtc_start);
	cyc_rtc = (cyc_rtc_end - cyc_rtc_start);

	us_hpet = (us_hpet_end - us_hpet_start);
	cyc_hpet = (cyc_hpet_end - cyc_hpet_start);

	cyc_sys = (cyc_sys_end - cyc_sys_start);
	us_sys = cyc_sys * Z_HZ_us / Z_HZ_cyc;

	hz_rtc = (uint32_t)((cyc_rtc * USEC_PER_SEC) / us_rtc);
	hz_hpet = (uint32_t)((cyc_hpet * USEC_PER_SEC) / us_hpet);
	hz_sys = (uint32_t)((cyc_sys * USEC_PER_SEC) / us_sys);
#define PSEC_PER_USEC (1000000)
	psec_hpet = (uint32_t)((us_hpet * PSEC_PER_USEC) / cyc_hpet);

	iut_case_print("RTC : %llu cycles, %llu us, %u HZ\n", cyc_rtc, us_rtc, hz_rtc);
	iut_case_print("HPET: %llu cycles, %llu us, %u HZ\n", cyc_hpet, us_hpet, hz_hpet);
	iut_case_print("SYS CLOCK: %llu cycles, %llu us, %u HZ\n", cyc_sys, us_sys, hz_sys);

	/* checking diff < 1/100 */
	TEST_ASSERT_TRUE(abs((int)(hz_rtc - SEDI_RTC_TICKS_PER_SECOND)) * 100
			< SEDI_RTC_TICKS_PER_SECOND);
	TEST_ASSERT_TRUE(abs((int)(hz_sys - CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC)) * 100
			< CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC);
	TEST_ASSERT_TRUE(abs((int)(psec_hpet - sedi_hpet_get_period())) * 100
			< sedi_hpet_get_period());
	TEST_ASSERT_TRUE(abs((int)(us_rtc - sec_run * USEC_PER_SEC - us_rtc)) * 100
			< (sec_run * USEC_PER_SEC - us_rtc));

	return IUT_ERR_OK;
}

DEFINE_IUT_CASE(sys_clock_freq, timer, IUT_ATTRI_NONE);
