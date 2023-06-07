/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_SPI_H_
#define _SEDI_DRIVER_SPI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_spi SPI
 * \ingroup sedi_driver
 */

#define SEDI_SPI_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/*!
 * \defgroup spi_control_mode  SPI Control
 * \ingroup sedi_driver_spi
 * \{
 */

enum sedi_spi_ioctl {

	/*!
	 * Clock Polarity 0, Clock Phase 0
	 */
	SEDI_SPI_IOCTL_CPOL0_CPHA0,

	/*!
	 * Clock Polarity 0, Clock Phase 1
	 */
	SEDI_SPI_IOCTL_CPOL0_CPHA1,

	/*!
	 * Clock Polarity 1, Clock Phase 0
	 */
	SEDI_SPI_IOCTL_CPOL1_CPHA0,

	/*!
	 * Clock Polarity 1, Clock Phase 1
	 */
	SEDI_SPI_IOCTL_CPOL1_CPHA1,

	/*!
	 * Texas Instruments Frame Format
	 * No need to input args
	 */
	SEDI_SPI_IOCTL_TI_SSI,

	/*!
	 * National Microwire Frame Format
	 * Need to input microwire configure pointer
	 */
	SEDI_SPI_IOCTL_MICROWIRE,

	/*!
	 * Set the number of bits per SPI frame
	 * The parameter range is [1,16]
	 * For 4 bits operation, users need to provide an expand buffer, which
	 * covert 4-bits data to 8-bits data. The transfer size shall also use
	 * the expanded buffer size while do transfer.
	 */
	SEDI_SPI_IOCTL_DATA_WIDTH,

	/*!
	 * MSB first send out, default
	 */
	SEDI_SPI_IOCTL_MSB,

	/*!
	 * LSB first send out, it should be supported by hardware
	 */
	SEDI_SPI_IOCTL_LSB,

	/*!
	 * The SPI will not drive or monitor the CS pin, user drives it with
	 * GPIO API before and after transaction, or directly connect the
	 * SPI slave's CS pin to a fixed low level.
	 */
	SEDI_SPI_IOCTL_CS_UNUSED,

	/*!
	 * The SPI auto active the CS pin before transaction, and deactive it
	 * after complete or abort.
	 * The parameter is bitmask of CS pin been controlled by SPI
	 */
	SEDI_SPI_IOCTL_CS_HW,

	/*!
	 * Get SPI speed in Hz
	 */
	SEDI_SPI_IOCTL_SPEED_SET,

	/*!
	 * Set SPI speed in Hz
	 */
	SEDI_SPI_IOCTL_SPEED_GET,

	/*!
	 * Set the FIFO depth, set it large for bulk transfer, set it small
	 * for few data transfer (register access).
	 * For bulk transfer, the data length should be aligned with the FIFO
	 * depth.
	 */
	SEDI_SPI_IOCTL_TX_WATERMARK_SET,

	/*!
	 * Set the FIFO depth, set it large for bulk transfer, set it small
	 * for few data transfer (register access).
	 * For bulk transfer, the data length should be aligned with the FIFO
	 * depth.
	 */
	SEDI_SPI_IOCTL_RX_WATERMARK_SET,

	/*!
	 * Get the FIFO depth
	 */
	SEDI_SPI_IOCTL_TX_WATERMARK_GET,

	/*!
	 * Get the FIFO depth
	 */
	SEDI_SPI_IOCTL_RX_WATERMARK_GET,

	/*!
	 * Set the dummy data on the bus, for example, master wants to read
	 * from slave. It can be 0x00 or 0xFF, which means keep data line low
	 * level or high level.
	 */
	SEDI_SPI_IOCTL_DUMMY_DATA,

	/*!
	 * Abort the data transfer.
	 */
	SEDI_SPI_IOCTL_ABORT,

	/*!
	 * Loopback mode for test
	 */
	SEDI_SPI_IOCTL_LOOPBACK,

	/*!
	 * SPI transfer buffer sets, it means in a transfer, the buffer can be
	 * not physical continuous. Users need to update buffer while callback
	 * event is SEDI_SPI_EVENT_TX_FINISHED or SEDI_SPI_EVENT_RX_FINISHED.
	 * Users need to use function sedi_spi_update_tx_buf or
	 * sedi_spi_update_rx_buf to update buffers.
	 * Input 1 means enable this mode, 0 means disable this mode.
	 * Notice: This mode only supported in irq transfer mode.
	 */
	SEDI_SPI_IOCTL_BUFFER_SETS,

	/*!
	 * Set SPI line mode, it can be single/dual/quad/octal mode.
	 */
	SEDI_SPI_IOCTL_LINE_MODE,

	/*!
	 * Indicates the end of ioctl code
	 */
	SEDI_SPI_IOCTL_NUM
};

/*!
 * \}
 */

/*!
 * \defgroup spi_quad_mode_t  SPI line mode
 * \ingroup sedi_driver_spi
 * \{
 */

typedef enum {
	SPI_SINGLE_MODE,
	SPI_DUAL_MODE,
	SPI_QUAD_MODE,
	SPI_OCTAL_MODE
} spi_line_mode_t;

typedef enum {
	SPI_INST_ADDR_NORMAL, /*!< SPI instruction and addr use single line */
	SPI_INST_NORMAL_ADDR_ENHANCED, /*!< Instruction use single line,
					    address use dual/quad/octal mode */
	SPI_INST_ADDR_ENHANCED, /*!< Instruction and address use
				     dual/quad/octal mode */
} spi_inst_addr_mode_t;

/*! Instruction length in SPI enhanced mode*/
typedef enum {
	SPI_INST_LEN_0_BIT,
	SPI_INST_LEN_4_BIT,
	SPI_INST_LEN_8_BIT,
	SPI_INST_LEN_16_BIT
} spi_inst_len_t;

/*! Address length in SPI enhanced mode*/
typedef enum {
	SPI_ADDR_LEN_0_BIT,
	SPI_ADDR_LEN_4_BIT,
	SPI_ADDR_LEN_8_BIT,
	SPI_ADDR_LEN_12_BIT,
	SPI_ADDR_LEN_16_BIT,
	SPI_ADDR_LEN_20_BIT,
	SPI_ADDR_LEN_24_BIT,
	SPI_ADDR_LEN_28_BIT,
	SPI_ADDR_LEN_32_BIT,
	SPI_ADDR_LEN_36_BIT,
	SPI_ADDR_LEN_40_BIT,
	SPI_ADDR_LEN_44_BIT,
	SPI_ADDR_LEN_48_BIT,
	SPI_ADDR_LEN_52_BIT,
	SPI_ADDR_LEN_56_BIT,
	SPI_ADDR_LEN_60_BIT,
} spi_addr_len_t;

/*!
 * \}
 */

/*!
 * \defgroup spi_event SPI Event
 * \ingroup sedi_driver_spi
 * \{
 */

/*! transfer complete */
#define SEDI_SPI_EVENT_COMPLETE (1UL << 0)

/*! data lost happens, for example, tx underflow or rx overflow */
#define SEDI_SPI_EVENT_DATA_LOST (1UL << 1)

/*!
 * it will be detected by hardware, master detect the CS pin deactive while
 * it transfer data, see sedi_spi_capabilities to get if hw support it.
 */
#define SEDI_SPI_EVENT_MODE_FAULT (1UL << 2)

#define SEDI_SPI_EVENT_TX_FINISHED (1UL << 3)

#define SEDI_SPI_EVENT_RX_FINISHED (1UL << 4)

/*!
 * \}
 */

/*!
 * \struct sedi_spi_status_t
 * \brief SPI Status, be used if callback has not been registered
 * \ingroup sedi_driver_spi
 */
typedef volatile struct {
	uint32_t busy : 1;
	uint32_t data_lost : 1;
	uint32_t mode_fault : 1;
	uint32_t is_available : 1; /** 1:available 0:used by host  **/
	uint32_t isr : 6; /* ISR status in error, only bit 0-5 is valid */
	uint32_t reserved : 22;
	uint32_t txflr;
	uint32_t rxflr;
	uint32_t sr;
} sedi_spi_status_t;

/*!
 * \struct sedi_spi_capabilities_t
 * \brief SPI Capabilities, the hardware feature
 * \ingroup sedi_driver_spi
 */
typedef struct {
	uint32_t ti_ssi : 1;
	uint32_t microwire : 1;
	uint32_t mode_fault : 1;
	uint32_t is_available : 1; /** 1:available 0:used by host  **/
	uint32_t reserved : 28;
} sedi_spi_capabilities_t;

/*!
 * \struct sedi_spi_microwire_config_t
 * \brief Microwire configure
 * \ingroup sedi_driver_spi
 */
typedef struct {
	bool microwire_handshake; /*!< If enable microwire handshake  */
	bool data_direction_tx;   /*!< True means data to transmit, false means
				     data for receive */
	bool sequential_mode;     /*!< true means only need one control data for
				     data transfer, false means one data needs one
				     control data*/
} sedi_spi_microwire_config_t;

/*!
 * \struct sedi_spi_enhanced_config_t
 * \brief Transfer in enhanced mode (dual/quad/octal) configure
 * \ingroup sedi_driver_spi
 */
typedef struct {
	uint8_t *inst_buf;
	spi_inst_len_t inst_len;
	uint8_t *addr_buf;
	spi_addr_len_t addr_len;
	uint8_t *tx_buf;
	uint8_t *rx_buf;
	uint32_t data_len;
	uint32_t dummy_cycles;
	spi_inst_addr_mode_t mode;
} sedi_spi_enhanced_config_t;

/*!
 * \defgroup spi_event_handler SPI Event Handler Callback
 * \ingroup sedi_driver_spi
 * \{
 */

/*!
 * \typedef sedi_spi_event_cb_t
 * \brief Callback function type for signal spi event.
 * \param[in] event: event type. see \ref spi_event
 * \param[inout] param: user parameter
 * \return    void
 */
typedef void (*sedi_spi_event_cb_t)(IN uint32_t event, INOUT void *param);

/*!
 * \}
 */

/*!
 * \defgroup spi_function_calls SPI Driver Function Calls
 * \ingroup sedi_driver_spi
 * \{
 */

/*!
 * \brief Get the spi driver's API version.
 * \return the version of current spi driver's API
 */
sedi_driver_version_t sedi_spi_get_version(void);

/*!
 * \brief Get the device's capabilities.
 * \param[in] spi_device: spi device id
 * \param[out] cap: spi device capabilities
 * \return  \ref return_status
 */
int32_t sedi_spi_get_capabilities(IN sedi_spi_t spi_device,
				  OUT sedi_spi_capabilities_t *cap);

/*!
 * \brief Initialize the device
 * \param[in] spi_device: spi device id
 * \param[in] cb: the callback function which can receive device's events.
 * \param[in] param: the callback function's parameter.
 * \param[in] base: base address of the SPI instance.
 * \return  \ref return_status
 */
int32_t sedi_spi_init(IN sedi_spi_t spi_device, IN sedi_spi_event_cb_t cb,
		      INOUT void *param, IN uint32_t base);

/*!
 * \brief Uninitialize the device
 * \param[in] spi_device: spi device id
 * \return  \ref return_status
 */
int32_t sedi_spi_uninit(IN sedi_spi_t spi_device);

/*!
 * \brief Set the device's power
 * \param[in] spi_device: spi device id
 * \param[in] state: the power state to be set to the device
 * \return  \ref return_status
 */
int32_t sedi_spi_set_power(IN sedi_spi_t spi_device,
			   IN sedi_power_state_t state);

/*!
 * \brief  Get transferred data count
 * \param[in] spi_device: spi device id
 * \return number of data bytes transferred;
 */
int32_t sedi_spi_get_data_count(IN sedi_spi_t spi_device);

/*!
 * \brief  Control the spi device
 * \note Shall not use it in dma mode, as DMA HW cannot support get transferred
 * bytes. \param[in] spi_device: spi device id \param[in] control: control
 * operation code. see \ref spi_control_codes \param[in] arg: argument of
 * operation (optional) \return  \ref return_status
 */
int32_t sedi_spi_control(IN sedi_spi_t spi_device, IN uint32_t control,
			 IN uint32_t arg);

/*!
 * \brief  Get device's status
 * \param[in] spi_device: spi device id
 * \param[out] status: spi device status
 * \return  \ref return_status
 */
int32_t sedi_spi_get_status(IN sedi_spi_t spi_device,
			    OUT sedi_spi_status_t *status);

/*!
 * \brief Update tx buffer during a spi irq transfer
 * This function used to tell spi driver a new tx buffer during a irq transfer.
 * Typically used in callback function with event SEDI_SPI_EVENT_TX_FINISHED.
 * Notice, if not call this function in callback, will cause data not send
 * correct data.
 * \param[in] spi_device: spi device id
 * \param[in] *tx_buffer: pointer of the buffer with data
 *                   which need send to slave
 * \param[in] len: number of data bytes to transfer
 * \return  \ref return_status
 */
int32_t sedi_spi_update_tx_buf(IN sedi_spi_t spi_device, IN uint8_t *tx_buf,
			       IN uint32_t len);

/*!
 * \brief Update rx buffer during a spi irq transfer
 * This function used to tell spi driver a new rx buffer during a irq transfer.
 * Typically used in callback function with event SEDI_SPI_EVENT_RX_FINISHED.
 * Notice, if not call this function in callback, will cause data not receive
 * to correct location.
 * \param[in] spi_device: spi device id
 * \param[out] *rx_buffer: pointer of the buffer with data
 *                   which need read from the slave
 * \param[in] len: number of data bytes to transfer
 * \return  \ref return_status
 */
int32_t sedi_spi_update_rx_buf(IN sedi_spi_t spi_device, OUT uint8_t *rx_buf,
			       IN uint32_t len);

/*!
 * \brief Start transmitting data to spi slave device as master
 * \param[in] spi_device: spi device id
 * \param[in] *data_out: pointer of the buffer with data
 *                   which need write to the slave
 * \param[out] *data_in: pointer of the buffer with data
 *                   which need read from the slave
 * \param[in] num: number of data bytes to transfer
 * \return  \ref return_status
 */
int32_t sedi_spi_transfer(IN sedi_spi_t spi_device, IN uint8_t *data_out,
			  OUT uint8_t *data_in, IN uint32_t num);

/*!
 * \brief Start transmitting data to spi slave device as master in polling mode
 * \param[in] spi_device: spi device id
 * \param[in] *data_out: pointer of the buffer with data
 *                   which need write to the slave
 * \param[out] *data_in: pointer of the buffer with data
 *                   which need read from the slave
 * \param[in] num: number of data bytes to transfer
 * \return  \ref return_status
 */
int32_t sedi_spi_poll_transfer(IN sedi_spi_t spi_device, IN uint8_t *data_out,
			       OUT uint8_t *data_in, IN uint32_t num);

/*!
 * \brief Start transmitting data to spi slave device as master in dma mode
 * \param[in] spi_device: spi device id
 * \param[in] tx_dma: dma device id
 * \param[in] tx_dma_chan: dma channel id
 * \param[in] *data_out: pointer of the buffer with data
 *                   which need write to the slave
 * \param[in] rx_dma: dma device id
 * \param[in] rx_dma_chan: dma channel id
 * \param[out] *data_in: pointer of the buffer with data
 *                   which need read from the slave
 * \param[in] num: number of data bytes to transfer
 * \return  \ref return_status
 */
int32_t sedi_spi_dma_transfer(IN sedi_spi_t spi_device, IN uint32_t tx_dma,
			      IN uint32_t tx_dma_chan, IN uint8_t *data_out,
			      IN uint32_t rx_dma, IN uint32_t rx_dma_chan,
			      OUT uint8_t *data_in, IN uint32_t num);

/*!
 * \brief Start transmitting data to spi slave device as master enhanced mode
 * including dual/quad/octal mode
 * \param[in] spi_device: spi device id
 * \param[in] *config: Enhanced SPI mode transfer configure
 * \return  \ref return_status
 */
int32_t sedi_spi_enhanced_transfer(IN sedi_spi_t spi_device,
				   IN sedi_spi_enhanced_config_t *config);

/*!
 * \brief Start transmitting data to spi slave device as master in dma mode
 * using SPI enhanced mode including dual/quad/octal mode
 * \param[in] spi_device: spi device id
 * \param[in] tx_dma: dma device id
 * \param[in] tx_dma_chan: dma channel id
 * \param[in] rx_dma: dma device id
 * \param[in] rx_dma_chan: dma channel id
 * \param[in] *config: Enhanced SPI mode transfer configure
 * \return  \ref return_status
 */
int32_t sedi_spi_dma_enhanced_transfer(IN sedi_spi_t spi_device, IN uint32_t tx_dma,
			      IN uint32_t tx_dma_chan, IN uint32_t rx_dma,
			      IN uint32_t rx_dma_chan,
			      IN sedi_spi_enhanced_config_t *config);

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_SPI_H_ */
