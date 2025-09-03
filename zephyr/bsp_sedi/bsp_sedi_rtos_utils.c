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
#ifdef CONFIG_LOG_MODE_MINIMAL
	va_list ap;

	va_start(ap, fmt);
	vprintk(fmt, ap);

	va_end(ap);
#else
	va_list vargs;

	va_start(vargs, fmt);
	log_generic(level, fmt, vargs);
	va_end(vargs);
#endif
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
