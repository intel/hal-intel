/*
 * Copyright (c) 2023-2025 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2023-09-19
 */

#ifndef _SEDI_DMA_MISC_REGS_H_
#define _SEDI_DMA_MISC_REGS_H_

#include <sedi_reg_defs.h>


/* ********* DMA_MISC CTL_CH ***********
 *
 * Register of SEDI DMA_MISC
 *   CTL_CH: DMA Channel Control register
 *     AddressOffset  : 0x0
 *     AccessType     : RW
 *     WritableBitMask: 0x77b
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(DMA_MISC, CTL_CH, 0x0, RW, (uint32_t)0x77b, (uint32_t)0x0);

/*
 * Bit Field of Register CTL_CH
 *   TRANSFER_MODE: DMA Transfer Mode
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, TRANSFER_MODE, 0, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CTL_CH
 *   RESERVED2: Non Snoop Attribute
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, RESERVED2, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, RESERVED2, 0, 0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, RESERVED2, 1, 1);

/*
 * Bit Field of Register CTL_CH
 *   RD_RS: Read Root Space
 *     BitOffset : 3
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, RD_RS, 3, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CTL_CH
 *   WR_RS: Write Root Space
 *     BitOffset : 5
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, WR_RS, 5, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CTL_CH
 *   RESERVED1:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, RESERVED1, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, RESERVED1, 0, 0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, RESERVED1, 1, 1);

/*
 * Bit Field of Register CTL_CH
 *   RD_NON_SNOOP: IOSF Virtual Channel
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, RD_NON_SNOOP, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, RD_NON_SNOOP, 0, 0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, RD_NON_SNOOP, 1, 1);

/*
 * Bit Field of Register CTL_CH
 *   WR_NON_SNOOP: IOSF MdestID, Function Selection Bits
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, WR_NON_SNOOP, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, WR_NON_SNOOP, 0, 0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, WR_NON_SNOOP, 1, 1);

/*
 * Bit Field of Register CTL_CH
 *   LLI_MODE: LLI Mode Selection
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, LLI_MODE, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, LLI_MODE, 0, 0);
SEDI_RBFV_DEFINE(DMA_MISC, CTL_CH, LLI_MODE, 1, 1);

/*
 * Bit Field of Register CTL_CH
 *   RESERVED0:
 *     BitOffset : 11
 *     BitWidth  : 21
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_CH, RESERVED0, 11, 21, RO, (uint32_t)0x0);

/* ********* DMA_MISC CTL_SPARE ***********
 *
 * Register of SEDI DMA_MISC
 *   CTL_SPARE: Spare Register
 *     AddressOffset  : 0x100
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(DMA_MISC, CTL_SPARE, 0x100, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register CTL_SPARE
 *   SPARE: Spare
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(DMA_MISC, CTL_SPARE, SPARE, 0, 32, RW, (uint32_t)0x0);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* DMA Channel Control register */
	__IO_RW uint32_t ctl_ch[8];

	/* Reserved */
	__IO_RW uint32_t reserved0[55];

	/* Spare Register */
	__IO_RW uint32_t ctl_spare;

} sedi_dma_misc_regs_t;
#define SEDI_DMA_MISC_REGS_T sedi_dma_misc_regs_t


#endif /* _SEDI_DMA_MISC_REGS_H_ */
