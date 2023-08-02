/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2023-08-01
 */

#ifndef _SEDI_HPET_REGS_H_
#define _SEDI_HPET_REGS_H_

#include <sedi_reg_defs.h>


/* ********* HPET GCID_LOW ***********
 *
 * Register of SEDI HPET
 *   GCID_LOW: General Capabilities And ID
 *     AddressOffset  : 0x0
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x8086a201
 */
SEDI_REG_DEFINE(HPET, GCID_LOW, 0x0, RO, (uint32_t)0x0, (uint32_t)0x8086a201);

/*
 * Bit Field of Register GCID_LOW
 *   RID: Revision ID
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(HPET, GCID_LOW, RID, 0, 8, RO, (uint32_t)0x1);

/*
 * Bit Field of Register GCID_LOW
 *   NT: Number Of Timers
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(HPET, GCID_LOW, NT, 8, 5, RO, (uint32_t)0x2);

/*
 * Bit Field of Register GCID_LOW
 *   CS: Counter Size
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(HPET, GCID_LOW, CS, 13, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(HPET, GCID_LOW, CS, 0, 0);
SEDI_RBFV_DEFINE(HPET, GCID_LOW, CS, 1, 1);

/*
 * Bit Field of Register GCID_LOW
 *   RESERVED0:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GCID_LOW, RESERVED0, 14, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, GCID_LOW, RESERVED0, 0, 0);
SEDI_RBFV_DEFINE(HPET, GCID_LOW, RESERVED0, 1, 1);

/*
 * Bit Field of Register GCID_LOW
 *   LRC: Legacy Rout Capable
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(HPET, GCID_LOW, LRC, 15, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(HPET, GCID_LOW, LRC, 0, 0);
SEDI_RBFV_DEFINE(HPET, GCID_LOW, LRC, 1, 1);

/*
 * Bit Field of Register GCID_LOW
 *   VID: Vendor ID
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x8086
 */
SEDI_RBF_DEFINE(HPET, GCID_LOW, VID, 16, 16, RO, (uint32_t)0x8086);

/* ********* HPET GCID_HIGH ***********
 *
 * Register of SEDI HPET
 *   GCID_HIGH: General Capabilities And ID
 *     AddressOffset  : 0x4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x1d1a94a
 */
SEDI_REG_DEFINE(HPET, GCID_HIGH, 0x4, RO, (uint32_t)0x0, (uint32_t)0x1d1a94a);

/*
 * Bit Field of Register GCID_HIGH
 *   CTP: Counter Tick Period
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1d1a94a
 */
SEDI_RBF_DEFINE(HPET, GCID_HIGH, CTP, 0, 32, RO, (uint32_t)0x1d1a94a);

/* ********* HPET GCFG_LOW ***********
 *
 * Register of SEDI HPET
 *   GCFG_LOW: General Configuration
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x3
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(HPET, GCFG_LOW, 0x10, RW, (uint32_t)0x3, (uint32_t)0x0);

/*
 * Bit Field of Register GCFG_LOW
 *   EN: Overall Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GCFG_LOW, EN, 0, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, GCFG_LOW, EN, 0, 0);
SEDI_RBFV_DEFINE(HPET, GCFG_LOW, EN, 1, 1);

/*
 * Bit Field of Register GCFG_LOW
 *   LRE: Overall Enable
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GCFG_LOW, LRE, 1, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, GCFG_LOW, LRE, 0, 0);
SEDI_RBFV_DEFINE(HPET, GCFG_LOW, LRE, 1, 1);

/*
 * Bit Field of Register GCFG_LOW
 *   RESERVED0:
 *     BitOffset : 2
 *     BitWidth  : 30
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GCFG_LOW, RESERVED0, 2, 30, RO, (uint32_t)0x0);

/* ********* HPET GCFG_HIGH ***********
 *
 * Register of SEDI HPET
 *   GCFG_HIGH: General Configuration
 *     AddressOffset  : 0x14
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(HPET, GCFG_HIGH, 0x14, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register GCFG_HIGH
 *   RESERVED0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GCFG_HIGH, RESERVED0, 0, 32, RO, (uint32_t)0x0);

/* ********* HPET GIS_LOW ***********
 *
 * Register of SEDI HPET
 *   GIS_LOW: General Interrupt Status
 *     AddressOffset  : 0x20
 *     AccessType     : RW
 *     WritableBitMask: 0x7
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(HPET, GIS_LOW, 0x20, RW, (uint32_t)0x7, (uint32_t)0x0);

/*
 * Bit Field of Register GIS_LOW
 *   T0: Timer 0 Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GIS_LOW, T0, 0, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, GIS_LOW, T0, 0, 0);
SEDI_RBFV_DEFINE(HPET, GIS_LOW, T0, 1, 1);

/*
 * Bit Field of Register GIS_LOW
 *   T1: Timer 1 Status
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GIS_LOW, T1, 1, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, GIS_LOW, T1, 0, 0);
SEDI_RBFV_DEFINE(HPET, GIS_LOW, T1, 1, 1);

/*
 * Bit Field of Register GIS_LOW
 *   T2: Timer 2 Status
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GIS_LOW, T2, 2, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, GIS_LOW, T2, 0, 0);
SEDI_RBFV_DEFINE(HPET, GIS_LOW, T2, 1, 1);

/*
 * Bit Field of Register GIS_LOW
 *   RESERVED0:
 *     BitOffset : 3
 *     BitWidth  : 29
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GIS_LOW, RESERVED0, 3, 29, RO, (uint32_t)0x0);

/* ********* HPET GIS_HIGH ***********
 *
 * Register of SEDI HPET
 *   GIS_HIGH: General Interrupt Status
 *     AddressOffset  : 0x24
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(HPET, GIS_HIGH, 0x24, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register GIS_HIGH
 *   RESERVED0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, GIS_HIGH, RESERVED0, 0, 32, RO, (uint32_t)0x0);

/* ********* HPET MCV_LOW ***********
 *
 * Register of SEDI HPET
 *   MCV_LOW: Main Counter Value
 *     AddressOffset  : 0x0f0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(HPET, MCV_LOW, 0x0f0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register MCV_LOW
 *   MCV_LOW: Counter Value
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, MCV_LOW, MCV_LOW, 0, 32, RW_V, (uint32_t)0x0);

/* ********* HPET MCV_HIGH ***********
 *
 * Register of SEDI HPET
 *   MCV_HIGH: Main Counter Value
 *     AddressOffset  : 0x0f4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(HPET, MCV_HIGH, 0x0f4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register MCV_HIGH
 *   MCV_HIGH: Counter Value
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, MCV_HIGH, MCV_HIGH, 0, 32, RW_V, (uint32_t)0x0);

/* ********* HPET T0C_LOW ***********
 *
 * Register of SEDI HPET
 *   T0C_LOW: Timer N Config And Capabilities
 *     AddressOffset  : 0x100
 *     AccessType     : RW
 *     WritableBitMask: 0x3f4e
 *     ResetValue     : (uint32_t)0x30
 */
SEDI_REG_DEFINE(HPET, T0C_LOW, 0x100, RW, (uint32_t)0x3f4e, (uint32_t)0x30);

/*
 * Bit Field of Register T0C_LOW
 *   RESERVED2:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, RESERVED2, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, RESERVED2, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, RESERVED2, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   IT: Timer Interrupt Type
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, IT, 1, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, IT, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, IT, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   IE: Interrupt Enable
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, IE, 2, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, IE, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, IE, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   TYP: Timer Type
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, TYP, 3, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, TYP, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, TYP, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   PIC: Periodic Interrupt Capable
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, PIC, 4, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, PIC, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, PIC, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   TS: Timer Size
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, TS, 5, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, TS, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, TS, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   TVS: Timer Value Set
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, TVS, 6, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, TVS, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, TVS, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   RESERVED1:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, RESERVED1, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, RESERVED1, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, RESERVED1, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   T32M: Timer 32-Bit Mode
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, T32M, 8, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, T32M, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, T32M, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   IR: Interrupt Rout
 *     BitOffset : 9
 *     BitWidth  : 5
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, IR, 9, 5, RW_V, (uint32_t)0x0);

/*
 * Bit Field of Register T0C_LOW
 *   FE: FSB Enable
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, FE, 14, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, FE, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, FE, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   FID: FSB Interrupt Delivery
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, FID, 15, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, FID, 0, 0);
SEDI_RBFV_DEFINE(HPET, T0C_LOW, FID, 1, 1);

/*
 * Bit Field of Register T0C_LOW
 *   RESERVED0:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T0C_LOW, RESERVED0, 16, 16, RO, (uint32_t)0x0);

/* ********* HPET T0C_HIGH ***********
 *
 * Register of SEDI HPET
 *   T0C_HIGH: Timer N Config And Capabilities
 *     AddressOffset  : 0x104
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0xf00000
 */
SEDI_REG_DEFINE(HPET, T0C_HIGH, 0x104, RO, (uint32_t)0x0, (uint32_t)0xf00000);

/*
 * Bit Field of Register T0C_HIGH
 *   IRC: Interrupt Rout Capability
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0f00000
 */
SEDI_RBF_DEFINE(HPET, T0C_HIGH, IRC, 0, 32, RO, (uint32_t)0x0f00000);

/* ********* HPET T0CV_LOW ***********
 *
 * Register of SEDI HPET
 *   T0CV_LOW: Timer N Comparator Value
 *     AddressOffset  : 0x108
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)-1
 */
SEDI_REG_DEFINE(HPET, T0CV_LOW, 0x108, RW, (uint32_t)0xffffffff, (uint32_t)-1);

/*
 * Bit Field of Register T0CV_LOW
 *   T0CV_LOW:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0ffffffff
 */
SEDI_RBF_DEFINE(HPET, T0CV_LOW, T0CV_LOW, 0, 32, RW_V, (uint32_t)0x0ffffffff);

/* ********* HPET T0CV_HIGH ***********
 *
 * Register of SEDI HPET
 *   T0CV_HIGH: Timer N Comparator Value
 *     AddressOffset  : 0x10c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)-1
 */
SEDI_REG_DEFINE(HPET, T0CV_HIGH, 0x10c, RW, (uint32_t)0xffffffff, (uint32_t)-1);

/*
 * Bit Field of Register T0CV_HIGH
 *   T0CV_HIGH:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0ffffffff
 */
SEDI_RBF_DEFINE(HPET, T0CV_HIGH, T0CV_HIGH, 0, 32, RW_V, (uint32_t)0x0ffffffff);

/* ********* HPET T1C_LOW ***********
 *
 * Register of SEDI HPET
 *   T1C_LOW: Timer N Config And Capabilities
 *     AddressOffset  : 0x120
 *     AccessType     : RW
 *     WritableBitMask: 0x3e06
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(HPET, T1C_LOW, 0x120, RW, (uint32_t)0x3e06, (uint32_t)0x0);

/*
 * Bit Field of Register T1C_LOW
 *   RESERVED2:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, RESERVED2, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, RESERVED2, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, RESERVED2, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   IT: Timer Interrupt Type
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, IT, 1, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, IT, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, IT, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   IE: Interrupt Enable
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, IE, 2, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, IE, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, IE, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   TYP: Timer Type
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, TYP, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, TYP, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, TYP, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   PIC: Periodic Interrupt Capable
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, PIC, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, PIC, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, PIC, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   TS: Timer Size
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, TS, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, TS, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, TS, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   TVS: Timer Value Set
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, TVS, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, TVS, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, TVS, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   RESERVED1:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, RESERVED1, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, RESERVED1, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, RESERVED1, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   T32M: Timer 32-Bit Mode
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, T32M, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, T32M, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, T32M, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   IR: Interrupt Route
 *     BitOffset : 9
 *     BitWidth  : 5
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, IR, 9, 5, RW_V, (uint32_t)0x0);

/*
 * Bit Field of Register T1C_LOW
 *   FE: FSB Enable
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, FE, 14, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, FE, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, FE, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   FID: FSB Interrupt Delivery
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, FID, 15, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, FID, 0, 0);
SEDI_RBFV_DEFINE(HPET, T1C_LOW, FID, 1, 1);

/*
 * Bit Field of Register T1C_LOW
 *   RESERVED0:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T1C_LOW, RESERVED0, 16, 16, RO, (uint32_t)0x0);

/* ********* HPET T1C_HIGH ***********
 *
 * Register of SEDI HPET
 *   T1C_HIGH: Timer N Config And Capabilities
 *     AddressOffset  : 0x124
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0xf00000
 */
SEDI_REG_DEFINE(HPET, T1C_HIGH, 0x124, RO, (uint32_t)0x0, (uint32_t)0xf00000);

/*
 * Bit Field of Register T1C_HIGH
 *   IRC: Interrupt Rout Capability
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0f00000
 */
SEDI_RBF_DEFINE(HPET, T1C_HIGH, IRC, 0, 32, RO, (uint32_t)0x0f00000);

/* ********* HPET T1CV_LOW ***********
 *
 * Register of SEDI HPET
 *   T1CV_LOW: Timer N Comparator Value
 *     AddressOffset  : 0x128
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)-1
 */
SEDI_REG_DEFINE(HPET, T1CV_LOW, 0x128, RW, (uint32_t)0xffffffff, (uint32_t)-1);

/*
 * Bit Field of Register T1CV_LOW
 *   T1CV:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0ffffffff
 */
SEDI_RBF_DEFINE(HPET, T1CV_LOW, T1CV, 0, 32, RW_V, (uint32_t)0x0ffffffff);

/* ********* HPET T2C_LOW ***********
 *
 * Register of SEDI HPET
 *   T2C_LOW: Timer N Config And Capabilities
 *     AddressOffset  : 0x140
 *     AccessType     : RW
 *     WritableBitMask: 0x3e06
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(HPET, T2C_LOW, 0x140, RW, (uint32_t)0x3e06, (uint32_t)0x0);

/*
 * Bit Field of Register T2C_LOW
 *   RESERVED2:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, RESERVED2, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, RESERVED2, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, RESERVED2, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   IT: Timer Interrupt Type
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, IT, 1, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, IT, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, IT, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   IE: Interrupt Enable
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, IE, 2, 1, RW_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, IE, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, IE, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   TYP: Timer Type
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, TYP, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, TYP, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, TYP, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   PIC: Periodic Interrupt Capable
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, PIC, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, PIC, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, PIC, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   TS: Timer Size
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, TS, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, TS, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, TS, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   TVS: Timer Value Set
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, TVS, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, TVS, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, TVS, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   RESERVED1:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, RESERVED1, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, RESERVED1, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, RESERVED1, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   T32M: Timer 32-Bit Mode
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, T32M, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, T32M, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, T32M, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   IR: Interrupt Route
 *     BitOffset : 9
 *     BitWidth  : 5
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, IR, 9, 5, RW_V, (uint32_t)0x0);

/*
 * Bit Field of Register T2C_LOW
 *   FE: FSB Enable
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, FE, 14, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, FE, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, FE, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   FID: FSB Interrupt Delivery
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, FID, 15, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, FID, 0, 0);
SEDI_RBFV_DEFINE(HPET, T2C_LOW, FID, 1, 1);

/*
 * Bit Field of Register T2C_LOW
 *   RESERVED0:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, T2C_LOW, RESERVED0, 16, 16, RO, (uint32_t)0x0);

/* ********* HPET T2C_HIGH ***********
 *
 * Register of SEDI HPET
 *   T2C_HIGH: Timer N Config And Capabilities
 *     AddressOffset  : 0x144
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0xf00800
 */
SEDI_REG_DEFINE(HPET, T2C_HIGH, 0x144, RO, (uint32_t)0x0, (uint32_t)0xf00800);

/*
 * Bit Field of Register T2C_HIGH
 *   IRC: Interrupt Rout Capability
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0f00800
 */
SEDI_RBF_DEFINE(HPET, T2C_HIGH, IRC, 0, 32, RO, (uint32_t)0x0f00800);

/* ********* HPET T2CV_LOW ***********
 *
 * Register of SEDI HPET
 *   T2CV_LOW: Timer N Comparator Value
 *     AddressOffset  : 0x148
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)-1
 */
SEDI_REG_DEFINE(HPET, T2CV_LOW, 0x148, RW, (uint32_t)0xffffffff, (uint32_t)-1);

/*
 * Bit Field of Register T2CV_LOW
 *   T2CV:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x0ffffffff
 */
SEDI_RBF_DEFINE(HPET, T2CV_LOW, T2CV, 0, 32, RW_V, (uint32_t)0x0ffffffff);

/* ********* HPET HPET_CTRL_STS ***********
 *
 * Register of SEDI HPET
 *   HPET_CTRL_STS: HPET Control And Status
 *     AddressOffset  : 0x160
 *     AccessType     : RW
 *     WritableBitMask: 0xc0000000
 *     ResetValue     : (uint32_t)0x80000000
 */
SEDI_REG_DEFINE(HPET, HPET_CTRL_STS, 0x160, RW, (uint32_t)0xc0000000, (uint32_t)0x80000000);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS0:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS0, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS0, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS0, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS1:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS1, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS1, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS1, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS2:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS2, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS2, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS2, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS3:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS3, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS3, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS3, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS4:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS4, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS4, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS4, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS5:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS5, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS5, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS5, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS6:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS6, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS6, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS6, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS7:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS7, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS7, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS7, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS8:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS8, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS8, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS8, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS9:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS9, 9, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS9, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS9, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS10:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS10, 10, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS10, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS10, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS11:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS11, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS11, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS11, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS12:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS12, 12, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS12, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS12, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS13:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS13, 13, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS13, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS13, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS16_29:
 *     BitOffset : 14
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS16_29, 14, 16, RO, (uint32_t)0x0);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS30: Write In Progress Status Bit Disable
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS30, 30, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS30, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS30, 1, 1);

/*
 * Bit Field of Register HPET_CTRL_STS
 *   HPET_CTRL_STS31: Enbale HPET Latency Fix
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW_V
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS31, 31, 1, RW_V, (uint32_t)0x1);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS31, 0, 0);
SEDI_RBFV_DEFINE(HPET, HPET_CTRL_STS, HPET_CTRL_STS31, 1, 1);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* General Capabilities And ID */
	__IO_R uint32_t gcid_low;

	/* General Capabilities And ID */
	__IO_R uint32_t gcid_high;

	/* Reserved */
	__IO_RW uint32_t reserved0[2];

	/* General Configuration */
	__IO_RW uint32_t gcfg_low;

	/* General Configuration */
	__IO_R uint32_t gcfg_high;

	/* Reserved */
	__IO_RW uint32_t reserved1[2];

	/* General Interrupt Status */
	__IO_RW uint32_t gis_low;

	/* General Interrupt Status */
	__IO_R uint32_t gis_high;

	/* Reserved */
	__IO_RW uint32_t reserved2[50];

	/* Main Counter Value */
	__IO_RW uint32_t mcv_low;

	/* Main Counter Value */
	__IO_RW uint32_t mcv_high;

	/* Reserved */
	__IO_RW uint32_t reserved3[2];

	/* Timer N Config And Capabilities */
	__IO_RW uint32_t t0c_low;

	/* Timer N Config And Capabilities */
	__IO_R uint32_t t0c_high;

	/* Timer N Comparator Value */
	__IO_RW uint32_t t0cv_low;

	/* Timer N Comparator Value */
	__IO_RW uint32_t t0cv_high;

	/* Reserved */
	__IO_RW uint32_t reserved4[4];

	/* Timer N Config And Capabilities */
	__IO_RW uint32_t t1c_low;

	/* Timer N Config And Capabilities */
	__IO_R uint32_t t1c_high;

	/* Timer N Comparator Value */
	__IO_RW uint32_t t1cv_low;

	/* Reserved */
	__IO_RW uint32_t reserved5[5];

	/* Timer N Config And Capabilities */
	__IO_RW uint32_t t2c_low;

	/* Timer N Config And Capabilities */
	__IO_R uint32_t t2c_high;

	/* Timer N Comparator Value */
	__IO_RW uint32_t t2cv_low;

	/* Reserved */
	__IO_RW uint32_t reserved6[5];

	/* HPET Control And Status */
	__IO_RW uint32_t hpet_ctrl_sts;

} sedi_hpet_regs_t;


#endif /* _SEDI_HPET_REGS_H_ */
