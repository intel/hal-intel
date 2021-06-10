/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * @file
 * @brief Board configuration macros for the PSE for arm platform
 *
 * This header file is used to specify and describe board-level aspects for
 * the 'PSE' platform.
 */

#ifndef _BOARD__H_
#define _BOARD__H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ASMLANGUAGE

typedef enum IRQn {
	NonMaskableInt_IRQn = -14,   /*  2 Non Maskable Interrupt          */
	HardFault_IRQn = -13,	/*  3 HardFault Interrupt             */
	MemoryManagement_IRQn = -12, /*  4 Memory Management Interrupt     */
	BusFault_IRQn = -11,	 /*  5 Bus Fault Interrupt             */
	UsageFault_IRQn = -10,       /*  6 Usage Fault Interrupt           */
	SVCall_IRQn = -5,	    /* 11 SV Call Interrupt               */
	DebugMonitor_IRQn = -4,      /* 12 Debug Monitor Interrupt         */
	PendSV_IRQn = -2,	    /* 14 Pend SV Interrupt               */
	SysTick_IRQn = -1,	   /* 15 System Tick Interrupt           */
} IRQn_Type;
#endif
#define __MPU_PRESENT 1
#ifndef _ASMLANGUAGE
#define __FPU_PRESENT 1
#define __NVIC_PRIO_BITS 3       /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig 1 /* Set 1 for different SysTick Config */
#define __FPU_DP 1U		 /* double precision FPU */

#define __ICACHE_PRESENT 1U
#define __DCACHE_PRESENT 1U

#define __DTCM_PRESENT 1U

#endif /* !_ASMLANGUAGE */

#ifdef __cplusplus
}
#endif

#endif /* _BOARD__H_ */
