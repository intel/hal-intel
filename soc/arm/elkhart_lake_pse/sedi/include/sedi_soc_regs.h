/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_SOC_REGS_H_
#define _SEDI_SOC_REGS_H_

/*!
 * \defgroup sedi_soc SEDI-SOC
 * \ingroup sedi
 */

#define PLATFORM_SI

/*!
 * @brief SOC clocks (Mhz)
 */
/* TODO: temporary setting for PO, will investigate
 * a better solution to distinguish silicon and FPGA
 */
#if defined(PLATFORM_SI)
/* TODO: The macro SEDI_PSE_LBW_OCP_CLOCK would be
 * removed, recommend to use sedi_pm_get_lbw_clock()
 */
#define SEDI_PSE_LBW_OCP_CLOCK (100U)
#define S0IX_CLK (100 * 1000000UL)
#define MAIN_CLK_200M (200 * 1000000UL)
#define MAIN_CLK_400M (400 * 1000000UL)
#define MAX_CLK_500M (500 * 1000000UL)
#else
#define SEDI_PSE_LBW_OCP_CLOCK (20U)
#define S0IX_CLK (20 * 1000000UL)
#define MAIN_CLK_200M (20 * 1000000UL)
#define MAIN_CLK_400M (20 * 1000000UL)
#define MAX_CLK_500M (20 * 1000000UL)
#endif

/*!
 * \defgroup soc_regs SOC MMIOs
 * \ingroup sedi_soc
 * \{
 */

#define MISC_BASE 0x40700000

/****** GPIO *****/

/*!
 * \struct sedi_gpio
 * \brief  GPIO controller device ID
 */
typedef enum { SEDI_GPIO_0 = 0, SEDI_GPIO_1, SEDI_GPIO_NUM } sedi_gpio_t;

#define SEDI_GPIO_0_REG_BASE (0x40200000)
#define SEDI_GPIO_1_REG_BASE (0x40300000)

#define SEDI_IRQ_GPIO_0 (15U)
#define SEDI_IRQ_GPIO_1 (16U)

#define SEDI_GPIO_SOC_PORT_NUM (2U)

/*!
 * @brief  TGPIO base addresses
 */
#define SEDI_TGPIO_0_BASE (0x40201000)
#define SEDI_TGPIO_1_BASE (0x40301000)

#define TGPIO_MUX_SEL_REG_0_LH2OSE (IPC_HOST_BASE + 0xB00)
#define TGPIO_MUX_SEL_REG_1_LH2OSE (IPC_HOST_BASE + 0xB04)

#define SEDI_TGPIO_SFT_RST_REG (SEDI_CCU_BASE + 0xC8)

/*
 * @brief  TGPIO interrupt lines
 */
#define SEDI_TGPIO_0_INTR (17)
#define SEDI_TGPIO_1_INTR (18)

/*!
 * \brief PWM register base address
 */
#define SEDI_PWM_0_BASE (0x48400000)
#define SEDI_PWM_1_BASE (0x48401000)

#define SEDI_PWM_SFT_RST_REG (SEDI_CCU_BASE + 0x6C)

#define SEDI_PWM_0_INTR (44)
#define SEDI_PWM_1_INTR (45)

/****** i2c *****/

#define SEDI_CLOCK_I2C (SEDI_PSE_LBW_OCP_CLOCK)

/*!
 * \struct sedi_i2c
 * \brief  I2C device bus ID
 */
typedef enum {
	SEDI_I2C_0 = 0,
	SEDI_I2C_1,
	SEDI_I2C_2,
	SEDI_I2C_3,
	SEDI_I2C_4,
	SEDI_I2C_5,
	SEDI_I2C_6,
	SEDI_I2C_7,
	SEDI_I2C_NUM
} sedi_i2c_t;

#define SEDI_I2C_0_REG_BASE (0x40100000)
#define SEDI_I2C_1_REG_BASE (0x40102000)
#define SEDI_I2C_2_REG_BASE (0x40104000)
#define SEDI_I2C_3_REG_BASE (0x40106000)
#define SEDI_I2C_4_REG_BASE (0x40108000)
#define SEDI_I2C_5_REG_BASE (0x4010A000)
#define SEDI_I2C_6_REG_BASE (0x4010C000)
#define SEDI_I2C_7_REG_BASE (0x4010E000)

#define SEDI_I2C_0_IRQ (26)
#define SEDI_I2C_1_IRQ (27)
#define SEDI_I2C_2_IRQ (28)
#define SEDI_I2C_3_IRQ (29)
#define SEDI_I2C_4_IRQ (30)
#define SEDI_I2C_5_IRQ (31)
#define SEDI_I2C_6_IRQ (32)
#define SEDI_I2C_7_IRQ (33)

#define I2C_FIFO_DEPTH (64)

/****** ipc *****/
#define SEDI_IRQ_IPC_HOST 0
#define SEDI_IRQ_IPC_CSME 1
#define SEDI_IRQ_IPC_PMC 2

#define IPC_HOST_BASE 0x40400000
#define IPC_CSME_BASE 0x40410000
#define IPC_PMC_BASE 0x40411000

/******* rtc ******/
#define SEDI_RTC_COUNTER (MISC_BASE + 0x94)
#define SEDI_RTC_COUNTER0 (MISC_BASE + 0x94)
#define SEDI_RTC_COUNTER1 (MISC_BASE + 0x98)

/* HW revision ID */
#define SEDI_HW_REVID (MISC_BASE + 0x100)
#define SEDI_HW_REVID_A0 0xB
#define SEDI_HW_REVID_B0 0x1
typedef enum {
	SEDI_HW_REV_INVALID = 0,
	SEDI_HW_REV_A0,
	SEDI_HW_REV_B0,
} sedi_hw_rev_t;

/******* DTF ******/
#define SEDI_DTF_REG_BASE 0x40900000

#define DTF_PCKTZR_DTF_SRC_CONFIG (SEDI_DTF_REG_BASE + 0x0)
#define DTF_PCKTZR_CONFIG_SRC_ENABLE (1 << 0)
#define DTF_PCKTZR_DTF_SRC_STATUS (SEDI_DTF_REG_BASE + 0x4)
#define DTF_PCKTZR_STATUS_BUSY (1 << 31)
#define DTF_ENCDR_DTF_SRC_CONFIG (SEDI_DTF_REG_BASE + 0x8)
#define DTF_ENCDR_DTF_SRC_STATUS (SEDI_DTF_REG_BASE + 0xC)
#define DTF_USR64_LOW_ADDR (SEDI_DTF_REG_BASE + 0x20)
#define DTF_USR64_HI_ADDR (SEDI_DTF_REG_BASE + 0x24)
#define DTF_DATA_WITHOUT_EOP (SEDI_DTF_REG_BASE + 0x28)
#define DTF_DATA_WITH_EOP (SEDI_DTF_REG_BASE + 0xFFC)

/****** uart *****/
/** Number of UART controllers. */
typedef enum {
	SEDI_UART_0 = 0,
	SEDI_UART_1,
	SEDI_UART_2,
	SEDI_UART_3,
	SEDI_UART_4,
	SEDI_UART_5,
	SEDI_UART_NUM
} sedi_uart_t;

/* UART register base addresses. */
#define SEDI_UART_0_BASE (0x48200000)
#define SEDI_UART_1_BASE (0x48202000)
#define SEDI_UART_2_BASE (0x48204000)
#define SEDI_UART_3_BASE (0x48206000)
#define SEDI_UART_4_BASE (0x48208000)
#define SEDI_UART_5_BASE (0x4820a000)

/******* QEP ******/

/* Number of QEP controllers */
typedef enum {
	SEDI_QEP_0,
	SEDI_QEP_1,
	SEDI_QEP_2,
	SEDI_QEP_3,
	SEDI_QEP_MAX
} sedi_qep_t;

/******* QEP Base Addresses ******/
#define SEDI_QEP_0_BASE (0x48600000)
#define SEDI_QEP_1_BASE (0x48602000)
#define SEDI_QEP_2_BASE (0x48604000)
#define SEDI_QEP_3_BASE (0x48606000)

/*!
 * \}
 */

/****** dma *****/

/*!
 * \struct sedi_dma
 * \brief  DMA device bus ID
 */
typedef enum {
	SEDI_DMA_0 = 0,
	SEDI_DMA_1,
	SEDI_DMA_2,
	SEDI_DMA_NUM
} sedi_dma_t;

#define SEDI_DMA_0_REG_BASE 0x50100000
#define SEDI_DMA_1_REG_BASE 0x50104000
#define SEDI_DMA_2_REG_BASE 0x50108000

#define SEDI_IRQ_DMA_0 11
#define SEDI_IRQ_DMA_1 12
#define SEDI_IRQ_DMA_2 13

/*!
 * \}
 */

/****** watchdog *****/

/*!
 * \struct sedi_watchdog
 * \brief  WATCHDOG device bus ID
 */
typedef enum { SEDI_WATCHDOG_0 = 0, SEDI_WATCHDOG_NUM } sedi_watchdog_t;

#define SEDI_WATCHDOG_0_REG_BASE 0x40B00000

#define SEDI_WATCHDOG_0_IRQ 25

/* Refer to HAS */
#if defined(PLATFORM_SI)
#define SEDI_CLOCK_WATCHDOG (32768)
#else
#define SEDI_CLOCK_WATCHDOG (32768 / 5)
#endif

/***************HPET***********/
#define SEDI_HPET_BASE 0x40A00000

#define SEDI_HPET_SOC_TIMER_NUM (3)

#define SEDI_IRQ_HPET_TIMER_0 (19)
#define SEDI_IRQ_HPET_TIMER_1 (20)
#define SEDI_IRQ_HPET_TIMER_2 (21)

/****** SPI *****/

#define SEDI_CLOCK_SPI (SEDI_PSE_LBW_OCP_CLOCK)

/*!
 * \struct sedi_spi
 * \brief  SPI device bus ID
 */
typedef enum {
	SEDI_SPI_0 = 0,
	SEDI_SPI_1,
	SEDI_SPI_2,
	SEDI_SPI_3,
	SEDI_SPI_NUM
} sedi_spi_t;

#define SEDI_SPI_0_REG_BASE (0x48100000)
#define SEDI_SPI_1_REG_BASE (0x48102000)
#define SEDI_SPI_2_REG_BASE (0x48104000)
#define SEDI_SPI_3_REG_BASE (0x48106000)

#define SEDI_SPI_0_IRQ (34)
#define SEDI_SPI_1_IRQ (35)
#define SEDI_SPI_2_IRQ (36)
#define SEDI_SPI_3_IRQ (37)

#define SPI_FIFO_DEPTH (64)

/****** I2S *****/

#define I2S_REGS_BASE_0 (0x48300000)
#define I2S_REGS_BASE_1 (0x48302000)

#define I2S_MN_DIV_REGS_BASE_0 (0x406000B0)
#define I2S_MN_DIV_REGS_BASE_1 (0x406000BC)
/**
 * @brief I2S instance
 */
typedef enum { SEDI_I2S_NUM_0 = 0x00, SEDI_I2S_NUM_1, SEDI_I2S_MAX } sedi_i2s_t;

/****** IOSF SBEP registers ******/
#define SBEP_REG_BASE (0x40800000)

/*!
 * \brief PMU base addresses
 */
#define SEDI_PMU_BASE 0x40500000

/*!
 * \brief PMU interrupt lines
 */
#define SEDI_IRQ_DASHBOARD (5)
#define SEDI_IRQ_PMU_RESETPREP (6)
#define SEDI_IRQ_PMU_WAKE (7)
#define SEDI_IRQ_PMU_PCIEDEV (9)
#define SEDI_IRQ_PMU_TO_NVIC (10)
#define SEDI_IRQ_FABRIC (14)
#define SEDI_IRQ_PMU_CRU_CLK_ACK (104)

/*!
 * \brief CCU base addresses
 */
#define SEDI_CCU_BASE 0x40600000
#define SEDI_PLL_CRI_BASE 0x41000000

/*!
 * \}
 */

#endif /* _SEDI_SOC_REGS_H_ */
