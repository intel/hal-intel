/*
 * Copyright (c) 2024-2025 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2024-09-23
 */

#ifndef _SEDI_MISC_REGS_H_
#define _SEDI_MISC_REGS_H_

#include <sedi_reg_defs.h>

/* ********* MISC ISH_FUSE0 ***********
 *
 * Register of SEDI MISC
 *   ISH_FUSE0: ISH Fuses 0 -31
 *     AddressOffset  : 0x50
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x1c4
 */
SEDI_REG_DEFINE(MISC, ISH_FUSE0, 0x50, RO, (uint32_t)0x0, (uint32_t)0x1c4);

/*
 * Bit Field of Register ISH_FUSE0
 *   DW0: Fuse Data  Bits 31 To 0
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1c4
 */
SEDI_RBF_DEFINE(MISC, ISH_FUSE0, DW0, 0, 32, RO, (uint32_t)0x1c4);

/* ********* MISC ISH_FUSE1 ***********
 *
 * Register of SEDI MISC
 *   ISH_FUSE1: ISH Fuses 32 -63
 *     AddressOffset  : 0x54
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_FUSE1, 0x54, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_FUSE1
 *   DW1: Fuse Data  Bits 63 To 32
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_FUSE1, DW1, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_FUSE2 ***********
 *
 * Register of SEDI MISC
 *   ISH_FUSE2: ISH Fuses 64 -95
 *     AddressOffset  : 0x58
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_FUSE2, 0x58, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_FUSE2
 *   DW2: Fuse Data  Bits 95 To 64
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_FUSE2, DW2, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_SOFT_STRAP0 ***********
 *
 * Register of SEDI MISC
 *   ISH_SOFT_STRAP0: ISH SOFT STRAP 0 -31
 *     AddressOffset  : 0x5c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x68000000
 */
SEDI_REG_DEFINE(MISC, ISH_SOFT_STRAP0, 0x5c, RO, (uint32_t)0x0, (uint32_t)0x68000000);

/*
 * Bit Field of Register ISH_SOFT_STRAP0
 *   DW0: Soft Strap Bits 31 To 0
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x68000000
 */
SEDI_RBF_DEFINE(MISC, ISH_SOFT_STRAP0, DW0, 0, 32, RO, (uint32_t)0x68000000);

/* ********* MISC ISH_SOFT_STRAP1 ***********
 *
 * Register of SEDI MISC
 *   ISH_SOFT_STRAP1: ISH SOFT STRAP 32 -63
 *     AddressOffset  : 0x60
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_SOFT_STRAP1, 0x60, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_SOFT_STRAP1
 *   DW1: Soft Strap Bits 63 To 32
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_SOFT_STRAP1, DW1, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_SOFT_STRAP2 ***********
 *
 * Register of SEDI MISC
 *   ISH_SOFT_STRAP2: ISH SOFT STRAP 64 -95
 *     AddressOffset  : 0x64
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_SOFT_STRAP2, 0x64, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_SOFT_STRAP2
 *   DW2: Soft Strap Bits 95 To 64
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_SOFT_STRAP2, DW2, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC RESERVED9 ***********
 *
 * Register of SEDI MISC
 *   RESERVED9: _RESERVED9
 *     AddressOffset  : 0x68
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, RESERVED9, 0x68, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RESERVED9
 *   RESERVED0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, RESERVED9, RESERVED0, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC DFX_VISA_MILESTONE ***********
 *
 * Register of SEDI MISC
 *   DFX_VISA_MILESTONE: DFX VISA Milestone
 *     AddressOffset  : 0x6c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, DFX_VISA_MILESTONE, 0x6c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DFX_VISA_MILESTONE
 *   DFX_VISA_MILESTONE_bit31to0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, DFX_VISA_MILESTONE, DFX_VISA_MILESTONE_bit31to0, 0, 32, RW, (uint32_t)0x0);

/* ********* MISC ISH_RTC_COUNTER0 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_COUNTER0: ISH RTC Counter LSB Value
 *     AddressOffset  : 0x70
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_COUNTER0, 0x70, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_COUNTER0
 *   ISH_RTC_COUNTER0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_COUNTER0, ISH_RTC_COUNTER0, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_COUNTER1 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_COUNTER1: ISH RTC Counter MSB Value
 *     AddressOffset  : 0x74
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_COUNTER1, 0x74, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_COUNTER1
 *   ISH_RTC_COUNTER1:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_COUNTER1, ISH_RTC_COUNTER1, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_MISC_ART_SNAPSHOT_LO_ADDR ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_ART_SNAPSHOT_LO_ADDR: 31:0 Of 64 Bit Snapshot Value Synchronized Using Sync Pulse
 *     AddressOffset  : 0xa0
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_LO_ADDR, 0xa0, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MISC_ART_SNAPSHOT_LO_ADDR
 *   ISH_MISC_ART_SNAPSHOT_LO_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_LO_ADDR, ISH_MISC_ART_SNAPSHOT_LO_ADDR, 0, 32, RO,
		(uint32_t)0x0);

/* ********* MISC ISH_MISC_ART_SNAPSHOT_HI_ADDR ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_ART_SNAPSHOT_HI_ADDR: 63:32 Of 64 Bit Snapshot Value Synchronized Using Sync Pulse
 *     AddressOffset  : 0xa4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_HI_ADDR, 0xa4, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MISC_ART_SNAPSHOT_HI_ADDR
 *   ISH_MISC_ART_SNAPSHOT_HI_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_HI_ADDR, ISH_MISC_ART_SNAPSHOT_HI_ADDR, 0, 32, RO,
		(uint32_t)0x0);

/* ********* MISC ISH_MISC_ART_SNAPSHOT_CTRL_ADDR ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_ART_SNAPSHOT_CTRL_ADDR: Snapshot Control And Status
 *     AddressOffset  : 0xa8
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR, 0xa8, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MISC_ART_SNAPSHOT_CTRL_ADDR
 *   ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_0:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_0, 0, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_0, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_0, 1, 1);

/*
 * Bit Field of Register ISH_MISC_ART_SNAPSHOT_CTRL_ADDR
 *   ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_1:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_1, 1, 1, RO,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_1, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_1, 1, 1);

/*
 * Bit Field of Register ISH_MISC_ART_SNAPSHOT_CTRL_ADDR
 *   ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_RES:
 *     BitOffset : 2
 *     BitWidth  : 30
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR, ISH_MISC_ART_SNAPSHOT_CTRL_ADDR_RES, 2, 30,
		RO, (uint32_t)0x0);

/* ********* MISC HH_ART_TS_CTRL ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TS_CTRL: HH ART Timestamp Control
 *     AddressOffset  : 0xc0
 *     AccessType     : RW
 *     WritableBitMask: 0x33
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, HH_ART_TS_CTRL, 0xc0, RW, (uint32_t)0x33, (uint32_t)0x0);

/*
 * Bit Field of Register HH_ART_TS_CTRL
 *   HH_TIMESTAMP_en:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TS_CTRL, HH_TIMESTAMP_en, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, HH_TIMESTAMP_en, 0, 0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, HH_TIMESTAMP_en, 1, 1);

/*
 * Bit Field of Register HH_ART_TS_CTRL
 *   HH_FWUpd:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_AC
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TS_CTRL, HH_FWUpd, 1, 1, RW_AC, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, HH_FWUpd, 0, 0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, HH_FWUpd, 1, 1);

/*
 * Bit Field of Register HH_ART_TS_CTRL
 *   RESERVED2:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TS_CTRL, RESERVED2, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, RESERVED2, 0, 0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, RESERVED2, 1, 1);

/*
 * Bit Field of Register HH_ART_TS_CTRL
 *   RESERVED1:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TS_CTRL, RESERVED1, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, RESERVED1, 0, 0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, RESERVED1, 1, 1);

/*
 * Bit Field of Register HH_ART_TS_CTRL
 *   HH_ART_TIMER_SEL:
 *     BitOffset : 4
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TS_CTRL, HH_ART_TIMER_SEL, 4, 2, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, HH_ART_TIMER_SEL, XTAL_CLK, 0);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, HH_ART_TIMER_SEL, AON_CLK, 1);
SEDI_RBFV_DEFINE(MISC, HH_ART_TS_CTRL, HH_ART_TIMER_SEL, RTC_CLK, 2);

/*
 * Bit Field of Register HH_ART_TS_CTRL
 *   RESERVED0:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TS_CTRL, RESERVED0, 6, 26, RO, (uint32_t)0x0);

/* ********* MISC HH_ART_TB_STAMP_LOW ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TB_STAMP_LOW: [31:0] Of HH FW Value Low
 *     AddressOffset  : 0xc4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, HH_ART_TB_STAMP_LOW, 0xc4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register HH_ART_TB_STAMP_LOW
 *   HH_FW_VALUE_LOW:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TB_STAMP_LOW, HH_FW_VALUE_LOW, 0, 32, RW, (uint32_t)0x0);

/* ********* MISC HH_ART_TB_STAMP_HIGH ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TB_STAMP_HIGH: [63:32] Of HH FW Value High
 *     AddressOffset  : 0xc8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, HH_ART_TB_STAMP_HIGH, 0xc8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register HH_ART_TB_STAMP_HIGH
 *   HH_FW_VALUE_HIGH:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TB_STAMP_HIGH, HH_FW_VALUE_HIGH, 0, 32, RW, (uint32_t)0x0);

/* ********* MISC HH_SATURATION ***********
 *
 * Register of SEDI MISC
 *   HH_SATURATION: HH Saturation Staus
 *     AddressOffset  : 0xcc
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, HH_SATURATION, 0xcc, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register HH_SATURATION
 *   HH_SAT_STAT:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_SATURATION, HH_SAT_STAT, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, HH_SATURATION, HH_SAT_STAT, 0, 0);
SEDI_RBFV_DEFINE(MISC, HH_SATURATION, HH_SAT_STAT, 1, 1);

/*
 * Bit Field of Register HH_SATURATION
 *   HH_UPD_IN_PROG:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_SATURATION, HH_UPD_IN_PROG, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, HH_SATURATION, HH_UPD_IN_PROG, 0, 0);
SEDI_RBFV_DEFINE(MISC, HH_SATURATION, HH_UPD_IN_PROG, 1, 1);

/*
 * Bit Field of Register HH_SATURATION
 *   RESERVED0:
 *     BitOffset : 2
 *     BitWidth  : 30
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_SATURATION, RESERVED0, 2, 30, RO, (uint32_t)0x0);

/* ********* MISC HH_ART_RD_TS_SNAPSHOT_LOW ***********
 *
 * Register of SEDI MISC
 *   HH_ART_RD_TS_SNAPSHOT_LOW: [31:0[]  Of Local Art Sync Counter
 *     AddressOffset  : 0xd0
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, HH_ART_RD_TS_SNAPSHOT_LOW, 0xd0, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register HH_ART_RD_TS_SNAPSHOT_LOW
 *   ISH_HH_ART_RD_TS_SNAPSHOT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_RD_TS_SNAPSHOT_LOW, ISH_HH_ART_RD_TS_SNAPSHOT, 0, 32, RO,
		(uint32_t)0x0);

/* ********* MISC HH_ART_RD_TS_SNAPSHOT_HIGH ***********
 *
 * Register of SEDI MISC
 *   HH_ART_RD_TS_SNAPSHOT_HIGH: [63:32] OfLocal Art Sync Counter
 *     AddressOffset  : 0xd4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, HH_ART_RD_TS_SNAPSHOT_HIGH, 0xd4, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register HH_ART_RD_TS_SNAPSHOT_HIGH
 *   ISH_HH_ART_RD_TS_SNAPSHOT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_RD_TS_SNAPSHOT_HIGH, ISH_HH_ART_RD_TS_SNAPSHOT, 0, 32, RO,
		(uint32_t)0x0);

/* ********* MISC ISH_MISC_REVISION_ID ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_REVISION_ID: Revision ID
 *     AddressOffset  : 0x100
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0xd
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_REVISION_ID, 0x100, RO, (uint32_t)0x0, (uint32_t)0xd);

/*
 * Bit Field of Register ISH_MISC_REVISION_ID
 *   ISH_MISC_REVISION_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0d
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_REVISION_ID, ISH_MISC_REVISION_ID, 0, 32, RO, (uint32_t)0x0d);

/* ********* MISC ISH_MISC_ECO_RO ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_ECO_RO: This Is Spare ROFor ECO.
 *     AddressOffset  : 0x200
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_ECO_RO, 0x200, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MISC_ECO_RO
 *   ISH_MISC_ECO_RO:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ECO_RO, ISH_MISC_ECO_RO, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_MISC_ECO_RW ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_ECO_RW: This Is Spare RWFor ECO.
 *     AddressOffset  : 0x204
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_ECO_RW, 0x204, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MISC_ECO_RW
 *   ISH_MISC_ECO_RW2:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ECO_RW, ISH_MISC_ECO_RW2, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_MISC_ECO_RW, ISH_MISC_ECO_RW2, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_MISC_ECO_RW, ISH_MISC_ECO_RW2, 1, 1);

/*
 * Bit Field of Register ISH_MISC_ECO_RW
 *   ISH_MISC_ECO_RW1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ECO_RW, ISH_MISC_ECO_RW1, 1, 31, RW, (uint32_t)0x0);

/* ********* MISC ISH_MISC_ECO_RW1C ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_ECO_RW1C: This Is Spare RW1CFor ECO
 *     AddressOffset  : 0x208
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_ECO_RW1C, 0x208, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MISC_ECO_RW1C
 *   ISH_MISC_ECO_RW1C:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ECO_RW1C, ISH_MISC_ECO_RW1C, 0, 32, RW_1C, (uint32_t)0x0);

/* ********* MISC ISH_MISC_ECO_RET_RW ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_ECO_RET_RW: This Is Spare Retention RWFor ECO.
 *     AddressOffset  : 0x20c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_ECO_RET_RW, 0x20c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MISC_ECO_RET_RW
 *   HPET_CHK_BIT: HPET CHK BIT
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ECO_RET_RW, HPET_CHK_BIT, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_MISC_ECO_RET_RW, HPET_CHK_BIT, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_MISC_ECO_RET_RW, HPET_CHK_BIT, 1, 1);

/*
 * Bit Field of Register ISH_MISC_ECO_RET_RW
 *   Spare_bits: Spare Bits
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ECO_RET_RW, Spare_bits, 1, 31, RW, (uint32_t)0x0);

/* ********* MISC ISH_MISC_ECO_RET_RW1C ***********
 *
 * Register of SEDI MISC
 *   ISH_MISC_ECO_RET_RW1C: This Is Spare Retention RW1CFor ECO.
 *     AddressOffset  : 0x210
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_MISC_ECO_RET_RW1C, 0x210, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MISC_ECO_RET_RW1C
 *   ISH_MISC_ECO_RET_RW1C:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_MISC_ECO_RET_RW1C, ISH_MISC_ECO_RET_RW1C, 0, 32, RW_1C, (uint32_t)0x0);

/* ********* MISC ISH_CSE_SAI_PORTID_STRAP ***********
 *
 * Register of SEDI MISC
 *   ISH_CSE_SAI_PORTID_STRAP: Ish_cse_sai_portid_strap
 *     AddressOffset  : 0x214
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_CSE_SAI_PORTID_STRAP, 0x214, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_CSE_SAI_PORTID_STRAP
 *   ISH_CSE_PORTID_STRAP: Ish_cse_portid
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_CSE_SAI_PORTID_STRAP, ISH_CSE_PORTID_STRAP, 0, 8, RO_V, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_CSE_SAI_PORTID_STRAP
 *   ISH_CSE_SAI_STRAP: Ish_cse_sai
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_CSE_SAI_PORTID_STRAP, ISH_CSE_SAI_STRAP, 8, 8, RO_V, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_CSE_SAI_PORTID_STRAP
 *   RESERVED0: Reserved
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_CSE_SAI_PORTID_STRAP, RESERVED0, 16, 16, RO, (uint32_t)0x0);

/* ********* MISC ISH_ESE_SAI_PORTID_STRAP ***********
 *
 * Register of SEDI MISC
 *   ISH_ESE_SAI_PORTID_STRAP: Ish_ese_sai_portid_strap
 *     AddressOffset  : 0x218
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_ESE_SAI_PORTID_STRAP, 0x218, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_ESE_SAI_PORTID_STRAP
 *   ISH_ESE_PORTID_STRAP: Ish_ese_portid
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_ESE_SAI_PORTID_STRAP, ISH_ESE_PORTID_STRAP, 0, 8, RO_V, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_ESE_SAI_PORTID_STRAP
 *   ISH_ESE_SAI_STRAP: Ish_ese_sai
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_ESE_SAI_PORTID_STRAP, ISH_ESE_SAI_STRAP, 8, 8, RO_V, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_ESE_SAI_PORTID_STRAP
 *   RESERVED0: Reserved
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_ESE_SAI_PORTID_STRAP, RESERVED0, 16, 16, RO, (uint32_t)0x0);

/* ********* MISC ISH_FDFX_SECURITY_POLICY ***********
 *
 * Register of SEDI MISC
 *   ISH_FDFX_SECURITY_POLICY: Ish_fdfx_secure_policy
 *     AddressOffset  : 0x21c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_FDFX_SECURITY_POLICY, 0x21c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_FDFX_SECURITY_POLICY
 *   ISH_FDFX_SECURE_POLICY: Ish_fdfx_secure_policy
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_FDFX_SECURITY_POLICY, ISH_FDFX_SECURE_POLICY, 0, 4, RO_V, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_FDFX_SECURITY_POLICY
 *   RESERVED0: Reserved
 *     BitOffset : 4
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_FDFX_SECURITY_POLICY, RESERVED0, 4, 28, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_CTRL0 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_CTRL0: AON Timestamp Control0
 *     AddressOffset  : 0x220
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, 0x220, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL0
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL0
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL0
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL0, BUSY, 1, 1);

/* ********* MISC ISH_AON_TIMESTAMP_LOW0 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_LOW0: AON Timestamp Capture LOWregister0
 *     AddressOffset  : 0x224
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_LOW0, 0x224, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_LOW0
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_LOW0, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_HIGH0 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_HIGH0: AON Timestamp Control HIGH0
 *     AddressOffset  : 0x228
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_HIGH0, 0x228, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_HIGH0
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_HIGH0, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_STATUS0 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_STATUS0: AON Timestamp Control STATUS0
 *     AddressOffset  : 0x22c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS0, 0x22c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_STATUS0
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_STATUS0
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS0, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_CTRL1 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_CTRL1: AON Timestamp Control1
 *     AddressOffset  : 0x230
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, 0x230, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL1
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL1
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL1
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL1, BUSY, 1, 1);

/* ********* MISC ISH_AON_TIMESTAMP_LOW1 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_LOW1: AON Timestamp Capture LOWregister1
 *     AddressOffset  : 0x234
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_LOW1, 0x234, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_LOW1
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_LOW1, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_HIGH1 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_HIGH1: AON Timestamp Control HIGH1
 *     AddressOffset  : 0x238
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_HIGH1, 0x238, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_HIGH1
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_HIGH1, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_STATUS1 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_STATUS1: AON Timestamp Control STATUS1
 *     AddressOffset  : 0x23c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS1, 0x23c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_STATUS1
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_STATUS1
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS1, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_CTRL2 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_CTRL2: AON Timestamp Control2
 *     AddressOffset  : 0x240
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, 0x240, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL2
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL2
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL2
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL2, BUSY, 1, 1);

/* ********* MISC ISH_AON_TIMESTAMP_LOW2 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_LOW2: AON Timestamp Capture LOWregister2
 *     AddressOffset  : 0x244
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_LOW2, 0x244, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_LOW2
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_LOW2, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_HIGH2 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_HIGH2: AON Timestamp Control HIGH2
 *     AddressOffset  : 0x248
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_HIGH2, 0x248, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_HIGH2
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_HIGH2, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_STATUS2 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_STATUS2: AON Timestamp Control STATUS2
 *     AddressOffset  : 0x24c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS2, 0x24c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_STATUS2
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_STATUS2
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS2, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_CTRL3 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_CTRL3: AON Timestamp Control3
 *     AddressOffset  : 0x250
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, 0x250, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL3
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL3
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_CTRL3
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_CTRL3, BUSY, 1, 1);

/* ********* MISC ISH_AON_TIMESTAMP_LOW3 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_LOW3: AON Timestamp Capture LOWregister3
 *     AddressOffset  : 0x254
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_LOW3, 0x254, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_LOW3
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_LOW3, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_HIGH3 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_HIGH3: AON Timestamp Control HIGH3
 *     AddressOffset  : 0x258
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_HIGH3, 0x258, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_HIGH3
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_HIGH3, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_AON_TIMESTAMP_STATUS3 ***********
 *
 * Register of SEDI MISC
 *   ISH_AON_TIMESTAMP_STATUS3: AON Timestamp Control STATUS3
 *     AddressOffset  : 0x25c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS3, 0x25c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_STATUS3
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_AON_TIMESTAMP_STATUS3
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_AON_TIMESTAMP_STATUS3, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_CTRL0 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_CTRL0: RTC Timestamp Control0
 *     AddressOffset  : 0x260
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, 0x260, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL0
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL0
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL0
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL0, BUSY, 1, 1);

/* ********* MISC ISH_RTC_TIMESTAMP_LOW0 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_LOW0: RTC Timestamp Capture LOWregister0
 *     AddressOffset  : 0x264
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_LOW0, 0x264, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_LOW0
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_LOW0, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_HIGH0 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_HIGH0: RTC Timestamp Control HIGH0
 *     AddressOffset  : 0x268
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_HIGH0, 0x268, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_HIGH0
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_HIGH0, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_STATUS0 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_STATUS0: RTC Timestamp Control STATUS0
 *     AddressOffset  : 0x26c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS0, 0x26c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_STATUS0
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_STATUS0
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS0, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_CTRL1 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_CTRL1: RTC Timestamp Control1
 *     AddressOffset  : 0x270
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, 0x270, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL1
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL1
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL1
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL1, BUSY, 1, 1);

/* ********* MISC ISH_RTC_TIMESTAMP_LOW1 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_LOW1: RTC Timestamp Capture LOWregister1
 *     AddressOffset  : 0x274
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_LOW1, 0x274, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_LOW1
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_LOW1, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_HIGH1 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_HIGH1: RTC Timestamp Control HIGH1
 *     AddressOffset  : 0x278
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_HIGH1, 0x278, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_HIGH1
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_HIGH1, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_STATUS1 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_STATUS1: RTC Timestamp Control STATUS1
 *     AddressOffset  : 0x27c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS1, 0x27c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_STATUS1
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_STATUS1
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS1, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_CTRL2 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_CTRL2: RTC Timestamp Control2
 *     AddressOffset  : 0x280
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, 0x280, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL2
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL2
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL2
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL2, BUSY, 1, 1);

/* ********* MISC ISH_RTC_TIMESTAMP_LOW2 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_LOW2: RTC Timestamp Capture LOWregister2
 *     AddressOffset  : 0x284
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_LOW2, 0x284, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_LOW2
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_LOW2, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_HIGH2 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_HIGH2: RTC Timestamp Control HIGH2
 *     AddressOffset  : 0x288
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_HIGH2, 0x288, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_HIGH2
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_HIGH2, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_STATUS2 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_STATUS2: RTC Timestamp Control STATUS2
 *     AddressOffset  : 0x28c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS2, 0x28c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_STATUS2
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_STATUS2
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS2, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_CTRL3 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_CTRL3: RTC Timestamp Control3
 *     AddressOffset  : 0x290
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, 0x290, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL3
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL3
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_CTRL3
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_CTRL3, BUSY, 1, 1);

/* ********* MISC ISH_RTC_TIMESTAMP_LOW3 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_LOW3: RTC Timestamp Capture LOWregister3
 *     AddressOffset  : 0x294
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_LOW3, 0x294, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_LOW3
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_LOW3, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_HIGH3 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_HIGH3: RTC Timestamp Control HIGH3
 *     AddressOffset  : 0x298
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_HIGH3, 0x298, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_HIGH3
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_HIGH3, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_RTC_TIMESTAMP_STATUS3 ***********
 *
 * Register of SEDI MISC
 *   ISH_RTC_TIMESTAMP_STATUS3: RTC Timestamp Control STATUS3
 *     AddressOffset  : 0x29c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS3, 0x29c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_STATUS3
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_RTC_TIMESTAMP_STATUS3
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_RTC_TIMESTAMP_STATUS3, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_CTRL0 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_CTRL0: XTAL Timestamp Control0
 *     AddressOffset  : 0x2a0
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, 0x2a0, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL0
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL0
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW,
		(uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL0
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL0
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL0, BUSY, 1, 1);

/* ********* MISC ISH_XTAL_TIMESTAMP_LOW0 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_LOW0: XTAL Timestamp Capture LOWregister0
 *     AddressOffset  : 0x2a4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_LOW0, 0x2a4, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_LOW0
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_LOW0, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_HIGH0 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_HIGH0: XTAL Timestamp Control HIGH0
 *     AddressOffset  : 0x2a8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_HIGH0, 0x2a8, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_HIGH0
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_HIGH0, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_STATUS0 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_STATUS0: XTAL Timestamp Control STATUS0
 *     AddressOffset  : 0x2ac
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS0, 0x2ac, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_STATUS0
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS0, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_STATUS0
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS0, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_CTRL1 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_CTRL1: XTAL Timestamp Control1
 *     AddressOffset  : 0x2b0
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, 0x2b0, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL1
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL1
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW,
		(uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL1
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL1
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL1, BUSY, 1, 1);

/* ********* MISC ISH_XTAL_TIMESTAMP_LOW1 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_LOW1: XTAL Timestamp Capture LOWregister1
 *     AddressOffset  : 0x2b4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_LOW1, 0x2b4, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_LOW1
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_LOW1, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_HIGH1 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_HIGH1: XTAL Timestamp Control HIGH1
 *     AddressOffset  : 0x2b8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_HIGH1, 0x2b8, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_HIGH1
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_HIGH1, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_STATUS1 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_STATUS1: XTAL Timestamp Control STATUS1
 *     AddressOffset  : 0x2bc
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS1, 0x2bc, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_STATUS1
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS1, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_STATUS1
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS1, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_CTRL2 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_CTRL2: XTAL Timestamp Control2
 *     AddressOffset  : 0x2c0
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, 0x2c0, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL2
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL2
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW,
		(uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL2
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL2
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL2, BUSY, 1, 1);

/* ********* MISC ISH_XTAL_TIMESTAMP_LOW2 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_LOW2: XTAL Timestamp Capture LOWregister2
 *     AddressOffset  : 0x2c4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_LOW2, 0x2c4, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_LOW2
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_LOW2, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_HIGH2 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_HIGH2: XTAL Timestamp Control HIGH2
 *     AddressOffset  : 0x2c8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_HIGH2, 0x2c8, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_HIGH2
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_HIGH2, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_STATUS2 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_STATUS2: XTAL Timestamp Control STATUS2
 *     AddressOffset  : 0x2cc
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS2, 0x2cc, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_STATUS2
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS2, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_STATUS2
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS2, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_CTRL3 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_CTRL3: XTAL Timestamp Control2
 *     AddressOffset  : 0x2d0
 *     AccessType     : RW
 *     WritableBitMask: 0x1f03
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, 0x2d0, RW, (uint32_t)0x1f03, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_EN: Timestamp Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EN, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_EDGE_DETECT_REG: Edge Detect
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1, RW,
		(uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, ISH_TIMESTAMP_EDGE_DETECT_REG, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL3
 *   RESERVED1: Reserved
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, RESERVED1, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL3
 *   ISH_TIMESTAMP_GPIO_SEL_REG: GPIO Select
 *     BitOffset : 8
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, ISH_TIMESTAMP_GPIO_SEL_REG, 8, 5, RW,
		(uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL3
 *   RESERVED0: Reserved
 *     BitOffset : 13
 *     BitWidth  : 18
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, RESERVED0, 13, 18, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_CTRL3
 *   BUSY: Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, BUSY, 31, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, BUSY, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_CTRL3, BUSY, 1, 1);

/* ********* MISC ISH_XTAL_TIMESTAMP_LOW3 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_LOW3: XTAL Timestamp Capture LOWregister3
 *     AddressOffset  : 0x2d4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_LOW3, 0x2d4, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_LOW3
 *   ISH_TIMESTAMP_LOW: Timestamp Low
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_LOW3, ISH_TIMESTAMP_LOW, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_HIGH3 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_HIGH3: XTAL Timestamp Control HIGH3
 *     AddressOffset  : 0x2d8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_HIGH3, 0x2d8, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_HIGH3
 *   ISH_TIMESTAMP_HIGH: Timestamp High
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_HIGH3, ISH_TIMESTAMP_HIGH, 0, 32, RO, (uint32_t)0x0);

/* ********* MISC ISH_XTAL_TIMESTAMP_STATUS3 ***********
 *
 * Register of SEDI MISC
 *   ISH_XTAL_TIMESTAMP_STATUS3: XTAL Timestamp Control STATUS3
 *     AddressOffset  : 0x2dc
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS3, 0x2dc, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_STATUS3
 *   ISH_TIMESTAMP_STATUS: Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 0, 0);
SEDI_RBFV_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS3, ISH_TIMESTAMP_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_XTAL_TIMESTAMP_STATUS3
 *   RESERVED0: Reserved
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, ISH_XTAL_TIMESTAMP_STATUS3, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* MISC HH_ART_TIMER0_N_VAL ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER0_N_VAL: N Value For M/N Of XTAL Timer
 *     AddressOffset  : 0x300
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x1
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER0_N_VAL, 0x300, RW, (uint32_t)0xffffffff, (uint32_t)0x1);

/*
 * Bit Field of Register HH_ART_TIMER0_N_VAL
 *   HH_ART_TIMER0_N_VAL:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER0_N_VAL, HH_ART_TIMER0_N_VAL, 0, 32, RW, (uint32_t)0x1);

/* ********* MISC HH_ART_TIMER1_N_VAL ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER1_N_VAL: N Value For M/N Of AON Timer
 *     AddressOffset  : 0x304
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x19
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER1_N_VAL, 0x304, RW, (uint32_t)0xffffffff, (uint32_t)0x19);

/*
 * Bit Field of Register HH_ART_TIMER1_N_VAL
 *   HH_ART_TIMER1_N_VAL:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x19
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER1_N_VAL, HH_ART_TIMER1_N_VAL, 0, 32, RW, (uint32_t)0x19);

/* ********* MISC HH_ART_TIMER2_N_VAL ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER2_N_VAL: N Value For M/N Of RTC Timer
 *     AddressOffset  : 0x308
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x8000
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER2_N_VAL, 0x308, RW, (uint32_t)0xffffffff, (uint32_t)0x8000);

/*
 * Bit Field of Register HH_ART_TIMER2_N_VAL
 *   HH_ART_TIMER2_N_VAL:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x8000
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER2_N_VAL, HH_ART_TIMER2_N_VAL, 0, 32, RW, (uint32_t)0x8000);

/* ********* MISC HH_ART_TIMER0_MN_QUOTIENT ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER0_MN_QUOTIENT: Quotient For M/N Of XTAL Timer
 *     AddressOffset  : 0x310
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x1
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER0_MN_QUOTIENT, 0x310, RW, (uint32_t)0xffffffff, (uint32_t)0x1);

/*
 * Bit Field of Register HH_ART_TIMER0_MN_QUOTIENT
 *   HH_ART_TIMER0_MN_QUOTIENT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER0_MN_QUOTIENT, HH_ART_TIMER0_MN_QUOTIENT, 0, 32, RW,
		(uint32_t)0x1);

/* ********* MISC HH_ART_TIMER1_MN_QUOTIENT ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER1_MN_QUOTIENT: Quotient For M/N Of AON Timer
 *     AddressOffset  : 0x314
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0xf
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER1_MN_QUOTIENT, 0x314, RW, (uint32_t)0xffffffff, (uint32_t)0xf);

/*
 * Bit Field of Register HH_ART_TIMER1_MN_QUOTIENT
 *   HH_ART_TIMER1_MN_QUOTIENT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0f
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER1_MN_QUOTIENT, HH_ART_TIMER1_MN_QUOTIENT, 0, 32, RW,
		(uint32_t)0x0f);

/* ********* MISC HH_ART_TIMER2_MN_QUOTIENT ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER2_MN_QUOTIENT: Quotient For M/N Of RTC Timer
 *     AddressOffset  : 0x318
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x493
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER2_MN_QUOTIENT, 0x318, RW, (uint32_t)0xffffffff, (uint32_t)0x493);

/*
 * Bit Field of Register HH_ART_TIMER2_MN_QUOTIENT
 *   HH_ART_TIMER2_MN_QUOTIENT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x493
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER2_MN_QUOTIENT, HH_ART_TIMER2_MN_QUOTIENT, 0, 32, RW,
		(uint32_t)0x493);

/* ********* MISC HH_ART_TIMER0_MN_REMAINDER ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER0_MN_REMAINDER: Remainder For M/N Of XTAL Timer
 *     AddressOffset  : 0x320
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER0_MN_REMAINDER, 0x320, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register HH_ART_TIMER0_MN_REMAINDER
 *   HH_ART_TIMER0_MN_REMAINDER:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER0_MN_REMAINDER, HH_ART_TIMER0_MN_REMAINDER, 0, 32, RW,
		(uint32_t)0x0);

/* ********* MISC HH_ART_TIMER1_MN_REMAINDER ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER1_MN_REMAINDER: Remainder For M/N Of AON Timer
 *     AddressOffset  : 0x324
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x9
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER1_MN_REMAINDER, 0x324, RW, (uint32_t)0xffffffff, (uint32_t)0x9);

/*
 * Bit Field of Register HH_ART_TIMER1_MN_REMAINDER
 *   HH_ART_TIMER1_MN_REMAINDER:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x9
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER1_MN_REMAINDER, HH_ART_TIMER1_MN_REMAINDER, 0, 32, RW,
		(uint32_t)0x9);

/* ********* MISC HH_ART_TIMER2_MN_REMAINDER ***********
 *
 * Register of SEDI MISC
 *   HH_ART_TIMER2_MN_REMAINDER: Remainder For M/N Of RTC Timer
 *     AddressOffset  : 0x328
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x7000
 */
SEDI_REG_DEFINE(MISC, HH_ART_TIMER2_MN_REMAINDER, 0x328, RW, (uint32_t)0xffffffff,
		(uint32_t)0x7000);

/*
 * Bit Field of Register HH_ART_TIMER2_MN_REMAINDER
 *   HH_ART_TIMER2_MN_REMAINDER:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x7000
 */
SEDI_RBF_DEFINE(MISC, HH_ART_TIMER2_MN_REMAINDER, HH_ART_TIMER2_MN_REMAINDER, 0, 32, RW,
		(uint32_t)0x7000);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* ISH Fuses 0 -31 */
	__IO_R uint32_t ish_fuse0;

	/* ISH Fuses 32 -63 */
	__IO_R uint32_t ish_fuse1;

	/* ISH Fuses 64 -95 */
	__IO_R uint32_t ish_fuse2;

	/* ISH SOFT STRAP 0 -31 */
	__IO_R uint32_t ish_soft_strap0;

	/* ISH SOFT STRAP 32 -63 */
	__IO_R uint32_t ish_soft_strap1;

	/* ISH SOFT STRAP 64 -95 */
	__IO_R uint32_t ish_soft_strap2;

	/* _RESERVED9 */
	__IO_R uint32_t reserved9;

	/* DFX VISA Milestone */
	__IO_RW uint32_t dfx_visa_milestone;

	/* ISH RTC Counter LSB Value */
	__IO_R uint32_t ish_rtc_counter0;

	/* ISH RTC Counter MSB Value */
	__IO_R uint32_t ish_rtc_counter1;

	/* Reserved */
	__IO_RW uint32_t reserved0[10];

	/* 31:0 Of 64 Bit Snapshot Value Synchronized Using Sync Pulse */
	__IO_R uint32_t ish_misc_art_snapshot_lo_addr;

	/* 63:32 Of 64 Bit Snapshot Value Synchronized Using Sync Pulse */
	__IO_R uint32_t ish_misc_art_snapshot_hi_addr;

	/* Snapshot Control And Status */
	__IO_RW uint32_t ish_misc_art_snapshot_ctrl_addr;

	/* Reserved */
	__IO_RW uint32_t reserved1[5];

	/* HH ART Timestamp Control */
	__IO_RW uint32_t hh_art_ts_ctrl;

	/* [31:0] Of HH FW Value Low */
	__IO_RW uint32_t hh_art_tb_stamp_low;

	/* [63:32] Of HH FW Value High */
	__IO_RW uint32_t hh_art_tb_stamp_high;

	/* HH Saturation Staus */
	__IO_RW uint32_t hh_saturation;

	/* [31:0[]  Of Local Art Sync Counter */
	__IO_R uint32_t hh_art_rd_ts_snapshot_low;

	/* [63:32] OfLocal Art Sync Counter */
	__IO_R uint32_t hh_art_rd_ts_snapshot_high;

	/* Reserved */
	__IO_RW uint32_t reserved2[10];

	/* Revision ID */
	__IO_R uint32_t ish_misc_revision_id;

	/* Reserved */
	__IO_RW uint32_t reserved3[63];

	/* This Is Spare ROFor ECO. */
	__IO_R uint32_t ish_misc_eco_ro;

	/* This Is Spare RWFor ECO. */
	__IO_RW uint32_t ish_misc_eco_rw;

	/* This Is Spare RW1CFor ECO */
	__IO_RW uint32_t ish_misc_eco_rw1c;

	/* This Is Spare Retention RWFor ECO. */
	__IO_RW uint32_t ish_misc_eco_ret_rw;

	/* This Is Spare Retention RW1CFor ECO. */
	__IO_RW uint32_t ish_misc_eco_ret_rw1c;

	/* Ish_cse_sai_portid_strap */
	__IO_R uint32_t ish_cse_sai_portid_strap;

	/* Ish_ese_sai_portid_strap */
	__IO_R uint32_t ish_ese_sai_portid_strap;

	/* Ish_fdfx_secure_policy */
	__IO_R uint32_t ish_fdfx_security_policy;

	/* AON Timestamp Control0 */
	__IO_RW uint32_t ish_aon_timestamp_ctrl0;

	/* AON Timestamp Capture LOWregister0 */
	__IO_R uint32_t ish_aon_timestamp_low0;

	/* AON Timestamp Control HIGH0 */
	__IO_R uint32_t ish_aon_timestamp_high0;

	/* AON Timestamp Control STATUS0 */
	__IO_RW uint32_t ish_aon_timestamp_status0;

	/* AON Timestamp Control1 */
	__IO_RW uint32_t ish_aon_timestamp_ctrl1;

	/* AON Timestamp Capture LOWregister1 */
	__IO_R uint32_t ish_aon_timestamp_low1;

	/* AON Timestamp Control HIGH1 */
	__IO_R uint32_t ish_aon_timestamp_high1;

	/* AON Timestamp Control STATUS1 */
	__IO_RW uint32_t ish_aon_timestamp_status1;

	/* AON Timestamp Control2 */
	__IO_RW uint32_t ish_aon_timestamp_ctrl2;

	/* AON Timestamp Capture LOWregister2 */
	__IO_R uint32_t ish_aon_timestamp_low2;

	/* AON Timestamp Control HIGH2 */
	__IO_R uint32_t ish_aon_timestamp_high2;

	/* AON Timestamp Control STATUS2 */
	__IO_RW uint32_t ish_aon_timestamp_status2;

	/* AON Timestamp Control3 */
	__IO_RW uint32_t ish_aon_timestamp_ctrl3;

	/* AON Timestamp Capture LOWregister3 */
	__IO_R uint32_t ish_aon_timestamp_low3;

	/* AON Timestamp Control HIGH3 */
	__IO_R uint32_t ish_aon_timestamp_high3;

	/* AON Timestamp Control STATUS3 */
	__IO_RW uint32_t ish_aon_timestamp_status3;

	/* RTC Timestamp Control0 */
	__IO_RW uint32_t ish_rtc_timestamp_ctrl0;

	/* RTC Timestamp Capture LOWregister0 */
	__IO_R uint32_t ish_rtc_timestamp_low0;

	/* RTC Timestamp Control HIGH0 */
	__IO_R uint32_t ish_rtc_timestamp_high0;

	/* RTC Timestamp Control STATUS0 */
	__IO_RW uint32_t ish_rtc_timestamp_status0;

	/* RTC Timestamp Control1 */
	__IO_RW uint32_t ish_rtc_timestamp_ctrl1;

	/* RTC Timestamp Capture LOWregister1 */
	__IO_R uint32_t ish_rtc_timestamp_low1;

	/* RTC Timestamp Control HIGH1 */
	__IO_R uint32_t ish_rtc_timestamp_high1;

	/* RTC Timestamp Control STATUS1 */
	__IO_RW uint32_t ish_rtc_timestamp_status1;

	/* RTC Timestamp Control2 */
	__IO_RW uint32_t ish_rtc_timestamp_ctrl2;

	/* RTC Timestamp Capture LOWregister2 */
	__IO_R uint32_t ish_rtc_timestamp_low2;

	/* RTC Timestamp Control HIGH2 */
	__IO_R uint32_t ish_rtc_timestamp_high2;

	/* RTC Timestamp Control STATUS2 */
	__IO_RW uint32_t ish_rtc_timestamp_status2;

	/* RTC Timestamp Control3 */
	__IO_RW uint32_t ish_rtc_timestamp_ctrl3;

	/* RTC Timestamp Capture LOWregister3 */
	__IO_R uint32_t ish_rtc_timestamp_low3;

	/* RTC Timestamp Control HIGH3 */
	__IO_R uint32_t ish_rtc_timestamp_high3;

	/* RTC Timestamp Control STATUS3 */
	__IO_RW uint32_t ish_rtc_timestamp_status3;

	/* XTAL Timestamp Control0 */
	__IO_RW uint32_t ish_xtal_timestamp_ctrl0;

	/* XTAL Timestamp Capture LOWregister0 */
	__IO_R uint32_t ish_xtal_timestamp_low0;

	/* XTAL Timestamp Control HIGH0 */
	__IO_R uint32_t ish_xtal_timestamp_high0;

	/* XTAL Timestamp Control STATUS0 */
	__IO_RW uint32_t ish_xtal_timestamp_status0;

	/* XTAL Timestamp Control1 */
	__IO_RW uint32_t ish_xtal_timestamp_ctrl1;

	/* XTAL Timestamp Capture LOWregister1 */
	__IO_R uint32_t ish_xtal_timestamp_low1;

	/* XTAL Timestamp Control HIGH1 */
	__IO_R uint32_t ish_xtal_timestamp_high1;

	/* XTAL Timestamp Control STATUS1 */
	__IO_RW uint32_t ish_xtal_timestamp_status1;

	/* XTAL Timestamp Control2 */
	__IO_RW uint32_t ish_xtal_timestamp_ctrl2;

	/* XTAL Timestamp Capture LOWregister2 */
	__IO_R uint32_t ish_xtal_timestamp_low2;

	/* XTAL Timestamp Control HIGH2 */
	__IO_R uint32_t ish_xtal_timestamp_high2;

	/* XTAL Timestamp Control STATUS2 */
	__IO_RW uint32_t ish_xtal_timestamp_status2;

	/* XTAL Timestamp Control2 */
	__IO_RW uint32_t ish_xtal_timestamp_ctrl3;

	/* XTAL Timestamp Capture LOWregister3 */
	__IO_R uint32_t ish_xtal_timestamp_low3;

	/* XTAL Timestamp Control HIGH3 */
	__IO_R uint32_t ish_xtal_timestamp_high3;

	/* XTAL Timestamp Control STATUS3 */
	__IO_RW uint32_t ish_xtal_timestamp_status3;

	/* Reserved */
	__IO_RW uint32_t reserved4[8];

	/* N Value For M/N Of XTAL Timer */
	__IO_RW uint32_t hh_art_timer0_n_val;

	/* N Value For M/N Of AON Timer */
	__IO_RW uint32_t hh_art_timer1_n_val;

	/* N Value For M/N Of RTC Timer */
	__IO_RW uint32_t hh_art_timer2_n_val;

	/* Reserved */
	__IO_RW uint32_t reserved5[1];

	/* Quotient For M/N Of XTAL Timer */
	__IO_RW uint32_t hh_art_timer0_mn_quotient;

	/* Quotient For M/N Of AON Timer */
	__IO_RW uint32_t hh_art_timer1_mn_quotient;

	/* Quotient For M/N Of RTC Timer */
	__IO_RW uint32_t hh_art_timer2_mn_quotient;

	/* Reserved */
	__IO_RW uint32_t reserved6[1];

	/* Remainder For M/N Of XTAL Timer */
	__IO_RW uint32_t hh_art_timer0_mn_remainder;

	/* Remainder For M/N Of AON Timer */
	__IO_RW uint32_t hh_art_timer1_mn_remainder;

	/* Remainder For M/N Of RTC Timer */
	__IO_RW uint32_t hh_art_timer2_mn_remainder;

} sedi_misc_regs_t;

#endif /* _SEDI_MISC_REGS_H_ */
