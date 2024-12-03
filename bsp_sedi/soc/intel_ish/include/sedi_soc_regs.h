/*
 * Copyright (c) 2023 - 2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_SOC_REGS_H_
#define _SEDI_SOC_REGS_H_

#include "sedi_reg_defs.h"

/****** uart *****/

/** Number of UART controllers. */
typedef enum {
	SEDI_UART_0 = 0,
	SEDI_UART_1,
	SEDI_UART_2,
	SEDI_UART_NUM
} sedi_uart_t;

/* UART register base addresses. */
SEDI_IREG_BASE_DEFINE(UART, 0, 0x08100000);
SEDI_IREG_BASE_DEFINE(UART, 1, 0x08102000);
SEDI_IREG_BASE_DEFINE(UART, 2, 0x08104000);

#define SEDI_UART_SFT_RST_REG (0x0430004C)
#define SEDI_UART_SFT_RST_MASK (0x7)


/****** dma *****/
/*!
 * \struct sedi_dma
 * \brief  DMA device bus ID
 */
typedef enum {
	SEDI_DMA_0 = 0,
	SEDI_DMA_NUM
} sedi_dma_t;

SEDI_IREG_BASE_DEFINE(DMA, 0, 0x10100000);

/**DMA block TS**/
#define SEDI_DMA_PERIPH_MAX_SIZE 4096
#define SEDI_DMA_PERIPH_MAX_SIZE_SHIFT 12

/****** i2c *****/
/*!
 * \struct sedi_i2c
 * \brief  I2C device bus ID
 */
typedef enum {
	SEDI_I2C_0 = 0,
	SEDI_I2C_1,
	SEDI_I2C_2,
	SEDI_I2C_NUM
} sedi_i2c_t;

SEDI_IREG_BASE_DEFINE(I2C, 0, 0x0000);
SEDI_IREG_BASE_DEFINE(I2C, 1, 0x2000);
SEDI_IREG_BASE_DEFINE(I2C, 2, 0x4000);

#define I2C_FIFO_DEPTH (64)

/****** GPIO *****/

/*!
 * \struct sedi_gpio
 * \brief  GPIO controller device ID
 */
typedef enum { SEDI_GPIO_0 = 0, SEDI_GPIO_NUM } sedi_gpio_t;

#define ISH_PIN_NUM 36
#define SEDI_GPIO_SOC_PORT_NUM (2U)

SEDI_IREG_BASE_DEFINE(GPIO, 0, 0x00100000);


typedef enum {
	SEDI_HW_REV_INVALID = 0,
} sedi_hw_rev_t;

/****** WDT *****/

/*!
 * \struct sedi_watchdog
 * \brief  WATCHDOG device bus ID
 */

typedef enum { SEDI_WATCHDOG_0 = 0, SEDI_WATCHDOG_NUM } sedi_watchdog_t;

SEDI_REG_BASE_DEFINE(WDT, 0x4900000);

/****** HPET *****/
SEDI_REG_BASE_DEFINE(HPET, 0x04700000);

#define SEDI_HPET_SOC_TIMER_NUM (3)

#define SEDI_IRQ_HPET_TIMER_0 (14)
#define SEDI_IRQ_HPET_TIMER_1 (0) /* fake IRQ number, same as timer 0's */

/****** IPC *****/
SEDI_IREG_BASE_DEFINE(IPC, HOST, 0x4100000);
SEDI_IREG_BASE_DEFINE(IPC, CSME, 0x4110000);
SEDI_IREG_BASE_DEFINE(IPC, PMC, 0x4111000);

/****** MISC *****/
#define SEDI_MISC_BASE (0x04400000)

#define SEDI_RTC_COUNTER (SEDI_MISC_BASE + 0x70)
#define SEDI_RTC_COUNTER0 (SEDI_MISC_BASE + 0x70)
#define SEDI_RTC_COUNTER1 (SEDI_MISC_BASE + 0x74)

/****** PM *****/
#define SEDI_PMU_BASE (0x04200000)
#define SEDI_CCU_BASE 0x04300000

#ifdef CONFIG_SOC_INTEL_ISH_5_8_0
#define SEDI_IRQ_RESET_PREP (8)
#define SEDI_IRQ_PCIEDEV (11)
#define SEDI_IRQ_PMU2IOAPIC (12)
#else
#define SEDI_IRQ_RESET_PREP (6)
#define SEDI_IRQ_PCIEDEV (9)
#define SEDI_IRQ_PMU2IOAPIC (10)
#endif

/****** APIC *****/
#define SEDI_IOAPIC_BASE 0xFEC00000
#define SEDI_LAPIC_BASE 0xFEE00000

#define SEDI_IOAPIC_IDX (SEDI_IOAPIC_BASE + 0x0000)
#define SEDI_IOAPIC_WDW (SEDI_IOAPIC_BASE + 0x0010)
#define SEDI_IOAPIC_EOI (SEDI_IOAPIC_BASE + 0x0040)

#define SEDI_IOAPIC_IOREDTBL 0x10
#define SEDI_IOAPIC_REDTBL_MASK 0x00010000

/****** SPI *****/
/*!
 * \struct sedi_spi
 * \brief  SPI device bus ID
 */
typedef enum {
	SEDI_SPI_0 = 0,
	SEDI_SPI_1,
	SEDI_SPI_NUM
} sedi_spi_t;

SEDI_IREG_BASE_DEFINE(SPI, 0, 0x8000000);
SEDI_IREG_BASE_DEFINE(SPI, 1, 0x8002000);

/**SPI physical addr for DMA transfer**/
#define SEDI_SPI_0_REG_DMA 0x8000000
#define SEDI_SPI_1_REG_DMA 0x8002000

#define SPI_FIFO_DEPTH (64)
#define SEDI_SPI_USE_DMA (1)


#endif /* _SEDI_SOC_REGS_H_ */
