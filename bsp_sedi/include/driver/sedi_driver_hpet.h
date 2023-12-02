/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_HPET_H_
#define _SEDI_DRIVER_HPET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_hpet HPET
 * \ingroup sedi_driver
 */

#define SEDI_HPET_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/*!
 * \defgroup sedi_sideband_t HPET instance id
 * \ingroup sedi_driver_hpet
 */
typedef enum {
	HPET_0 = 0,
	HPET_1,
	HPET_2,
	HPET_NUM,
} sedi_hpet_t;

/*!
 * \struct sedi_hpet_capabilities_t
 * \brief HPET Driver Capabilities.
 * \ingroup sedi_driver_hpet
 */
typedef struct sedi_hpet_capabilities {
	uint32_t reserved;
} sedi_hpet_capabilities_t;

/*!
 * \defgroup hpet_function_calls HEPT Driver Function Calls
 * \ingroup sedi_driver_hpet
 * \{
 */

/*!
 * \brief Hpet callback function.
 * \param param User callback parameter.
 */
typedef int (*hpet_callback_t)(void *param);

/*!
 * \brief Get the hpet driver's API version.
 * \return the version of current hpet driver's API
 */
sedi_driver_version_t sedi_hpet_get_version(void);

/*!
 * \brief Get the device's capabilities.
 * \return the capabilities of hpet device
 */
sedi_hpet_capabilities_t sedi_hpet_get_capabilities(void);

/*!
 * \brief Get HPET's current setting of minimal delay time.
 * \return HPET's current setting of minimal delay time.
 */
uint32_t sedi_hpet_get_min_delay(void);

/*!
 * \brief Set HPET's minimal delay time. The comparator value must be set
 *	farther than this value, ahead of the current main counter value.
 *	Or interrupt might be missed due to the hardware latency
 * \param[in] min_delay: SoC-specific HPET minimal delay time.
 */
void sedi_hpet_set_min_delay(uint32_t min_delay);

/*!
 * \brief Initialize the device
 * \param[in] clk_divisor: the clock divisor to set.
 * \param[in] min_delay: SoC-specific HPET minimal delay time to set.
 * \return  \ref return_status
 */
int32_t sedi_hpet_init(uint32_t clk_divisor, uint32_t min_delay);

/*!
 * \brief Uninitialize the device
 * \return  \ref return_status
 */
int32_t sedi_hpet_uninit(void);

/*!
 * \brief Set the device's power
 * \param[in] state: the power state to be set to the device
 * \return  \ref return_status
 */
int32_t sedi_hpet_set_power(IN sedi_power_state_t state);

/*!
 * \brief Set the timer's comparator. This means when to trigger an interrupt.
 * \param[in] timer_id: Timer ID to set.
 * \param[in] value: The value need to set.
 * \return  \ref return_status
 */
int sedi_hpet_set_comparator(IN sedi_hpet_t timer_id, IN uint64_t value);

/*!
 * \brief Set the timer's main counter to the new value.
 * \param[in] value: The value need to set.
 */
void sedi_hpet_set_main_counter(uint64_t value);

/*!
 * \brief Get the timer's current value of main counter.
 * \return The current value of main counter.
 */
uint64_t sedi_hpet_get_main_counter(void);

uint64_t sedi_hpet_get_us(void);

/*!
 * \brief Enable the timer's interrupt.
 * \param[in] timer_id: Timer ID to enable interrupt.
 */
void sedi_hpet_enable_interrupt(IN sedi_hpet_t timer_id);

/*!
 * \brief Disable the timer's interrupt.
 * \param[in] timer_id: Timer ID to enable interrupt.
 */
void sedi_hpet_disable_interrupt(IN sedi_hpet_t timer_id);

/*!
 * \brief Get the interrupt status.
 * \return the current value of the interrupt status.
 */
uint32_t sedi_hpet_get_int_status(void);

/*!
 * \brief Set value to the interrupt status to clear.
 * \param[in] val: val to set to the interrupt status.
 */
void sedi_hpet_set_int_status(IN uint32_t val);

/*!
 * \brief Handle the interrupt of HPET Timer N
 * \param[in] timer_id: Timer ID to handle.
 */
void sedi_hpet_timer_int_handler(IN sedi_hpet_t timer_id);

/*!
 * \brief Get the timer's period, specified in picoseconds.
 * \1000000 ps: (1 MHz clock period)
 * \83333 ps: (12 MHz clock period)
 * \30517578 ps: (32.768 KHz clock period)
 * \return the value of period.
 */
uint32_t sedi_hpet_get_period(void);

/*!
 * \brief initialize one timer
 * \param[in] timer_id Timer index to be configured
 * \param[in] microseconds: the cycle of timer
 * \param[in] callback: callback function when timeout
 * \param[in] param: callback parameters
 * \param[in] one_shot: if it is a one_shot timer
 * \return fail reason
 */
int32_t sedi_hpet_config_timer(IN sedi_hpet_t timer_id,
			       IN uint64_t microseconds,
			       IN hpet_callback_t callback, IN void *param,
			       IN bool one_shot);

/*!
 * \brief start the timer
 * \param[in] timer_id: the timer's id
 * \return fail reason
 */
int32_t sedi_hpet_start_timer(IN sedi_hpet_t timer_id);

/*!
 * \brief kill the timer
 * \param[in] timer_id: the timer's id
 * \return fail reason
 */
int32_t sedi_hpet_kill_timer(IN sedi_hpet_t timer_id);

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_HPET_H_*/
