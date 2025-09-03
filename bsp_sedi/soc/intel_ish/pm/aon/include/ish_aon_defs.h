/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _ISH_AON_DEFS_H_
#define _ISH_AON_DEFS_H_

#include "ish_ia_structs.h"

/**
 * SNOWBALL - registers about UMA/IMR DDR information and FW location
 * in it.  ISH Bringup will set these register values at boot
 */
struct snowball_struct {
	uint32_t reserved[28];

	uint32_t volatile uma_base_hi;
	uint32_t volatile uma_base_lo;
	uint32_t volatile uma_limit;
	uint32_t volatile fw_offset;
};

/* aontask entry point function */
void ish_aon_main(void);

extern int ish_ipapg(void);
extern void ish_pg_exit_restore_ctx(void);
extern void ish_pg_exit_save_ctx(void);

struct gdt_header ish_mainfw_gdt;
uint16_t ish_mainfw_tr;

#endif
