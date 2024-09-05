/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2023-08-31
 */

#ifndef _SEDI_I3C_REGS_H_
#define _SEDI_I3C_REGS_H_

#include <sedi_reg_defs.h>


/* ********* I3C HCI_VERSION ***********
 *
 * Register of SEDI I3C
 *   HCI_VERSION: HCI Version register
 *     AddressOffset  : 0x0
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x100
 */
SEDI_REG_DEFINE(I3C, HCI_VERSION, 0x0, RO, (uint32_t)0x0, (uint32_t)0x100);

/*
 * Bit Field of Register HCI_VERSION
 *   VERSION:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x100
 */
SEDI_RBF_DEFINE(I3C, HCI_VERSION, VERSION, 0, 32, RO, (uint32_t)0x100);

/* ********* I3C HC_CONTROL ***********
 *
 * Register of SEDI I3C
 *   HC_CONTROL: HC_CONTROL
 *     AddressOffset  : 0x4
 *     AccessType     : RW
 *     WritableBitMask: 0xe0000181
 *     ResetValue     : (uint32_t)0x1
 */
SEDI_REG_DEFINE(I3C, HC_CONTROL, 0x4, RW, (uint32_t)0xe0000181, (uint32_t)0x1);

/*
 * Bit Field of Register HC_CONTROL
 *   IBA_INCLUDE:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, HC_CONTROL, IBA_INCLUDE, 0, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, IBA_INCLUDE, INCLUDED, 0x1);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, IBA_INCLUDE, NOT_INCLUDED, 0x0);

/*
 * Bit Field of Register HC_CONTROL
 *   I2C_SLAVE_PRESENT:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, HC_CONTROL, I2C_SLAVE_PRESENT, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, I2C_SLAVE_PRESENT, NOT_PRESENT, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, I2C_SLAVE_PRESENT, PRESENT, 0x1);

/*
 * Bit Field of Register HC_CONTROL
 *   HOT_JOIN_CTRL:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, HC_CONTROL, HOT_JOIN_CTRL, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, HOT_JOIN_CTRL, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, HOT_JOIN_CTRL, ENABLED, 0x1);

/*
 * Bit Field of Register HC_CONTROL
 *   ABORT:
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, HC_CONTROL, ABORT, 29, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, ABORT, ABORTED, 0x1);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, ABORT, RUNNING, 0x0);

/*
 * Bit Field of Register HC_CONTROL
 *   RESUME:
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, HC_CONTROL, RESUME, 30, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, RESUME, RUNNING, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, RESUME, SUSPENDED, 0x1);

/*
 * Bit Field of Register HC_CONTROL
 *   BUS_ENABLE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, HC_CONTROL, BUS_ENABLE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, BUS_ENABLE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CONTROL, BUS_ENABLE, ENABLED, 0x1);

/* ********* I3C MASTER_DEVICE_ADDR ***********
 *
 * Register of SEDI I3C
 *   MASTER_DEVICE_ADDR: Master Device Address Register
 *     AddressOffset  : 0x8
 *     AccessType     : RW
 *     WritableBitMask: 0x807f0000
 *     ResetValue     : (uint32_t)0x80000000
 */
SEDI_REG_DEFINE(I3C, MASTER_DEVICE_ADDR, 0x8, RW, (uint32_t)0x807f0000, (uint32_t)0x80000000);

/*
 * Bit Field of Register MASTER_DEVICE_ADDR
 *   DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, MASTER_DEVICE_ADDR, DYNAMIC_ADDR, 16, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register MASTER_DEVICE_ADDR
 *   DYNAMIC_ADDR_VALID:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, MASTER_DEVICE_ADDR, DYNAMIC_ADDR_VALID, 31, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, MASTER_DEVICE_ADDR, DYNAMIC_ADDR_VALID, INVALID, 0x0);
SEDI_RBFV_DEFINE(I3C, MASTER_DEVICE_ADDR, DYNAMIC_ADDR_VALID, VALID, 0x1);

/* ********* I3C HC_CAPABILITIES ***********
 *
 * Register of SEDI I3C
 *   HC_CAPABILITIES: HC Capabilities Register
 *     AddressOffset  : 0xc
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0xcc
 */
SEDI_REG_DEFINE(I3C, HC_CAPABILITIES, 0xc, RO, (uint32_t)0x0, (uint32_t)0xcc);

/*
 * Bit Field of Register HC_CAPABILITIES
 *   COMBO_COMMAND:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, HC_CAPABILITIES, COMBO_COMMAND, 2, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, COMBO_COMMAND, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, COMBO_COMMAND, ENABLED, 0x1);

/*
 * Bit Field of Register HC_CAPABILITIES
 *   AUTO_COMMAND:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, HC_CAPABILITIES, AUTO_COMMAND, 3, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, AUTO_COMMAND, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, AUTO_COMMAND, ENABLED, 0x1);

/*
 * Bit Field of Register HC_CAPABILITIES
 *   NON_CURRENT_MASTER_CAP:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, HC_CAPABILITIES, NON_CURRENT_MASTER_CAP, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, NON_CURRENT_MASTER_CAP, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, NON_CURRENT_MASTER_CAP, ENABLED, 0x1);

/*
 * Bit Field of Register HC_CAPABILITIES
 *   HDR_DDR_EN:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, HC_CAPABILITIES, HDR_DDR_EN, 6, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, HDR_DDR_EN, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, HDR_DDR_EN, ENABLED, 0x1);

/*
 * Bit Field of Register HC_CAPABILITIES
 *   HDR_TS_EN:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, HC_CAPABILITIES, HDR_TS_EN, 7, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, HDR_TS_EN, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, HC_CAPABILITIES, HDR_TS_EN, ENABLED, 0x1);

/* ********* I3C RESET_CONTROL ***********
 *
 * Register of SEDI I3C
 *   RESET_CONTROL: Reset Control Register
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, RESET_CONTROL, 0x10, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register RESET_CONTROL
 *   SOFT_RST:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESET_CONTROL, SOFT_RST, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, SOFT_RST, 0, 0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, SOFT_RST, 1, 1);

/*
 * Bit Field of Register RESET_CONTROL
 *   CMD_QUEUE_RST:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESET_CONTROL, CMD_QUEUE_RST, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, CMD_QUEUE_RST, 0, 0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, CMD_QUEUE_RST, 1, 1);

/*
 * Bit Field of Register RESET_CONTROL
 *   RESP_QUEUE_RST:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESET_CONTROL, RESP_QUEUE_RST, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, RESP_QUEUE_RST, 0, 0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, RESP_QUEUE_RST, 1, 1);

/*
 * Bit Field of Register RESET_CONTROL
 *   TX_FIFO_RST:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESET_CONTROL, TX_FIFO_RST, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, TX_FIFO_RST, 0, 0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, TX_FIFO_RST, 1, 1);

/*
 * Bit Field of Register RESET_CONTROL
 *   RX_FIFO_RST:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESET_CONTROL, RX_FIFO_RST, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, RX_FIFO_RST, 0, 0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, RX_FIFO_RST, 1, 1);

/*
 * Bit Field of Register RESET_CONTROL
 *   IBI_QUEUE_RST:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESET_CONTROL, IBI_QUEUE_RST, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, IBI_QUEUE_RST, 0, 0);
SEDI_RBFV_DEFINE(I3C, RESET_CONTROL, IBI_QUEUE_RST, 1, 1);

/* ********* I3C PRESENT_STATE ***********
 *
 * Register of SEDI I3C
 *   PRESENT_STATE: Present State Register
 *     AddressOffset  : 0x14
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, PRESENT_STATE, 0x14, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register PRESENT_STATE
 *   CURRENT_MASTER:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PRESENT_STATE, CURRENT_MASTER, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE, CURRENT_MASTER, BUS_OWNER, 0x1);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE, CURRENT_MASTER, NOT_BUS_OWNER, 0x0);

/* ********* I3C INTR_STATUS ***********
 *
 * Register of SEDI I3C
 *   INTR_STATUS: Interrupt Status Register
 *     AddressOffset  : 0x20
 *     AccessType     : RW
 *     WritableBitMask: 0x400
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, INTR_STATUS, 0x20, RW, (uint32_t)0x400, (uint32_t)0x0);

/*
 * Bit Field of Register INTR_STATUS
 *   HC_INTERNAL_ERR_STAT:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, INTR_STATUS, HC_INTERNAL_ERR_STAT, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, INTR_STATUS, HC_INTERNAL_ERR_STAT, 0, 0);
SEDI_RBFV_DEFINE(I3C, INTR_STATUS, HC_INTERNAL_ERR_STAT, 1, 1);

/* ********* I3C INTR_STATUS_ENABLE ***********
 *
 * Register of SEDI I3C
 *   INTR_STATUS_ENABLE: Interrupt Status Enable Register
 *     AddressOffset  : 0x24
 *     AccessType     : RW
 *     WritableBitMask: 0x400
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, INTR_STATUS_ENABLE, 0x24, RW, (uint32_t)0x400, (uint32_t)0x0);

/*
 * Bit Field of Register INTR_STATUS_ENABLE
 *   HC_INTERNAL_ERR_STAT_EN:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, INTR_STATUS_ENABLE, HC_INTERNAL_ERR_STAT_EN, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, INTR_STATUS_ENABLE, HC_INTERNAL_ERR_STAT_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, INTR_STATUS_ENABLE, HC_INTERNAL_ERR_STAT_EN, 1, 1);

/* ********* I3C INTR_SIGNAL_ENABLE ***********
 *
 * Register of SEDI I3C
 *   INTR_SIGNAL_ENABLE: Interrupt Signal Enable Register
 *     AddressOffset  : 0x28
 *     AccessType     : RW
 *     WritableBitMask: 0x400
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, INTR_SIGNAL_ENABLE, 0x28, RW, (uint32_t)0x400, (uint32_t)0x0);

/*
 * Bit Field of Register INTR_SIGNAL_ENABLE
 *   HC_INTERNAL_ERR_SIGNAL_EN:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, INTR_SIGNAL_ENABLE, HC_INTERNAL_ERR_SIGNAL_EN, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, INTR_SIGNAL_ENABLE, HC_INTERNAL_ERR_SIGNAL_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, INTR_SIGNAL_ENABLE, HC_INTERNAL_ERR_SIGNAL_EN, 1, 1);

/* ********* I3C INTR_FORCE ***********
 *
 * Register of SEDI I3C
 *   INTR_FORCE: Interrupt Force Enable Register
 *     AddressOffset  : 0x2c
 *     AccessType     : RW
 *     WritableBitMask: 0x400
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, INTR_FORCE, 0x2c, RW, (uint32_t)0x400, (uint32_t)0x0);

/*
 * Bit Field of Register INTR_FORCE
 *   HC_INTERNAL_ERR_FORCE:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, INTR_FORCE, HC_INTERNAL_ERR_FORCE, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, INTR_FORCE, HC_INTERNAL_ERR_FORCE, 0, 0);
SEDI_RBFV_DEFINE(I3C, INTR_FORCE, HC_INTERNAL_ERR_FORCE, 1, 1);

/* ********* I3C DAT_SECTION_OFFSET ***********
 *
 * Register of SEDI I3C
 *   DAT_SECTION_OFFSET: Device Address Table Pointer
 *     AddressOffset  : 0x30
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x10080
 */
SEDI_REG_DEFINE(I3C, DAT_SECTION_OFFSET, 0x30, RO, (uint32_t)0x0, (uint32_t)0x10080);

/*
 * Bit Field of Register DAT_SECTION_OFFSET
 *   TABLE_OFFSET:
 *     BitOffset : 0
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x80
 */
SEDI_RBF_DEFINE(I3C, DAT_SECTION_OFFSET, TABLE_OFFSET, 0, 12, RO, (uint32_t)0x80);

/*
 * Bit Field of Register DAT_SECTION_OFFSET
 *   TABLE_SIZE:
 *     BitOffset : 12
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x10
 */
SEDI_RBF_DEFINE(I3C, DAT_SECTION_OFFSET, TABLE_SIZE, 12, 6, RO, (uint32_t)0x10);

/* ********* I3C DCT_SECTION_OFFSET ***********
 *
 * Register of SEDI I3C
 *   DCT_SECTION_OFFSET: Device Characteristics Table Pointer
 *     AddressOffset  : 0x34
 *     AccessType     : RW
 *     WritableBitMask: 0x380000
 *     ResetValue     : (uint32_t)0x20100
 */
SEDI_REG_DEFINE(I3C, DCT_SECTION_OFFSET, 0x34, RW, (uint32_t)0x380000, (uint32_t)0x20100);

/*
 * Bit Field of Register DCT_SECTION_OFFSET
 *   TABLE_OFFSET:
 *     BitOffset : 0
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x100
 */
SEDI_RBF_DEFINE(I3C, DCT_SECTION_OFFSET, TABLE_OFFSET, 0, 12, RO, (uint32_t)0x100);

/*
 * Bit Field of Register DCT_SECTION_OFFSET
 *   TABLE_SIZE:
 *     BitOffset : 12
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x20
 */
SEDI_RBF_DEFINE(I3C, DCT_SECTION_OFFSET, TABLE_SIZE, 12, 7, RO, (uint32_t)0x20);

/*
 * Bit Field of Register DCT_SECTION_OFFSET
 *   TABLE_INDEX:
 *     BitOffset : 19
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DCT_SECTION_OFFSET, TABLE_INDEX, 19, 3, RW, (uint32_t)0x0);

/* ********* I3C RING_HEADERS_SECTION_OFFSET ***********
 *
 * Register of SEDI I3C
 *   RING_HEADERS_SECTION_OFFSET: Ring Headers Section Offset Register
 *     AddressOffset  : 0x38
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x3c0
 */
SEDI_REG_DEFINE(I3C, RING_HEADERS_SECTION_OFFSET, 0x38, RO, (uint32_t)0x0, (uint32_t)0x3c0);

/*
 * Bit Field of Register RING_HEADERS_SECTION_OFFSET
 *   SECTION_OFFSET:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3c0
 */
SEDI_RBF_DEFINE(I3C, RING_HEADERS_SECTION_OFFSET, SECTION_OFFSET, 0, 16, RO, (uint32_t)0x3c0);

/* ********* I3C PIO_SECTION_OFFSET ***********
 *
 * Register of SEDI I3C
 *   PIO_SECTION_OFFSET: PIO Section Offset Register
 *     AddressOffset  : 0x3c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0xc0
 */
SEDI_REG_DEFINE(I3C, PIO_SECTION_OFFSET, 0x3c, RO, (uint32_t)0x0, (uint32_t)0xc0);

/*
 * Bit Field of Register PIO_SECTION_OFFSET
 *   SECTION_OFFSET:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0xc0
 */
SEDI_RBF_DEFINE(I3C, PIO_SECTION_OFFSET, SECTION_OFFSET, 0, 16, RO, (uint32_t)0xc0);

/* ********* I3C EXTCAPS_SECTION_OFFSET ***********
 *
 * Register of SEDI I3C
 *   EXTCAPS_SECTION_OFFSET: Extended Capabilities Section Offset Register
 *     AddressOffset  : 0x40
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x200
 */
SEDI_REG_DEFINE(I3C, EXTCAPS_SECTION_OFFSET, 0x40, RO, (uint32_t)0x0, (uint32_t)0x200);

/*
 * Bit Field of Register EXTCAPS_SECTION_OFFSET
 *   SECTION_OFFSET:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x200
 */
SEDI_RBF_DEFINE(I3C, EXTCAPS_SECTION_OFFSET, SECTION_OFFSET, 0, 16, RO, (uint32_t)0x200);

/* ********* I3C IBI_NOTIFY_CTRL ***********
 *
 * Register of SEDI I3C
 *   IBI_NOTIFY_CTRL: IBI Queue Control Register
 *     AddressOffset  : 0x58
 *     AccessType     : RW
 *     WritableBitMask: 0xb
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, IBI_NOTIFY_CTRL, 0x58, RW, (uint32_t)0xb, (uint32_t)0x0);

/*
 * Bit Field of Register IBI_NOTIFY_CTRL
 *   NOTIFY_HJ_REJECTED:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_HJ_REJECTED, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_HJ_REJECTED, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_HJ_REJECTED, ENABLED, 0x1);

/*
 * Bit Field of Register IBI_NOTIFY_CTRL
 *   NOTIFY_MR_REJECTED:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_MR_REJECTED, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_MR_REJECTED, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_MR_REJECTED, ENABLED, 0x1);

/*
 * Bit Field of Register IBI_NOTIFY_CTRL
 *   NOTIFY_SIR_REJECTED:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_SIR_REJECTED, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_SIR_REJECTED, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I3C, IBI_NOTIFY_CTRL, NOTIFY_SIR_REJECTED, ENABLED, 0x1);

/* ********* I3C DEV_CTX_BASE_LO ***********
 *
 * Register of SEDI I3C
 *   DEV_CTX_BASE_LO: Device Context Address Low Register
 *     AddressOffset  : 0x60
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CTX_BASE_LO, 0x60, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CTX_BASE_LO
 *   BASE_LO:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CTX_BASE_LO, BASE_LO, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CTX_BASE_HI ***********
 *
 * Register of SEDI I3C
 *   DEV_CTX_BASE_HI: Device Context Address High Register
 *     AddressOffset  : 0x64
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CTX_BASE_HI, 0x64, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CTX_BASE_HI
 *   BASE_HI:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CTX_BASE_HI, BASE_HI, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_ADDR_TABLE1_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE1_LOC1: Device Address Table Location 1 of Device1
 *     AddressOffset  : 0x80
 *     AccessType     : RW
 *     WritableBitMask: 0xfcfff07f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, 0x80, RW, (uint32_t)0xfcfff07f, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   STATIC_ADDRESS:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, STATIC_ADDRESS, 0, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   IBI_WITH_DATA:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, IBI_WITH_DATA, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, IBI_WITH_DATA, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, IBI_WITH_DATA, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   SIR_REJECT:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, SIR_REJECT, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, SIR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, SIR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   MR_REJECT:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, MR_REJECT, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, MR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, MR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   TS:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, TS, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, TS, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, TS, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, DEV_DYNAMIC_ADDR, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   RING_ID:
 *     BitOffset : 26
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, RING_ID, 26, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   DEV_NACK_RETRY_CNT:
 *     BitOffset : 29
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, DEV_NACK_RETRY_CNT, 29, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC1
 *   DEVICE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, DEVICE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, DEVICE, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE1_LOC1, DEVICE, 1, 1);

/* ********* I3C DEV_ADDR_TABLE1_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE1_LOC2: Device Address Table Location 2 of Device1
 *     AddressOffset  : 0x84
 *     AccessType     : RW
 *     WritableBitMask: 0x7ffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE1_LOC2, 0x84, RW, (uint32_t)0x7ffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC2
 *   AUTOCMD_MASK:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC2, AUTOCMD_MASK, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC2
 *   AUTOCMD_VALUE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC2, AUTOCMD_VALUE, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC2
 *   AUTOCMD_MODE:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC2, AUTOCMD_MODE, 16, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE1_LOC2
 *   AUTOCMD_HDR_CODE:
 *     BitOffset : 19
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE1_LOC2, AUTOCMD_HDR_CODE, 19, 8, RW, (uint32_t)0x0);

/* ********* I3C DEV_ADDR_TABLE2_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE2_LOC1: Device Address Table Location 1 of Device2
 *     AddressOffset  : 0x88
 *     AccessType     : RW
 *     WritableBitMask: 0xfcfff07f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, 0x88, RW, (uint32_t)0xfcfff07f, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   STATIC_ADDRESS:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, STATIC_ADDRESS, 0, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   IBI_WITH_DATA:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, IBI_WITH_DATA, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, IBI_WITH_DATA, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, IBI_WITH_DATA, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   SIR_REJECT:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, SIR_REJECT, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, SIR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, SIR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   MR_REJECT:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, MR_REJECT, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, MR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, MR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   TS:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, TS, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, TS, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, TS, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, DEV_DYNAMIC_ADDR, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   RING_ID:
 *     BitOffset : 26
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, RING_ID, 26, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   DEV_NACK_RETRY_CNT:
 *     BitOffset : 29
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, DEV_NACK_RETRY_CNT, 29, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC1
 *   DEVICE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, DEVICE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, DEVICE, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE2_LOC1, DEVICE, 1, 1);

/* ********* I3C DEV_ADDR_TABLE2_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE2_LOC2: Device Address Table Location 2 of Device2
 *     AddressOffset  : 0x8c
 *     AccessType     : RW
 *     WritableBitMask: 0x7ffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE2_LOC2, 0x8c, RW, (uint32_t)0x7ffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC2
 *   AUTOCMD_MASK:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC2, AUTOCMD_MASK, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC2
 *   AUTOCMD_VALUE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC2, AUTOCMD_VALUE, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC2
 *   AUTOCMD_MODE:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC2, AUTOCMD_MODE, 16, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE2_LOC2
 *   AUTOCMD_HDR_CODE:
 *     BitOffset : 19
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE2_LOC2, AUTOCMD_HDR_CODE, 19, 8, RW, (uint32_t)0x0);

/* ********* I3C DEV_ADDR_TABLE3_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE3_LOC1: Device Address Table Location 1 of Device3
 *     AddressOffset  : 0x90
 *     AccessType     : RW
 *     WritableBitMask: 0xfcfff07f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, 0x90, RW, (uint32_t)0xfcfff07f, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   STATIC_ADDRESS:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, STATIC_ADDRESS, 0, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   IBI_WITH_DATA:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, IBI_WITH_DATA, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, IBI_WITH_DATA, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, IBI_WITH_DATA, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   SIR_REJECT:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, SIR_REJECT, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, SIR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, SIR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   MR_REJECT:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, MR_REJECT, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, MR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, MR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   TS:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, TS, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, TS, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, TS, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, DEV_DYNAMIC_ADDR, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   RING_ID:
 *     BitOffset : 26
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, RING_ID, 26, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   DEV_NACK_RETRY_CNT:
 *     BitOffset : 29
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, DEV_NACK_RETRY_CNT, 29, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC1
 *   DEVICE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, DEVICE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, DEVICE, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE3_LOC1, DEVICE, 1, 1);

/* ********* I3C DEV_ADDR_TABLE3_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE3_LOC2: Device Address Table Location 2 of Device3
 *     AddressOffset  : 0x94
 *     AccessType     : RW
 *     WritableBitMask: 0x7ffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE3_LOC2, 0x94, RW, (uint32_t)0x7ffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC2
 *   AUTOCMD_MASK:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC2, AUTOCMD_MASK, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC2
 *   AUTOCMD_VALUE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC2, AUTOCMD_VALUE, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC2
 *   AUTOCMD_MODE:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC2, AUTOCMD_MODE, 16, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE3_LOC2
 *   AUTOCMD_HDR_CODE:
 *     BitOffset : 19
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE3_LOC2, AUTOCMD_HDR_CODE, 19, 8, RW, (uint32_t)0x0);

/* ********* I3C DEV_ADDR_TABLE4_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE4_LOC1: Device Address Table Location 1 of Device4
 *     AddressOffset  : 0x98
 *     AccessType     : RW
 *     WritableBitMask: 0xfcfff07f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, 0x98, RW, (uint32_t)0xfcfff07f, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   STATIC_ADDRESS:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, STATIC_ADDRESS, 0, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   IBI_WITH_DATA:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, IBI_WITH_DATA, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, IBI_WITH_DATA, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, IBI_WITH_DATA, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   SIR_REJECT:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, SIR_REJECT, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, SIR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, SIR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   MR_REJECT:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, MR_REJECT, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, MR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, MR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   TS:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, TS, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, TS, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, TS, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, DEV_DYNAMIC_ADDR, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   RING_ID:
 *     BitOffset : 26
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, RING_ID, 26, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   DEV_NACK_RETRY_CNT:
 *     BitOffset : 29
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, DEV_NACK_RETRY_CNT, 29, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC1
 *   DEVICE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, DEVICE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, DEVICE, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE4_LOC1, DEVICE, 1, 1);

/* ********* I3C DEV_ADDR_TABLE4_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE4_LOC2: Device Address Table Location 2 of Device4
 *     AddressOffset  : 0x9c
 *     AccessType     : RW
 *     WritableBitMask: 0x7ffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE4_LOC2, 0x9c, RW, (uint32_t)0x7ffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC2
 *   AUTOCMD_MASK:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC2, AUTOCMD_MASK, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC2
 *   AUTOCMD_VALUE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC2, AUTOCMD_VALUE, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC2
 *   AUTOCMD_MODE:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC2, AUTOCMD_MODE, 16, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE4_LOC2
 *   AUTOCMD_HDR_CODE:
 *     BitOffset : 19
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE4_LOC2, AUTOCMD_HDR_CODE, 19, 8, RW, (uint32_t)0x0);

/* ********* I3C DEV_ADDR_TABLE5_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE5_LOC1: Device Address Table Location 1 of Device5
 *     AddressOffset  : 0xa0
 *     AccessType     : RW
 *     WritableBitMask: 0xfcfff07f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, 0xa0, RW, (uint32_t)0xfcfff07f, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   STATIC_ADDRESS:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, STATIC_ADDRESS, 0, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   IBI_WITH_DATA:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, IBI_WITH_DATA, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, IBI_WITH_DATA, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, IBI_WITH_DATA, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   SIR_REJECT:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, SIR_REJECT, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, SIR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, SIR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   MR_REJECT:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, MR_REJECT, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, MR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, MR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   TS:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, TS, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, TS, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, TS, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, DEV_DYNAMIC_ADDR, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   RING_ID:
 *     BitOffset : 26
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, RING_ID, 26, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   DEV_NACK_RETRY_CNT:
 *     BitOffset : 29
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, DEV_NACK_RETRY_CNT, 29, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC1
 *   DEVICE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, DEVICE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, DEVICE, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE5_LOC1, DEVICE, 1, 1);

/* ********* I3C DEV_ADDR_TABLE5_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE5_LOC2: Device Address Table Location 2 of Device5
 *     AddressOffset  : 0xa4
 *     AccessType     : RW
 *     WritableBitMask: 0x7ffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE5_LOC2, 0xa4, RW, (uint32_t)0x7ffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC2
 *   AUTOCMD_MASK:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC2, AUTOCMD_MASK, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC2
 *   AUTOCMD_VALUE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC2, AUTOCMD_VALUE, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC2
 *   AUTOCMD_MODE:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC2, AUTOCMD_MODE, 16, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE5_LOC2
 *   AUTOCMD_HDR_CODE:
 *     BitOffset : 19
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE5_LOC2, AUTOCMD_HDR_CODE, 19, 8, RW, (uint32_t)0x0);

/* ********* I3C DEV_ADDR_TABLE6_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE6_LOC1: Device Address Table Location 1 of Device6
 *     AddressOffset  : 0xa8
 *     AccessType     : RW
 *     WritableBitMask: 0xfcfff07f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, 0xa8, RW, (uint32_t)0xfcfff07f, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   STATIC_ADDRESS:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, STATIC_ADDRESS, 0, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   IBI_WITH_DATA:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, IBI_WITH_DATA, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, IBI_WITH_DATA, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, IBI_WITH_DATA, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   SIR_REJECT:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, SIR_REJECT, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, SIR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, SIR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   MR_REJECT:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, MR_REJECT, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, MR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, MR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   TS:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, TS, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, TS, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, TS, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, DEV_DYNAMIC_ADDR, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   RING_ID:
 *     BitOffset : 26
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, RING_ID, 26, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   DEV_NACK_RETRY_CNT:
 *     BitOffset : 29
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, DEV_NACK_RETRY_CNT, 29, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC1
 *   DEVICE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, DEVICE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, DEVICE, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE6_LOC1, DEVICE, 1, 1);

/* ********* I3C DEV_ADDR_TABLE6_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE6_LOC2: Device Address Table Location 2 of Device6
 *     AddressOffset  : 0xac
 *     AccessType     : RW
 *     WritableBitMask: 0x7ffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE6_LOC2, 0xac, RW, (uint32_t)0x7ffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC2
 *   AUTOCMD_MASK:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC2, AUTOCMD_MASK, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC2
 *   AUTOCMD_VALUE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC2, AUTOCMD_VALUE, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC2
 *   AUTOCMD_MODE:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC2, AUTOCMD_MODE, 16, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE6_LOC2
 *   AUTOCMD_HDR_CODE:
 *     BitOffset : 19
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE6_LOC2, AUTOCMD_HDR_CODE, 19, 8, RW, (uint32_t)0x0);

/* ********* I3C DEV_ADDR_TABLE7_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE7_LOC1: Device Address Table Location 1 of Device7
 *     AddressOffset  : 0xb0
 *     AccessType     : RW
 *     WritableBitMask: 0xfcfff07f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, 0xb0, RW, (uint32_t)0xfcfff07f, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   STATIC_ADDRESS:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, STATIC_ADDRESS, 0, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   IBI_WITH_DATA:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, IBI_WITH_DATA, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, IBI_WITH_DATA, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, IBI_WITH_DATA, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   SIR_REJECT:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, SIR_REJECT, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, SIR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, SIR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   MR_REJECT:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, MR_REJECT, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, MR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, MR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   TS:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, TS, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, TS, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, TS, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, DEV_DYNAMIC_ADDR, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   RING_ID:
 *     BitOffset : 26
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, RING_ID, 26, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   DEV_NACK_RETRY_CNT:
 *     BitOffset : 29
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, DEV_NACK_RETRY_CNT, 29, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC1
 *   DEVICE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, DEVICE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, DEVICE, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE7_LOC1, DEVICE, 1, 1);

/* ********* I3C DEV_ADDR_TABLE7_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE7_LOC2: Device Address Table Location 2 of Device7
 *     AddressOffset  : 0xb4
 *     AccessType     : RW
 *     WritableBitMask: 0x7ffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE7_LOC2, 0xb4, RW, (uint32_t)0x7ffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC2
 *   AUTOCMD_MASK:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC2, AUTOCMD_MASK, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC2
 *   AUTOCMD_VALUE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC2, AUTOCMD_VALUE, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC2
 *   AUTOCMD_MODE:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC2, AUTOCMD_MODE, 16, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE7_LOC2
 *   AUTOCMD_HDR_CODE:
 *     BitOffset : 19
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE7_LOC2, AUTOCMD_HDR_CODE, 19, 8, RW, (uint32_t)0x0);

/* ********* I3C DEV_ADDR_TABLE8_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE8_LOC1: Device Address Table Location 1 of Device8
 *     AddressOffset  : 0xb8
 *     AccessType     : RW
 *     WritableBitMask: 0xfcfff07f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, 0xb8, RW, (uint32_t)0xfcfff07f, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   STATIC_ADDRESS:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, STATIC_ADDRESS, 0, 7, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   IBI_WITH_DATA:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, IBI_WITH_DATA, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, IBI_WITH_DATA, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, IBI_WITH_DATA, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   SIR_REJECT:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, SIR_REJECT, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, SIR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, SIR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   MR_REJECT:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, MR_REJECT, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, MR_REJECT, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, MR_REJECT, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   TS:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, TS, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, TS, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, TS, 1, 1);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, DEV_DYNAMIC_ADDR, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   RING_ID:
 *     BitOffset : 26
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, RING_ID, 26, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   DEV_NACK_RETRY_CNT:
 *     BitOffset : 29
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, DEV_NACK_RETRY_CNT, 29, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC1
 *   DEVICE:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, DEVICE, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, DEVICE, 0, 0);
SEDI_RBFV_DEFINE(I3C, DEV_ADDR_TABLE8_LOC1, DEVICE, 1, 1);

/* ********* I3C DEV_ADDR_TABLE8_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_ADDR_TABLE8_LOC2: Device Address Table Location 2 of Device8
 *     AddressOffset  : 0xbc
 *     AccessType     : RW
 *     WritableBitMask: 0x7ffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_ADDR_TABLE8_LOC2, 0xbc, RW, (uint32_t)0x7ffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC2
 *   AUTOCMD_MASK:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC2, AUTOCMD_MASK, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC2
 *   AUTOCMD_VALUE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC2, AUTOCMD_VALUE, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC2
 *   AUTOCMD_MODE:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC2, AUTOCMD_MODE, 16, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_ADDR_TABLE8_LOC2
 *   AUTOCMD_HDR_CODE:
 *     BitOffset : 19
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_ADDR_TABLE8_LOC2, AUTOCMD_HDR_CODE, 19, 8, RW, (uint32_t)0x0);

/* ********* I3C COMMAND_QUEUE_PORT ***********
 *
 * Register of SEDI I3C
 *   COMMAND_QUEUE_PORT: COMMAND_QUEUE_PORT
 *     AddressOffset  : 0xc0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, COMMAND_QUEUE_PORT, 0xc0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register COMMAND_QUEUE_PORT
 *   COMMAND:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, COMMAND_QUEUE_PORT, COMMAND, 0, 32, RW, (uint32_t)0x0);

/* ********* I3C RESPONSE_QUEUE_PORT ***********
 *
 * Register of SEDI I3C
 *   RESPONSE_QUEUE_PORT: Response Queue Port Register
 *     AddressOffset  : 0xc4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, RESPONSE_QUEUE_PORT, 0xc4, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RESPONSE_QUEUE_PORT
 *   DATA_LENGTH:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESPONSE_QUEUE_PORT, DATA_LENGTH, 0, 16, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RESPONSE_QUEUE_PORT
 *   TID:
 *     BitOffset : 24
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESPONSE_QUEUE_PORT, TID, 24, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RESPONSE_QUEUE_PORT
 *   ERR_STATUS:
 *     BitOffset : 28
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, RESPONSE_QUEUE_PORT, ERR_STATUS, 28, 4, RO, (uint32_t)0x0);

/* ********* I3C TX_DATA_PORT ***********
 *
 * Register of SEDI I3C
 *   TX_DATA_PORT: Transmit Data Port Register
 *     AddressOffset  : 0xc8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, TX_DATA_PORT, 0xc8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register TX_DATA_PORT
 *
 *     BitOffset :
 *     BitWidth  :
 *     AccessType:
 *     ResetValue:
 */

/* ********* I3C IBI_PORT ***********
 *
 * Register of SEDI I3C
 *   IBI_PORT: IBI Port Register
 *     AddressOffset  : 0xcc
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, IBI_PORT, 0xcc, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register IBI_PORT
 *   IBI_DATA:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, IBI_PORT, IBI_DATA, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C QUEUE_THLD_CTRL ***********
 *
 * Register of SEDI I3C
 *   QUEUE_THLD_CTRL: Queue Threshold Control Register
 *     AddressOffset  : 0xd0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x200002
 */
SEDI_REG_DEFINE(I3C, QUEUE_THLD_CTRL, 0xd0, RW, (uint32_t)0xffffffff, (uint32_t)0x200002);

/*
 * Bit Field of Register QUEUE_THLD_CTRL
 *   CMD_EMPTY_BUF_THLD:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(I3C, QUEUE_THLD_CTRL, CMD_EMPTY_BUF_THLD, 0, 8, RW, (uint32_t)0x2);

/*
 * Bit Field of Register QUEUE_THLD_CTRL
 *   RESP_BUF_THLD:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, QUEUE_THLD_CTRL, RESP_BUF_THLD, 8, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register QUEUE_THLD_CTRL
 *   IBI_DATA_THLD:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x20
 */
SEDI_RBF_DEFINE(I3C, QUEUE_THLD_CTRL, IBI_DATA_THLD, 16, 8, RW, (uint32_t)0x20);

/*
 * Bit Field of Register QUEUE_THLD_CTRL
 *   IBI_STATUS_THLD:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, QUEUE_THLD_CTRL, IBI_STATUS_THLD, 24, 8, RW, (uint32_t)0x0);

/* ********* I3C DATA_BUFFER_THLD_CTRL ***********
 *
 * Register of SEDI I3C
 *   DATA_BUFFER_THLD_CTRL: Data Buffer Threshold Control Register
 *     AddressOffset  : 0xd4
 *     AccessType     : RW
 *     WritableBitMask: 0x7070707
 *     ResetValue     : (uint32_t)0x1010404
 */
SEDI_REG_DEFINE(I3C, DATA_BUFFER_THLD_CTRL, 0xd4, RW, (uint32_t)0x7070707, (uint32_t)0x1010404);

/*
 * Bit Field of Register DATA_BUFFER_THLD_CTRL
 *   TX_BUF_THLD:
 *     BitOffset : 0
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x4
 */
SEDI_RBF_DEFINE(I3C, DATA_BUFFER_THLD_CTRL, TX_BUF_THLD, 0, 3, RW, (uint32_t)0x4);

/*
 * Bit Field of Register DATA_BUFFER_THLD_CTRL
 *   RX_BUF_THLD:
 *     BitOffset : 8
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x4
 */
SEDI_RBF_DEFINE(I3C, DATA_BUFFER_THLD_CTRL, RX_BUF_THLD, 8, 3, RW, (uint32_t)0x4);

/*
 * Bit Field of Register DATA_BUFFER_THLD_CTRL
 *   TX_START_THLD:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, DATA_BUFFER_THLD_CTRL, TX_START_THLD, 16, 3, RW, (uint32_t)0x1);

/*
 * Bit Field of Register DATA_BUFFER_THLD_CTRL
 *   RX_START_THLD:
 *     BitOffset : 24
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, DATA_BUFFER_THLD_CTRL, RX_START_THLD, 24, 3, RW, (uint32_t)0x1);

/* ********* I3C QUEUE_SIZE_CTRL ***********
 *
 * Register of SEDI I3C
 *   QUEUE_SIZE_CTRL: Queue Size Register
 *     AddressOffset  : 0xd8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x5051010
 */
SEDI_REG_DEFINE(I3C, QUEUE_SIZE_CTRL, 0xd8, RO, (uint32_t)0x0, (uint32_t)0x5051010);

/*
 * Bit Field of Register QUEUE_SIZE_CTRL
 *   CR_QUEUE_SIZE:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x10
 */
SEDI_RBF_DEFINE(I3C, QUEUE_SIZE_CTRL, CR_QUEUE_SIZE, 0, 8, RO, (uint32_t)0x10);

/*
 * Bit Field of Register QUEUE_SIZE_CTRL
 *   IBI_STATUS_SIZE:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x10
 */
SEDI_RBF_DEFINE(I3C, QUEUE_SIZE_CTRL, IBI_STATUS_SIZE, 8, 8, RO, (uint32_t)0x10);

/*
 * Bit Field of Register QUEUE_SIZE_CTRL
 *   RX_DATA_BUFFER_SIZE:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x5
 */
SEDI_RBF_DEFINE(I3C, QUEUE_SIZE_CTRL, RX_DATA_BUFFER_SIZE, 16, 8, RO, (uint32_t)0x5);

/*
 * Bit Field of Register QUEUE_SIZE_CTRL
 *   TX_DATA_BUFFER_SIZE:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x5
 */
SEDI_RBF_DEFINE(I3C, QUEUE_SIZE_CTRL, TX_DATA_BUFFER_SIZE, 24, 8, RO, (uint32_t)0x5);

/* ********* I3C PIO_INTR_STATUS ***********
 *
 * Register of SEDI I3C
 *   PIO_INTR_STATUS: PIO Interrupt Status Register
 *     AddressOffset  : 0xe0
 *     AccessType     : RW
 *     WritableBitMask: 0x220
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, PIO_INTR_STATUS, 0xe0, RW, (uint32_t)0x220, (uint32_t)0x0);

/*
 * Bit Field of Register PIO_INTR_STATUS
 *   TX_THLD_STAT:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS, TX_THLD_STAT, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, TX_THLD_STAT, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, TX_THLD_STAT, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS
 *   RX_THLD_STAT:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS, RX_THLD_STAT, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, RX_THLD_STAT, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, RX_THLD_STAT, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS
 *   IBI_STATUS_THLD_STAT:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS, IBI_STATUS_THLD_STAT, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, IBI_STATUS_THLD_STAT, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, IBI_STATUS_THLD_STAT, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS
 *   CMD_QUEUE_READY_STAT:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS, CMD_QUEUE_READY_STAT, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, CMD_QUEUE_READY_STAT, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, CMD_QUEUE_READY_STAT, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS
 *   RESP_READY_STAT:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS, RESP_READY_STAT, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, RESP_READY_STAT, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, RESP_READY_STAT, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS
 *   TRANSFER_ABORT_STAT:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS, TRANSFER_ABORT_STAT, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, TRANSFER_ABORT_STAT, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, TRANSFER_ABORT_STAT, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS
 *   TRANSFER_ERR_STAT:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS, TRANSFER_ERR_STAT, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, TRANSFER_ERR_STAT, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS, TRANSFER_ERR_STAT, 1, 1);

/* ********* I3C PIO_INTR_STATUS_ENABLE ***********
 *
 * Register of SEDI I3C
 *   PIO_INTR_STATUS_ENABLE: PIO Interrupt Status Enable Register
 *     AddressOffset  : 0xe4
 *     AccessType     : RW
 *     WritableBitMask: 0x23f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, 0xe4, RW, (uint32_t)0x23f, (uint32_t)0x0);

/*
 * Bit Field of Register PIO_INTR_STATUS_ENABLE
 *   TX_THLD_STAT_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TX_THLD_STAT_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TX_THLD_STAT_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TX_THLD_STAT_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS_ENABLE
 *   RX_THLD_STAT_EN:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, RX_THLD_STAT_EN, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, RX_THLD_STAT_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, RX_THLD_STAT_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS_ENABLE
 *   IBI_THLD_STAT_EN:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, IBI_THLD_STAT_EN, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, IBI_THLD_STAT_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, IBI_THLD_STAT_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS_ENABLE
 *   CMD_QUEUE_READY_STAT_EN:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, CMD_QUEUE_READY_STAT_EN, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, CMD_QUEUE_READY_STAT_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, CMD_QUEUE_READY_STAT_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS_ENABLE
 *   RESP_READY_STAT_INTR_EN:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, RESP_READY_STAT_INTR_EN, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, RESP_READY_STAT_INTR_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, RESP_READY_STAT_INTR_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS_ENABLE
 *   TRANSFER_ABORT_STAT_EN:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TRANSFER_ABORT_STAT_EN, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TRANSFER_ABORT_STAT_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TRANSFER_ABORT_STAT_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_STATUS_ENABLE
 *   TRANSFER_ERR_STAT_EN:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TRANSFER_ERR_STAT_EN, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TRANSFER_ERR_STAT_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_STATUS_ENABLE, TRANSFER_ERR_STAT_EN, 1, 1);

/* ********* I3C PIO_INTR_SIGNAL_ENABLE ***********
 *
 * Register of SEDI I3C
 *   PIO_INTR_SIGNAL_ENABLE: PIO Interrupt Signal Enable Register
 *     AddressOffset  : 0xe8
 *     AccessType     : RW
 *     WritableBitMask: 0x23f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, 0xe8, RW, (uint32_t)0x23f, (uint32_t)0x0);

/*
 * Bit Field of Register PIO_INTR_SIGNAL_ENABLE
 *   TX_THLD_SIGNAL_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TX_THLD_SIGNAL_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TX_THLD_SIGNAL_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TX_THLD_SIGNAL_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_SIGNAL_ENABLE
 *   RX_THLD_SIGNAL_EN:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, RX_THLD_SIGNAL_EN, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, RX_THLD_SIGNAL_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, RX_THLD_SIGNAL_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_SIGNAL_ENABLE
 *   IBI_THLD_SIGNAL_EN:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, IBI_THLD_SIGNAL_EN, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, IBI_THLD_SIGNAL_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, IBI_THLD_SIGNAL_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_SIGNAL_ENABLE
 *   CMD_QUEUE_READY_SIGNAL_EN:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, CMD_QUEUE_READY_SIGNAL_EN, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, CMD_QUEUE_READY_SIGNAL_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, CMD_QUEUE_READY_SIGNAL_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_SIGNAL_ENABLE
 *   RESP_READY_SIGNAL_EN:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, RESP_READY_SIGNAL_EN, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, RESP_READY_SIGNAL_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, RESP_READY_SIGNAL_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_SIGNAL_ENABLE
 *   TRANSFER_ABORT_SIGNAL_EN:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TRANSFER_ABORT_SIGNAL_EN, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TRANSFER_ABORT_SIGNAL_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TRANSFER_ABORT_SIGNAL_EN, 1, 1);

/*
 * Bit Field of Register PIO_INTR_SIGNAL_ENABLE
 *   TRANSFER_ERR_SIGNAL_EN:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TRANSFER_ERR_SIGNAL_EN, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TRANSFER_ERR_SIGNAL_EN, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_SIGNAL_ENABLE, TRANSFER_ERR_SIGNAL_EN, 1, 1);

/* ********* I3C PIO_INTR_FORCE ***********
 *
 * Register of SEDI I3C
 *   PIO_INTR_FORCE: PIO Interrupt Force Register
 *     AddressOffset  : 0xec
 *     AccessType     : RW
 *     WritableBitMask: 0x23f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, PIO_INTR_FORCE, 0xec, RW, (uint32_t)0x23f, (uint32_t)0x0);

/*
 * Bit Field of Register PIO_INTR_FORCE
 *   TX_THLD_FORCE:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_FORCE, TX_THLD_FORCE, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, TX_THLD_FORCE, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, TX_THLD_FORCE, 1, 1);

/*
 * Bit Field of Register PIO_INTR_FORCE
 *   RX_THLD_FORCE:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_FORCE, RX_THLD_FORCE, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, RX_THLD_FORCE, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, RX_THLD_FORCE, 1, 1);

/*
 * Bit Field of Register PIO_INTR_FORCE
 *   IBI_THLD_FORCE:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_FORCE, IBI_THLD_FORCE, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, IBI_THLD_FORCE, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, IBI_THLD_FORCE, 1, 1);

/*
 * Bit Field of Register PIO_INTR_FORCE
 *   CMD_QUEUE_READY_FORCE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_FORCE, CMD_QUEUE_READY_FORCE, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, CMD_QUEUE_READY_FORCE, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, CMD_QUEUE_READY_FORCE, 1, 1);

/*
 * Bit Field of Register PIO_INTR_FORCE
 *   RESP_READY_FORCE:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_FORCE, RESP_READY_FORCE, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, RESP_READY_FORCE, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, RESP_READY_FORCE, 1, 1);

/*
 * Bit Field of Register PIO_INTR_FORCE
 *   TRANSFER_ABORT_FORCE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_FORCE, TRANSFER_ABORT_FORCE, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, TRANSFER_ABORT_FORCE, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, TRANSFER_ABORT_FORCE, 1, 1);

/*
 * Bit Field of Register PIO_INTR_FORCE
 *   TRANSFER_ERR_FORCE:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PIO_INTR_FORCE, TRANSFER_ERR_FORCE, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, TRANSFER_ERR_FORCE, 0, 0);
SEDI_RBFV_DEFINE(I3C, PIO_INTR_FORCE, TRANSFER_ERR_FORCE, 1, 1);

/* ********* I3C DEV_CHAR_TABLE1_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE1_LOC1: DEV_CHAR_TABLE1_LOC1
 *     AddressOffset  : 0x100
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE1_LOC1, 0x100, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE1_LOC1
 *   MSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE1_LOC1, MSB_PROVISIONAL_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE1_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE1_LOC2: DEV_CHAR_TABLE1_LOC2
 *     AddressOffset  : 0x104
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE1_LOC2, 0x104, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE1_LOC2
 *   LSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE1_LOC2, LSB_PROVISIONAL_ID, 0, 16, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE1_LOC3 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE1_LOC3: DEV_CHAR_TABLE1_LOC3
 *     AddressOffset  : 0x108
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE1_LOC3, 0x108, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE1_LOC3
 *   DCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE1_LOC3, DCR, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE1_LOC3
 *   BCR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE1_LOC3, BCR, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE1_LOC4 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE1_LOC4: DEV_CHAR_TABLE1_LOC4
 *     AddressOffset  : 0x10c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE1_LOC4, 0x10c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE1_LOC4
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE1_LOC4, DEV_DYNAMIC_ADDR, 0, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE2_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE2_LOC1: DEV_CHAR_TABLE2_LOC1
 *     AddressOffset  : 0x110
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE2_LOC1, 0x110, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE2_LOC1
 *   MSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE2_LOC1, MSB_PROVISIONAL_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE2_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE2_LOC2: DEV_CHAR_TABLE2_LOC2
 *     AddressOffset  : 0x114
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE2_LOC2, 0x114, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE2_LOC2
 *   LSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE2_LOC2, LSB_PROVISIONAL_ID, 0, 16, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE2_LOC3 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE2_LOC3: DEV_CHAR_TABLE2_LOC3
 *     AddressOffset  : 0x118
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE2_LOC3, 0x118, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE2_LOC3
 *   DCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE2_LOC3, DCR, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE2_LOC3
 *   BCR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE2_LOC3, BCR, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE2_LOC4 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE2_LOC4: DEV_CHAR_TABLE2_LOC4
 *     AddressOffset  : 0x11c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE2_LOC4, 0x11c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE2_LOC4
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE2_LOC4, DEV_DYNAMIC_ADDR, 0, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE3_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE3_LOC1: DEV_CHAR_TABLE3_LOC1
 *     AddressOffset  : 0x120
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE3_LOC1, 0x120, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE3_LOC1
 *   MSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE3_LOC1, MSB_PROVISIONAL_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE3_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE3_LOC2: DEV_CHAR_TABLE3_LOC2
 *     AddressOffset  : 0x124
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE3_LOC2, 0x124, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE3_LOC2
 *   LSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE3_LOC2, LSB_PROVISIONAL_ID, 0, 16, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE3_LOC3 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE3_LOC3: DEV_CHAR_TABLE3_LOC3
 *     AddressOffset  : 0x128
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE3_LOC3, 0x128, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE3_LOC3
 *   DCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE3_LOC3, DCR, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE3_LOC3
 *   BCR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE3_LOC3, BCR, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE3_LOC4 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE3_LOC4: DEV_CHAR_TABLE3_LOC4
 *     AddressOffset  : 0x12c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE3_LOC4, 0x12c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE3_LOC4
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE3_LOC4, DEV_DYNAMIC_ADDR, 0, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE4_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE4_LOC1: DEV_CHAR_TABLE4_LOC1
 *     AddressOffset  : 0x130
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE4_LOC1, 0x130, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE4_LOC1
 *   MSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE4_LOC1, MSB_PROVISIONAL_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE4_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE4_LOC2: DEV_CHAR_TABLE4_LOC2
 *     AddressOffset  : 0x134
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE4_LOC2, 0x134, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE4_LOC2
 *   LSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE4_LOC2, LSB_PROVISIONAL_ID, 0, 16, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE4_LOC3 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE4_LOC3: DEV_CHAR_TABLE4_LOC3
 *     AddressOffset  : 0x138
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE4_LOC3, 0x138, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE4_LOC3
 *   DCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE4_LOC3, DCR, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE4_LOC3
 *   BCR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE4_LOC3, BCR, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE4_LOC4 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE4_LOC4: DEV_CHAR_TABLE4_LOC4
 *     AddressOffset  : 0x13c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE4_LOC4, 0x13c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE4_LOC4
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE4_LOC4, DEV_DYNAMIC_ADDR, 0, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE5_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE5_LOC1: DEV_CHAR_TABLE5_LOC1
 *     AddressOffset  : 0x140
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE5_LOC1, 0x140, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE5_LOC1
 *   MSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE5_LOC1, MSB_PROVISIONAL_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE5_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE5_LOC2: DEV_CHAR_TABLE5_LOC2
 *     AddressOffset  : 0x144
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE5_LOC2, 0x144, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE5_LOC2
 *   LSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE5_LOC2, LSB_PROVISIONAL_ID, 0, 16, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE5_LOC3 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE5_LOC3: DEV_CHAR_TABLE5_LOC3
 *     AddressOffset  : 0x148
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE5_LOC3, 0x148, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE5_LOC3
 *   DCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE5_LOC3, DCR, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE5_LOC3
 *   BCR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE5_LOC3, BCR, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE5_LOC4 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE5_LOC4: DEV_CHAR_TABLE5_LOC4
 *     AddressOffset  : 0x14c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE5_LOC4, 0x14c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE5_LOC4
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE5_LOC4, DEV_DYNAMIC_ADDR, 0, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE6_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE6_LOC1: DEV_CHAR_TABLE6_LOC1
 *     AddressOffset  : 0x150
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE6_LOC1, 0x150, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE6_LOC1
 *   MSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE6_LOC1, MSB_PROVISIONAL_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE6_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE6_LOC2: DEV_CHAR_TABLE6_LOC2
 *     AddressOffset  : 0x154
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE6_LOC2, 0x154, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE6_LOC2
 *   LSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE6_LOC2, LSB_PROVISIONAL_ID, 0, 16, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE6_LOC3 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE6_LOC3: DEV_CHAR_TABLE6_LOC3
 *     AddressOffset  : 0x158
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE6_LOC3, 0x158, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE6_LOC3
 *   DCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE6_LOC3, DCR, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE6_LOC3
 *   BCR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE6_LOC3, BCR, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE6_LOC4 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE6_LOC4: DEV_CHAR_TABLE6_LOC4
 *     AddressOffset  : 0x15c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE6_LOC4, 0x15c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE6_LOC4
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE6_LOC4, DEV_DYNAMIC_ADDR, 0, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE7_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE7_LOC1: DEV_CHAR_TABLE7_LOC1
 *     AddressOffset  : 0x160
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE7_LOC1, 0x160, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE7_LOC1
 *   MSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE7_LOC1, MSB_PROVISIONAL_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE7_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE7_LOC2: DEV_CHAR_TABLE7_LOC2
 *     AddressOffset  : 0x164
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE7_LOC2, 0x164, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE7_LOC2
 *   LSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE7_LOC2, LSB_PROVISIONAL_ID, 0, 16, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE7_LOC3 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE7_LOC3: DEV_CHAR_TABLE7_LOC3
 *     AddressOffset  : 0x168
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE7_LOC3, 0x168, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE7_LOC3
 *   DCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE7_LOC3, DCR, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE7_LOC3
 *   BCR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE7_LOC3, BCR, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE7_LOC4 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE7_LOC4: DEV_CHAR_TABLE7_LOC4
 *     AddressOffset  : 0x16c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE7_LOC4, 0x16c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE7_LOC4
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE7_LOC4, DEV_DYNAMIC_ADDR, 0, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE8_LOC1 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE8_LOC1: DEV_CHAR_TABLE8_LOC1
 *     AddressOffset  : 0x170
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE8_LOC1, 0x170, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE8_LOC1
 *   MSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE8_LOC1, MSB_PROVISIONAL_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE8_LOC2 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE8_LOC2: DEV_CHAR_TABLE8_LOC2
 *     AddressOffset  : 0x174
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE8_LOC2, 0x174, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE8_LOC2
 *   LSB_PROVISIONAL_ID:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE8_LOC2, LSB_PROVISIONAL_ID, 0, 16, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE8_LOC3 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE8_LOC3: DEV_CHAR_TABLE8_LOC3
 *     AddressOffset  : 0x178
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE8_LOC3, 0x178, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE8_LOC3
 *   DCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE8_LOC3, DCR, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE8_LOC3
 *   BCR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE8_LOC3, BCR, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C DEV_CHAR_TABLE8_LOC4 ***********
 *
 * Register of SEDI I3C
 *   DEV_CHAR_TABLE8_LOC4: DEV_CHAR_TABLE8_LOC4
 *     AddressOffset  : 0x17c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, DEV_CHAR_TABLE8_LOC4, 0x17c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register DEV_CHAR_TABLE8_LOC4
 *   DEV_DYNAMIC_ADDR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DEV_CHAR_TABLE8_LOC4, DEV_DYNAMIC_ADDR, 0, 8, RO, (uint32_t)0x0);

/* ********* I3C HW_IDENTIFICATION_HEADER ***********
 *
 * Register of SEDI I3C
 *   HW_IDENTIFICATION_HEADER: Hardware Identification header Register
 *     AddressOffset  : 0x200
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x401
 */
SEDI_REG_DEFINE(I3C, HW_IDENTIFICATION_HEADER, 0x200, RO, (uint32_t)0x0, (uint32_t)0x401);

/*
 * Bit Field of Register HW_IDENTIFICATION_HEADER
 *   CAP_ID:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, HW_IDENTIFICATION_HEADER, CAP_ID, 0, 8, RO, (uint32_t)0x1);

/*
 * Bit Field of Register HW_IDENTIFICATION_HEADER
 *   CAP_LEN:
 *     BitOffset : 8
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x4
 */
SEDI_RBF_DEFINE(I3C, HW_IDENTIFICATION_HEADER, CAP_LEN, 8, 16, RO, (uint32_t)0x4);

/* ********* I3C COMP_MANUFACTURER ***********
 *
 * Register of SEDI I3C
 *   COMP_MANUFACTURER: DWC_mipi_i3c MIPI Manufacturer ID Register
 *     AddressOffset  : 0x204
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, COMP_MANUFACTURER, 0x204, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register COMP_MANUFACTURER
 *   MIPI_VENDOR_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, COMP_MANUFACTURER, MIPI_VENDOR_ID, 0, 32, RO, (uint32_t)0x0);

/* ********* I3C COMP_VERSION ***********
 *
 * Register of SEDI I3C
 *   COMP_VERSION: DWC_mipi_i3c Version ID Register
 *     AddressOffset  : 0x208
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x3130302a
 */
SEDI_REG_DEFINE(I3C, COMP_VERSION, 0x208, RO, (uint32_t)0x0, (uint32_t)0x3130302a);

/*
 * Bit Field of Register COMP_VERSION
 *   I3C_VER_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3130302a
 */
SEDI_RBF_DEFINE(I3C, COMP_VERSION, I3C_VER_ID, 0, 32, RO, (uint32_t)0x3130302a);

/* ********* I3C COMP_TYPE ***********
 *
 * Register of SEDI I3C
 *   COMP_TYPE: DWC_mipi_i3c Version Type Register
 *     AddressOffset  : 0x20c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x6c633033
 */
SEDI_REG_DEFINE(I3C, COMP_TYPE, 0x20c, RO, (uint32_t)0x0, (uint32_t)0x6c633033);

/*
 * Bit Field of Register COMP_TYPE
 *   I3C_VER_TYPE:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x6c633033
 */
SEDI_RBF_DEFINE(I3C, COMP_TYPE, I3C_VER_TYPE, 0, 32, RO, (uint32_t)0x6c633033);

/* ********* I3C BUS_TIMING_HEADER ***********
 *
 * Register of SEDI I3C
 *   BUS_TIMING_HEADER: Bus Timing Header Register
 *     AddressOffset  : 0x210
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0xcc0
 */
SEDI_REG_DEFINE(I3C, BUS_TIMING_HEADER, 0x210, RO, (uint32_t)0x0, (uint32_t)0xcc0);

/*
 * Bit Field of Register BUS_TIMING_HEADER
 *   CAP_ID:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0xc0
 */
SEDI_RBF_DEFINE(I3C, BUS_TIMING_HEADER, CAP_ID, 0, 8, RO, (uint32_t)0xc0);

/*
 * Bit Field of Register BUS_TIMING_HEADER
 *   CAP_LEN:
 *     BitOffset : 8
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0xc
 */
SEDI_RBF_DEFINE(I3C, BUS_TIMING_HEADER, CAP_LEN, 8, 16, RO, (uint32_t)0xc);

/* ********* I3C SCL_I3C_OD_TIMING ***********
 *
 * Register of SEDI I3C
 *   SCL_I3C_OD_TIMING: SCL I3C Open Drain Timing Register
 *     AddressOffset  : 0x214
 *     AccessType     : RW
 *     WritableBitMask: 0xff00ff
 *     ResetValue     : (uint32_t)0x4001a
 */
SEDI_REG_DEFINE(I3C, SCL_I3C_OD_TIMING, 0x214, RW, (uint32_t)0xff00ff, (uint32_t)0x4001a);

/*
 * Bit Field of Register SCL_I3C_OD_TIMING
 *   I3C_OD_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1a
 */
SEDI_RBF_DEFINE(I3C, SCL_I3C_OD_TIMING, I3C_OD_LCNT, 0, 8, RW, (uint32_t)0x1a);

/*
 * Bit Field of Register SCL_I3C_OD_TIMING
 *   I3C_OD_HCNT:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x4
 */
SEDI_RBF_DEFINE(I3C, SCL_I3C_OD_TIMING, I3C_OD_HCNT, 16, 8, RW, (uint32_t)0x4);

/* ********* I3C SCL_I3C_PP_TIMING ***********
 *
 * Register of SEDI I3C
 *   SCL_I3C_PP_TIMING: SCL I3C Push Pull Timing Register
 *     AddressOffset  : 0x218
 *     AccessType     : RW
 *     WritableBitMask: 0xff00ff
 *     ResetValue     : (uint32_t)0x50005
 */
SEDI_REG_DEFINE(I3C, SCL_I3C_PP_TIMING, 0x218, RW, (uint32_t)0xff00ff, (uint32_t)0x50005);

/*
 * Bit Field of Register SCL_I3C_PP_TIMING
 *   I3C_PP_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x5
 */
SEDI_RBF_DEFINE(I3C, SCL_I3C_PP_TIMING, I3C_PP_LCNT, 0, 8, RW, (uint32_t)0x5);

/*
 * Bit Field of Register SCL_I3C_PP_TIMING
 *   I3C_PP_HCNT:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x5
 */
SEDI_RBF_DEFINE(I3C, SCL_I3C_PP_TIMING, I3C_PP_HCNT, 16, 8, RW, (uint32_t)0x5);

/* ********* I3C SCL_I2C_FM_TIMING ***********
 *
 * Register of SEDI I3C
 *   SCL_I2C_FM_TIMING: SCL I2C Fast Mode Timing Register
 *     AddressOffset  : 0x21c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffff
 *     ResetValue     : (uint32_t)0x5a00a0
 */
SEDI_REG_DEFINE(I3C, SCL_I2C_FM_TIMING, 0x21c, RW, (uint32_t)0xffffff, (uint32_t)0x5a00a0);

/*
 * Bit Field of Register SCL_I2C_FM_TIMING
 *   I2C_FM_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0xa0
 */
SEDI_RBF_DEFINE(I3C, SCL_I2C_FM_TIMING, I2C_FM_LCNT, 0, 16, RW, (uint32_t)0xa0);

/*
 * Bit Field of Register SCL_I2C_FM_TIMING
 *   I2C_FM_HCNT:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x5a
 */
SEDI_RBF_DEFINE(I3C, SCL_I2C_FM_TIMING, I2C_FM_HCNT, 16, 8, RW, (uint32_t)0x5a);

/* ********* I3C SCL_I2C_FMP_TIMING ***********
 *
 * Register of SEDI I3C
 *   SCL_I2C_FMP_TIMING: SCL I2C Fast Mode Plus Timing Register
 *     AddressOffset  : 0x220
 *     AccessType     : RW
 *     WritableBitMask: 0xff00ff
 *     ResetValue     : (uint32_t)0x26003e
 */
SEDI_REG_DEFINE(I3C, SCL_I2C_FMP_TIMING, 0x220, RW, (uint32_t)0xff00ff, (uint32_t)0x26003e);

/*
 * Bit Field of Register SCL_I2C_FMP_TIMING
 *   I2C_FMP_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x3e
 */
SEDI_RBF_DEFINE(I3C, SCL_I2C_FMP_TIMING, I2C_FMP_LCNT, 0, 8, RW, (uint32_t)0x3e);

/*
 * Bit Field of Register SCL_I2C_FMP_TIMING
 *   I2C_FMP_HCNT:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x26
 */
SEDI_RBF_DEFINE(I3C, SCL_I2C_FMP_TIMING, I2C_FMP_HCNT, 16, 8, RW, (uint32_t)0x26);

/* ********* I3C SCL_I2C_SS_TIMING ***********
 *
 * Register of SEDI I3C
 *   SCL_I2C_SS_TIMING: SCL I2C Standard Speed Timing Register
 *     AddressOffset  : 0x224
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x32003ac
 */
SEDI_REG_DEFINE(I3C, SCL_I2C_SS_TIMING, 0x224, RW, (uint32_t)0xffffffff, (uint32_t)0x32003ac);

/*
 * Bit Field of Register SCL_I2C_SS_TIMING
 *   I2C_SS_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x3ac
 */
SEDI_RBF_DEFINE(I3C, SCL_I2C_SS_TIMING, I2C_SS_LCNT, 0, 16, RW, (uint32_t)0x3ac);

/*
 * Bit Field of Register SCL_I2C_SS_TIMING
 *   I2C_SS_HCNT:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x320
 */
SEDI_RBF_DEFINE(I3C, SCL_I2C_SS_TIMING, I2C_SS_HCNT, 16, 16, RW, (uint32_t)0x320);

/* ********* I3C SCL_EXT_LCNT_TIMING ***********
 *
 * Register of SEDI I3C
 *   SCL_EXT_LCNT_TIMING: SCL Extended Low Count Timing Register
 *     AddressOffset  : 0x228
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x20202020
 */
SEDI_REG_DEFINE(I3C, SCL_EXT_LCNT_TIMING, 0x228, RW, (uint32_t)0xffffffff, (uint32_t)0x20202020);

/*
 * Bit Field of Register SCL_EXT_LCNT_TIMING
 *   I3C_EXT_LCNT_1:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x20
 */
SEDI_RBF_DEFINE(I3C, SCL_EXT_LCNT_TIMING, I3C_EXT_LCNT_1, 0, 8, RW, (uint32_t)0x20);

/*
 * Bit Field of Register SCL_EXT_LCNT_TIMING
 *   I3C_EXT_LCNT_2:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x20
 */
SEDI_RBF_DEFINE(I3C, SCL_EXT_LCNT_TIMING, I3C_EXT_LCNT_2, 8, 8, RW, (uint32_t)0x20);

/*
 * Bit Field of Register SCL_EXT_LCNT_TIMING
 *   I3C_EXT_LCNT_3:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x20
 */
SEDI_RBF_DEFINE(I3C, SCL_EXT_LCNT_TIMING, I3C_EXT_LCNT_3, 16, 8, RW, (uint32_t)0x20);

/*
 * Bit Field of Register SCL_EXT_LCNT_TIMING
 *   I3C_EXT_LCNT_4:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x20
 */
SEDI_RBF_DEFINE(I3C, SCL_EXT_LCNT_TIMING, I3C_EXT_LCNT_4, 24, 8, RW, (uint32_t)0x20);

/* ********* I3C SCL_EXT_TERMN_LCNT_TIMING ***********
 *
 * Register of SEDI I3C
 *   SCL_EXT_TERMN_LCNT_TIMING: SCL Termination Bit Low count Timing Register
 *     AddressOffset  : 0x22c
 *     AccessType     : RW
 *     WritableBitMask: 0xf000f
 *     ResetValue     : (uint32_t)0x30000
 */
SEDI_REG_DEFINE(I3C, SCL_EXT_TERMN_LCNT_TIMING, 0x22c, RW, (uint32_t)0xf000f, (uint32_t)0x30000);

/*
 * Bit Field of Register SCL_EXT_TERMN_LCNT_TIMING
 *   I3C_EXT_TERMN_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, SCL_EXT_TERMN_LCNT_TIMING, I3C_EXT_TERMN_LCNT, 0, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register SCL_EXT_TERMN_LCNT_TIMING
 *   I3C_TS_SKEW_CNT:
 *     BitOffset : 16
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x3
 */
SEDI_RBF_DEFINE(I3C, SCL_EXT_TERMN_LCNT_TIMING, I3C_TS_SKEW_CNT, 16, 4, RW, (uint32_t)0x3);

/* ********* I3C SDA_HOLD_SWITCH_DLY_TIMING ***********
 *
 * Register of SEDI I3C
 *   SDA_HOLD_SWITCH_DLY_TIMING: SDA Hold and Mode Switch Delay Timing Register
 *     AddressOffset  : 0x230
 *     AccessType     : RW
 *     WritableBitMask: 0x70707
 *     ResetValue     : (uint32_t)0x10000
 */
SEDI_REG_DEFINE(I3C, SDA_HOLD_SWITCH_DLY_TIMING, 0x230, RW, (uint32_t)0x70707, (uint32_t)0x10000);

/*
 * Bit Field of Register SDA_HOLD_SWITCH_DLY_TIMING
 *   SDA_OD_PP_SWITCH_DLY:
 *     BitOffset : 0
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, SDA_HOLD_SWITCH_DLY_TIMING, SDA_OD_PP_SWITCH_DLY, 0, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register SDA_HOLD_SWITCH_DLY_TIMING
 *   SDA_PP_OD_SWITCH_DLY:
 *     BitOffset : 8
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, SDA_HOLD_SWITCH_DLY_TIMING, SDA_PP_OD_SWITCH_DLY, 8, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register SDA_HOLD_SWITCH_DLY_TIMING
 *   SDA_TX_HOLD:
 *     BitOffset : 16
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, SDA_HOLD_SWITCH_DLY_TIMING, SDA_TX_HOLD, 16, 3, RW, (uint32_t)0x1);

/* ********* I3C BUS_FREE_TIMING ***********
 *
 * Register of SEDI I3C
 *   BUS_FREE_TIMING: Bus Free Timing Register
 *     AddressOffset  : 0x234
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x20
 */
SEDI_REG_DEFINE(I3C, BUS_FREE_TIMING, 0x234, RW, (uint32_t)0xffff, (uint32_t)0x20);

/*
 * Bit Field of Register BUS_FREE_TIMING
 *   I3C_MST_FREE:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x20
 */
SEDI_RBF_DEFINE(I3C, BUS_FREE_TIMING, I3C_MST_FREE, 0, 16, RW, (uint32_t)0x20);

/* ********* I3C DS_EXTCAP_HEADER ***********
 *
 * Register of SEDI I3C
 *   DS_EXTCAP_HEADER: Debug specific header Register
 *     AddressOffset  : 0x240
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x50c
 */
SEDI_REG_DEFINE(I3C, DS_EXTCAP_HEADER, 0x240, RO, (uint32_t)0x0, (uint32_t)0x50c);

/*
 * Bit Field of Register DS_EXTCAP_HEADER
 *   CAP_ID:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0xc
 */
SEDI_RBF_DEFINE(I3C, DS_EXTCAP_HEADER, CAP_ID, 0, 8, RO, (uint32_t)0xc);

/*
 * Bit Field of Register DS_EXTCAP_HEADER
 *   CAP_LEN:
 *     BitOffset : 8
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x5
 */
SEDI_RBF_DEFINE(I3C, DS_EXTCAP_HEADER, CAP_LEN, 8, 16, RO, (uint32_t)0x5);

/* ********* I3C QUEUE_STATUS_LEVEL ***********
 *
 * Register of SEDI I3C
 *   QUEUE_STATUS_LEVEL: Queue Status Level Register
 *     AddressOffset  : 0x244
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x10
 */
SEDI_REG_DEFINE(I3C, QUEUE_STATUS_LEVEL, 0x244, RO, (uint32_t)0x0, (uint32_t)0x10);

/*
 * Bit Field of Register QUEUE_STATUS_LEVEL
 *   CMD_QUEUE_FREE_LVL:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x10
 */
SEDI_RBF_DEFINE(I3C, QUEUE_STATUS_LEVEL, CMD_QUEUE_FREE_LVL, 0, 8, RO, (uint32_t)0x10);

/*
 * Bit Field of Register QUEUE_STATUS_LEVEL
 *   RESP_BUF_BLR:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, QUEUE_STATUS_LEVEL, RESP_BUF_BLR, 8, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register QUEUE_STATUS_LEVEL
 *   IBI_BUF_BLR:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, QUEUE_STATUS_LEVEL, IBI_BUF_BLR, 16, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register QUEUE_STATUS_LEVEL
 *   IBI_STATUS_CNT:
 *     BitOffset : 24
 *     BitWidth  : 5
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, QUEUE_STATUS_LEVEL, IBI_STATUS_CNT, 24, 5, RO, (uint32_t)0x0);

/* ********* I3C DATA_BUFFER_STATUS_LEVEL ***********
 *
 * Register of SEDI I3C
 *   DATA_BUFFER_STATUS_LEVEL: Data Buffer Status Level Register
 *     AddressOffset  : 0x248
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x40
 */
SEDI_REG_DEFINE(I3C, DATA_BUFFER_STATUS_LEVEL, 0x248, RO, (uint32_t)0x0, (uint32_t)0x40);

/*
 * Bit Field of Register DATA_BUFFER_STATUS_LEVEL
 *   TX_BUF_FREE_LVL:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x40
 */
SEDI_RBF_DEFINE(I3C, DATA_BUFFER_STATUS_LEVEL, TX_BUF_FREE_LVL, 0, 8, RO, (uint32_t)0x40);

/*
 * Bit Field of Register DATA_BUFFER_STATUS_LEVEL
 *   RX_BUF_LVL:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, DATA_BUFFER_STATUS_LEVEL, RX_BUF_LVL, 8, 8, RO, (uint32_t)0x0);

/* ********* I3C PRESENT_STATE_DEBUG ***********
 *
 * Register of SEDI I3C
 *   PRESENT_STATE_DEBUG: Present State Register
 *     AddressOffset  : 0x24c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x10000003
 */
SEDI_REG_DEFINE(I3C, PRESENT_STATE_DEBUG, 0x24c, RO, (uint32_t)0x0, (uint32_t)0x10000003);

/*
 * Bit Field of Register PRESENT_STATE_DEBUG
 *   SCL_LINE_SIGNAL_LEVEL:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, PRESENT_STATE_DEBUG, SCL_LINE_SIGNAL_LEVEL, 0, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, SCL_LINE_SIGNAL_LEVEL, 0, 0);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, SCL_LINE_SIGNAL_LEVEL, 1, 1);

/*
 * Bit Field of Register PRESENT_STATE_DEBUG
 *   SDA_LINE_SIGNAL_LEVEL:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, PRESENT_STATE_DEBUG, SDA_LINE_SIGNAL_LEVEL, 1, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, SDA_LINE_SIGNAL_LEVEL, 0, 0);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, SDA_LINE_SIGNAL_LEVEL, 1, 1);

/*
 * Bit Field of Register PRESENT_STATE_DEBUG
 *   CM_TFR_STATUS:
 *     BitOffset : 8
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, 8, 6, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, BCAST_WRITE, 0x1);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, ENTDAA, 0x4);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, HALTED, 0xf);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, HDR_DDR_READ, 0xd);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, HDR_DDR_WRITE, 0xc);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, HDR_TS_READ, 0xb);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, HDR_TS_WRITE, 0xa);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, I2C_SDR_READ, 0x9);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, I2C_SDR_WRITE, 0x8);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, I3C_SDR_READ, 0x7);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, I3C_SDR_WRITE, 0x6);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, IBI, 0xe);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, IDLE, 0x0);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, SETDASA, 0x5);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, SLAVE_READ, 0x3);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_STATUS, SLAVE_WRITE, 0x2);

/*
 * Bit Field of Register PRESENT_STATE_DEBUG
 *   CM_TFR_ST_STATUS:
 *     BitOffset : 16
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, 16, 6, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, BCAST_READ, 0x6);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, BCAST_WRITE, 0x5);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, CCC, 0xb);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, CLOCK_EXT, 0x12);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, DAA, 0x7);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, HALT, 0x13);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, HDR, 0xc);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, HDR_DDR_CRC, 0x11);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, IDLE, 0x0);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, RD, 0xe);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, RESTART, 0x2);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, SAG, 0x8);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, SIR_AUTO_DISABLE, 0x10);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, SIR_READ, 0xf);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, SIR_READ_DATA_STATE, 0x14);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, START, 0x1);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, START_HOLD, 0x4);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, STOP, 0x3);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, CM_TFR_ST_STATUS, WR, 0xd);

/*
 * Bit Field of Register PRESENT_STATE_DEBUG
 *   CMD_TID:
 *     BitOffset : 24
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, PRESENT_STATE_DEBUG, CMD_TID, 24, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PRESENT_STATE_DEBUG
 *   MASTER_IDLE:
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, PRESENT_STATE_DEBUG, MASTER_IDLE, 28, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, MASTER_IDLE, MST_IDLE, 0x1);
SEDI_RBFV_DEFINE(I3C, PRESENT_STATE_DEBUG, MASTER_IDLE, MST_NOT_IDLE, 0x0);

/* ********* I3C MASTER_EXT_HEADER ***********
 *
 * Register of SEDI I3C
 *   MASTER_EXT_HEADER: Master Extended specific header Register
 *     AddressOffset  : 0x254
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x1002
 */
SEDI_REG_DEFINE(I3C, MASTER_EXT_HEADER, 0x254, RO, (uint32_t)0x0, (uint32_t)0x1002);

/*
 * Bit Field of Register MASTER_EXT_HEADER
 *   CAP_ID:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(I3C, MASTER_EXT_HEADER, CAP_ID, 0, 8, RO, (uint32_t)0x2);

/*
 * Bit Field of Register MASTER_EXT_HEADER
 *   CAP_LEN:
 *     BitOffset : 8
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x10
 */
SEDI_RBF_DEFINE(I3C, MASTER_EXT_HEADER, CAP_LEN, 8, 16, RO, (uint32_t)0x10);

/* ********* I3C MASTER_CONFIG ***********
 *
 * Register of SEDI I3C
 *   MASTER_CONFIG: Master Config Register
 *     AddressOffset  : 0x258
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x39
 */
SEDI_REG_DEFINE(I3C, MASTER_CONFIG, 0x258, RO, (uint32_t)0x0, (uint32_t)0x39);

/*
 * Bit Field of Register MASTER_CONFIG
 *   APP_IF_MODE:
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I3C, MASTER_CONFIG, APP_IF_MODE, 0, 2, RO, (uint32_t)0x1);

/*
 * Bit Field of Register MASTER_CONFIG
 *   APP_IF_DATA_WIDTH:
 *     BitOffset : 2
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(I3C, MASTER_CONFIG, APP_IF_DATA_WIDTH, 2, 2, RO, (uint32_t)0x2);

/*
 * Bit Field of Register MASTER_CONFIG
 *   OPERATION_MODE:
 *     BitOffset : 4
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3
 */
SEDI_RBF_DEFINE(I3C, MASTER_CONFIG, OPERATION_MODE, 4, 2, RO, (uint32_t)0x3);

/* ********* I3C EXTCAP_END ***********
 *
 * Register of SEDI I3C
 *   EXTCAP_END: Extended capability end register
 *     AddressOffset  : 0x294
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I3C, EXTCAP_END, 0x294, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register EXTCAP_END
 *   CAP_ID:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, EXTCAP_END, CAP_ID, 0, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register EXTCAP_END
 *   CAP_LEN:
 *     BitOffset : 8
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I3C, EXTCAP_END, CAP_LEN, 8, 16, RO, (uint32_t)0x0);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* HCI Version register */
	__IO_R uint32_t hci_version;

	/* HC_CONTROL */
	__IO_RW uint32_t hc_control;

	/* Master Device Address Register */
	__IO_RW uint32_t master_device_addr;

	/* HC Capabilities Register */
	__IO_R uint32_t hc_capabilities;

	/* Reset Control Register */
	__IO_RW uint32_t reset_control;

	/* Present State Register */
	__IO_R uint32_t present_state;

	/* Reserved */
	__IO_RW uint32_t reserved0[2];

	/* Interrupt Status Register */
	__IO_RW uint32_t intr_status;

	/* Interrupt Status Enable Register */
	__IO_RW uint32_t intr_status_enable;

	/* Interrupt Signal Enable Register */
	__IO_RW uint32_t intr_signal_enable;

	/* Interrupt Force Enable Register */
	__IO_RW uint32_t intr_force;

	/* Device Address Table Pointer */
	__IO_R uint32_t dat_section_offset;

	/* Device Characteristics Table Pointer */
	__IO_RW uint32_t dct_section_offset;

	/* Ring Headers Section Offset Register */
	__IO_R uint32_t ring_headers_section_offset;

	/* PIO Section Offset Register */
	__IO_R uint32_t pio_section_offset;

	/* Extended Capabilities Section Offset Register */
	__IO_R uint32_t extcaps_section_offset;

	/* Reserved */
	__IO_RW uint32_t reserved1[5];

	/* IBI Queue Control Register */
	__IO_RW uint32_t ibi_notify_ctrl;

	/* Reserved */
	__IO_RW uint32_t reserved2[1];

	/* Device Context Address Low Register */
	__IO_R uint32_t dev_ctx_base_lo;

	/* Device Context Address High Register */
	__IO_R uint32_t dev_ctx_base_hi;

	/* Reserved */
	__IO_RW uint32_t reserved3[6];

	/* Device Address Table Location 1 of Device1 */
	__IO_RW uint32_t dev_addr_table1_loc1;

	/* Device Address Table Location 2 of Device1 */
	__IO_RW uint32_t dev_addr_table1_loc2;

	/* Device Address Table Location 1 of Device2 */
	__IO_RW uint32_t dev_addr_table2_loc1;

	/* Device Address Table Location 2 of Device2 */
	__IO_RW uint32_t dev_addr_table2_loc2;

	/* Device Address Table Location 1 of Device3 */
	__IO_RW uint32_t dev_addr_table3_loc1;

	/* Device Address Table Location 2 of Device3 */
	__IO_RW uint32_t dev_addr_table3_loc2;

	/* Device Address Table Location 1 of Device4 */
	__IO_RW uint32_t dev_addr_table4_loc1;

	/* Device Address Table Location 2 of Device4 */
	__IO_RW uint32_t dev_addr_table4_loc2;

	/* Device Address Table Location 1 of Device5 */
	__IO_RW uint32_t dev_addr_table5_loc1;

	/* Device Address Table Location 2 of Device5 */
	__IO_RW uint32_t dev_addr_table5_loc2;

	/* Device Address Table Location 1 of Device6 */
	__IO_RW uint32_t dev_addr_table6_loc1;

	/* Device Address Table Location 2 of Device6 */
	__IO_RW uint32_t dev_addr_table6_loc2;

	/* Device Address Table Location 1 of Device7 */
	__IO_RW uint32_t dev_addr_table7_loc1;

	/* Device Address Table Location 2 of Device7 */
	__IO_RW uint32_t dev_addr_table7_loc2;

	/* Device Address Table Location 1 of Device8 */
	__IO_RW uint32_t dev_addr_table8_loc1;

	/* Device Address Table Location 2 of Device8 */
	__IO_RW uint32_t dev_addr_table8_loc2;

	/* COMMAND_QUEUE_PORT */
	__IO_RW uint32_t command_queue_port;

	/* Response Queue Port Register */
	__IO_R uint32_t response_queue_port;

	/* TX Port register */
	__IO_RW uint32_t tx_data_port;

	/* IBI Port Register */
	__IO_R uint32_t ibi_port;

	/* Queue Threshold Control Register */
	__IO_RW uint32_t queue_thld_ctrl;

	/* Data Buffer Threshold Control Register */
	__IO_RW uint32_t data_buffer_thld_ctrl;

	/* Queue Size Register */
	__IO_R uint32_t queue_size_ctrl;

	/* Reserved */
	__IO_RW uint32_t reserved4[1];

	/* PIO Interrupt Status Register */
	__IO_RW uint32_t pio_intr_status;

	/* PIO Interrupt Status Enable Register */
	__IO_RW uint32_t pio_intr_status_enable;

	/* PIO Interrupt Signal Enable Register */
	__IO_RW uint32_t pio_intr_signal_enable;

	/* PIO Interrupt Force Register */
	__IO_RW uint32_t pio_intr_force;

	/* Reserved */
	__IO_RW uint32_t reserved5[4];

	/* DEV_CHAR_TABLE1_LOC1 */
	__IO_R uint32_t dev_char_table1_loc1;

	/* DEV_CHAR_TABLE1_LOC2 */
	__IO_R uint32_t dev_char_table1_loc2;

	/* DEV_CHAR_TABLE1_LOC3 */
	__IO_R uint32_t dev_char_table1_loc3;

	/* DEV_CHAR_TABLE1_LOC4 */
	__IO_R uint32_t dev_char_table1_loc4;

	/* DEV_CHAR_TABLE2_LOC1 */
	__IO_R uint32_t dev_char_table2_loc1;

	/* DEV_CHAR_TABLE2_LOC2 */
	__IO_R uint32_t dev_char_table2_loc2;

	/* DEV_CHAR_TABLE2_LOC3 */
	__IO_R uint32_t dev_char_table2_loc3;

	/* DEV_CHAR_TABLE2_LOC4 */
	__IO_R uint32_t dev_char_table2_loc4;

	/* DEV_CHAR_TABLE3_LOC1 */
	__IO_R uint32_t dev_char_table3_loc1;

	/* DEV_CHAR_TABLE3_LOC2 */
	__IO_R uint32_t dev_char_table3_loc2;

	/* DEV_CHAR_TABLE3_LOC3 */
	__IO_R uint32_t dev_char_table3_loc3;

	/* DEV_CHAR_TABLE3_LOC4 */
	__IO_R uint32_t dev_char_table3_loc4;

	/* DEV_CHAR_TABLE4_LOC1 */
	__IO_R uint32_t dev_char_table4_loc1;

	/* DEV_CHAR_TABLE4_LOC2 */
	__IO_R uint32_t dev_char_table4_loc2;

	/* DEV_CHAR_TABLE4_LOC3 */
	__IO_R uint32_t dev_char_table4_loc3;

	/* DEV_CHAR_TABLE4_LOC4 */
	__IO_R uint32_t dev_char_table4_loc4;

	/* DEV_CHAR_TABLE5_LOC1 */
	__IO_R uint32_t dev_char_table5_loc1;

	/* DEV_CHAR_TABLE5_LOC2 */
	__IO_R uint32_t dev_char_table5_loc2;

	/* DEV_CHAR_TABLE5_LOC3 */
	__IO_R uint32_t dev_char_table5_loc3;

	/* DEV_CHAR_TABLE5_LOC4 */
	__IO_R uint32_t dev_char_table5_loc4;

	/* DEV_CHAR_TABLE6_LOC1 */
	__IO_R uint32_t dev_char_table6_loc1;

	/* DEV_CHAR_TABLE6_LOC2 */
	__IO_R uint32_t dev_char_table6_loc2;

	/* DEV_CHAR_TABLE6_LOC3 */
	__IO_R uint32_t dev_char_table6_loc3;

	/* DEV_CHAR_TABLE6_LOC4 */
	__IO_R uint32_t dev_char_table6_loc4;

	/* DEV_CHAR_TABLE7_LOC1 */
	__IO_R uint32_t dev_char_table7_loc1;

	/* DEV_CHAR_TABLE7_LOC2 */
	__IO_R uint32_t dev_char_table7_loc2;

	/* DEV_CHAR_TABLE7_LOC3 */
	__IO_R uint32_t dev_char_table7_loc3;

	/* DEV_CHAR_TABLE7_LOC4 */
	__IO_R uint32_t dev_char_table7_loc4;

	/* DEV_CHAR_TABLE8_LOC1 */
	__IO_R uint32_t dev_char_table8_loc1;

	/* DEV_CHAR_TABLE8_LOC2 */
	__IO_R uint32_t dev_char_table8_loc2;

	/* DEV_CHAR_TABLE8_LOC3 */
	__IO_R uint32_t dev_char_table8_loc3;

	/* DEV_CHAR_TABLE8_LOC4 */
	__IO_R uint32_t dev_char_table8_loc4;

	/* Reserved */
	__IO_RW uint32_t reserved6[32];

	/* Hardware Identification header Register */
	__IO_R uint32_t hw_identification_header;

	/* DWC_mipi_i3c MIPI Manufacturer ID Register */
	__IO_R uint32_t comp_manufacturer;

	/* DWC_mipi_i3c Version ID Register */
	__IO_R uint32_t comp_version;

	/* DWC_mipi_i3c Version Type Register */
	__IO_R uint32_t comp_type;

	/* Bus Timing Header Register */
	__IO_R uint32_t bus_timing_header;

	/* SCL I3C Open Drain Timing Register */
	__IO_RW uint32_t scl_i3c_od_timing;

	/* SCL I3C Push Pull Timing Register */
	__IO_RW uint32_t scl_i3c_pp_timing;

	/* SCL I2C Fast Mode Timing Register */
	__IO_RW uint32_t scl_i2c_fm_timing;

	/* SCL I2C Fast Mode Plus Timing Register */
	__IO_RW uint32_t scl_i2c_fmp_timing;

	/* SCL I2C Standard Speed Timing Register */
	__IO_RW uint32_t scl_i2c_ss_timing;

	/* SCL Extended Low Count Timing Register */
	__IO_RW uint32_t scl_ext_lcnt_timing;

	/* SCL Termination Bit Low count Timing Register */
	__IO_RW uint32_t scl_ext_termn_lcnt_timing;

	/* SDA Hold and Mode Switch Delay Timing Register */
	__IO_RW uint32_t sda_hold_switch_dly_timing;

	/* Bus Free Timing Register */
	__IO_RW uint32_t bus_free_timing;

	/* Reserved */
	__IO_RW uint32_t reserved7[2];

	/* Debug specific header Register */
	__IO_R uint32_t ds_extcap_header;

	/* Queue Status Level Register */
	__IO_R uint32_t queue_status_level;

	/* Data Buffer Status Level Register */
	__IO_R uint32_t data_buffer_status_level;

	/* Present State Register */
	__IO_R uint32_t present_state_debug;

	/* Reserved */
	__IO_RW uint32_t reserved8[1];

	/* Master Extended specific header Register */
	__IO_R uint32_t master_ext_header;

	/* Master Config Register */
	__IO_R uint32_t master_config;

	/* Reserved */
	__IO_RW uint32_t reserved9[14];

	/* Extended capability end register */
	__IO_R uint32_t extcap_end;

} sedi_i3c_regs_t;


#endif /* _SEDI_I3C_REGS_H_ */
