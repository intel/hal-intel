/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated and modified
 * Tool Version: 1.0.0
 * Generation Date: 2023-08-01
 */

#ifndef _SEDI_GPIO_REGS_H_
#define _SEDI_GPIO_REGS_H_

#include <sedi_reg_defs.h>


/* ********* GPIO GCCR ***********
 *
 * Register of SEDI GPIO
 *   GCCR: GPIO Pin DirectionLock
 *     AddressOffset  : 0x0
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GCCR, 0x0, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register GCCR
 *   GPDR_LOCK:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GCCR, GPDR_LOCK, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(GPIO, GCCR, GPDR_LOCK, 0, 0);
SEDI_RBFV_DEFINE(GPIO, GCCR, GPDR_LOCK, 1, 1);

/*
 * Bit Field of Register GCCR
 *   RESERVED0:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GCCR, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* GPIO GPLR0 ***********
 *
 * Register of SEDI GPIO
 *   GPLR0: GPIO Pin Level
 *     AddressOffset  : 0x4
 *     AccessType     : RO
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GPLR0, 0x4, RO, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GPLR0
 *   GPLR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GPLR0, GPLR0, 0, 32, RO_V, (uint32_t)0x0);

/* ********* GPIO GPDR0 ***********
 *
 * Register of SEDI GPIO
 *   GPDR0: GPIO Pin Direction
 *     AddressOffset  : 0x1c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GPDR0, 0x1c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GPDR0
 *   GPDR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_L
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GPDR0, GPDR0, 0, 32, RW_L, (uint32_t)0x0);

/* ********* GPIO GPSR0 ***********
 *
 * Register of SEDI GPIO
 *   GPSR0: GPIO Pin Output Set
 *     AddressOffset  : 0x34
 *     AccessType     : RO
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GPSR0, 0x34, RO, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GPSR0
 *   GPSR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: WO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GPSR0, GPSR0, 0, 32, WO, (uint32_t)0x0);

/* ********* GPIO GPCR0 ***********
 *
 * Register of SEDI GPIO
 *   GPCR0: GPIO Pin Output Clear
 *     AddressOffset  : 0x4c
 *     AccessType     : RO
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GPCR0, 0x4c, RO, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GPCR0
 *   GPCR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: WO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GPCR0, GPCR0, 0, 32, WO, (uint32_t)0x0);

/* ********* GPIO GRER0 ***********
 *
 * Register of SEDI GPIO
 *   GRER0: GPIO Rising Edge Detect Enable
 *     AddressOffset  : 0x64
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GRER0, 0x64, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GRER0
 *   GRER0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GRER0, GRER0, 0, 32, RW, (uint32_t)0x0);

/* ********* GPIO GFER0 ***********
 *
 * Register of SEDI GPIO
 *   GFER0: GPIO Falling Edge Detect Enable
 *     AddressOffset  : 0x7c
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GFER0, 0x7c, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GFER0
 *   GFER0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GFER0, GFER0, 0, 32, RW, (uint32_t)0x0);

/* ********* GPIO GFBR0 ***********
 *
 * Register of SEDI GPIO
 *   GFBR0: GPIO Glitch Filter Bypass
 *     AddressOffset  : 0x94
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)-1
 */
SEDI_REG_DEFINE(GPIO, GFBR0, 0x94, RW, (uint32_t)0xffffffff, (uint32_t)-1);

/*
 * Bit Field of Register GFBR0
 *   GFBR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)-1
 */
SEDI_RBF_DEFINE(GPIO, GFBR0, GFBR0, 0, 32, RW, (uint32_t)-1);

/* ********* GPIO GIMR0 ***********
 *
 * Register of SEDI GPIO
 *   GIMR0: GPIO Interrupt Mask
 *     AddressOffset  : 0xac
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GIMR0, 0xac, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GIMR0
 *   GIMR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GIMR0, GIMR0, 0, 32, RW, (uint32_t)0x0);

/* ********* GPIO GISR0 ***********
 *
 * Register of SEDI GPIO
 *   GISR0: GPIO Interrupt Source
 *     AddressOffset  : 0xc4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GISR0, 0xc4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GISR0
 *   GISR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GISR0, GISR0, 0, 32, RW_1C_V, (uint32_t)0x0);

/* ********* GPIO GWMR0 ***********
 *
 * Register of SEDI GPIO
 *   GWMR0: GPIO Wake Mask
 *     AddressOffset  : 0x100
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GWMR0, 0x100, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GWMR0
 *   GWMR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GWMR0, GWMR0, 0, 32, RW, (uint32_t)0x0);

/* ********* GPIO GWSR0 ***********
 *
 * Register of SEDI GPIO
 *   GWSR0: GPIO Wake Source
 *     AddressOffset  : 0x118
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GWSR0, 0x118, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GWSR0
 *   GWSR0:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GWSR0, GWSR0, 0, 32, RW_1C_V, (uint32_t)0x0);

/* ********* GPIO GSEC ***********
 *
 * Register of SEDI GPIO
 *   GSEC: GPIO Secure Input
 *     AddressOffset  : 0x130
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, GSEC, 0x130, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register GSEC
 *   GSEC:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, GSEC, GSEC, 0, 32, RW, (uint32_t)0x0);

/* ********* GPIO SPARE ***********
 *
 * Register of SEDI GPIO
 *   SPARE: Spare Register
 *     AddressOffset  : 0x200
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(GPIO, SPARE, 0x200, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register SPARE
 *   SPARE:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(GPIO, SPARE, SPARE, 0, 32, RW, (uint32_t)0x0);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* GPIO Pin DirectionLock */
	__IO_RW uint32_t gccr;

	/* GPIO Pin Level */
	__IO_RW uint32_t gplr[6];

	/* GPIO Pin Direction */
	__IO_RW uint32_t gpdr[6];

	/* GPIO Pin Output Set */
	__IO_RW uint32_t gpsr[6];

	/* GPIO Pin Output Clear */
	__IO_RW uint32_t gpcr[6];

	/* GPIO Rising Edge Detect Enable */
	__IO_RW uint32_t grer[6];

	/* GPIO Falling Edge Detect Enable */
	__IO_RW uint32_t gfer[6];

	/* GPIO Glitch Filter Bypass */
	__IO_RW uint32_t gfbr[6];

	/* GPIO Interrupt Mask */
	__IO_RW uint32_t gimr[6];

	/* GPIO Interrupt Source */
	__IO_RW uint32_t gisr[6];

	/* Reserved */
	__IO_RW uint32_t reserved0[9];

	/* GPIO Wake Mask */
	__IO_RW uint32_t gwmr[6];

	/* GPIO Wake Source */
	__IO_RW uint32_t gwsr[6];

	/* GPIO Secure Input */
	__IO_RW uint32_t gsec;

	/* Reserved */
	__IO_RW uint32_t reserved1[51];

	/* Spare Register */
	__IO_RW uint32_t spare;

} sedi_gpio_regs_t;


#endif /* _SEDI_GPIO_REGS_H_ */
