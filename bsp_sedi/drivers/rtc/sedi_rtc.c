/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <sedi_driver_rtc.h>

/* driver version */
#define SEDI_RTC_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

#ifndef SEDI_RTC_TICKS_PER_SECOND
#define SEDI_RTC_TICKS_PER_SECOND 32768
#endif

#ifndef USECS_PER_SEC
#define USECS_PER_SEC 1000000
#endif

/* driver version */
static const sedi_driver_version_t driver_version = { SEDI_RTC_API_VERSION,
						      SEDI_RTC_DRIVER_VERSION };

/* driver capabilities */
static const sedi_rtc_capabilities_t driver_capabilities = { .support_alarm = 0,
							     .support_callback = 0,
							     .reserved = 0 };

static inline uint64_t sedi_rtc_to_us(uint64_t rtc_ticks)
{
	return (rtc_ticks * USECS_PER_SEC) / SEDI_RTC_TICKS_PER_SECOND;
}

sedi_driver_version_t sedi_rtc_get_version(void)
{
	return driver_version;
}

int sedi_rtc_get_capabilities(sedi_rtc_capabilities_t *cap)
{
	SEDI_ASSERT(cap);

	cap->support_alarm = driver_capabilities.support_alarm;
	cap->support_callback = driver_capabilities.support_callback;

	return SEDI_DRIVER_OK;
}

int sedi_rtc_init(void)
{
	/* SEDI RTC have no alarm and interrupt feature, callback not used */
	return SEDI_DRIVER_OK;
}

int sedi_rtc_uninit(void)
{
	return SEDI_DRIVER_OK;
}

int sedi_rtc_set_power(sedi_power_state_t state)
{
	PARAM_UNUSED(state);

	return SEDI_DRIVER_OK;
}

uint64_t sedi_rtc_get(void)
{
	uint32_t lower;
	uint32_t upper;

	do {
		upper = read32(SEDI_RTC_COUNTER1);
		lower = read32(SEDI_RTC_COUNTER0);
	} while (upper != read32(SEDI_RTC_COUNTER1));

	return ((uint64_t)upper << 32U) | lower;
}

void sedi_rtc_get_us(INOUT uint64_t *us)
{
	/* returns the current time in micro seconds. */
	uint64_t result;
	uint64_t rtc = sedi_rtc_get();

	result = sedi_rtc_to_us(rtc);
	*us = result;
}
