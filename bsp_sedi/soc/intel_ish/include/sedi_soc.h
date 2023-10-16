/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_SOC_H_
#define _SEDI_SOC_H_

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
 * \defgroup sedi_soc_ish Intel ISH SoC
 */

/*!
 * \fn uint32_t sedi_pm_get_hbw_clock(void)
 * \brief Get current HBW clock frequency
 * \return uint32_t current HBW clock frequency
 * \ingroup sedi_soc_ish
 */
static inline uint32_t sedi_pm_get_hbw_clock(void)
{
	return SEDI_MHZ_TO_HZ(ISH_CONFIG_CLK_FREQUENCY_MHZ /
			ISH_CONFIG_HBW_CLK_DIVIDER);
}

/*!
 * \fn uint32_t sedi_pm_get_lbw_clock(void)
 * \brief Get current LBW clock frequency
 * \return uint32_t current LBW clock frequency
 * \ingroup sedi_soc_ish
 */
static inline uint32_t sedi_pm_get_lbw_clock(void)
{
	return SEDI_MHZ_TO_HZ(ISH_CONFIG_CLK_FREQUENCY_MHZ);
}

/*!
 * \enum vnn_id_t
 * \brief VNN ID bit for different drivers
 * \ingroup sedi_soc_ish
 */
typedef enum {
	VNN_ID_FIRST = 0,
	VNN_ID_AON_TASK = VNN_ID_FIRST,
	VNN_ID_IPC_HOST_W,
	VNN_ID_IPC_HOST_R,
	VNN_ID_IPC_CSME_W,
	VNN_ID_IPC_CSME_R,
	VNN_ID_IPC_PMC_W = 5,
	VNN_ID_IPC_PMC_R,
	VNN_ID_DMA0,
	VNN_ID_SIDEBAND,
	VNN_ID_TOP,
} vnn_id_t;

#define VNN_ID_IPC_CSE_R VNN_ID_IPC_CSME_R
#define VNN_ID_IPC_CSE_W VNN_ID_IPC_CSME_W

#ifndef SEDI_PMU_BASE
#define SEDI_PMU_BASE (0x04200000)
#endif

#define PMU_VNN_REQ_31_0 (SEDI_PMU_BASE + 0x3c)
#define PMU_VNN_REQ_ACK (SEDI_PMU_BASE + 0x40)
#define PMU_VNN_REQ_ACK_STS BIT(0)

/*!
 * \enum sedi_devid_t
 * \brief SEDI device ID table
 * \ingroup sedi_soc_ish
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

/*!
 * \brief check if a device is owned by SoC itself
 * \param[in] dev: device id to check
 * \return true/false
 * \ingroup sedi_soc_ish
 */
static inline bool sedi_dev_is_self_owned(sedi_devid_t dev)
{
	(void)dev;

	return true;
}

/*!
 * \brief Request VNN for a device
 * \param[in] vnn_id: device id
 * \return void
 * \ingroup sedi_soc_ish
 */
void PM_VNN_DRIVER_REQ(vnn_id_t vnn_id);

/*!
 * \brief De-request VNN for a device
 * \param[in] vnn_id: device id
 * \return void
 * \ingroup sedi_soc_ish
 */
void PM_VNN_DRIVER_DEREQ(vnn_id_t vnn_id);

/*!
 * \brief Reset VNN for all devices
 * \return void
 * \ingroup sedi_soc_ish
 */
void PM_VNN_ALL_RESET(void);

/*!
 * \brief Reset VNN for a device
 * \param[in] vnn_id: device id
 * \return void
 * \ingroup sedi_soc_ish
 */
void PM_VNN_DRIVER_RESET(vnn_id_t vnn_id);

#endif
