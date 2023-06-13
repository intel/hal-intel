/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_RTC_H_
#define _SEDI_DRIVER_RTC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_rtc RTC
 * \ingroup sedi_driver
 */

#define SEDI_RTC_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/*!
 * \struct sedi_rtc_capabilities_t
 * \brief RTC Driver Capabilities.
 * \ingroup sedi_driver_rtc
 */
typedef struct {
	uint32_t support_alarm : 1; /**< interrupt supports timestamp */
	uint32_t support_callback : 1; /**< RTC support interrupt callback feature*/
	uint32_t reserved : 30;
} sedi_rtc_capabilities_t;

/*!
 * \struct sedi_rtc_time
 * \brief RTC time.
 * \ingroup sedi_driver_rtc
 */
typedef struct {
	uint32_t year;   /**< Year of the time */
	uint8_t month;   /**< Month*/
	uint8_t day;     /**< Day */
	uint8_t hour;    /**< Time hour */
	uint8_t minute;  /**< Time minute */
	uint8_t seconds; /**< Time second */
} sedi_rtc_time_t;

/*!
 * \defgroup rtc_event_handler RTC Event Handler Callback
 * \ingroup sedi_driver_rtc
 * \{
 */
/*!
 * \typedef sedi_rtc_event_cb_t
 * \brief Callback function type for signal rtc event.
 * \param[in] event_flag: Event flags for the callback.
 * \param[in] param:  User callback parameter pointer.
 * \return    void
 */
typedef void (*sedi_rtc_event_cb_t)(IN uint32_t event_flag, INOUT void *param);

/*!
 * \}
 */

/*!
 * \brief Get rtc driver's API versions
 * \return the version of current rtc driver
 */
sedi_driver_version_t sedi_rtc_get_version(void);

/*!
 * \brief Get rtc device's capabilities.
 * \param[out] cap: RTC device capabilities pointer
 * \return \ref return_status
 */
int sedi_rtc_get_capabilities(sedi_rtc_capabilities_t *cap);

/*!
 * \brief Init rtc module
 * \return \ref return_status
 */
int sedi_rtc_init(void);

/*!
 * \brief Uninit rtc module.
 * \return \ref return_status
 */
int sedi_rtc_uninit(void);

/*!
 * \brief Set rtc module power state.
 * \param[IN] state: Power state.
 * \return \ref return_status.
 */
int sedi_rtc_set_power(IN sedi_power_state_t state);

/*!
 * \brief Get rtc timer.
 * \return Timer of rtc in clock cycle
 */
uint64_t sedi_rtc_get(void);

/*!
 * \brief Get rtc time in microsecond
 * \return RTC time in microsecond
 */
uint64_t sedi_rtc_get_us(void);

#ifdef __cplusplus
}
#endif

#endif /*_SEDI_DRIVER_RTC_H_*/
