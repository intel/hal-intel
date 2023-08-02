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

#ifndef _SEDI_SPI_REGS_H_
#define _SEDI_SPI_REGS_H_

#include <sedi_reg_defs.h>


/* ********* SPI CTRLR0 ***********
 *
 * Register of SEDI SPI
 *   CTRLR0: Control Register 0
 *     AddressOffset  : 0x0
 *     AccessType     : RW
 *     WritableBitMask: 0x11ffbf0
 *     ResetValue     : (uint32_t)0x1070000
 */
SEDI_REG_DEFINE(SPI, CTRLR0, 0x0, RW, (uint32_t)0x11ffbf0, (uint32_t)0x1070000);

/*
 * Bit Field of Register CTRLR0
 *   DFS:
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, DFS, 0, 4, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_04BITS, 0x3);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_05BITS, 0x4);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_06BITS, 0x5);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_07BITS, 0x6);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_08BITS, 0x7);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_09BITS, 0x8);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_10BITS, 0x9);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_11BITS, 0xa);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_12BITS, 0xb);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_13BITS, 0xc);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_14BITS, 0xd);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_15BITS, 0xe);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS, FRAME_16BITS, 0xf);

/*
 * Bit Field of Register CTRLR0
 *   FRF:
 *     BitOffset : 4
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, FRF, 4, 2, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, FRF, MOTOROLA_SPI, 0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, FRF, NS_MICROWIRE, 0x2);
SEDI_RBFV_DEFINE(SPI, CTRLR0, FRF, RESERVED, 0x3);
SEDI_RBFV_DEFINE(SPI, CTRLR0, FRF, TEXAS_SSP, 0x1);

/*
 * Bit Field of Register CTRLR0
 *   SCPH:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, SCPH, 6, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SCPH, SCPH_MIDDLE, 0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SCPH, SCPH_START, 0x1);

/*
 * Bit Field of Register CTRLR0
 *   SCPOL:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, SCPOL, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SCPOL, SCLK_HIGH, 0x1);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SCPOL, SCLK_LOW, 0x0);

/*
 * Bit Field of Register CTRLR0
 *   TMOD:
 *     BitOffset : 8
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, TMOD, 8, 2, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, TMOD, EEPROM_READ, 0x3);
SEDI_RBFV_DEFINE(SPI, CTRLR0, TMOD, RX_ONLY, 0x2);
SEDI_RBFV_DEFINE(SPI, CTRLR0, TMOD, TX_AND_RX, 0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, TMOD, TX_ONLY, 0x1);

/*
 * Bit Field of Register CTRLR0
 *   SLV_OE:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, SLV_OE, 10, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SLV_OE, DISABLED, 0x1);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SLV_OE, ENABLED, 0x0);

/*
 * Bit Field of Register CTRLR0
 *   SRL:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, SRL, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SRL, NORMAL_MODE, 0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SRL, TESTING_MODE, 0x1);

/*
 * Bit Field of Register CTRLR0
 *   CFS:
 *     BitOffset : 12
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, CFS, 12, 4, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_01_BIT, 0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_02_BIT, 0x1);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_03_BIT, 0x2);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_04_BIT, 0x3);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_05_BIT, 0x4);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_06_BIT, 0x5);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_07_BIT, 0x6);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_08_BIT, 0x7);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_09_BIT, 0x8);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_10_BIT, 0x9);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_11_BIT, 0xa);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_12_BIT, 0xb);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_13_BIT, 0xc);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_14_BIT, 0xd);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_15_BIT, 0xe);
SEDI_RBFV_DEFINE(SPI, CTRLR0, CFS, SIZE_16_BIT, 0xf);

/*
 * Bit Field of Register CTRLR0
 *   DFS_32:
 *     BitOffset : 16
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x7
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, DFS_32, 16, 5, RW, (uint32_t)0x7);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_04BITS, 0x3);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_05BITS, 0x4);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_06BITS, 0x5);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_07BITS, 0x6);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_08BITS, 0x7);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_09BITS, 0x8);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_10BITS, 0x9);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_11BITS, 0xa);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_12BITS, 0xb);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_13BITS, 0xc);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_14BITS, 0xd);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_15BITS, 0xe);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_16BITS, 0xf);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_17BITS, 0x10);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_18BITS, 0x11);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_19BITS, 0x12);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_20BITS, 0x13);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_21BITS, 0x14);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_22BITS, 0x15);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_23BITS, 0x16);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_24BITS, 0x17);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_25BITS, 0x18);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_26BITS, 0x19);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_27BITS, 0x1a);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_28BITS, 0x1b);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_29BITS, 0x1c);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_30BITS, 0x1d);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_31BITS, 0x1e);
SEDI_RBFV_DEFINE(SPI, CTRLR0, DFS_32, FRAME_32BITS, 0x1f);

/*
 * Bit Field of Register CTRLR0
 *   SPI_FRF:
 *     BitOffset : 21
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, SPI_FRF, 21, 2, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SPI_FRF, DUAL_SPI_FRF, 0x1);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SPI_FRF, OCTAL_SPI_FRF, 0x3);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SPI_FRF, QUAD_SPI_FRF, 0x2);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SPI_FRF, STD_SPI_FRF, 0x0);

/*
 * Bit Field of Register CTRLR0
 *   RSVD_CTRLR0_23:
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, RSVD_CTRLR0_23, 23, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, RSVD_CTRLR0_23, 0, 0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, RSVD_CTRLR0_23, 1, 1);

/*
 * Bit Field of Register CTRLR0
 *   SSTE:
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, SSTE, 24, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SSTE, 0, 0);
SEDI_RBFV_DEFINE(SPI, CTRLR0, SSTE, 1, 1);

/*
 * Bit Field of Register CTRLR0
 *   RSVD_CTRLR0:
 *     BitOffset : 26
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR0, RSVD_CTRLR0, 26, 6, RO, (uint32_t)0x0);

/* ********* SPI CTRLR1 ***********
 *
 * Register of SEDI SPI
 *   CTRLR1: Control Register 1
 *     AddressOffset  : 0x4
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, CTRLR1, 0x4, RW, (uint32_t)0xffff, (uint32_t)0x0);

/*
 * Bit Field of Register CTRLR1
 *   NDF:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR1, NDF, 0, 16, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CTRLR1
 *   RSVD_CTRLR1:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, CTRLR1, RSVD_CTRLR1, 16, 16, RO, (uint32_t)0x0);

/* ********* SPI SSIENR ***********
 *
 * Register of SEDI SPI
 *   SSIENR: SSI Enable Register
 *     AddressOffset  : 0x8
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, SSIENR, 0x8, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register SSIENR
 *   SSI_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SSIENR, SSI_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, SSIENR, SSI_EN, DISABLE, 0x0);
SEDI_RBFV_DEFINE(SPI, SSIENR, SSI_EN, ENABLED, 0x1);

/*
 * Bit Field of Register SSIENR
 *   RSVD_SSIENR:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SSIENR, RSVD_SSIENR, 1, 31, RO, (uint32_t)0x0);

/* ********* SPI MWCR ***********
 *
 * Register of SEDI SPI
 *   MWCR: Microwire Control Register
 *     AddressOffset  : 0xc
 *     AccessType     : RW
 *     WritableBitMask: 0x7
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, MWCR, 0xc, RW, (uint32_t)0x7, (uint32_t)0x0);

/*
 * Bit Field of Register MWCR
 *   MWMOD:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, MWCR, MWMOD, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, MWCR, MWMOD, NON_SEQUENTIAL, 0x0);
SEDI_RBFV_DEFINE(SPI, MWCR, MWMOD, SEQUENTIAL, 0x1);

/*
 * Bit Field of Register MWCR
 *   MDD:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, MWCR, MDD, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, MWCR, MDD, RECEIVE, 0x0);
SEDI_RBFV_DEFINE(SPI, MWCR, MDD, TRANSMIT, 0x1);

/*
 * Bit Field of Register MWCR
 *   MHS:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, MWCR, MHS, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, MWCR, MHS, DISABLE, 0x0);
SEDI_RBFV_DEFINE(SPI, MWCR, MHS, ENABLED, 0x1);

/*
 * Bit Field of Register MWCR
 *   RSVD_MWCR:
 *     BitOffset : 3
 *     BitWidth  : 29
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, MWCR, RSVD_MWCR, 3, 29, RO, (uint32_t)0x0);

/* ********* SPI SER ***********
 *
 * Register of SEDI SPI
 *   SER: Slave Enable Register
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x3
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, SER, 0x10, RW, (uint32_t)0x3, (uint32_t)0x0);

/*
 * Bit Field of Register SER
 *   SER:
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SER, SER, 0, 2, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, SER, SER, NOT_SELECTED, 0x0);
SEDI_RBFV_DEFINE(SPI, SER, SER, SELECTED, 0x1);

/*
 * Bit Field of Register SER
 *   RSVD_SER:
 *     BitOffset : 2
 *     BitWidth  : 30
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SER, RSVD_SER, 2, 30, RO, (uint32_t)0x0);

/* ********* SPI BAUDR ***********
 *
 * Register of SEDI SPI
 *   BAUDR: Baud Rate Select
 *     AddressOffset  : 0x14
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, BAUDR, 0x14, RW, (uint32_t)0xffff, (uint32_t)0x0);

/*
 * Bit Field of Register BAUDR
 *   SCKDV:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, BAUDR, SCKDV, 0, 16, RW, (uint32_t)0x0);

/*
 * Bit Field of Register BAUDR
 *   RSVD_BAUDR:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, BAUDR, RSVD_BAUDR, 16, 16, RO, (uint32_t)0x0);

/* ********* SPI TXFTLR ***********
 *
 * Register of SEDI SPI
 *   TXFTLR: Transmit FIFO Threshold Level
 *     AddressOffset  : 0x18
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, TXFTLR, 0x18, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register TXFTLR
 *   TFT:
 *     BitOffset : 0
 *     BitWidth  : 6
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, TXFTLR, TFT, 0, 6, RW, (uint32_t)0x0);

/*
 * Bit Field of Register TXFTLR
 *   RSVD_TXFTLR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, TXFTLR, RSVD_TXFTLR, 6, 26, RO, (uint32_t)0x0);

/* ********* SPI RXFTLR ***********
 *
 * Register of SEDI SPI
 *   RXFTLR: Receive FIFO Threshold Level
 *     AddressOffset  : 0x1c
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, RXFTLR, 0x1c, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register RXFTLR
 *   RFT:
 *     BitOffset : 0
 *     BitWidth  : 6
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RXFTLR, RFT, 0, 6, RW, (uint32_t)0x0);

/*
 * Bit Field of Register RXFTLR
 *   RSVD_RXFTLR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RXFTLR, RSVD_RXFTLR, 6, 26, RO, (uint32_t)0x0);

/* ********* SPI TXFLR ***********
 *
 * Register of SEDI SPI
 *   TXFLR: Transmit FIFO Level Register
 *     AddressOffset  : 0x20
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, TXFLR, 0x20, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register TXFLR
 *   TXTFL:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, TXFLR, TXTFL, 0, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register TXFLR
 *   RSVD_TXFLR:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, TXFLR, RSVD_TXFLR, 7, 25, RO, (uint32_t)0x0);

/* ********* SPI RXFLR ***********
 *
 * Register of SEDI SPI
 *   RXFLR: Receive FIFO Level Register
 *     AddressOffset  : 0x24
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, RXFLR, 0x24, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RXFLR
 *   RXTFL:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RXFLR, RXTFL, 0, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RXFLR
 *   RSVD_RXFLR:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RXFLR, RSVD_RXFLR, 7, 25, RO, (uint32_t)0x0);

/* ********* SPI SR ***********
 *
 * Register of SEDI SPI
 *   SR: Status Register
 *     AddressOffset  : 0x28
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x6
 */
SEDI_REG_DEFINE(SPI, SR, 0x28, RO, (uint32_t)0x0, (uint32_t)0x6);

/*
 * Bit Field of Register SR
 *   BUSY:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SR, BUSY, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, SR, BUSY, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, SR, BUSY, INACTIVE, 0x0);

/*
 * Bit Field of Register SR
 *   TFNF:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, SR, TFNF, 1, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, SR, TFNF, FULL, 0x0);
SEDI_RBFV_DEFINE(SPI, SR, TFNF, NOT_FULL, 0x1);

/*
 * Bit Field of Register SR
 *   TFE:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, SR, TFE, 2, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, SR, TFE, EMPTY, 0x1);
SEDI_RBFV_DEFINE(SPI, SR, TFE, NOT_EMPTY, 0x0);

/*
 * Bit Field of Register SR
 *   RFNE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SR, RFNE, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, SR, RFNE, EMPTY, 0x0);
SEDI_RBFV_DEFINE(SPI, SR, RFNE, NOT_EMPTY, 0x1);

/*
 * Bit Field of Register SR
 *   RFF:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SR, RFF, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, SR, RFF, FULL, 0x1);
SEDI_RBFV_DEFINE(SPI, SR, RFF, NOT_FULL, 0x0);

/*
 * Bit Field of Register SR
 *   RSVD_TXE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SR, RSVD_TXE, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, SR, RSVD_TXE, 0, 0);
SEDI_RBFV_DEFINE(SPI, SR, RSVD_TXE, 1, 1);

/*
 * Bit Field of Register SR
 *   DCOL:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SR, DCOL, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, SR, DCOL, NO_ERROR_CONDITION, 0x0);
SEDI_RBFV_DEFINE(SPI, SR, DCOL, TX_COLLISION_ERROR, 0x1);

/*
 * Bit Field of Register SR
 *   RSVD_SR:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, SR, RSVD_SR, 7, 25, RO, (uint32_t)0x0);

/* ********* SPI IMR ***********
 *
 * Register of SEDI SPI
 *   IMR: Interrupt Mask Register
 *     AddressOffset  : 0x2c
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x3f
 */
SEDI_REG_DEFINE(SPI, IMR, 0x2c, RW, (uint32_t)0x3f, (uint32_t)0x3f);

/*
 * Bit Field of Register IMR
 *   TXEIM:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, IMR, TXEIM, 0, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, IMR, TXEIM, MASKED, 0x0);
SEDI_RBFV_DEFINE(SPI, IMR, TXEIM, UNMASKED, 0x1);

/*
 * Bit Field of Register IMR
 *   TXOIM:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, IMR, TXOIM, 1, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, IMR, TXOIM, MASKED, 0x0);
SEDI_RBFV_DEFINE(SPI, IMR, TXOIM, UNMASKED, 0x1);

/*
 * Bit Field of Register IMR
 *   RXUIM:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, IMR, RXUIM, 2, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, IMR, RXUIM, MASKED, 0x0);
SEDI_RBFV_DEFINE(SPI, IMR, RXUIM, UNMASKED, 0x1);

/*
 * Bit Field of Register IMR
 *   RXOIM:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, IMR, RXOIM, 3, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, IMR, RXOIM, MASKED, 0x0);
SEDI_RBFV_DEFINE(SPI, IMR, RXOIM, UNMASKED, 0x1);

/*
 * Bit Field of Register IMR
 *   RXFIM:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, IMR, RXFIM, 4, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, IMR, RXFIM, MASKED, 0x0);
SEDI_RBFV_DEFINE(SPI, IMR, RXFIM, UNMASKED, 0x1);

/*
 * Bit Field of Register IMR
 *   MSTIM:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(SPI, IMR, MSTIM, 5, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(SPI, IMR, MSTIM, MASKED, 0x0);
SEDI_RBFV_DEFINE(SPI, IMR, MSTIM, UNMASKED, 0x1);

/*
 * Bit Field of Register IMR
 *   RSVD_IMR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, IMR, RSVD_IMR, 6, 26, RO, (uint32_t)0x0);

/* ********* SPI ISR ***********
 *
 * Register of SEDI SPI
 *   ISR: Interrupt Status Register
 *     AddressOffset  : 0x30
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, ISR, 0x30, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ISR
 *   TXEIS:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ISR, TXEIS, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, ISR, TXEIS, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, ISR, TXEIS, INACTIVE, 0x0);

/*
 * Bit Field of Register ISR
 *   TXOIS:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ISR, TXOIS, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, ISR, TXOIS, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, ISR, TXOIS, INACTIVE, 0x0);

/*
 * Bit Field of Register ISR
 *   RXUIS:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ISR, RXUIS, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, ISR, RXUIS, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, ISR, RXUIS, INACTIVE, 0x0);

/*
 * Bit Field of Register ISR
 *   RXOIS:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ISR, RXOIS, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, ISR, RXOIS, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, ISR, RXOIS, INACTIVE, 0x0);

/*
 * Bit Field of Register ISR
 *   RXFIS:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ISR, RXFIS, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, ISR, RXFIS, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, ISR, RXFIS, INACTIVE, 0x0);

/*
 * Bit Field of Register ISR
 *   MSTIS:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ISR, MSTIS, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, ISR, MSTIS, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, ISR, MSTIS, INACTIVE, 0x0);

/*
 * Bit Field of Register ISR
 *   RSVD_ISR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ISR, RSVD_ISR, 6, 26, RO, (uint32_t)0x0);

/* ********* SPI RISR ***********
 *
 * Register of SEDI SPI
 *   RISR: Raw Interrupt Status Register
 *     AddressOffset  : 0x34
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, RISR, 0x34, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RISR
 *   TXEIR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RISR, TXEIR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, RISR, TXEIR, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, RISR, TXEIR, INACTIVE, 0x0);

/*
 * Bit Field of Register RISR
 *   TXOIR:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RISR, TXOIR, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, RISR, TXOIR, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, RISR, TXOIR, INACTIVE, 0x0);

/*
 * Bit Field of Register RISR
 *   RXUIR:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RISR, RXUIR, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, RISR, RXUIR, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, RISR, RXUIR, INACTIVE, 0x0);

/*
 * Bit Field of Register RISR
 *   RXOIR:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RISR, RXOIR, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, RISR, RXOIR, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, RISR, RXOIR, INACTIVE, 0x0);

/*
 * Bit Field of Register RISR
 *   RXFIR:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RISR, RXFIR, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, RISR, RXFIR, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, RISR, RXFIR, INACTIVE, 0x0);

/*
 * Bit Field of Register RISR
 *   MSTIR:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RISR, MSTIR, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, RISR, MSTIR, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(SPI, RISR, MSTIR, INACTIVE, 0x0);

/*
 * Bit Field of Register RISR
 *   RSVD_RISR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RISR, RSVD_RISR, 6, 26, RO, (uint32_t)0x0);

/* ********* SPI TXOICR ***********
 *
 * Register of SEDI SPI
 *   TXOICR: Transmit FIFO Overflow Interrupt Clear Register
 *     AddressOffset  : 0x38
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, TXOICR, 0x38, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register TXOICR
 *   TXOICR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, TXOICR, TXOICR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, TXOICR, TXOICR, 0, 0);
SEDI_RBFV_DEFINE(SPI, TXOICR, TXOICR, 1, 1);

/*
 * Bit Field of Register TXOICR
 *   RSVD_TXOICR:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, TXOICR, RSVD_TXOICR, 1, 31, RO, (uint32_t)0x0);

/* ********* SPI RXOICR ***********
 *
 * Register of SEDI SPI
 *   RXOICR: Receive FIFO Overflow Interrupt Clear Register
 *     AddressOffset  : 0x3c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, RXOICR, 0x3c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RXOICR
 *   RXOICR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RXOICR, RXOICR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, RXOICR, RXOICR, 0, 0);
SEDI_RBFV_DEFINE(SPI, RXOICR, RXOICR, 1, 1);

/*
 * Bit Field of Register RXOICR
 *   RSVD_RXOICR:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RXOICR, RSVD_RXOICR, 1, 31, RO, (uint32_t)0x0);

/* ********* SPI RXUICR ***********
 *
 * Register of SEDI SPI
 *   RXUICR: Receive FIFO Underflow Interrupt Clear Register
 *     AddressOffset  : 0x40
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, RXUICR, 0x40, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RXUICR
 *   RXUICR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RXUICR, RXUICR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, RXUICR, RXUICR, 0, 0);
SEDI_RBFV_DEFINE(SPI, RXUICR, RXUICR, 1, 1);

/*
 * Bit Field of Register RXUICR
 *   RSVD_RXUICR:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RXUICR, RSVD_RXUICR, 1, 31, RO, (uint32_t)0x0);

/* ********* SPI MSTICR ***********
 *
 * Register of SEDI SPI
 *   MSTICR: Multi-Master Interrupt Clear Register
 *     AddressOffset  : 0x44
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, MSTICR, 0x44, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register MSTICR
 *   MSTICR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, MSTICR, MSTICR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, MSTICR, MSTICR, 0, 0);
SEDI_RBFV_DEFINE(SPI, MSTICR, MSTICR, 1, 1);

/*
 * Bit Field of Register MSTICR
 *   RSVD_MSTICR:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, MSTICR, RSVD_MSTICR, 1, 31, RO, (uint32_t)0x0);

/* ********* SPI ICR ***********
 *
 * Register of SEDI SPI
 *   ICR: Interrupt Clear Register
 *     AddressOffset  : 0x48
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, ICR, 0x48, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register ICR
 *   ICR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ICR, ICR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, ICR, ICR, 0, 0);
SEDI_RBFV_DEFINE(SPI, ICR, ICR, 1, 1);

/*
 * Bit Field of Register ICR
 *   RSVD_ICR:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, ICR, RSVD_ICR, 1, 31, RO, (uint32_t)0x0);

/* ********* SPI DMACR ***********
 *
 * Register of SEDI SPI
 *   DMACR: DMA Control Register
 *     AddressOffset  : 0x4c
 *     AccessType     : RW
 *     WritableBitMask: 0x3
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DMACR, 0x4c, RW, (uint32_t)0x3, (uint32_t)0x0);

/*
 * Bit Field of Register DMACR
 *   RDMAE:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DMACR, RDMAE, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, DMACR, RDMAE, DISABLE, 0x0);
SEDI_RBFV_DEFINE(SPI, DMACR, RDMAE, ENABLED, 0x1);

/*
 * Bit Field of Register DMACR
 *   TDMAE:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DMACR, TDMAE, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(SPI, DMACR, TDMAE, DISABLE, 0x0);
SEDI_RBFV_DEFINE(SPI, DMACR, TDMAE, ENABLED, 0x1);

/*
 * Bit Field of Register DMACR
 *   RSVD_DMACR:
 *     BitOffset : 2
 *     BitWidth  : 30
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DMACR, RSVD_DMACR, 2, 30, RO, (uint32_t)0x0);

/* ********* SPI DMATDLR ***********
 *
 * Register of SEDI SPI
 *   DMATDLR: DMA Transmit Data Level
 *     AddressOffset  : 0x50
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DMATDLR, 0x50, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register DMATDLR
 *   DMATDL:
 *     BitOffset : 0
 *     BitWidth  : 6
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DMATDLR, DMATDL, 0, 6, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DMATDLR
 *   RSVD_DMATDLR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DMATDLR, RSVD_DMATDLR, 6, 26, RO, (uint32_t)0x0);

/* ********* SPI DMARDLR ***********
 *
 * Register of SEDI SPI
 *   DMARDLR: DMA Receive Data Level
 *     AddressOffset  : 0x54
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DMARDLR, 0x54, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register DMARDLR
 *   DMARDL:
 *     BitOffset : 0
 *     BitWidth  : 6
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DMARDLR, DMARDL, 0, 6, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DMARDLR
 *   RSVD_DMARDLR:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DMARDLR, RSVD_DMARDLR, 6, 26, RO, (uint32_t)0x0);

/* ********* SPI IDR ***********
 *
 * Register of SEDI SPI
 *   IDR: Identification Register
 *     AddressOffset  : 0x58
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)-1
 */
SEDI_REG_DEFINE(SPI, IDR, 0x58, RO, (uint32_t)0x0, (uint32_t)-1);

/*
 * Bit Field of Register IDR
 *   IDCODE:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)-1
 */
SEDI_RBF_DEFINE(SPI, IDR, IDCODE, 0, 32, RO, (uint32_t)-1);

/* ********* SPI SSI_VERSION_ID ***********
 *
 * Register of SEDI SPI
 *   SSI_VERSION_ID: coreKit version ID Register
 *     AddressOffset  : 0x5c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x3430332a
 */
SEDI_REG_DEFINE(SPI, SSI_VERSION_ID, 0x5c, RO, (uint32_t)0x0, (uint32_t)0x3430332a);

/*
 * Bit Field of Register SSI_VERSION_ID
 *   SSI_COMP_VERSION:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3430332a
 */
SEDI_RBF_DEFINE(SPI, SSI_VERSION_ID, SSI_COMP_VERSION, 0, 32, RO, (uint32_t)0x3430332a);

/* ********* SPI DR0 ***********
 *
 * Register of SEDI SPI
 *   DR0: Data Register x
 *     AddressOffset  : 0x60
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR0, 0x60, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR0
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR0, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR1 ***********
 *
 * Register of SEDI SPI
 *   DR1: Data Register x
 *     AddressOffset  : 0x64
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR1, 0x64, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR1
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR1, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR2 ***********
 *
 * Register of SEDI SPI
 *   DR2: Data Register x
 *     AddressOffset  : 0x68
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR2, 0x68, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR2
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR2, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR3 ***********
 *
 * Register of SEDI SPI
 *   DR3: Data Register x
 *     AddressOffset  : 0x6c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR3, 0x6c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR3
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR3, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR4 ***********
 *
 * Register of SEDI SPI
 *   DR4: Data Register x
 *     AddressOffset  : 0x70
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR4, 0x70, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR4
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR4, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR5 ***********
 *
 * Register of SEDI SPI
 *   DR5: Data Register x
 *     AddressOffset  : 0x74
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR5, 0x74, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR5
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR5, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR6 ***********
 *
 * Register of SEDI SPI
 *   DR6: Data Register x
 *     AddressOffset  : 0x78
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR6, 0x78, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR6
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR6, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR7 ***********
 *
 * Register of SEDI SPI
 *   DR7: Data Register x
 *     AddressOffset  : 0x7c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR7, 0x7c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR7
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR7, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR8 ***********
 *
 * Register of SEDI SPI
 *   DR8: Data Register x
 *     AddressOffset  : 0x80
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR8, 0x80, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR8
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR8, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR9 ***********
 *
 * Register of SEDI SPI
 *   DR9: Data Register x
 *     AddressOffset  : 0x84
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR9, 0x84, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR9
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR9, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR10 ***********
 *
 * Register of SEDI SPI
 *   DR10: Data Register x
 *     AddressOffset  : 0x88
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR10, 0x88, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR10
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR10, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR11 ***********
 *
 * Register of SEDI SPI
 *   DR11: Data Register x
 *     AddressOffset  : 0x8c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR11, 0x8c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR11
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR11, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR12 ***********
 *
 * Register of SEDI SPI
 *   DR12: Data Register x
 *     AddressOffset  : 0x90
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR12, 0x90, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR12
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR12, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR13 ***********
 *
 * Register of SEDI SPI
 *   DR13: Data Register x
 *     AddressOffset  : 0x94
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR13, 0x94, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR13
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR13, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR14 ***********
 *
 * Register of SEDI SPI
 *   DR14: Data Register x
 *     AddressOffset  : 0x98
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR14, 0x98, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR14
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR14, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR15 ***********
 *
 * Register of SEDI SPI
 *   DR15: Data Register x
 *     AddressOffset  : 0x9c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR15, 0x9c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR15
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR15, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR16 ***********
 *
 * Register of SEDI SPI
 *   DR16: Data Register x
 *     AddressOffset  : 0xa0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR16, 0xa0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR16
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR16, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR17 ***********
 *
 * Register of SEDI SPI
 *   DR17: Data Register x
 *     AddressOffset  : 0xa4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR17, 0xa4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR17
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR17, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR18 ***********
 *
 * Register of SEDI SPI
 *   DR18: Data Register x
 *     AddressOffset  : 0xa8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR18, 0xa8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR18
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR18, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR19 ***********
 *
 * Register of SEDI SPI
 *   DR19: Data Register x
 *     AddressOffset  : 0xac
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR19, 0xac, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR19
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR19, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR20 ***********
 *
 * Register of SEDI SPI
 *   DR20: Data Register x
 *     AddressOffset  : 0xb0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR20, 0xb0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR20
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR20, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR21 ***********
 *
 * Register of SEDI SPI
 *   DR21: Data Register x
 *     AddressOffset  : 0xb4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR21, 0xb4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR21
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR21, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR22 ***********
 *
 * Register of SEDI SPI
 *   DR22: Data Register x
 *     AddressOffset  : 0xb8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR22, 0xb8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR22
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR22, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR23 ***********
 *
 * Register of SEDI SPI
 *   DR23: Data Register x
 *     AddressOffset  : 0xbc
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR23, 0xbc, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR23
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR23, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR24 ***********
 *
 * Register of SEDI SPI
 *   DR24: Data Register x
 *     AddressOffset  : 0xc0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR24, 0xc0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR24
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR24, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR25 ***********
 *
 * Register of SEDI SPI
 *   DR25: Data Register x
 *     AddressOffset  : 0xc4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR25, 0xc4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR25
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR25, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR26 ***********
 *
 * Register of SEDI SPI
 *   DR26: Data Register x
 *     AddressOffset  : 0xc8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR26, 0xc8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR26
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR26, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR27 ***********
 *
 * Register of SEDI SPI
 *   DR27: Data Register x
 *     AddressOffset  : 0xcc
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR27, 0xcc, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR27
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR27, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR28 ***********
 *
 * Register of SEDI SPI
 *   DR28: Data Register x
 *     AddressOffset  : 0xd0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR28, 0xd0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR28
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR28, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR29 ***********
 *
 * Register of SEDI SPI
 *   DR29: Data Register x
 *     AddressOffset  : 0xd4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR29, 0xd4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR29
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR29, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR30 ***********
 *
 * Register of SEDI SPI
 *   DR30: Data Register x
 *     AddressOffset  : 0xd8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR30, 0xd8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR30
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR30, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR31 ***********
 *
 * Register of SEDI SPI
 *   DR31: Data Register x
 *     AddressOffset  : 0xdc
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR31, 0xdc, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR31
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR31, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR32 ***********
 *
 * Register of SEDI SPI
 *   DR32: Data Register x
 *     AddressOffset  : 0xe0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR32, 0xe0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR32
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR32, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR33 ***********
 *
 * Register of SEDI SPI
 *   DR33: Data Register x
 *     AddressOffset  : 0xe4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR33, 0xe4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR33
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR33, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR34 ***********
 *
 * Register of SEDI SPI
 *   DR34: Data Register x
 *     AddressOffset  : 0xe8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR34, 0xe8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR34
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR34, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI DR35 ***********
 *
 * Register of SEDI SPI
 *   DR35: Data Register x
 *     AddressOffset  : 0xec
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, DR35, 0xec, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register DR35
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, DR35, DR, 0, 32, RW, (uint32_t)0x0);

/* ********* SPI RX_SAMPLE_DLY ***********
 *
 * Register of SEDI SPI
 *   RX_SAMPLE_DLY: RX Sample Delay Register
 *     AddressOffset  : 0xf0
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, RX_SAMPLE_DLY, 0xf0, RW, (uint32_t)0xff, (uint32_t)0x0);

/*
 * Bit Field of Register RX_SAMPLE_DLY
 *   RSD:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RX_SAMPLE_DLY, RSD, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register RX_SAMPLE_DLY
 *   RSVD_RX_SAMPLE_DLY:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RX_SAMPLE_DLY, RSVD_RX_SAMPLE_DLY, 8, 24, RO, (uint32_t)0x0);

/* ********* SPI RSVD ***********
 *
 * Register of SEDI SPI
 *   RSVD: RSVD - Reserved address location
 *     AddressOffset  : 0xfc
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(SPI, RSVD, 0xfc, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RSVD
 *   RSVD:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(SPI, RSVD, RSVD, 0, 32, RO, (uint32_t)0x0);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* Control Register 0 */
	__IO_RW uint32_t ctrlr0;

	/* Control Register 1 */
	__IO_RW uint32_t ctrlr1;

	/* SSI Enable Register */
	__IO_RW uint32_t ssienr;

	/* Microwire Control Register */
	__IO_RW uint32_t mwcr;

	/* Slave Enable Register */
	__IO_RW uint32_t ser;

	/* Baud Rate Select */
	__IO_RW uint32_t baudr;

	/* Transmit FIFO Threshold Level */
	__IO_RW uint32_t txftlr;

	/* Receive FIFO Threshold Level */
	__IO_RW uint32_t rxftlr;

	/* Transmit FIFO Level Register */
	__IO_R uint32_t txflr;

	/* Receive FIFO Level Register */
	__IO_R uint32_t rxflr;

	/* Status Register */
	__IO_R uint32_t sr;

	/* Interrupt Mask Register */
	__IO_RW uint32_t imr;

	/* Interrupt Status Register */
	__IO_R uint32_t isr;

	/* Raw Interrupt Status Register */
	__IO_R uint32_t risr;

	/* Transmit FIFO Overflow Interrupt Clear Register */
	__IO_R uint32_t txoicr;

	/* Receive FIFO Overflow Interrupt Clear Register */
	__IO_R uint32_t rxoicr;

	/* Receive FIFO Underflow Interrupt Clear Register */
	__IO_R uint32_t rxuicr;

	/* Multi-Master Interrupt Clear Register */
	__IO_R uint32_t msticr;

	/* Interrupt Clear Register */
	__IO_R uint32_t icr;

	/* DMA Control Register */
	__IO_RW uint32_t dmacr;

	/* DMA Transmit Data Level */
	__IO_RW uint32_t dmatdlr;

	/* DMA Receive Data Level */
	__IO_RW uint32_t dmardlr;

	/* Identification Register */
	__IO_R uint32_t idr;

	/* coreKit version ID Register */
	__IO_R uint32_t ssi_version_id;

	/* Data Register x */
	__IO_RW uint32_t dr0;

	/* Data Register x */
	__IO_RW uint32_t dr1;

	/* Data Register x */
	__IO_RW uint32_t dr2;

	/* Data Register x */
	__IO_RW uint32_t dr3;

	/* Data Register x */
	__IO_RW uint32_t dr4;

	/* Data Register x */
	__IO_RW uint32_t dr5;

	/* Data Register x */
	__IO_RW uint32_t dr6;

	/* Data Register x */
	__IO_RW uint32_t dr7;

	/* Data Register x */
	__IO_RW uint32_t dr8;

	/* Data Register x */
	__IO_RW uint32_t dr9;

	/* Data Register x */
	__IO_RW uint32_t dr10;

	/* Data Register x */
	__IO_RW uint32_t dr11;

	/* Data Register x */
	__IO_RW uint32_t dr12;

	/* Data Register x */
	__IO_RW uint32_t dr13;

	/* Data Register x */
	__IO_RW uint32_t dr14;

	/* Data Register x */
	__IO_RW uint32_t dr15;

	/* Data Register x */
	__IO_RW uint32_t dr16;

	/* Data Register x */
	__IO_RW uint32_t dr17;

	/* Data Register x */
	__IO_RW uint32_t dr18;

	/* Data Register x */
	__IO_RW uint32_t dr19;

	/* Data Register x */
	__IO_RW uint32_t dr20;

	/* Data Register x */
	__IO_RW uint32_t dr21;

	/* Data Register x */
	__IO_RW uint32_t dr22;

	/* Data Register x */
	__IO_RW uint32_t dr23;

	/* Data Register x */
	__IO_RW uint32_t dr24;

	/* Data Register x */
	__IO_RW uint32_t dr25;

	/* Data Register x */
	__IO_RW uint32_t dr26;

	/* Data Register x */
	__IO_RW uint32_t dr27;

	/* Data Register x */
	__IO_RW uint32_t dr28;

	/* Data Register x */
	__IO_RW uint32_t dr29;

	/* Data Register x */
	__IO_RW uint32_t dr30;

	/* Data Register x */
	__IO_RW uint32_t dr31;

	/* Data Register x */
	__IO_RW uint32_t dr32;

	/* Data Register x */
	__IO_RW uint32_t dr33;

	/* Data Register x */
	__IO_RW uint32_t dr34;

	/* Data Register x */
	__IO_RW uint32_t dr35;

	/* RX Sample Delay Register */
	__IO_RW uint32_t rx_sample_dly;

	/* Reserved */
	__IO_RW uint32_t reserved0[2];

	/* RSVD - Reserved address location */
	__IO_R uint32_t rsvd;

} sedi_spi_regs_t;


#endif /* _SEDI_SPI_REGS_H_ */
