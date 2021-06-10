/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DASHBOARD_H_
#define _DASHBOARD_H_


/* DASHBOARD */
#define DASHBOARD_BASE          0x40F00000
#define DASHBOARD_CTRLPOLICY    DASHBOARD_BASE
#define DASHBOARD_VRF_ERR_STS   (DASHBOARD_BASE + 0x30)
#define DASHBOARD_VRF_ADDR1_0   (DASHBOARD_BASE + 0x40)
#define DASHBOARD_VRF_ADDR1_1   (DASHBOARD_BASE + 0x44)
#define DASHBOARD_VRF_SIZE1_0   (DASHBOARD_BASE + 0x48)
#define DASHBOARD_VRF_SIZE1_1   (DASHBOARD_BASE + 0x4C)
#define DASHBOARD_VRF_ADDR2_0   (DASHBOARD_BASE + 0x50)
#define DASHBOARD_VRF_ADDR2_1   (DASHBOARD_BASE + 0x54)
#define DASHBOARD_VRF_SIZE2_0   (DASHBOARD_BASE + 0x58)
#define DASHBOARD_VRF_SIZE2_1   (DASHBOARD_BASE + 0x5C)
#define DASHBOARD_IMR_ADDR1_0   (DASHBOARD_BASE + 0x80)
#define DASHBOARD_IMR_ADDR1_1   (DASHBOARD_BASE + 0x84)
#define DASHBOARD_IMR_SIZE1_0   (DASHBOARD_BASE + 0x88)
#define DASHBOARD_IMR_SIZE1_1   (DASHBOARD_BASE + 0x8C)
#define DASHBOARD_GP3_0         (DASHBOARD_BASE + 0x140)
#define DASHBOARD_GP3_1         (DASHBOARD_BASE + 0x144)
#define DASHBOARD_GP3_2         (DASHBOARD_BASE + 0x148)
#define DASHBOARD_GP3_3         (DASHBOARD_BASE + 0x14c)
#define DASHBOARD_GP3_4         (DASHBOARD_BASE + 0x150)
#define DASHBOARD_GP3_5         (DASHBOARD_BASE + 0x154)
#define DASHBOARD_GP3_6         (DASHBOARD_BASE + 0x158)
#define DASHBOARD_GP3_7         (DASHBOARD_BASE + 0x15c)
#define DASHBOARD_INT_STS       (DASHBOARD_BASE + 0x103C)
#define DASHBOARD_INT_MASK      (DASHBOARD_BASE + 0x1038)


#define DB_VERF_SZ_SHIFT        10      /* The data stored in reg is in kB unit. */
#define DB_INFO_SZ_2KB_SHIFT    4       /* The data stored in bit[63 ~ 4] in reg stands for
					 * IMR size in kB
					 */
#define DB_RS_MASK      0x7
#define DB_RS_SHIFT     1
#define DB_GET_RS(size1_0)      ((size1_0 >> DB_RS_SHIFT) & DB_RS_MASK)

#define DASHBOARD_MASK_IP_READY         (0x0000000F)
#define DASHBOARD_MASK_LOAD_DONE        (0x000000F0)
#define DASHBOARD_MASK_VERF_LOAD_DONE   (0x00000F00)
#define DASHBOARD_MASK_VERF_DONE        (0x0000F000)
#define DASHBOARD_MASK_PUSHPULL_DONE    (0x000F0000)

#define DASHBOARD_STS_VERF_DONE         (1)
#define DASHBOARD_PUSHPULL_DONE         (0x10000)

#define DASHBOARD_BOOT_CFG      DASHBOARD_GP3_0 /* Configuration for bootload */
#define DASHBOARD_CFG_LOGOUT_EN  (0x100)        /* 0 - debug output disabled; 1 - Debug output
						 *  enable
						 */
#define DASHBOARD_CFG_MASK_CHN   (0xFF)         /* Debug output channel */
#define DASHBOARD_CFG_FRQ_BOOST  (0x1000)       /* If bit 12 set, then boost frequency to 400MHz
						 *  before load
						 */
#define DASHBOARD_CFG_JTAG_HALT  (0x2000)       /* If bit 13 set, ROM halt if JTAG debugger is
						 *  detected
						 */
#define DASHBOARD_CFG_TO_RESET   (0x4000)       /* If bit 14 set, capsule updated or BIOS setting
						 *  changed, need to reset with host
						 */
#define DASHBOARD_SHELL_EN       (0x8000)       /* If bit 15 set, Shell is enabled in BIOS */
#define DASHBOARD_ECLITE_EN      (0x10000)      /* If bit 16 set, Eclite is enabled in BIOS */
#define DASHBOARD_OOB_EN         (0x20000)      /* If bit 17 set, OOB is enabled in BIOS */
#define DASHBOARD_ECLITE_DTS_EN  (0x40000)      /* If bit 18 set, Eclite dts is enabled in BIOS */
#define DASHBOARD_WOL_EN         (0x80000)      /* If bit 19 set, WOL is enabled in BIOS */
#define DASHBOARD_FUSA_SKU_EN    (0x100000)     /* If bit 20 set, FUSA SKU is enabled in BIOS */

#define DASHBOARD_DBG_ARG       DASHBOARD_GP3_1

#define DASHBOARD_CFG_SHIFT             0
#define DASHBOARD_CFG_DBG_MEM           0       /**< Debug log output to memory */
#define DASHBOARD_CFG_DBG_UART0         1       /**< Debug log output to UART 0 */
#define DASHBOARD_CFG_DBG_UART1         2       /**< Debug log output to UART 1 */
#define DASHBOARD_CFG_DBG_UART2         3       /**< Debug log output to UART 2 */
#define DASHBOARD_CFG_DBG_UART3         4       /**< Debug log output to UART 3 */
#define DASHBOARD_CFG_DBG_UART4         5       /**< Debug log output to UART 4 */
#define DASHBOARD_CFG_DBG_UART5         6       /**< Debug log output to UART 5 */
#define DASHBOARD_CFG_DBG_INV           0xFF

#define SNOWBALL        (DASHBOARD_GP3_2)       /**< ROM register outpu */
#define BUP_SIGNATURE   0xBEEFBEEF

#endif
