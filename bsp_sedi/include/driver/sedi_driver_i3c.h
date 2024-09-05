/*
 * Copyright (c) 2021-2024 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _SEDI_DRIVER_I3C_H_
#define _SEDI_DRIVER_I3C_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_i3c I3C
 * \ingroup sedi_driver
 */

#define SEDI_I3C_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(1, 0)

/****** I3C Event *****/

/*!
 * \defgroup i3c_event_types I3C Event Types
 * \ingroup sedi_driver_i3c
 * \{
 */

/*!
 * \def SEDI_I3C_EVENT_SUCCESS
 * \brief Master/Slave Transmit/Receive finished
 */
#define SEDI_I3C_EVENT_SUCCESS          0x0
#define SEDI_I3C_EVENT_CRC              0x1
#define SEDI_I3C_EVENT_PARITY           0x2
#define SEDI_I3C_EVENT_FRAME            0x3
#define SEDI_I3C_EVENT_ADDRESS_HEADER   0x4
#define SEDI_I3C_EVENT_NACK             0x5
#define SEDI_I3C_EVENT_OVL              0x6
#define SEDI_I3C_EVENT_RESERVED_0       0x7
#define SEDI_I3C_EVENT_ABORTED          0x8
#define SEDI_I3C_EVENT_I2C_WRITE_NACK   0x9
#define SEDI_I3C_EVENT_NOT_SUPPORTED    0xA
/*!
 * \def SEDI_I3C_SLAVE_EVENT_SLAVE_TRANSMIT
 * \brief Slave Transmit operation requested
 */
#define SEDI_I3C_EVENT_SLAVE_TRANSMIT (0xB)

/*!
 * \def SEDI_I3C_SLAVE_EVENT_SLAVE_RECEIVE
 * \brief Slave Receive operation requested
 */
#define SEDI_I3C_EVENT_SLAVE_RECEIVE (0xC)
/*!
 * \def SEDI_I3C_SLAVE_EVENT_SLAVE_READ_REQ
 * \brief Slave received read request
 */
#define SEDI_I3C_EVENT_SLAVE_READ_REQ (0xD)

/*!
 * \def SEDI_I3C_SLAVE_EVENT_SLAVE_WRITE_REQ
 * \brief Slave received write request
 */
#define SEDI_I3C_EVENT_SLAVE_WRITE_REQ (0xE)

/*!
 * \def SEDI_I3C_SLAVE_EVENT_SLAVE_STOP_DET
 * \brief Slave detected stop signal
 */
#define SEDI_I3C_EVENT_SLAVE_STOP_DET (0xF)

/*!
 * \def SEDI_I3C_EVENT_SLAVE_CCC_UPDATE
 * \brief Slave detected CCC command from master
 */
#define SEDI_I3C_EVENT_SLAVE_CCC_UPDATE (0x11)

/*!
 * \def SEDI_I3C_EVENT_SLAVE_IBI_UPDATE
 * \brief Slave detected IBI acked
 */
#define SEDI_I3C_EVENT_SLAVE_IBI_UPDATE (0x11)

#define SEDI_I3C_EVENT_INTERNAL_ERR     0x10
#define SEDI_I3C_EVENT_UNKNOWN_ERROR    0x20

#define SEDI_I3C_SUCCESS(event)         ((event) == SEDI_I3C_EVENT_SUCCESS)

/*!
 * \}
 */

#define SEDI_I3C_DEVICE_NUM_MAX         8

/****** I3C CCC *****/

/*!
 * \defgroup i3c_common_command_codes I3C Common Command Codes
 * \ingroup sedi_driver_i3c
 * \{
 */

#undef I3C_CCC_BROAD_RSTDAA
#undef I3C_CCC_ENTDAA
#undef I3C_CCC_ENEC
#undef I3C_CCC_DISEC
#undef I3C_CCC_DIRECT_RSTDAA
#undef I3C_CCC_SETDASA
#undef I3C_CCC_SETNEWDA
#undef I3C_CCC_SETMRL
#undef I3C_CCC_GETMRL
#undef I3C_CCC_GETBCR
#undef I3C_CCC_GETDCR
#undef I3C_CCC_GETSTATUS
#undef I3C_CCC_GETMXDS

/*!
 * \def I3C_CCC_BROAD_RSTDAA
 * \brief Broadcast Reset Dynamic Address Assignment
 */
#define I3C_CCC_BROAD_RSTDAA                 0x6

/*!
 * \def I3C_CCC_ENTDAA
 * \brief Enter Dynamic Address Assignment
 */
#define I3C_CCC_ENTDAA                       0x7

/*!
 * \def I3C_CCC_ENEC
 * \brief Enable Events Command
 */
#define I3C_CCC_ENEC                         0x80

/*!
 * \def I3C_CCC_DISEC
 * \brief Disable Events Command
 */
#define I3C_CCC_DISEC                        0x81

/*!
 * \def I3C_CCC_DIRECT_RSTDAA
 * \brief Direct Reset Dynamic Address Assignment
 */
#define I3C_CCC_DIRECT_RSTDAA                0x86

/*!
 * \def I3C_CCC_SETDASA
 * \brief Set Dynamic Address from Static Address
 */
#define I3C_CCC_SETDASA                      0x87

/*!
 * \def I3C_CCC_SETNEWDA
 * \brief Set New Dynamic Address
 */
#define I3C_CCC_SETNEWDA                     0x88

/*!
 * \def I3C_CCC_SETMRL
 * \brief Set Max Read Length
 */
#define I3C_CCC_SETMRL                       0x8A

/*!
 * \def I3C_CCC_GETMRL
 * \brief Get Max Read Length
 */
#define I3C_CCC_GETMRL                       0x8C

/*!
 * \def I3C_CCC_GETBCR
 * \brief Get Bus Characteristics Register
 */
#define I3C_CCC_GETBCR                       0x8E

/*!
 * \def I3C_CCC_GETDCR
 * \brief Get Device Characteristics Register
 */
#define I3C_CCC_GETDCR                       0x8F

/*!
 * \def I3C_CCC_GETSTATUS
 * \brief Get Device Status
 */
#define I3C_CCC_GETSTATUS                    0x90

/*!
 * \def I3C_CCC_GETMXDS
 * \brief Get Max Data Speed
 */
#define I3C_CCC_GETMXDS                      0x94

/*!
 * \}
 */

/****** I3C Device Config *****/

/*!
 * \defgroup i3c device specific config and settings
 * \ingroup sedi_driver_i3c
 * \{
 */

/*!
 * \def SIR_REJECT
 * \brief Slave Interrupt Request Reject
 */
#define SEDI_SIR_REJECT                           0x1
/*!
 * \def SIR_ACCEPT
 * \brief Slave Interrupt Request Accept
 */
#define SEDI_SIR_ACCEPT                           0x0
/*!
 * \def MR_REJECT
 * \brief Master Request Reject
 */
#define SEDI_MR_REJECT                            0x1
/*!
 * \def MR_ACCEPT
 * \brief Master Request Accept
 */
#define SEDI_MR_ACCEPT                            0x0
/*!
 * \def IBI_TIME_STAMPING_ON
 * \brief IBI is Timestamped
 */
#define IBI_TIME_STAMPING_ON                 0x1
/*!
 * \def IBI_TIME_STAMPING_OFF
 * \brief IBI is not Timestamped
 */
#define IBI_TIME_STAMPING_OFF                0x0
/*!
 * \def IBI_WITH_PAYLOAD
 * \brief IBI with Mandatory Bytes
 */
#define IBI_WITH_PAYLOAD                     0x1
/*!
 * \def IBI_WITH_NO_PAYLOAD
 * \brief IBI without Mandatory Bytes
 */
#define IBI_WITH_NO_PAYLOAD                  0x0

#define BCR_IBI_PAYLOAD                      (0x1 << 2)
#define BCR_MDS_LIMIT                        (0x1 << 0)

/*!
 * \}
 */

/****** I3C Transfer Flags *****/

/*!
 * \defgroup i3c_transfer_flags I3C Transfer Flags
 * \ingroup sedi_driver_i3c
 * \{
 */

/*!
 * \def I3C_CMD_TRANSFER
 * \brief I3C SDR Transfer
 */
#define I3C_CMD_TRANSFER                    0x0

/*!
 * \def I3C_CMD_CCC_HDR
 * \brief I3C CCC or HDR Transfer
 */
#define I3C_CMD_CCC_HDR                     0x1

/*!
 * \def SEDI_I3C_HDR_CMD_WRITE
 * \brief I3C HDR Write Command Code Value
 */
/* TODO: double check, 0x70 in lpss */
#define SEDI_I3C_HDR_CMD_WRITE               0x7f

/*!
 * \def SEDI_I3C_HDR_CMD_READ
 * \brief I3C HDR Read Command Code Value
 */
#define SEDI_I3C_HDR_CMD_READ                0x8f

/*!
 * \}
 */

/* TODO: bus speed mode */
typedef enum _sedi_i3c_speed {
	SEDI_I3C_SPEED_INVALID,
	SEDI_I3C_SPEED_100KHZ,
	SEDI_I3C_SPEED_400KHZ,
	SEDI_I3C_SPEED_1MHZ,
	SEDI_I3C_SPEED_2MHZ,
	SEDI_I3C_SPEED_4MHZ,
	SEDI_I3C_SPEED_6MHZ,
	SEDI_I3C_SPEED_8MHZ,
	SEDI_I3C_SPEED_10MHZ,
	SEDI_I3C_SPEED_MAX,
} sedi_i3c_speed_t;

typedef enum {
	SEDI_TIMING_INVALID = 0,
	SEDI_TIMING_OD,
	SEDI_TIMING_PP,
	SEDI_TIMING_FM,
	SEDI_TIMING_FMP,
	SEDI_TIMING_SS,
	SEDI_TIMING_MAX,
} sedi_i3c_timing_type_t;

typedef enum {
	SEDI_I2C_XFER_FM = 0,
	SEDI_I2C_XFER_FMP = 1,
	SEDI_I3C_XFER_SDR0 = 2,
	SEDI_I3C_XFER_SDR1 = 3,
	SEDI_I3C_XFER_SDR2 = 4,
	SEDI_I3C_XFER_SDR3 = 5,
	SEDI_I3C_XFER_SDR4 = 6,
	SEDI_I3C_XFER_HDR_TS = 7,
	SEDI_I3C_XFER_HDR_DDR = 8,
	SEDI_I3C_XFER_MAX,
} sedi_i3c_xfer_mode_t;

typedef enum {
	SEDI_I3C_WRITE = 0,
	SEDI_I3C_READ = 1,
	SEDI_I3C_DIRECTION_INVALID = 2,
	SEDI_I3C_DIRECTION_MAX = 2,
} sedi_i3c_direction_t;

typedef enum {
	SEDI_I3C_POS_INVALID = 0,
	SEDI_I3C_POS_SINGLE,
	SEDI_I3C_POS_FIRST,
	SEDI_I3C_POS_CONTINUE,
	SEDI_I3C_POS_LAST,
	SEDI_I3C_POS_MAX
} sedi_i3c_position_t;

typedef enum {
	SEDI_I3C_LOG_ERR = 3,
	SEDI_I3C_LOG_WARNING = 4,
	SEDI_I3C_LOG_NOTICE = 5,
	SEDI_I3C_LOG_INFO = 6,
	SEDI_I3C_LOG_DEBUG = 7,
} sedi_i3c_log_priority_t;


typedef struct{
	uint16_t        hcnt;
	uint16_t        lcnt;
} sedi_i3c_bus_data_t;

/* TODO: check if we need standard mode 100K */
struct sedi_i3c_bus_info {
	uint8_t  bus_id;
	sedi_i3c_bus_data_t i3c_od_scl;
	sedi_i3c_bus_data_t i3c_pp_scl;
	sedi_i3c_bus_data_t i2c_fm_scl;
	sedi_i3c_bus_data_t i2c_fmp_scl;
};

typedef struct sedi_i3c_bus_info sedi_i3c_bus_info_t;


#define SEDI_I3C_MAX_IBI_PAYLOAD_LEN             (4*7)

/*!
 * \struct sedi_ibi_t
 * \brief I3C IBI
 * \ingroup sedi_driver_i3c
 */
typedef struct _sedi_ibi_t {
	/**< ibi address */
	uint8_t     ibi_address;
	/**< length of ibi */
	uint8_t      ibi_len;
	/**< payload of ibi */
	uint8_t     ibi_payload[SEDI_I3C_MAX_IBI_PAYLOAD_LEN];
} sedi_ibi_t;

/*!
 * \struct sedi_i3c_timing_t
 * \brief i3c timing struct.
 * \ingroup sedi_driver_i3c
 */
typedef struct _sedi_i3c_timing_t {
	union {
		struct {
			/* in ns */
			uint16_t l_time;
			uint16_t h_time;
		};
		uint32_t as_uint32;
	};
} sedi_i3c_timing_t, *p_sedi_i3c_timing_t;

/*!
 * \struct i3c_dat_entry_t
 * \brief i3c device address table entry.
 * \ingroup sedi_driver_i3c
 */
typedef struct _i3c_dat_entry_t {
	union {
		struct {
			/**< device static address */
			uint32_t static_address : 7;
			uint32_t reserved0 : 5;
			/**< ibi payload: 0=no, 1=one or more bytes  */
			uint32_t ibi_payload : 1;
			/**< slave interrupt reject bit: 0=accept, 1=reject */
			uint32_t sir_reject : 1;
			/**< master request reject bit: 0=accept, 1=reject */
			uint32_t mr_reject : 1;
			/**< ibi timestamping bit */
			uint32_t en_ibi_timestamp : 1;
			/**< device dynamic address */
			uint32_t dynamic_address : 8;
			uint32_t reserved1 : 2;
			/**< ring group id */
			uint32_t ring_id : 3;
			/**< device NACK retry count */
			uint32_t dev_nack_retry_count : 2;
			/**< device type: 0=i3c, 1=i2c */
			uint32_t device_type : 1;
		};
		uint32_t as_uint32;
	} low;

	union {
		struct {
			/**< mask of ibi mandatory byte */
			uint32_t auto_cmd_mask : 8;
			/**< value of ibi mandatory byte */
			uint32_t auto_cmd_value : 8;
			/**< mode of automatic read transaction */
			uint32_t auto_cmd_mode : 3;
			/**< device auto_cmd hdr command code */
			uint32_t auto_cmd_hdr_code : 8;
			uint32_t reserved0 : 5;
		};
		uint32_t as_uint32;
	} high;
} i3c_dat_entry_t, *p_i3c_dat_entry_t;

/*!
 * \struct i3c_slave_config_t
 * \brief i3c slave configure structure.
 * \ingroup sedi_driver_i3c
 */
typedef struct sedi_i3c_slave_config {
	bool is_static_addr; /*!< Dynamic address or static address */
	bool support_ibi; /*!< If support IBI command */
	uint8_t addr; /*!< If static address, addr */
} sedi_i3c_slave_config_t;

/*!
 * \defgroup i3c_event_handler I3C Event Handler Callback
 * \ingroup sedi_driver_i3c
 * \{
 */

/*!
 * \typedef sedi_i3c_event_cb_t
 * \brief Callback function type for signal i3c event.
 * \param[in] event: event type. see \ref i3c_event
 * \return    void
 */
typedef void (*sedi_i3c_event_cb_t)(IN uint32_t event, void *prv_data);

/*!
 * \typedef sedi_i3c_ibi_cb_t
 * \brief Callback function type for ibi event.
 * \param[in] ibi: ibi struct. see \ref i3c_event
 * \return    void
 */
typedef void (*sedi_i3c_ibi_cb_t)(IN sedi_ibi_t *ibi, void *prv_data);

/*!
 * \typedef sedi_i3c_udelay_cb_t
 * \brief Callback function type for delay.
 * \param[in] usec: delay time. see \ref i3c_event
 * \return    void
 */
typedef void (*sedi_i3c_udelay_cb_t)(IN uint32_t usec);

/*!
 * \typedef sedi_i3c_log_cb_t
 * \brief Callback function type for log.
 * \param[in] priority: log priority
 * \param[in] message: log message
 * \param[in] vargs: variable list
 * \return    void
 */
typedef void (*sedi_i3c_log_cb_t)(sedi_i3c_log_priority_t priority, const char *message, va_list vargs);

/*!
 * \typedef sedi_i3c_slave_transmit_cb_t
 * \brief Callback function type for i3c slave read/write.
 * \param[in] event: event type. see \ref i3c_event
 * \param[in] len: Read/write length in bytes.
 * \return    void
 */
typedef void (*sedi_i3c_slave_transmit_cb_t)(IN uint32_t event, IN uint32_t len);

/*!
 * \}
 */

/*!
 * \defgroup i3c_function_calls I3C Driver Function Calls
 * \ingroup sedi_driver_i3c
 * \{
 */

/*!
 * \brief Get the i3c driver's API version.
 * \return the version of current i3c driver's API
 */
sedi_driver_version_t sedi_i3c_get_version(void);

/*!
 * \brief Initialize i3c sedi context.
 * \param[in] bus: i3c bus num
 * \param[in] base: base address
 * \param[in] log_cb: log callback function
 * \param[in] udelay_cb: delay callback function
 * \param[in] event_cb: event callback function
 * \param[in] ibi_cb: ibi callback function
 * \param[in] prv_data: data pointer
 * \return  \ref return_status
 */
int sedi_i3c_context_init(IN sedi_i3c_t bus,
				IN uint32_t *base,
				IN sedi_i3c_log_cb_t log_cb,
				IN sedi_i3c_udelay_cb_t udelay_cb,
				IN sedi_i3c_event_cb_t event_cb,
				IN sedi_i3c_ibi_cb_t ibi_cb,
				IN void *prv_data);

/*!
 * \brief Uninitialize i3c sedi context.
 * \param[in] bus: i3c bus num
 * \return  \ref return_status
 */
int sedi_i3c_context_uninit(IN sedi_i3c_t bus);

/*!
 * \brief Initialize sedi i3c controller.
 * \param[in] bus: i3c bus num
 * \return  \ref return_status
 */
int sedi_i3c_controller_init(IN sedi_i3c_t bus);

/*!
 * \brief Uninitialize sedi i3c controller.
 * \param[in] bus: i3c bus num
 * \return  \ref return_status
 */
int sedi_i3c_controller_uninit(IN sedi_i3c_t bus);

/*!
 * \brief Enable or disable i3c device.
 * \param[in] bus: i3c bus num
 * \param[in] en: enable or disable flag
 * \return  \ref return_status
 */
int sedi_i3c_hci_enable(IN sedi_i3c_t bus, IN bool en);

/*!
 * \brief Recover i3c controller.
 * \param[in] bus: i3c bus num
 * \return  \ref return_status
 */
int sedi_i3c_controller_recover(IN sedi_i3c_t bus);

/*!
 * \brief Configure i3c timing.
 * \param[in] bus: i3c bus num
 * \param[in] type: timing type
 * \param[in] speed: i3c speed
 * \param[in] timing: timing para
 * \return  \ref return_status
 */
int sedi_i3c_timing_config(IN sedi_i3c_t bus,
				IN sedi_i3c_timing_type_t type,
				IN sedi_i3c_speed_t speed,
				IN p_sedi_i3c_timing_t timing);

/*!
 * \brief Assemble i3c dat entry.
 * \param[in] static_addr: static address
 * \param[in] dyn_addr: dynamic address
 * \return  value of dat entry
 */
uint32_t sedi_i3c_dat_entry_assembler(
				IN uint8_t static_addr,
				IN uint8_t dyn_addr);

/*!
 * \brief Get dat entry.
 * \param[in] bus: i3c bus num
 * \param[in] index: dat index
 * \param[out] low: low 32 bits
 * \param[out] high: high 32 bits
 * \return  void
 */
void sedi_i3c_get_dat_entry(IN sedi_i3c_t bus, IN int index,
				OUT uint32_t *low, OUT uint32_t *high);

/*!
 * \brief Set dat entry.
 * \param[in] bus: i3c bus num
 * \param[in] index: dat index
 * \param[in] low: low 32 bits value
 * \param[in] high: high 32 bit value
 * \return  void
 */
void sedi_i3c_set_dat_entry(IN sedi_i3c_t bus, IN int index,
				IN uint32_t low, IN uint32_t high);

/*!
 * \brief Get dct entry. Set_dct is not needed as read only
 * \param[in] bus: i3c bus num
 * \param[in] index: dct index
 * \param[out] loc1: first 32 bits of dct
 * \param[out] loc2: second 32 bits of dct
 * \param[out] loc3: third 32 bits of dct
 * \param[out] loc4: last 32 bits of dct
 * \return  void
 */
void sedi_i3c_get_dct_entry(IN sedi_i3c_t bus, IN int index,
				OUT uint32_t *loc1, OUT uint32_t *loc2,
				OUT uint32_t *loc3, OUT uint32_t *loc4);

/*!
 * \brief i3c power gate.
 * \param[in] bus: i3c bus num
 * \return  void
 */
void sedi_i3c_on_power_gate(IN sedi_i3c_t bus);

/*!
 * \brief i3c power ungate.
 * \param[in] bus: i3c bus num
 * \return  void
 */
void sedi_i3c_on_power_ungate(IN sedi_i3c_t bus);

/*!
 * \brief i3c interrupt service routine.
 * \param[in] bus: i3c bus num
 * \return  void
 */
void sedi_i3c_isr(IN sedi_i3c_t bus);

/*!
 * \brief i3c address assign async function.
 * \param[in] bus: i3c bus num
 * \param[in] index: dat table index
 * \param[in] count: number of device
 * \param[in] is_daa: entdaa or setdasa
 * \return  \ref return_status
 */
int sedi_i3c_address_assign(IN sedi_i3c_t bus, IN int index,
				IN uint8_t count, IN bool is_daa);

/*!
 * \brief i3c immediate write async function.
 * \param[in] bus: i3c bus num
 * \param[in] dev_index: device index
 * \param[in] cmd_code: command code value
 * \param[in] mode: transfer or ccc_hdr
 * \param[in] buf: data pointer
 * \param[in] length: length of write
 * \param[in] position: request position
 * \return  \ref return_status
 */
int sedi_i3c_immediate_write(IN sedi_i3c_t bus,
				IN uint8_t dev_index,
				IN uint8_t cmd_code,
				IN sedi_i3c_xfer_mode_t mode,
				IN uint8_t *buf,
				IN int8_t length,
				IN sedi_i3c_position_t position);

/*!
 * \brief i3c regular transfer async function.
 * \param[in] bus: i3c bus num
 * \param[in] dev_index: device index
 * \param[in] cmd_code: command code value
 * \param[in] mode: transfer or ccc_hdr
 * \param[inout] buf: data pointer
 * \param[in] length: length of write or read
 * \param[in] direction: write or read
 * \param[in] position: request position
 * \return  \ref return_status
 */
int sedi_i3c_regular_xfer(IN sedi_i3c_t bus,
				IN uint8_t dev_index,
				IN uint8_t cmd_code,
				IN sedi_i3c_xfer_mode_t mode,
				INOUT uint8_t *buf,
				IN uint32_t length,
				IN sedi_i3c_direction_t direction,
				IN sedi_i3c_position_t position);

/*!
 * \brief i3c combo transfer async function.
 * \param[in] bus: i3c bus num
 * \param[in] dev_index: device index
 * \param[in] cmd_code: command code value
 * \param[in] mode: transfer or ccc_hdr
 * \param[inout] buf: data pointer
 * \param[in] length: length of write or read
 * \param[in] direction: write or read
 * \param[in] position: request position
 * \return  \ref return_status
 */
int sedi_i3c_combo_xfer(IN sedi_i3c_t bus,
				IN uint8_t dev_index,
				IN uint8_t cmd_code,
				IN sedi_i3c_xfer_mode_t mode,
				INOUT uint8_t *buf,
				IN uint32_t length,
				IN sedi_i3c_direction_t direction,
				IN sedi_i3c_position_t position);

/*!
 * \brief i3c enable ibi.
 * \param[in] bus: i3c bus num
 * \param[in] en: enable or disable
 * \return  void
 */
void sedi_i3c_ibi_enable(IN sedi_i3c_t bus, IN bool en);

/*!
 * \brief i3c enable i2c transfer.
 * \param[in] bus: i3c bus num
 * \param[in] en: enable or disable
 * \return  void
 */
void sedi_i3c_enable_i2c_xfer(IN sedi_i3c_t bus, IN bool en);

/*!
 * \brief i3c dump register.
 * \param[in] bus: i3c bus num
 * \return  void
 */
void sedi_i3c_register_dump(sedi_i3c_t bus);

/*!
 * \brief i3c set timing config.
 * \param[in] bus: i3c bus num
 * \param[in] info: i3c bus info
 * \return  void
 */
void sedi_i3c_set_timing_config(sedi_i3c_t bus, sedi_i3c_bus_info_t *info);

/*!
 * \brief i3c set i2c speed.
 * \param[in] bus: i3c bus num
 * \param[in] speed: i2c speed
 * \return  \ref return_status
 */
int sedi_i2c_set_speed(sedi_i3c_t bus, sedi_i3c_speed_t speed);

/*!
 * \brief i3c set i3c speed.
 * \param[in] bus: i3c bus num
 * \param[in] speed: i3c speed
 * \return  \ref return_status
 */
int sedi_i3c_set_speed(sedi_i3c_t bus, sedi_i3c_speed_t speed);

/*!
 * \brief i3c set power state.
 * \param[in] bus: i3c bus num
 * \param[in] state: i3c power state
 * \return  \ref return_status
 */
int32_t sedi_i3c_set_power(sedi_i3c_t bus, sedi_power_state_t state);

/*!
 * \brief Init i3c to slave device
 * \param[in] bus: i3c_slave device id
 * \param[in] event_callback: I3C slave event callback
 * \param[in] event_param: I3C event callback user parameter
 * \param[in] trans_callback: I3C slave transfer callback function
 * \return  \ref return_status
 */
int32_t sedi_i3c_slave_init(IN sedi_i3c_t bus,
			IN sedi_i3c_event_cb_t event_callback,
			IN void *event_param,
			IN sedi_i3c_slave_transmit_cb_t trans_callback);

/*!
 * \brief Uninit the device's power
 * \param[in] bus: i3c_slave device id
 * \return  \ref return_status
 */
int32_t sedi_i3c_slave_uninit(IN sedi_i3c_t bus);

/*!
 * \brief Set the device's power
 * \param[in] bus: i3c_slave device id
 * \param[in] config: I3C slave configure structure pointer
 * \return  \ref return_status
 */
int32_t sedi_i3c_slave_setup(IN sedi_i3c_t bus,
			   IN sedi_i3c_slave_config_t *config);

/*!
 * \brief Notify I3C slave to prepare for a I3C master read operation
 * \param[in] bus: i3c_slave device id
 * \param[in] lem: Master read length in bytes
 * \return  \ref return_status
 */
int32_t sedi_i3c_slave_init_master_read(IN sedi_i3c_t bus, IN uint32_t len);

/*!
 * \brief Start transmitting data to i3c master due to a master read request
 * \note DMA function do not support transfer length smaller than 4 bytes.
 * \param[in] bus: i3c_slave device id
 * \param[in] dma: dma device id
 * \param[in] dma_chan: dma channel id
 * \param[in] data: pointer of the buffer with data
 *                   which need write to the slave
 * \param[in] num: number of data bytes to transfer
 * \return  \ref return_status
 */
int32_t sedi_i3c_slave_write_dma(IN sedi_i3c_t bus, IN uint32_t dma,
				  IN uint32_t dma_chan, IN uint8_t *data, IN uint32_t num);


/*!
 * \brief  Read out data from fifo directly
 * \param[in] bus: i3c_slave device id
 * \param[out] buf: Pointer to data storage area.
 * \param[in] len: Read length in bytes
 * \return  \ref return_status
 */
int sedi_i3c_slave_read_fifo(IN sedi_i3c_t bus, OUT uint8_t *buf, IN uint8_t len);

/*!
 * \brief  Write certain data into fifo directly
 * \param[in] bus: i3c_slave device id
 * \param[in] buf: Pointer to data storage area.
 * \param[in] len: Write length in bytes
 * \return  \ref return_status
 */
int sedi_i3c_slave_write_fifo(IN sedi_i3c_t bus, IN uint8_t *buf, IN uint8_t len);

/*!
 * \brief  I3C slave request irq to master (SIR)
 * \param[in] bus: i3c_slave device id
 * \return  \ref return_status
 */
int sedi_i3c_slave_request_irq(IN sedi_i3c_t bus);

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_I3C_H_*/
