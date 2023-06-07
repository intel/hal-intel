/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_GPIO_H_
#define _SEDI_DRIVER_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_gpio GPIO
 * \ingroup sedi_driver
 */

#define SEDI_GPIO_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/****** GPIO pin config *****/

/*!
 * \defgroup gpio_pin_config GPIO Pin Configuration
 * \ingroup sedi_driver_gpio
 * \{
 */

/*!
 * \struct sedi_gpio_port_
 * \brief  GPIO pin port enumeration
 */
typedef enum {
	GPIO_PORT_0 = 0,
	GPIO_PORT_1,
	GPIO_PORT_2,
	GPIO_PORT_3,
	GPIO_PORT_4,
	GPIO_PORT_5,
	GPIO_PORT_MAX_NUM
} sedi_gpio_port_t;

/*!
 * \struct sedi_gpio_direction_mode_
 * \brief  GPIO pin direction enumeration
 */
typedef enum {
	SEDI_GPIO_DIR_MODE_INPUT = 0,
	SEDI_GPIO_DIR_MODE_OUTPUT
} sedi_gpio_direction_mode_t;

/*!
 * \struct sedi_gpio_interrupt_mode_
 * \brief  GPIO interrupt mode enumeration
 */
typedef enum {
	SEDI_GPIO_INT_MODE_FALLING_EDGE = 0x1,
	SEDI_GPIO_INT_MODE_RISING_EDGE = 0x2,
	SEDI_GPIO_INT_MODE_BOTH_EDGE = 0x3
} sedi_gpio_interrupt_mode_t;

/*!
 * \struct sedi_gpio_pin_config_
 * \brief GPIO Pin Config Structure definition
 */
typedef struct {
	sedi_gpio_direction_mode_t direction;
	bool enable_interrupt;
	bool enable_wakeup;
	sedi_gpio_interrupt_mode_t interrupt_mode;
} sedi_gpio_pin_config_t;

/*!
 * \}
 */

/*!
 * \struct sedi_gpio_pin_state
 * \brief  GPIO pin low or high value enumeration
 * \ingroup sedi_driver_gpio
 */
typedef enum {
	SEDI_GPIO_STATE_LOW = 0,
	SEDI_GPIO_STATE_HIGH
} sedi_gpio_pin_state_t;

/****** GPIO Event *****/

/*!
 * \defgroup gpio_event GPIO Event Types
 * \ingroup sedi_driver_gpio
 * \{
 */

/*!
 * \def SEDI_GPIO_EVENT_INTERRUPT
 * \brief Interrupt event
 */
#define SEDI_GPIO_EVENT_INTERRUPT (1UL << 0)

/*!
 * \}
 */

/*!
 * \struct sedi_gpio_capabilities_t
 * \brief GPIO Driver Capabilities.
 * \ingroup sedi_driver_gpio
 */
typedef struct {
	uint32_t support_pins_map;      /**< supports pins map */
	uint32_t support_timestamp : 1; /**< interrupt supports timestamp */
	uint32_t is_available : 1;      /** 1:available 0:used by host  **/
	uint32_t reserved : 30;		/**< Reserved (must be zero) */
} sedi_gpio_capabilities_t;

/*!
 * \defgroup gpio_event_handler GPIO Event Handler Callback
 * \ingroup sedi_driver_gpio
 * \{
 */
/*!
 * \typedef sedi_gpio_event_cb_t
 * \brief Callback function type for signal gpio event.
 * \param[in] pin_mask:  32-bits pin mask, indicate the pins trigger this
 * callback.
 * \param[in] group:  Group number, a port can cover 32 pins.
 * \param[in] param:  User callback parameter pointer.
 * \return    void
 */
typedef void (*sedi_gpio_event_cb_t)(IN uint32_t pin_mask,
				     IN sedi_gpio_port_t port,
				     INOUT void *param);

/*!
 * \}
 */

/*!
 * \defgroup gpio_function_calls GPIO Driver Function Calls
 * \ingroup sedi_driver_gpio
 * \{
 */

/*!
 * \brief Get the gpio driver's API version.
 * \return the version of current gpio driver's API
 */
sedi_driver_version_t sedi_gpio_get_version(void);

/*!
 * \brief Get the device's capabilities.
 * \param[in] gpio_device: device id
 * \param[out] cap: gpio device capabilities
 * \return  \ref return_status
 */
int32_t sedi_gpio_get_capabilities(IN sedi_gpio_t gpio_device,
				   OUT sedi_gpio_capabilities_t *cap);

/*!
 * \brief Initialize the device
 * \param[in] gpio_device: gpio device id
 * \param[in] cb:  the callback function which can receive device's events.
 * \param[in] param:  User parameter for callback function.
 * \return  \ref return_status
 */
int32_t sedi_gpio_init(IN sedi_gpio_t gpio_device, IN sedi_gpio_event_cb_t cb,
		       INOUT void *param);

/*!
 * \brief Uninitialize the device
 * \param[in] gpio_device: gpio device id
 * \return  \ref return_status
 */
int32_t sedi_gpio_uninit(IN sedi_gpio_t gpio_device);

/*!
 * \brief Set the device's power
 * \param[in] gpio_device: gpio device id
 * \param[in] state: the power state to be set to the device
 * \return  \ref return_status
 */
int32_t sedi_gpio_set_power(IN sedi_gpio_t gpio_device,
			    IN sedi_power_state_t state);

/*!
 * \brief Configurate the pin of a gpio device
 * \param[in] gpio_device: gpio device id
 * \param[in] pin: gpio pin number in this device
 * \param[in] pin_config: pin configuration
 * \return void
 */
void sedi_gpio_config_pin(IN sedi_gpio_t gpio_device, IN uint32_t pin,
			  IN sedi_gpio_pin_config_t pin_config);

/*!
 * \brief Write pin state value
 * \param[in] gpio_device: gpio device id
 * \param[in] pin: gpio pin number in this device
 * \param[in] pin_state: pin state value to write
 * \return void
 */
void sedi_gpio_write_pin(IN sedi_gpio_t gpio_device, IN uint32_t pin,
			 IN sedi_gpio_pin_state_t pin_state);

/*!
 * \brief Write 8 pins state value one time
 * \param[in] gpio_device: gpio device id
 * \param[in] group: gpio pin group, 8 pins in a group
 * \param[in] pin_state: pin state value to write
 * \return void
 */
void sedi_gpio_write_pin_8bits(IN sedi_gpio_t gpio_device, IN uint8_t group,
			       IN sedi_gpio_pin_state_t pin_state);

/*!
 * \brief Write 16 pins state value one time
 * \param[in] gpio_device: gpio device id
 * \param[in] group: gpio pin group, 16 pins in a group
 * \param[in] pin_state: pin state value to write
 * \return void
 */
void sedi_gpio_write_pin_16bits(IN sedi_gpio_t gpio_device, IN uint8_t group,
				IN sedi_gpio_pin_state_t pin_state);

/*!
 * \brief Write 32 pins state value one time
 * \param[in] gpio_device: gpio device id
 * \param[in] group: gpio pin group, 32 pins in a group
 * \param[in] pin_state: pin state value to write
 * \return void
 */
void sedi_gpio_write_pin_32bits(IN sedi_gpio_t gpio_device, IN uint8_t group,
				IN sedi_gpio_pin_state_t pin_state);

/*!
 * \brief Read 8 pins state value one time
 * \param[in] gpio_device: gpio device id
 * \param[in] group: gpio pin group, 8 pins in a group
 * \return 8-bit pin value
 */
uint8_t sedi_gpio_read_pin_8bits(IN sedi_gpio_t gpio_device, IN uint8_t group);

/*!
 * \brief Read 16 pins state value one time
 * \param[in] gpio_device: gpio device id
 * \param[in] group: gpio pin group, 16 pins in a group
 * \return 16-bit pin value
 */
uint16_t sedi_gpio_read_pin_16bits(IN sedi_gpio_t gpio_device,
				   IN uint8_t group);

/*!
 * \brief Read 32 pins state value one time
 * \param[in] gpio_device: gpio device id
 * \param[in] group: gpio pin group, 32 pins in a group
 * \return 32-bit pin value
 */
uint32_t sedi_gpio_read_pin_32bits(IN sedi_gpio_t gpio_device,
				   IN uint8_t group);

/*!
 * \brief Read pin state value
 * \param[in] gpio_device: gpio device id
 * \param[in] pin: gpio pin number in this device
 * \return  the pin state value of this device
 */
sedi_gpio_pin_state_t sedi_gpio_read_pin(IN sedi_gpio_t gpio_device,
					 IN uint32_t pin);

/*!
 * \brief Toggle the pin state
 * \param[in] gpio_device: gpio device id
 * \param[in] pin: gpio pin number in this device
 * \return void
 */
void sedi_gpio_toggle_pin(IN sedi_gpio_t gpio_device, IN uint32_t pin);

/*!
 * \brief  Get device's interrupt status register value
 * \param[in] gpio_device: gpio device id
 * \param[in] port: Port id, one port represents 32 pins.
 * \return current device's interrupt status register value
 */
uint32_t sedi_gpio_get_gisr(IN sedi_gpio_t gpio_device,
			    IN sedi_gpio_port_t port);

/*!
 * \brief  Get device's wake up status register value
 * \param[in] gpio_device: gpio device id
 * \param[in] port: Port id, one port represents 32 pins.
 * \return current device's wake up status register value
 */
uint32_t sedi_gpio_get_gwsr(IN sedi_gpio_t gpio_device,
			    IN sedi_gpio_port_t port);

/*!
 * \brief  Clear the interrupt status manually
 * \param[in] gpio_device: gpio device id
 * \param[in] port: Port id, one port represents 32 pins.
 * \param[in] val: Clear mask value, any bit equals to 1 means clear the
 * relevant pin interrupt status.
 */
void sedi_gpio_clear_gisr(IN sedi_gpio_t gpio_device, IN sedi_gpio_port_t port,
			  IN uint32_t val);

/*!
 * \brief  Clear the wake up status manually.
 * \param[in] gpio_device: gpio device id
 * \param[in] port: Port id, one port represents 32 pins.
 * \param[in] val: Clear mask value, any bit equals to 1 means clear the
 * relevant pin wake up status.
 */
void sedi_gpio_clear_gwsr(IN sedi_gpio_t gpio_device, IN sedi_gpio_port_t port,
			  IN uint32_t val);

/*!
 * \brief  Enable/Disable GPIO pin interrupt
 * \param[in] gpio_device: gpio device id
 * \param[in] pin: gpio pin number in this device
 * \param[in] enable: True means enable, false means disable
 */
void sedi_gpio_enable_interrupt(IN sedi_gpio_t gpio_device, IN uint32_t pin,
				bool enable);

/*!
 * \brief  Enable/Disable GPIO pin wake up
 * \param[in] gpio_device: gpio device id
 * \param[in] pin: gpio pin number in this device
 * \param[in] enable: True means enable, false means disable
 */
void sedi_gpio_enable_wakeup(IN sedi_gpio_t gpio_device, IN uint32_t pin,
			     bool enable);

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_GPIO_H_*/
