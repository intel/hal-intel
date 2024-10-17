/*
 * Copyright (c) 2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_SOC_FUNCS_H_
#define _SEDI_SOC_FUNCS_H_

#include <stdbool.h>
#include "sedi_soc_defs.h"

/*!
 * \defgroup sedi_soc_funcs_ish Intel ISH SoC Helper Functions
 */

/*!
 * \fn uint32_t sedi_pm_get_hbw_clock(void)
 * \brief Get current HBW clock frequency
 * \return uint32_t current HBW clock frequency
 * \ingroup sedi_soc_funcs_ish
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
 * \ingroup sedi_soc_funcs_ish
 */
static inline uint32_t sedi_pm_get_lbw_clock(void)
{
	return SEDI_MHZ_TO_HZ(ISH_CONFIG_CLK_FREQUENCY_MHZ);
}

/*!
 * \brief Request VNN for a device
 * \param[in] vnn_id: device id
 * \return void
 * \ingroup sedi_soc_funcs_ish
 */
void PM_VNN_DRIVER_REQ(vnn_id_t vnn_id);

/*!
 * \brief De-request VNN for a device
 * \param[in] vnn_id: device id
 * \return void
 * \ingroup sedi_soc_funcs_ish
 */
void PM_VNN_DRIVER_DEREQ(vnn_id_t vnn_id);

/*!
 * \brief Reset VNN for all devices
 * \return void
 * \ingroup sedi_soc_funcs_ish
 */
void PM_VNN_ALL_RESET(void);

/*!
 * \brief Reset VNN for a device
 * \param[in] vnn_id: device id
 * \return void
 * \ingroup sedi_soc_funcs_ish
 */
void PM_VNN_DRIVER_RESET(vnn_id_t vnn_id);

#endif /* _SEDI_SOC_FUNCS_H_ */
