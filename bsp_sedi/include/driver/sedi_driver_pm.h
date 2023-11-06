/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_PM_H_
#define _SEDI_DRIVER_PM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_pm Power Management
 * \ingroup sedi_driver
 */

/*!
 * \defgroup pm_function_calls PM Driver Function Calls
 * \ingroup sedi_driver_pm
 * \{
 */

/*!
 * \brief Set a device into some power state
 * \param[in] id: device id
 * \param[in] state: the power state to be set to the device
 * \return void
 */
void sedi_pm_set_device_power(IN sedi_devid_t id, IN sedi_power_state_t state);

/*!
 * \brief Get the power state of a device
 * \param[in] id: device id
 * \return \ref sedi_power_state_t
 */
sedi_power_state_t sedi_pm_get_device_power(IN sedi_devid_t id);

/*!
 * \brief Notify host suspend state change to SEDI PM
 * \param[in] suspend: host goes into/out of suspend state
 * \return void
 */
void sedi_pm_host_suspend(uint32_t suspend);

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_PM_H_*/
