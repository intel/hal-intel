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

#ifndef _SEDI_I2C_REGS_H_
#define _SEDI_I2C_REGS_H_

#include <sedi_reg_defs.h>


/* ********* I2C CON ***********
 *
 * Register of SEDI I2C
 *   CON: I2C Control Register
 *     AddressOffset  : 0x0
 *     AccessType     : RW
 *     WritableBitMask: 0xfef
 *     ResetValue     : (uint32_t)0x67
 */
SEDI_REG_DEFINE(I2C, CON, 0x0, RW, (uint32_t)0xfef, (uint32_t)0x67);

/*
 * Bit Field of Register CON
 *   MASTER_MODE:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, CON, MASTER_MODE, 0, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, CON, MASTER_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, CON, MASTER_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register CON
 *   SPEED:
 *     BitOffset : 1
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x3
 */
SEDI_RBF_DEFINE(I2C, CON, SPEED, 1, 2, RW, (uint32_t)0x3);
SEDI_RBFV_DEFINE(I2C, CON, SPEED, FAST, 0x2);
SEDI_RBFV_DEFINE(I2C, CON, SPEED, HIGH, 0x3);
SEDI_RBFV_DEFINE(I2C, CON, SPEED, STANDARD, 0x1);

/*
 * Bit Field of Register CON
 *   IC_10BITADDR_SLAVE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, IC_10BITADDR_SLAVE, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, IC_10BITADDR_SLAVE, ADDR_10BITS, 0x1);
SEDI_RBFV_DEFINE(I2C, CON, IC_10BITADDR_SLAVE, ADDR_7BITS, 0x0);

/*
 * Bit Field of Register CON
 *   IC_10BITADDR_MASTER_rd_only:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, IC_10BITADDR_MASTER_rd_only, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, IC_10BITADDR_MASTER_rd_only, ADDR_10BITS, 0x1);
SEDI_RBFV_DEFINE(I2C, CON, IC_10BITADDR_MASTER_rd_only, ADDR_7BITS, 0x0);

/*
 * Bit Field of Register CON
 *   IC_RESTART_EN:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, CON, IC_RESTART_EN, 5, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, CON, IC_RESTART_EN, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, CON, IC_RESTART_EN, ENABLED, 0x1);

/*
 * Bit Field of Register CON
 *   IC_SLAVE_DISABLE:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, CON, IC_SLAVE_DISABLE, 6, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, CON, IC_SLAVE_DISABLE, SLAVE_DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, CON, IC_SLAVE_DISABLE, SLAVE_ENABLED, 0x0);

/*
 * Bit Field of Register CON
 *   STOP_DET_IFADDRESSED:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, STOP_DET_IFADDRESSED, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, STOP_DET_IFADDRESSED, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, CON, STOP_DET_IFADDRESSED, ENABLED, 0x1);

/*
 * Bit Field of Register CON
 *   TX_EMPTY_CTRL:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, TX_EMPTY_CTRL, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, TX_EMPTY_CTRL, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, CON, TX_EMPTY_CTRL, ENABLED, 0x1);

/*
 * Bit Field of Register CON
 *   RX_FIFO_FULL_HLD_CTRL:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RX_FIFO_FULL_HLD_CTRL, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RX_FIFO_FULL_HLD_CTRL, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, CON, RX_FIFO_FULL_HLD_CTRL, ENABLED, 0x1);

/*
 * Bit Field of Register CON
 *   STOP_DET_IF_MASTER_ACTIVE:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, STOP_DET_IF_MASTER_ACTIVE, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, STOP_DET_IF_MASTER_ACTIVE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, CON, STOP_DET_IF_MASTER_ACTIVE, ENABLED, 0x1);

/*
 * Bit Field of Register CON
 *   BUS_CLEAR_FEATURE_CTRL:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, BUS_CLEAR_FEATURE_CTRL, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, BUS_CLEAR_FEATURE_CTRL, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, CON, BUS_CLEAR_FEATURE_CTRL, ENABLED, 0x1);

/*
 * Bit Field of Register CON
 *   RSVD_IC_CON_1:
 *     BitOffset : 12
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_IC_CON_1, 12, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register CON
 *   RSVD_OPTIONAL_SAR_CTRL:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_OPTIONAL_SAR_CTRL, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_OPTIONAL_SAR_CTRL, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_OPTIONAL_SAR_CTRL, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_SMBUS_SLAVE_QUICK_EN:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_SMBUS_SLAVE_QUICK_EN, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_SLAVE_QUICK_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_SLAVE_QUICK_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_SMBUS_ARP_EN:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_SMBUS_ARP_EN, 18, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_ARP_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_ARP_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_SMBUS_PERSISTENT_SLV_ADDR_EN:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR_EN, 19, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_SMBUS_PERSISTENT_SLV_ADDR2_EN:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR2_EN, 20, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR2_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR2_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_SMBUS_PERSISTENT_SLV_ADDR3_EN:
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR3_EN, 21, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR3_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR3_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_SMBUS_PERSISTENT_SLV_ADDR4_EN:
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR4_EN, 22, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR4_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_SMBUS_PERSISTENT_SLV_ADDR4_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_IC_SAR2_SMBUS_ARP_EN:
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_IC_SAR2_SMBUS_ARP_EN, 23, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_IC_SAR2_SMBUS_ARP_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_IC_SAR2_SMBUS_ARP_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_IC_SAR3_SMBUS_ARP_EN:
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_IC_SAR3_SMBUS_ARP_EN, 24, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_IC_SAR3_SMBUS_ARP_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_IC_SAR3_SMBUS_ARP_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_IC_SAR4_SMBUS_ARP_EN:
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_IC_SAR4_SMBUS_ARP_EN, 25, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_IC_SAR4_SMBUS_ARP_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, CON, RSVD_IC_SAR4_SMBUS_ARP_EN, 1, 1);

/*
 * Bit Field of Register CON
 *   RSVD_IC_CON_2:
 *     BitOffset : 26
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CON, RSVD_IC_CON_2, 26, 6, RO, (uint32_t)0x0);

/* ********* I2C TAR ***********
 *
 * Register of SEDI I2C
 *   TAR: I2C Target Address Register
 *     AddressOffset  : 0x4
 *     AccessType     : RW
 *     WritableBitMask: 0x1fff
 *     ResetValue     : (uint32_t)0x55
 */
SEDI_REG_DEFINE(I2C, TAR, 0x4, RW, (uint32_t)0x1fff, (uint32_t)0x55);

/*
 * Bit Field of Register TAR
 *   IC_TAR:
 *     BitOffset : 0
 *     BitWidth  : 10
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x55
 */
SEDI_RBF_DEFINE(I2C, TAR, IC_TAR, 0, 10, RW, (uint32_t)0x55);

/*
 * Bit Field of Register TAR
 *   GC_OR_START:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TAR, GC_OR_START, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TAR, GC_OR_START, GENERAL_CALL, 0x0);
SEDI_RBFV_DEFINE(I2C, TAR, GC_OR_START, START_BYTE, 0x1);

/*
 * Bit Field of Register TAR
 *   SPECIAL:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TAR, SPECIAL, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TAR, SPECIAL, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, TAR, SPECIAL, ENABLED, 0x1);

/*
 * Bit Field of Register TAR
 *   IC_10BITADDR_MASTER:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TAR, IC_10BITADDR_MASTER, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TAR, IC_10BITADDR_MASTER, ADDR_10BITS, 0x1);
SEDI_RBFV_DEFINE(I2C, TAR, IC_10BITADDR_MASTER, ADDR_7BITS, 0x0);

/*
 * Bit Field of Register TAR
 *   RSVD_DEVICE_ID:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TAR, RSVD_DEVICE_ID, 13, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TAR, RSVD_DEVICE_ID, 0, 0);
SEDI_RBFV_DEFINE(I2C, TAR, RSVD_DEVICE_ID, 1, 1);

/*
 * Bit Field of Register TAR
 *   RSVD_IC_TAR_1:
 *     BitOffset : 14
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TAR, RSVD_IC_TAR_1, 14, 2, RO, (uint32_t)0x0);

/*
 * Bit Field of Register TAR
 *   RSVD_SMBUS_QUICK_CMD:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TAR, RSVD_SMBUS_QUICK_CMD, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TAR, RSVD_SMBUS_QUICK_CMD, 0, 0);
SEDI_RBFV_DEFINE(I2C, TAR, RSVD_SMBUS_QUICK_CMD, 1, 1);

/*
 * Bit Field of Register TAR
 *   RSVD_IC_TAR_2:
 *     BitOffset : 17
 *     BitWidth  : 15
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TAR, RSVD_IC_TAR_2, 17, 15, RO, (uint32_t)0x0);

/* ********* I2C SAR ***********
 *
 * Register of SEDI I2C
 *   SAR: I2C Slave Address Register
 *     AddressOffset  : 0x8
 *     AccessType     : RW
 *     WritableBitMask: 0x3ff
 *     ResetValue     : (uint32_t)0x55
 */
SEDI_REG_DEFINE(I2C, SAR, 0x8, RW, (uint32_t)0x3ff, (uint32_t)0x55);

/*
 * Bit Field of Register SAR
 *   IC_SAR:
 *     BitOffset : 0
 *     BitWidth  : 10
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x55
 */
SEDI_RBF_DEFINE(I2C, SAR, IC_SAR, 0, 10, RW, (uint32_t)0x55);

/*
 * Bit Field of Register SAR
 *   RSVD_IC_SAR:
 *     BitOffset : 10
 *     BitWidth  : 22
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, SAR, RSVD_IC_SAR, 10, 22, RO, (uint32_t)0x0);

/* ********* I2C HS_MADDR ***********
 *
 * Register of SEDI I2C
 *   HS_MADDR: I2C High Speed Master Mode Code Address Register
 *     AddressOffset  : 0xc
 *     AccessType     : RW
 *     WritableBitMask: 0x7
 *     ResetValue     : (uint32_t)0x1
 */
SEDI_REG_DEFINE(I2C, HS_MADDR, 0xc, RW, (uint32_t)0x7, (uint32_t)0x1);

/*
 * Bit Field of Register HS_MADDR
 *   IC_HS_MAR:
 *     BitOffset : 0
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, HS_MADDR, IC_HS_MAR, 0, 3, RW, (uint32_t)0x1);

/*
 * Bit Field of Register HS_MADDR
 *   RSVD_IC_HS_MAR:
 *     BitOffset : 3
 *     BitWidth  : 29
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, HS_MADDR, RSVD_IC_HS_MAR, 3, 29, RO, (uint32_t)0x0);

/* ********* I2C DATA_CMD ***********
 *
 * Register of SEDI I2C
 *   DATA_CMD: I2C Rx/Tx Data Buffer and Command Register
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x7ff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, DATA_CMD, 0x10, RW, (uint32_t)0x7ff, (uint32_t)0x0);

/*
 * Bit Field of Register DATA_CMD
 *   DAT:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DATA_CMD, DAT, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DATA_CMD
 *   CMD:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DATA_CMD, CMD, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, DATA_CMD, CMD, READ, 0x1);
SEDI_RBFV_DEFINE(I2C, DATA_CMD, CMD, WRITE, 0x0);

/*
 * Bit Field of Register DATA_CMD
 *   STOP:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DATA_CMD, STOP, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, DATA_CMD, STOP, DISABLE, 0x0);
SEDI_RBFV_DEFINE(I2C, DATA_CMD, STOP, ENABLE, 0x1);

/*
 * Bit Field of Register DATA_CMD
 *   RESTART:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DATA_CMD, RESTART, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, DATA_CMD, RESTART, DISABLE, 0x0);
SEDI_RBFV_DEFINE(I2C, DATA_CMD, RESTART, ENABLE, 0x1);

/*
 * Bit Field of Register DATA_CMD
 *   FIRST_DATA_BYTE:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DATA_CMD, FIRST_DATA_BYTE, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, DATA_CMD, FIRST_DATA_BYTE, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, DATA_CMD, FIRST_DATA_BYTE, INACTIVE, 0x0);

/*
 * Bit Field of Register DATA_CMD
 *   RSVD_IC_DATA_CMD:
 *     BitOffset : 12
 *     BitWidth  : 20
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DATA_CMD, RSVD_IC_DATA_CMD, 12, 20, RO, (uint32_t)0x0);

/* ********* I2C SS_SCL_HCNT ***********
 *
 * Register of SEDI I2C
 *   SS_SCL_HCNT: Standard Speed I2C Clock SCL High Count Register
 *     AddressOffset  : 0x14
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x1e8
 */
SEDI_REG_DEFINE(I2C, SS_SCL_HCNT, 0x14, RW, (uint32_t)0xffff, (uint32_t)0x1e8);

/*
 * Bit Field of Register SS_SCL_HCNT
 *   IC_SS_SCL_HCNT:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1e8
 */
SEDI_RBF_DEFINE(I2C, SS_SCL_HCNT, IC_SS_SCL_HCNT, 0, 16, RW, (uint32_t)0x1e8);

/*
 * Bit Field of Register SS_SCL_HCNT
 *   RSVD_IC_SS_SCL_HIGH_COUNT:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, SS_SCL_HCNT, RSVD_IC_SS_SCL_HIGH_COUNT, 16, 16, RO, (uint32_t)0x0);

/* ********* I2C SS_SCL_LCNT ***********
 *
 * Register of SEDI I2C
 *   SS_SCL_LCNT: Standard Speed I2C Clock SCL Low Count Register
 *     AddressOffset  : 0x18
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x1f3
 */
SEDI_REG_DEFINE(I2C, SS_SCL_LCNT, 0x18, RW, (uint32_t)0xffff, (uint32_t)0x1f3);

/*
 * Bit Field of Register SS_SCL_LCNT
 *   IC_SS_SCL_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1f3
 */
SEDI_RBF_DEFINE(I2C, SS_SCL_LCNT, IC_SS_SCL_LCNT, 0, 16, RW, (uint32_t)0x1f3);

/*
 * Bit Field of Register SS_SCL_LCNT
 *   RSVD_IC_SS_SCL_LOW_COUNT:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, SS_SCL_LCNT, RSVD_IC_SS_SCL_LOW_COUNT, 16, 16, RO, (uint32_t)0x0);

/* ********* I2C FS_SCL_HCNT ***********
 *
 * Register of SEDI I2C
 *   FS_SCL_HCNT: Fast Mode or Fast Mode Plus I2C Clock SCL High Count Register
 *     AddressOffset  : 0x1c
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x71
 */
SEDI_REG_DEFINE(I2C, FS_SCL_HCNT, 0x1c, RW, (uint32_t)0xffff, (uint32_t)0x71);

/*
 * Bit Field of Register FS_SCL_HCNT
 *   IC_FS_SCL_HCNT:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x71
 */
SEDI_RBF_DEFINE(I2C, FS_SCL_HCNT, IC_FS_SCL_HCNT, 0, 16, RW, (uint32_t)0x71);

/*
 * Bit Field of Register FS_SCL_HCNT
 *   RSVD_IC_FS_SCL_HCNT:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, FS_SCL_HCNT, RSVD_IC_FS_SCL_HCNT, 16, 16, RO, (uint32_t)0x0);

/* ********* I2C FS_SCL_LCNT ***********
 *
 * Register of SEDI I2C
 *   FS_SCL_LCNT: Fast Mode or Fast Mode Plus I2C Clock SCL Low Count Register
 *     AddressOffset  : 0x20
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x7c
 */
SEDI_REG_DEFINE(I2C, FS_SCL_LCNT, 0x20, RW, (uint32_t)0xffff, (uint32_t)0x7c);

/*
 * Bit Field of Register FS_SCL_LCNT
 *   IC_FS_SCL_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x7c
 */
SEDI_RBF_DEFINE(I2C, FS_SCL_LCNT, IC_FS_SCL_LCNT, 0, 16, RW, (uint32_t)0x7c);

/*
 * Bit Field of Register FS_SCL_LCNT
 *   RSVD_IC_FS_SCL_LCNT:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, FS_SCL_LCNT, RSVD_IC_FS_SCL_LCNT, 16, 16, RO, (uint32_t)0x0);

/* ********* I2C HS_SCL_HCNT ***********
 *
 * Register of SEDI I2C
 *   HS_SCL_HCNT: High Speed I2C Clock SCL High Count Register
 *     AddressOffset  : 0x24
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x29
 */
SEDI_REG_DEFINE(I2C, HS_SCL_HCNT, 0x24, RW, (uint32_t)0xffff, (uint32_t)0x29);

/*
 * Bit Field of Register HS_SCL_HCNT
 *   IC_HS_SCL_HCNT:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x29
 */
SEDI_RBF_DEFINE(I2C, HS_SCL_HCNT, IC_HS_SCL_HCNT, 0, 16, RW, (uint32_t)0x29);

/*
 * Bit Field of Register HS_SCL_HCNT
 *   RSVD_IC_HS_SCL_HCNT:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, HS_SCL_HCNT, RSVD_IC_HS_SCL_HCNT, 16, 16, RO, (uint32_t)0x0);

/* ********* I2C HS_SCL_LCNT ***********
 *
 * Register of SEDI I2C
 *   HS_SCL_LCNT: High Speed I2C Clock SCL Low Count Register
 *     AddressOffset  : 0x28
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x32
 */
SEDI_REG_DEFINE(I2C, HS_SCL_LCNT, 0x28, RW, (uint32_t)0xffff, (uint32_t)0x32);

/*
 * Bit Field of Register HS_SCL_LCNT
 *   IC_HS_SCL_LCNT:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x32
 */
SEDI_RBF_DEFINE(I2C, HS_SCL_LCNT, IC_HS_SCL_LCNT, 0, 16, RW, (uint32_t)0x32);

/*
 * Bit Field of Register HS_SCL_LCNT
 *   RSVD_IC_HS_SCL_LOW_CNT:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, HS_SCL_LCNT, RSVD_IC_HS_SCL_LOW_CNT, 16, 16, RO, (uint32_t)0x0);

/* ********* I2C INTR_STAT ***********
 *
 * Register of SEDI I2C
 *   INTR_STAT: I2C Interrupt Status Register
 *     AddressOffset  : 0x2c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, INTR_STAT, 0x2c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_RX_UNDER:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_RX_UNDER, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RX_UNDER, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RX_UNDER, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_RX_OVER:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_RX_OVER, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RX_OVER, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RX_OVER, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_RX_FULL:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_RX_FULL, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RX_FULL, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RX_FULL, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_TX_OVER:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_TX_OVER, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_TX_OVER, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_TX_OVER, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_TX_EMPTY:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_TX_EMPTY, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_TX_EMPTY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_TX_EMPTY, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_RD_REQ:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_RD_REQ, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RD_REQ, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RD_REQ, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_TX_ABRT:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_TX_ABRT, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_TX_ABRT, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_TX_ABRT, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_RX_DONE:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_RX_DONE, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RX_DONE, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RX_DONE, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_ACTIVITY:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_ACTIVITY, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_ACTIVITY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_ACTIVITY, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_STOP_DET:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_STOP_DET, 9, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_STOP_DET, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_STOP_DET, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_START_DET:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_START_DET, 10, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_START_DET, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_START_DET, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_GEN_CALL:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_GEN_CALL, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_GEN_CALL, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_GEN_CALL, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_RESTART_DET:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_RESTART_DET, 12, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RESTART_DET, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_RESTART_DET, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_MASTER_ON_HOLD:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_MASTER_ON_HOLD, 13, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_MASTER_ON_HOLD, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_MASTER_ON_HOLD, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   R_SCL_STUCK_AT_LOW:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, R_SCL_STUCK_AT_LOW, 14, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_SCL_STUCK_AT_LOW, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, R_SCL_STUCK_AT_LOW, INACTIVE, 0x0);

/*
 * Bit Field of Register INTR_STAT
 *   RSVD_R_WR_REQ:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, RSVD_R_WR_REQ, 15, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_WR_REQ, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_WR_REQ, 1, 1);

/*
 * Bit Field of Register INTR_STAT
 *   RSVD_R_SLV_ADDR1_TAG:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR1_TAG, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR1_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR1_TAG, 1, 1);

/*
 * Bit Field of Register INTR_STAT
 *   RSVD_R_SLV_ADDR2_TAG:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR2_TAG, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR2_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR2_TAG, 1, 1);

/*
 * Bit Field of Register INTR_STAT
 *   RSVD_R_SLV_ADDR3_TAG:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR3_TAG, 18, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR3_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR3_TAG, 1, 1);

/*
 * Bit Field of Register INTR_STAT
 *   RSVD_R_SLV_ADDR4_TAG:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR4_TAG, 19, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR4_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_STAT, RSVD_R_SLV_ADDR4_TAG, 1, 1);

/*
 * Bit Field of Register INTR_STAT
 *   RSVD_IC_INTR_STAT:
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_STAT, RSVD_IC_INTR_STAT, 20, 12, RO, (uint32_t)0x0);

/* ********* I2C INTR_MASK ***********
 *
 * Register of SEDI I2C
 *   INTR_MASK: I2C Interrupt Mask Register
 *     AddressOffset  : 0x30
 *     AccessType     : RW
 *     WritableBitMask: 0x7fff
 *     ResetValue     : (uint32_t)0x48ff
 */
SEDI_REG_DEFINE(I2C, INTR_MASK, 0x30, RW, (uint32_t)0x7fff, (uint32_t)0x48ff);

/*
 * Bit Field of Register INTR_MASK
 *   M_RX_UNDER:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_RX_UNDER, 0, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RX_UNDER, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RX_UNDER, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_RX_OVER:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_RX_OVER, 1, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RX_OVER, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RX_OVER, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_RX_FULL:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_RX_FULL, 2, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RX_FULL, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RX_FULL, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_TX_OVER:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_TX_OVER, 3, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_TX_OVER, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_TX_OVER, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_TX_EMPTY:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_TX_EMPTY, 4, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_TX_EMPTY, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_TX_EMPTY, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_RD_REQ:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_RD_REQ, 5, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RD_REQ, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RD_REQ, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_TX_ABRT:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_TX_ABRT, 6, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_TX_ABRT, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_TX_ABRT, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_RX_DONE:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_RX_DONE, 7, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RX_DONE, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RX_DONE, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_ACTIVITY:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_ACTIVITY, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_ACTIVITY, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_ACTIVITY, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_STOP_DET:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_STOP_DET, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_STOP_DET, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_STOP_DET, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_START_DET:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_START_DET, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_START_DET, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_START_DET, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_GEN_CALL:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_GEN_CALL, 11, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_GEN_CALL, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_GEN_CALL, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_RESTART_DET:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_RESTART_DET, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RESTART_DET, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_RESTART_DET, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_MASTER_ON_HOLD:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_MASTER_ON_HOLD, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_MASTER_ON_HOLD, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_MASTER_ON_HOLD, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   M_SCL_STUCK_AT_LOW:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, M_SCL_STUCK_AT_LOW, 14, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_SCL_STUCK_AT_LOW, DISABLED, 0x1);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, M_SCL_STUCK_AT_LOW, ENABLED, 0x0);

/*
 * Bit Field of Register INTR_MASK
 *   RSVD_M_WR_REQ:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, RSVD_M_WR_REQ, 15, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_WR_REQ, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_WR_REQ, 1, 1);

/*
 * Bit Field of Register INTR_MASK
 *   RSVD_M_SLV_ADDR1_TAG:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR1_TAG, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR1_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR1_TAG, 1, 1);

/*
 * Bit Field of Register INTR_MASK
 *   RSVD_M_SLV_ADDR2_TAG:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR2_TAG, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR2_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR2_TAG, 1, 1);

/*
 * Bit Field of Register INTR_MASK
 *   RSVD_M_SLV_ADDR3_TAG:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR3_TAG, 18, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR3_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR3_TAG, 1, 1);

/*
 * Bit Field of Register INTR_MASK
 *   RSVD_M_SLV_ADDR4_TAG:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR4_TAG, 19, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR4_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, INTR_MASK, RSVD_M_SLV_ADDR4_TAG, 1, 1);

/*
 * Bit Field of Register INTR_MASK
 *   RSVD_IC_INTR_STAT:
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, INTR_MASK, RSVD_IC_INTR_STAT, 20, 12, RO, (uint32_t)0x0);

/* ********* I2C RAW_INTR_STAT ***********
 *
 * Register of SEDI I2C
 *   RAW_INTR_STAT: I2C Raw Interrupt Status Register
 *     AddressOffset  : 0x34
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, RAW_INTR_STAT, 0x34, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RX_UNDER:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RX_UNDER, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RX_UNDER, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RX_UNDER, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RX_OVER:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RX_OVER, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RX_OVER, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RX_OVER, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RX_FULL:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RX_FULL, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RX_FULL, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RX_FULL, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   TX_OVER:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, TX_OVER, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, TX_OVER, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, TX_OVER, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   TX_EMPTY:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, TX_EMPTY, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, TX_EMPTY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, TX_EMPTY, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RD_REQ:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RD_REQ, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RD_REQ, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RD_REQ, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   TX_ABRT:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, TX_ABRT, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, TX_ABRT, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, TX_ABRT, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RX_DONE:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RX_DONE, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RX_DONE, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RX_DONE, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   ACTIVITY:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, ACTIVITY, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, ACTIVITY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, ACTIVITY, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   STOP_DET:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, STOP_DET, 9, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, STOP_DET, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, STOP_DET, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   START_DET:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, START_DET, 10, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, START_DET, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, START_DET, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   GEN_CALL:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, GEN_CALL, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, GEN_CALL, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, GEN_CALL, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RESTART_DET:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RESTART_DET, 12, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RESTART_DET, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RESTART_DET, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   MASTER_ON_HOLD:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, MASTER_ON_HOLD, 13, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, MASTER_ON_HOLD, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, MASTER_ON_HOLD, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   SCL_STUCK_AT_LOW:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, SCL_STUCK_AT_LOW, 14, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, SCL_STUCK_AT_LOW, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, SCL_STUCK_AT_LOW, INACTIVE, 0x0);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RSVD_WR_REQ:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RSVD_WR_REQ, 15, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_WR_REQ, 0, 0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_WR_REQ, 1, 1);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RSVD_SLV_ADDR1_TAG:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR1_TAG, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR1_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR1_TAG, 1, 1);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RSVD_SLV_ADDR2_TAG:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR2_TAG, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR2_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR2_TAG, 1, 1);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RSVD_SLV_ADDR3_TAG:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR3_TAG, 18, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR3_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR3_TAG, 1, 1);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RSVD_SLV_ADDR4_TAG:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR4_TAG, 19, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR4_TAG, 0, 0);
SEDI_RBFV_DEFINE(I2C, RAW_INTR_STAT, RSVD_SLV_ADDR4_TAG, 1, 1);

/*
 * Bit Field of Register RAW_INTR_STAT
 *   RSVD_IC_RAW_INTR_STAT:
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RAW_INTR_STAT, RSVD_IC_RAW_INTR_STAT, 20, 12, RO, (uint32_t)0x0);

/* ********* I2C RX_TL ***********
 *
 * Register of SEDI I2C
 *   RX_TL: I2C Receive FIFO Threshold Register
 *     AddressOffset  : 0x38
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, RX_TL, 0x38, RW, (uint32_t)0xff, (uint32_t)0x0);

/*
 * Bit Field of Register RX_TL
 *   RX_TL:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RX_TL, RX_TL, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register RX_TL
 *   RSVD_IC_RX_TL:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RX_TL, RSVD_IC_RX_TL, 8, 24, RO, (uint32_t)0x0);

/* ********* I2C TX_TL ***********
 *
 * Register of SEDI I2C
 *   TX_TL: I2C Transmit FIFO Threshold Register
 *     AddressOffset  : 0x3c
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, TX_TL, 0x3c, RW, (uint32_t)0xff, (uint32_t)0x0);

/*
 * Bit Field of Register TX_TL
 *   TX_TL:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_TL, TX_TL, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register TX_TL
 *   RSVD_IC_TX_TL:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_TL, RSVD_IC_TX_TL, 8, 24, RO, (uint32_t)0x0);

/* ********* I2C CLR_INTR ***********
 *
 * Register of SEDI I2C
 *   CLR_INTR: Clear Combined and Individual Interrupt Register
 *     AddressOffset  : 0x40
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_INTR, 0x40, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_INTR
 *   CLR_INTR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_INTR, CLR_INTR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_INTR, CLR_INTR, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_INTR, CLR_INTR, 1, 1);

/*
 * Bit Field of Register CLR_INTR
 *   RSVD_IC_CLR_INTR:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_INTR, RSVD_IC_CLR_INTR, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_RX_UNDER ***********
 *
 * Register of SEDI I2C
 *   CLR_RX_UNDER: Clear RX_UNDER Interrupt Register
 *     AddressOffset  : 0x44
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_RX_UNDER, 0x44, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_RX_UNDER
 *   CLR_RX_UNDER:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RX_UNDER, CLR_RX_UNDER, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_RX_UNDER, CLR_RX_UNDER, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_RX_UNDER, CLR_RX_UNDER, 1, 1);

/*
 * Bit Field of Register CLR_RX_UNDER
 *   RSVD_IC_CLR_RX_UNDER:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RX_UNDER, RSVD_IC_CLR_RX_UNDER, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_RX_OVER ***********
 *
 * Register of SEDI I2C
 *   CLR_RX_OVER: Clear RX_OVER Interrupt Register
 *     AddressOffset  : 0x48
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_RX_OVER, 0x48, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_RX_OVER
 *   CLR_RX_OVER:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RX_OVER, CLR_RX_OVER, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_RX_OVER, CLR_RX_OVER, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_RX_OVER, CLR_RX_OVER, 1, 1);

/*
 * Bit Field of Register CLR_RX_OVER
 *   RSVD_IC_CLR_RX_OVER:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RX_OVER, RSVD_IC_CLR_RX_OVER, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_TX_OVER ***********
 *
 * Register of SEDI I2C
 *   CLR_TX_OVER: Clear TX_OVER Interrupt Register
 *     AddressOffset  : 0x4c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_TX_OVER, 0x4c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_TX_OVER
 *   CLR_TX_OVER:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_TX_OVER, CLR_TX_OVER, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_TX_OVER, CLR_TX_OVER, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_TX_OVER, CLR_TX_OVER, 1, 1);

/*
 * Bit Field of Register CLR_TX_OVER
 *   RSVD_IC_CLR_TX_OVER:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_TX_OVER, RSVD_IC_CLR_TX_OVER, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_RD_REQ ***********
 *
 * Register of SEDI I2C
 *   CLR_RD_REQ: Clear RD_REQ Interrupt Register
 *     AddressOffset  : 0x50
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_RD_REQ, 0x50, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_RD_REQ
 *   CLR_RD_REQ:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RD_REQ, CLR_RD_REQ, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_RD_REQ, CLR_RD_REQ, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_RD_REQ, CLR_RD_REQ, 1, 1);

/*
 * Bit Field of Register CLR_RD_REQ
 *   RSVD_IC_CLR_RD_REQ:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RD_REQ, RSVD_IC_CLR_RD_REQ, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_TX_ABRT ***********
 *
 * Register of SEDI I2C
 *   CLR_TX_ABRT: Clear TX_ABRT Interrupt Register
 *     AddressOffset  : 0x54
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_TX_ABRT, 0x54, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_TX_ABRT
 *   CLR_TX_ABRT:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_TX_ABRT, CLR_TX_ABRT, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_TX_ABRT, CLR_TX_ABRT, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_TX_ABRT, CLR_TX_ABRT, 1, 1);

/*
 * Bit Field of Register CLR_TX_ABRT
 *   RSVD_IC_CLR_TX_ABRT:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_TX_ABRT, RSVD_IC_CLR_TX_ABRT, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_RX_DONE ***********
 *
 * Register of SEDI I2C
 *   CLR_RX_DONE: Clear RX_DONE Interrupt Register
 *     AddressOffset  : 0x58
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_RX_DONE, 0x58, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_RX_DONE
 *   CLR_RX_DONE:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RX_DONE, CLR_RX_DONE, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_RX_DONE, CLR_RX_DONE, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_RX_DONE, CLR_RX_DONE, 1, 1);

/*
 * Bit Field of Register CLR_RX_DONE
 *   RSVD_IC_CLR_RX_DONE:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RX_DONE, RSVD_IC_CLR_RX_DONE, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_ACTIVITY ***********
 *
 * Register of SEDI I2C
 *   CLR_ACTIVITY: Clear ACTIVITY Interrupt Register
 *     AddressOffset  : 0x5c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_ACTIVITY, 0x5c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_ACTIVITY
 *   CLR_ACTIVITY:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_ACTIVITY, CLR_ACTIVITY, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_ACTIVITY, CLR_ACTIVITY, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_ACTIVITY, CLR_ACTIVITY, 1, 1);

/*
 * Bit Field of Register CLR_ACTIVITY
 *   RSVD_IC_CLR_ACTIVITY:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_ACTIVITY, RSVD_IC_CLR_ACTIVITY, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_STOP_DET ***********
 *
 * Register of SEDI I2C
 *   CLR_STOP_DET: Clear STOP_DET Interrupt Register
 *     AddressOffset  : 0x60
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_STOP_DET, 0x60, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_STOP_DET
 *   CLR_STOP_DET:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_STOP_DET, CLR_STOP_DET, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_STOP_DET, CLR_STOP_DET, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_STOP_DET, CLR_STOP_DET, 1, 1);

/*
 * Bit Field of Register CLR_STOP_DET
 *   RSVD_IC_CLR_STOP_DET:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_STOP_DET, RSVD_IC_CLR_STOP_DET, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_START_DET ***********
 *
 * Register of SEDI I2C
 *   CLR_START_DET: Clear START_DET Interrupt Register
 *     AddressOffset  : 0x64
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_START_DET, 0x64, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_START_DET
 *   CLR_START_DET:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_START_DET, CLR_START_DET, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_START_DET, CLR_START_DET, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_START_DET, CLR_START_DET, 1, 1);

/*
 * Bit Field of Register CLR_START_DET
 *   RSVD_IC_CLR_START_DET:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_START_DET, RSVD_IC_CLR_START_DET, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C CLR_GEN_CALL ***********
 *
 * Register of SEDI I2C
 *   CLR_GEN_CALL: Clear GEN_CALL Interrupt Register
 *     AddressOffset  : 0x68
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_GEN_CALL, 0x68, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_GEN_CALL
 *   CLR_GEN_CALL:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_GEN_CALL, CLR_GEN_CALL, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_GEN_CALL, CLR_GEN_CALL, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_GEN_CALL, CLR_GEN_CALL, 1, 1);

/*
 * Bit Field of Register CLR_GEN_CALL
 *   RSVD_IC_CLR_GEN_CALL:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_GEN_CALL, RSVD_IC_CLR_GEN_CALL, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C ENABLE ***********
 *
 * Register of SEDI I2C
 *   ENABLE: I2C ENABLE Register
 *     AddressOffset  : 0x6c
 *     AccessType     : RW
 *     WritableBitMask: 0xf
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, ENABLE, 0x6c, RW, (uint32_t)0xf, (uint32_t)0x0);

/*
 * Bit Field of Register ENABLE
 *   ENABLE:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, ENABLE, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, ENABLE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, ENABLE, ENABLED, 0x1);

/*
 * Bit Field of Register ENABLE
 *   ABORT:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, ABORT, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, ABORT, DISABLE, 0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, ABORT, ENABLED, 0x1);

/*
 * Bit Field of Register ENABLE
 *   TX_CMD_BLOCK:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, TX_CMD_BLOCK, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, TX_CMD_BLOCK, BLOCKED, 0x1);
SEDI_RBFV_DEFINE(I2C, ENABLE, TX_CMD_BLOCK, NOT_BLOCKED, 0x0);

/*
 * Bit Field of Register ENABLE
 *   SDA_STUCK_RECOVERY_ENABLE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, SDA_STUCK_RECOVERY_ENABLE, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, SDA_STUCK_RECOVERY_ENABLE, SDA_STUCK_RECOVERY_DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, SDA_STUCK_RECOVERY_ENABLE, SDA_STUCK_RECOVERY_ENABLED, 0x1);

/*
 * Bit Field of Register ENABLE
 *   RSVD_IC_ENABLE_1:
 *     BitOffset : 4
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_IC_ENABLE_1, 4, 12, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ENABLE
 *   RSVD_SMBUS_CLK_RESET:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_SMBUS_CLK_RESET, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_SMBUS_CLK_RESET, 0, 0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_SMBUS_CLK_RESET, 1, 1);

/*
 * Bit Field of Register ENABLE
 *   RSVD_SMBUS_SUSPEND_EN:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_SMBUS_SUSPEND_EN, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_SMBUS_SUSPEND_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_SMBUS_SUSPEND_EN, 1, 1);

/*
 * Bit Field of Register ENABLE
 *   RSVD_SMBUS_ALERT_EN:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_SMBUS_ALERT_EN, 18, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_SMBUS_ALERT_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_SMBUS_ALERT_EN, 1, 1);

/*
 * Bit Field of Register ENABLE
 *   RSVD_IC_SAR_EN:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_IC_SAR_EN, 19, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_IC_SAR_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_IC_SAR_EN, 1, 1);

/*
 * Bit Field of Register ENABLE
 *   RSVD_IC_SAR2_EN:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_IC_SAR2_EN, 20, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_IC_SAR2_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_IC_SAR2_EN, 1, 1);

/*
 * Bit Field of Register ENABLE
 *   RSVD_IC_SAR3_EN:
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_IC_SAR3_EN, 21, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_IC_SAR3_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_IC_SAR3_EN, 1, 1);

/*
 * Bit Field of Register ENABLE
 *   RSVD_IC_SAR4_EN:
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_IC_SAR4_EN, 22, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_IC_SAR4_EN, 0, 0);
SEDI_RBFV_DEFINE(I2C, ENABLE, RSVD_IC_SAR4_EN, 1, 1);

/*
 * Bit Field of Register ENABLE
 *   RSVD_IC_ENABLE_2:
 *     BitOffset : 23
 *     BitWidth  : 9
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE, RSVD_IC_ENABLE_2, 23, 9, RO, (uint32_t)0x0);

/* ********* I2C STATUS ***********
 *
 * Register of SEDI I2C
 *   STATUS: I2C STATUS Register
 *     AddressOffset  : 0x70
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x6
 */
SEDI_REG_DEFINE(I2C, STATUS, 0x70, RO, (uint32_t)0x0, (uint32_t)0x6);

/*
 * Bit Field of Register STATUS
 *   ACTIVITY:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, ACTIVITY, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, ACTIVITY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, ACTIVITY, INACTIVE, 0x0);

/*
 * Bit Field of Register STATUS
 *   TFNF:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, STATUS, TFNF, 1, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, TFNF, FULL, 0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, TFNF, NOT_FULL, 0x1);

/*
 * Bit Field of Register STATUS
 *   TFE:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, STATUS, TFE, 2, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, TFE, EMPTY, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, TFE, NON_EMPTY, 0x0);

/*
 * Bit Field of Register STATUS
 *   RFNE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RFNE, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RFNE, EMPTY, 0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RFNE, NOT_EMPTY, 0x1);

/*
 * Bit Field of Register STATUS
 *   RFF:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RFF, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RFF, FULL, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, RFF, NOT_FULL, 0x0);

/*
 * Bit Field of Register STATUS
 *   MST_ACTIVITY:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, MST_ACTIVITY, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, MST_ACTIVITY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, MST_ACTIVITY, IDLE, 0x0);

/*
 * Bit Field of Register STATUS
 *   SLV_ACTIVITY:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, SLV_ACTIVITY, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, SLV_ACTIVITY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, SLV_ACTIVITY, IDLE, 0x0);

/*
 * Bit Field of Register STATUS
 *   MST_HOLD_TX_FIFO_EMPTY:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, MST_HOLD_TX_FIFO_EMPTY, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, MST_HOLD_TX_FIFO_EMPTY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, MST_HOLD_TX_FIFO_EMPTY, INACTIVE, 0x0);

/*
 * Bit Field of Register STATUS
 *   MST_HOLD_RX_FIFO_FULL:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, MST_HOLD_RX_FIFO_FULL, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, MST_HOLD_RX_FIFO_FULL, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, MST_HOLD_RX_FIFO_FULL, INACTIVE, 0x0);

/*
 * Bit Field of Register STATUS
 *   SLV_HOLD_TX_FIFO_EMPTY:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, SLV_HOLD_TX_FIFO_EMPTY, 9, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, SLV_HOLD_TX_FIFO_EMPTY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, SLV_HOLD_TX_FIFO_EMPTY, INACTIVE, 0x0);

/*
 * Bit Field of Register STATUS
 *   SLV_HOLD_RX_FIFO_FULL:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, SLV_HOLD_RX_FIFO_FULL, 10, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, SLV_HOLD_RX_FIFO_FULL, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, SLV_HOLD_RX_FIFO_FULL, INACTIVE, 0x0);

/*
 * Bit Field of Register STATUS
 *   SDA_STUCK_NOT_RECOVERED:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, SDA_STUCK_NOT_RECOVERED, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, SDA_STUCK_NOT_RECOVERED, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, STATUS, SDA_STUCK_NOT_RECOVERED, INACTIVE, 0x0);

/*
 * Bit Field of Register STATUS
 *   RSVD_SLV_ISO_SAR_DATA_CLK_STRETCH:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SLV_ISO_SAR_DATA_CLK_STRETCH, 12, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SLV_ISO_SAR_DATA_CLK_STRETCH, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SLV_ISO_SAR_DATA_CLK_STRETCH, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_IC_STATUS_1:
 *     BitOffset : 13
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_IC_STATUS_1, 13, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_QUICK_CMD_BIT:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_QUICK_CMD_BIT, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_QUICK_CMD_BIT, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_QUICK_CMD_BIT, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SLAVE_ADDR_VALID:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR_VALID, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR_VALID, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR_VALID, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SLAVE_ADDR_RESOLVED:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR_RESOLVED, 18, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR_RESOLVED, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR_RESOLVED, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SUSPEND_STATUS:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SUSPEND_STATUS, 19, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SUSPEND_STATUS, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SUSPEND_STATUS, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_ALERT_STATUS:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_ALERT_STATUS, 20, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_ALERT_STATUS, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_ALERT_STATUS, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SLAVE_ADDR2_VALID:
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR2_VALID, 21, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR2_VALID, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR2_VALID, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SLAVE_ADDR2_RESOLVED:
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR2_RESOLVED, 22, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR2_RESOLVED, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR2_RESOLVED, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SLAVE_ADDR3_VALID:
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR3_VALID, 23, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR3_VALID, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR3_VALID, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SLAVE_ADDR3_RESOLVED:
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR3_RESOLVED, 24, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR3_RESOLVED, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR3_RESOLVED, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SLAVE_ADDR4_VALID:
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR4_VALID, 25, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR4_VALID, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR4_VALID, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_SMBUS_SLAVE_ADDR4_RESOLVED:
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR4_RESOLVED, 26, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR4_RESOLVED, 0, 0);
SEDI_RBFV_DEFINE(I2C, STATUS, RSVD_SMBUS_SLAVE_ADDR4_RESOLVED, 1, 1);

/*
 * Bit Field of Register STATUS
 *   RSVD_IC_STATUS_2:
 *     BitOffset : 27
 *     BitWidth  : 5
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, STATUS, RSVD_IC_STATUS_2, 27, 5, RO, (uint32_t)0x0);

/* ********* I2C TXFLR ***********
 *
 * Register of SEDI I2C
 *   TXFLR: I2C Transmit FIFO Level Register
 *     AddressOffset  : 0x74
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, TXFLR, 0x74, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register TXFLR
 *   TXFLR:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TXFLR, TXFLR, 0, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register TXFLR
 *   RSVD_TXFLR:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TXFLR, RSVD_TXFLR, 7, 25, RO, (uint32_t)0x0);

/* ********* I2C RXFLR ***********
 *
 * Register of SEDI I2C
 *   RXFLR: I2C Receive FIFO Level Register
 *     AddressOffset  : 0x78
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, RXFLR, 0x78, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RXFLR
 *   RXFLR:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RXFLR, RXFLR, 0, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RXFLR
 *   RSVD_RXFLR:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, RXFLR, RSVD_RXFLR, 7, 25, RO, (uint32_t)0x0);

/* ********* I2C SDA_HOLD ***********
 *
 * Register of SEDI I2C
 *   SDA_HOLD: I2C SDA Hold Time Length Register
 *     AddressOffset  : 0x7c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffff
 *     ResetValue     : (uint32_t)0x5
 */
SEDI_REG_DEFINE(I2C, SDA_HOLD, 0x7c, RW, (uint32_t)0xffffff, (uint32_t)0x5);

/*
 * Bit Field of Register SDA_HOLD
 *   IC_SDA_TX_HOLD:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x5
 */
SEDI_RBF_DEFINE(I2C, SDA_HOLD, IC_SDA_TX_HOLD, 0, 16, RW, (uint32_t)0x5);

/*
 * Bit Field of Register SDA_HOLD
 *   IC_SDA_RX_HOLD:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, SDA_HOLD, IC_SDA_RX_HOLD, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register SDA_HOLD
 *   RSVD_IC_SDA_HOLD:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, SDA_HOLD, RSVD_IC_SDA_HOLD, 24, 8, RO, (uint32_t)0x0);

/* ********* I2C TX_ABRT_SOURCE ***********
 *
 * Register of SEDI I2C
 *   TX_ABRT_SOURCE: I2C Transmit Abort Source Register
 *     AddressOffset  : 0x80
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, TX_ABRT_SOURCE, 0x80, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_7B_ADDR_NOACK:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_7B_ADDR_NOACK, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_7B_ADDR_NOACK, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_7B_ADDR_NOACK, INACTIVE, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_10ADDR1_NOACK:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10ADDR1_NOACK, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10ADDR1_NOACK, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10ADDR1_NOACK, INACTIVE, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_10ADDR2_NOACK:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10ADDR2_NOACK, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10ADDR2_NOACK, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10ADDR2_NOACK, INACTIVE, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_TXDATA_NOACK:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_TXDATA_NOACK, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_TXDATA_NOACK, ABRT_TXDATA_NOACK_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_TXDATA_NOACK, ABRT_TXDATA_NOACK_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_GCALL_NOACK:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_GCALL_NOACK, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_GCALL_NOACK, ABRT_GCALL_NOACK_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_GCALL_NOACK, ABRT_GCALL_NOACK_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_GCALL_READ:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_GCALL_READ, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_GCALL_READ, ABRT_GCALL_READ_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_GCALL_READ, ABRT_GCALL_READ_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_HS_ACKDET:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_HS_ACKDET, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_HS_ACKDET, ABRT_HS_ACK_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_HS_ACKDET, ABRT_HS_ACK_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_SBYTE_ACKDET:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SBYTE_ACKDET, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SBYTE_ACKDET, ABRT_SBYTE_ACKDET_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SBYTE_ACKDET, ABRT_SBYTE_ACKDET_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_HS_NORSTRT:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_HS_NORSTRT, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_HS_NORSTRT, ABRT_HS_NORSTRT_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_HS_NORSTRT, ABRT_HS_NORSTRT_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_SBYTE_NORSTRT:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SBYTE_NORSTRT, 9, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SBYTE_NORSTRT, ABRT_SBYTE_NORSTRT_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SBYTE_NORSTRT, ABRT_SBYTE_NORSTRT_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_10B_RD_NORSTRT:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10B_RD_NORSTRT, 10, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10B_RD_NORSTRT, ABRT_10B_RD_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_10B_RD_NORSTRT, ABRT_10B_RD_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_MASTER_DIS:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_MASTER_DIS, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_MASTER_DIS, ABRT_MASTER_DIS_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_MASTER_DIS, ABRT_MASTER_DIS_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ARB_LOST:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ARB_LOST, 12, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ARB_LOST, ABRT_LOST_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ARB_LOST, ABRT_LOST_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_SLVFLUSH_TXFIFO:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLVFLUSH_TXFIFO, 13, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLVFLUSH_TXFIFO, ABRT_SLVFLUSH_TXFIFO_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLVFLUSH_TXFIFO, ABRT_SLVFLUSH_TXFIFO_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_SLV_ARBLOST:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLV_ARBLOST, 14, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLV_ARBLOST, ABRT_SLV_ARBLOST_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLV_ARBLOST, ABRT_SLV_ARBLOST_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_SLVRD_INTX:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLVRD_INTX, 15, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLVRD_INTX, ABRT_SLVRD_INTX_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SLVRD_INTX, ABRT_SLVRD_INTX_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_USER_ABRT:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_USER_ABRT, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_USER_ABRT, ABRT_USER_ABRT_GENERATED, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_USER_ABRT, ABRT_USER_ABRT_VOID, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   ABRT_SDA_STUCK_AT_LOW:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SDA_STUCK_AT_LOW, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SDA_STUCK_AT_LOW, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, TX_ABRT_SOURCE, ABRT_SDA_STUCK_AT_LOW, INACTIVE, 0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   RSVD_ABRT_DEVICE_WRITE:
 *     BitOffset : 18
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, RSVD_ABRT_DEVICE_WRITE, 18, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   RSVD_IC_TX_ABRT_SOURCE:
 *     BitOffset : 21
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, RSVD_IC_TX_ABRT_SOURCE, 21, 2, RO, (uint32_t)0x0);

/*
 * Bit Field of Register TX_ABRT_SOURCE
 *   TX_FLUSH_CNT:
 *     BitOffset : 23
 *     BitWidth  : 9
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, TX_ABRT_SOURCE, TX_FLUSH_CNT, 23, 9, RO, (uint32_t)0x0);

/* ********* I2C DMA_CR ***********
 *
 * Register of SEDI I2C
 *   DMA_CR: DMA Control Register
 *     AddressOffset  : 0x88
 *     AccessType     : RW
 *     WritableBitMask: 0x3
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, DMA_CR, 0x88, RW, (uint32_t)0x3, (uint32_t)0x0);

/*
 * Bit Field of Register DMA_CR
 *   RDMAE:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DMA_CR, RDMAE, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, DMA_CR, RDMAE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, DMA_CR, RDMAE, ENABLED, 0x1);

/*
 * Bit Field of Register DMA_CR
 *   TDMAE:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DMA_CR, TDMAE, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, DMA_CR, TDMAE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, DMA_CR, TDMAE, ENABLED, 0x1);

/*
 * Bit Field of Register DMA_CR
 *   RSVD_IC_DMA_CR_2_31:
 *     BitOffset : 2
 *     BitWidth  : 30
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DMA_CR, RSVD_IC_DMA_CR_2_31, 2, 30, RO, (uint32_t)0x0);

/* ********* I2C DMA_TDLR ***********
 *
 * Register of SEDI I2C
 *   DMA_TDLR: DMA Transmit Data Level Register
 *     AddressOffset  : 0x8c
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, DMA_TDLR, 0x8c, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register DMA_TDLR
 *   DMATDL:
 *     BitOffset : 0
 *     BitWidth  : 6
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DMA_TDLR, DMATDL, 0, 6, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DMA_TDLR
 *   RSVD_DMA_TDLR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DMA_TDLR, RSVD_DMA_TDLR, 6, 26, RO, (uint32_t)0x0);

/* ********* I2C DMA_RDLR ***********
 *
 * Register of SEDI I2C
 *   DMA_RDLR: DMA Receive Data Level Register
 *     AddressOffset  : 0x90
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, DMA_RDLR, 0x90, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register DMA_RDLR
 *   DMARDL:
 *     BitOffset : 0
 *     BitWidth  : 6
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DMA_RDLR, DMARDL, 0, 6, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DMA_RDLR
 *   RSVD_DMA_RDLR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, DMA_RDLR, RSVD_DMA_RDLR, 6, 26, RO, (uint32_t)0x0);

/* ********* I2C SDA_SETUP ***********
 *
 * Register of SEDI I2C
 *   SDA_SETUP: I2C SDA Setup Register
 *     AddressOffset  : 0x94
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x2
 */
SEDI_REG_DEFINE(I2C, SDA_SETUP, 0x94, RW, (uint32_t)0xff, (uint32_t)0x2);

/*
 * Bit Field of Register SDA_SETUP
 *   SDA_SETUP:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(I2C, SDA_SETUP, SDA_SETUP, 0, 8, RW, (uint32_t)0x2);

/*
 * Bit Field of Register SDA_SETUP
 *   RSVD_IC_SDA_SETUP:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, SDA_SETUP, RSVD_IC_SDA_SETUP, 8, 24, RO, (uint32_t)0x0);

/* ********* I2C ACK_GENERAL_CALL ***********
 *
 * Register of SEDI I2C
 *   ACK_GENERAL_CALL: I2C ACK General Call Register
 *     AddressOffset  : 0x98
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, ACK_GENERAL_CALL, 0x98, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ACK_GENERAL_CALL
 *   ACK_GEN_CALL:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ACK_GENERAL_CALL, ACK_GEN_CALL, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ACK_GENERAL_CALL, ACK_GEN_CALL, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, ACK_GENERAL_CALL, ACK_GEN_CALL, ENABLED, 0x1);

/*
 * Bit Field of Register ACK_GENERAL_CALL
 *   RSVD_IC_ACK_GEN_1_31:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ACK_GENERAL_CALL, RSVD_IC_ACK_GEN_1_31, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C ENABLE_STATUS ***********
 *
 * Register of SEDI I2C
 *   ENABLE_STATUS: I2C Enable Status Register
 *     AddressOffset  : 0x9c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, ENABLE_STATUS, 0x9c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ENABLE_STATUS
 *   IC_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE_STATUS, IC_EN, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE_STATUS, IC_EN, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE_STATUS, IC_EN, ENABLED, 0x1);

/*
 * Bit Field of Register ENABLE_STATUS
 *   SLV_DISABLED_WHILE_BUSY:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE_STATUS, SLV_DISABLED_WHILE_BUSY, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE_STATUS, SLV_DISABLED_WHILE_BUSY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, ENABLE_STATUS, SLV_DISABLED_WHILE_BUSY, INACTIVE, 0x0);

/*
 * Bit Field of Register ENABLE_STATUS
 *   SLV_RX_DATA_LOST:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE_STATUS, SLV_RX_DATA_LOST, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, ENABLE_STATUS, SLV_RX_DATA_LOST, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(I2C, ENABLE_STATUS, SLV_RX_DATA_LOST, INACTIVE, 0x0);

/*
 * Bit Field of Register ENABLE_STATUS
 *   RSVD_IC_ENABLE_STATUS:
 *     BitOffset : 3
 *     BitWidth  : 29
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, ENABLE_STATUS, RSVD_IC_ENABLE_STATUS, 3, 29, RO, (uint32_t)0x0);

/* ********* I2C FS_SPKLEN ***********
 *
 * Register of SEDI I2C
 *   FS_SPKLEN: I2C SS, FS or FM+  spike suppression limit
 *     AddressOffset  : 0xa0
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x5
 */
SEDI_REG_DEFINE(I2C, FS_SPKLEN, 0xa0, RW, (uint32_t)0xff, (uint32_t)0x5);

/*
 * Bit Field of Register FS_SPKLEN
 *   IC_FS_SPKLEN:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x5
 */
SEDI_RBF_DEFINE(I2C, FS_SPKLEN, IC_FS_SPKLEN, 0, 8, RW, (uint32_t)0x5);

/*
 * Bit Field of Register FS_SPKLEN
 *   RSVD_IC_FS_SPKLEN:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, FS_SPKLEN, RSVD_IC_FS_SPKLEN, 8, 24, RO, (uint32_t)0x0);

/* ********* I2C HS_SPKLEN ***********
 *
 * Register of SEDI I2C
 *   HS_SPKLEN: I2C HS spike suppression limit register
 *     AddressOffset  : 0xa4
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x2
 */
SEDI_REG_DEFINE(I2C, HS_SPKLEN, 0xa4, RW, (uint32_t)0xff, (uint32_t)0x2);

/*
 * Bit Field of Register HS_SPKLEN
 *   IC_HS_SPKLEN:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(I2C, HS_SPKLEN, IC_HS_SPKLEN, 0, 8, RW, (uint32_t)0x2);

/*
 * Bit Field of Register HS_SPKLEN
 *   RSVD_IC_HS_SPKLEN:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, HS_SPKLEN, RSVD_IC_HS_SPKLEN, 8, 24, RO, (uint32_t)0x0);

/* ********* I2C CLR_RESTART_DET ***********
 *
 * Register of SEDI I2C
 *   CLR_RESTART_DET: Clear RESTART_DET Interrupt Register
 *     AddressOffset  : 0xa8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_RESTART_DET, 0xa8, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_RESTART_DET
 *   CLR_RESTART_DET:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RESTART_DET, CLR_RESTART_DET, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_RESTART_DET, CLR_RESTART_DET, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_RESTART_DET, CLR_RESTART_DET, 1, 1);

/*
 * Bit Field of Register CLR_RESTART_DET
 *   RSVD_IC_CLR_RESTART_DET:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_RESTART_DET, RSVD_IC_CLR_RESTART_DET, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C SCL_STUCK_AT_LOW_TIMEOUT ***********
 *
 * Register of SEDI I2C
 *   SCL_STUCK_AT_LOW_TIMEOUT: I2C SCL Stuck at Low Timeout register
 *     AddressOffset  : 0xac
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)-1
 */
SEDI_REG_DEFINE(I2C, SCL_STUCK_AT_LOW_TIMEOUT, 0xac, RW, (uint32_t)0xffffffff, (uint32_t)-1);

/*
 * Bit Field of Register SCL_STUCK_AT_LOW_TIMEOUT
 *   IC_SCL_STUCK_LOW_TIMEOUT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)-1
 */
SEDI_RBF_DEFINE(I2C, SCL_STUCK_AT_LOW_TIMEOUT, IC_SCL_STUCK_LOW_TIMEOUT, 0, 32, RW, (uint32_t)-1);

/* ********* I2C SDA_STUCK_AT_LOW_TIMEOUT ***********
 *
 * Register of SEDI I2C
 *   SDA_STUCK_AT_LOW_TIMEOUT: I2C SDA Stuck at Low Timeout register
 *     AddressOffset  : 0xb0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)-1
 */
SEDI_REG_DEFINE(I2C, SDA_STUCK_AT_LOW_TIMEOUT, 0xb0, RW, (uint32_t)0xffffffff, (uint32_t)-1);

/*
 * Bit Field of Register SDA_STUCK_AT_LOW_TIMEOUT
 *   IC_SDA_STUCK_LOW_TIMEOUT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)-1
 */
SEDI_RBF_DEFINE(I2C, SDA_STUCK_AT_LOW_TIMEOUT, IC_SDA_STUCK_LOW_TIMEOUT, 0, 32, RW, (uint32_t)-1);

/* ********* I2C CLR_SCL_STUCK_DET ***********
 *
 * Register of SEDI I2C
 *   CLR_SCL_STUCK_DET: Clear SCL Stuck at Low Detect interrupt Register
 *     AddressOffset  : 0xb4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(I2C, CLR_SCL_STUCK_DET, 0xb4, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register CLR_SCL_STUCK_DET
 *   CLR_SCL_STUCK_DET:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_SCL_STUCK_DET, CLR_SCL_STUCK_DET, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, CLR_SCL_STUCK_DET, CLR_SCL_STUCK_DET, 0, 0);
SEDI_RBFV_DEFINE(I2C, CLR_SCL_STUCK_DET, CLR_SCL_STUCK_DET, 1, 1);

/*
 * Bit Field of Register CLR_SCL_STUCK_DET
 *   RSVD_CLR_SCL_STUCK_DET:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, CLR_SCL_STUCK_DET, RSVD_CLR_SCL_STUCK_DET, 1, 31, RO, (uint32_t)0x0);

/* ********* I2C COMP_PARAM_1 ***********
 *
 * Register of SEDI I2C
 *   COMP_PARAM_1: Component Parameter Register 1
 *     AddressOffset  : 0xf4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x3f3fee
 */
SEDI_REG_DEFINE(I2C, COMP_PARAM_1, 0xf4, RO, (uint32_t)0x0, (uint32_t)0x3f3fee);

/*
 * Bit Field of Register COMP_PARAM_1
 *   APB_DATA_WIDTH:
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, APB_DATA_WIDTH, 0, 2, RO, (uint32_t)0x2);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, APB_DATA_WIDTH, APB_08BITS, 0x0);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, APB_DATA_WIDTH, APB_16BITS, 0x1);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, APB_DATA_WIDTH, APB_32BITS, 0x2);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, APB_DATA_WIDTH, RESERVED, 0x3);

/*
 * Bit Field of Register COMP_PARAM_1
 *   MAX_SPEED_MODE:
 *     BitOffset : 2
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, MAX_SPEED_MODE, 2, 2, RO, (uint32_t)0x3);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, MAX_SPEED_MODE, FAST, 0x2);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, MAX_SPEED_MODE, HIGH, 0x3);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, MAX_SPEED_MODE, STANDARD, 0x1);

/*
 * Bit Field of Register COMP_PARAM_1
 *   HC_COUNT_VALUES:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, HC_COUNT_VALUES, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, HC_COUNT_VALUES, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, HC_COUNT_VALUES, ENABLED, 0x1);

/*
 * Bit Field of Register COMP_PARAM_1
 *   INTR_IO:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, INTR_IO, 5, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, INTR_IO, COMBINED, 0x1);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, INTR_IO, INDIVIDUAL, 0x0);

/*
 * Bit Field of Register COMP_PARAM_1
 *   HAS_DMA:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, HAS_DMA, 6, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, HAS_DMA, DISABLED, 0x0);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, HAS_DMA, ENABLED, 0x1);

/*
 * Bit Field of Register COMP_PARAM_1
 *   ADD_ENCODED_PARAMS:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, ADD_ENCODED_PARAMS, 7, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, ADD_ENCODED_PARAMS, DISBALED, 0x0);
SEDI_RBFV_DEFINE(I2C, COMP_PARAM_1, ADD_ENCODED_PARAMS, ENABLED, 0x1);

/*
 * Bit Field of Register COMP_PARAM_1
 *   RX_BUFFER_DEPTH:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3f
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, RX_BUFFER_DEPTH, 8, 8, RO, (uint32_t)0x3f);

/*
 * Bit Field of Register COMP_PARAM_1
 *   TX_BUFFER_DEPTH:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3f
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, TX_BUFFER_DEPTH, 16, 8, RO, (uint32_t)0x3f);

/*
 * Bit Field of Register COMP_PARAM_1
 *   RSVD_IC_COMP_PARAM_1:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(I2C, COMP_PARAM_1, RSVD_IC_COMP_PARAM_1, 24, 8, RO, (uint32_t)0x0);

/* ********* I2C COMP_VERSION ***********
 *
 * Register of SEDI I2C
 *   COMP_VERSION: I2C Component Version Register
 *     AddressOffset  : 0xf8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x3230332a
 */
SEDI_REG_DEFINE(I2C, COMP_VERSION, 0xf8, RO, (uint32_t)0x0, (uint32_t)0x3230332a);

/*
 * Bit Field of Register COMP_VERSION
 *   IC_COMP_VERSION:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3230332a
 */
SEDI_RBF_DEFINE(I2C, COMP_VERSION, IC_COMP_VERSION, 0, 32, RO, (uint32_t)0x3230332a);

/* ********* I2C COMP_TYPE ***********
 *
 * Register of SEDI I2C
 *   COMP_TYPE: I2C Component Type Register
 *     AddressOffset  : 0xfc
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x44570140
 */
SEDI_REG_DEFINE(I2C, COMP_TYPE, 0xfc, RO, (uint32_t)0x0, (uint32_t)0x44570140);

/*
 * Bit Field of Register COMP_TYPE
 *   IC_COMP_TYPE:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x44570140
 */
SEDI_RBF_DEFINE(I2C, COMP_TYPE, IC_COMP_TYPE, 0, 32, RO, (uint32_t)0x44570140);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* I2C Control Register */
	__IO_RW uint32_t con;

	/* I2C Target Address Register */
	__IO_RW uint32_t tar;

	/* I2C Slave Address Register */
	__IO_RW uint32_t sar;

	/* I2C High Speed Master Mode Code Address Register */
	__IO_RW uint32_t hs_maddr;

	/* I2C Rx/Tx Data Buffer and Command Register */
	__IO_RW uint32_t data_cmd;

	/* Standard Speed I2C Clock SCL High Count Register */
	__IO_RW uint32_t ss_scl_hcnt;

	/* Standard Speed I2C Clock SCL Low Count Register */
	__IO_RW uint32_t ss_scl_lcnt;

	/* Fast Mode or Fast Mode Plus I2C Clock SCL High Count Register */
	__IO_RW uint32_t fs_scl_hcnt;

	/* Fast Mode or Fast Mode Plus I2C Clock SCL Low Count Register */
	__IO_RW uint32_t fs_scl_lcnt;

	/* High Speed I2C Clock SCL High Count Register */
	__IO_RW uint32_t hs_scl_hcnt;

	/* High Speed I2C Clock SCL Low Count Register */
	__IO_RW uint32_t hs_scl_lcnt;

	/* I2C Interrupt Status Register */
	__IO_R uint32_t intr_stat;

	/* I2C Interrupt Mask Register */
	__IO_RW uint32_t intr_mask;

	/* I2C Raw Interrupt Status Register */
	__IO_R uint32_t raw_intr_stat;

	/* I2C Receive FIFO Threshold Register */
	__IO_RW uint32_t rx_tl;

	/* I2C Transmit FIFO Threshold Register */
	__IO_RW uint32_t tx_tl;

	/* Clear Combined and Individual Interrupt Register */
	__IO_R uint32_t clr_intr;

	/* Clear RX_UNDER Interrupt Register */
	__IO_R uint32_t clr_rx_under;

	/* Clear RX_OVER Interrupt Register */
	__IO_R uint32_t clr_rx_over;

	/* Clear TX_OVER Interrupt Register */
	__IO_R uint32_t clr_tx_over;

	/* Clear RD_REQ Interrupt Register */
	__IO_R uint32_t clr_rd_req;

	/* Clear TX_ABRT Interrupt Register */
	__IO_R uint32_t clr_tx_abrt;

	/* Clear RX_DONE Interrupt Register */
	__IO_R uint32_t clr_rx_done;

	/* Clear ACTIVITY Interrupt Register */
	__IO_R uint32_t clr_activity;

	/* Clear STOP_DET Interrupt Register */
	__IO_R uint32_t clr_stop_det;

	/* Clear START_DET Interrupt Register */
	__IO_R uint32_t clr_start_det;

	/* Clear GEN_CALL Interrupt Register */
	__IO_R uint32_t clr_gen_call;

	/* I2C ENABLE Register */
	__IO_RW uint32_t enable;

	/* I2C STATUS Register */
	__IO_R uint32_t status;

	/* I2C Transmit FIFO Level Register */
	__IO_R uint32_t txflr;

	/* I2C Receive FIFO Level Register */
	__IO_R uint32_t rxflr;

	/* I2C SDA Hold Time Length Register */
	__IO_RW uint32_t sda_hold;

	/* I2C Transmit Abort Source Register */
	__IO_R uint32_t tx_abrt_source;

	/* Reserved */
	__IO_RW uint32_t reserved0[1];

	/* DMA Control Register */
	__IO_RW uint32_t dma_cr;

	/* DMA Transmit Data Level Register */
	__IO_RW uint32_t dma_tdlr;

	/* DMA Receive Data Level Register */
	__IO_RW uint32_t dma_rdlr;

	/* I2C SDA Setup Register */
	__IO_RW uint32_t sda_setup;

	/* I2C ACK General Call Register */
	__IO_RW uint32_t ack_general_call;

	/* I2C Enable Status Register */
	__IO_R uint32_t enable_status;

	/* I2C SS, FS or FM+  spike suppression limit */
	__IO_RW uint32_t fs_spklen;

	/* I2C HS spike suppression limit register */
	__IO_RW uint32_t hs_spklen;

	/* Clear RESTART_DET Interrupt Register */
	__IO_R uint32_t clr_restart_det;

	/* I2C SCL Stuck at Low Timeout register */
	__IO_RW uint32_t scl_stuck_at_low_timeout;

	/* I2C SDA Stuck at Low Timeout register */
	__IO_RW uint32_t sda_stuck_at_low_timeout;

	/* Clear SCL Stuck at Low Detect interrupt Register */
	__IO_R uint32_t clr_scl_stuck_det;

	/* Reserved */
	__IO_RW uint32_t reserved1[15];

	/* Component Parameter Register 1 */
	__IO_R uint32_t comp_param_1;

	/* I2C Component Version Register */
	__IO_R uint32_t comp_version;

	/* I2C Component Type Register */
	__IO_R uint32_t comp_type;

} sedi_i2c_regs_t;


#endif /* _SEDI_I2C_REGS_H_ */
