/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_HPET_H_
#define _SEDI_HPET_H_

#include "sedi_driver_common.h"

/* HPET registers address map structure */
typedef struct {
	__IO_R uint32_t gcid_low;
	__IO_R uint32_t gcid_high;
	__IO_R uint32_t reserved0[2];
	__IO_RW uint32_t gcfg_low;
	__IO_RW uint32_t gcfg_high;
	__IO_R uint32_t reserved1[2];
	__IO_RW uint32_t gis_low;
	__IO_RW uint32_t gis_high;
	__IO_RW uint32_t reserved2[50];
	__IO_RW uint32_t mcv_low;
	__IO_RW uint32_t mcv_high;
	__IO_R uint32_t reserved3[2];
	__IO_RW uint32_t t0c_low;
	__IO_RW uint32_t t0c_high;
	__IO_RW uint32_t t0cv_low;
	__IO_RW uint32_t t0cv_high;
	__IO_R uint32_t reserved4[4];
	__IO_RW uint32_t t1c_low;
	__IO_RW uint32_t t1c_high;
	__IO_RW uint32_t t1cv_low;
	__IO_R uint32_t reserved5[5];
	__IO_RW uint32_t t2c_low;
	__IO_RW uint32_t t2c_high;
	__IO_RW uint32_t t2cv_low;
	__IO_R uint32_t reserved6[5];
	__IO_R uint32_t hpet_ctrl_sts;
} hpet_regs_t;

#endif
