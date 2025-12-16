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

#ifndef _SEDI_DMA_REGS_H_
#define _SEDI_DMA_REGS_H_

#include <sedi_reg_defs.h>

/* ********* DMA SAR ***********
 *
 * Register of SEDI DMA
 *   SAR: DW_axi_dmac Channel x Source Address Register
 *     AddressOffset  : 0x0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffffffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, SAR, 0x0, RW, (uint64_t)0xffffffffffffffff, (uint64_t)0x0);

/*
 * Bit Field of Register SAR
 *   SAR:
 *     BitOffset : 0
 *     BitWidth  : 64
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SAR, SAR, 0, 64, RW, (uint64_t)0x0);

/* ********* DMA DAR ***********
 *
 * Register of SEDI DMA
 *   DAR: DW_axi_dmac Channel x Destination Address Register
 *     AddressOffset  : 0x8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffffffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, DAR, 0x8, RW, (uint64_t)0xffffffffffffffff, (uint64_t)0x0);

/*
 * Bit Field of Register DAR
 *   DAR:
 *     BitOffset : 0
 *     BitWidth  : 64
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, DAR, DAR, 0, 64, RW, (uint64_t)0x0);

/* ********* DMA BLOCK_TS ***********
 *
 * Register of SEDI DMA
 *   BLOCK_TS: DW_axi_dmac Channel x Block Transfer Size Register
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x3fffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, BLOCK_TS, 0x10, RW, (uint64_t)0x3fffff, (uint64_t)0x0);

/*
 * Bit Field of Register BLOCK_TS
 *   BLOCK_TS:
 *     BitOffset : 0
 *     BitWidth  : 22
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, BLOCK_TS, BLOCK_TS, 0, 22, RW, (uint64_t)0x0);

/*
 * Bit Field of Register BLOCK_TS
 *   RSVD_DMAC_CHx_BLOCK_TSREG_63to22:
 *     BitOffset : 22
 *     BitWidth  : 42
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, BLOCK_TS, RSVD_DMAC_CHx_BLOCK_TSREG_63to22, 22, 42, RO, (uint64_t)0x0);

/* ********* DMA CTL ***********
 *
 * Register of SEDI DMA
 *   CTL: DW_axi_dmac Channel x Control Register
 *     AddressOffset  : 0x18
 *     AccessType     : RW
 *     WritableBitMask: 0xc7ffffff7fffff50
 *     ResetValue     : (uint64_t)0x1200
 */
SEDI_REG_DEFINE(DMA, CTL, 0x18, RW, (uint64_t)0xc7ffffff7fffff50, (uint64_t)0x1200);

/*
 * Bit Field of Register CTL
 *   SMS:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, SMS, 0, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, SMS, MASTER1_INTF, 0x0);
SEDI_RBFV_DEFINE(DMA, CTL, SMS, MASTER2_INTF, 0x1);

/*
 * Bit Field of Register CTL
 *   RSVD_DMAC_CHx_CTL_1:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_1, 1, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_1, 0, 0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_1, 1, 1);

/*
 * Bit Field of Register CTL
 *   DMS:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, DMS, 2, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, DMS, MASTER1_INTF, 0x0);
SEDI_RBFV_DEFINE(DMA, CTL, DMS, MASTER2_INTF, 0x1);

/*
 * Bit Field of Register CTL
 *   RSVD_DMAC_CHx_CTL_3:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_3, 3, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_3, 0, 0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_3, 1, 1);

/*
 * Bit Field of Register CTL
 *   SINC:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, SINC, 4, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, SINC, FIXED, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, SINC, INCREMENTAL, 0x0);

/*
 * Bit Field of Register CTL
 *   RSVD_DMAC_CHx_CTL_5:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_5, 5, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_5, 0, 0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_5, 1, 1);

/*
 * Bit Field of Register CTL
 *   DINC:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, DINC, 6, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, DINC, FIXED, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, DINC, INCREMENTAL, 0x0);

/*
 * Bit Field of Register CTL
 *   RSVD_DMAC_CHx_CTL_7:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_7, 7, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_7, 0, 0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_7, 1, 1);

/*
 * Bit Field of Register CTL
 *   SRC_TR_WIDTH:
 *     BitOffset : 8
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x2
 */
SEDI_RBF_DEFINE(DMA, CTL, SRC_TR_WIDTH, 8, 3, RW, (uint64_t)0x2);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_TR_WIDTH, BITS_128, 0x4);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_TR_WIDTH, BITS_16, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_TR_WIDTH, BITS_256, 0x5);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_TR_WIDTH, BITS_32, 0x2);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_TR_WIDTH, BITS_512, 0x6);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_TR_WIDTH, BITS_64, 0x3);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_TR_WIDTH, BITS_8, 0x0);

/*
 * Bit Field of Register CTL
 *   DST_TR_WIDTH:
 *     BitOffset : 11
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x2
 */
SEDI_RBF_DEFINE(DMA, CTL, DST_TR_WIDTH, 11, 3, RW, (uint64_t)0x2);
SEDI_RBFV_DEFINE(DMA, CTL, DST_TR_WIDTH, BITS_128, 0x4);
SEDI_RBFV_DEFINE(DMA, CTL, DST_TR_WIDTH, BITS_16, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, DST_TR_WIDTH, BITS_256, 0x5);
SEDI_RBFV_DEFINE(DMA, CTL, DST_TR_WIDTH, BITS_32, 0x2);
SEDI_RBFV_DEFINE(DMA, CTL, DST_TR_WIDTH, BITS_512, 0x6);
SEDI_RBFV_DEFINE(DMA, CTL, DST_TR_WIDTH, BITS_64, 0x3);
SEDI_RBFV_DEFINE(DMA, CTL, DST_TR_WIDTH, BITS_8, 0x0);

/*
 * Bit Field of Register CTL
 *   SRC_MSIZE:
 *     BitOffset : 14
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, SRC_MSIZE, 14, 4, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_1024, 0x9);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_128, 0x6);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_16, 0x3);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_256, 0x7);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_32, 0x4);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_4, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_512, 0x8);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_64, 0x5);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEMS_8, 0x2);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_MSIZE, DATA_ITEM_1, 0x0);

/*
 * Bit Field of Register CTL
 *   DST_MSIZE:
 *     BitOffset : 18
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, DST_MSIZE, 18, 4, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_1024, 0x9);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_128, 0x6);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_16, 0x3);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_256, 0x7);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_32, 0x4);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_4, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_512, 0x8);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_64, 0x5);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEMS_8, 0x2);
SEDI_RBFV_DEFINE(DMA, CTL, DST_MSIZE, DATA_ITEM_1, 0x0);

/*
 * Bit Field of Register CTL
 *   AR_CACHE:
 *     BitOffset : 22
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, AR_CACHE, 22, 4, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CTL
 *   AW_CACHE:
 *     BitOffset : 26
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, AW_CACHE, 26, 4, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CTL
 *   NonPosted_LastWrite_En:
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, NonPosted_LastWrite_En, 30, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, NonPosted_LastWrite_En, Disable, 0x0);
SEDI_RBFV_DEFINE(DMA, CTL, NonPosted_LastWrite_En, Enable, 0x1);

/*
 * Bit Field of Register CTL
 *   RSVD_DMAC_CHx_CTL_31:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_31, 31, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_31, 0, 0);
SEDI_RBFV_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_31, 1, 1);

/*
 * Bit Field of Register CTL
 *   AR_PROT:
 *     BitOffset : 32
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, AR_PROT, 32, 3, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CTL
 *   AW_PROT:
 *     BitOffset : 35
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, AW_PROT, 35, 3, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CTL
 *   ARLEN_EN:
 *     BitOffset : 38
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, ARLEN_EN, 38, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, ARLEN_EN, Disable, 0x0);
SEDI_RBFV_DEFINE(DMA, CTL, ARLEN_EN, Enable, 0x1);

/*
 * Bit Field of Register CTL
 *   ARLEN:
 *     BitOffset : 39
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, ARLEN, 39, 8, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CTL
 *   AWLEN_EN:
 *     BitOffset : 47
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, AWLEN_EN, 47, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, AWLEN_EN, Disable, 0x0);
SEDI_RBFV_DEFINE(DMA, CTL, AWLEN_EN, Enable, 0x1);

/*
 * Bit Field of Register CTL
 *   AWLEN:
 *     BitOffset : 48
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, AWLEN, 48, 8, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CTL
 *   SRC_STAT_EN:
 *     BitOffset : 56
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, SRC_STAT_EN, 56, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_STAT_EN, Enable_STAT_FETCH, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, SRC_STAT_EN, NO_STAT_FETCH, 0x0);

/*
 * Bit Field of Register CTL
 *   DST_STAT_EN:
 *     BitOffset : 57
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, DST_STAT_EN, 57, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, DST_STAT_EN, Enable_STAT_FETCH, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, DST_STAT_EN, NO_STAT_FETCH, 0x0);

/*
 * Bit Field of Register CTL
 *   IOC_BlkTfr:
 *     BitOffset : 58
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, IOC_BlkTfr, 58, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, IOC_BlkTfr, DISABLE_BLKTFR_INTR, 0x0);
SEDI_RBFV_DEFINE(DMA, CTL, IOC_BlkTfr, Enable_BLKTFR_INTR, 0x1);

/*
 * Bit Field of Register CTL
 *   RSVD_DMAC_CHx_CTL_59to61:
 *     BitOffset : 59
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, RSVD_DMAC_CHx_CTL_59to61, 59, 3, RO, (uint64_t)0x0);

/*
 * Bit Field of Register CTL
 *   SHADOWREG_OR_LLI_LAST:
 *     BitOffset : 62
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, SHADOWREG_OR_LLI_LAST, 62, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, SHADOWREG_OR_LLI_LAST, LAST_ITEM, 0x1);
SEDI_RBFV_DEFINE(DMA, CTL, SHADOWREG_OR_LLI_LAST, NOT_LAST_ITEM, 0x0);

/*
 * Bit Field of Register CTL
 *   SHADOWREG_OR_LLI_VALID:
 *     BitOffset : 63
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CTL, SHADOWREG_OR_LLI_VALID, 63, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CTL, SHADOWREG_OR_LLI_VALID, INVALID, 0x0);
SEDI_RBFV_DEFINE(DMA, CTL, SHADOWREG_OR_LLI_VALID, VALID, 0x1);

/* ********* DMA CFG2 ***********
 *
 * Register of SEDI DMA
 *   CFG2: DW_axi_dmac Channel x Configuration Register 2
 *     AddressOffset  : 0x20
 *     AccessType     : RW
 *     WritableBitMask: 0x7fff801f0000f9ff
 *     ResetValue     : (uint64_t)0x3801b00000000
 */
SEDI_REG_DEFINE(DMA, CFG2, 0x20, RW, (uint64_t)0x7fff801f0000f9ff, (uint64_t)0x3801b00000000);

/*
 * Bit Field of Register CFG2
 *   SRC_MULTBLK_TYPE:
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, SRC_MULTBLK_TYPE, 0, 2, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, SRC_MULTBLK_TYPE, CONTINGUOUS, 0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, SRC_MULTBLK_TYPE, LINKED_LIST, 0x3);
SEDI_RBFV_DEFINE(DMA, CFG2, SRC_MULTBLK_TYPE, RELOAD, 0x1);
SEDI_RBFV_DEFINE(DMA, CFG2, SRC_MULTBLK_TYPE, SHADOW_REGISTER, 0x2);

/*
 * Bit Field of Register CFG2
 *   DST_MULTBLK_TYPE:
 *     BitOffset : 2
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, DST_MULTBLK_TYPE, 2, 2, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, DST_MULTBLK_TYPE, CONTINGUOUS, 0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, DST_MULTBLK_TYPE, LINKED_LIST, 0x3);
SEDI_RBFV_DEFINE(DMA, CFG2, DST_MULTBLK_TYPE, RELOAD, 0x1);
SEDI_RBFV_DEFINE(DMA, CFG2, DST_MULTBLK_TYPE, SHADOW_REGISTER, 0x2);

/*
 * Bit Field of Register CFG2
 *   SRC_PER:
 *     BitOffset : 4
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, SRC_PER, 4, 5, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   RSVD_DMAC_CHx_CFG_9_4:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_9_4, 9, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_9_4, 0, 0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_9_4, 1, 1);

/*
 * Bit Field of Register CFG2
 *   RSVD_DMAC_CHx_CFG_10:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_10, 10, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_10, 0, 0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_10, 1, 1);

/*
 * Bit Field of Register CFG2
 *   DST_PER:
 *     BitOffset : 11
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, DST_PER, 11, 5, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   RSVD_DMAC_CHx_CFG_16_11:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_16_11, 16, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_16_11, 0, 0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_16_11, 1, 1);

/*
 * Bit Field of Register CFG2
 *   RSVD_DMAC_CHx_CFG_17:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_17, 17, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_17, 0, 0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_17, 1, 1);

/*
 * Bit Field of Register CFG2
 *   RD_UID:
 *     BitOffset : 18
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RD_UID, 18, 4, RO, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   RSVD_DMAC_CHx_CFG_22to24:
 *     BitOffset : 22
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_22to24, 22, 3, RO, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   WR_UID:
 *     BitOffset : 25
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, WR_UID, 25, 4, RO, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   RSVD_DMAC_CHx_CFG_29to31:
 *     BitOffset : 29
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_29to31, 29, 3, RO, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   TT_FC:
 *     BitOffset : 32
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x3
 */
SEDI_RBF_DEFINE(DMA, CFG2, TT_FC, 32, 3, RW, (uint64_t)0x3);
SEDI_RBFV_DEFINE(DMA, CFG2, TT_FC, MEM_TO_MEM_DMAC, 0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, TT_FC, MEM_TO_PER_DMAC, 0x1);
SEDI_RBFV_DEFINE(DMA, CFG2, TT_FC, MEM_TO_PER_DST, 0x6);
SEDI_RBFV_DEFINE(DMA, CFG2, TT_FC, PER_TO_MEM_DMAC, 0x2);
SEDI_RBFV_DEFINE(DMA, CFG2, TT_FC, PER_TO_MEM_SRC, 0x4);
SEDI_RBFV_DEFINE(DMA, CFG2, TT_FC, PER_TO_PER_DMAC, 0x3);
SEDI_RBFV_DEFINE(DMA, CFG2, TT_FC, PER_TO_PER_DST, 0x7);
SEDI_RBFV_DEFINE(DMA, CFG2, TT_FC, PER_TO_PER_SRC, 0x5);

/*
 * Bit Field of Register CFG2
 *   HS_SEL_SRC:
 *     BitOffset : 35
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, CFG2, HS_SEL_SRC, 35, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, CFG2, HS_SEL_SRC, HARDWARE_HS, 0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, HS_SEL_SRC, SOFTWARE_HS, 0x1);

/*
 * Bit Field of Register CFG2
 *   HS_SEL_DST:
 *     BitOffset : 36
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, CFG2, HS_SEL_DST, 36, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, CFG2, HS_SEL_DST, HARDWARE_HS, 0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, HS_SEL_DST, SOFTWARE_HS, 0x1);

/*
 * Bit Field of Register CFG2
 *   SRC_HWHS_POL:
 *     BitOffset : 37
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, SRC_HWHS_POL, 37, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, SRC_HWHS_POL, ACTIVE_HIGH, 0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, SRC_HWHS_POL, ACTIVE_LOW, 0x1);

/*
 * Bit Field of Register CFG2
 *   DST_HWHS_POL:
 *     BitOffset : 38
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, DST_HWHS_POL, 38, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, DST_HWHS_POL, ACTIVE_HIGH, 0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, DST_HWHS_POL, ACTIVE_LOW, 0x1);

/*
 * Bit Field of Register CFG2
 *   RSVD_DMAC_CHx_CFG_39to46:
 *     BitOffset : 39
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_39to46, 39, 8, RO, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   CH_PRIOR:
 *     BitOffset : 47
 *     BitWidth  : 5
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x7
 */
SEDI_RBF_DEFINE(DMA, CFG2, CH_PRIOR, 47, 5, RW, (uint64_t)0x7);

/*
 * Bit Field of Register CFG2
 *   LOCK_CH:
 *     BitOffset : 52
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, LOCK_CH, 52, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, LOCK_CH, CHANNEL_LOCK, 0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, LOCK_CH, NO_CHANNEL_LOCK, 0x0);

/*
 * Bit Field of Register CFG2
 *   LOCK_CH_L:
 *     BitOffset : 53
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, LOCK_CH_L, 53, 2, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, LOCK_CH_L, BLOCK_TRANFER_CH_LOCK, 0x1);
SEDI_RBFV_DEFINE(DMA, CFG2, LOCK_CH_L, DMA_transfer_CH_LOCK, 0x0);

/*
 * Bit Field of Register CFG2
 *   SRC_OSR_LMT:
 *     BitOffset : 55
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, SRC_OSR_LMT, 55, 4, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   DST_OSR_LMT:
 *     BitOffset : 59
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, DST_OSR_LMT, 59, 4, RW, (uint64_t)0x0);

/*
 * Bit Field of Register CFG2
 *   RSVD_DMAC_CHx_CFG_63:
 *     BitOffset : 63
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_63, 63, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_63, 0, 0);
SEDI_RBFV_DEFINE(DMA, CFG2, RSVD_DMAC_CHx_CFG_63, 1, 1);

/* ********* DMA LLP ***********
 *
 * Register of SEDI DMA
 *   LLP: DW_axi_dmac Channel x Linked List Pointer Register
 *     AddressOffset  : 0x28
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffffffc0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, LLP, 0x28, RW, (uint64_t)0xffffffffffffffc0, (uint64_t)0x0);

/*
 * Bit Field of Register LLP
 *   LMS:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, LLP, LMS, 0, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, LLP, LMS, MASTER1_INTF, 0x0);
SEDI_RBFV_DEFINE(DMA, LLP, LMS, MASTER2_INTF, 0x1);

/*
 * Bit Field of Register LLP
 *   RSVD_DMAC_CHx_LLP_1to5:
 *     BitOffset : 1
 *     BitWidth  : 5
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, LLP, RSVD_DMAC_CHx_LLP_1to5, 1, 5, RO, (uint64_t)0x0);

/*
 * Bit Field of Register LLP
 *   LOC:
 *     BitOffset : 6
 *     BitWidth  : 58
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, LLP, LOC, 6, 58, RW, (uint64_t)0x0);

/* ********* DMA STATUSREG ***********
 *
 * Register of SEDI DMA
 *   STATUSREG: DW_axi_dmac Channel x Status Register
 *     AddressOffset  : 0x30
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, STATUSREG, 0x30, RO, (uint64_t)0x0, (uint64_t)0x0);

/*
 * Bit Field of Register STATUSREG
 *   CMPLTD_BLK_TFR_SIZE:
 *     BitOffset : 0
 *     BitWidth  : 22
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, STATUSREG, CMPLTD_BLK_TFR_SIZE, 0, 22, RO, (uint64_t)0x0);

/*
 * Bit Field of Register STATUSREG
 *   RSVD_DMAC_CHx_STATUSREG_22to31:
 *     BitOffset : 22
 *     BitWidth  : 10
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, STATUSREG, RSVD_DMAC_CHx_STATUSREG_22to31, 22, 10, RO, (uint64_t)0x0);

/*
 * Bit Field of Register STATUSREG
 *   DATA_LEFT_IN_FIFO:
 *     BitOffset : 32
 *     BitWidth  : 15
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, STATUSREG, DATA_LEFT_IN_FIFO, 32, 15, RO, (uint64_t)0x0);

/*
 * Bit Field of Register STATUSREG
 *   RSVD_DMAC_CHx_STATUSREG_47to63:
 *     BitOffset : 47
 *     BitWidth  : 17
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, STATUSREG, RSVD_DMAC_CHx_STATUSREG_47to63, 47, 17, RO, (uint64_t)0x0);

/* ********* DMA SWHSSRCREG ***********
 *
 * Register of SEDI DMA
 *   SWHSSRCREG: DW_axi_dmac Channel x Software Handshake Source Register
 *     AddressOffset  : 0x38
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, SWHSSRCREG, 0x38, RW, (uint64_t)0x3f, (uint64_t)0x0);

/*
 * Bit Field of Register SWHSSRCREG
 *   SWHS_REQ_SRC:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSSRCREG, SWHS_REQ_SRC, 0, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_REQ_SRC, ACTIVE_SWHS_REQ_SRC, 0x1);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_REQ_SRC, INACTIVE_SWHS_REQ_SRC, 0x0);

/*
 * Bit Field of Register SWHSSRCREG
 *   SWHS_REQ_SRC_WE:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSSRCREG, SWHS_REQ_SRC_WE, 1, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_REQ_SRC_WE, DISABLE_SWHS_REQ_SRC, 0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_REQ_SRC_WE, ENABLE_SWHS_REQ_SRC, 0x1);

/*
 * Bit Field of Register SWHSSRCREG
 *   SWHS_SGLREQ_SRC:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSSRCREG, SWHS_SGLREQ_SRC, 2, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_SGLREQ_SRC, ACTIVE_SWHS_SGLREQ_SRC, 0x1);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_SGLREQ_SRC, INACTIVE_SWHS_SGLREQ_SRC, 0x0);

/*
 * Bit Field of Register SWHSSRCREG
 *   SWHS_SGLREQ_SRC_WE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSSRCREG, SWHS_SGLREQ_SRC_WE, 3, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_SGLREQ_SRC_WE, DISABLE_SWHS_SGLREQ_SRC, 0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_SGLREQ_SRC_WE, ENABLE_SWHS_SGLREQ_SRC, 0x1);

/*
 * Bit Field of Register SWHSSRCREG
 *   SWHS_LST_SRC:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSSRCREG, SWHS_LST_SRC, 4, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_LST_SRC, ACTIVE_SWHS_LAST_SRC, 0x1);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_LST_SRC, INACTIVE_SWHS_LAST_SRC, 0x0);

/*
 * Bit Field of Register SWHSSRCREG
 *   SWHS_LST_SRC_WE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSSRCREG, SWHS_LST_SRC_WE, 5, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_LST_SRC_WE, DISABLE_SWHS_LAST_SRC, 0x0);
SEDI_RBFV_DEFINE(DMA, SWHSSRCREG, SWHS_LST_SRC_WE, ENABLE_SWHS_LAST_SRC, 0x1);

/*
 * Bit Field of Register SWHSSRCREG
 *   RSVD_DMAC_CHx_SWHSSRCREG_6to63:
 *     BitOffset : 6
 *     BitWidth  : 58
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSSRCREG, RSVD_DMAC_CHx_SWHSSRCREG_6to63, 6, 58, RO, (uint64_t)0x0);

/* ********* DMA SWHSDSTREG ***********
 *
 * Register of SEDI DMA
 *   SWHSDSTREG: DW_axi_dmac Channel x Software Handshake Destination Register
 *     AddressOffset  : 0x40
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, SWHSDSTREG, 0x40, RW, (uint64_t)0x3f, (uint64_t)0x0);

/*
 * Bit Field of Register SWHSDSTREG
 *   SWHS_REQ_DST:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSDSTREG, SWHS_REQ_DST, 0, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_REQ_DST, ACTIVE_SWHS_REQ_DST, 0x1);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_REQ_DST, INACTIVE_SWHS_REQ_DST, 0x0);

/*
 * Bit Field of Register SWHSDSTREG
 *   SWHS_REQ_DST_WE:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSDSTREG, SWHS_REQ_DST_WE, 1, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_REQ_DST_WE, DISABLE_SWHS_REQ_DST, 0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_REQ_DST_WE, ENABLE_SWHS_REQ_DST, 0x1);

/*
 * Bit Field of Register SWHSDSTREG
 *   SWHS_SGLREQ_DST:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSDSTREG, SWHS_SGLREQ_DST, 2, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_SGLREQ_DST, ACTIVE_SWHS_SGLREQ_DST, 0x1);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_SGLREQ_DST, INACTIVE_SWHS_SGLREQ_DST, 0x0);

/*
 * Bit Field of Register SWHSDSTREG
 *   SWHS_SGLREQ_DST_WE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSDSTREG, SWHS_SGLREQ_DST_WE, 3, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_SGLREQ_DST_WE, DISABLE_SWHS_SGLREQ_DST, 0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_SGLREQ_DST_WE, ENABLE_SWHS_SGLREQ_DST, 0x1);

/*
 * Bit Field of Register SWHSDSTREG
 *   SWHS_LST_DST:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSDSTREG, SWHS_LST_DST, 4, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_LST_DST, ACTIVE_SWHS_LAST_DST, 0x1);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_LST_DST, INACTIVE_SWHS_LAST_DST, 0x0);

/*
 * Bit Field of Register SWHSDSTREG
 *   SWHS_LST_DST_WE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSDSTREG, SWHS_LST_DST_WE, 5, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_LST_DST_WE, DISABLE_SWHS_LAST_DST, 0x0);
SEDI_RBFV_DEFINE(DMA, SWHSDSTREG, SWHS_LST_DST_WE, ENABLE_SWHS_LAST_DST, 0x1);

/*
 * Bit Field of Register SWHSDSTREG
 *   RSVD_DMAC_CHx_SWHSDSTREG_6to63:
 *     BitOffset : 6
 *     BitWidth  : 58
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SWHSDSTREG, RSVD_DMAC_CHx_SWHSDSTREG_6to63, 6, 58, RO, (uint64_t)0x0);

/* ********* DMA BLK_TFR_RESUMEREQREG ***********
 *
 * Register of SEDI DMA
 *   BLK_TFR_RESUMEREQREG: DW_axi_dmac Channel x Block Transfer Resume Request Register
 *     AddressOffset  : 0x48
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffffffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, BLK_TFR_RESUMEREQREG, 0x48, RW, (uint64_t)0xffffffffffffffff, (uint64_t)0x0);

/*
 * Bit Field of Register BLK_TFR_RESUMEREQREG
 *   BLK_TFR_RESUMEREQ:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, BLK_TFR_RESUMEREQREG, BLK_TFR_RESUMEREQ, 0, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, BLK_TFR_RESUMEREQREG, BLK_TFR_RESUMEREQ, ACTIVE_BLK_TFR_RESUMEREQ, 0x1);
SEDI_RBFV_DEFINE(DMA, BLK_TFR_RESUMEREQREG, BLK_TFR_RESUMEREQ, INACTIVE_BLK_TFR_RESUMEREQ, 0x0);

/*
 * Bit Field of Register BLK_TFR_RESUMEREQREG
 *   RSVD_DMAC_CHx_BLK_TFR_RESUMEREQREG_1to63:
 *     BitOffset : 1
 *     BitWidth  : 63
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, BLK_TFR_RESUMEREQREG, RSVD_DMAC_CHx_BLK_TFR_RESUMEREQREG_1to63, 1, 63, RW,
		(uint64_t)0x0);

/* ********* DMA AXI_QOSREG ***********
 *
 * Register of SEDI DMA
 *   AXI_QOSREG: DW_axi_dmac Channel x AXI QoS Register
 *     AddressOffset  : 0x58
 *     AccessType     : RW
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, AXI_QOSREG, 0x58, RW, (uint64_t)0x0, (uint64_t)0x0);

/*
 * Bit Field of Register AXI_QOSREG
 *   AXI_AWQOS:
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, AXI_QOSREG, AXI_AWQOS, 0, 4, RO, (uint64_t)0x0);

/*
 * Bit Field of Register AXI_QOSREG
 *   AXI_ARQOS:
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, AXI_QOSREG, AXI_ARQOS, 4, 4, RO, (uint64_t)0x0);

/*
 * Bit Field of Register AXI_QOSREG
 *   RSVD_DMAC_CHx_AXI_QOSREG_8to63:
 *     BitOffset : 8
 *     BitWidth  : 56
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, AXI_QOSREG, RSVD_DMAC_CHx_AXI_QOSREG_8to63, 8, 56, RO, (uint64_t)0x0);

/* ********* DMA SSTAT ***********
 *
 * Register of SEDI DMA
 *   SSTAT: DW_axi_dmac Channel x Source Status Register
 *     AddressOffset  : 0x60
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, SSTAT, 0x60, RO, (uint64_t)0x0, (uint64_t)0x0);

/*
 * Bit Field of Register SSTAT
 *   SSTAT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SSTAT, SSTAT, 0, 32, RO, (uint64_t)0x0);

/*
 * Bit Field of Register SSTAT
 *   RSVD_DMAC_CHx_SSTAT_32to63:
 *     BitOffset : 32
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SSTAT, RSVD_DMAC_CHx_SSTAT_32to63, 32, 32, RO, (uint64_t)0x0);

/* ********* DMA DSTAT ***********
 *
 * Register of SEDI DMA
 *   DSTAT: DW_axi_dmac Channel x Destination Status Register
 *     AddressOffset  : 0x68
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, DSTAT, 0x68, RO, (uint64_t)0x0, (uint64_t)0x0);

/*
 * Bit Field of Register DSTAT
 *   DSTAT:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, DSTAT, DSTAT, 0, 32, RO, (uint64_t)0x0);

/*
 * Bit Field of Register DSTAT
 *   RSVD_DMAC_CHx_DSTAT_32to63:
 *     BitOffset : 32
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, DSTAT, RSVD_DMAC_CHx_DSTAT_32to63, 32, 32, RO, (uint64_t)0x0);

/* ********* DMA SSTATAR ***********
 *
 * Register of SEDI DMA
 *   SSTATAR: DW_axi_dmac Channel x Source Status Fetch Register
 *     AddressOffset  : 0x70
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffffffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, SSTATAR, 0x70, RW, (uint64_t)0xffffffffffffffff, (uint64_t)0x0);

/*
 * Bit Field of Register SSTATAR
 *   SSTATAR:
 *     BitOffset : 0
 *     BitWidth  : 64
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, SSTATAR, SSTATAR, 0, 64, RW, (uint64_t)0x0);

/* ********* DMA DSTATAR ***********
 *
 * Register of SEDI DMA
 *   DSTATAR: DW_axi_dmac Channel x Destination Status Fetch Register
 *     AddressOffset  : 0x78
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffffffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, DSTATAR, 0x78, RW, (uint64_t)0xffffffffffffffff, (uint64_t)0x0);

/*
 * Bit Field of Register DSTATAR
 *   DSTATAR:
 *     BitOffset : 0
 *     BitWidth  : 64
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, DSTATAR, DSTATAR, 0, 64, RW, (uint64_t)0x0);

/* ********* DMA INTSTATUS_ENABLEREG ***********
 *
 * Register of SEDI DMA
 *   INTSTATUS_ENABLEREG: DW_axi_dmac Channel x Interrupt Status Enable Register
 *     AddressOffset  : 0x80
 *     AccessType     : RW
 *     WritableBitMask: 0xf83f7ffb
 *     ResetValue     : (uint64_t)0xffffffffffffffff
 */
SEDI_REG_DEFINE(DMA, INTSTATUS_ENABLEREG, 0x80, RW, (uint64_t)0xf83f7ffb,
		(uint64_t)0xffffffffffffffff);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_BLOCK_TFR_DONE_IntStat:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_BLOCK_TFR_DONE_IntStat, 0, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_BLOCK_TFR_DONE_IntStat, DISABLE_BLOCK_TFR_DONE,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_BLOCK_TFR_DONE_IntStat, ENABLE_BLOCK_TFR_DONE,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_DMA_TFR_DONE_IntStat:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DMA_TFR_DONE_IntStat, 1, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DMA_TFR_DONE_IntStat, DISABLE_DMA_TFR_DONE, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DMA_TFR_DONE_IntStat, ENABLE_DMA_TFR_DONE, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_2:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_2, 2, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_2, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_2, 1, 1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SRC_TRANSCOMP_IntStat:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_TRANSCOMP_IntStat, 3, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_TRANSCOMP_IntStat, DISABLE_SRC_TRANSCOMP,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_TRANSCOMP_IntStat, ENABLE_SRC_TRANSCOMP, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_DST_TRANSCOMP_IntStat:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_TRANSCOMP_IntStat, 4, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_TRANSCOMP_IntStat, DISABLE_DST_TRANSCOMP,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_TRANSCOMP_IntStat, ENABLE_DST_TRANSCOMP, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SRC_DEC_ERR_IntStat:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_DEC_ERR_IntStat, 5, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_DEC_ERR_IntStat, DISABLE_SRC_DEC_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_DEC_ERR_IntStat, ENABLE_SRC_DEC_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_DST_DEC_ERR_IntStat:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_DEC_ERR_IntStat, 6, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_DEC_ERR_IntStat, DISABLE_DST_DEC_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_DEC_ERR_IntStat, ENABLE_DST_DEC_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SRC_SLV_ERR_IntStat:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_SLV_ERR_IntStat, 7, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_SLV_ERR_IntStat, DISABLE_SRC_SLV_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SRC_SLV_ERR_IntStat, ENABLE_SRC_SLV_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_DST_SLV_ERR_IntStat:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_SLV_ERR_IntStat, 8, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_SLV_ERR_IntStat, DISABLE_DST_SLV_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_DST_SLV_ERR_IntStat, ENABLE_DST_SLV_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_LLI_RD_DEC_ERR_IntStat:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_RD_DEC_ERR_IntStat, 9, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_RD_DEC_ERR_IntStat, DISABLE_LLI_RD_DEC_ERR,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_RD_DEC_ERR_IntStat, ENABLE_LLI_RD_DEC_ERR,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_LLI_WR_DEC_ERR_IntStat:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_WR_DEC_ERR_IntStat, 10, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_WR_DEC_ERR_IntStat, DISABLE_LLI_WR_DEC_ERR,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_WR_DEC_ERR_IntStat, ENABLE_LLI_WR_DEC_ERR,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_LLI_RD_SLV_ERR_IntStat:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_RD_SLV_ERR_IntStat, 11, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_RD_SLV_ERR_IntStat, DISABLE_LLI_RD_SLV_ERR,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_RD_SLV_ERR_IntStat, ENABLE_LLI_RD_SLV_ERR,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_LLI_WR_SLV_ERR_IntStat:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_WR_SLV_ERR_IntStat, 12, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_WR_SLV_ERR_IntStat, DISABLE_LLI_WR_SLV_ERR,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_LLI_WR_SLV_ERR_IntStat, ENABLE_LLI_WR_SLV_ERR,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntStat:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntStat, 13, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntStat,
		 DISABLE_SHADOWREG_OR_LLI_INVALID_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntStat,
		 ENABLE_SHADOWREG_OR_LLI_INVALID_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SLVIF_MULTIBLKTYPE_ERR_IntStat:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_MULTIBLKTYPE_ERR_IntStat, 14, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_MULTIBLKTYPE_ERR_IntStat,
		 DISABLE_SLVIF_MULTIBLKTYPE_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_MULTIBLKTYPE_ERR_IntStat,
		 ENABLE_SLVIF_MULTIBLKTYPE_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_15:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_15, 15, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_15, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_15, 1, 1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SLVIF_DEC_ERR_IntStat:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_DEC_ERR_IntStat, 16, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_DEC_ERR_IntStat, DISABLE_SLVIF_DEC_ERR,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_DEC_ERR_IntStat, ENABLE_SLVIF_DEC_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SLVIF_WR2RO_ERR_IntStat:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WR2RO_ERR_IntStat, 17, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WR2RO_ERR_IntStat, DISABLE_SLVIF_WR2RO_ERR,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WR2RO_ERR_IntStat, ENABLE_SLVIF_WR2RO_ERR,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SLVIF_RD2RWO_ERR_IntStat:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_RD2RWO_ERR_IntStat, 18, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_RD2RWO_ERR_IntStat,
		 DISABLE_SLVIF_RD2RWO_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_RD2RWO_ERR_IntStat, ENABLE_SLVIF_RD2RWO_ERR,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SLVIF_WRONCHEN_ERR_IntStat:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRONCHEN_ERR_IntStat, 19, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRONCHEN_ERR_IntStat,
		 DISABLE_SLVIF_WRONCHEN_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRONCHEN_ERR_IntStat,
		 ENABLE_SLVIF_WRONCHEN_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat, 20, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat,
		 DISABLE_SLVIF_SHADOWREG_WRON_VALID_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat,
		 ENABLE_SLVIF_SHADOWREG_WRON_VALID_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SLVIF_WRONHOLD_ERR_IntStat:
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRONHOLD_ERR_IntStat, 21, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRONHOLD_ERR_IntStat,
		 DISABLE_SLVIF_WRONHOLD_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRONHOLD_ERR_IntStat,
		 ENABLE_SLVIF_WRONHOLD_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_22to24:
 *     BitOffset : 22
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x7
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_22to24, 22, 3, RO,
		(uint64_t)0x7);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_SLVIF_WRPARITY_ERR_IntStat:
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRPARITY_ERR_IntStat, 25, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRPARITY_ERR_IntStat,
		 Disable_SLVIF_WRPARITY_ERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_SLVIF_WRPARITY_ERR_IntStat,
		 Enable_SLVIF_WRPARITY_ERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_26:
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_26, 26, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_26, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_26, 1, 1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_CH_LOCK_CLEARED_IntStat:
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_LOCK_CLEARED_IntStat, 27, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_LOCK_CLEARED_IntStat, DISABLE_CH_LOCK_CLEARED,
		 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_LOCK_CLEARED_IntStat, ENABLE_CH_LOCK_CLEARED,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_CH_SRC_SUSPENDED_IntStat:
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_SRC_SUSPENDED_IntStat, 28, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_SRC_SUSPENDED_IntStat,
		 DISABLE_CH_SRC_SUSPENDED, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_SRC_SUSPENDED_IntStat, ENABLE_CH_SRC_SUSPENDED,
		 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_CH_SUSPENDED_IntStat:
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_SUSPENDED_IntStat, 29, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_SUSPENDED_IntStat, DISABLE_CH_SUSPENDED, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_SUSPENDED_IntStat, ENABLE_CH_SUSPENDED, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_CH_DISABLED_IntStat:
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_DISABLED_IntStat, 30, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_DISABLED_IntStat, DISABLE_CH_DISABLED, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_DISABLED_IntStat, ENABLE_CH_DISABLED, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_CH_ABORTED_IntStat:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_ABORTED_IntStat, 31, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_ABORTED_IntStat, DISABLE_CH_ABORTED, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_CH_ABORTED_IntStat, ENABLE_CH_ABORTED, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_ECC_PROT_CHMem_CorrERR_IntStat:
 *     BitOffset : 32
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_CHMem_CorrERR_IntStat, 32, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_CHMem_CorrERR_IntStat,
		 DISABLE_ECC_CHMEM_CORRERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_CHMem_CorrERR_IntStat,
		 ENABLE_ECC_CHMEM_CORRERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_ECC_PROT_CHMem_UnCorrERR_IntStat:
 *     BitOffset : 33
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_CHMem_UnCorrERR_IntStat, 33, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_CHMem_UnCorrERR_IntStat,
		 DISABLE_ECC_CHMEM_UNCORRERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_CHMem_UnCorrERR_IntStat,
		 ENABLE_ECC_CHMEM_UNCORRERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_ECC_PROT_UIDMem_CorrERR_IntStat:
 *     BitOffset : 34
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_UIDMem_CorrERR_IntStat, 34, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_UIDMem_CorrERR_IntStat,
		 DISABLE_ECC_UIDMEM_CORRERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_UIDMem_CorrERR_IntStat,
		 ENABLE_ECC_UIDMEM_CORRERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   Enable_ECC_PROT_UIDMem_UnCorrERR_IntStat:
 *     BitOffset : 35
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_UIDMem_UnCorrERR_IntStat, 35, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_UIDMem_UnCorrERR_IntStat,
		 DISABLE_ECC_UIDMEM_UNCORRERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS_ENABLEREG, Enable_ECC_PROT_UIDMem_UnCorrERR_IntStat,
		 ENABLE_ECC_UIDMEM_UNCORRERR, 0x1);

/*
 * Bit Field of Register INTSTATUS_ENABLEREG
 *   RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_32to63:
 *     BitOffset : 36
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint64_t)0xfffffff
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_32to63, 36, 28, RO,
		(uint64_t)0xfffffff);

/* ********* DMA INTSTATUS ***********
 *
 * Register of SEDI DMA
 *   INTSTATUS: DW_axi_dmac Channel x Interrupt Status Register
 *     AddressOffset  : 0x88
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, INTSTATUS, 0x88, RO, (uint64_t)0x0, (uint64_t)0x0);

/*
 * Bit Field of Register INTSTATUS
 *   BLOCK_TFR_DONE_IntStat:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, BLOCK_TFR_DONE_IntStat, 0, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, BLOCK_TFR_DONE_IntStat, BLOCK_TFR_COMPLETED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, BLOCK_TFR_DONE_IntStat, BLOCK_TFR_NOT_COMPLETE, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   DMA_TFR_DONE_IntStat:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, DMA_TFR_DONE_IntStat, 1, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, DMA_TFR_DONE_IntStat, DMA_TFR_COMPLETED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, DMA_TFR_DONE_IntStat, DMA_TFR_NOT_COMPLETE, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   RSVD_DMAC_CHx_INTSTATUSREG_2:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_2, 2, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_2, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_2, 1, 1);

/*
 * Bit Field of Register INTSTATUS
 *   SRC_TRANSCOMP_IntStat:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SRC_TRANSCOMP_IntStat, 3, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SRC_TRANSCOMP_IntStat, ACTIVE_SRC_TRANSCOMP, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SRC_TRANSCOMP_IntStat, INACTIVE_SRC_TRANSCOMP, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   DST_TRANSCOMP_IntStat:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, DST_TRANSCOMP_IntStat, 4, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, DST_TRANSCOMP_IntStat, ACTIVE_DST_TRANSCOMP, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, DST_TRANSCOMP_IntStat, INACTIVE_DST_TRANSCOMP, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SRC_DEC_ERR_IntStat:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SRC_DEC_ERR_IntStat, 5, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SRC_DEC_ERR_IntStat, ACTIVE_SRC_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SRC_DEC_ERR_IntStat, INACTIVE_SRC_DEC_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   DST_DEC_ERR_IntStat:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, DST_DEC_ERR_IntStat, 6, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, DST_DEC_ERR_IntStat, ACTIVE_DST_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, DST_DEC_ERR_IntStat, INACTIVE_DST_DEC_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SRC_SLV_ERR_IntStat:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SRC_SLV_ERR_IntStat, 7, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SRC_SLV_ERR_IntStat, ACTIVE_SRC_SLV_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SRC_SLV_ERR_IntStat, INACTIVE_SRC_SLV_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   DST_SLV_ERR_IntStat:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, DST_SLV_ERR_IntStat, 8, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, DST_SLV_ERR_IntStat, ACTIVE_DST_SLV_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, DST_SLV_ERR_IntStat, INACTIVE_DST_SLV_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   LLI_RD_DEC_ERR_IntStat:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, LLI_RD_DEC_ERR_IntStat, 9, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, LLI_RD_DEC_ERR_IntStat, ACTIVE_LLI_RD_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, LLI_RD_DEC_ERR_IntStat, INACTIVE_LLI_RD_DEC_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   LLI_WR_DEC_ERR_IntStat:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, LLI_WR_DEC_ERR_IntStat, 10, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, LLI_WR_DEC_ERR_IntStat, ACTIVE_LLI_WR_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, LLI_WR_DEC_ERR_IntStat, INACTIVE_LLI_WR_DEC_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   LLI_RD_SLV_ERR_IntStat:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, LLI_RD_SLV_ERR_IntStat, 11, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, LLI_RD_SLV_ERR_IntStat, ACTIVE_LLI_RD_SLV_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, LLI_RD_SLV_ERR_IntStat, INACTIVE_LLI_RD_SLV_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   LLI_WR_SLV_ERR_IntStat:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, LLI_WR_SLV_ERR_IntStat, 12, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, LLI_WR_SLV_ERR_IntStat, ACTIVE_LLI_WR_SLV, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, LLI_WR_SLV_ERR_IntStat, INACTIVE_LLI_WR_SLV, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SHADOWREG_OR_LLI_INVALID_ERR_IntStat:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SHADOWREG_OR_LLI_INVALID_ERR_IntStat, 13, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SHADOWREG_OR_LLI_INVALID_ERR_IntStat,
		 ACTIVE_SHADOWREG_OR_LLI_INVALID_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SHADOWREG_OR_LLI_INVALID_ERR_IntStat,
		 INACTIVE_SHADOWREG_OR_LLI_INVALID_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SLVIF_MULTIBLKTYPE_ERR_IntStat:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SLVIF_MULTIBLKTYPE_ERR_IntStat, 14, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_MULTIBLKTYPE_ERR_IntStat, ACTIVE_SLVIF_MULTIBLKTYPE_ERR,
		 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_MULTIBLKTYPE_ERR_IntStat, INACTIVE_SLVIF_MULTIBLKTYPE_ERR,
		 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   RSVD_DMAC_CHx_INTSTATUSREG_15:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_15, 15, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_15, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_15, 1, 1);

/*
 * Bit Field of Register INTSTATUS
 *   SLVIF_DEC_ERR_IntStat:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SLVIF_DEC_ERR_IntStat, 16, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_DEC_ERR_IntStat, ACTIVE_SLVIF_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_DEC_ERR_IntStat, INACTIVE_SLVIF_DEC_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SLVIF_WR2RO_ERR_IntStat:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SLVIF_WR2RO_ERR_IntStat, 17, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_WR2RO_ERR_IntStat, ACTIVE_SLVIF_WR2RO_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_WR2RO_ERR_IntStat, INACTIVE_SLVIF_WR2RO_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SLVIF_RD2RWO_ERR_IntStat:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SLVIF_RD2RWO_ERR_IntStat, 18, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_RD2RWO_ERR_IntStat, ACTIVE_SLVIF_RD2RWO_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_RD2RWO_ERR_IntStat, INACTIVE_SLVIF_RD2RWO_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SLVIF_WRONCHEN_ERR_IntStat:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SLVIF_WRONCHEN_ERR_IntStat, 19, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_WRONCHEN_ERR_IntStat, ACTIVE_SLVIF_WRONCHEN_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_WRONCHEN_ERR_IntStat, INACTIVE_SLVIF_WRONCHEN_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat, 20, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat,
		 ACTIVE_SLVIF_SHADOWREG_WRON_VALID_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat,
		 INACTIVE_SLVIF_SHADOWREG_WRON_VALID_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SLVIF_WRONHOLD_ERR_IntStat:
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SLVIF_WRONHOLD_ERR_IntStat, 21, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_WRONHOLD_ERR_IntStat, ACTIVE_SLVIF_WRONHOLD_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_WRONHOLD_ERR_IntStat, INACTIVE_SLVIF_WRONHOLD_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   RSVD_DMAC_CHx_INTSTATUSREG_22to24:
 *     BitOffset : 22
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_22to24, 22, 3, RO, (uint64_t)0x0);

/*
 * Bit Field of Register INTSTATUS
 *   SLVIF_WRPARITY_ERR_IntStat:
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, SLVIF_WRPARITY_ERR_IntStat, 25, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_WRPARITY_ERR_IntStat, ACTIVE_SLVIF_WRPARITY_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, SLVIF_WRPARITY_ERR_IntStat, INACTIVE_SLVIF_WRPARITY_ERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   RSVD_DMAC_CHx_INTSTATUSREG_26:
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_26, 26, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_26, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_26, 1, 1);

/*
 * Bit Field of Register INTSTATUS
 *   CH_LOCK_CLEARED_IntStat:
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, CH_LOCK_CLEARED_IntStat, 27, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_LOCK_CLEARED_IntStat, ACTIVE_CH_LOCK_CLEARED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_LOCK_CLEARED_IntStat, INACTIVE_CH_LOCK_CLEARED, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   CH_SRC_SUSPENDED_IntStat:
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, CH_SRC_SUSPENDED_IntStat, 28, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_SRC_SUSPENDED_IntStat, ACTIVE_CH_SRC_SUSPENDED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_SRC_SUSPENDED_IntStat, INACTIVE_CH_SRC_SUSPENDED, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   CH_SUSPENDED_IntStat:
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, CH_SUSPENDED_IntStat, 29, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_SUSPENDED_IntStat, ACTIVE_CH_SUSPENDED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_SUSPENDED_IntStat, INACTIVE_CH_SUSPENDED, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   CH_DISABLED_IntStat:
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, CH_DISABLED_IntStat, 30, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_DISABLED_IntStat, ACTIVE_CH_DISABLED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_DISABLED_IntStat, INACTIVE_CH_DISABLED, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   CH_ABORTED_IntStat:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, CH_ABORTED_IntStat, 31, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_ABORTED_IntStat, ACTIVE_CH_ABORTED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, CH_ABORTED_IntStat, INACTIVE_CH_ABORTED, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   ECC_PROT_CHMem_CorrERR_IntStat:
 *     BitOffset : 32
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, ECC_PROT_CHMem_CorrERR_IntStat, 32, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, ECC_PROT_CHMem_CorrERR_IntStat, ACTIVE_EccPROT_CHMem_CorrERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, ECC_PROT_CHMem_CorrERR_IntStat, INACTIVE_EccPROT_CHMem_CorrERR,
		 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   ECC_PROT_CHMem_UnCorrERR_IntStat:
 *     BitOffset : 33
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, ECC_PROT_CHMem_UnCorrERR_IntStat, 33, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, ECC_PROT_CHMem_UnCorrERR_IntStat, ACTIVE_EccPROT_CHMem_UnCorrERR,
		 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, ECC_PROT_CHMem_UnCorrERR_IntStat, INACTIVE_EccPROT_CHMem_UnCorrERR,
		 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   ECC_PROT_UIDMem_CorrERR_IntStat:
 *     BitOffset : 34
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, ECC_PROT_UIDMem_CorrERR_IntStat, 34, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, ECC_PROT_UIDMem_CorrERR_IntStat, ACTIVE_EccPROT_UIDMem_CorrERR,
		 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, ECC_PROT_UIDMem_CorrERR_IntStat, INACTIVE_EccPROT_UIDMem_CorrERR,
		 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   ECC_PROT_UIDMem_UnCorrERR_IntStat:
 *     BitOffset : 35
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, ECC_PROT_UIDMem_UnCorrERR_IntStat, 35, 1, RO, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, ECC_PROT_UIDMem_UnCorrERR_IntStat, ACTIVE_EccPROT_UIDMem_UnCorrERR,
		 0x1);
SEDI_RBFV_DEFINE(DMA, INTSTATUS, ECC_PROT_UIDMem_UnCorrERR_IntStat,
		 INACTIVE_EccPROT_UIDMem_UnCorrERR, 0x0);

/*
 * Bit Field of Register INTSTATUS
 *   RSVD_DMAC_CHx_INTSTATUSREG_36to63:
 *     BitOffset : 36
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTSTATUS, RSVD_DMAC_CHx_INTSTATUSREG_36to63, 36, 28, RO, (uint64_t)0x0);

/* ********* DMA INTSIGNAL_ENABLEREG ***********
 *
 * Register of SEDI DMA
 *   INTSIGNAL_ENABLEREG: DW_axi_dmac Channel x Interrupt Signal Enable Register
 *     AddressOffset  : 0x90
 *     AccessType     : RW
 *     WritableBitMask: 0xf83f7ffb
 *     ResetValue     : (uint64_t)0xffffffffffffffff
 */
SEDI_REG_DEFINE(DMA, INTSIGNAL_ENABLEREG, 0x90, RW, (uint64_t)0xf83f7ffb,
		(uint64_t)0xffffffffffffffff);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_BLOCK_TFR_DONE_IntSignal:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_BLOCK_TFR_DONE_IntSignal, 0, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_BLOCK_TFR_DONE_IntSignal,
		 DISABLE_BLOCK_TFR_DONE_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_BLOCK_TFR_DONE_IntSignal,
		 ENABLE_BLOCK_TFR_DONE_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_DMA_TFR_DONE_IntSignal:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DMA_TFR_DONE_IntSignal, 1, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DMA_TFR_DONE_IntSignal,
		 DISABLE_DMA_TFR_DONE_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DMA_TFR_DONE_IntSignal,
		 ENABLE_DMA_TFR_DONE_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_2:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_2, 2, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_2, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_2, 1, 1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SRC_TRANSCOMP_IntSignal:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_TRANSCOMP_IntSignal, 3, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_TRANSCOMP_IntSignal,
		 DISABLE_SRC_TRANSCOMP_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_TRANSCOMP_IntSignal,
		 ENABLE_SRC_TRANSCOMP_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_DST_TRANSCOMP_IntSignal:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_TRANSCOMP_IntSignal, 4, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_TRANSCOMP_IntSignal,
		 DISABLE_DST_TRANSCOMP_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_TRANSCOMP_IntSignal,
		 ENABLE_DST_TRANSCOMP_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SRC_DEC_ERR_IntSignal:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_DEC_ERR_IntSignal, 5, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_DEC_ERR_IntSignal,
		 DISABLE_SRC_DEC_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_DEC_ERR_IntSignal,
		 ENABLE_SRC_DEC_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_DST_DEC_ERR_IntSignal:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_DEC_ERR_IntSignal, 6, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_DEC_ERR_IntSignal,
		 DISABLE_DST_DEC_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_DEC_ERR_IntSignal,
		 ENABLE_DST_DEC_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SRC_SLV_ERR_IntSignal:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_SLV_ERR_IntSignal, 7, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_SLV_ERR_IntSignal,
		 DISABLE_SRC_SLV_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SRC_SLV_ERR_IntSignal,
		 ENABLE_SRC_SLV_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_DST_SLV_ERR_IntSignal:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_SLV_ERR_IntSignal, 8, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_SLV_ERR_IntSignal,
		 DISABLE_DST_SLV_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_DST_SLV_ERR_IntSignal,
		 ENABLE_DST_SLV_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_LLI_RD_DEC_ERR_IntSignal:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_RD_DEC_ERR_IntSignal, 9, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_RD_DEC_ERR_IntSignal,
		 DISABLE_LLI_RD_DEC_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_RD_DEC_ERR_IntSignal,
		 ENABLE_LLI_RD_DEC_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_LLI_WR_DEC_ERR_IntSignal:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_WR_DEC_ERR_IntSignal, 10, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_WR_DEC_ERR_IntSignal,
		 DISABLE_LLI_WR_DEC_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_WR_DEC_ERR_IntSignal,
		 ENABLE_LLI_WR_DEC_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_LLI_RD_SLV_ERR_IntSignal:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_RD_SLV_ERR_IntSignal, 11, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_RD_SLV_ERR_IntSignal,
		 DISABLE_LLI_RD_SLV_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_RD_SLV_ERR_IntSignal,
		 ENABLE_LLI_RD_SLV_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_LLI_WR_SLV_ERR_IntSignal:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_WR_SLV_ERR_IntSignal, 12, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_WR_SLV_ERR_IntSignal,
		 DISABLE_LLI_WR_SLV_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_LLI_WR_SLV_ERR_IntSignal,
		 ENABLE_LLI_WR_SLV_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntSignal:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntSignal, 13, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntSignal,
		 DISABLE_SHADOWREG_OR_LLI_INVALID_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SHADOWREG_OR_LLI_INVALID_ERR_IntSignal,
		 ENABLE_SHADOWREG_OR_LLI_INVALID_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_MULTIBLKTYPE_ERR_IntSignal:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_MULTIBLKTYPE_ERR_IntSignal, 14, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_MULTIBLKTYPE_ERR_IntSignal,
		 DISABLE_SLVIF_MULTIBLKTYPE_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_MULTIBLKTYPE_ERR_IntSignal,
		 ENABLE_SLVIF_MULTIBLKTYPE_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_15:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_15, 15, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_15, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSTATUS_ENABLEREG_15, 1, 1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_DEC_ERR_IntSignal:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_DEC_ERR_IntSignal, 16, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_DEC_ERR_IntSignal,
		 DISABLE_SLVIF_DEC_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_DEC_ERR_IntSignal,
		 ENABLE_SLVIF_DEC_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_WR2RO_ERR_IntSignal:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WR2RO_ERR_IntSignal, 17, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WR2RO_ERR_IntSignal,
		 DISABLE_SLVIF_WR2RO_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WR2RO_ERR_IntSignal,
		 ENABLE_SLVIF_WR2RO_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_RD2RWO_ERR_IntSignal:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_RD2RWO_ERR_IntSignal, 18, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_RD2RWO_ERR_IntSignal,
		 DISABLE_SLVIF_RD2RWO_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_RD2RWO_ERR_IntSignal,
		 ENABLE_SLVIF_RD2RWO_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_WRONCHEN_ERR_IntSignal:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRONCHEN_ERR_IntSignal, 19, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRONCHEN_ERR_IntSignal,
		 DISABLE_SLVIF_WRONCHEN_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRONCHEN_ERR_IntSignal,
		 ENABLE_SLVIF_WRONCHEN_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_SHADOWREG_WRON_VALID_ERR_IntSignal:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_SHADOWREG_WRON_VALID_ERR_IntSignal, 20, 1,
		RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_SHADOWREG_WRON_VALID_ERR_IntSignal,
		 DISABLE_SLVIF_SHADOWREG_WRON_VALID_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_SHADOWREG_WRON_VALID_ERR_IntSignal,
		 ENABLE_SLVIF_SHADOWREG_WRON_VALID_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_WRONHOLD_ERR_IntSignal:
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRONHOLD_ERR_IntSignal, 21, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRONHOLD_ERR_IntSignal,
		 DISABLE_SLVIF_WRONHOLD_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRONHOLD_ERR_IntSignal,
		 ENABLE_SLVIF_WRONHOLD_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   RSVD_DMAC_CHx_INTSIGNAL_ENABLEREG_22to24:
 *     BitOffset : 22
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x7
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSIGNAL_ENABLEREG_22to24, 22, 3, RO,
		(uint64_t)0x7);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_SLVIF_WRPARITY_ERR_IntSignal:
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRPARITY_ERR_IntSignal, 25, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRPARITY_ERR_IntSignal,
		 Disable_SLVIF_WRPARITY_ERR_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_SLVIF_WRPARITY_ERR_IntSignal,
		 Enable_SLVIF_WRPARITY_ERR_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   RSVD_DMAC_CHx_INTSIGNAL_ENABLEREG_26:
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSIGNAL_ENABLEREG_26, 26, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSIGNAL_ENABLEREG_26, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSIGNAL_ENABLEREG_26, 1, 1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_CH_LOCK_CLEARED_IntSignal:
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_LOCK_CLEARED_IntSignal, 27, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_LOCK_CLEARED_IntSignal,
		 DISABLE_CH_LOCK_CLEARED_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_LOCK_CLEARED_IntSignal,
		 ENABLE_CH_LOCK_CLEARED_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_CH_SRC_SUSPENDED_IntSignal:
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_SRC_SUSPENDED_IntSignal, 28, 1, RW,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_SRC_SUSPENDED_IntSignal,
		 DISABLE_CH_SRC_SUSPENDED_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_SRC_SUSPENDED_IntSignal,
		 ENABLE_CH_SRC_SUSPENDED_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_CH_SUSPENDED_IntSignal:
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_SUSPENDED_IntSignal, 29, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_SUSPENDED_IntSignal,
		 DISABLE_CH_SUSPENDED_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_SUSPENDED_IntSignal,
		 ENABLE_CH_SUSPENDED_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_CH_DISABLED_IntSignal:
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_DISABLED_IntSignal, 30, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_DISABLED_IntSignal,
		 DISABLE_CH_DISABLED_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_DISABLED_IntSignal,
		 ENABLE_CH_DISABLED_IntSignal, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_CH_ABORTED_IntSignal:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_ABORTED_IntSignal, 31, 1, RW, (uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_ABORTED_IntSignal,
		 DISABLE_CH_ABORTED_IntSignal, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_CH_ABORTED_IntSignal, ENABLE_CH_ABORTED_IntSignal,
		 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_ECC_PROT_CHMem_CorrERR_IntSignal:
 *     BitOffset : 32
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_CHMem_CorrERR_IntSignal, 32, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_CHMem_CorrERR_IntSignal,
		 DISABLE_ECC_CHMEM_CORRERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_CHMem_CorrERR_IntSignal,
		 ENABLE_ECC_CHMEM_CORRERR, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_ECC_PROT_CHMem_UnCorrERR_IntSignal:
 *     BitOffset : 33
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_CHMem_UnCorrERR_IntSignal, 33, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_CHMem_UnCorrERR_IntSignal,
		 DISABLE_ECC_CHMEM_UNCORRERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_CHMem_UnCorrERR_IntSignal,
		 ENABLE_ECC_CHMEM_UNCORRERR, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_ECC_PROT_UIDMem_CorrERR_IntSignal:
 *     BitOffset : 34
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_UIDMem_CorrERR_IntSignal, 34, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_UIDMem_CorrERR_IntSignal,
		 DISABLE_ECC_UIDMEM_CORRERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_UIDMem_CorrERR_IntSignal,
		 ENABLE_ECC_UIDMEM_CORRERR, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   Enable_ECC_PROT_UIDMem_UnCorrERR_IntSignal:
 *     BitOffset : 35
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint64_t)0x1
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_UIDMem_UnCorrERR_IntSignal, 35, 1, RO,
		(uint64_t)0x1);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_UIDMem_UnCorrERR_IntSignal,
		 DISABLE_ECC_UIDMEM_UNCORRERR, 0x0);
SEDI_RBFV_DEFINE(DMA, INTSIGNAL_ENABLEREG, Enable_ECC_PROT_UIDMem_UnCorrERR_IntSignal,
		 ENABLE_ECC_UIDMEM_UNCORRERR, 0x1);

/*
 * Bit Field of Register INTSIGNAL_ENABLEREG
 *   RSVD_DMAC_CHx_INTSIGNAL_ENABLEREG_36to63:
 *     BitOffset : 36
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint64_t)0xfffffff
 */
SEDI_RBF_DEFINE(DMA, INTSIGNAL_ENABLEREG, RSVD_DMAC_CHx_INTSIGNAL_ENABLEREG_36to63, 36, 28, RO,
		(uint64_t)0xfffffff);

/* ********* DMA INTCLEARREG ***********
 *
 * Register of SEDI DMA
 *   INTCLEARREG: DW_axi_dmac Channel x Interrupt Status Clear Register
 *     AddressOffset  : 0x98
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffffffffffff
 *     ResetValue     : (uint64_t)0x0
 */
SEDI_REG_DEFINE(DMA, INTCLEARREG, 0x98, RW, (uint64_t)0xffffffffffffffff, (uint64_t)0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_BLOCK_TFR_DONE_IntStat:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_BLOCK_TFR_DONE_IntStat, 0, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_BLOCK_TFR_DONE_IntStat, CLEAR_BLOCK_TFR_DONE, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_BLOCK_TFR_DONE_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_DMA_TFR_DONE_IntStat:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_DMA_TFR_DONE_IntStat, 1, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_DMA_TFR_DONE_IntStat, CLEAR_DMA_TFR_DONE, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_DMA_TFR_DONE_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   RSVD_DMAC_CHx_INTCLEARREG_2:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_2, 2, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_2, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_2, 1, 1);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SRC_TRANSCOMP_IntStat:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SRC_TRANSCOMP_IntStat, 3, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SRC_TRANSCOMP_IntStat, CLEAR_SRC_TRANSCOMP, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SRC_TRANSCOMP_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_DST_TRANSCOMP_IntStat:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_DST_TRANSCOMP_IntStat, 4, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_DST_TRANSCOMP_IntStat, CLEAR_DST_TRANSCOMP, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_DST_TRANSCOMP_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SRC_DEC_ERR_IntStat:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SRC_DEC_ERR_IntStat, 5, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SRC_DEC_ERR_IntStat, CLEAR_SRC_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SRC_DEC_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_DST_DEC_ERR_IntStat:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_DST_DEC_ERR_IntStat, 6, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_DST_DEC_ERR_IntStat, CLEAR_DST_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_DST_DEC_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SRC_SLV_ERR_IntStat:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SRC_SLV_ERR_IntStat, 7, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SRC_SLV_ERR_IntStat, CLEAR_SRC_SLV_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SRC_SLV_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_DST_SLV_ERR_IntStat:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_DST_SLV_ERR_IntStat, 8, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_DST_SLV_ERR_IntStat, CLEAR_DST_SLV_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_DST_SLV_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_LLI_RD_DEC_ERR_IntStat:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_LLI_RD_DEC_ERR_IntStat, 9, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_LLI_RD_DEC_ERR_IntStat, CLEAR_LLI_RD_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_LLI_RD_DEC_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_LLI_WR_DEC_ERR_IntStat:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_LLI_WR_DEC_ERR_IntStat, 10, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_LLI_WR_DEC_ERR_IntStat, CLEAR_LLI_WR_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_LLI_WR_DEC_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_LLI_RD_SLV_ERR_IntStat:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_LLI_RD_SLV_ERR_IntStat, 11, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_LLI_RD_SLV_ERR_IntStat, CLEAR_LLI_RD_SLV_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_LLI_RD_SLV_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_LLI_WR_SLV_ERR_IntStat:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_LLI_WR_SLV_ERR_IntStat, 12, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_LLI_WR_SLV_ERR_IntStat, CLEAR_LLI_WR_SLV_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_LLI_WR_SLV_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SHADOWREG_OR_LLI_INVALID_ERR_IntStat:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SHADOWREG_OR_LLI_INVALID_ERR_IntStat, 13, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SHADOWREG_OR_LLI_INVALID_ERR_IntStat,
		 CLEAR_SHADOWREG_OR_LLI_INVALID_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SHADOWREG_OR_LLI_INVALID_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SLVIF_MULTIBLKTYPE_ERR_IntStat:
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_MULTIBLKTYPE_ERR_IntStat, 14, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_MULTIBLKTYPE_ERR_IntStat,
		 CLEAR_SLVIF_MULTIBLKTYPE_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_MULTIBLKTYPE_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   RSVD_DMAC_CHx_INTCLEARREG_15:
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_15, 15, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_15, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_15, 1, 1);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SLVIF_DEC_ERR_IntStat:
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_DEC_ERR_IntStat, 16, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_DEC_ERR_IntStat, CLEAR_SLVIF_DEC_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_DEC_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SLVIF_WR2RO_ERR_IntStat:
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WR2RO_ERR_IntStat, 17, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WR2RO_ERR_IntStat, CLEAR_SLVIF_WR2RO_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WR2RO_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SLVIF_RD2RWO_ERR_IntStat:
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_RD2RWO_ERR_IntStat, 18, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_RD2RWO_ERR_IntStat, CLEAR_SLVIF_RD2RWO_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_RD2RWO_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SLVIF_WRONCHEN_ERR_IntStat:
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRONCHEN_ERR_IntStat, 19, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRONCHEN_ERR_IntStat, CLEAR_SLVIF_WRONCHEN_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRONCHEN_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat:
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat, 20, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat,
		 CLEAR_SLVIF_SHADOWREG_WRON_VALID_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_SHADOWREG_WRON_VALID_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SLVIF_WRONHOLD_ERR_IntStat:
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRONHOLD_ERR_IntStat, 21, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRONHOLD_ERR_IntStat, CLEAR_SLVIF_WRONHOLD_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRONHOLD_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   RSVD_DMAC_CHx_INTCLEARREG_22to24:
 *     BitOffset : 22
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_22to24, 22, 3, RW, (uint64_t)0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_SLVIF_WRPARITY_ERR_IntStat:
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRPARITY_ERR_IntStat, 25, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRPARITY_ERR_IntStat, CLEAR_SLVIF_WRPARITY_ERR, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_SLVIF_WRPARITY_ERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   RSVD_DMAC_CHx_INTCLEARREG_26:
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_26, 26, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_26, 0, 0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_26, 1, 1);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_CH_LOCK_CLEARED_IntStat:
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_CH_LOCK_CLEARED_IntStat, 27, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_LOCK_CLEARED_IntStat, CLEAR_CH_LOCK_CLEARED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_LOCK_CLEARED_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_CH_SRC_SUSPENDED_IntStat:
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_CH_SRC_SUSPENDED_IntStat, 28, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_SRC_SUSPENDED_IntStat, CLEAR_CH_SRC_SUSPENDED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_SRC_SUSPENDED_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_CH_SUSPENDED_IntStat:
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_CH_SUSPENDED_IntStat, 29, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_SUSPENDED_IntStat, CLEAR_CH_SUSPENDED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_SUSPENDED_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_CH_DISABLED_IntStat:
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_CH_DISABLED_IntStat, 30, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_DISABLED_IntStat, CLEAR_CH_DISABLED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_DISABLED_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_CH_ABORTED_IntStat:
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_CH_ABORTED_IntStat, 31, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_ABORTED_IntStat, CLEAR_CH_ABORTED, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_CH_ABORTED_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_ECC_PROT_CHMem_CorrERR_IntStat:
 *     BitOffset : 32
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_CHMem_CorrERR_IntStat, 32, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_CHMem_CorrERR_IntStat,
		 CLEAR_ECC_CHMEM_CORRERR_IntStat, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_CHMem_CorrERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_ECC_PROT_CHMem_UnCorrERR_IntStat:
 *     BitOffset : 33
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_CHMem_UnCorrERR_IntStat, 33, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_CHMem_UnCorrERR_IntStat,
		 CLEAR_ECC_CHMEM_CORRERR_IntStat, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_CHMem_UnCorrERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_ECC_PROT_UIDMem_CorrERR_IntStat:
 *     BitOffset : 34
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_UIDMem_CorrERR_IntStat, 34, 1, RW, (uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_UIDMem_CorrERR_IntStat,
		 CLEAR_ECC_UIDMEM_CORRERR_IntStat, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_UIDMem_CorrERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   Clear_ECC_PROT_UIDMem_UnCorrERR_IntStat:
 *     BitOffset : 35
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_UIDMem_UnCorrERR_IntStat, 35, 1, RW,
		(uint64_t)0x0);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_UIDMem_UnCorrERR_IntStat,
		 Clear_ECC_UIDMEM_CORRERR_IntStat, 0x1);
SEDI_RBFV_DEFINE(DMA, INTCLEARREG, Clear_ECC_PROT_UIDMem_UnCorrERR_IntStat, NO_ACTION, 0x0);

/*
 * Bit Field of Register INTCLEARREG
 *   RSVD_DMAC_CHx_INTCLEARREG_36to63:
 *     BitOffset : 36
 *     BitWidth  : 28
 *     AccessType: RW
 *     ResetValue: (uint64_t)0x0
 */
SEDI_RBF_DEFINE(DMA, INTCLEARREG, RSVD_DMAC_CHx_INTCLEARREG_36to63, 36, 28, RW, (uint64_t)0x0);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* DW_axi_dmac Channel x Source Address Register */
	__IO_RW uint64_t sar;

	/* DW_axi_dmac Channel x Destination Address Register */
	__IO_RW uint64_t dar;

	/* DW_axi_dmac Channel x Block Transfer Size Register */
	__IO_RW uint64_t block_ts;

	/* DW_axi_dmac Channel x Control Register */
	__IO_RW uint64_t ctl;

	/* DW_axi_dmac Channel x Configuration Register 2 */
	__IO_RW uint64_t cfg2;

	/* DW_axi_dmac Channel x Linked List Pointer Register */
	__IO_RW uint64_t llp;

	/* DW_axi_dmac Channel x Status Register */
	__IO_R uint64_t statusreg;

	/* DW_axi_dmac Channel x Software Handshake Source Register */
	__IO_RW uint64_t swhssrcreg;

	/* DW_axi_dmac Channel x Software Handshake Destination Register */
	__IO_RW uint64_t swhsdstreg;

	/* DW_axi_dmac Channel x Block Transfer Resume Request Register */
	__IO_RW uint64_t blk_tfr_resumereqreg;

	/* Reserved */
	__IO_RW uint64_t reserved0[1];

	/* DW_axi_dmac Channel x AXI QoS Register */
	__IO_RW uint64_t axi_qosreg;

	/* DW_axi_dmac Channel x Source Status Register */
	__IO_R uint64_t sstat;

	/* DW_axi_dmac Channel x Destination Status Register */
	__IO_R uint64_t dstat;

	/* DW_axi_dmac Channel x Source Status Fetch Register */
	__IO_RW uint64_t sstatar;

	/* DW_axi_dmac Channel x Destination Status Fetch Register */
	__IO_RW uint64_t dstatar;

	/* DW_axi_dmac Channel x Interrupt Status Enable Register */
	__IO_RW uint64_t intstatus_enablereg;

	/* DW_axi_dmac Channel x Interrupt Status Register */
	__IO_R uint64_t intstatus;

	/* DW_axi_dmac Channel x Interrupt Signal Enable Register */
	__IO_RW uint64_t intsignal_enablereg;

	/* DW_axi_dmac Channel x Interrupt Status Clear Register */
	__IO_RW uint64_t intclearreg;

} sedi_dma_regs_t;
#define SEDI_DMA_REGS_T sedi_dma_regs_t

#endif /* _SEDI_DMA_REGS_H_ */
