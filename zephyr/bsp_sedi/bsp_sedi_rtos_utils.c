/*
 * Copyright (c) 2025 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log_ctrl.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(bsp_sedi, CONFIG_BSP_SEDI_LOG_LEVEL);

void sedi_log(int level, const char *fmt, ...)
{
	va_list vargs;

	va_start(vargs, fmt);

#ifndef CONFIG_LOG
	/* No support, do nothing */
	ARG_UNUSED(level);
#elif CONFIG_LOG_MODE_MINIMAL
	vprintk(fmt, vargs);
#else
	log_generic(level, fmt, vargs);
#endif

	va_end(vargs);
}

#ifdef CONFIG_DEBUG
void sedi_assert_halt(void)
{
	while (1) {
		if (k_is_in_isr()) {
			LOG_PANIC();
		} else {
			k_msleep(1);
		}
	}
}
#endif
