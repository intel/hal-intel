/*
 * Copyright (c) 2025 Intel Corporation. All Rights Reserved.
 *
 * This software and the related documents are Intel copyrighted materials,
 * and your use of them is governed by the express license under which they
 * were provided to you ("License"). Unless the License provides otherwise,
 * you may not use, modify, copy, publish, distribute, disclose or transmit
 * this software or the related documents without Intel's prior written
 * permission.
 *
 * This software and the related documents are provided as is, with no express
 * or implied warranties, other than those that are expressly stated in the
 * License.
 */

/* IUT help functions for Zephyr */

#include <zephyr/kernel.h>

#ifndef _IUT_ZEPHYR_H_
#define _IUT_ZEPHYR_H_

#ifdef CONFIG_SHELL
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
