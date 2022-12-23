/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _ISH_PM_H_
#define _ISH_PM_H_

#include <sedi_driver_common.h>
#include "pm_regs.h"

#define FABRIC_IDLE_COUNT	50
#define TRUNK_CLKGATE_COUNT	0xf

/* power states for ISH */
enum ish_pm_state {
	/* D0 state: active mode */
	ISH_PM_STATE_D0 = 0,
	/* sleep state: cpu halt */
	ISH_PM_STATE_D0I0,
	/* deep sleep state 1: Trunk Clock Gating(TCG), cpu halt*/
	ISH_PM_STATE_D0I1,
	/* deep sleep state 2: TCG, SRAM retention, cpu halt */
	ISH_PM_STATE_D0I2,
	/* deep sleep state 3: TCG, SRAM power off, cpu halt*/
	ISH_PM_STATE_D0I3,
	/**
	 * D3 state: power off state, on ISH5.0, can't do real power off,
	 * similar to D0I3, but will reset ISH
	 */
	ISH_PM_STATE_D3,
	/**
	 * reset ISH, main FW received 'reboot' command
	 */
	ISH_PM_STATE_RESET,
	/**
	 * reset ISH, main FW received reset_prep interrupt during
	 * S0->Sx transition.
	 */
	ISH_PM_STATE_RESET_PREP,
	ISH_PM_STATE_NUM
};

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
