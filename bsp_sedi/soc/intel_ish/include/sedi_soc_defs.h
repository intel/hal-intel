/*
 * Copyright (c) 2023-2026 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_SOC_DEFS_H_
#define _SEDI_SOC_DEFS_H_

#include <stdbool.h>

/*!
 * \defgroup sedi_soc_defs_ish Intel ISH SoC Definitions
 */

#define SEDI_CONFIG_ARCH_X86	(1)

#if defined(CONFIG_ISH_PLATFORM_FPGA)
/* ISH SoC clock is lower on FPGA than Silicon */
#define SEDI_SOC_CLK_DIVISOR (5)
#endif

#ifndef SEDI_SOC_CLK_DIVISOR
#define SEDI_SOC_CLK_DIVISOR (1)
#endif

#ifndef ISH_CONFIG_HBW_CLK_DIVIDER
#define ISH_CONFIG_HBW_CLK_DIVIDER (1)
#endif

#define SEDI_RTC_BASE_FREQ (32768)
#define SEDI_RTC_TICKS_PER_SECOND (SEDI_RTC_BASE_FREQ / SEDI_SOC_CLK_DIVISOR)
#define SEDI_RTC_TICKS2US(ticks) (ticks * 1000000 * SEDI_SOC_CLK_DIVISOR \
		/ SEDI_RTC_BASE_FREQ)

#define SEDI_MHZ_TO_HZ(mhz) ((mhz) * 1000000)

#ifndef ISH_CONFIG_CLK_FREQUENCY_MHZ
#define ISH_CONFIG_CLK_FREQUENCY_MHZ (100 / SEDI_SOC_CLK_DIVISOR)
#endif

/*!
 * \enum sedi_hw_rev_t
 * \brief HW Revision ID
 */
typedef enum {
	SEDI_HW_REV_INVALID = 0
} sedi_hw_rev_t;

/*!
 * \enum sedi_uart_t
 * \brief  uart device bus ID
 */
typedef enum {
	SEDI_UART_0 = 0,
	SEDI_UART_1,
	SEDI_UART_2,
	SEDI_UART_NUM
} sedi_uart_t;

/*!
 * \enum sedi_dma_t
 * \brief  DMA device bus ID
 */
typedef enum {
	SEDI_DMA_0 = 0,
	SEDI_DMA_NUM
} sedi_dma_t;

/**DMA block TS**/
#define SEDI_DMA_PERIPH_MAX_SIZE 4096
#define SEDI_DMA_PERIPH_MAX_SIZE_SHIFT 12

/*!
 * \enum sedi_i2c_t
 * \brief  I2C device bus ID
 */
typedef enum {
	SEDI_I2C_0 = 0,
	SEDI_I2C_1,
	SEDI_I2C_2,
	SEDI_I2C_NUM
} sedi_i2c_t;

#define I2C_FIFO_DEPTH (64)

/*
 * \enum sedi_ipc_t
 * \brief IPC interface ID
 */
typedef enum {
	SEDI_IPC_HOST = 0,
	SEDI_IPC_CSME,
	SEDI_IPC_PMC,
	SEDI_IPC_NUM
} sedi_ipc_t;

/*!
 * \enum sedi_gpio_t
 * \brief  GPIO device bus ID
 */
typedef enum {
	SEDI_GPIO_0 = 0,
	SEDI_GPIO_NUM
} sedi_gpio_t;

#define ISH_PIN_NUM 36
#define SEDI_GPIO_SOC_PORT_NUM (2U)

#define SEDI_GPIO_TIMESTAMP_SLOTS_NUM 4
#define SEDI_GPIO_TIMESTAMP_INTERVAL 0x10

/*!
 * \enum sedi_watchdog_t
 * \brief  WATCHDOG device bus ID
 */
typedef enum {
	SEDI_WATCHDOG_0 = 0,
	SEDI_WATCHDOG_NUM
} sedi_watchdog_t;

#define SEDI_HPET_SOC_TIMER_NUM (3)

/*!
 * \enum sedi_spi_t
 * \brief  SPI device bus ID
 */
typedef enum {
	SEDI_SPI_0 = 0,
	SEDI_SPI_1,
	SEDI_SPI_NUM
} sedi_spi_t;

#define SPI_FIFO_DEPTH (64)

#if defined(CONFIG_SOC_INTEL_ISH_5_4_1) || defined(CONFIG_SOC_INTEL_ISH_5_6_0)
#define SEDI_IRQ_HPET_TIMER_0 (14)
#else
#define SEDI_IRQ_HPET_TIMER_0 (17)
#endif
#define SEDI_IRQ_HPET_TIMER_1 (0) /* fake IRQ number, same as timer 0's */

#if defined(CONFIG_SOC_INTEL_ISH_5_4_1) || defined(CONFIG_SOC_INTEL_ISH_5_6_0)
#define SEDI_IRQ_RESET_PREP (6)
#define SEDI_IRQ_PCIEDEV (9)
#define SEDI_IRQ_PMU2IOAPIC (10)
#else
#define SEDI_IRQ_RESET_PREP (8)
#define SEDI_IRQ_PCIEDEV (11)
#define SEDI_IRQ_PMU2IOAPIC (12)
#endif

/*!
 * \enum vnn_id_t
 * \brief VNN ID bit for different drivers
 * \ingroup sedi_soc_defs_ish
 */
typedef enum {
	VNN_ID_FIRST = 0,
	VNN_ID_AON_TASK = VNN_ID_FIRST,
	VNN_ID_DMA0,
	VNN_ID_SIDEBAND,
	VNN_ID_IPC_START,
	VNN_ID_TOP = VNN_ID_IPC_START + SEDI_IPC_NUM * 2,
} vnn_id_t;

#define VNN_ID_IPC_R(_instance) (VNN_ID_IPC_START + (_instance) * 2)
#define VNN_ID_IPC_W(_instance) (VNN_ID_IPC_START + (_instance) * 2 + 1)

/*!
 * \enum sedi_devid_t
 * \brief SEDI device ID table
 * \ingroup sedi_soc_defs_ish
 */
typedef enum {
	SEDI_DEVID_FIRST = 0,
	SEDI_DEVID_I2C0 = SEDI_DEVID_FIRST,
	SEDI_DEVID_I2C1,
	SEDI_DEVID_I2C2,
	SEDI_DEVID_UART0,
	SEDI_DEVID_UART1,
	SEDI_DEVID_UART2,
	SEDI_DEVID_GPIO0,
	SEDI_DEVID_DMA0,
	SEDI_DEVID_SPI0,
	SEDI_DEVID_SPI1,
	SEDI_DEVID_TOP
} sedi_devid_t;

/*!
 * peripheral device id for dma handshake
 */
typedef enum {
	DMA_HWID_I2C0_RX = 0,
	DMA_HWID_I2C0_TX = 1,
	DMA_HWID_I2C1_RX = 2,
	DMA_HWID_I2C1_TX = 3,
	DMA_HWID_I2C2_RX = 4,
	DMA_HWID_I2C2_TX = 5,
	DMA_HWID_UART0_RX = 6,
	DMA_HWID_UART0_TX = 7,
	DMA_HWID_UART1_RX = 8,
	DMA_HWID_UART1_TX = 9,
	DMA_HWID_UART2_RX = 10,
	DMA_HWID_UART2_TX = 11,
	DMA_HWID_SPI0_RX = 12,
	DMA_HWID_SPI0_TX = 13,
	DMA_HWID_SPI1_RX = 14,
	DMA_HWID_SPI1_TX = 15,
} dma_hs_per_dev_id_t;

/* The step number of hardware IDs per device */
#define SEDI_HWID_PER_DEVICE 2

/*!
 * \brief check if a device is owned by SoC itself
 * \param[in] dev: device id to check
 * \return true/false
 * \ingroup sedi_soc_defs_ish
 */
static inline bool sedi_dev_is_self_owned(sedi_devid_t dev)
{
	(void)dev;

	return true;
}

#endif /* _SEDI_SOC_DEFS_H_ */
