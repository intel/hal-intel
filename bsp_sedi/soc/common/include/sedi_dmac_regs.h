/*
 * Copyright (c) 2023-2025 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2023-08-01
 */

#ifndef _SEDI_DMAC_REGS_H_
#define _SEDI_DMAC_REGS_H_

#include <sedi_reg_defs.h>

/* ********* DMAC IDREG ***********
 *
 * Register of SEDI DMAC
 *   IDREG: DW_axi_dmac Component ID Register
 *     AddressOffset  : 0x0
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMAC, IDREG, 0x0, RO, (uint64_t)0x0, (uint64_t)0x0);

/*
 * Bit Field of Register IDREG
 *   DMAC_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, IDREG, DMAC_ID, 0, 32, RO, (uint64_t)0x0);

/*
 * Bit Field of Register IDREG
 *   RSVD_DMAC_IDREG:
 *     BitOffset : 32
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, IDREG, RSVD_DMAC_IDREG, 32, 32, RO, (uint64_t)0x0);

/* ********* DMAC COMPVERREG ***********
 *
 * Register of SEDI DMAC
 *   COMPVERREG: DW_axi_dmac Component Version Register
 *     AddressOffset  : 0x8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x3230302a
 */
SEDI_REG_DEFINE(DMAC, COMPVERREG, 0x8, RO, (uint64_t)0x0, (uint64_t)0x3230302a);

/*
 * Bit Field of Register COMPVERREG
 *   DMAC_COMPVER:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x3230302a
 */
SEDI_RBF_DEFINE(DMAC, COMPVERREG, DMAC_COMPVER, 0, 32, RO, (uint64_t)0x3230302a);

/*
 * Bit Field of Register COMPVERREG
 *   RSVD_DMAC_COMPVERREG:
 *     BitOffset : 32
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMPVERREG, RSVD_DMAC_COMPVERREG, 32, 32, RO, (uint64_t)0x0);

/* ********* DMAC CFGREG ***********
 *
 * Register of SEDI DMAC
 *   CFGREG: DW_axi_dmac Global Configuration Register
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x3
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMAC, CFGREG, 0x10, RW, (uint64_t)0x3, (uint64_t)0x0);

/*
 * Bit Field of Register CFGREG
 *   DMAC_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CFGREG, DMAC_EN, 0, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CFGREG, DMAC_EN, DISABLED, 0x0);
SEDI_RBFV_DEFINE(DMAC, CFGREG, DMAC_EN, ENABLED, 0x1);

/*
 * Bit Field of Register CFGREG
 *   INT_EN:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CFGREG, INT_EN, 1, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CFGREG, INT_EN, DISABLED, 0x0);
SEDI_RBFV_DEFINE(DMAC, CFGREG, INT_EN, ENABLED, 0x1);

/*
 * Bit Field of Register CFGREG
 *   RSVD_DMAC_CFGREG:
 *     BitOffset : 2
 *     BitWidth  : 62
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CFGREG, RSVD_DMAC_CFGREG, 2, 62, RO, (uint64_t)0x0);

/* ********* DMAC CHENREG ***********
 *
 * Register of SEDI DMAC
 *   CHENREG: DW_axi_dmac Channel Enable Register
 *     AddressOffset  : 0x18
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMAC, CHENREG, 0x18, RW, (uint64_t)0xffffffffffff, (uint64_t)0x0);

/*
 * Bit Field of Register CHENREG
 *   CH1_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH1_EN, 0, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_EN, DISABLE_CH1, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_EN, ENABLE_CH1, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH2_EN:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH2_EN, 1, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_EN, DISABLE_CH2, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_EN, ENABLE_CH2, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH3_EN:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH3_EN, 2, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_EN, DISABLE_CH3, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_EN, ENABLE_CH3, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH4_EN:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH4_EN, 3, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_EN, DISABLE_CH4, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_EN, ENABLE_CH4, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH5_EN:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH5_EN, 4, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_EN, DISABLE_CH5, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_EN, ENABLE_CH5, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH6_EN:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH6_EN, 5, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_EN, DISABLE_CH6, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_EN, ENABLE_CH6, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH7_EN:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH7_EN, 6, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_EN, DISABLE_CH7, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_EN, ENABLE_CH7, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH8_EN:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH8_EN, 7, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_EN, DISABLE_CH8, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_EN, ENABLE_CH8, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH1_EN_WE:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH1_EN_WE, 8, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_EN_WE, DISABLE_WR_CH1_EN, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_EN_WE, ENABLE_WR_CH1_EN, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH2_EN_WE:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH2_EN_WE, 9, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_EN_WE, DISABLE_WR_CH2_EN, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_EN_WE, ENABLE_WR_CH2_EN, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH3_EN_WE:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH3_EN_WE, 10, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_EN_WE, DISABLE_WR_CH3_EN, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_EN_WE, ENABLE_WR_CH3_EN, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH4_EN_WE:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH4_EN_WE, 11, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_EN_WE, DISABLE_WR_CH4_EN, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_EN_WE, ENABLE_WR_CH4_EN, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH5_EN_WE:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH5_EN_WE, 12, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_EN_WE, DISABLE_WR_CH5_EN, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_EN_WE, ENABLE_WR_CH5_EN, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH6_EN_WE:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH6_EN_WE, 13, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_EN_WE, DISABLE_WR_CH6_EN, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_EN_WE, ENABLE_WR_CH6_EN, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH7_EN_WE:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH7_EN_WE, 14, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_EN_WE, DISABLE_WR_CH7_EN, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_EN_WE, ENABLE_WR_CH7_EN, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH8_EN_WE:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH8_EN_WE, 15, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_EN_WE, DISABLE_WR_CH8_EN, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_EN_WE, ENABLE_WR_CH8_EN, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH1_SUSP:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH1_SUSP, 16, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_SUSP, DISABLE_CH1_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_SUSP, ENABLE_CH1_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH2_SUSP:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH2_SUSP, 17, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_SUSP, DISABLE_CH2_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_SUSP, ENABLE_CH2_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH3_SUSP:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH3_SUSP, 18, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_SUSP, DISABLE_CH3_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_SUSP, ENABLE_CH3_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH4_SUSP:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH4_SUSP, 19, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_SUSP, DISABLE_CH4_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_SUSP, ENABLE_CH4_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH5_SUSP:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH5_SUSP, 20, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_SUSP, DISABLE_CH5_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_SUSP, ENABLE_CH5_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH6_SUSP:
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH6_SUSP, 21, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_SUSP, DISABLE_CH6_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_SUSP, ENABLE_CH6_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH7_SUSP:
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH7_SUSP, 22, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_SUSP, DISABLE_CH7_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_SUSP, ENABLE_CH7_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH8_SUSP:
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH8_SUSP, 23, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_SUSP, DISABLE_CH8_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_SUSP, ENABLE_CH8_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH1_SUSP_WE:
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH1_SUSP_WE, 24, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_SUSP_WE, DISABLE_WR_CH1_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_SUSP_WE, ENABLE_WR_CH1_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH2_SUSP_WE:
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH2_SUSP_WE, 25, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_SUSP_WE, DISABLE_WR_CH2_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_SUSP_WE, ENABLE_WR_CH2_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH3_SUSP_WE:
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH3_SUSP_WE, 26, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_SUSP_WE, DISABLE_WR_CH3_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_SUSP_WE, ENABLE_WR_CH3_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH4_SUSP_WE:
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH4_SUSP_WE, 27, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_SUSP_WE, DISABLE_WR_CH4_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_SUSP_WE, ENABLE_WR_CH4_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH5_SUSP_WE:
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH5_SUSP_WE, 28, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_SUSP_WE, DISABLE_WR_CH5_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_SUSP_WE, ENABLE_WR_CH5_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH6_SUSP_WE:
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH6_SUSP_WE, 29, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_SUSP_WE, DISABLE_WR_CH6_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_SUSP_WE, ENABLE_WR_CH6_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH7_SUSP_WE:
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH7_SUSP_WE, 30, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_SUSP_WE, DISABLE_WR_CH7_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_SUSP_WE, ENABLE_WR_CH7_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH8_SUSP_WE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH8_SUSP_WE, 31, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_SUSP_WE, DISABLE_WR_CH8_SUSP, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_SUSP_WE, ENABLE_WR_CH8_SUSP, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH1_ABORT:
 *     BitOffset : 32
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH1_ABORT, 32, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_ABORT, DISABLE_CH1_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_ABORT, ENABLE_CH1_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH2_ABORT:
 *     BitOffset : 33
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH2_ABORT, 33, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_ABORT, DISABLE_CH2_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_ABORT, ENABLE_CH2_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH3_ABORT:
 *     BitOffset : 34
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH3_ABORT, 34, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_ABORT, DISABLE_CH3_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_ABORT, ENABLE_CH3_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH4_ABORT:
 *     BitOffset : 35
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH4_ABORT, 35, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_ABORT, DISABLE_CH4_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_ABORT, ENABLE_CH4_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH5_ABORT:
 *     BitOffset : 36
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH5_ABORT, 36, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_ABORT, DISABLE_CH5_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_ABORT, ENABLE_CH5_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH6_ABORT:
 *     BitOffset : 37
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH6_ABORT, 37, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_ABORT, DISABLE_CH6_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_ABORT, ENABLE_CH6_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH7_ABORT:
 *     BitOffset : 38
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH7_ABORT, 38, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_ABORT, DISABLE_CH7_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_ABORT, ENABLE_CH7_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH8_ABORT:
 *     BitOffset : 39
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH8_ABORT, 39, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_ABORT, DISABLE_CH8_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_ABORT, ENABLE_CH8_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH1_ABORT_WE:
 *     BitOffset : 40
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH1_ABORT_WE, 40, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_ABORT_WE, DISABLE_WR_CH1_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH1_ABORT_WE, ENABLE_WR_CH1_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH2_ABORT_WE:
 *     BitOffset : 41
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH2_ABORT_WE, 41, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_ABORT_WE, DISABLE_WR_CH2_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH2_ABORT_WE, ENABLE_WR_CH2_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH3_ABORT_WE:
 *     BitOffset : 42
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH3_ABORT_WE, 42, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_ABORT_WE, DISABLE_WR_CH3_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH3_ABORT_WE, ENABLE_WR_CH3_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH4_ABORT_WE:
 *     BitOffset : 43
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH4_ABORT_WE, 43, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_ABORT_WE, DISABLE_WR_CH4_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH4_ABORT_WE, ENABLE_WR_CH4_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH5_ABORT_WE:
 *     BitOffset : 44
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH5_ABORT_WE, 44, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_ABORT_WE, DISABLE_WR_CH5_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH5_ABORT_WE, ENABLE_WR_CH5_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH6_ABORT_WE:
 *     BitOffset : 45
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH6_ABORT_WE, 45, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_ABORT_WE, DISABLE_WR_CH6_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH6_ABORT_WE, ENABLE_WR_CH6_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH7_ABORT_WE:
 *     BitOffset : 46
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH7_ABORT_WE, 46, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_ABORT_WE, DISABLE_WR_CH7_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH7_ABORT_WE, ENABLE_WR_CH7_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   CH8_ABORT_WE:
 *     BitOffset : 47
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, CH8_ABORT_WE, 47, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_ABORT_WE, DISABLE_WR_CH8_ABORT, 0x0);
SEDI_RBFV_DEFINE(DMAC, CHENREG, CH8_ABORT_WE, ENABLE_WR_CH8_ABORT, 0x1);

/*
 * Bit Field of Register CHENREG
 *   RSVD_DMAC_CHENREG:
 *     BitOffset : 48
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, CHENREG, RSVD_DMAC_CHENREG, 48, 16, RO, (uint64_t)0x0);

/* ********* DMAC INTSTATUSREG ***********
 *
 * Register of SEDI DMAC
 *   INTSTATUSREG: DW_axi_dmac Combined Interrupt Status Register
 *     AddressOffset  : 0x30
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMAC, INTSTATUSREG, 0x30, RO, (uint64_t)0x0, (uint64_t)0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CH1_IntStat:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CH1_IntStat, 0, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH1_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH1_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CH2_IntStat:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CH2_IntStat, 1, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH2_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH2_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CH3_IntStat:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CH3_IntStat, 2, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH3_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH3_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CH4_IntStat:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CH4_IntStat, 3, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH4_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH4_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CH5_IntStat:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CH5_IntStat, 4, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH5_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH5_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CH6_IntStat:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CH6_IntStat, 5, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH6_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH6_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CH7_IntStat:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CH7_IntStat, 6, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH7_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH7_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CH8_IntStat:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CH8_IntStat, 7, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH8_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CH8_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   RSVD_DMAC_INTSTATUSREG:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, RSVD_DMAC_INTSTATUSREG, 8, 8, RO, (uint64_t)0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   CommonReg_IntStat:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, CommonReg_IntStat, 16, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CommonReg_IntStat, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(DMAC, INTSTATUSREG, CommonReg_IntStat, INACTIVE, 0x0);

/*
 * Bit Field of Register INTSTATUSREG
 *   RSVD_DMAC_INTSTATUSREG_63to17:
 *     BitOffset : 17
 *     BitWidth  : 47
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, INTSTATUSREG, RSVD_DMAC_INTSTATUSREG_63to17, 17, 47, RO, (uint64_t)0x0);

/* ********* DMAC COMMONREG_INTCLEARREG ***********
 *
 * Register of SEDI DMAC
 *   COMMONREG_INTCLEARREG: DW_axi_dmac Common Register Space Interrupt Clear Register
 *     AddressOffset  : 0x38
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffffffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMAC, COMMONREG_INTCLEARREG, 0x38, RW, (uint64_t)0xffffffffffffffff, (uint64_t)0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_SLVIF_CommonReg_DEC_ERR_IntStat:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_DEC_ERR_IntStat, 0, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_DEC_ERR_IntStat,
		 CLEAR_SLVIF_CommonReg_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_DEC_ERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_SLVIF_CommonReg_WR2RO_ERR_IntStat:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WR2RO_ERR_IntStat, 1, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WR2RO_ERR_IntStat,
		 CLEAR_SLVIF_CommonReg_WR2RO_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WR2RO_ERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_SLVIF_CommonReg_RD2WO_ERR_IntStat:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_RD2WO_ERR_IntStat, 2, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_RD2WO_ERR_IntStat,
		 CLEAR_SLVIF_CommonReg_RD2WO_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_RD2WO_ERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_SLVIF_CommonReg_WrOnHold_ERR_IntStat:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WrOnHold_ERR_IntStat, 3, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WrOnHold_ERR_IntStat,
		 CLEAR_SLVIF_CommonReg_WrOnHold_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WrOnHold_ERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   RSVD_DMAC_COMMONREG_INTCLEARREG_6to4:
 *     BitOffset : 4
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, RSVD_DMAC_COMMONREG_INTCLEARREG_6to4, 4, 3, RW,
		(uint64_t)0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_SLVIF_CommonReg_WRPARITY_ERR_IntStat:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WRPARITY_ERR_IntStat, 7, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WRPARITY_ERR_IntStat,
		 CLEAR_SLVIF_CommonReg_WRPARITY_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_CommonReg_WRPARITY_ERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_SLVIF_UndefinedReg_DEC_ERR_IntStat:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_UndefinedReg_DEC_ERR_IntStat, 8, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_UndefinedReg_DEC_ERR_IntStat,
		 CLEAR_SLVIF_UndefinedReg_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_SLVIF_UndefinedReg_DEC_ERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF1_RCH0_EccPROT_CorrERR_IntStat:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH0_EccPROT_CorrERR_IntStat, 9, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH0_EccPROT_CorrERR_IntStat,
		 CLEAR_MXIF1_RCH0_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH0_EccPROT_CorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat, 10, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat,
		 CLEAR_MXIF1_RCH0_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF1_RCH1_EccPROT_CorrERR_IntStat:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH1_EccPROT_CorrERR_IntStat, 11, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH1_EccPROT_CorrERR_IntStat,
		 CLEAR_MXIF1_RCH1_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH1_EccPROT_CorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat, 12, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat,
		 CLEAR_MXIF1_RCH1_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF1_BCH_EccPROT_CorrERR_IntStat:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_BCH_EccPROT_CorrERR_IntStat, 13, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_BCH_EccPROT_CorrERR_IntStat,
		 CLEAR_MXIF1_BCH_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_BCH_EccPROT_CorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF1_BCH_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_BCH_EccPROT_UnCorrERR_IntStat, 14, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_BCH_EccPROT_UnCorrERR_IntStat,
		 CLEAR_MXIF1_BCH_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF1_BCH_EccPROT_UnCorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF2_RCH0_EccPROT_CorrERR_IntStat:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH0_EccPROT_CorrERR_IntStat, 15, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH0_EccPROT_CorrERR_IntStat,
		 CLEAR_MXIF2_RCH0_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH0_EccPROT_CorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat, 16, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat,
		 CLEAR_MXIF2_RCH0_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF2_RCH1_EccPROT_CorrERR_IntStat:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH1_EccPROT_CorrERR_IntStat, 17, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH1_EccPROT_CorrERR_IntStat,
		 CLEAR_MXIF2_RCH1_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH1_EccPROT_CorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat, 18, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat,
		 CLEAR_MXIF2_RCH1_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF2_BCH_EccPROT_CorrERR_IntStat:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_BCH_EccPROT_CorrERR_IntStat, 19, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_BCH_EccPROT_CorrERR_IntStat,
		 CLEAR_MXIF2_BCH_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_BCH_EccPROT_CorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   Clear_MXIF2_BCH_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_BCH_EccPROT_UnCorrERR_IntStat, 20, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_BCH_EccPROT_UnCorrERR_IntStat,
		 CLEAR_MXIF2_BCH_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTCLEARREG, Clear_MXIF2_BCH_EccPROT_UnCorrERR_IntStat, No_ACTION,
		 0x0);

/*
 * Bit Field of Register COMMONREG_INTCLEARREG
 *   RSVD_DMAC_COMMONREG_INTCLEARREG_63to21:
 *     BitOffset : 21
 *     BitWidth  : 43
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTCLEARREG, RSVD_DMAC_COMMONREG_INTCLEARREG_63to21, 21, 43, RW,
		(uint64_t)0x0);

/* ********* DMAC COMMONREG_INTSTATUS_ENABLEREG ***********
 *
 * Register of SEDI DMAC
 *   COMMONREG_INTSTATUS_ENABLEREG: DW_axi_dmac Common Register Space Interrupt Enable Register
 *     AddressOffset  : 0x40
 *     AccessType     : RW
 *     WritableBitMask: 0x10f
 *     ResetValue     : (uint64_t)0xffffffffffffffff
 */
SEDI_REG_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, 0x40, RW, (uint64_t)0x10f,
		(uint64_t)0xffffffffffffffff);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_SLVIF_CommonReg_DEC_ERR_IntStat:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_DEC_ERR_IntStat, 0, 1,
		RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_DEC_ERR_IntStat,
		 DISABLE_SLVIF_CommonReg_DEC_ERR, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_DEC_ERR_IntStat,
		 ENABLE_SLVIF_CommonReg_DEC_ERR, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_SLVIF_CommonReg_WR2RO_ERR_IntStat:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WR2RO_ERR_IntStat, 1, 1,
		RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WR2RO_ERR_IntStat,
		 DISABLE_SLVIF_CommonReg_WR2RO_ERR, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WR2RO_ERR_IntStat,
		 ENABLE_SLVIF_CommonReg_WR2RO_ERR, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_SLVIF_CommonReg_RD2WO_ERR_IntStat:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_RD2WO_ERR_IntStat, 2, 1,
		RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_RD2WO_ERR_IntStat,
		 DISABLE_SLVIF_CommonReg_RD2WO_ERR, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_RD2WO_ERR_IntStat,
		 ENABLE_SLVIF_CommonReg_RD2WO_ERR, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_SLVIF_CommonReg_WrOnHold_ERR_IntStat:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WrOnHold_ERR_IntStat, 3,
		1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WrOnHold_ERR_IntStat,
		 DISABLE_SLVIF_CommonReg_WrOnHold_ERR, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WrOnHold_ERR_IntStat,
		 ENABLE_SLVIF_CommonReg_WrOnHold_ERR, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   RSVD_DMAC_COMMONREG_INTSTATUS_ENABLEREG_6to4:
 *     BitOffset : 4
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x7
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, RSVD_DMAC_COMMONREG_INTSTATUS_ENABLEREG_6to4,
		4, 3, RO, (uint64_t)0x7);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_SLVIF_CommonReg_WRPARITY_ERR_IntStat:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WRPARITY_ERR_IntStat, 7,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WRPARITY_ERR_IntStat,
		 DISABLE_SLVIF_CommonReg_WRPARITY_ERR, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_CommonReg_WRPARITY_ERR_IntStat,
		 ENABLE_SLVIF_CommonReg_WRPARITY_ERR, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_SLVIF_UndefinedReg_DEC_ERR_IntStat:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_UndefinedReg_DEC_ERR_IntStat, 8,
		1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_UndefinedReg_DEC_ERR_IntStat,
		 DISABLE_SLVIF_UndefinedReg_DEC_ERR, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_SLVIF_UndefinedReg_DEC_ERR_IntStat,
		 ENABLE_SLVIF_UndefinedReg_DEC_ERR, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF1_RCH0_EccPROT_CorrERR_IntStat:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_CorrERR_IntStat, 9,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_CorrERR_IntStat,
		 DISABLE_MXIF1_RCH0_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_CorrERR_IntStat,
		 ENABLE_MXIF1_RCH0_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat,
		10, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat,
		 DISABLE_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat,
		 ENABLE_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF1_RCH1_EccPROT_CorrERR_IntStat:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_CorrERR_IntStat, 11,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_CorrERR_IntStat,
		 DISABLE_MXIF1_RCH1_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_CorrERR_IntStat,
		 ENABLE_MXIF1_RCH1_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat,
		12, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat,
		 DISABLE_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat,
		 ENABLE_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF1_BCH_EccPROT_CorrERR_IntStat:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_BCH_EccPROT_CorrERR_IntStat, 13,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_BCH_EccPROT_CorrERR_IntStat,
		 DISABLE_MXIF1_BCH_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_BCH_EccPROT_CorrERR_IntStat,
		 ENABLE_MXIF1_BCH_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF1_BCH_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_BCH_EccPROT_UnCorrERR_IntStat, 14,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_BCH_EccPROT_UnCorrERR_IntStat,
		 DISABLE_MXIF1_BCH_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF1_BCH_EccPROT_UnCorrERR_IntStat,
		 ENABLE_MXIF1_BCH_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF2_RCH0_EccPROT_CorrERR_IntStat:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_CorrERR_IntStat, 15,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_CorrERR_IntStat,
		 DISABLE_MXIF2_RCH0_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_CorrERR_IntStat,
		 ENABLE_MXIF2_RCH0_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat,
		16, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat,
		 DISABLE_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat,
		 ENABLE_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF2_RCH1_EccPROT_CorrERR_IntStat:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_CorrERR_IntStat, 17,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_CorrERR_IntStat,
		 DISABLE_MXIF2_RCH1_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_CorrERR_IntStat,
		 ENABLE_MXIF2_RCH1_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat,
		18, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat,
		 DISABLE_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat,
		 ENABLE_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF2_BCH_EccPROT_CorrERR_IntStat:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_BCH_EccPROT_CorrERR_IntStat, 19,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_BCH_EccPROT_CorrERR_IntStat,
		 DISABLE_MXIF2_BCH_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_BCH_EccPROT_CorrERR_IntStat,
		 ENABLE_MXIF2_BCH_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   Enable_MXIF2_BCH_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_BCH_EccPROT_UnCorrERR_IntStat, 20,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_BCH_EccPROT_UnCorrERR_IntStat,
		 DISABLE_MXIF2_BCH_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, Enable_MXIF2_BCH_EccPROT_UnCorrERR_IntStat,
		 ENABLE_MXIF2_BCH_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSTATUS_ENABLEREG
 *   RSVD_DMAC_COMMONREG_INTSTATUS_ENABLEREG_63to21:
 *     BitOffset : 21
 *     BitWidth  : 43
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x7ffffffffff
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUS_ENABLEREG, RSVD_DMAC_COMMONREG_INTSTATUS_ENABLEREG_63to21,
		21, 43, RO, (uint64_t)0x7ffffffffff);

/* ********* DMAC COMMONREG_INTSIGNAL_ENABLEREG ***********
 *
 * Register of SEDI DMAC
 *   COMMONREG_INTSIGNAL_ENABLEREG: DW_axi_dmac Common Register Space Interrupt Signal Enable
 * Register AddressOffset  : 0x48 AccessType     : RW WritableBitMask: 0x10f ResetValue     :
 * (uint64_t)0xffffffffffffffff
 */
SEDI_REG_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, 0x48, RW, (uint64_t)0x10f,
		(uint64_t)0xffffffffffffffff);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_CommonReg_DEC_ERR_IntSignal:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_DEC_ERR_IntSignal, 0, 1,
		RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_DEC_ERR_IntSignal,
		 DISABLE_SLVIF_CommonReg_DEC_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_DEC_ERR_IntSignal,
		 ENABLE_SLVIF_CommonReg_DEC_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_CommonReg_WR2RO_ERR_IntSignal:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WR2RO_ERR_IntSignal, 1,
		1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WR2RO_ERR_IntSignal,
		 DISABLE_SLVIF_CommonReg_WR2RO_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WR2RO_ERR_IntSignal,
		 ENABLE_SLVIF_CommonReg_WR2RO_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_CommonReg_RD2WO_ERR_IntSignal:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_RD2WO_ERR_IntSignal, 2,
		1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_RD2WO_ERR_IntSignal,
		 DISABLE_SLVIF_CommonReg_RD2WO_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_RD2WO_ERR_IntSignal,
		 ENABLE_SLVIF_CommonReg_RD2WO_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_CommonReg_WrOnHold_ERR_IntSignal:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WrOnHold_ERR_IntSignal,
		3, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WrOnHold_ERR_IntSignal,
		 DISABLE_SLVIF_CommonReg_WrOnHold_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WrOnHold_ERR_IntSignal,
		 ENABLE_SLVIF_CommonReg_WrOnHold_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   RSVD_DMAC_COMMONREG_INTSIGNAL_ENABLEREG_6to4:
 *     BitOffset : 4
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x7
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, RSVD_DMAC_COMMONREG_INTSIGNAL_ENABLEREG_6to4,
		4, 3, RO, (uint64_t)0x7);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_CommonReg_WRPARITY_ERR_IntSignal:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WRPARITY_ERR_IntSignal,
		7, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WRPARITY_ERR_IntSignal,
		 DISABLE_SLVIF_CommonReg_WRPARITY_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_CommonReg_WRPARITY_ERR_IntSignal,
		 ENABLE_SLVIF_CommonReg_WRPARITY_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_UndefinedReg_DEC_ERR_IntSignal:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_UndefinedReg_DEC_ERR_IntSignal, 8,
		1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_UndefinedReg_DEC_ERR_IntSignal,
		 DISABLE_SLVIF_UndefinedReg_DEC_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_SLVIF_UndefinedReg_DEC_ERR_IntSignal,
		 ENABLE_SLVIF_UndefinedReg_DEC_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF1_RCH0_EccPROT_CorrERR_IntSignal:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_CorrERR_IntSignal, 9,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_CorrERR_IntSignal,
		 DISABLE_MXIF1_RCH0_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_CorrERR_IntSignal,
		 ENABLE_MXIF1_RCH0_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF1_RCH0_EccPROT_UnCorrERR_IntSignal:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_UnCorrERR_IntSignal,
		10, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_UnCorrERR_IntSignal,
		 DISABLE_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH0_EccPROT_UnCorrERR_IntSignal,
		 ENABLE_MXIF1_RCH0_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF1_RCH1_EccPROT_CorrERR_IntSignal:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_CorrERR_IntSignal,
		11, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_CorrERR_IntSignal,
		 DISABLE_MXIF1_RCH1_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_CorrERR_IntSignal,
		 ENABLE_MXIF1_RCH1_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF1_RCH1_EccPROT_UnCorrERR_IntSignal:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_UnCorrERR_IntSignal,
		12, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_UnCorrERR_IntSignal,
		 DISABLE_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_RCH1_EccPROT_UnCorrERR_IntSignal,
		 ENABLE_MXIF1_RCH1_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF1_BCH_EccPROT_CorrERR_IntSignal:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_BCH_EccPROT_CorrERR_IntSignal, 13,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_BCH_EccPROT_CorrERR_IntSignal,
		 DISABLE_MXIF1_BCH_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_BCH_EccPROT_CorrERR_IntSignal,
		 ENABLE_MXIF1_BCH_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF1_BCH_EccPROT_UnCorrERR_IntSignal:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_BCH_EccPROT_UnCorrERR_IntSignal,
		14, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_BCH_EccPROT_UnCorrERR_IntSignal,
		 DISABLE_MXIF1_BCH_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF1_BCH_EccPROT_UnCorrERR_IntSignal,
		 ENABLE_MXIF1_BCH_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF2_RCH0_EccPROT_CorrERR_IntSignal:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_CorrERR_IntSignal,
		15, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_CorrERR_IntSignal,
		 DISABLE_MXIF2_RCH0_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_CorrERR_IntSignal,
		 ENABLE_MXIF2_RCH0_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF2_RCH0_EccPROT_UnCorrERR_IntSignal:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_UnCorrERR_IntSignal,
		16, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_UnCorrERR_IntSignal,
		 DISABLE_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH0_EccPROT_UnCorrERR_IntSignal,
		 ENABLE_MXIF2_RCH0_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF2_RCH1_EccPROT_CorrERR_IntSignal:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_CorrERR_IntSignal,
		17, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_CorrERR_IntSignal,
		 DISABLE_MXIF2_RCH1_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_CorrERR_IntSignal,
		 ENABLE_MXIF2_RCH1_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF2_RCH1_EccPROT_UnCorrERR_IntSignal:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_UnCorrERR_IntSignal,
		18, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_UnCorrERR_IntSignal,
		 DISABLE_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_RCH1_EccPROT_UnCorrERR_IntSignal,
		 ENABLE_MXIF2_RCH1_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF2_BCH_EccPROT_CorrERR_IntSignal:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_BCH_EccPROT_CorrERR_IntSignal, 19,
		1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_BCH_EccPROT_CorrERR_IntSignal,
		 DISABLE_MXIF2_BCH_EccPROT_CorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_BCH_EccPROT_CorrERR_IntSignal,
		 ENABLE_MXIF2_BCH_EccPROT_CorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   Enable_MXIF2_BCH_EccPROT_UnCorrERR_IntSignal:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_BCH_EccPROT_UnCorrERR_IntSignal,
		20, 1, RO, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_BCH_EccPROT_UnCorrERR_IntSignal,
		 DISABLE_MXIF2_BCH_EccPROT_UnCorrERR_IntStat, 0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, Enable_MXIF2_BCH_EccPROT_UnCorrERR_IntSignal,
		 ENABLE_MXIF2_BCH_EccPROT_UnCorrERR_IntStat, 0x1);

/*
 * Bit Field of Register COMMONREG_INTSIGNAL_ENABLEREG
 *   RSVD_DMAC_COMMONREG_INTSIGNAL_ENABLEREG_63to21:
 *     BitOffset : 21
 *     BitWidth  : 43
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x7ffffffffff
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSIGNAL_ENABLEREG, RSVD_DMAC_COMMONREG_INTSIGNAL_ENABLEREG_63to21,
		21, 43, RO, (uint64_t)0x7ffffffffff);

/* ********* DMAC COMMONREG_INTSTATUSREG ***********
 *
 * Register of SEDI DMAC
 *   COMMONREG_INTSTATUSREG: DW_axi_dmac Common Register Space Interrupt Status Register
 *     AddressOffset  : 0x50
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMAC, COMMONREG_INTSTATUSREG, 0x50, RO, (uint64_t)0x0, (uint64_t)0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   SLVIF_CommonReg_DEC_ERR_IntStat:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_DEC_ERR_IntStat, 0, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_DEC_ERR_IntStat,
		 Active_CommonReg_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_DEC_ERR_IntStat,
		 Inactive_CommonReg_DEC_ERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   SLVIF_CommonReg_WR2RO_ERR_IntStat:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WR2RO_ERR_IntStat, 1, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WR2RO_ERR_IntStat,
		 Active_CommonReg_WR2RO_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WR2RO_ERR_IntStat,
		 Inactive_CommonReg_WR2RO_ERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   SLVIF_CommonReg_RD2WO_ERR_IntStat:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_RD2WO_ERR_IntStat, 2, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_RD2WO_ERR_IntStat,
		 Active_CommonReg_RD2WO_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_RD2WO_ERR_IntStat,
		 Inactive_CommonReg_RD2WO_ERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   SLVIF_CommonReg_WrOnHold_ERR_IntStat:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WrOnHold_ERR_IntStat, 3, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WrOnHold_ERR_IntStat,
		 Active_CommonReg_WrOnHold_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WrOnHold_ERR_IntStat,
		 Inactive_CommonReg_WrOnHold_ERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   RSVD_DMAC_COMMONREG_INTSTATUSREG_6to4:
 *     BitOffset : 4
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, RSVD_DMAC_COMMONREG_INTSTATUSREG_6to4, 4, 3, RO,
		(uint64_t)0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   SLVIF_CommonReg_WRPARITY_ERR_IntStat:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WRPARITY_ERR_IntStat, 7, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WRPARITY_ERR_IntStat,
		 Active_CommonReg_WRPARITY_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_CommonReg_WRPARITY_ERR_IntStat,
		 Inactive_CommonReg_WRPARITY_ERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   SLVIF_UndefinedReg_DEC_ERR_IntStat:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_UndefinedReg_DEC_ERR_IntStat, 8, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_UndefinedReg_DEC_ERR_IntStat,
		 Active_UndefinedReg_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, SLVIF_UndefinedReg_DEC_ERR_IntStat,
		 Inactive_UndefinedReg_DEC_ERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF1_RCH0_EccPROT_CorrERR_IntStat:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH0_EccPROT_CorrERR_IntStat, 9, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH0_EccPROT_CorrERR_IntStat,
		 Active_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH0_EccPROT_CorrERR_IntStat,
		 Inactive_EccPROT_CorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF1_RCH0_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH0_EccPROT_UnCorrERR_IntStat, 10, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH0_EccPROT_UnCorrERR_IntStat,
		 Active_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH0_EccPROT_UnCorrERR_IntStat,
		 Inactive_EccPROT_UnCorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF1_RCH1_EccPROT_CorrERR_IntStat:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH1_EccPROT_CorrERR_IntStat, 11, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH1_EccPROT_CorrERR_IntStat,
		 Active_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH1_EccPROT_CorrERR_IntStat,
		 Inactive_EccPROT_CorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF1_RCH1_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH1_EccPROT_UnCorrERR_IntStat, 12, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH1_EccPROT_UnCorrERR_IntStat,
		 Active_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_RCH1_EccPROT_UnCorrERR_IntStat,
		 Inactive_EccPROT_UnCorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF1_BCH_EccPROT_CorrERR_IntStat:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_BCH_EccPROT_CorrERR_IntStat, 13, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_BCH_EccPROT_CorrERR_IntStat,
		 Active_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_BCH_EccPROT_CorrERR_IntStat,
		 Inactive_EccPROT_CorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF1_BCH_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_BCH_EccPROT_UnCorrERR_IntStat, 14, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_BCH_EccPROT_UnCorrERR_IntStat,
		 Active_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF1_BCH_EccPROT_UnCorrERR_IntStat,
		 Inactive_EccPROT_UnCorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF2_RCH0_EccPROT_CorrERR_IntStat:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH0_EccPROT_CorrERR_IntStat, 15, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH0_EccPROT_CorrERR_IntStat,
		 Active_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH0_EccPROT_CorrERR_IntStat,
		 Inactive_EccPROT_CorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF2_RCH0_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH0_EccPROT_UnCorrERR_IntStat, 16, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH0_EccPROT_UnCorrERR_IntStat,
		 Active_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH0_EccPROT_UnCorrERR_IntStat,
		 Inactive_EccPROT_UnCorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF2_RCH1_EccPROT_CorrERR_IntStat:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH1_EccPROT_CorrERR_IntStat, 17, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH1_EccPROT_CorrERR_IntStat,
		 Active_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH1_EccPROT_CorrERR_IntStat,
		 Inactive_EccPROT_CorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF2_RCH1_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH1_EccPROT_UnCorrERR_IntStat, 18, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH1_EccPROT_UnCorrERR_IntStat,
		 Active_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_RCH1_EccPROT_UnCorrERR_IntStat,
		 Inactive_EccPROT_UnCorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF2_BCH_EccPROT_CorrERR_IntStat:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_BCH_EccPROT_CorrERR_IntStat, 19, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_BCH_EccPROT_CorrERR_IntStat,
		 Active_EccPROT_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_BCH_EccPROT_CorrERR_IntStat,
		 Inactive_EccPROT_CorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   MXIF2_BCH_EccPROT_UnCorrERR_IntStat:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_BCH_EccPROT_UnCorrERR_IntStat, 20, 1, RO,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_BCH_EccPROT_UnCorrERR_IntStat,
		 Active_EccPROT_UnCorrERR, 0x1);
SEDI_RBFV_DEFINE(DMAC, COMMONREG_INTSTATUSREG, MXIF2_BCH_EccPROT_UnCorrERR_IntStat,
		 Inactive_EccPROT_UnCorrERR, 0x0);

/*
 * Bit Field of Register COMMONREG_INTSTATUSREG
 *   RSVD_DMAC_COMMONREG_INTSTATUSREG_63to21:
 *     BitOffset : 21
 *     BitWidth  : 43
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, COMMONREG_INTSTATUSREG, RSVD_DMAC_COMMONREG_INTSTATUSREG_63to21, 21, 43, RO,
		(uint64_t)0x0);

/* ********* DMAC RESETREG ***********
 *
 * Register of SEDI DMAC
 *   RESETREG: DW_axi_dmac Software Reset Register
 *     AddressOffset  : 0x58
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMAC, RESETREG, 0x58, RW, (uint64_t)0x1, (uint64_t)0x0);

/*
 * Bit Field of Register RESETREG
 *   DMAC_RST:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, RESETREG, DMAC_RST, 0, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMAC, RESETREG, DMAC_RST, 0, 0);
SEDI_RBFV_DEFINE(DMAC, RESETREG, DMAC_RST, 1, 1);

/*
 * Bit Field of Register RESETREG
 *   RSVD_DMAC_ResetReg_1to63:
 *     BitOffset : 1
 *     BitWidth  : 63
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, RESETREG, RSVD_DMAC_ResetReg_1to63, 1, 63, RO, (uint64_t)0x0);

/* ********* DMAC LOWPOWER_CFGREG ***********
 *
 * Register of SEDI DMAC
 *   LOWPOWER_CFGREG: DW_axi_dmac Low Power Configuration Register
 *     AddressOffset  : 0x60
 *     AccessType     : RW
 *     WritableBitMask: 0xffffff0000000f
 *     ResetValue     : (uint64_t)0xf0f0f0000000f
 */
SEDI_REG_DEFINE(DMAC, LOWPOWER_CFGREG, 0x60, RW, (uint64_t)0xffffff0000000f,
		(uint64_t)0xf0f0f0000000f);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   GBL_CSLP_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, GBL_CSLP_EN, 0, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, LOWPOWER_CFGREG, GBL_CSLP_EN, GBL_CSLP_DISABLE, 0x0);
SEDI_RBFV_DEFINE(DMAC, LOWPOWER_CFGREG, GBL_CSLP_EN, GBL_CSLP_ENABLE, 0x1);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   CHNL_CSLP_EN:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, CHNL_CSLP_EN, 1, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, LOWPOWER_CFGREG, CHNL_CSLP_EN, CHNL_CSLP_DISABLE, 0x0);
SEDI_RBFV_DEFINE(DMAC, LOWPOWER_CFGREG, CHNL_CSLP_EN, CHNL_CSLP_ENABLE, 0x1);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   SBIU_CSLP_EN:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, SBIU_CSLP_EN, 2, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, LOWPOWER_CFGREG, SBIU_CSLP_EN, SBIU_CSLP_DISABLE, 0x0);
SEDI_RBFV_DEFINE(DMAC, LOWPOWER_CFGREG, SBIU_CSLP_EN, SBIU_CSLP_ENABLE, 0x1);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   MXIF_CSLP_EN:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, MXIF_CSLP_EN, 3, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMAC, LOWPOWER_CFGREG, MXIF_CSLP_EN, MXIF_CSLP_DISABLE, 0x0);
SEDI_RBFV_DEFINE(DMAC, LOWPOWER_CFGREG, MXIF_CSLP_EN, MXIF_CSLP_ENABLE, 0x1);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   RSVD_DMAC_LOWPOWER_CFGREG_31to4:
 *     BitOffset : 4
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, RSVD_DMAC_LOWPOWER_CFGREG_31to4, 4, 28, RO, (uint64_t)0x0);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   GLCH_LPDLY:
 *     BitOffset : 32
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint64_t)0xf
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, GLCH_LPDLY, 32, 8, RW, (uint64_t)0xf);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   SBIU_LPDLY:
 *     BitOffset : 40
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint64_t)0xf
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, SBIU_LPDLY, 40, 8, RW, (uint64_t)0xf);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   MXIF_LPDLY:
 *     BitOffset : 48
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint64_t)0xf
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, MXIF_LPDLY, 48, 8, RW, (uint64_t)0xf);

/*
 * Bit Field of Register LOWPOWER_CFGREG
 *   RSVD_DMAC_LOWPOWER_CFGREG_63to56:
 *     BitOffset : 56
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMAC, LOWPOWER_CFGREG, RSVD_DMAC_LOWPOWER_CFGREG_63to56, 56, 8, RO, (uint64_t)0x0);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* DW_axi_dmac Component ID Register */
	__IO_R uint64_t idreg;

	/* DW_axi_dmac Component Version Register */
	__IO_R uint64_t compverreg;

	/* DW_axi_dmac Global Configuration Register */
	__IO_RW uint64_t cfgreg;

	/* DW_axi_dmac Channel Enable Register */
	__IO_RW uint64_t chenreg;

	/* Reserved */
	__IO_RW uint64_t reserved0[2];

	/* DW_axi_dmac Combined Interrupt Status Register */
	__IO_R uint64_t intstatusreg;

	/* DW_axi_dmac Common Register Space Interrupt Clear Register */
	__IO_RW uint64_t commonreg_intclearreg;

	/* DW_axi_dmac Common Register Space Interrupt Enable Register */
	__IO_RW uint64_t commonreg_intstatus_enablereg;

	/* DW_axi_dmac Common Register Space Interrupt Signal Enable Register */
	__IO_RW uint64_t commonreg_intsignal_enablereg;

	/* DW_axi_dmac Common Register Space Interrupt Status Register */
	__IO_R uint64_t commonreg_intstatusreg;

	/* DW_axi_dmac Software Reset Register */
	__IO_RW uint64_t resetreg;

	/* DW_axi_dmac Low Power Configuration Register */
	__IO_RW uint64_t lowpower_cfgreg;

} sedi_dmac_regs_t;
#define SEDI_DMAC_REGS_T sedi_dmac_regs_t

#endif /* _SEDI_DMAC_REGS_H_ */
