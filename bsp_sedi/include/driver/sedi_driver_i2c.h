/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_I2C_H_
#define _SEDI_DRIVER_I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_i2c I2C
 * \ingroup sedi_driver
 */

#define SEDI_I2C_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/****** I2C Control Codes *****/

/*!
 * \defgroup i2c_control_codes  I2C Control Codes
 * \ingroup sedi_driver_i2c
 * \{
 */

/*!
 * \def SEDI_I2C_OWN_ADDRESS
 * \brief Set Own Slave Address; arg = address
 */
#define SEDI_I2C_OWN_ADDRESS (0x01)

/*!
 * \def SEDI_I2C_BUS_SPEED
 * \brief Set Bus Speed; arg = speed
 */
#define SEDI_I2C_BUS_SPEED (0x02)

/*!
 * \def SEDI_I2C_BUS_CLEAR
 * \brief Execute Bus clear: send nine clock pulses
 */
#define SEDI_I2C_BUS_CLEAR (0x03)

/*!
 * \def SEDI_I2C_ABORT_TRANSFER
 * \brief Abort Master/Slave Transmit/Receive
 */
#define SEDI_I2C_ABORT_TRANSFER (0x04)

/*!
 * \def SEDI_I2C_SET_TX_MEMORY_TYPE
 * \brief Control function parameter, set DMA memory type, only used to tell
 *        driver tx buffer located in DRAM.
 */
#define SEDI_I2C_SET_TX_MEMORY_TYPE (0x05)

/*!
 * \def SEDI_I2C_SET_RX_MEMORY_TYPE
 * \brief Control function parameter, set DMA memory type, only used to tell
 *        driver rx buffer located in DRAM.
 */
#define SEDI_I2C_SET_RX_MEMORY_TYPE (0x06)

/*!
 * \}
 */

/*----- I2C Bus Speed -----*/

/*!
 * \defgroup i2c_bus_speed  I2C Bus Speed
 * \ingroup sedi_driver_i2c
 * \{
 */

/*!
 * \def SEDI_I2C_BUS_SPEED_STANDARD
 * \brief Standard Speed (100kHz)
 */
#define SEDI_I2C_BUS_SPEED_STANDARD (0x01)

/*!
 * \def SEDI_I2C_BUS_SPEED_FAST
 * \brief Fast Speed (400kHz)
 */
#define SEDI_I2C_BUS_SPEED_FAST (0x02)

/*!
 * \def SEDI_I2C_BUS_SPEED_FAST_PLUS
 * \brief Fast+ Speed (1MHz)
 */
#define SEDI_I2C_BUS_SPEED_FAST_PLUS (0x03)

/*!
 * \def SEDI_I2C_BUS_SPEED_HIGH
 * \brief High Speed (3.4MHz)
 */
#define SEDI_I2C_BUS_SPEED_HIGH (0x04)

/*!
 * \}
 */

/****** I2C Address Flags *****/

/*!
 * \defgroup i2c_address_flags  I2C Address Flags
 * \ingroup sedi_driver_i2c
 * \{
 */

/*!
 * \def SEDI_I2C_ADDRESS_10BIT
 * \brief 10-bit address flag
 */
#define SEDI_I2C_ADDRESS_10BIT (0x0400)

/*!
 * \def SEDI_I2C_ADDRESS_GC
 * \brief General Call flag
 */
#define SEDI_I2C_ADDRESS_GC (0x8000)

/*!
 * \}
 */

/****** I2C Event *****/

/*!
 * \defgroup i2c_event I2C Event Types
 * \ingroup sedi_driver_i2c
 * \{
 */

#define SEDI_I2C_EVENT_TRANSFER_NONE (0)

/*!
 * \def SEDI_I2C_EVENT_TRANSFER_DONE
 * \brief Master/Slave Transmit/Receive finished
 */
#define SEDI_I2C_EVENT_TRANSFER_DONE (1UL << 0)

/*!
 * \def SEDI_I2C_EVENT_TRANSFER_INCOMPLETE
 * \brief Master/Slave Transmit/Receive incomplete transfer
 */
#define SEDI_I2C_EVENT_TRANSFER_INCOMPLETE (1UL << 1)

/*!
 * \def SEDI_I2C_EVENT_SLAVE_TRANSMIT
 * \brief Slave Transmit operation requested
 */
#define SEDI_I2C_EVENT_SLAVE_TRANSMIT (1UL << 2)

/*!
 * \def SEDI_I2C_EVENT_SLAVE_RECEIVE
 * \brief Slave Receive operation requested
 */
#define SEDI_I2C_EVENT_SLAVE_RECEIVE (1UL << 3)

/*!
 * \def SEDI_I2C_EVENT_ADDRESS_NACK
 * \brief Address not acknowledged from Slave
 */
#define SEDI_I2C_EVENT_ADDRESS_NACK (1UL << 4)

/*!
 * \def SEDI_I2C_EVENT_GENERAL_CALL
 * \brief General Call indication
 */
#define SEDI_I2C_EVENT_GENERAL_CALL (1UL << 5)

/*!
 * \def SEDI_I2C_EVENT_ARBITRATION_LOST
 * \brief Master lost arbitration
 */
#define SEDI_I2C_EVENT_ARBITRATION_LOST (1UL << 6)

/*!
 * \def SEDI_I2C_EVENT_BUS_ERROR
 * \brief Bus error detected (START/STOP at illegal position)
 */
#define SEDI_I2C_EVENT_BUS_ERROR (1UL << 7)

/*!
 * \def SEDI_I2C_EVENT_BUS_CLEAR
 * \brief Bus clear finished
 */
#define SEDI_I2C_EVENT_BUS_CLEAR (1UL << 8)

/*!
 * \def SEDI_I2C_EVENT_DMA_ERROR
 * \brief DMA error detected
 */
#define SEDI_I2C_EVENT_DMA_ERROR (1UL << 12)

/*!
 * \}
 */

/****** I2C Usage Limits *****/

/*!
 * \defgroup i2c_usage_limits  I2C Usage Limits
 * \ingroup sedi_driver_i2c
 * \{
 */

/*!
 * \def SEDI_I2C_DMA_LENGTH_LIMIT
 * \brief define the minimal data length if use dma transfer
 */
#define SEDI_I2C_DMA_LENGTH_LIMIT (2)

/*!
 * \}
 */

/*!
 * \struct sedi_i2c_status_t
 * \brief I2C Status
 * \ingroup sedi_driver_i2c
 */
typedef volatile struct {
	/**< Busy flag */
	uint32_t busy : 1;
	/**< Mode: 0=Slave, 1=Master */
	uint32_t mode : 1;
	/**< Direction: 0=Transmitter, 1=Receiver */
	uint32_t direction : 1;
	/**< General Call indication (cleared for next Slave operation) */
	uint32_t general_call : 1;
	/**< Master lost arbitration (cleared for next Master operation) */
	uint32_t arbitration_lost : 1;
	/**< Bus error detected (cleared for next operation) */
	uint32_t bus_error : 1;
	/* Event for I2C transfer */
	uint32_t event : 13;
	uint32_t reserved : 13;
} sedi_i2c_status_t;

/*!
 * \struct sedi_i2c_capabilities_t
 * \brief I2C Driver Capabilities.
 * \ingroup sedi_driver_i2c
 */
typedef struct {
	uint32_t address_10_bit : 1; /**< supports 10-bit addressing */
	uint32_t dma : 1;	    /**< supports DMA */
	uint32_t is_available : 1;   /** 1:available 0:used by host  **/
	uint32_t rx_buffer_depth : 9;
	uint32_t tx_buffer_depth : 9;
	uint32_t reserved : 11;      /**< Reserved (must be zero) */
} sedi_i2c_capabilities_t;

/*!
 * \struct sedi_i2c_bus_clk_t
 * \brief I2C bus clock frequency configuration.
 * \ingroup sedi_driver_i2c
 */
typedef struct{
	uint16_t		sda_hold;
	uint16_t		hcnt;
	uint16_t		lcnt;
} sedi_i2c_bus_clk_t;

/*!
 * \struct sedi_i2c_bus_info_t
 * \brief I2C bus clock frequency configuration for each mode.
 * \ingroup sedi_driver_i2c
 */
typedef struct {
	sedi_i2c_bus_clk_t	std_clk;
	sedi_i2c_bus_clk_t	fst_clk;
	sedi_i2c_bus_clk_t	fsp_clk;
	sedi_i2c_bus_clk_t	high_clk;
} sedi_i2c_bus_info_t;

/*!
 * \defgroup i2c_event_handler I2C Event Handler Callback
 * \ingroup sedi_driver_i2c
 * \{
 */

/*!
 * \typedef sedi_i2c_event_cb_t
 * \brief Callback function type for signal i2c event.
 * \param[in] event: event type. see \ref i2c_event
 * \return    void
 */
typedef void (*sedi_i2c_event_cb_t)(IN uint32_t event);

/*!
 * \}
 */

/*!
 * \defgroup i2c_function_calls I2C Driver Function Calls
 * \ingroup sedi_driver_i2c
 * \{
 */

/*!
 * \brief Get the i2c driver's API version.
 * \return the version of current i2c driver's API
 */
sedi_driver_version_t sedi_i2c_get_version(void);

/*!
 * \brief Get the device's capabilities.
 * \param[in] i2c_device: i2c device id
 * \param[out] cap: i2c device capabilities
 * \return  \ref return_status
 */
int sedi_i2c_get_capabilities(IN sedi_i2c_t i2c_device,
			      sedi_i2c_capabilities_t *cap);

/*!
 * \brief Initialize the device
 * \param[in] i2c_device: i2c device id
 * \param[in] cb: the callback function which can receive device's events.
 * \param[in] base: register base address of the i2c device.
 * \return  \ref return_status
 */
int32_t sedi_i2c_init(IN sedi_i2c_t i2c_device, IN sedi_i2c_event_cb_t cb,
		IN uint32_t base);

/*!
 * \brief Uninitialize the device
 * \param[in] i2c_device: i2c device id
 * \return  \ref return_status
 */
int32_t sedi_i2c_uninit(IN sedi_i2c_t i2c_device);

/*!
 * \brief Set the device's power
 * \param[in] i2c_device: i2c device id
 * \param[in] state: the power state to be set to the device
 * \return  \ref return_status
 */
int32_t sedi_i2c_set_power(IN sedi_i2c_t i2c_device,
			   IN sedi_power_state_t state);

/*!
 * \brief Start transmitting data to i2c slave device as master
 * \param[in] i2c_device: i2c device id
 * \param[in] addr: slave address (7-bit or 10-bit)
 * \param[in] *data: pointer of the buffer with data
 *                   which need write to the slave
 * \param[in] num: number of data bytes to transfer
 * \param[in] pending: i2c data transfer operation is pending
 *                     ('Stop' signal will not be sent)
 * \return  \ref return_status
 */
int32_t sedi_i2c_master_write_async(IN sedi_i2c_t i2c_device, IN uint32_t addr,
				    IN uint8_t *data, IN uint32_t num,
				    IN bool pending);

/*!
 * \brief Start receiving data from i2c slave device as master
 * \param[in] i2c_device: i2c device id
 * \param[in] addr: slave address (7-bit or 10-bit)
 * \param[in] *data: pointer of the buffer for data from the slave device
 * \param[out] num: number of data bytes to receive
 * \param[in] pending: i2c data transfer operation is pending
 *                     ('Stop' signal will not be sent)
 * \return  \ref return_status
 */
int32_t sedi_i2c_master_read_async(IN sedi_i2c_t i2c_device, IN uint32_t addr,
				   OUT uint8_t *data, IN uint32_t num,
				   IN bool pending);

/*!
 * \brief Start transmitting data to i2c slave device as master
 * \note DMA function do not support transfer length smaller than 3 bytes.
 * \param[in] i2c_device: i2c device id
 * \param[in] addr: slave address (7-bit or 10-bit)
 * \param[in] *data: pointer of the buffer with data
 *                   which need write to the slave
 * \param[in] num: number of data bytes to transfer
 * \param[in] pending: i2c data transfer operation is pending
 *                     ('Stop' signal will not be sent)
 * \param[in] dma_dev: dma device id
 * \param[in] dma_chan: dma channel id
 * \return  \ref return_status
 */
int32_t sedi_i2c_master_write_dma(IN sedi_i2c_t i2c_device, IN uint32_t addr,
	IN uint8_t *data, IN uint32_t num, IN bool pending,
	IN uint32_t dma_dev, IN uint32_t dma_chan);

/*!
 * \brief Start receiving data from i2c slave device as master
 * \note DMA function do not support transfer length smaller than 3 bytes.
 * \note As the DW I2C needs 2 channels to do RX DMA operation, need to add
 *			another parameter.
 * \param[in] i2c_device: i2c device id
 * \param[in] addr: slave address(7-bit or 10-bit)
 * \param[in] *data: pointer of the buffer for data from the slave device
 * \param[out] num: number of data bytes to receive
 * \param[in] pending: i2c data transfer operation is pending
 *                     ('Stop' signal will not be sent)
 * \param[in] rx_dma_dev: rx dma device id
 * \param[in] rx_dma_chan: rx dma channel id
 * \param[in] cmd_dma_dev: cmd dma device id
 * \param[in] cmd_dma_chan: cmd dma channel id
 * \return  \ref return_status
 */
int32_t sedi_i2c_master_read_dma(IN sedi_i2c_t i2c_device, IN uint32_t addr,
	OUT uint8_t *data, IN uint32_t num, IN bool pending,
	IN uint32_t rx_dma_dev, IN uint32_t rx_dma_chan,
	IN uint32_t cmd_dma_dev, IN uint32_t cmd_dma_chan);

/*!
 * \brief Send data to i2c slave device as master through polling mode.
 * \param[in] i2c_device: i2c device id
 * \param[in] addr: slave address (7-bit or 10-bit)
 * \param[in] *data: pointer of the buffer with data
 *                   which need write to the slave
 * \param[in] num: number of data bytes to transfer
 * \param[in] pending: i2c data transfer operation is pending
 *                     ('Stop' signal will not be sent)
 * \return  \ref return_status
 */
int32_t sedi_i2c_master_poll_write(IN sedi_i2c_t i2c_device, IN uint32_t addr,
				   IN uint8_t *data, IN uint32_t num,
				   IN bool pending);

/*!
 * \brief Receiving data from i2c slave device as master through polling mode
 * \param[in] i2c_device: i2c device id
 * \param[in] addr: slave address (7-bit or 10-bit)
 * \param[in] *data: pointer of the buffer for data from the slave device
 * \param[out] num: number of data bytes to receive
 * \param[in] pending: i2c data transfer operation is pending
 *                     ('Stop' signal will not be sent)
 * \return  \ref return_status
 */
int32_t sedi_i2c_master_poll_read(IN sedi_i2c_t i2c_device, IN uint32_t addr,
				  OUT uint8_t *data, IN uint32_t num,
				  IN bool pending);

/*!
 * \brief  Get transferred data count
 * \param[in] i2c_device: i2c device id
 * \return number of data bytes transferred;
 *         -1 when slave is not addressed by master
 */
int32_t sedi_i2c_get_data_count(IN sedi_i2c_t i2c_device);

/*!
 * \brief  Control the i2c device
 * \param[in] i2c_device: i2c device id
 * \param[in] control: control operation code. see \ref i2c_control_codes
 * \param[in] arg: argument of operation (optional)
 * \return  \ref return_status
 */
int32_t sedi_i2c_control(IN sedi_i2c_t i2c_device, IN uint32_t control,
			 IN uint32_t arg);

/*!
 * \brief  Get device's status
 * \param[in] i2c_device: i2c device id
 * \param[out] status: i2c device status
 * \return  \ref return_status
 */
int sedi_i2c_get_status(IN sedi_i2c_t i2c_device, sedi_i2c_status_t *status);

/*!
 * \brief Handle devices's interrupt
 * \param[in] i2c_device: i2c device id
 * \return  void
 */
void sedi_i2c_isr_handler(IN sedi_i2c_t i2c_device);

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_I2C_H_*/
