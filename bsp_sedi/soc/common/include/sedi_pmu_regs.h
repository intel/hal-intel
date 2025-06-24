/*
 * Copyright (c) 2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2023-12-14
 */

#ifndef _SEDI_PMU_REGS_H_
#define _SEDI_PMU_REGS_H_

#include <sedi_reg_defs.h>


/* ********* PMU SRAM_PG_EN ***********
 *
 * Register of SEDI PMU
 *   SRAM_PG_EN: SRAM Bank Power Gate Enable
 *     AddressOffset  : 0x0
 *     AccessType     : RW
 *     WritableBitMask: 0xfffff
 *     ResetValue     : (uint32_t)0xfffff
 */
SEDI_REG_DEFINE(PMU, SRAM_PG_EN, 0x0, RW, (uint32_t)0xfffff, (uint32_t)0xfffff);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK0_TILE0: POWER GATE Enable For Bank 0 Tile 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK0_TILE0, 0, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK0_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK0_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK0_TILE1: POWER GATE Enable For Bank 0 Tile 1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK0_TILE1, 1, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK0_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK0_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK1_TILE0: POWER GATE Enable For Bank 1 Tile 0
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK1_TILE0, 2, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK1_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK1_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK1_TILE1: POWER GATE Enable For Bank 1 Tile 1
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK1_TILE1, 3, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK1_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK1_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK2_TILE0: POWER GATE Enable For Bank 2 Tile 0
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK2_TILE0, 4, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK2_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK2_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK2_TILE1: POWER GATE Enable For Bank 2 Tile 1
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK2_TILE1, 5, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK2_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK2_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK3_TILE0: POWER GATE Enable For Bank 3 Tile 0
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK3_TILE0, 6, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK3_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK3_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK3_TILE1: POWER GATE Enable For Bank 3 Tile 1
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK3_TILE1, 7, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK3_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK3_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK4_TILE0: POWER GATE Enable For Bank 4 Tile 0
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK4_TILE0, 8, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK4_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK4_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK4_TILE1: POWER GATE Enable For Bank 4 Tile 1
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK4_TILE1, 9, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK4_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK4_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK5_TILE0: POWER GATE Enable For Bank 5 Tile 0
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK5_TILE0, 10, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK5_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK5_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK5_TILE1: POWER GATE Enable For Bank 5 Tile 1
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK5_TILE1, 11, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK5_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK5_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK6_TILE0: POWER GATE Enable For Bank 6 Tile 0
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK6_TILE0, 12, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK6_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK6_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK6_TILE1: POWER GATE Enable For Bank 6 Tile 1
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK6_TILE1, 13, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK6_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK6_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK7_TILE0: POWER GATE Enable For Bank 7 Tile 0
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK7_TILE0, 14, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK7_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK7_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK7_TILE1: POWER GATE Enable For Bank 7 Tile 1
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK7_TILE1, 15, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK7_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK7_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK8_TILE0: POWER GATE Enable For Bank 8 Tile 0
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK8_TILE0, 16, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK8_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK8_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK8_TILE1: POWER GATE Enable For Bank 8 Tile 1
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK8_TILE1, 17, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK8_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK8_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK9_TILE0: POWER GATE Enable For Bank 9 Tile 0
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK9_TILE0, 18, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK9_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK9_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   SRAM_PG_EN_BANK9_TILE1: POWER GATE Enable For Bank 9 Tile 1
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK9_TILE1, 19, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK9_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PG_EN, SRAM_PG_EN_BANK9_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PG_EN
 *   RSVD_SRAM_PGEN: RSV
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PG_EN, RSVD_SRAM_PGEN, 20, 12, RO, (uint32_t)0x0);

/* ********* PMU HOST_WAKEUP ***********
 *
 * Register of SEDI PMU
 *   HOST_WAKEUP: 'Host Wake(Unused/Reserved)'
 *     AddressOffset  : 0x8
 *     AccessType     : RW
 *     WritableBitMask: 0x301
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, HOST_WAKEUP, 0x8, RW, (uint32_t)0x301, (uint32_t)0x0);

/*
 * Bit Field of Register HOST_WAKEUP
 *   OOB_PME: OOB_PME Assert Bit
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOST_WAKEUP, OOB_PME, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, HOST_WAKEUP, OOB_PME, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOST_WAKEUP, OOB_PME, 1, 1);

/*
 * Bit Field of Register HOST_WAKEUP
 *   PMC_STS_SHADOW: PME_STS Live Status Bit
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOST_WAKEUP, PMC_STS_SHADOW, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, HOST_WAKEUP, PMC_STS_SHADOW, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOST_WAKEUP, PMC_STS_SHADOW, 1, 1);

/*
 * Bit Field of Register HOST_WAKEUP
 *   RSVD_HOST_WK2: RSV
 *     BitOffset : 2
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOST_WAKEUP, RSVD_HOST_WK2, 2, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register HOST_WAKEUP
 *   PME_STATUS_CLR_INTR_STS: PME Status Clear Interrupt Status Register
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOST_WAKEUP, PME_STATUS_CLR_INTR_STS, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, HOST_WAKEUP, PME_STATUS_CLR_INTR_STS, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOST_WAKEUP, PME_STATUS_CLR_INTR_STS, 1, 1);

/*
 * Bit Field of Register HOST_WAKEUP
 *   MASK_PME_STATUS_CLR_INTR: PME Status Clear Interrupt Mask Register
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOST_WAKEUP, MASK_PME_STATUS_CLR_INTR, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, HOST_WAKEUP, MASK_PME_STATUS_CLR_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOST_WAKEUP, MASK_PME_STATUS_CLR_INTR, 1, 1);

/*
 * Bit Field of Register HOST_WAKEUP
 *   RSVD_HOST_WK1: RSV
 *     BitOffset : 10
 *     BitWidth  : 22
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOST_WAKEUP, RSVD_HOST_WK1, 10, 22, RO, (uint32_t)0x0);

/* ********* PMU ISH_WAKE_EVENT ***********
 *
 * Register of SEDI PMU
 *   ISH_WAKE_EVENT: Wake Event- 1
 *     AddressOffset  : 0xc
 *     AccessType     : RW
 *     WritableBitMask: 0xefff0000
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, ISH_WAKE_EVENT, 0xc, RW, (uint32_t)0xefff0000, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   RSVD_WK3: RSV
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, RSVD_WK3, 0, 16, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   TIMER_WK: HPET Timer Wake
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, TIMER_WK, 16, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, TIMER_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, TIMER_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   IPC_WK: Wake From Any Ipc Access
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, IPC_WK, 17, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, IPC_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, IPC_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   RSVD_WK2: RSV
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, RSVD_WK2, 18, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, RSVD_WK2, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, RSVD_WK2, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   DMA_WK: DMA Wake
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, DMA_WK, 19, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, DMA_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, DMA_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   I2C0_WK: I2C0 Wake
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, I2C0_WK, 20, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, I2C0_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, I2C0_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   I2C1_WK: I2C1 Wake
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, I2C1_WK, 21, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, I2C1_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, I2C1_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   SPI_WK: SPI Wake
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, SPI_WK, 22, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, SPI_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, SPI_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   UART_WK: UART Wake
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, UART_WK, 23, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, UART_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, UART_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   BRIDGE_WK: Bridge Wake
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, BRIDGE_WK, 24, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, BRIDGE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, BRIDGE_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   I2C2_WK: I2C2 Wake
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, I2C2_WK, 25, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, I2C2_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, I2C2_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   SBEP_WK: SBEP Wake
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, SBEP_WK, 26, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, SBEP_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, SBEP_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   SPI1_WK: SP1 Wake
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, SPI1_WK, 27, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, SPI1_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, SPI1_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   RSVD_WK: RSV
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, RSVD_WK, 28, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, RSVD_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, RSVD_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   D0I3_WK: D0i3 Wake
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, D0I3_WK, 29, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, D0I3_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, D0I3_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   VNN_ACK_RISING_EDGE_WK: Vnn_ack Rise Edge Wake.
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, VNN_ACK_RISING_EDGE_WK, 30, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, VNN_ACK_RISING_EDGE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, VNN_ACK_RISING_EDGE_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT
 *   VNN_ACK_FALLING_EDGE_WK: Vnn_ack Fall Edge Wake.
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT, VNN_ACK_FALLING_EDGE_WK, 31, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, VNN_ACK_FALLING_EDGE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT, VNN_ACK_FALLING_EDGE_WK, 1, 1);

/* ********* PMU ISH_MASK_EVENT ***********
 *
 * Register of SEDI PMU
 *   ISH_MASK_EVENT: Wake Mask-1
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0xeefb0000
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, ISH_MASK_EVENT, 0x10, RW, (uint32_t)0xeefb0000, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   RSVD_WK_MASK2: RSV
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, RSVD_WK_MASK2, 0, 16, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_TIMER_WK: HPET Timer Wake Mask 1-Mask Wake From Timer Event 0-No Mask For Wake From Timer Event
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_TIMER_WK, 16, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_TIMER_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_TIMER_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_HOST_IPC_WK: Host IPC Wake Mask 1-Mask Wake From IPC 0-No Mask For Wake From IPC
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_HOST_IPC_WK, 17, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_HOST_IPC_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_HOST_IPC_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   RSVD_WK_MASK1: RSV
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, RSVD_WK_MASK1, 18, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, RSVD_WK_MASK1, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, RSVD_WK_MASK1, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_DMA_WK: DMA Wake Mask 1-Mask Wake From DMA Event 0-No Mask For Wake From DMA Event
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_DMA_WK, 19, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_DMA_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_DMA_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_I2C0_WK: I2C0 Wake Mask
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C0_WK, 20, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C0_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C0_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_I2C1_WK: I2C1 Wake Mask
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C1_WK, 21, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C1_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C1_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_SPI_WK: SPI0 Wake Interrupts 1-Mask Wake From SPI0 Event 0-No Mask For Wake From SPI0 Event
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_SPI_WK, 22, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_SPI_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_SPI_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_UART_WK: UART Wake Mask 1-Mask Wake From UART Event 0-No Mask For Wake From UART Event
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_UART_WK, 23, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_UART_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_UART_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_RSVD_WK: RSV
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_RSVD_WK, 24, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_RSVD_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_RSVD_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_I2C2_WK: I2C2 Wake Mask
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C2_WK, 25, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C2_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_I2C2_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_SBEP_WK: SBEP Wake Mask 1-Mask Wake From SBEP Event 0-No Mask For Wake From SBEP Event
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_SBEP_WK, 26, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_SBEP_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_SBEP_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_SPI1_WK: SPI1 Wake Mask 1-Mask Wake From SPI1 Event 0-No Mask For Wake From SPI1 Event
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_SPI1_WK, 27, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_SPI1_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_SPI1_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_RSVD_ISH_WK: Reserved
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_RSVD_ISH_WK, 28, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_RSVD_ISH_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_RSVD_ISH_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_D0I3_WK: D0i3 Wake Mask.
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_D0I3_WK, 29, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_D0I3_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_D0I3_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_VNN_ACK_RISING_WK: Vnn_ack Wake Rise Interrupt Mask
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_VNN_ACK_RISING_WK, 30, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_VNN_ACK_RISING_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_VNN_ACK_RISING_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT
 *   MASK_VNN_ACK_FALLING_WK: Vnn_ack Wake Fall Interrupt Mask
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT, MASK_VNN_ACK_FALLING_WK, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_VNN_ACK_FALLING_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT, MASK_VNN_ACK_FALLING_WK, 1, 1);

/* ********* PMU ISH_FABRIC_CNT ***********
 *
 * Register of SEDI PMU
 *   ISH_FABRIC_CNT: Fabric Idle And Time Out Count Configuration
 *     AddressOffset  : 0x18
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x3a980008
 */
SEDI_REG_DEFINE(PMU, ISH_FABRIC_CNT, 0x18, RW, (uint32_t)0xffffffff, (uint32_t)0x3a980008);

/*
 * Bit Field of Register ISH_FABRIC_CNT
 *   FABRIC_IDLE_CNT: Value For The Idle Counter 0 - 16
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x8
 */
SEDI_RBF_DEFINE(PMU, ISH_FABRIC_CNT, FABRIC_IDLE_CNT, 0, 16, RW, (uint32_t)0x8);

/*
 * Bit Field of Register ISH_FABRIC_CNT
 *   FABRIC_TIMEOUT_CNT: Time Out Value For PMU Fabric Timeout Counter
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x3a98
 */
SEDI_RBF_DEFINE(PMU, ISH_FABRIC_CNT, FABRIC_TIMEOUT_CNT, 16, 16, RW, (uint32_t)0x3a98);

/* ********* PMU ISH_GLITCH_BYPASS ***********
 *
 * Register of SEDI PMU
 *   ISH_GLITCH_BYPASS: Glitch Bypass Enable
 *     AddressOffset  : 0x1c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x1
 */
SEDI_REG_DEFINE(PMU, ISH_GLITCH_BYPASS, 0x1c, RW, (uint32_t)0x1, (uint32_t)0x1);

/*
 * Bit Field of Register ISH_GLITCH_BYPASS
 *   GLITCH_BYPASS: Glitch Bypass Enable Bit
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_GLITCH_BYPASS, GLITCH_BYPASS, 0, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_GLITCH_BYPASS, GLITCH_BYPASS, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_GLITCH_BYPASS, GLITCH_BYPASS, 1, 1);

/*
 * Bit Field of Register ISH_GLITCH_BYPASS
 *   RSVD_GLITCH_BYPASS: RSV
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_GLITCH_BYPASS, RSVD_GLITCH_BYPASS, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU RF_ROM_CLKGATE_TO_ISOEN_CTRL ***********
 *
 * Register of SEDI PMU
 *   RF_ROM_CLKGATE_TO_ISOEN_CTRL: RF And ROM Clock Gate To Isolation Enable Count.
 *     AddressOffset  : 0x20
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x2
 */
SEDI_REG_DEFINE(PMU, RF_ROM_CLKGATE_TO_ISOEN_CTRL, 0x20, RW, (uint32_t)0xffff, (uint32_t)0x2);

/*
 * Bit Field of Register RF_ROM_CLKGATE_TO_ISOEN_CTRL
 *   CLKGATE_TO_ISOEN_COUNTER: ClkGate To ISOEN Count
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_CLKGATE_TO_ISOEN_CTRL, CLKGATE_TO_ISOEN_COUNTER, 0, 16, RW, (uint32_t)0x2);

/*
 * Bit Field of Register RF_ROM_CLKGATE_TO_ISOEN_CTRL
 *   RSVD_CLKGATE_ISOEN: RSV
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_CLKGATE_TO_ISOEN_CTRL, RSVD_CLKGATE_ISOEN, 16, 16, RO, (uint32_t)0x0);

/* ********* PMU RF_ROM_ISOEN_TO_PWRGATE_CTRL ***********
 *
 * Register of SEDI PMU
 *   RF_ROM_ISOEN_TO_PWRGATE_CTRL: RF And ROM Isolation Enable To Power Gate Count.
 *     AddressOffset  : 0x24
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x2
 */
SEDI_REG_DEFINE(PMU, RF_ROM_ISOEN_TO_PWRGATE_CTRL, 0x24, RW, (uint32_t)0xffff, (uint32_t)0x2);

/*
 * Bit Field of Register RF_ROM_ISOEN_TO_PWRGATE_CTRL
 *   ISOEN_TO_PWRGATE_COUNTER: ISOEN To POWRGATE Count
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_ISOEN_TO_PWRGATE_CTRL, ISOEN_TO_PWRGATE_COUNTER, 0, 16, RW, (uint32_t)0x2);

/*
 * Bit Field of Register RF_ROM_ISOEN_TO_PWRGATE_CTRL
 *   RSVD_ISOEN_PWRGATE: RSV
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_ISOEN_TO_PWRGATE_CTRL, RSVD_ISOEN_PWRGATE, 16, 16, RO, (uint32_t)0x0);

/* ********* PMU RF_ROM_PWRUNGATE_TO_ISODIS_CTRL ***********
 *
 * Register of SEDI PMU
 *   RF_ROM_PWRUNGATE_TO_ISODIS_CTRL: RF And ROM Power Ungate To Isolation Disable Count
 *     AddressOffset  : 0x28
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x2
 */
SEDI_REG_DEFINE(PMU, RF_ROM_PWRUNGATE_TO_ISODIS_CTRL, 0x28, RW, (uint32_t)0xffff, (uint32_t)0x2);

/*
 * Bit Field of Register RF_ROM_PWRUNGATE_TO_ISODIS_CTRL
 *   PWRUNGATE_TO_ISODIS_COUNTER: PWRUNGATE To ISODIS Count
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_PWRUNGATE_TO_ISODIS_CTRL, PWRUNGATE_TO_ISODIS_COUNTER, 0, 16, RW, (uint32_t)0x2);

/*
 * Bit Field of Register RF_ROM_PWRUNGATE_TO_ISODIS_CTRL
 *   RSVD_PWRUNGATE_ISODIS: RSV
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_PWRUNGATE_TO_ISODIS_CTRL, RSVD_PWRUNGATE_ISODIS, 16, 16, RO, (uint32_t)0x0);

/* ********* PMU RF_ROM_ISODIS_TO_CLKGATEEXIT_CTRL ***********
 *
 * Register of SEDI PMU
 *   RF_ROM_ISODIS_TO_CLKGATEEXIT_CTRL: RF And ROM Isolation Disable To Clock Gate Exit Count
 *     AddressOffset  : 0x2c
 *     AccessType     : RW
 *     WritableBitMask: 0xffff
 *     ResetValue     : (uint32_t)0x2
 */
SEDI_REG_DEFINE(PMU, RF_ROM_ISODIS_TO_CLKGATEEXIT_CTRL, 0x2c, RW, (uint32_t)0xffff, (uint32_t)0x2);

/*
 * Bit Field of Register RF_ROM_ISODIS_TO_CLKGATEEXIT_CTRL
 *   ISODIS_TO_CLKGATEEXIT_COUNTER: ISODIS To CLKGATEEXIT Count
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_ISODIS_TO_CLKGATEEXIT_CTRL, ISODIS_TO_CLKGATEEXIT_COUNTER, 0, 16, RW, (uint32_t)0x2);

/*
 * Bit Field of Register RF_ROM_ISODIS_TO_CLKGATEEXIT_CTRL
 *   RSVD_ISODIS_CLKGATEEXIT: RSV
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_ISODIS_TO_CLKGATEEXIT_CTRL, RSVD_ISODIS_CLKGATEEXIT, 16, 16, RO, (uint32_t)0x0);

/* ********* PMU RF_ROM_PWR_CTRL ***********
 *
 * Register of SEDI PMU
 *   RF_ROM_PWR_CTRL: RF And ROM Power Gating Control
 *     AddressOffset  : 0x30
 *     AccessType     : RW
 *     WritableBitMask: 0x3
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, RF_ROM_PWR_CTRL, 0x30, RW, (uint32_t)0x3, (uint32_t)0x0);

/*
 * Bit Field of Register RF_ROM_PWR_CTRL
 *   RF_ROM_POWER_GATING_ENABLE: RF And ROM Power Gating Enable 1-RF ROM Power Gating Enable 0-RF ROM Power Gating Disable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_PWR_CTRL, RF_ROM_POWER_GATING_ENABLE, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, RF_ROM_PWR_CTRL, RF_ROM_POWER_GATING_ENABLE, 0, 0);
SEDI_RBFV_DEFINE(PMU, RF_ROM_PWR_CTRL, RF_ROM_POWER_GATING_ENABLE, 1, 1);

/*
 * Bit Field of Register RF_ROM_PWR_CTRL
 *   AONRF_DEEPSLEEP_EN: AON RF DeepsleepEnable 1-Enable AON_RF Deepsleep Mode 0-Disable AONRF Deepsleep Mode
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_PWR_CTRL, AONRF_DEEPSLEEP_EN, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, RF_ROM_PWR_CTRL, AONRF_DEEPSLEEP_EN, 0, 0);
SEDI_RBFV_DEFINE(PMU, RF_ROM_PWR_CTRL, AONRF_DEEPSLEEP_EN, 1, 1);

/*
 * Bit Field of Register RF_ROM_PWR_CTRL
 *   RSVD_RF_ROM_PWR_CTRL: RSV
 *     BitOffset : 2
 *     BitWidth  : 30
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RF_ROM_PWR_CTRL, RSVD_RF_ROM_PWR_CTRL, 2, 30, RO, (uint32_t)0x0);

/* ********* PMU SRAM_PWR_CTRL ***********
 *
 * Register of SEDI PMU
 *   SRAM_PWR_CTRL: SRAM Isolation Disable To Idle Count
 *     AddressOffset  : 0x34
 *     AccessType     : RW
 *     WritableBitMask: 0xf0f0f0f
 *     ResetValue     : (uint32_t)0xf0f0f02
 */
SEDI_REG_DEFINE(PMU, SRAM_PWR_CTRL, 0x34, RW, (uint32_t)0xf0f0f0f, (uint32_t)0xf0f0f02);

/*
 * Bit Field of Register SRAM_PWR_CTRL
 *   SRAM_ISOEN_TO_POWERGATE_COUNTER: SRAM ISOEN To POWERGATE Count
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_CTRL, SRAM_ISOEN_TO_POWERGATE_COUNTER, 0, 4, RW, (uint32_t)0x2);

/*
 * Bit Field of Register SRAM_PWR_CTRL
 *   RSVD_SRAM_PG_FSM_CNT3: RSV
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_CTRL, RSVD_SRAM_PG_FSM_CNT3, 4, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register SRAM_PWR_CTRL
 *   SRAM_POWERGATE_TO_POWERUNGATE_COUNTER: SRAM POWERGATE To POWERUNGATE Count
 *     BitOffset : 8
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0f
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_CTRL, SRAM_POWERGATE_TO_POWERUNGATE_COUNTER, 8, 4, RW, (uint32_t)0x0f);

/*
 * Bit Field of Register SRAM_PWR_CTRL
 *   RSVD_SRAM_PG_FSM_CNT2: RSV
 *     BitOffset : 12
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_CTRL, RSVD_SRAM_PG_FSM_CNT2, 12, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register SRAM_PWR_CTRL
 *   SRAM_POWERUNGATE_TO_ISODIS_COUNTER: SRAM POWERUNGATE To ISODIS Count
 *     BitOffset : 16
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0f
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_CTRL, SRAM_POWERUNGATE_TO_ISODIS_COUNTER, 16, 4, RW, (uint32_t)0x0f);

/*
 * Bit Field of Register SRAM_PWR_CTRL
 *   RSVD_SRAM_PG_FSM_CNT1: RSV
 *     BitOffset : 20
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_CTRL, RSVD_SRAM_PG_FSM_CNT1, 20, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register SRAM_PWR_CTRL
 *   SRAM_ISODIS_TO_IDLE_COUNTER: SRAM ISODIS To IDLE Count
 *     BitOffset : 24
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0f
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_CTRL, SRAM_ISODIS_TO_IDLE_COUNTER, 24, 4, RW, (uint32_t)0x0f);

/*
 * Bit Field of Register SRAM_PWR_CTRL
 *   RSVD_SRAM_PG_FSM_CNT0: RSV
 *     BitOffset : 28
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_CTRL, RSVD_SRAM_PG_FSM_CNT0, 28, 4, RO, (uint32_t)0x0);

/* ********* PMU VNN_REQ ***********
 *
 * Register of SEDI PMU
 *   VNN_REQ: VNN Req Assert
 *     AddressOffset  : 0x3c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, VNN_REQ, 0x3c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ0: Vnn_req Assert Bit 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ0, 0, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ0, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ0, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ1: Vnn_req Assert Bit 1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ1, 1, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ1, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ1, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ2: Vnn_req Assert Bit 2
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ2, 2, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ2, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ2, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ3: Vnn_req Assert Bit 3
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ3, 3, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ3, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ3, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ4: Vnn_req Assert Bit 4
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ4, 4, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ4, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ4, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ5: Vnn_req Assert Bit 5
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ5, 5, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ5, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ5, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ6: Vnn_req Assert Bit 6
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ6, 6, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ6, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ6, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ7: Vnn_req Assert Bit 7
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ7, 7, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ7, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ7, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ8: Vnn_req Assert Bit 8
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ8, 8, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ8, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ8, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ9: Vnn_req Assert Bit 9
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ9, 9, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ9, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ9, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ10: Vnn_req Assert Bit 10
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ10, 10, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ10, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ10, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ11: Vnn_req Assert Bit 11
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ11, 11, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ11, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ11, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ12: Vnn_req Assert Bit 12
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ12, 12, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ12, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ12, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ13: Vnn_req Assert Bit 13
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ13, 13, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ13, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ13, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ14: Vnn_req Assert Bit 14
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ14, 14, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ14, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ14, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ15: Vnn_req Assert Bit 15
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ15, 15, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ15, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ15, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ16: Vnn_req Assert Bit 16
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ16, 16, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ16, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ16, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ17: Vnn_req Assert Bit 17
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ17, 17, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ17, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ17, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ18: Vnn_req Assert Bit 18
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ18, 18, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ18, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ18, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ19: Vnn_req Assert Bit 19
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ19, 19, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ19, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ19, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ20: Vnn_req Assert Bit 20
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ20, 20, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ20, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ20, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ21: Vnn_req Assert Bit 21
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ21, 21, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ21, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ21, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ22: Vnn_req Assert Bit 22
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ22, 22, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ22, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ22, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ23: Vnn_req Assert Bit 23
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ23, 23, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ23, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ23, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ24: Vnn_req Assert Bit 24
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ24, 24, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ24, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ24, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ25: Vnn_req Assert Bit 25
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ25, 25, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ25, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ25, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ26: Vnn_req Assert Bit 26
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ26, 26, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ26, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ26, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ27: Vnn_req Assert Bit 27
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ27, 27, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ27, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ27, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ28: Vnn_req Assert Bit 28
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ28, 28, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ28, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ28, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ29: Vnn_req Assert Bit 29
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ29, 29, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ29, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ29, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ30: Vnn_req Assert Bit 30
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ30, 30, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ30, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ30, 1, 1);

/*
 * Bit Field of Register VNN_REQ
 *   VNN_REQ31: Vnn_req Assert Bit 31
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW_1S_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ, VNN_REQ31, 31, 1, RW_1S_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ31, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ, VNN_REQ31, 1, 1);

/* ********* PMU VNN_REQ_ACK ***********
 *
 * Register of SEDI PMU
 *   VNN_REQ_ACK: Vnn_req/Ack Live Status, Interrupts And Interrupt Masks Record
 *     AddressOffset  : 0x40
 *     AccessType     : RW
 *     WritableBitMask: 0x3c
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, VNN_REQ_ACK, 0x40, RW, (uint32_t)0x3c, (uint32_t)0x0);

/*
 * Bit Field of Register VNN_REQ_ACK
 *   VNN_REQ_ACK_STATUS: Vnn_req_ack Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ_ACK, VNN_REQ_ACK_STATUS, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, VNN_REQ_ACK_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, VNN_REQ_ACK_STATUS, 1, 1);

/*
 * Bit Field of Register VNN_REQ_ACK
 *   VNN_ACK_STATUS: Vnn_ack Live Status
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_STATUS, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_STATUS, 1, 1);

/*
 * Bit Field of Register VNN_REQ_ACK
 *   VNN_ACK_RISING_EDGE_INTERRUPT: Interrupt Status For Vnn_ack Rise Interrupt
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_RISING_EDGE_INTERRUPT, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_RISING_EDGE_INTERRUPT, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_RISING_EDGE_INTERRUPT, 1, 1);

/*
 * Bit Field of Register VNN_REQ_ACK
 *   VNN_ACK_FALLING_EDGE_INTERRUPT: Interrupt Status For Vnn_ack Fall Interrupt
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_FALLING_EDGE_INTERRUPT, 3, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_FALLING_EDGE_INTERRUPT, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, VNN_ACK_FALLING_EDGE_INTERRUPT, 1, 1);

/*
 * Bit Field of Register VNN_REQ_ACK
 *   MASK_VNN_ACK_RISING_EDGE_INTERRUPT: Interrupt Mask For Vnn_ack Rise Interrupt
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ_ACK, MASK_VNN_ACK_RISING_EDGE_INTERRUPT, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, MASK_VNN_ACK_RISING_EDGE_INTERRUPT, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, MASK_VNN_ACK_RISING_EDGE_INTERRUPT, 1, 1);

/*
 * Bit Field of Register VNN_REQ_ACK
 *   MASK_VNN_ACK_FALLING_EDGE_INTERRUPT: Interrupt Mask For Vnn_ack Fall Interrupt
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ_ACK, MASK_VNN_ACK_FALLING_EDGE_INTERRUPT, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, MASK_VNN_ACK_FALLING_EDGE_INTERRUPT, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNN_REQ_ACK, MASK_VNN_ACK_FALLING_EDGE_INTERRUPT, 1, 1);

/*
 * Bit Field of Register VNN_REQ_ACK
 *   RSVD_VNNREQACK: RSV
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNN_REQ_ACK, RSVD_VNNREQACK, 6, 26, RO, (uint32_t)0x0);

/* ********* PMU LDO_CTRL ***********
 *
 * Register of SEDI PMU
 *   LDO_CTRL: LDO Control
 *     AddressOffset  : 0x44
 *     AccessType     : RW
 *     WritableBitMask: 0x3ffffe30
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, LDO_CTRL, 0x44, RW, (uint32_t)0x7, (uint32_t)0x0);

/*
 * Bit Field of Register LDO_CTRL
 *   RSVD_LDO_CTRL: RSV
 *     BitOffset : 4
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, LDO_CTRL, RSVD_LDO_CTRL, 4, 28, RO, (uint32_t)0x0);

/*
 * Bit Field of Register LDO_CTRL
 *   LDO_READY: LDO Ready Indication
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, LDO_CTRL, LDO_READY, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, LDO_CTRL, LDO_READY, 0, 0);
SEDI_RBFV_DEFINE(PMU, LDO_CTRL, LDO_READY, 1, 1);

/*
 * Bit Field of Register LDO_CTRL
 *   LDO_CALIBRATION: LDO Calibration Done Indication
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_AC
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, LDO_CTRL, LDO_CALIBRATION, 2, 1, RW_AC, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, LDO_CTRL, LDO_CALIBRATION, 0, 0);
SEDI_RBFV_DEFINE(PMU, LDO_CTRL, LDO_CALIBRATION, 1, 1);

/*
 * Bit Field of Register LDO_CTRL
 *   LDO_RETENTION: LDO Retention Request
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, LDO_CTRL, LDO_RETENTION, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, LDO_CTRL, LDO_RETENTION, 0, 0);
SEDI_RBFV_DEFINE(PMU, LDO_CTRL, LDO_RETENTION, 1, 1);

/*
 * Bit Field of Register LDO_CTRL
 *   LDO_REQ: LDO ON Request
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, LDO_CTRL, LDO_REQ, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, LDO_CTRL, LDO_REQ, 0, 0);
SEDI_RBFV_DEFINE(PMU, LDO_CTRL, LDO_REQ, 1, 1);

/* ********* PMU ISH_WAKE_EVENT2 ***********
 *
 * Register of SEDI PMU
 *   ISH_WAKE_EVENT2: Wake Event- 2
 *     AddressOffset  : 0x48
 *     AccessType     : RW
 *     WritableBitMask: 0x3ffffe30
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, ISH_WAKE_EVENT2, 0x48, RW, (uint32_t)0x3ffffe30, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   RSVD_WAKE2REG_2: RSV
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, RSVD_WAKE2REG_2, 0, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   SRAM_ERASE_WK: SRAM Erase Wake
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, SRAM_ERASE_WK, 4, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SRAM_ERASE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SRAM_ERASE_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   RESET_PREP_AVAIL_WK: Reset Prep Avail Wake
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, RESET_PREP_AVAIL_WK, 5, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, RESET_PREP_AVAIL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, RESET_PREP_AVAIL_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   RSVD_WAKE2REG_1: RSV
 *     BitOffset : 6
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, RSVD_WAKE2REG_1, 6, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   XPRSN_WK: XPRSN Wake Bit
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, XPRSN_WK, 9, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, XPRSN_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, XPRSN_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   SW_PG_REQ_B_RISE_WK: SW_PG_REQ_B_RISE Wake Bit
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, SW_PG_REQ_B_RISE_WK, 10, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SW_PG_REQ_B_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SW_PG_REQ_B_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   SW_PG_REQ_B_FALL_WK: SW_PG_REQ_B_FALL Wake Bit
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, SW_PG_REQ_B_FALL_WK, 11, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SW_PG_REQ_B_FALL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SW_PG_REQ_B_FALL_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   PG_WAKE_RISE_WK: PMC_PG_WAKE_RISE Wake Bit
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, PG_WAKE_RISE_WK, 12, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, PG_WAKE_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, PG_WAKE_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   PG_WAKE_FALL_WK: PMC_PG_WAKE_FALL Wake Bit
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, PG_WAKE_FALL_WK, 13, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, PG_WAKE_FALL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, PG_WAKE_FALL_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   BR_ISOL_ACK_RISE_WK: BR_ISOL_ACK_RISE Wake Bit
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, BR_ISOL_ACK_RISE_WK, 14, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, BR_ISOL_ACK_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, BR_ISOL_ACK_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   BR_ISOL_ACK_FALL_WK: BR_ISOL_ACK_FALL Wake Bit
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, BR_ISOL_ACK_FALL_WK, 15, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, BR_ISOL_ACK_FALL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, BR_ISOL_ACK_FALL_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   HOST_RSTB_WIRE_RISE_WK: HOST_RSTB_WIRE_RISE Wake Bit
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, HOST_RSTB_WIRE_RISE_WK, 16, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, HOST_RSTB_WIRE_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, HOST_RSTB_WIRE_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   HOST_RSTB_WIRE_FALL_WK: HOST_RSTB_WIRE_FALL Wake Bit
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, HOST_RSTB_WIRE_FALL_WK, 17, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, HOST_RSTB_WIRE_FALL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, HOST_RSTB_WIRE_FALL_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   PCE_CHG_DETECT_INTR_WK: PCE_CHG_DETECT_INTR Wake Bit
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, PCE_CHG_DETECT_INTR_WK, 18, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, PCE_CHG_DETECT_INTR_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, PCE_CHG_DETECT_INTR_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   PME_STATUS_CLR_INTR_WK: PME_STATUS_CLR_INTR Wake Bit
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, PME_STATUS_CLR_INTR_WK, 19, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, PME_STATUS_CLR_INTR_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, PME_STATUS_CLR_INTR_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   RST_WARN_RISE_WK: Reset Warn Wake
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, RST_WARN_RISE_WK, 20, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, RST_WARN_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, RST_WARN_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   I2C3_WK: I2C3 Wake
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, I2C3_WK, 21, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I2C3_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I2C3_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   I2C4_WK: I2C4 Wake
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, I2C4_WK, 22, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I2C4_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I2C4_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   I2C5_WK: I2C5 Wake
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, I2C5_WK, 23, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I2C5_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I2C5_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   SPI2_WK: SPI2 Wake
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, SPI2_WK, 24, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SPI2_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SPI2_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   SPI3_WK: SPI3 Wake
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, SPI3_WK, 25, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SPI3_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, SPI3_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   DMA1_WK: DMA1 Wake
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, DMA1_WK, 26, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, DMA1_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, DMA1_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   DMA2_WK: DMA2 Wake
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, DMA2_WK, 27, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, DMA2_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, DMA2_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   I3C1_WK: I3C1 Wake
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, I3C1_WK, 28, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I3C1_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I3C1_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   I3C2_WK: I3C2 Wake
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, I3C2_WK, 29, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I3C2_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_WAKE_EVENT2, I3C2_WK, 1, 1);

/*
 * Bit Field of Register ISH_WAKE_EVENT2
 *   RSVD_ISH_WK_EVENT2: RSV
 *     BitOffset : 30
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_WAKE_EVENT2, RSVD_ISH_WK_EVENT2, 30, 2, RO, (uint32_t)0x0);

/* ********* PMU ISH_MASK_EVENT2 ***********
 *
 * Register of SEDI PMU
 *   ISH_MASK_EVENT2: Wake Mask-2
 *     AddressOffset  : 0x4c
 *     AccessType     : RW
 *     WritableBitMask: 0x3ffffe30
 *     ResetValue     : (uint32_t)0xffc00
 */
SEDI_REG_DEFINE(PMU, ISH_MASK_EVENT2, 0x4c, RW, (uint32_t)0x3ffffe30, (uint32_t)0xffc00);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   RSVD_MASK2REG_2: RSV
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, RSVD_MASK2REG_2, 0, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_SRAM_ERASE_WK: Sram Erase Wake Mask
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 * Note: Rename MASK_SRAM_ERASE_WK_0 to MASK_SRAM_ERASE_WK manually
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SRAM_ERASE_WK, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SRAM_ERASE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SRAM_ERASE_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_RESET_PREP_AVAIL_WK: RESET Prep Wake Mask
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_RESET_PREP_AVAIL_WK, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_RESET_PREP_AVAIL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_RESET_PREP_AVAIL_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   RSVD_MASK2REG_1: RSV
 *     BitOffset : 6
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, RSVD_MASK2REG_1, 6, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_XPRSN_WK: XPRSN Wake Mask Bit
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_XPRSN_WK, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_XPRSN_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_XPRSN_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_SW_PG_REQ_B_RISE_WK: PG_REQ_B_RISE Wake Mask Bit
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SW_PG_REQ_B_RISE_WK, 10, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SW_PG_REQ_B_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SW_PG_REQ_B_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_SW_PG_REQ_B_FALL_WK: PG_REQ_B_FALL Wake Mask Bit
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SW_PG_REQ_B_FALL_WK, 11, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SW_PG_REQ_B_FALL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SW_PG_REQ_B_FALL_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_PG_WAKE_RISE_WK: PMC_PG_WAKE_RISE Wake Mask Bit
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PG_WAKE_RISE_WK, 12, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PG_WAKE_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PG_WAKE_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_PG_WAKE_FALL_WK: PMC_PG_WAKE_FALL Wake Mask Bit
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PG_WAKE_FALL_WK, 13, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PG_WAKE_FALL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PG_WAKE_FALL_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_BR_ISOL_ACK_RISE_WK: BR_ISOL_ACK_RISE Wake Mask Bit
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_BR_ISOL_ACK_RISE_WK, 14, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_BR_ISOL_ACK_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_BR_ISOL_ACK_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_BR_ISOL_ACK_FALL_WK: BR_ISOL_ACK_FALL Wake Mask Bit
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_BR_ISOL_ACK_FALL_WK, 15, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_BR_ISOL_ACK_FALL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_BR_ISOL_ACK_FALL_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_HOST_RSTB_WIRE_RISE_WK: HOST_RSTB_WIRE_RISE Wake Mask Bit
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_HOST_RSTB_WIRE_RISE_WK, 16, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_HOST_RSTB_WIRE_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_HOST_RSTB_WIRE_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_HOST_RSTB_WIRE_FALL_WK: HOST_RSTB_WIRE_FALL Wake Mask Bit
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_HOST_RSTB_WIRE_FALL_WK, 17, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_HOST_RSTB_WIRE_FALL_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_HOST_RSTB_WIRE_FALL_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_PCE_CHG_DETECT_INTR_WK: PCE_CHG_DETECT_INTR Wake Mask Bit
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PCE_CHG_DETECT_INTR_WK, 18, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PCE_CHG_DETECT_INTR_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PCE_CHG_DETECT_INTR_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_PME_STATUS_CLR_INTR_WK: PME_STATUS_CLR_INTR Wake Mask Bit
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PME_STATUS_CLR_INTR_WK, 19, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PME_STATUS_CLR_INTR_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_PME_STATUS_CLR_INTR_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_RST_WARN_RISE_WK: Reset Warn Rise Wake Mask
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_RST_WARN_RISE_WK, 20, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_RST_WARN_RISE_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_RST_WARN_RISE_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_I2C3_WK: I2C3 Wake Mask
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C3_WK, 21, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C3_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C3_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_I2C4_WK: I2C4 Wake Mask
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C4_WK, 22, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C4_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C4_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_I2C5_WK: I2C5 Wake Mask
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C5_WK, 23, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C5_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I2C5_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_SPI2_WK: SPI2 Wake Interrupts 1-Mask Wake From SPI2 Event 0-No Mask For Wake From SPI2 Event
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SPI2_WK, 24, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SPI2_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SPI2_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_SPI3_WK: SPI3 Wake Interrupts 1-Mask Wake From SPI3 Event 0-No Mask For Wake From SPI3 Event
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SPI3_WK, 25, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SPI3_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_SPI3_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_DMA1_WK: DMA1 Wake Mask 1-Mask Wake From DMA1 Event 0-No Mask For Wake From DMA1 Event
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_DMA1_WK, 26, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_DMA1_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_DMA1_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_DMA2_WK: DMA2 Wake Mask 1-Mask Wake From DMA2 Event 0-No Mask For Wake From DMA2 Event
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_DMA2_WK, 27, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_DMA2_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_DMA2_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_I3C1_WK: I3C1 Wake Mask 1-Mask Wake From I3C1 Event 0-No Mask For Wake From I3C1 Event
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I3C1_WK, 28, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I3C1_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I3C1_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   MASK_I3C2_WK: I3C2 Wake Mask 1-Mask Wake From I3C2 Event 0-No Mask For Wake From I3C2 Event
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I3C2_WK, 29, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I3C2_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_MASK_EVENT2, MASK_I3C2_WK, 1, 1);

/*
 * Bit Field of Register ISH_MASK_EVENT2
 *   RSVD_WK_MASK2: RSV
 *     BitOffset : 30
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_MASK_EVENT2, RSVD_WK_MASK2, 30, 2, RO, (uint32_t)0x0);

/* ********* PMU ISH_HPET_INTR_CTRL ***********
 *
 * Register of SEDI PMU
 *   ISH_HPET_INTR_CTRL: 'HPET Interrupt(Not POR)'
 *     AddressOffset  : 0x50
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, ISH_HPET_INTR_CTRL, 0x50, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_HPET_INTR_CTRL
 *   HPET_INTR0_CONTROL: 'HPET Interrupt 0 Control (Reserved)'
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR0_CONTROL, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR0_CONTROL, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR0_CONTROL, 1, 1);

/*
 * Bit Field of Register ISH_HPET_INTR_CTRL
 *   HPET_INTR1_CONTROL: 'HPET Interrupt 1 Control (Reserved)'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR1_CONTROL, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR1_CONTROL, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR1_CONTROL, 1, 1);

/*
 * Bit Field of Register ISH_HPET_INTR_CTRL
 *   HPET_INTR2_CONTROL: 'HPET Interrupt 2 Control (Resrved)'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR2_CONTROL, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR2_CONTROL, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR2_CONTROL, 1, 1);

/*
 * Bit Field of Register ISH_HPET_INTR_CTRL
 *   HPET_INTR0_STATUS: 'HPET Intr0 Status (Reserved)'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR0_STATUS, 3, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR0_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR0_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_HPET_INTR_CTRL
 *   HPET_INTR1_STATUS: 'HPET Intr1 Status (Reserved)'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR1_STATUS, 4, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR1_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR1_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_HPET_INTR_CTRL
 *   HPET_INTR2_STATUS: 'HPET Intr2 Status (Reserved)'
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR2_STATUS, 5, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR2_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, ISH_HPET_INTR_CTRL, HPET_INTR2_STATUS, 1, 1);

/*
 * Bit Field of Register ISH_HPET_INTR_CTRL
 *   RESERVD: RSV
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_HPET_INTR_CTRL, RESERVD, 6, 26, RO, (uint32_t)0x0);

/* ********* PMU PGCB_CLK_GATE_CTRL ***********
 *
 * Register of SEDI PMU
 *   PGCB_CLK_GATE_CTRL: PGCB Clock Gating Control
 *     AddressOffset  : 0x54
 *     AccessType     : RW
 *     WritableBitMask: 0x10f
 *     ResetValue     : (uint32_t)0x100
 */
SEDI_REG_DEFINE(PMU, PGCB_CLK_GATE_CTRL, 0x54, RW, (uint32_t)0x10f, (uint32_t)0x100);

/*
 * Bit Field of Register PGCB_CLK_GATE_CTRL
 *   T_CLKGATE_TIMER_VALUE: T_CLKGATE Count Value
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PGCB_CLK_GATE_CTRL, T_CLKGATE_TIMER_VALUE, 0, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register PGCB_CLK_GATE_CTRL
 *   RSVD1: Reserved
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PGCB_CLK_GATE_CTRL, RSVD1, 4, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PGCB_CLK_GATE_CTRL
 *   ACC_CLKGATE_DISABLED: Accessible Clock Gate Disable Bit For PGCB Clock
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, PGCB_CLK_GATE_CTRL, ACC_CLKGATE_DISABLED, 8, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, PGCB_CLK_GATE_CTRL, ACC_CLKGATE_DISABLED, 0, 0);
SEDI_RBFV_DEFINE(PMU, PGCB_CLK_GATE_CTRL, ACC_CLKGATE_DISABLED, 1, 1);

/*
 * Bit Field of Register PGCB_CLK_GATE_CTRL
 *   RSVD_PGCB_CLK_GATE: RSV
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PGCB_CLK_GATE_CTRL, RSVD_PGCB_CLK_GATE, 9, 23, RO, (uint32_t)0x0);

/* ********* PMU VNNAON_RED_EN ***********
 *
 * Register of SEDI PMU
 *   VNNAON_RED_EN: Vnnaon Reduction Enable
 *     AddressOffset  : 0x58
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, VNNAON_RED_EN, 0x58, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register VNNAON_RED_EN
 *   VNNAON_RED_EN: VNNAON Reduction Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_AC
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNNAON_RED_EN, VNNAON_RED_EN, 0, 1, RW_AC, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, VNNAON_RED_EN, VNNAON_RED_EN, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNNAON_RED_EN, VNNAON_RED_EN, 1, 1);

/*
 * Bit Field of Register VNNAON_RED_EN
 *   RSVD_VNNAON_RED_EN: RSV
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNNAON_RED_EN, RSVD_VNNAON_RED_EN, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU RESET_PREP_REG ***********
 *
 * Register of SEDI PMU
 *   RESET_PREP_REG: Reset Prep
 *     AddressOffset  : 0x5c
 *     AccessType     : RW
 *     WritableBitMask: 0x80000001
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, RESET_PREP_REG, 0x5c, RW, (uint32_t)0x80000001, (uint32_t)0x0);

/*
 * Bit Field of Register RESET_PREP_REG
 *   RESET_PREP_GET: Prep Get 1- Reset Prep Message Read 0-Reset Prep Message Not Read
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_AC
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RESET_PREP_REG, RESET_PREP_GET, 0, 1, RW_AC, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, RESET_PREP_REG, RESET_PREP_GET, 0, 0);
SEDI_RBFV_DEFINE(PMU, RESET_PREP_REG, RESET_PREP_GET, 1, 1);

/*
 * Bit Field of Register RESET_PREP_REG
 *   RESET_PREP_AVAIL:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RESET_PREP_REG, RESET_PREP_AVAIL, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, RESET_PREP_REG, RESET_PREP_AVAIL, 0, 0);
SEDI_RBFV_DEFINE(PMU, RESET_PREP_REG, RESET_PREP_AVAIL, 1, 1);

/*
 * Bit Field of Register RESET_PREP_REG
 *   RESET_TYPE:
 *     BitOffset : 2
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RESET_PREP_REG, RESET_TYPE, 2, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RESET_PREP_REG
 *   PREP_TYPE:
 *     BitOffset : 10
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RESET_PREP_REG, PREP_TYPE, 10, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RESET_PREP_REG
 *   RSV:
 *     BitOffset : 18
 *     BitWidth  : 13
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RESET_PREP_REG, RSV, 18, 13, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RESET_PREP_REG
 *   MASK_RESET_PREP_AVAIL: Prep Avail Mask 1- Mask Reset Prep Avail Interrupt 0-Reset Prep Avail Interrupt Not Masked.
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, RESET_PREP_REG, MASK_RESET_PREP_AVAIL, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, RESET_PREP_REG, MASK_RESET_PREP_AVAIL, 0, 0);
SEDI_RBFV_DEFINE(PMU, RESET_PREP_REG, MASK_RESET_PREP_AVAIL, 1, 1);

/* ********* PMU FABRIC_SNAPSHOT_REG ***********
 *
 * Register of SEDI PMU
 *   FABRIC_SNAPSHOT_REG: Fabric Idle Time Out Snapshot
 *     AddressOffset  : 0x60
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, FABRIC_SNAPSHOT_REG, 0x60, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register FABRIC_SNAPSHOT_REG
 *   BR_PRIM_ACTIVE_SNAPSHOT: Bridge Prim Active Snapshot
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_PRIM_ACTIVE_SNAPSHOT, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_PRIM_ACTIVE_SNAPSHOT, 0, 0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_PRIM_ACTIVE_SNAPSHOT, 1, 1);

/*
 * Bit Field of Register FABRIC_SNAPSHOT_REG
 *   BR_SIDE_ACTIVE_SNAPSHOT: Bridge Side Active Snapshot
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_SIDE_ACTIVE_SNAPSHOT, 1, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_SIDE_ACTIVE_SNAPSHOT, 0, 0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_SIDE_ACTIVE_SNAPSHOT, 1, 1);

/*
 * Bit Field of Register FABRIC_SNAPSHOT_REG
 *   BR_OCP_ACTIVE_SNAPSHOT: Bridge OCP  Active Snapshot
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_OCP_ACTIVE_SNAPSHOT, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_OCP_ACTIVE_SNAPSHOT, 0, 0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, BR_OCP_ACTIVE_SNAPSHOT, 1, 1);

/*
 * Bit Field of Register FABRIC_SNAPSHOT_REG
 *   FABRIC_ACTIVE_SNAPSHOT: OCP  Fabric Active Snapshot
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, FABRIC_SNAPSHOT_REG, FABRIC_ACTIVE_SNAPSHOT, 3, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, FABRIC_ACTIVE_SNAPSHOT, 0, 0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, FABRIC_ACTIVE_SNAPSHOT, 1, 1);

/*
 * Bit Field of Register FABRIC_SNAPSHOT_REG
 *   HSU_ACTIVE_SNAPSHOT: UART HSU Active Snapshot
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, FABRIC_SNAPSHOT_REG, HSU_ACTIVE_SNAPSHOT, 4, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, HSU_ACTIVE_SNAPSHOT, 0, 0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, HSU_ACTIVE_SNAPSHOT, 1, 1);

/*
 * Bit Field of Register FABRIC_SNAPSHOT_REG
 *   HPET_WR_INPROGRESS_SNAPSHOT: HPET  Write InProgress Snapshot
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, FABRIC_SNAPSHOT_REG, HPET_WR_INPROGRESS_SNAPSHOT, 5, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, HPET_WR_INPROGRESS_SNAPSHOT, 0, 0);
SEDI_RBFV_DEFINE(PMU, FABRIC_SNAPSHOT_REG, HPET_WR_INPROGRESS_SNAPSHOT, 1, 1);

/*
 * Bit Field of Register FABRIC_SNAPSHOT_REG
 *   RSVD_FABRIC_SNAPSHOT: RSV
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, FABRIC_SNAPSHOT_REG, RSVD_FABRIC_SNAPSHOT, 6, 26, RO, (uint32_t)0x0);

/* ********* PMU CP_EN_REG ***********
 *
 * Register of SEDI PMU
 *   CP_EN_REG: Context Propagation Enable
 *     AddressOffset  : 0x64
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CP_EN_REG, 0x64, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register CP_EN_REG
 *   CP_EN: Force Clock For Context Propagation Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CP_EN_REG, CP_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CP_EN_REG, CP_EN, 0, 0);
SEDI_RBFV_DEFINE(PMU, CP_EN_REG, CP_EN, 1, 1);

/*
 * Bit Field of Register CP_EN_REG
 *   RSV:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CP_EN_REG, RSV, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU CG_PG_STATUS_REG ***********
 *
 * Register of SEDI PMU
 *   CG_PG_STATUS_REG: Clock Gating And Power Gating Status
 *     AddressOffset  : 0x68
 *     AccessType     : RW
 *     WritableBitMask: 0x1fff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CG_PG_STATUS_REG, 0x68, RW, (uint32_t)0x1fff, (uint32_t)0x0);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   MIA_CG_ENTRY_STATUS: Successful Minute IA CG ONLY State Entry Achieved
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, MIA_CG_ENTRY_STATUS, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, MIA_CG_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, MIA_CG_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   CG_ABORT_STATUS: Clock Gating Abort Condition
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, CG_ABORT_STATUS, 1, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, CG_ABORT_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, CG_ABORT_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   RF_ROM_PG_ENTRY_STATUS: Successful RF And ROM ONLY Power Gate Entry Achieved
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, RF_ROM_PG_ENTRY_STATUS, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, RF_ROM_PG_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, RF_ROM_PG_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   TCG_ENTRY_STATUS: Successful Trunk Clock Gate Entry Achieved
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, TCG_ENTRY_STATUS, 3, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, TCG_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, TCG_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   VNNAON_ACT_DEASRT_ENTRY_STATUS: Successful Vnnaon Active Deassertion Entry Achieved
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, VNNAON_ACT_DEASRT_ENTRY_STATUS, 4, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, VNNAON_ACT_DEASRT_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, VNNAON_ACT_DEASRT_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   PGREADY_XTAL_ENTRY_STATUS: Successful PowerGate Ready Achieved For Xtal Clock Domain
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_XTAL_ENTRY_STATUS, 5, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_XTAL_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_XTAL_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   PGREADY_MIA_ENTRY_STATUS: Successful PowerGate Ready Achieved For MIA Clock Domain
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_MIA_ENTRY_STATUS, 6, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_MIA_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_MIA_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   PGREADY_FUNC_ENTRY_STATUS: Successful PowerGate Ready Achieved For Functional Clock Domain
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_FUNC_ENTRY_STATUS, 7, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_FUNC_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_FUNC_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   PGREADY_BRPRIM_ENTRY_STATUS: Successful PowerGate Ready Achieved For Bridge Primary Clock Domain
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_BRPRIM_ENTRY_STATUS, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_BRPRIM_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_BRPRIM_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   PGREADY_BRSIDE_ENTRY_STATUS: Successful PowerGate Ready Achieved For Bridge Side Clock Domain
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_BRSIDE_ENTRY_STATUS, 9, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_BRSIDE_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_BRSIDE_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   PGREADY_SBEP_ENTRY_STATUS: Successful PowerGate Ready Achieved For SBEP Side Clock Domain
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_SBEP_ENTRY_STATUS, 10, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_SBEP_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PGREADY_SBEP_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   PG_ENTRY_STATUS: Successful PowerGate Entry Achieved
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, PG_ENTRY_STATUS, 11, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PG_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, PG_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   AONCG_ENTRY_STATUS: Successful AON Clk Gating Entry Achieved
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, AONCG_ENTRY_STATUS, 12, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, AONCG_ENTRY_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, CG_PG_STATUS_REG, AONCG_ENTRY_STATUS, 1, 1);

/*
 * Bit Field of Register CG_PG_STATUS_REG
 *   RSV:
 *     BitOffset : 13
 *     BitWidth  : 19
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CG_PG_STATUS_REG, RSV, 13, 19, RO, (uint32_t)0x0);

/* ********* PMU PCE_STATUS_0 ***********
 *
 * Register of SEDI PMU
 *   PCE_STATUS_0: PCE ShadowFor PCI Function 0
 *     AddressOffset  : 0x100
 *     AccessType     : RW
 *     WritableBitMask: 0x1e9e1f00
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, PCE_STATUS_0, 0x100, RW, (uint32_t)0x1e9e1f00, (uint32_t)0x0);

/*
 * Bit Field of Register PCE_STATUS_0
 *   PMCRE: 'PMC Request Enable (PMCRE)'
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, PMCRE, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, PMCRE, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, PMCRE, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   IDLEN: 'IDLE Enable (IDLEN)'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, IDLEN, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, IDLEN, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, IDLEN, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   D3HEN: 'D3Hot Enable (D3HEN)'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, D3HEN, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D3HEN, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D3HEN, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   SE: 'Sleep Enable (SE)'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, SE, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, SE, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, SE, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   HAE: 'Hardware Autonomous Enable (HAE)'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, HAE, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, HAE, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, HAE, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   RSVD_PCE_0_STATUS_1: RSV
 *     BitOffset : 5
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, RSVD_PCE_0_STATUS_1, 5, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_PMCRE: 'PMC Request Enable Mask (PMCRE)'
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_PMCRE, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_PMCRE, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_PMCRE, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_IDLEN: 'IDLE Enable Mask (IDLEN)'
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_IDLEN, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_IDLEN, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_IDLEN, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_D3HEN: 'D3Hot Enable Mask (D3HEN)'
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_D3HEN, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_D3HEN, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_D3HEN, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_SE: 'Sleep Enable Mask (SE)'
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_SE, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_SE, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_SE, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_HAE: 'Hardware Autonomous Enable Mask (HAE)'
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_HAE, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_HAE, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_HAE, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   RSVD_PCE_0_STATUS_2: RSV
 *     BitOffset : 13
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, RSVD_PCE_0_STATUS_2, 13, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PCE_STATUS_0
 *   D3_LIVE_STATUS: D3 Live Status Bit
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, D3_LIVE_STATUS, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D3_LIVE_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D3_LIVE_STATUS, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   D3_RISING_EDGE_INTR_STATUS: D3 Rise  Edge INTR Status
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, D3_RISING_EDGE_INTR_STATUS, 17, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D3_RISING_EDGE_INTR_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D3_RISING_EDGE_INTR_STATUS, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   D3_FALLING_EDGE_INTR_STATUS: D3 Fall Edge INTR Status
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, D3_FALLING_EDGE_INTR_STATUS, 18, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D3_FALLING_EDGE_INTR_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D3_FALLING_EDGE_INTR_STATUS, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_D3_RISING_EDGE_INTR: D3 Rise  Edge INTR Mask
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_D3_RISING_EDGE_INTR, 19, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_D3_RISING_EDGE_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_D3_RISING_EDGE_INTR, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_D3_FALLING_EDGE_INTR: D3 Fall Edge INTR Mask
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_D3_FALLING_EDGE_INTR, 20, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_D3_FALLING_EDGE_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_D3_FALLING_EDGE_INTR, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   D0I3_CIP_LIVE_STATUS: D0i3 CIP Live Status
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, D0I3_CIP_LIVE_STATUS, 21, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D0I3_CIP_LIVE_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D0I3_CIP_LIVE_STATUS, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   D0I3_LIVE_STATUS: D0i3 Live Status
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, D0I3_LIVE_STATUS, 22, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D0I3_LIVE_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, D0I3_LIVE_STATUS, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_D0I3: D0i3 Enable Mask
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_D0I3, 23, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_D0I3, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_D0I3, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   BME_LIVE_STATUS: BME Live Status Bit
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, BME_LIVE_STATUS, 24, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, BME_LIVE_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, BME_LIVE_STATUS, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   BME_RISE_EDGE_INTR_STATUS: BME Rise  Edge INTR Status
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, BME_RISE_EDGE_INTR_STATUS, 25, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, BME_RISE_EDGE_INTR_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, BME_RISE_EDGE_INTR_STATUS, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   BME_FALL_EDGE_INTR_STATUS: BME Fall Edge INTR Status
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, BME_FALL_EDGE_INTR_STATUS, 26, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, BME_FALL_EDGE_INTR_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, BME_FALL_EDGE_INTR_STATUS, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_BME_RISE_EDGE_INTR: BME Rise  Edge INTR Mask
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_BME_RISE_EDGE_INTR, 27, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_BME_RISE_EDGE_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_BME_RISE_EDGE_INTR, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   MASK_BME_FALL_EDGE_INTR: BME Fall Edge INTR Mask
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, MASK_BME_FALL_EDGE_INTR, 28, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_BME_FALL_EDGE_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_STATUS_0, MASK_BME_FALL_EDGE_INTR, 1, 1);

/*
 * Bit Field of Register PCE_STATUS_0
 *   RSVD_PCE_0_STATUS_3: RSV
 *     BitOffset : 29
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_STATUS_0, RSVD_PCE_0_STATUS_3, 29, 3, RO, (uint32_t)0x0);

/* ********* PMU PCE_STATUS_1 ***********
 *
 * Register of SEDI PMU
 *   PCE_STATUS_0: PCE ShadowFor PCI Function 0
 *     AddressOffset  : 0x104
 *     AccessType     : RW
 *     WritableBitMask: 0x1e9e1f00
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, PCE_STATUS_1, 0x104, RW, (uint32_t)0x1e9e1f00, (uint32_t)0x0);

/* ********* PMU D3_RISE_INTR_MASK_REG_0 ***********
 *
 * Register of SEDI PMU
 *   D3_RISE_INTR_MASK_REG_0: Bridge D3 Rise Interrupt Wake Mask
 *     AddressOffset  : 0x200
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, D3_RISE_INTR_MASK_REG_0, 0x200, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register D3_RISE_INTR_MASK_REG_0
 *   D3_RISE_INTR_MASK_0: D3 Rise Wake Mask For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 * Note: keep consistent to ISH_MASK_EVENT naming rule manually
 */
SEDI_RBF_DEFINE(PMU, D3_RISE_INTR_MASK_REG_0, MASK_D3_RISE_INTR_0_WK, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, D3_RISE_INTR_MASK_REG_0, MASK_D3_RISE_INTR_0_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, D3_RISE_INTR_MASK_REG_0, MASK_D3_RISE_INTR_0_WK, 1, 1);

/*
 * Bit Field of Register D3_RISE_INTR_MASK_REG_0
 *   D3_RISE_INTR_MASK_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_RISE_INTR_MASK_REG_0, D3_RISE_INTR_MASK_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU D3_FALL_INTR_MASK_REG_0 ***********
 *
 * Register of SEDI PMU
 *   D3_FALL_INTR_MASK_REG_0: Bridge D3 Fall Interrupt Wake Mask
 *     AddressOffset  : 0x208
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, D3_FALL_INTR_MASK_REG_0, 0x208, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register D3_FALL_INTR_MASK_REG_0
 *   D3_FALL_INTR_MASK_0: D3 Fall Wake Mask For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 * Note: keep consistent to ISH_MASK_EVENT naming rule manually
 */
SEDI_RBF_DEFINE(PMU, D3_FALL_INTR_MASK_REG_0, MASK_D3_FALL_INTR_0_WK, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, D3_FALL_INTR_MASK_REG_0, MASK_D3_FALL_INTR_0_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, D3_FALL_INTR_MASK_REG_0, MASK_D3_FALL_INTR_0_WK, 1, 1);

/*
 * Bit Field of Register D3_FALL_INTR_MASK_REG_0
 *   D3_FALL_INTR_MASK_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_FALL_INTR_MASK_REG_0, D3_FALL_INTR_MASK_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU D3_RISE_INTR_REG_0 ***********
 *
 * Register of SEDI PMU
 *   D3_RISE_INTR_REG_0: Bridge D3 Rise Interrupt Wake
 *     AddressOffset  : 0x210
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, D3_RISE_INTR_REG_0, 0x210, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register D3_RISE_INTR_REG_0
 *   D3_RISE_INTR_0: D3 Rise Wake Record For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_RISE_INTR_REG_0, D3_RISE_INTR_0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, D3_RISE_INTR_REG_0, D3_RISE_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, D3_RISE_INTR_REG_0, D3_RISE_INTR_0, 1, 1);

/*
 * Bit Field of Register D3_RISE_INTR_REG_0
 *   D3_RISE_INTR_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_RISE_INTR_REG_0, D3_RISE_INTR_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU D3_FALL_INTR_REG_0 ***********
 *
 * Register of SEDI PMU
 *   D3_FALL_INTR_REG_0: Bridge D3 Fall Interrupt Wake
 *     AddressOffset  : 0x218
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, D3_FALL_INTR_REG_0, 0x218, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register D3_FALL_INTR_REG_0
 *   D3_FALL_INTR_0: D3 Fall Wake Record For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_FALL_INTR_REG_0, D3_FALL_INTR_0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, D3_FALL_INTR_REG_0, D3_FALL_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, D3_FALL_INTR_REG_0, D3_FALL_INTR_0, 1, 1);

/*
 * Bit Field of Register D3_FALL_INTR_REG_0
 *   D3_FALL_INTR_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_FALL_INTR_REG_0, D3_FALL_INTR_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU BME_RISE_INTR_MASK_REG_0 ***********
 *
 * Register of SEDI PMU
 *   BME_RISE_INTR_MASK_REG_0: BME Rise Interrupt Wake Mask
 *     AddressOffset  : 0x220
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, BME_RISE_INTR_MASK_REG_0, 0x220, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register BME_RISE_INTR_MASK_REG_0
 *   BME_RISE_INTR_MASK_0: BME Rise Wake Mask For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 * Note: keep consistent to ISH_MASK_EVENT naming rule manually
 */
SEDI_RBF_DEFINE(PMU, BME_RISE_INTR_MASK_REG_0, MASK_BME_RISE_INTR_0_WK, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, BME_RISE_INTR_MASK_REG_0, MASK_BME_RISE_INTR_0_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, BME_RISE_INTR_MASK_REG_0, MASK_BME_RISE_INTR_0_WK, 1, 1);

/*
 * Bit Field of Register BME_RISE_INTR_MASK_REG_0
 *   BME_RISE_INTR_MASK_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BME_RISE_INTR_MASK_REG_0, BME_RISE_INTR_MASK_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU BME_FALL_INTR_MASK_REG_0 ***********
 *
 * Register of SEDI PMU
 *   BME_FALL_INTR_MASK_REG_0: BME Fall Interrupt Wake Mask
 *     AddressOffset  : 0x228
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, BME_FALL_INTR_MASK_REG_0, 0x228, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register BME_FALL_INTR_MASK_REG_0
 *   BME_FALL_INTR_MASK_0: BME Fall Wake Mask For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 * Note: keep consistent to ISH_MASK_EVENT naming rule manually
 */
SEDI_RBF_DEFINE(PMU, BME_FALL_INTR_MASK_REG_0, MASK_BME_FALL_INTR_0_WK, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, BME_FALL_INTR_MASK_REG_0, MASK_BME_FALL_INTR_0_WK, 0, 0);
SEDI_RBFV_DEFINE(PMU, BME_FALL_INTR_MASK_REG_0, MASK_BME_FALL_INTR_0_WK, 1, 1);

/*
 * Bit Field of Register BME_FALL_INTR_MASK_REG_0
 *   BME_FALL_INTR_MASK_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BME_FALL_INTR_MASK_REG_0, BME_FALL_INTR_MASK_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU BME_RISE_INTR_REG_0 ***********
 *
 * Register of SEDI PMU
 *   BME_RISE_INTR_REG_0: BME Rise Interrupt Wake
 *     AddressOffset  : 0x230
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, BME_RISE_INTR_REG_0, 0x230, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register BME_RISE_INTR_REG_0
 *   BME_RISE_INTR_0: BME Rise Wake Record For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BME_RISE_INTR_REG_0, BME_RISE_INTR_0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, BME_RISE_INTR_REG_0, BME_RISE_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, BME_RISE_INTR_REG_0, BME_RISE_INTR_0, 1, 1);

/*
 * Bit Field of Register BME_RISE_INTR_REG_0
 *   BME_RISE_INTR_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BME_RISE_INTR_REG_0, BME_RISE_INTR_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU BME_FALL_INTR_REG_0 ***********
 *
 * Register of SEDI PMU
 *   BME_FALL_INTR_REG_0: BME Fall Interrupt Wake
 *     AddressOffset  : 0x238
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, BME_FALL_INTR_REG_0, 0x238, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register BME_FALL_INTR_REG_0
 *   BME_FALL_INTR_0: BME Fall Wake Record For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BME_FALL_INTR_REG_0, BME_FALL_INTR_0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, BME_FALL_INTR_REG_0, BME_FALL_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, BME_FALL_INTR_REG_0, BME_FALL_INTR_0, 1, 1);

/*
 * Bit Field of Register BME_FALL_INTR_REG_0
 *   BME_FALL_INTR_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BME_FALL_INTR_REG_0, BME_FALL_INTR_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU D3_INTR_MASK_REG_0 ***********
 *
 * Register of SEDI PMU
 *   D3_INTR_MASK_REG_0: Bridge D3 Interrupt Wake Mask
 *     AddressOffset  : 0x240
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, D3_INTR_MASK_REG_0, 0x240, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register D3_INTR_MASK_REG_0
 *   D3_INTR_MASK_0: D3 Wake Mask For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_INTR_MASK_REG_0, D3_INTR_MASK_0, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, D3_INTR_MASK_REG_0, D3_INTR_MASK_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, D3_INTR_MASK_REG_0, D3_INTR_MASK_0, 1, 1);

/*
 * Bit Field of Register D3_INTR_MASK_REG_0
 *   D3_INTR_MASK_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_INTR_MASK_REG_0, D3_INTR_MASK_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU D3_INTR_REG_0 ***********
 *
 * Register of SEDI PMU
 *   D3_INTR_REG_0: Bridge D3 Interrupt Wake
 *     AddressOffset  : 0x248
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, D3_INTR_REG_0, 0x248, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register D3_INTR_REG_0
 *   D3_INTR_0: D3 Wake Record For PCI Function 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_INTR_REG_0, D3_INTR_0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, D3_INTR_REG_0, D3_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, D3_INTR_REG_0, D3_INTR_0, 1, 1);

/*
 * Bit Field of Register D3_INTR_REG_0
 *   D3_INTR_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D3_INTR_REG_0, D3_INTR_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU GPIO_INTR_MASK_REG_0 ***********
 *
 * Register of SEDI PMU
 *   GPIO_INTR_MASK_REG_0: GPIO Interrupt Mask
 *     AddressOffset  : 0x250
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, GPIO_INTR_MASK_REG_0, 0x250, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_0: GPIO Wake Mask For GPIO_0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_0, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_0, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_1: GPIO Wake Mask For GPIO_1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_1, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_1, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_1, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_2: GPIO Wake Mask For GPIO_2
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_2, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_2, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_2, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_3: GPIO Wake Mask For GPIO_3
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_3, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_3, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_3, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_4: GPIO Wake Mask For GPIO_4
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_4, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_4, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_4, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_5: GPIO Wake Mask For GPIO_5
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_5, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_5, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_5, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_6: GPIO Wake Mask For GPIO_6
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_6, 6, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_6, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_6, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_7: GPIO Wake Mask For GPIO_7
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_7, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_7, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_7, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_8: GPIO Wake Mask For GPIO_8
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_8, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_8, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_8, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_9: GPIO Wake Mask For GPIO_9
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_9, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_9, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_9, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_10: GPIO Wake Mask For GPIO_10
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_10, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_10, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_10, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_11: GPIO Wake Mask For GPIO_11
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_11, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_11, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_11, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_12: GPIO Wake Mask For GPIO_12
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_12, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_12, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_12, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_13: GPIO Wake Mask For GPIO_13
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_13, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_13, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_13, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_14: GPIO Wake Mask For GPIO_14
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_14, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_14, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_14, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_15: GPIO Wake Mask For GPIO_15
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_15, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_15, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_15, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_16: GPIO Wake Mask For GPIO_16
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_16, 16, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_16, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_16, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_17: GPIO Wake Mask For GPIO_17
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_17, 17, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_17, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_17, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_18: GPIO Wake Mask For GPIO_18
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_18, 18, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_18, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_18, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_19: GPIO Wake Mask For GPIO_19
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_19, 19, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_19, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_19, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_20: GPIO Wake Mask For GPIO_20
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_20, 20, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_20, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_20, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_21: GPIO Wake Mask For GPIO_21
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_21, 21, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_21, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_21, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_22: GPIO Wake Mask For GPIO_22
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_22, 22, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_22, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_22, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_23: GPIO Wake Mask For GPIO_23
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_23, 23, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_23, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_23, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_24: GPIO Wake Mask For GPIO_24
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_24, 24, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_24, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_24, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_25: GPIO Wake Mask For GPIO_25
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_25, 25, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_25, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_25, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_26: GPIO Wake Mask For GPIO_26
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_26, 26, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_26, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_26, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_27: GPIO Wake Mask For GPIO_27
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_27, 27, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_27, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_27, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_28: GPIO Wake Mask For GPIO_28
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_28, 28, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_28, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_28, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_29: GPIO Wake Mask For GPIO_29
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_29, 29, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_29, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_29, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_30: GPIO Wake Mask For GPIO_30
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_30, 30, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_30, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_30, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_0
 *   GPIO_INTR_MASK_31: GPIO Wake Mask For GPIO_31
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_31, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_31, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_0, GPIO_INTR_MASK_31, 1, 1);

/* ********* PMU GPIO_INTR_MASK_REG_1 ***********
 *
 * Register of SEDI PMU
 *   GPIO_INTR_MASK_REG_1: GPIO Interrupt Mask
 *     AddressOffset  : 0x254
 *     AccessType     : RW
 *     WritableBitMask: 0x1f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, GPIO_INTR_MASK_REG_1, 0x254, RW, (uint32_t)0x1f, (uint32_t)0x0);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_1
 *   GPIO_INTR_MASK_32: 'GPIO Wake Mask For GPIO_32 (UART 0 CTS)'
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_32, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_32, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_32, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_1
 *   GPIO_INTR_MASK_33: 'GPIO Wake Mask For GPIO_33 (UART 1 CTS)'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_33, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_33, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_33, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_1
 *   GPIO_INTR_MASK_34: 'GPIO Wake Mask For GPIO_34 (UART 2 CTS)'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_34, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_34, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_34, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_1
 *   GPIO_INTR_MASK_35: 'GPIO Wake Mask For GPIO_35 (I3C 0 IBI Wake)'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_35, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_35, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_35, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_1
 *   GPIO_INTR_MASK_36: 'GPIO Wake Mask For GPIO_36 (I3C 1 IBI Wake)'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_36, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_36, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_36, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_MASK_REG_1
 *   GPIO_INTR_MASK_RSVD: RSVD
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_MASK_REG_1, GPIO_INTR_MASK_RSVD, 5, 27, RO, (uint32_t)0x0);

/* ********* PMU GPIO_INTR_REG_0 ***********
 *
 * Register of SEDI PMU
 *   GPIO_INTR_REG_0: GPIO Wake Interrupt Record
 *     AddressOffset  : 0x270
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, GPIO_INTR_REG_0, 0x270, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_0: GPIO Wake Record For GPIO_0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_0, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_1: GPIO Wake Record For GPIO_1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_1, 1, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_1, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_1, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_2: GPIO Wake Record For GPIO_2
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_2, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_2, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_2, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_3: GPIO Wake Record For GPIO_3
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_3, 3, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_3, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_3, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_4: GPIO Wake Record For GPIO_4
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_4, 4, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_4, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_4, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_5: GPIO Wake Record For GPIO_5
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_5, 5, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_5, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_5, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_6: GPIO Wake Record For GPIO_6
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_6, 6, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_6, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_6, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_7: GPIO Wake Record For GPIO_7
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_7, 7, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_7, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_7, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_8: GPIO Wake Record For GPIO_8
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_8, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_8, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_8, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_9: GPIO Wake Record For GPIO_9
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_9, 9, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_9, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_9, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_10: GPIO Wake Record For GPIO_10
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_10, 10, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_10, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_10, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_11: GPIO Wake Record For GPIO_11
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_11, 11, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_11, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_11, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_12: GPIO Wake Record For GPIO_12
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_12, 12, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_12, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_12, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_13: GPIO Wake Record For GPIO_13
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_13, 13, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_13, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_13, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_14: GPIO Wake Record For GPIO_14
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_14, 14, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_14, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_14, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_15: GPIO Wake Record For GPIO_15
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_15, 15, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_15, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_15, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_16: GPIO Wake Record For GPIO_16
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_16, 16, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_16, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_16, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_17: GPIO Wake Record For GPIO_17
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_17, 17, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_17, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_17, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_18: GPIO Wake Record For GPIO_18
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_18, 18, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_18, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_18, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_19: GPIO Wake Record For GPIO_19
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_19, 19, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_19, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_19, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_20: GPIO Wake Record For GPIO_20
 *     BitOffset : 20
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_20, 20, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_20, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_20, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_21: GPIO Wake Record For GPIO_21
 *     BitOffset : 21
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_21, 21, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_21, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_21, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_22: GPIO Wake Record For GPIO_22
 *     BitOffset : 22
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_22, 22, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_22, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_22, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_23: GPIO Wake Record For GPIO_23
 *     BitOffset : 23
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_23, 23, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_23, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_23, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_24: GPIO Wake Record For GPIO_24
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_24, 24, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_24, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_24, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_25: GPIO Wake Record For GPIO_25
 *     BitOffset : 25
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_25, 25, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_25, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_25, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_26: GPIO Wake Record For GPIO_26
 *     BitOffset : 26
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_26, 26, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_26, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_26, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_27: GPIO Wake Record For GPIO_27
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_27, 27, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_27, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_27, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_28: GPIO Wake Record For GPIO_28
 *     BitOffset : 28
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_28, 28, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_28, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_28, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_29: GPIO Wake Record For GPIO_29
 *     BitOffset : 29
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_29, 29, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_29, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_29, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_30: GPIO Wake Record For GPIO_30
 *     BitOffset : 30
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_30, 30, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_30, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_30, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_0
 *   GPIO_INTR_31: GPIO Wake Record For GPIO_31
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_31, 31, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_31, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_0, GPIO_INTR_31, 1, 1);

/* ********* PMU GPIO_INTR_REG_1 ***********
 *
 * Register of SEDI PMU
 *   GPIO_INTR_REG_1: GPIO Wake Interrupt Record
 *     AddressOffset  : 0x274
 *     AccessType     : RW
 *     WritableBitMask: 0x1f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, GPIO_INTR_REG_1, 0x274, RW, (uint32_t)0x1f, (uint32_t)0x0);

/*
 * Bit Field of Register GPIO_INTR_REG_1
 *   GPIO_INTR_32: 'GPIO Wake Record For GPIO_32 (UART0 CTS)'
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_32, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_32, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_32, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_1
 *   GPIO_INTR_33: 'GPIO Wake Record For GPIO_33 (UART1 CTS)'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_33, 1, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_33, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_33, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_1
 *   GPIO_INTR_34: 'GPIO Wake Record For GPIO_34 (UART2 CTS)'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_34, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_34, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_34, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_1
 *   GPIO_INTR_35: 'GPIO Wake Record For GPIO_35 (I3C 0 IBI Wake)'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_35, 3, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_35, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_35, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_1
 *   GPIO_INTR_36: 'GPIO Wake Record For GPIO_36 (I3C 1 IBI Wake)'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_36, 4, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_36, 0, 0);
SEDI_RBFV_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_36, 1, 1);

/*
 * Bit Field of Register GPIO_INTR_REG_1
 *   GPIO_INTR_RSVD: RSVD
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, GPIO_INTR_REG_1, GPIO_INTR_RSVD, 5, 27, RO, (uint32_t)0x0);

/* ********* PMU I2S_INTR_REG ***********
 *
 * Register of SEDI PMU
 *   I2S_INTR_REG: PWM And I2S Wake Interrupt
 *     AddressOffset  : 0x290
 *     AccessType     : RW
 *     WritableBitMask: 0x101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, I2S_INTR_REG, 0x290, RW, (uint32_t)0x101, (uint32_t)0x0);

/*
 * Bit Field of Register I2S_INTR_REG
 *   I2S_INTR__0: Reserved Wake Record Register For I2S_0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, I2S_INTR_REG, I2S_INTR__0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, I2S_INTR_REG, I2S_INTR__0, 0, 0);
SEDI_RBFV_DEFINE(PMU, I2S_INTR_REG, I2S_INTR__0, 1, 1);

/*
 * Bit Field of Register I2S_INTR_REG
 *   RSVD_INTR_I2S_1: RSV
 *     BitOffset : 1
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, I2S_INTR_REG, RSVD_INTR_I2S_1, 1, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register I2S_INTR_REG
 *   PWM_INTR_0: RSV
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, I2S_INTR_REG, PWM_INTR_0, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, I2S_INTR_REG, PWM_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, I2S_INTR_REG, PWM_INTR_0, 1, 1);

/*
 * Bit Field of Register I2S_INTR_REG
 *   RSVD_INTR_I2S: RSVD
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, I2S_INTR_REG, RSVD_INTR_I2S, 9, 23, RO, (uint32_t)0x0);

/* ********* PMU I2S_INTR_MASK_REG ***********
 *
 * Register of SEDI PMU
 *   I2S_INTR_MASK_REG: I2S Interrupt Mask
 *     AddressOffset  : 0x294
 *     AccessType     : RW
 *     WritableBitMask: 0x101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, I2S_INTR_MASK_REG, 0x294, RW, (uint32_t)0x101, (uint32_t)0x0);

/*
 * Bit Field of Register I2S_INTR_MASK_REG
 *   I2S_INTR_MASK_0: Reserved Wake Mask For I2S_0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, I2S_INTR_MASK_REG, I2S_INTR_MASK_0, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, I2S_INTR_MASK_REG, I2S_INTR_MASK_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, I2S_INTR_MASK_REG, I2S_INTR_MASK_0, 1, 1);

/*
 * Bit Field of Register I2S_INTR_MASK_REG
 *   RSVD_INTR_MASK_I2S_1: RSV
 *     BitOffset : 1
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, I2S_INTR_MASK_REG, RSVD_INTR_MASK_I2S_1, 1, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register I2S_INTR_MASK_REG
 *   PWM_INTR_MASK_0: RSV
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, I2S_INTR_MASK_REG, PWM_INTR_MASK_0, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, I2S_INTR_MASK_REG, PWM_INTR_MASK_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, I2S_INTR_MASK_REG, PWM_INTR_MASK_0, 1, 1);

/*
 * Bit Field of Register I2S_INTR_MASK_REG
 *   RSVD_INTR_MASK_I2S: RSVD
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, I2S_INTR_MASK_REG, RSVD_INTR_MASK_I2S, 9, 23, RO, (uint32_t)0x0);

/* ********* PMU ETHER_INTR_REG ***********
 *
 * Register of SEDI PMU
 *   ETHER_INTR_REG: IETHERNET Wake Interrupt
 *     AddressOffset  : 0x298
 *     AccessType     : RW
 *     WritableBitMask: 0x1010101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, ETHER_INTR_REG, 0x298, RW, (uint32_t)0x1010101, (uint32_t)0x0);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   ETHERNET_INTR_0: Reserved Wake Record Register For Ethernet_0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, ETHERNET_INTR_0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, ETHERNET_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, ETHERNET_INTR_0, 1, 1);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   RSVD_ETHER_INTR_REG_1: RSV
 *     BitOffset : 1
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, RSVD_ETHER_INTR_REG_1, 1, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   ETHERCAT_INTR_0: Reserved Wake Record Register For Ethercat
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, ETHERCAT_INTR_0, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, ETHERCAT_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, ETHERCAT_INTR_0, 1, 1);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   RSVD_ETHER_INTR_REG_2: RSV
 *     BitOffset : 9
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, RSVD_ETHER_INTR_REG_2, 9, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   CANBUS_INTR_0: RSV
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, CANBUS_INTR_0, 16, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, CANBUS_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, CANBUS_INTR_0, 1, 1);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   CANBUS_INTR_1: RSV
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, CANBUS_INTR_1, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, CANBUS_INTR_1, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, CANBUS_INTR_1, 1, 1);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   RSVD_ETHER_INTR_REG_3: RSV
 *     BitOffset : 18
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, RSVD_ETHER_INTR_REG_3, 18, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   TSN_SWITCH_INTR_0: Reserved Wake Record Register For TSN Switch
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, TSN_SWITCH_INTR_0, 24, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, TSN_SWITCH_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHER_INTR_REG, TSN_SWITCH_INTR_0, 1, 1);

/*
 * Bit Field of Register ETHER_INTR_REG
 *   RSVD_ETHER_INTR_REG_4: RSV
 *     BitOffset : 25
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHER_INTR_REG, RSVD_ETHER_INTR_REG_4, 25, 7, RO, (uint32_t)0x0);

/* ********* PMU ETHERNET_INTR_MASK_REG ***********
 *
 * Register of SEDI PMU
 *   ETHERNET_INTR_MASK_REG: ETHERNET Interrupt Mask
 *     AddressOffset  : 0x29c
 *     AccessType     : RW
 *     WritableBitMask: 0x1010101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, ETHERNET_INTR_MASK_REG, 0x29c, RW, (uint32_t)0x1010101, (uint32_t)0x0);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   ETHERNET_INTR_MASK_0: Reserved Wake Mask For ETHERNET_0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERNET_INTR_MASK_0, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERNET_INTR_MASK_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERNET_INTR_MASK_0, 1, 1);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   ETHERNET_INTR_MASK_2_7: RSV
 *     BitOffset : 1
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERNET_INTR_MASK_2_7, 1, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   ETHERCAT_INTR_MASK_0: Reserved Wake Mask For ETHERCAT
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERCAT_INTR_MASK_0, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERCAT_INTR_MASK_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERCAT_INTR_MASK_0, 1, 1);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   ETHERNET_INTR_MASK_9_11: RSV
 *     BitOffset : 9
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERNET_INTR_MASK_9_11, 9, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   ETHERNET_INTR_MASK_12_15: RSV
 *     BitOffset : 12
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, ETHERNET_INTR_MASK_12_15, 12, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   CANBUS_INTR_MASK_0: Wake Mask For CANBUS_0
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, CANBUS_INTR_MASK_0, 16, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, CANBUS_INTR_MASK_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, CANBUS_INTR_MASK_0, 1, 1);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   CANBUS_INTR_MASK_1: Wake Mask For CANBUS_1
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, CANBUS_INTR_MASK_1, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, CANBUS_INTR_MASK_1, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, CANBUS_INTR_MASK_1, 1, 1);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   RSVD_INTR_MASK_ETHERNET_3: RSV
 *     BitOffset : 18
 *     BitWidth  : 6
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, RSVD_INTR_MASK_ETHERNET_3, 18, 6, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   MASK_TSN_SWITCH_INTR: Reserved Wake Mask For TSN_SWITCH
 *     BitOffset : 24
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, MASK_TSN_SWITCH_INTR, 24, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, MASK_TSN_SWITCH_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, ETHERNET_INTR_MASK_REG, MASK_TSN_SWITCH_INTR, 1, 1);

/*
 * Bit Field of Register ETHERNET_INTR_MASK_REG
 *   RSVD_INTR_MASK_ETHERNET_4: RSV
 *     BitOffset : 25
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ETHERNET_INTR_MASK_REG, RSVD_INTR_MASK_ETHERNET_4, 25, 7, RO, (uint32_t)0x0);

/* ********* PMU QEP_INTR_REG ***********
 *
 * Register of SEDI PMU
 *   QEP_INTR_REG: QEP Wake Interrupt
 *     AddressOffset  : 0x2a0
 *     AccessType     : RW
 *     WritableBitMask: 0x101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, QEP_INTR_REG, 0x2a0, RW, (uint32_t)0x101, (uint32_t)0x0);

/*
 * Bit Field of Register QEP_INTR_REG
 *   RSVD_QEP_INTR_0: RSV
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_REG, RSVD_QEP_INTR_0, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, QEP_INTR_REG, RSVD_QEP_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, QEP_INTR_REG, RSVD_QEP_INTR_0, 1, 1);

/*
 * Bit Field of Register QEP_INTR_REG
 *   RSVD_QEP_INTR: RSV
 *     BitOffset : 1
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_REG, RSVD_QEP_INTR, 1, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register QEP_INTR_REG
 *   RSVD_QEP_INTR_REG_1: RSV
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_REG, RSVD_QEP_INTR_REG_1, 4, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register QEP_INTR_REG
 *   ADC_INTR_0: Reserved Wake Record Register For ADC_0
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_REG, ADC_INTR_0, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, QEP_INTR_REG, ADC_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, QEP_INTR_REG, ADC_INTR_0, 1, 1);

/*
 * Bit Field of Register QEP_INTR_REG
 *   RSVD_QEP_INTR_REG_2: RSV
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_REG, RSVD_QEP_INTR_REG_2, 9, 23, RO, (uint32_t)0x0);

/* ********* PMU QEP_INTR_MASK_REG ***********
 *
 * Register of SEDI PMU
 *   QEP_INTR_MASK_REG: QEP Interrupt Mask
 *     AddressOffset  : 0x2a4
 *     AccessType     : RW
 *     WritableBitMask: 0x101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, QEP_INTR_MASK_REG, 0x2a4, RW, (uint32_t)0x101, (uint32_t)0x0);

/*
 * Bit Field of Register QEP_INTR_MASK_REG
 *   MASK_RSVD_QEP_INTR: RSV
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_MASK_REG, MASK_RSVD_QEP_INTR, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, QEP_INTR_MASK_REG, MASK_RSVD_QEP_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, QEP_INTR_MASK_REG, MASK_RSVD_QEP_INTR, 1, 1);

/*
 * Bit Field of Register QEP_INTR_MASK_REG
 *   RSVD_QEP_INTR_MASK_3: RSV
 *     BitOffset : 1
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_MASK_REG, RSVD_QEP_INTR_MASK_3, 1, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register QEP_INTR_MASK_REG
 *   RSVD_INTR_MASK_QEP_1: RSV
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_MASK_REG, RSVD_INTR_MASK_QEP_1, 4, 4, RO, (uint32_t)0x0);

/*
 * Bit Field of Register QEP_INTR_MASK_REG
 *   ADC_INTR_MASK_0: Wake Mask For ADC_0
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_MASK_REG, ADC_INTR_MASK_0, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, QEP_INTR_MASK_REG, ADC_INTR_MASK_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, QEP_INTR_MASK_REG, ADC_INTR_MASK_0, 1, 1);

/*
 * Bit Field of Register QEP_INTR_MASK_REG
 *   RSVD_INTR_MASK_QEP_2: RSV
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, QEP_INTR_MASK_REG, RSVD_INTR_MASK_QEP_2, 9, 23, RO, (uint32_t)0x0);

/* ********* PMU ADR_LART_UPD_REG ***********
 *
 * Register of SEDI PMU
 *   ADR_LART_UPD_REG: PMU LART Update
 *     AddressOffset  : 0x2a8
 *     AccessType     : RW
 *     WritableBitMask: 0x301
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, ADR_LART_UPD_REG, 0x2a8, RW, (uint32_t)0x301, (uint32_t)0x0);

/*
 * Bit Field of Register ADR_LART_UPD_REG
 *   LART_UPD_EN: PMU LART Update Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ADR_LART_UPD_REG, LART_UPD_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ADR_LART_UPD_REG, LART_UPD_EN, 0, 0);
SEDI_RBFV_DEFINE(PMU, ADR_LART_UPD_REG, LART_UPD_EN, 1, 1);

/*
 * Bit Field of Register ADR_LART_UPD_REG
 *   LART_UPD_RSVD0: RSV
 *     BitOffset : 1
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ADR_LART_UPD_REG, LART_UPD_RSVD0, 1, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register ADR_LART_UPD_REG
 *   LART_UPD_INT: PMU LART Update Interrupt Status
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ADR_LART_UPD_REG, LART_UPD_INT, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ADR_LART_UPD_REG, LART_UPD_INT, 0, 0);
SEDI_RBFV_DEFINE(PMU, ADR_LART_UPD_REG, LART_UPD_INT, 1, 1);

/*
 * Bit Field of Register ADR_LART_UPD_REG
 *   MASK_LART_UPD_INT: PMU LART Update Interrupt Mask
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ADR_LART_UPD_REG, MASK_LART_UPD_INT, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ADR_LART_UPD_REG, MASK_LART_UPD_INT, 0, 0);
SEDI_RBFV_DEFINE(PMU, ADR_LART_UPD_REG, MASK_LART_UPD_INT, 1, 1);

/*
 * Bit Field of Register ADR_LART_UPD_REG
 *   LART_UPD_RSVD1: RSV
 *     BitOffset : 10
 *     BitWidth  : 22
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ADR_LART_UPD_REG, LART_UPD_RSVD1, 10, 22, RO, (uint32_t)0x0);

/* ********* PMU PCE_INTR_REG_0 ***********
 *
 * Register of SEDI PMU
 *   PCE_INTR_REG_0: PCI Interrupt
 *     AddressOffset  : 0x2b0
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, PCE_INTR_REG_0, 0x2b0, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register PCE_INTR_REG_0
 *   PCE_INTR_0: PCI Interrupt Record For PCI_0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_INTR_REG_0, PCE_INTR_0, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_INTR_REG_0, PCE_INTR_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_INTR_REG_0, PCE_INTR_0, 1, 1);

/*
 * Bit Field of Register PCE_INTR_REG_0
 *   PCE_INTR_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_INTR_REG_0, PCE_INTR_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU D0I3_CIP_INTR_REG_0 ***********
 *
 * Register of SEDI PMU
 *   D0I3_CIP_INTR_REG_0: D0i3 Interrupt
 *     AddressOffset  : 0x2b8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, D0I3_CIP_INTR_REG_0, 0x2b8, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register D0I3_CIP_INTR_REG_0
 *   D0I3_INTR_STATUS_0: D0i3 CIP Interrupt Status For PCI Function_0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D0I3_CIP_INTR_REG_0, D0I3_INTR_STATUS_0, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, D0I3_CIP_INTR_REG_0, D0I3_INTR_STATUS_0, 0, 0);
SEDI_RBFV_DEFINE(PMU, D0I3_CIP_INTR_REG_0, D0I3_INTR_STATUS_0, 1, 1);

/*
 * Bit Field of Register D0I3_CIP_INTR_REG_0
 *   D0I3_INTR_STATUS_RSVD: RSVD
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, D0I3_CIP_INTR_REG_0, D0I3_INTR_STATUS_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU XTAL_CLK_REQ_REG ***********
 *
 * Register of SEDI PMU
 *   XTAL_CLK_REQ_REG: XTAL Clk Reg
 *     AddressOffset  : 0x2c0
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, XTAL_CLK_REQ_REG, 0x2c0, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register XTAL_CLK_REQ_REG
 *   XTAL_CLK_REQ: Config Bit For XTAL Gclkreq
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, XTAL_CLK_REQ_REG, XTAL_CLK_REQ, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, XTAL_CLK_REQ_REG, XTAL_CLK_REQ, 0, 0);
SEDI_RBFV_DEFINE(PMU, XTAL_CLK_REQ_REG, XTAL_CLK_REQ, 1, 1);

/*
 * Bit Field of Register XTAL_CLK_REQ_REG
 *   XTAL_CLK_ACK: Live Status Of XTAL Gclkack
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, XTAL_CLK_REQ_REG, XTAL_CLK_ACK, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, XTAL_CLK_REQ_REG, XTAL_CLK_ACK, 0, 0);
SEDI_RBFV_DEFINE(PMU, XTAL_CLK_REQ_REG, XTAL_CLK_ACK, 1, 1);

/*
 * Bit Field of Register XTAL_CLK_REQ_REG
 *   XTAL_CLK_REQ_RSVD0: RSV
 *     BitOffset : 2
 *     BitWidth  : 30
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, XTAL_CLK_REQ_REG, XTAL_CLK_REQ_RSVD0, 2, 30, RO, (uint32_t)0x0);

/* ********* PMU LMT_CTC_FREQ_REG ***********
 *
 * Register of SEDI PMU
 *   LMT_CTC_FREQ_REG: LMT Configuration
 *     AddressOffset  : 0x2c8
 *     AccessType     : RW
 *     WritableBitMask: 0x70
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, LMT_CTC_FREQ_REG, 0x2c8, RW, (uint32_t)0x70, (uint32_t)0x0);

/*
 * Bit Field of Register LMT_CTC_FREQ_REG
 *   LMT_CTC_DLY_SEL: CTC Delay Select For LMT
 *     BitOffset : 4
 *     BitWidth  : 3
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, LMT_CTC_FREQ_REG, LMT_CTC_DLY_SEL, 4, 3, RW, (uint32_t)0x0);

/*
 * Bit Field of Register LMT_CTC_FREQ_REG
 *   LMT_CTC_FREQ_RSVD: RSVD
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, LMT_CTC_FREQ_REG, LMT_CTC_FREQ_RSVD, 7, 25, RO, (uint32_t)0x0);

/* ********* PMU VNNAON_METAFIX_EN_REG ***********
 *
 * Register of SEDI PMU
 *   VNNAON_METAFIX_EN_REG: PMU VNNAON Metastability Fix Enable
 *     AddressOffset  : 0x2cc
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x1
 */
SEDI_REG_DEFINE(PMU, VNNAON_METAFIX_EN_REG, 0x2cc, RW, (uint32_t)0x1, (uint32_t)0x1);

/*
 * Bit Field of Register VNNAON_METAFIX_EN_REG
 *   VNNAON_METAFIX_EN: Vnnaon Meta-Stabiility Fix Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, VNNAON_METAFIX_EN_REG, VNNAON_METAFIX_EN, 0, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, VNNAON_METAFIX_EN_REG, VNNAON_METAFIX_EN, 0, 0);
SEDI_RBFV_DEFINE(PMU, VNNAON_METAFIX_EN_REG, VNNAON_METAFIX_EN, 1, 1);

/*
 * Bit Field of Register VNNAON_METAFIX_EN_REG
 *   VNNAON_METAFIX_EN_RSVD: RSV
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, VNNAON_METAFIX_EN_REG, VNNAON_METAFIX_EN_RSVD, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU ISH_PSW_DEL_CNT ***********
 *
 * Register of SEDI PMU
 *   ISH_PSW_DEL_CNT: Power Switch Delay Count
 *     AddressOffset  : 0x70c
 *     AccessType     : RW
 *     WritableBitMask: 0xf
 *     ResetValue     : (uint32_t)0x4
 */
SEDI_REG_DEFINE(PMU, ISH_PSW_DEL_CNT, 0x70c, RW, (uint32_t)0xf, (uint32_t)0x4);

/*
 * Bit Field of Register ISH_PSW_DEL_CNT
 *   PSW_DEL_CNT:
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x4
 */
SEDI_RBF_DEFINE(PMU, ISH_PSW_DEL_CNT, PSW_DEL_CNT, 0, 4, RW, (uint32_t)0x4);

/*
 * Bit Field of Register ISH_PSW_DEL_CNT
 *   RSVD_PSW_DEL_CNT: RSV
 *     BitOffset : 4
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ISH_PSW_DEL_CNT, RSVD_PSW_DEL_CNT, 4, 28, RO, (uint32_t)0x0);

/* ********* PMU PWR_ST_REG ***********
 *
 * Register of SEDI PMU
 *   PWR_ST_REG: Power Status
 *     AddressOffset  : 0xf00
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, PWR_ST_REG, 0xf00, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register PWR_ST_REG
 *   PWR_ST_D0IX_STATE: D0ix State
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PWR_ST_REG, PWR_ST_D0IX_STATE, 0, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register PWR_ST_REG
 *   PWR_ST_S_STATE: S State
 *     BitOffset : 2
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PWR_ST_REG, PWR_ST_S_STATE, 2, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register PWR_ST_REG
 *   PWR_ST_IPAPG: IP Accessible PG
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PWR_ST_REG, PWR_ST_IPAPG, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PWR_ST_REG, PWR_ST_IPAPG, 0, 0);
SEDI_RBFV_DEFINE(PMU, PWR_ST_REG, PWR_ST_IPAPG, 1, 1);

/*
 * Bit Field of Register PWR_ST_REG
 *   PWR_ST_FW_ST_TRACK: FW Status/Track
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PWR_ST_REG, PWR_ST_FW_ST_TRACK, 5, 27, RW, (uint32_t)0x0);

/* ********* PMU IPAPG_SC_PAD0 ***********
 *
 * Register of SEDI PMU
 *   IPAPG_SC_PAD0: IPAPG Scrath-Pad0
 *     AddressOffset  : 0xf04
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, IPAPG_SC_PAD0, 0xf04, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register IPAPG_SC_PAD0
 *   IPAPG_SC_PAD0: FW Scratch Pad Register0
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, IPAPG_SC_PAD0, IPAPG_SC_PAD0, 0, 32, RW, (uint32_t)0x0);

/* ********* PMU IPAPG_SC_PAD1 ***********
 *
 * Register of SEDI PMU
 *   IPAPG_SC_PAD1: IPAPG Scratch-Pad1
 *     AddressOffset  : 0xf08
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, IPAPG_SC_PAD1, 0xf08, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register IPAPG_SC_PAD1
 *   IPAPG_SC_PAD1: FW Scratch Pad Register1
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, IPAPG_SC_PAD1, IPAPG_SC_PAD1, 0, 32, RW, (uint32_t)0x0);

/* ********* PMU IPAPG_EN_REG ***********
 *
 * Register of SEDI PMU
 *   IPAPG_EN_REG: IP Accessible PG Enable
 *     AddressOffset  : 0xf10
 *     AccessType     : RW
 *     WritableBitMask: 0x101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, IPAPG_EN_REG, 0xf10, RW, (uint32_t)0x101, (uint32_t)0x0);

/*
 * Bit Field of Register IPAPG_EN_REG
 *   IPAPG_EN: IP Accessible PG Enable
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, IPAPG_EN_REG, IPAPG_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, IPAPG_EN_REG, IPAPG_EN, 0, 0);
SEDI_RBFV_DEFINE(PMU, IPAPG_EN_REG, IPAPG_EN, 1, 1);

/*
 * Bit Field of Register IPAPG_EN_REG
 *   RSVD_IPAPG_EN1: RSV
 *     BitOffset : 1
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, IPAPG_EN_REG, RSVD_IPAPG_EN1, 1, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register IPAPG_EN_REG
 *   IPAPG_EXIT_INDICATION: IPAPG Exit Completed
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, IPAPG_EN_REG, IPAPG_EXIT_INDICATION, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, IPAPG_EN_REG, IPAPG_EXIT_INDICATION, 0, 0);
SEDI_RBFV_DEFINE(PMU, IPAPG_EN_REG, IPAPG_EXIT_INDICATION, 1, 1);

/*
 * Bit Field of Register IPAPG_EN_REG
 *   RSVD_IPAPG_EN0: RSV
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, IPAPG_EN_REG, RSVD_IPAPG_EN0, 9, 23, RO, (uint32_t)0x0);

/* ********* PMU SW_PG_REQ_INTR ***********
 *
 * Register of SEDI PMU
 *   SW_PG_REQ_INTR: SW PG REQ Interrupt
 *     AddressOffset  : 0xf14
 *     AccessType     : RW
 *     WritableBitMask: 0x1e
 *     ResetValue     : (uint32_t)0x18
 */
SEDI_REG_DEFINE(PMU, SW_PG_REQ_INTR, 0xf14, RW, (uint32_t)0x1e, (uint32_t)0x18);

/*
 * Bit Field of Register SW_PG_REQ_INTR
 *   SW_PG_REQ_B_ASSERTED:  Pmc_ish_sw_pg_req_b Live Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_B_ASSERTED, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_B_ASSERTED, 0, 0);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_B_ASSERTED, 1, 1);

/*
 * Bit Field of Register SW_PG_REQ_INTR
 *   SW_PG_REQ_RISE_INTR_STATUS: 'Sw_pg_req_b_riseedge\' INTR Status Bit'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_RISE_INTR_STATUS, 1, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_RISE_INTR_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_RISE_INTR_STATUS, 1, 1);

/*
 * Bit Field of Register SW_PG_REQ_INTR
 *   SW_PG_REQ_FALL_INTR_STATUS: 'Sw_pg_req_b_falledge\' INTR Status Bit'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_FALL_INTR_STATUS, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_FALL_INTR_STATUS, 0, 0);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, SW_PG_REQ_FALL_INTR_STATUS, 1, 1);

/*
 * Bit Field of Register SW_PG_REQ_INTR
 *   MASK_SW_PG_REQ_RISE_INTR: 'Sw_pg_req_b_riseedge\' INTR Mask Bit'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SW_PG_REQ_INTR, MASK_SW_PG_REQ_RISE_INTR, 3, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, MASK_SW_PG_REQ_RISE_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, MASK_SW_PG_REQ_RISE_INTR, 1, 1);

/*
 * Bit Field of Register SW_PG_REQ_INTR
 *   MASK_SW_PG_REQ_FALL_INTR: 'Sw_pg_req_b_falledge\' INTR Mask Bit.'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, SW_PG_REQ_INTR, MASK_SW_PG_REQ_FALL_INTR, 4, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, MASK_SW_PG_REQ_FALL_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, SW_PG_REQ_INTR, MASK_SW_PG_REQ_FALL_INTR, 1, 1);

/*
 * Bit Field of Register SW_PG_REQ_INTR
 *   RSVD_SW_PG_REQ: RSV
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SW_PG_REQ_INTR, RSVD_SW_PG_REQ, 5, 27, RO, (uint32_t)0x0);

/* ********* PMU PMC_WAKE_INT_REG ***********
 *
 * Register of SEDI PMU
 *   PMC_WAKE_INT_REG: ISH PMC WAKE INTR
 *     AddressOffset  : 0xf18
 *     AccessType     : RW
 *     WritableBitMask: 0x1e
 *     ResetValue     : (uint32_t)0x18
 */
SEDI_REG_DEFINE(PMU, PMC_WAKE_INT_REG, 0xf18, RW, (uint32_t)0x1e, (uint32_t)0x18);

/*
 * Bit Field of Register PMC_WAKE_INT_REG
 *   PMC_WAKE_LIVE: 'Pmc_ish_pg_wake\' Live Status Register'
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_LIVE, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_LIVE, 0, 0);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_LIVE, 1, 1);

/*
 * Bit Field of Register PMC_WAKE_INT_REG
 *   PMC_WAKE_RISE_INT: 'Pmc_wake_riseedge\' INTR Status Bit'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_RISE_INT, 1, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_RISE_INT, 0, 0);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_RISE_INT, 1, 1);

/*
 * Bit Field of Register PMC_WAKE_INT_REG
 *   PMC_WAKE_FALL_INT: 'Pmc_wake_falledge\' INTR Status Bit'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_FALL_INT, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_FALL_INT, 0, 0);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, PMC_WAKE_FALL_INT, 1, 1);

/*
 * Bit Field of Register PMC_WAKE_INT_REG
 *   MASK_PMC_WAKE_RISE_INT: 'Pmc_wake_riseedge\' INTR Mask Bit'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, PMC_WAKE_INT_REG, MASK_PMC_WAKE_RISE_INT, 3, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, MASK_PMC_WAKE_RISE_INT, 0, 0);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, MASK_PMC_WAKE_RISE_INT, 1, 1);

/*
 * Bit Field of Register PMC_WAKE_INT_REG
 *   MASK_PMC_WAKE_FALL_INT: 'Pmc_wake_falledge\' INTR Mask Bit'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, PMC_WAKE_INT_REG, MASK_PMC_WAKE_FALL_INT, 4, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, MASK_PMC_WAKE_FALL_INT, 0, 0);
SEDI_RBFV_DEFINE(PMU, PMC_WAKE_INT_REG, MASK_PMC_WAKE_FALL_INT, 1, 1);

/*
 * Bit Field of Register PMC_WAKE_INT_REG
 *   RSVD_PMC_WAKE: RSV
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PMC_WAKE_INT_REG, RSVD_PMC_WAKE, 5, 27, RO, (uint32_t)0x0);

/* ********* PMU HOSTRSTBCTL_REG ***********
 *
 * Register of SEDI PMU
 *   HOSTRSTBCTL_REG: 'ISH HOSTRSTB CTL(Unused )'
 *     AddressOffset  : 0xf20
 *     AccessType     : RW
 *     WritableBitMask: 0x11e
 *     ResetValue     : (uint32_t)0x18
 */
SEDI_REG_DEFINE(PMU, HOSTRSTBCTL_REG, 0xf20, RW, (uint32_t)0x11e, (uint32_t)0x18);

/*
 * Bit Field of Register HOSTRSTBCTL_REG
 *   HOST_RSTB_WIRE: 'Host Reset State - Wire (HOST_RSTB_WIRE)'
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE, 1, 1);

/*
 * Bit Field of Register HOSTRSTBCTL_REG
 *   HOST_RSTB_WIRE_RISE: 'Host_rstb_riseedge\' INTR Status Bit'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE_RISE, 1, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE_RISE, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE_RISE, 1, 1);

/*
 * Bit Field of Register HOSTRSTBCTL_REG
 *   HOST_RSTB_WIRE_FALL: 'Host_rstb_falledge\' INTR Status Bit'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE_FALL, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE_FALL, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_WIRE_FALL, 1, 1);

/*
 * Bit Field of Register HOSTRSTBCTL_REG
 *   MASK_HOST_RSTB_WIRE_RISE: 'Host_rstb_riseedge\' INTR Mask Bit'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, HOSTRSTBCTL_REG, MASK_HOST_RSTB_WIRE_RISE, 3, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, MASK_HOST_RSTB_WIRE_RISE, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, MASK_HOST_RSTB_WIRE_RISE, 1, 1);

/*
 * Bit Field of Register HOSTRSTBCTL_REG
 *   MASK_HOST_RSTB_WIRE_FALL: 'Host_rstb_falledge\' INTR Mask Bit'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, HOSTRSTBCTL_REG, MASK_HOST_RSTB_WIRE_FALL, 4, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, MASK_HOST_RSTB_WIRE_FALL, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, MASK_HOST_RSTB_WIRE_FALL, 1, 1);

/*
 * Bit Field of Register HOSTRSTBCTL_REG
 *   RSVD_HOST_RST1: RSV
 *     BitOffset : 5
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOSTRSTBCTL_REG, RSVD_HOST_RST1, 5, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register HOSTRSTBCTL_REG
 *   HOST_RSTB_MSG: 'Host Reset State - Message (HOST_RSTB_MSG)'
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_MSG, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_MSG, 0, 0);
SEDI_RBFV_DEFINE(PMU, HOSTRSTBCTL_REG, HOST_RSTB_MSG, 1, 1);

/*
 * Bit Field of Register HOSTRSTBCTL_REG
 *   RSVD_HOST_RST0: RSV
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, HOSTRSTBCTL_REG, RSVD_HOST_RST0, 9, 23, RO, (uint32_t)0x0);

/* ********* PMU BRISOLCTL_REG ***********
 *
 * Register of SEDI PMU
 *   BRISOLCTL_REG: 'ISH BRIDGEISOL CTL(Supported Only When There Is Sx Usage)'
 *     AddressOffset  : 0xf24
 *     AccessType     : RW
 *     WritableBitMask: 0x3d
 *     ResetValue     : (uint32_t)0x30
 */
SEDI_REG_DEFINE(PMU, BRISOLCTL_REG, 0xf24, RW, (uint32_t)0x3d, (uint32_t)0x30);

/*
 * Bit Field of Register BRISOLCTL_REG
 *   BR_ISOL_REQ: 'Bridge Host Reset Isolation Request (BR_ISOL_REQ)'
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1S
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_REQ, 0, 1, RW_1S, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_REQ, 0, 0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_REQ, 1, 1);

/*
 * Bit Field of Register BRISOLCTL_REG
 *   BR_ISOL_ACK: 'Bridge Host Reset Isolation Acknowledge (BR_ISOL_ACK)'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK, 0, 0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK, 1, 1);

/*
 * Bit Field of Register BRISOLCTL_REG
 *   BR_ISOL_ACK_RISE: 'Br_rst_isol_ack_rise\' INTR Status Bit'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK_RISE, 2, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK_RISE, 0, 0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK_RISE, 1, 1);

/*
 * Bit Field of Register BRISOLCTL_REG
 *   BR_ISOL_ACK_FALL: 'Br_rst_isol_ack_fall\' INTR Status Bit'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK_FALL, 3, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK_FALL, 0, 0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, BR_ISOL_ACK_FALL, 1, 1);

/*
 * Bit Field of Register BRISOLCTL_REG
 *   MASK_BR_ISOL_ACK_RISE: 'Br_rst_isol_ack_rise\' INTR Mask Bit'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, BRISOLCTL_REG, MASK_BR_ISOL_ACK_RISE, 4, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, MASK_BR_ISOL_ACK_RISE, 0, 0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, MASK_BR_ISOL_ACK_RISE, 1, 1);

/*
 * Bit Field of Register BRISOLCTL_REG
 *   MASK_BR_ISOL_ACK_FALL: 'Br_rst_isol_ack_fall\' INTR Mask Bit'
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, BRISOLCTL_REG, MASK_BR_ISOL_ACK_FALL, 5, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, MASK_BR_ISOL_ACK_FALL, 0, 0);
SEDI_RBFV_DEFINE(PMU, BRISOLCTL_REG, MASK_BR_ISOL_ACK_FALL, 1, 1);

/*
 * Bit Field of Register BRISOLCTL_REG
 *   RSV:
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, BRISOLCTL_REG, RSV, 6, 26, RO, (uint32_t)0x0);

/* ********* PMU CDCCGDIS_REG ***********
 *
 * Register of SEDI PMU
 *   CDCCGDIS_REG: 'CDC Config Clock Gate Disable( Required Only During Sx Usage)'
 *     AddressOffset  : 0xf28
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CDCCGDIS_REG, 0xf28, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCGDIS_REG
 *   CDC0_BRPRICLK_CG_DIS_REG: Bridge PRIM CLK GATE DISABLE BIT
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGDIS_REG, CDC0_BRPRICLK_CG_DIS_REG, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC0_BRPRICLK_CG_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC0_BRPRICLK_CG_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCGDIS_REG
 *   CDC1_BRSBCLK_CG_DIS_REG: Bridge SIDE CLK GATE DISABLE BIT
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGDIS_REG, CDC1_BRSBCLK_CG_DIS_REG, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC1_BRSBCLK_CG_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC1_BRSBCLK_CG_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCGDIS_REG
 *   CDC2_SBEPCLK_CG_DIS_REG: SBEP CLK GATE DISABLE BIT
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGDIS_REG, CDC2_SBEPCLK_CG_DIS_REG, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC2_SBEPCLK_CG_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC2_SBEPCLK_CG_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCGDIS_REG
 *   CDC3_FUNCCLK_CG_DIS_REG: ISH Functional CLK GATE DISABLE BIT
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGDIS_REG, CDC3_FUNCCLK_CG_DIS_REG, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC3_FUNCCLK_CG_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC3_FUNCCLK_CG_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCGDIS_REG
 *   CDC5_MIACCLK_CG_DIS_REG: ISH MIA CLK GATE DISABLE BIT
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGDIS_REG, CDC5_MIACCLK_CG_DIS_REG, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC5_MIACCLK_CG_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC5_MIACCLK_CG_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCGDIS_REG
 *   CDC6_XTALCLK_CG_DIS_REG: ISH Xtal CLK GATE DISABLE BIT
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGDIS_REG, CDC6_XTALCLK_CG_DIS_REG, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC6_XTALCLK_CG_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCGDIS_REG, CDC6_XTALCLK_CG_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCGDIS_REG
 *   RSVD_CDCCGDIS: RSV
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGDIS_REG, RSVD_CDCCGDIS, 6, 26, RO, (uint32_t)0x0);

/* ********* PMU PCE_LOCAL_REG ***********
 *
 * Register of SEDI PMU
 *   PCE_LOCAL_REG: PCE ISH FW Local
 *     AddressOffset  : 0xf30
 *     AccessType     : RW
 *     WritableBitMask: 0x31f
 *     ResetValue     : (uint32_t)0x200
 */
SEDI_REG_DEFINE(PMU, PCE_LOCAL_REG, 0xf30, RW, (uint32_t)0x31f, (uint32_t)0x200);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   PCE_PMCRE_LOCAL: 'PMC Request Enable (PMCRE)'
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, PCE_PMCRE_LOCAL, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_PMCRE_LOCAL, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_PMCRE_LOCAL, 1, 1);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   PCE_IDLEEN_LOCAL: 'IDLE Enable (IDLEN)'
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, PCE_IDLEEN_LOCAL, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_IDLEEN_LOCAL, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_IDLEEN_LOCAL, 1, 1);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   PCE_D3HEN_LOCAL: 'D3Hot Enable (D3HEN)'
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, PCE_D3HEN_LOCAL, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_D3HEN_LOCAL, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_D3HEN_LOCAL, 1, 1);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   PCE_SLEN_LOCAL: 'Sleep Enable (SE)'
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, PCE_SLEN_LOCAL, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_SLEN_LOCAL, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_SLEN_LOCAL, 1, 1);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   PCE_HAE_LOCAL: 'Hardware Autonomous Enable (HAE)'
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, PCE_HAE_LOCAL, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_HAE_LOCAL, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_HAE_LOCAL, 1, 1);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   RSVD_PCE_LOCAL1: RSV
 *     BitOffset : 5
 *     BitWidth  : 3
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, RSVD_PCE_LOCAL1, 5, 3, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   PCE_CHG_DETECT_INTR: PCE Change Detect Interrupt Status
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, PCE_CHG_DETECT_INTR, 8, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_CHG_DETECT_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, PCE_CHG_DETECT_INTR, 1, 1);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   MASK_PCE_CHG_DETECT_INTR: PCE Change Detect Interrupt Mask
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, MASK_PCE_CHG_DETECT_INTR, 9, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, MASK_PCE_CHG_DETECT_INTR, 0, 0);
SEDI_RBFV_DEFINE(PMU, PCE_LOCAL_REG, MASK_PCE_CHG_DETECT_INTR, 1, 1);

/*
 * Bit Field of Register PCE_LOCAL_REG
 *   RSVD_PCE_LOCAL0: RSV
 *     BitOffset : 10
 *     BitWidth  : 22
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, PCE_LOCAL_REG, RSVD_PCE_LOCAL0, 10, 22, RO, (uint32_t)0x0);

/* ********* PMU SRAM_LIGHTSLEEP ***********
 *
 * Register of SEDI PMU
 *   SRAM_LIGHTSLEEP: SRAM Bank Light Sleep Enable
 *     AddressOffset  : 0xf34
 *     AccessType     : RW
 *     WritableBitMask: 0xfffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, SRAM_LIGHTSLEEP, 0xf34, RW, (uint32_t)0xfffff, (uint32_t)0x0);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK0_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 0 Tile 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK0_TILE0, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK0_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK0_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK0_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 0 Tile 1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK0_TILE1, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK0_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK0_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK1_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 1 Tile 0
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK1_TILE0, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK1_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK1_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK1_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 1 Tile 1
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK1_TILE1, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK1_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK1_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK2_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 2 Tile 0
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK2_TILE0, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK2_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK2_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK2_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 2 Tile 1
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK2_TILE1, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK2_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK2_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK3_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 3 Tile 0
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK3_TILE0, 6, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK3_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK3_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK3_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 3 Tile 1
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK3_TILE1, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK3_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK3_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK4_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 4 Tile 0
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK4_TILE0, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK4_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK4_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK4_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 4 Tile 1
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK4_TILE1, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK4_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK4_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK5_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 5 Tile 0
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK5_TILE0, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK5_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK5_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK5_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 5 Tile 1
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK5_TILE1, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK5_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK5_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK6_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 6 Tile 0
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK6_TILE0, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK6_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK6_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK6_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 6 Tile 1
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK6_TILE1, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK6_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK6_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK7_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 7 Tile 0
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK7_TILE0, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK7_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK7_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK7_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 7 Tile 1
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK7_TILE1, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK7_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK7_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK8_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 8 Tile 0
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK8_TILE0, 16, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK8_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK8_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK8_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 8 Tile 1
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK8_TILE1, 17, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK8_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK8_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK9_TILE0: SRAM Bank LIGHT Sleep Enable For Bank 9 Tile 0
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK9_TILE0, 18, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK9_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK9_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   SRAM_LIGHTSLEEP_BANK9_TILE1: SRAM Bank LIGHT Sleep Enable For Bank 9 Tile 1
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK9_TILE1, 19, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK9_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_LIGHTSLEEP, SRAM_LIGHTSLEEP_BANK9_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_LIGHTSLEEP
 *   RSVD_SRAM_LIGHTSLEEP: RSV
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_LIGHTSLEEP, RSVD_SRAM_LIGHTSLEEP, 20, 12, RO, (uint32_t)0x0);

/* ********* PMU SRAM_DEEPSLEEP ***********
 *
 * Register of SEDI PMU
 *   SRAM_DEEPSLEEP: SRAM Bank Deep Sleep Enable
 *     AddressOffset  : 0xf38
 *     AccessType     : RW
 *     WritableBitMask: 0xfffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, SRAM_DEEPSLEEP, 0xf38, RW, (uint32_t)0xfffff, (uint32_t)0x0);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK0_TILE0: SRAM Bank Deep Sleep Enable For Bank 0 Tile 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK0_TILE0, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK0_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK0_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK0_TILE1: SRAM Bank Deep Sleep Enable For Bank 0 Tile 1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK0_TILE1, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK0_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK0_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK1_TILE0: SRAM Bank Deep Sleep Enable For Bank 1 Tile 0
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK1_TILE0, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK1_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK1_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK1_TILE1: SRAM Bank Deep Sleep Enable For Bank 1 Tile 1
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK1_TILE1, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK1_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK1_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK2_TILE0: SRAM Bank Deep Sleep Enable For Bank 2 Tile 0
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK2_TILE0, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK2_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK2_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK2_TILE1: SRAM Bank Deep Sleep Enable For Bank 2 Tile 1
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK2_TILE1, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK2_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK2_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK3_TILE0: SRAM Bank Deep Sleep Enable For Bank 3 Tile 0
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK3_TILE0, 6, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK3_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK3_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK3_TILE1: SRAM Bank Deep Sleep Enable For Bank 3 Tile 1
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK3_TILE1, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK3_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK3_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK4_TILE0: SRAM Bank Deep Sleep Enable For Bank 4 Tile 0
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK4_TILE0, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK4_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK4_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK4_TILE1: SRAM Bank Deep Sleep Enable For Bank 4 Tile 1
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK4_TILE1, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK4_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK4_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK5_TILE0: SRAM Bank Deep Sleep Enable For Bank 5 Tile 0
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK5_TILE0, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK5_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK5_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK5_TILE1: SRAM Bank Deep Sleep Enable For Bank 5 Tile 1
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK5_TILE1, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK5_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK5_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK6_TILE0: SRAM Bank Deep Sleep Enable For Bank 6 Tile 0
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK6_TILE0, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK6_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK6_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK6_TILE1: SRAM Bank Deep Sleep Enable For Bank 6 Tile 1
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK6_TILE1, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK6_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK6_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK7_TILE0: SRAM Bank Deep Sleep Enable For Bank 7 Tile 0
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK7_TILE0, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK7_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK7_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK7_TILE1: SRAM Bank Deep Sleep Enable For Bank 7 Tile 1
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK7_TILE1, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK7_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK7_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK8_TILE0: SRAM Bank Deep Sleep Enable For Bank 8 Tile 0
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK8_TILE0, 16, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK8_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK8_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK8_TILE1: SRAM Bank Deep Sleep Enable For Bank 8 Tile 1
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK8_TILE1, 17, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK8_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK8_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK9_TILE0: SRAM Bank Deep Sleep Enable For Bank 9 Tile 0
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK9_TILE0, 18, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK9_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK9_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   SRAM_DEEPSLEEP_BANK9_TILE1: SRAM Bank Deep Sleep Enable For Bank 9 Tile 1
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK9_TILE1, 19, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK9_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_DEEPSLEEP, SRAM_DEEPSLEEP_BANK9_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_DEEPSLEEP
 *   RSVD_SRAM_DEEPSLEEP: RSV
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_DEEPSLEEP, RSVD_SRAM_DEEPSLEEP, 20, 12, RO, (uint32_t)0x0);

/* ********* PMU IPIAPG_EN_REG ***********
 *
 * Register of SEDI PMU
 *   IPIAPG_EN_REG: IP In-Accessible PG Exit Status
 *     AddressOffset  : 0xf40
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, IPIAPG_EN_REG, 0xf40, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register IPIAPG_EN_REG
 *   IPIAPG_EXIT_INDICATION: IPIAPG Exit Complete
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, IPIAPG_EN_REG, IPIAPG_EXIT_INDICATION, 0, 1, RW_1C, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, IPIAPG_EN_REG, IPIAPG_EXIT_INDICATION, 0, 0);
SEDI_RBFV_DEFINE(PMU, IPIAPG_EN_REG, IPIAPG_EXIT_INDICATION, 1, 1);

/*
 * Bit Field of Register IPIAPG_EN_REG
 *   RSVD_IPIAPG_EN0: RSV
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, IPIAPG_EN_REG, RSVD_IPIAPG_EN0, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU CDCCLKREQCTLDIS_REG ***********
 *
 * Register of SEDI PMU
 *   CDCCLKREQCTLDIS_REG: CDC Config Clock Request Control Disable
 *     AddressOffset  : 0xf48
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CDCCLKREQCTLDIS_REG, 0xf48, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQCTLDIS_REG
 *   CDC0_BRPRICLK_CLK_REQ_CTL_DIS_REG: Bridge PRIM CLK REQ CTRL DISABLE BIT
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC0_BRPRICLK_CLK_REQ_CTL_DIS_REG, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC0_BRPRICLK_CLK_REQ_CTL_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC0_BRPRICLK_CLK_REQ_CTL_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCLKREQCTLDIS_REG
 *   CDC1_BRSBCLK_CLK_REQ_CTL_DIS_REG: Bridge SIDE CLK REQ CONTROL DISABLE BIT
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC1_BRSBCLK_CLK_REQ_CTL_DIS_REG, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC1_BRSBCLK_CLK_REQ_CTL_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC1_BRSBCLK_CLK_REQ_CTL_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCLKREQCTLDIS_REG
 *   CDC2_SBEPCLK_CLK_REQ_CTL_DIS_REG: SBEP CLK REQ CONTROL DISABLE BIT
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC2_SBEPCLK_CLK_REQ_CTL_DIS_REG, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC2_SBEPCLK_CLK_REQ_CTL_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC2_SBEPCLK_CLK_REQ_CTL_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCLKREQCTLDIS_REG
 *   CDC3_FUNCCLK_CLK_REQ_CTL_DIS_REG: ISH Functional CLK REQ CONTROL DISABLE BIT
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC3_FUNCCLK_CLK_REQ_CTL_DIS_REG, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC3_FUNCCLK_CLK_REQ_CTL_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC3_FUNCCLK_CLK_REQ_CTL_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCLKREQCTLDIS_REG
 *   CDC5_MIACCLK_CLK_REQ_CTL_DIS_REG: ISH MIA CLK REQ CONTROL DISABLE BIT
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC5_MIACCLK_CLK_REQ_CTL_DIS_REG, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC5_MIACCLK_CLK_REQ_CTL_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC5_MIACCLK_CLK_REQ_CTL_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCLKREQCTLDIS_REG
 *   CDC6_XTALCLK_CLK_REQ_CTL_DIS_REG: ISH Xtal CLK REQ CONTROL DISABLE BIT
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC6_XTALCLK_CLK_REQ_CTL_DIS_REG, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC6_XTALCLK_CLK_REQ_CTL_DIS_REG, 0, 0);
SEDI_RBFV_DEFINE(PMU, CDCCLKREQCTLDIS_REG, CDC6_XTALCLK_CLK_REQ_CTL_DIS_REG, 1, 1);

/*
 * Bit Field of Register CDCCLKREQCTLDIS_REG
 *   RSVD_CDCCLKREQCTLDIS: RSV
 *     BitOffset : 6
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQCTLDIS_REG, RSVD_CDCCLKREQCTLDIS, 6, 26, RO, (uint32_t)0x0);

/* ********* PMU CDCCGHOLDOFF_REG ***********
 *
 * Register of SEDI PMU
 *   CDCCGHOLDOFF_REG: CDC Clock Gate Hold Off
 *     AddressOffset  : 0xf4c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CDCCGHOLDOFF_REG, 0xf4c, RW, (uint32_t)0xffffff, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCGHOLDOFF_REG
 *   CDC0_BRPRICLK_CG_HOLD_OFF_REG: Bridge PRIM CLK GATE HOLD OFF BIT
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGHOLDOFF_REG, CDC0_BRPRICLK_CG_HOLD_OFF_REG, 0, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCGHOLDOFF_REG
 *   CDC1_BRSBCLK_CG_HOLD_OFF_REG: Bridge SIDE CLK GATE HOLD OFF BIT
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGHOLDOFF_REG, CDC1_BRSBCLK_CG_HOLD_OFF_REG, 4, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCGHOLDOFF_REG
 *   CDC2_SBEPCLK_CG_HOLD_OFF_REG: SBEP CLK GATE HOLD OFF BIT
 *     BitOffset : 8
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGHOLDOFF_REG, CDC2_SBEPCLK_CG_HOLD_OFF_REG, 8, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCGHOLDOFF_REG
 *   CDC3_FUNCCLK_CG_HOLD_OFF_REG: ISH Functional CLK GATE HOLD OFF BIT
 *     BitOffset : 12
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGHOLDOFF_REG, CDC3_FUNCCLK_CG_HOLD_OFF_REG, 12, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCGHOLDOFF_REG
 *   CDC5_MIACCLK_CG_HOLD_OFF_REG: ISH MIA CLK GATE HOLD OFF BIT
 *     BitOffset : 16
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGHOLDOFF_REG, CDC5_MIACCLK_CG_HOLD_OFF_REG, 16, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCGHOLDOFF_REG
 *   CDC6_XTALCLK_CG_HOLD_OFF_REG: ISH Xtal CLK GATE HOLD OFF BIT
 *     BitOffset : 20
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGHOLDOFF_REG, CDC6_XTALCLK_CG_HOLD_OFF_REG, 20, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCGHOLDOFF_REG
 *   RSVD_CDCCGHOLDOFF: RSV
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCGHOLDOFF_REG, RSVD_CDCCGHOLDOFF, 24, 8, RO, (uint32_t)0x0);

/* ********* PMU CDCPGHOLDOFF_REG ***********
 *
 * Register of SEDI PMU
 *   CDCPGHOLDOFF_REG: CDC Power Gate Hold Off
 *     AddressOffset  : 0xf50
 *     AccessType     : RW
 *     WritableBitMask: 0xffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CDCPGHOLDOFF_REG, 0xf50, RW, (uint32_t)0xffffff, (uint32_t)0x0);

/*
 * Bit Field of Register CDCPGHOLDOFF_REG
 *   CDC0_BRPRICLK_PG_HOLD_OFF_REG: Bridge PRIM POWER GATE HOLDOFF BIT
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCPGHOLDOFF_REG, CDC0_BRPRICLK_PG_HOLD_OFF_REG, 0, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCPGHOLDOFF_REG
 *   CDC1_BRSBCLK_PG_HOLD_OFF_REG: Bridge SIDE POWER GATE HOLD OFF BIT
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCPGHOLDOFF_REG, CDC1_BRSBCLK_PG_HOLD_OFF_REG, 4, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCPGHOLDOFF_REG
 *   CDC2_SBEPCLK_PG_HOLD_OFF_REG: SBEP POWER GATE HOLD OFF BIT
 *     BitOffset : 8
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCPGHOLDOFF_REG, CDC2_SBEPCLK_PG_HOLD_OFF_REG, 8, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCPGHOLDOFF_REG
 *   CDC3_FUNCCLK_PG_HOLD_OFF_REG: ISH Functional POWER GATE HOLD OFF BIT
 *     BitOffset : 12
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCPGHOLDOFF_REG, CDC3_FUNCCLK_PG_HOLD_OFF_REG, 12, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCPGHOLDOFF_REG
 *   CDC5_MIACCLK_PG_HOLD_OFF_REG: ISH MIA POWER GATE HOLD OFF BIT
 *     BitOffset : 16
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCPGHOLDOFF_REG, CDC5_MIACCLK_PG_HOLD_OFF_REG, 16, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCPGHOLDOFF_REG
 *   CDC6_XTALCLK_PG_HOLD_OFF_REG: ISH Xtal POWER GATE HOLD OFF BIT
 *     BitOffset : 20
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCPGHOLDOFF_REG, CDC6_XTALCLK_PG_HOLD_OFF_REG, 20, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCPGHOLDOFF_REG
 *   RSVD_CDCPGHOLDOFF: RSV
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCPGHOLDOFF_REG, RSVD_CDCPGHOLDOFF, 24, 8, RO, (uint32_t)0x0);

/* ********* PMU CDCCLKREQOFFHOLDOFF_REG ***********
 *
 * Register of SEDI PMU
 *   CDCCLKREQOFFHOLDOFF_REG: CDC Clock Request Off Hold Off
 *     AddressOffset  : 0xf54
 *     AccessType     : RW
 *     WritableBitMask: 0xffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CDCCLKREQOFFHOLDOFF_REG, 0xf54, RW, (uint32_t)0xffffff, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQOFFHOLDOFF_REG
 *   CDC0_BRPRICLK_REQ_OFF_HOLD_OFF_REG: Bridge PRIM CLK REQ HOLD OFF BIT
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQOFFHOLDOFF_REG, CDC0_BRPRICLK_REQ_OFF_HOLD_OFF_REG, 0, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQOFFHOLDOFF_REG
 *   CDC1_BRSBCLK_REQ_OFF_HOLD_OFF_REG: Bridge SIDE CLK REQ OFF HOLD OFF BIT
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQOFFHOLDOFF_REG, CDC1_BRSBCLK_REQ_OFF_HOLD_OFF_REG, 4, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQOFFHOLDOFF_REG
 *   CDC2_SBEPCLK_REQ_OFF_HOLD_OFF_REG: SBEP CLK REQ OFF HOLD OFF BIT
 *     BitOffset : 8
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQOFFHOLDOFF_REG, CDC2_SBEPCLK_REQ_OFF_HOLD_OFF_REG, 8, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQOFFHOLDOFF_REG
 *   CDC3_FUNCCLK_REQ_OFF_HOLD_OFF_REG: ISH Functional CLK REQ OFF HOLD OFF BIT
 *     BitOffset : 12
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQOFFHOLDOFF_REG, CDC3_FUNCCLK_REQ_OFF_HOLD_OFF_REG, 12, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQOFFHOLDOFF_REG
 *   CDC5_MIACCLK_REQ_OFF_HOLD_OFF_REG: ISH MIA CLK REQ OFF HOLD OFF BIT
 *     BitOffset : 16
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQOFFHOLDOFF_REG, CDC5_MIACCLK_REQ_OFF_HOLD_OFF_REG, 16, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQOFFHOLDOFF_REG
 *   CDC6_XTALCLK_REQ_OFF_HOLD_OFF_REG: ISH Xtal CLK REQ OFF HOLD OFF BIT
 *     BitOffset : 20
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQOFFHOLDOFF_REG, CDC6_XTALCLK_REQ_OFF_HOLD_OFF_REG, 20, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQOFFHOLDOFF_REG
 *   RSVD_CDCCLKREQOFFHOLDOFF: RSV
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQOFFHOLDOFF_REG, RSVD_CDCCLKREQOFFHOLDOFF, 24, 8, RO, (uint32_t)0x0);

/* ********* PMU CDCCLKREQSYNCOFFHOLDOFF_REG ***********
 *
 * Register of SEDI PMU
 *   CDCCLKREQSYNCOFFHOLDOFF_REG: CDC Clock Request Sync Off Hold Off
 *     AddressOffset  : 0xf58
 *     AccessType     : RW
 *     WritableBitMask: 0xffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CDCCLKREQSYNCOFFHOLDOFF_REG, 0xf58, RW, (uint32_t)0xffffff, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQSYNCOFFHOLDOFF_REG
 *   CDC0_BRPRICLK_REQ_SYNCOFF_HOLD_OFF_REG: Bridge PRIM CLK REQ SYNC HOLD OFF BIT
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQSYNCOFFHOLDOFF_REG, CDC0_BRPRICLK_REQ_SYNCOFF_HOLD_OFF_REG, 0, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQSYNCOFFHOLDOFF_REG
 *   CDC1_BRSBCLK_REQ_SYNCOFF_HOLD_OFF_REG: Bridge SIDE CLK REQ SYNCOFF HOLD OFF BIT
 *     BitOffset : 4
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQSYNCOFFHOLDOFF_REG, CDC1_BRSBCLK_REQ_SYNCOFF_HOLD_OFF_REG, 4, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQSYNCOFFHOLDOFF_REG
 *   CDC2_SBEPCLK_REQ_SYNCOFF_HOLD_OFF_REG: SBEP CLK REQ SYNCOFF HOLD OFF BIT
 *     BitOffset : 8
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQSYNCOFFHOLDOFF_REG, CDC2_SBEPCLK_REQ_SYNCOFF_HOLD_OFF_REG, 8, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQSYNCOFFHOLDOFF_REG
 *   CDC3_FUNCCLK_REQ_SYNCOFF_HOLD_OFF_REG: ISH Functional CLK REQ SYNCOFF HOLD OFF BIT
 *     BitOffset : 12
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQSYNCOFFHOLDOFF_REG, CDC3_FUNCCLK_REQ_SYNCOFF_HOLD_OFF_REG, 12, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQSYNCOFFHOLDOFF_REG
 *   CDC5_MIACCLK_REQ_SYNCOFF_HOLD_OFF_REG: ISH MIA CLK REQ SYNCOFF HOLD OFF BIT
 *     BitOffset : 16
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQSYNCOFFHOLDOFF_REG, CDC5_MIACCLK_REQ_SYNCOFF_HOLD_OFF_REG, 16, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQSYNCOFFHOLDOFF_REG
 *   CDC6_XTALCLK_REQ_SYNCOFF_HOLD_OFF_REG: ISH Xtal CLK REQ SYNCOFF HOLD OFF BIT
 *     BitOffset : 20
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQSYNCOFFHOLDOFF_REG, CDC6_XTALCLK_REQ_SYNCOFF_HOLD_OFF_REG, 20, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register CDCCLKREQSYNCOFFHOLDOFF_REG
 *   RSVD_CDCCLKREQSYNCOFFHOLDOFF: RSV
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CDCCLKREQSYNCOFFHOLDOFF_REG, RSVD_CDCCLKREQSYNCOFFHOLDOFF, 24, 8, RO, (uint32_t)0x0);

/* ********* PMU SRAM_PWR_STATUS ***********
 *
 * Register of SEDI PMU
 *   SRAM_PWR_STATUS: SRAM Bank Power Status
 *     AddressOffset  : 0xf60
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, SRAM_PWR_STATUS, 0xf60, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK0_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 0 Tile 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK0_TILE0, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK0_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK0_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK0_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 0 Tile 1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK0_TILE1, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK0_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK0_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK1_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 1 Tile 0
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK1_TILE0, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK1_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK1_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK1_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 1 Tile 1
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK1_TILE1, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK1_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK1_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK2_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 2 Tile 0
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK2_TILE0, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK2_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK2_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK2_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 2 Tile 1
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK2_TILE1, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK2_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK2_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK3_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 3 Tile 0
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK3_TILE0, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK3_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK3_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK3_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 3 Tile 1
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK3_TILE1, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK3_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK3_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK4_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 4 Tile 0
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK4_TILE0, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK4_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK4_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK4_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 4 Tile 1
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK4_TILE1, 9, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK4_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK4_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK5_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 5 Tile 0
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK5_TILE0, 10, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK5_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK5_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK5_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 5 Tile 1
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK5_TILE1, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK5_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK5_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK6_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 6 Tile 0
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK6_TILE0, 12, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK6_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK6_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK6_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 6 Tile 1
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK6_TILE1, 13, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK6_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK6_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK7_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 7 Tile 0
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK7_TILE0, 14, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK7_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK7_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK7_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 7 Tile 1
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK7_TILE1, 15, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK7_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK7_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK8_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 8 Tile 0
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK8_TILE0, 16, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK8_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK8_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK8_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 8 Tile 1
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK8_TILE1, 17, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK8_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK8_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK9_TILE0: SRAM Bank Ready To Be Accessed Status For Bank 9 Tile 0
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK9_TILE0, 18, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK9_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK9_TILE0, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   SRAM_PWR_STATUS_BANK9_TILE1: SRAM Bank Ready To Be Accessed Status For Bank 9 Tile 1
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK9_TILE1, 19, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK9_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, SRAM_PWR_STATUS, SRAM_PWR_STATUS_BANK9_TILE1, 1, 1);

/*
 * Bit Field of Register SRAM_PWR_STATUS
 *   RSVD: Reserved Field
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, SRAM_PWR_STATUS, RSVD, 20, 12, RO, (uint32_t)0x0);

/* ********* PMU ADR_SRAM_PG_FSM_OVERRIDE_EN ***********
 *
 * Register of SEDI PMU
 *   ADR_SRAM_PG_FSM_OVERRIDE_EN: SRAM Power Gate FSM Override Enable
 *     AddressOffset  : 0xf70
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, ADR_SRAM_PG_FSM_OVERRIDE_EN, 0xf70, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ADR_SRAM_PG_FSM_OVERRIDE_EN
 *   SRAM_PG_FSM_OVERRIDE_EN: Register Is Used By FW To Set To Bypass The SRAM PG FSM.
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ADR_SRAM_PG_FSM_OVERRIDE_EN, SRAM_PG_FSM_OVERRIDE_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, ADR_SRAM_PG_FSM_OVERRIDE_EN, SRAM_PG_FSM_OVERRIDE_EN, 0, 0);
SEDI_RBFV_DEFINE(PMU, ADR_SRAM_PG_FSM_OVERRIDE_EN, SRAM_PG_FSM_OVERRIDE_EN, 1, 1);

/*
 * Bit Field of Register ADR_SRAM_PG_FSM_OVERRIDE_EN
 *   RSVD_SRAM_PG_FSM_OVERRIDE_EN: RSV
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, ADR_SRAM_PG_FSM_OVERRIDE_EN, RSVD_SRAM_PG_FSM_OVERRIDE_EN, 1, 31, RO, (uint32_t)0x0);

/* ********* PMU CCM_PG_EN ***********
 *
 * Register of SEDI PMU
 *   CCM_PG_EN: CCM Bank Power Gate Enable
 *     AddressOffset  : 0xf80
 *     AccessType     : RW
 *     WritableBitMask: 0xfffff
 *     ResetValue     : (uint32_t)0xfffff
 */
SEDI_REG_DEFINE(PMU, CCM_PG_EN, 0xf80, RW, (uint32_t)0xfffff, (uint32_t)0xfffff);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK0_TILE0: POWER GATE Enable For Bank 0 Tile 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK0_TILE0, 0, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK0_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK0_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK0_TILE1: POWER GATE Enable For Bank 0 Tile 1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK0_TILE1, 1, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK0_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK0_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK1_TILE0: POWER GATE Enable For Bank 1 Tile 0
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK1_TILE0, 2, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK1_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK1_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK1_TILE1: POWER GATE Enable For Bank 1 Tile 1
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK1_TILE1, 3, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK1_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK1_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK2_TILE0: POWER GATE Enable For Bank 2 Tile 0
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK2_TILE0, 4, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK2_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK2_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK2_TILE1: POWER GATE Enable For Bank 2 Tile 1
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK2_TILE1, 5, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK2_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK2_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK3_TILE0: POWER GATE Enable For Bank 3 Tile 0
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK3_TILE0, 6, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK3_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK3_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK3_TILE1: POWER GATE Enable For Bank 3 Tile 1
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK3_TILE1, 7, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK3_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK3_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK4_TILE0: POWER GATE Enable For Bank 4 Tile 0
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK4_TILE0, 8, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK4_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK4_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK4_TILE1: POWER GATE Enable For Bank 4 Tile 1
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK4_TILE1, 9, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK4_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK4_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK5_TILE0: POWER GATE Enable For Bank 5 Tile 0
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK5_TILE0, 10, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK5_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK5_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK5_TILE1: POWER GATE Enable For Bank 5 Tile 1
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK5_TILE1, 11, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK5_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK5_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK6_TILE0: POWER GATE Enable For Bank 6 Tile 0
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK6_TILE0, 12, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK6_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK6_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK6_TILE1: POWER GATE Enable For Bank 6 Tile 1
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK6_TILE1, 13, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK6_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK6_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK7_TILE0: POWER GATE Enable For Bank 7 Tile 0
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK7_TILE0, 14, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK7_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK7_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK7_TILE1: POWER GATE Enable For Bank 7 Tile 1
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK7_TILE1, 15, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK7_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK7_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK8_TILE0: POWER GATE Enable For Bank 8 Tile 0
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK8_TILE0, 16, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK8_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK8_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK8_TILE1: POWER GATE Enable For Bank 8 Tile 1
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK8_TILE1, 17, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK8_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK8_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK9_TILE0: POWER GATE Enable For Bank 9 Tile 0
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK9_TILE0, 18, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK9_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK9_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   CCM_PG_EN_BANK9_TILE1: POWER GATE Enable For Bank 9 Tile 1
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK9_TILE1, 19, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK9_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_PG_EN, CCM_PG_EN_BANK9_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_PG_EN
 *   RSVD_SRAM_PGEN: RSV
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_PG_EN, RSVD_SRAM_PGEN, 20, 12, RO, (uint32_t)0x0);

/* ********* PMU CCM_DEEPSLEEP ***********
 *
 * Register of SEDI PMU
 *   CCM_DEEPSLEEP: CCM Bank Deep Sleep Enable
 *     AddressOffset  : 0xf84
 *     AccessType     : RW
 *     WritableBitMask: 0xfffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(PMU, CCM_DEEPSLEEP, 0xf84, RW, (uint32_t)0xfffff, (uint32_t)0x0);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK0_TILE0: CCM Bank Deep Sleep Enable For Bank 0 Tile 0
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK0_TILE0, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK0_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK0_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK0_TILE1: CCM Bank Deep Sleep Enable For Bank 0 Tile 1
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK0_TILE1, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK0_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK0_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK1_TILE0: CCM Bank Deep Sleep Enable For Bank 1 Tile 0
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK1_TILE0, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK1_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK1_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK1_TILE1: CCM Bank Deep Sleep Enable For Bank 1 Tile 1
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK1_TILE1, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK1_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK1_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK2_TILE0: CCM Bank Deep Sleep Enable For Bank 2 Tile 0
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK2_TILE0, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK2_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK2_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK2_TILE1: CCM Bank Deep Sleep Enable For Bank 2 Tile 1
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK2_TILE1, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK2_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK2_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK3_TILE0: CCM Bank Deep Sleep Enable For Bank 3 Tile 0
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK3_TILE0, 6, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK3_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK3_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK3_TILE1: CCM Bank Deep Sleep Enable For Bank 3 Tile 1
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK3_TILE1, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK3_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK3_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK4_TILE0: CCM Bank Deep Sleep Enable For Bank 4 Tile 0
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK4_TILE0, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK4_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK4_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK4_TILE1: CCM Bank Deep Sleep Enable For Bank 4 Tile 1
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK4_TILE1, 9, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK4_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK4_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK5_TILE0: CCM Bank Deep Sleep Enable For Bank 5 Tile 0
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK5_TILE0, 10, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK5_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK5_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK5_TILE1: CCM Bank Deep Sleep Enable For Bank 5 Tile 1
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK5_TILE1, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK5_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK5_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK6_TILE0: CCM Bank Deep Sleep Enable For Bank 6 Tile 0
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK6_TILE0, 12, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK6_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK6_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK6_TILE1: CCM Bank Deep Sleep Enable For Bank 6 Tile 1
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK6_TILE1, 13, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK6_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK6_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK7_TILE0: CCM Bank Deep Sleep Enable For Bank 7 Tile 0
 *     BitOffset : 14
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK7_TILE0, 14, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK7_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK7_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK7_TILE1: CCM Bank Deep Sleep Enable For Bank 7 Tile 1
 *     BitOffset : 15
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK7_TILE1, 15, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK7_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK7_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK8_TILE0: CCM Bank Deep Sleep Enable For Bank 8 Tile 0
 *     BitOffset : 16
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK8_TILE0, 16, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK8_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK8_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK8_TILE1: CCM Bank Deep Sleep Enable For Bank 8 Tile 1
 *     BitOffset : 17
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK8_TILE1, 17, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK8_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK8_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK9_TILE0: CCM Bank Deep Sleep Enable For Bank 9 Tile 0
 *     BitOffset : 18
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK9_TILE0, 18, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK9_TILE0, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK9_TILE0, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   CCM_DEEPSLEEP_BANK9_TILE1: CCM Bank Deep Sleep Enable For Bank 9 Tile 1
 *     BitOffset : 19
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK9_TILE1, 19, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK9_TILE1, 0, 0);
SEDI_RBFV_DEFINE(PMU, CCM_DEEPSLEEP, CCM_DEEPSLEEP_BANK9_TILE1, 1, 1);

/*
 * Bit Field of Register CCM_DEEPSLEEP
 *   RSVD_CCM_DEEPSLEEP: RSV
 *     BitOffset : 20
 *     BitWidth  : 12
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(PMU, CCM_DEEPSLEEP, RSVD_CCM_DEEPSLEEP, 20, 12, RO, (uint32_t)0x0);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* SRAM Bank Power Gate Enable */
	__IO_RW uint32_t sram_pg_en;

	/* Reserved */
	__IO_RW uint32_t reserved0[1];

	/* 'Host Wake(Unused/Reserved)' */
	__IO_RW uint32_t host_wakeup;

	/* Wake Event- 1 */
	__IO_RW uint32_t ish_wake_event;

	/* Wake Mask-1 */
	__IO_RW uint32_t ish_mask_event;

	/* Reserved */
	__IO_RW uint32_t reserved1[1];

	/* Fabric Idle And Time Out Count Configuration */
	__IO_RW uint32_t ish_fabric_cnt;

	/* Glitch Bypass Enable */
	__IO_RW uint32_t ish_glitch_bypass;

	/* RF And ROM Clock Gate To Isolation Enable Count. */
	__IO_RW uint32_t rf_rom_clkgate_to_isoen_ctrl;

	/* RF And ROM Isolation Enable To Power Gate Count. */
	__IO_RW uint32_t rf_rom_isoen_to_pwrgate_ctrl;

	/* RF And ROM Power Ungate To Isolation Disable Count */
	__IO_RW uint32_t rf_rom_pwrungate_to_isodis_ctrl;

	/* RF And ROM Isolation Disable To Clock Gate Exit Count */
	__IO_RW uint32_t rf_rom_isodis_to_clkgateexit_ctrl;

	/* RF And ROM Power Gating Control */
	__IO_RW uint32_t rf_rom_pwr_ctrl;

	/* SRAM Isolation Disable To Idle Count */
	__IO_RW uint32_t sram_pwr_ctrl;

	/* Reserved */
	__IO_RW uint32_t reserved2[1];

	/* VNN Req Assert */
	__IO_RW uint32_t vnn_req;

	/* Vnn_req/Ack Live Status, Interrupts And Interrupt Masks Record */
	__IO_RW uint32_t vnn_req_ack;

	/* Reserved */
	__IO_RW uint32_t ldo_ctrl;

	/* Wake Event- 2 */
	__IO_RW uint32_t ish_wake_event2;

	/* Wake Mask-2 */
	__IO_RW uint32_t ish_mask_event2;

	/* 'HPET Interrupt(Not POR)' */
	__IO_RW uint32_t ish_hpet_intr_ctrl;

	/* PGCB Clock Gating Control */
	__IO_RW uint32_t pgcb_clk_gate_ctrl;

	/* Vnnaon Reduction Enable */
	__IO_RW uint32_t vnnaon_red_en;

	/* Reset Prep */
	__IO_RW uint32_t reset_prep_reg;

	/* Fabric Idle Time Out Snapshot */
	__IO_RW uint32_t fabric_snapshot_reg;

	/* Context Propagation Enable */
	__IO_RW uint32_t cp_en_reg;

	/* Clock Gating And Power Gating Status */
	__IO_RW uint32_t cg_pg_status_reg;

	/* Reserved */
	__IO_RW uint32_t reserved3[37];

	/* PCE ShadowFor PCI Function 0 */
	__IO_RW uint32_t pce_status_0;

	/* PCE ShadowFor PCI Function 1 */
	__IO_RW uint32_t pce_status_1;

	/* Reserved */
	__IO_RW uint32_t reserved4[62];

	/* Bridge D3 Rise Interrupt Wake Mask */
	__IO_RW uint32_t d3_rise_intr_mask_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved5[1];

	/* Bridge D3 Fall Interrupt Wake Mask */
	__IO_RW uint32_t d3_fall_intr_mask_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved6[1];

	/* Bridge D3 Rise Interrupt Wake */
	__IO_RW uint32_t d3_rise_intr_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved7[1];

	/* Bridge D3 Fall Interrupt Wake */
	__IO_RW uint32_t d3_fall_intr_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved8[1];

	/* BME Rise Interrupt Wake Mask */
	__IO_RW uint32_t bme_rise_intr_mask_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved9[1];

	/* BME Fall Interrupt Wake Mask */
	__IO_RW uint32_t bme_fall_intr_mask_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved10[1];

	/* BME Rise Interrupt Wake */
	__IO_RW uint32_t bme_rise_intr_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved11[1];

	/* BME Fall Interrupt Wake */
	__IO_RW uint32_t bme_fall_intr_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved12[1];

	/* Bridge D3 Interrupt Wake Mask */
	__IO_RW uint32_t d3_intr_mask_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved13[1];

	/* Bridge D3 Interrupt Wake */
	__IO_RW uint32_t d3_intr_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved14[1];

	/* GPIO Interrupt Mask */
	__IO_RW uint32_t gpio_intr_mask_reg_0;

	/* GPIO Interrupt Mask */
	__IO_RW uint32_t gpio_intr_mask_reg_1;

	/* Reserved */
	__IO_RW uint32_t reserved15[6];

	/* GPIO Wake Interrupt Record */
	__IO_RW uint32_t gpio_intr_reg_0;

	/* GPIO Wake Interrupt Record */
	__IO_RW uint32_t gpio_intr_reg_1;

	/* Reserved */
	__IO_RW uint32_t reserved16[6];

	/* PWM And I2S Wake Interrupt */
	__IO_RW uint32_t i2s_intr_reg;

	/* I2S Interrupt Mask */
	__IO_RW uint32_t i2s_intr_mask_reg;

	/* IETHERNET Wake Interrupt */
	__IO_RW uint32_t ether_intr_reg;

	/* ETHERNET Interrupt Mask */
	__IO_RW uint32_t ethernet_intr_mask_reg;

	/* QEP Wake Interrupt */
	__IO_RW uint32_t qep_intr_reg;

	/* QEP Interrupt Mask */
	__IO_RW uint32_t qep_intr_mask_reg;

	/* PMU LART Update */
	__IO_RW uint32_t adr_lart_upd_reg;

	/* Reserved */
	__IO_RW uint32_t reserved17[1];

	/* PCI Interrupt */
	__IO_R uint32_t pce_intr_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved18[1];

	/* D0i3 Interrupt */
	__IO_R uint32_t d0i3_cip_intr_reg_0;

	/* Reserved */
	__IO_RW uint32_t reserved19[1];

	/* XTAL Clk Reg */
	__IO_RW uint32_t xtal_clk_req_reg;

	/* Reserved */
	__IO_RW uint32_t reserved20[1];

	/* LMT Configuration */
	__IO_RW uint32_t lmt_ctc_freq_reg;

	/* PMU VNNAON Metastability Fix Enable */
	__IO_RW uint32_t vnnaon_metafix_en_reg;

	/* Reserved */
	__IO_RW uint32_t reserved21[271];

	/* Power Switch Delay Count */
	__IO_RW uint32_t ish_psw_del_cnt;

	/* Reserved */
	__IO_RW uint32_t reserved22[508];

	/* Power Status */
	__IO_RW uint32_t pwr_st_reg;

	/* IPAPG Scrath-Pad0 */
	__IO_RW uint32_t ipapg_sc_pad0;

	/* IPAPG Scratch-Pad1 */
	__IO_RW uint32_t ipapg_sc_pad1;

	/* Reserved */
	__IO_RW uint32_t reserved23[1];

	/* IP Accessible PG Enable */
	__IO_RW uint32_t ipapg_en_reg;

	/* SW PG REQ Interrupt */
	__IO_RW uint32_t sw_pg_req_intr;

	/* ISH PMC WAKE INTR */
	__IO_RW uint32_t pmc_wake_int_reg;

	/* Reserved */
	__IO_RW uint32_t reserved24[1];

	/* 'ISH HOSTRSTB CTL(Unused )' */
	__IO_RW uint32_t hostrstbctl_reg;

	/* 'ISH BRIDGEISOL CTL(Supported Only When There Is Sx Usage)' */
	__IO_RW uint32_t brisolctl_reg;

	/* 'CDC Config Clock Gate Disable( Required Only During Sx Usage)' */
	__IO_RW uint32_t cdccgdis_reg;

	/* Reserved */
	__IO_RW uint32_t reserved25[1];

	/* PCE ISH FW Local */
	__IO_RW uint32_t pce_local_reg;

	/* SRAM Bank Light Sleep Enable */
	__IO_RW uint32_t sram_lightsleep;

	/* SRAM Bank Deep Sleep Enable */
	__IO_RW uint32_t sram_deepsleep;

	/* Reserved */
	__IO_RW uint32_t reserved26[1];

	/* IP In-Accessible PG Exit Status */
	__IO_RW uint32_t ipiapg_en_reg;

	/* Reserved */
	__IO_RW uint32_t reserved27[1];

	/* CDC Config Clock Request Control Disable */
	__IO_RW uint32_t cdcclkreqctldis_reg;

	/* CDC Clock Gate Hold Off */
	__IO_RW uint32_t cdccgholdoff_reg;

	/* CDC Power Gate Hold Off */
	__IO_RW uint32_t cdcpgholdoff_reg;

	/* CDC Clock Request Off Hold Off */
	__IO_RW uint32_t cdcclkreqoffholdoff_reg;

	/* CDC Clock Request Sync Off Hold Off */
	__IO_RW uint32_t cdcclkreqsyncoffholdoff_reg;

	/* Reserved */
	__IO_RW uint32_t reserved28[1];

	/* SRAM Bank Power Status */
	__IO_R uint32_t sram_pwr_status;

	/* Reserved */
	__IO_RW uint32_t reserved29[3];

	/* SRAM Power Gate FSM Override Enable */
	__IO_RW uint32_t adr_sram_pg_fsm_override_en;

	/* Reserved */
	__IO_RW uint32_t reserved30[3];

	/* CCM Bank Power Gate Enable */
	__IO_RW uint32_t ccm_pg_en;

	/* CCM Bank Deep Sleep Enable */
	__IO_RW uint32_t ccm_deepsleep;

} sedi_pmu_regs_t;


#endif /* _SEDI_PMU_REGS_H_ */
