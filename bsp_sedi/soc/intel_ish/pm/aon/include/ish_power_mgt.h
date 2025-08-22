/*
 * Copyright (c) 2023-2025 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __ISH_POWER_MGT_H
#define __ISH_POWER_MGT_H


#include <sedi_driver_common.h>
#include "ish_registers.h"

#define FABRIC_IDLE_COUNT	50
#define TRUNK_CLKGATE_COUNT	0xf

/* halt ISH minute-ia cpu core */
static inline void ish_mia_halt(void)
{
	/* make sure interrupts are enabled before halting */
	__asm__ volatile("sti;\n"
			 "hlt;");
}

/* reset ISH mintue-ia cpu core  */
static inline void ish_mia_reset(void)
{
	/**
	 * ISH HW looks at the rising edge of this bit to
	 * trigger a MIA reset.
	 */
	write32(ISH_RST_REG, 0);
	write32(ISH_RST_REG, 1);

	__builtin_unreachable();
}

/* Initialize power management module. */
void ish_pm_init(void);

/**
 * reset ISH (reset minute-ia cpu core, and power off main SRAM)
 */
void ish_pm_reset(enum ish_pm_state pm_state);

#endif
