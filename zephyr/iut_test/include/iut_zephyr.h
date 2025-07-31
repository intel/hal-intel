/*
 * Copyright (c) 2025 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* IUT help functions for Zephyr */

#include <zephyr/kernel.h>

#ifndef _IUT_ZEPHYR_H_
#define _IUT_ZEPHYR_H_

#ifndef CONFIG_SHELL_BACKEND_SERIAL_INTERRUPT_DRIVEN
void iut_shell_suspend(void);
void iut_shell_resume(void);
#else
static inline void iut_shell_suspend(void)
{
}

static inline void iut_shell_resume(void)
{
}
#endif

#endif /* _IUT_ZEPHYR_H_ */
