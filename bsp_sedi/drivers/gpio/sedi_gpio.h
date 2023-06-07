/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _GPIO_BSP_H_
#define _GPIO_BSP_H_

#include <sedi_driver_gpio.h>

#define GPIO_FLAG_INIT (1UL << 0)
#define GPIO_PAD_REG_START (0x700)
#define GPIO_PAD_REG_OFFSET (0x10)
#define GPIO_PAD_FUNCTION_MASK (0x3c00)
#define GPIO_PAD_FUNCTION_SHIFT (10)

/* GPIO registers address map structure */
typedef struct {
	__IO_RW uint32_t gccr;
	__IO_R uint32_t gplr[GPIO_PORT_MAX_NUM];
	__IO_RW uint32_t gpdr[GPIO_PORT_MAX_NUM];
	__IO_W uint32_t gpsr[GPIO_PORT_MAX_NUM];
	__IO_W uint32_t gpcr[GPIO_PORT_MAX_NUM];
	__IO_RW uint32_t grer[GPIO_PORT_MAX_NUM];
	__IO_RW uint32_t gfer[GPIO_PORT_MAX_NUM];
	__IO_RW uint32_t gfbr[GPIO_PORT_MAX_NUM];
	__IO_RW uint32_t gimr[GPIO_PORT_MAX_NUM];
	__IO_RW uint32_t gisr[GPIO_PORT_MAX_NUM];
	__IO_R uint32_t rsvd_0[9];
	__IO_RW uint32_t gwmr[GPIO_PORT_MAX_NUM];
	__IO_RW uint32_t gwsr[GPIO_PORT_MAX_NUM];
	__IO_RW uint32_t gsec;
} gpio_bsp_regs_t;

/* GPIO runtime context information */
typedef struct {
	sedi_gpio_event_cb_t cb_event;
	void *callback_param;
	uint8_t flag;
	uint32_t outpin_state[SEDI_GPIO_SOC_PORT_NUM];
} gpio_context_t;

/* resource data structure */
typedef struct {
	gpio_bsp_regs_t *reg;
} gpio_resoures_t;

#endif
