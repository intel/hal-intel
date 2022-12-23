/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _AON_DEFS_H_
#define _AON_DEFS_H_

#include "../ia_structs.h"

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

extern int ipapg(void);
extern void pg_exit_restore_ctx(void);
extern void pg_exit_save_ctx(void);

struct gdt_header mainfw_gdt;
uint16_t tr;

#define FPU_REG_SET_SIZE 108
uint8_t fpu_reg_set[FPU_REG_SET_SIZE];

#endif
