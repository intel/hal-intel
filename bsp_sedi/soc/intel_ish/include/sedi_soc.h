/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_SOC_H_
#define _SEDI_SOC_H_

#define SEDI_CONFIG_ARCH_X86	(1)

#define SEDI_MHZ_TO_HZ(mhz) ((mhz) * 1000000)

#ifndef ISH_CONFIG_CLK_FREQUENCY_MHZ
#ifdef CONFIG_ISH_PLATFORM_FPGA
#define ISH_CONFIG_CLK_FREQUENCY_MHZ (20)
#else
#define ISH_CONFIG_CLK_FREQUENCY_MHZ (100)
#endif
#endif

#ifndef ISH_CONFIG_HBW_CLK_DIVIDER
#define ISH_CONFIG_HBW_CLK_DIVIDER (1)
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

#define PM_VNN_DRIVER_REQ(vnn_id)                                              \
	do {                                                                   \
		if ((read32(PMU_VNN_REQ_31_0) & BIT(vnn_id)) == 0) {           \
			write32(PMU_VNN_REQ_31_0, BIT(vnn_id));                \
			while (                                                \
			    !(read32(PMU_VNN_REQ_ACK) & PMU_VNN_REQ_ACK_STS))  \
				;                                              \
		}                                                              \
	} while (0)

#define PM_VNN_DRIVER_DEREQ(vnn_id)                                            \
	do {                                                                   \
		if ((read32(PMU_VNN_REQ_31_0) & BIT(vnn_id)) != 0) {           \
			write32(PMU_VNN_REQ_31_0, BIT(vnn_id));                \
			write32(PMU_VNN_REQ_ACK, read32(PMU_VNN_REQ_ACK));     \
		}                                                              \
	} while (0)

#define PM_VNN_ALL_RESET()                                                     \
	do {                                                                   \
		write32(PMU_VNN_REQ_31_0, read32(PMU_VNN_REQ_31_0));           \
		write32(PMU_VNN_REQ_ACK, read32(PMU_VNN_REQ_ACK));             \
	} while (0)

#define PM_VNN_DRIVER_RESET(vnn_id)                                            \
	write32(PMU_VNN_REQ_31_0,                                              \
		read32(PMU_VNN_REQ_31_0) & BIT(vnn_id));

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

#endif
