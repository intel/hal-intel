/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_IPC_H_
#define _SEDI_DRIVER_IPC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/****** IPC Interface type *****/

/*
 * struct sedi_ipc
 * define IPC interface ID
 * \ingroup sedi_driver_ipc
 */
typedef enum {
	SEDI_IPC_HOST = 0,
	SEDI_IPC_CSME,
	SEDI_IPC_PMC,
	SEDI_IPC_NUM
} sedi_ipc_t;

/****** IPC Event *****/

/*
 * SEDI_IPC_EVENT_MSG_IN
 * Received an coming ipc message
 * \ingroup sedi_driver_ipc
 */
#define SEDI_IPC_EVENT_MSG_IN (1UL << 0)

/*
 * SEDI_IPC_EVENT_MSG_PEER_ACKED
 * An ipc busy bit is cleared by peer
 * \ingroup sedi_driver_ipc
 */
#define SEDI_IPC_EVENT_MSG_PEER_ACKED (1UL << 1)

/*
 * SEDI_IPC_EVENT_MSG_OUT
 * An ipc message is received by peer
 * \ingroup sedi_driver_ipc
 */
#define SEDI_IPC_EVENT_MSG_OUT (1UL << 2)

/*
 * SEDI_IPC_EVENT_CSR_ACK
 * Receive a CSR ack from peer after writing CSR
 * \ingroup sedi_driver_ipc
 */
#define SEDI_IPC_EVENT_CSR_ACK (1UL << 3)

/****** IPC Capbility *****/

/*
 * struct sedi_ipc_capabilities_t
 * define IPC Driver Capabilities.
 * \ingroup sedi_driver_ipc
 */
typedef struct {
	uint32_t is_available : 1;
	uint32_t reserved : 31;
} sedi_ipc_capabilities_t;

/****** IPC Driver helper definitions *****/

#define IPC_PROTOCOL_BOOT 0
#define IPC_PROTOCOL_HECI 1
#define IPC_PROTOCOL_MCTP 2
#define IPC_PROTOCOL_MNG 3

#define IPC_DATA_LEN_MAX (128)

#define IPC_HEADER_LENGTH_MASK (0x03FF)
#define IPC_HEADER_PROTOCOL_MASK (0x0F)
#define IPC_HEADER_LENGTH_OFFSET 0
#define IPC_HEADER_PROTOCOL_OFFSET 10
#define IPC_HEADER_GET_LENGTH(drbl_reg)	\
	(((drbl_reg) >> IPC_HEADER_LENGTH_OFFSET) & IPC_HEADER_LENGTH_MASK)
#define IPC_HEADER_GET_PROTOCOL(drbl_reg) \
	(((drbl_reg) >> IPC_HEADER_PROTOCOL_OFFSET) & IPC_HEADER_PROTOCOL_MASK)
#define IPC_IS_BUSY(drbl_reg) \
	(((drbl_reg) & IPC_DRBL_BUSY_BIT) == ((uint32_t)IPC_DRBL_BUSY_BIT))
#define IPC_BUILD_HEADER(length, protocol, busy)      \
	(((busy) << IPC_DRBL_BUSY_OFFS) |	      \
	 ((protocol) << IPC_HEADER_PROTOCOL_OFFSET) | \
	 ((length) << IPC_HEADER_LENGTH_OFFSET))
#define IPC_SET_BUSY(drbl_reg) ((drbl_reg) | (IPC_DRBL_BUSY_BIT))

/****** IPC Driver API *****/

/*
 * ipc_event_handler I2C Event Handler Callback
 * typedef sedi_i2c_event_cb_t
 * Callback function type for signal i2c event.
 * param[in] event: event type.
 * return    void
 */
typedef void (*sedi_ipc_event_cb_t)(IN sedi_ipc_t device, IN uint32_t event,
				    INOUT void *params);

/*
 * Get the ipc driver's API version.
 * return the version of current ipc driver's API
 */
sedi_driver_version_t sedi_ipc_get_version(void);

/*
 * Get the device's capabilities.
 * param[in] ipc_device: ipc device id
 * param[inout]  the capabilities of specific ipc device
 * return return status
 */
int32_t sedi_ipc_get_capabilities(IN sedi_ipc_t ipc_device,
				  INOUT sedi_ipc_capabilities_t *cap);

/*
 * Initialize the device
 * param[in] ipc_device: ipc device id
 * param[in] cb: the callback function which can receive device's events.
 * param[in] user_params: user params, will be the last input of callback
 * return  return_status
 */
int32_t sedi_ipc_init(IN sedi_ipc_t ipc_device, IN sedi_ipc_event_cb_t cb,
		      INOUT void *user_params);

/*
 * Uninitailize the device
 * param[in] ipc_device: ipc device id
 * return  return_status
 */
int32_t sedi_ipc_uninit(IN sedi_ipc_t ipc_device);

/*
 * Set the device's power
 * param[in] ipc_device: ipc device id
 * param[in] state: the power state to be set to the device
 * return  return_status
 */
int32_t sedi_ipc_set_power(IN sedi_ipc_t ipc_device,
			   IN sedi_power_state_t state);

/*
 * Write data to IPC message fifo
 * param[in] ipc_device: ipc device id
 * param[in] msg: point to memory area where data is stored
 * param[in] size: the length of data buffer
 * return  return_status
 */
int32_t sedi_ipc_write_msg(IN sedi_ipc_t ipc_device, IN uint8_t *msg,
			   IN int32_t size);

/*
 * Write IPC doorbell register
 * param[in] ipc_device: ipc device id
 * param[in] doorbell: the value of doorbell
 * return  return_status
 */
int32_t sedi_ipc_write_dbl(IN sedi_ipc_t ipc_device, IN uint32_t doorbell);

/*
 * Read data from IPC message fifo
 * param[in] ipc_device: ipc device id
 * param[out] msg: point to memory area where data will be stored
 * param[in] size: the length of data buffer
 * return  return_status
 */
int32_t sedi_ipc_read_msg(IN sedi_ipc_t ipc_device, OUT uint8_t *msg,
			  IN int32_t size);

/*
 * Read IPC doorbell register
 * param[in] ipc_device: ipc device id
 * param[out] doorbel: point to the value of doorbell
 * return  return_status
 */
int32_t sedi_ipc_read_dbl(IN sedi_ipc_t ipc_device, OUT uint32_t *doorbell);

/*
 * send ack IPC message
 * param[in] ipc_device: ipc device id
 * param[in] msg: the ack msg
 * param[in] size: the length of data buffer
 * return  return_status
 */
int32_t sedi_ipc_send_ack_msg(IN sedi_ipc_t ipc_device, IN uint8_t *msg,
			      IN int32_t size);

/*
 * send ack IPC doorbell register
 * param[in] ipc_device: ipc device id
 * param[in] doorbell: the ack doorbell
 * return  return_status
 */
int32_t sedi_ipc_send_ack_drbl(IN sedi_ipc_t ipc_device, IN uint32_t ack);

/*
 * read peer ack IPC message
 * param[in] ipc_device: ipc device id
 * param[out] doorbell: the buffer to store ack msg
 * param[in] size: the length of data buffer
 * return  return_status
 */
int32_t sedi_ipc_read_ack_msg(IN sedi_ipc_t ipc_device, OUT uint8_t *msg,
			      IN int32_t size);

/*
 * read peer ack IPC doorbell register
 * param[in] ipc_device: ipc device id
 * param[out] doorbell: the ack doorbell
 * return  return_status
 */
int32_t sedi_ipc_read_ack_drbl(IN sedi_ipc_t ipc_device, OUT uint32_t *ack);

/*!
 * \enum sedi_fwst_type_t
 * \brief Firmware status types
 * \ingroup sedi_driver_ipc
 */
typedef enum {
	ILUP_HOST,
	ILUP_SEC,
	HECI_READY,
	FAILURE_REASON, /**< Failure reason, check below for details. */
	RESET_COUNT,
	FW_STATE,       /**< Firware status, check below for details. */
	DMA_PROGRESS0,  /**< DMA0 is in progress. */
	DMA_PROGRESS1,
	DMA_PROGRESS2,
	DMA_PROGRESS3,
	PWR_STATE,              /**< PSE power state, check below for details. */
	AON_CHECKPOINTS,        /**< Checkpoints for AON task, check below as details. */
	FWST_TYPES_LAST
} sedi_fwst_type_t;

/*!
 * \enum sedi_fwst_t
 * \brief Firmware status
 * \ingroup sedi_driver_ipc
 */
typedef enum {
	AFTER_RESET             = 0,
	WAITING_FOR_PATCH       = 1,
	BUP_IN_PROGRESS         = 2,
	LOAD_REQ_SENT           = 3,
	WAIT_FOR_HOST           = 4,
	START_KERNEL_DMA        = 5,
	JUMP_TO_KERNEL          = 6,
	FW_IS_RUNNING           = 7, /**< From now on, kernel used. */
	SENSORS_APP_LOADED      = 8,
	SENSORS_TABLES_LOADED   = 9,
	SENSORS_APP_RUNNING     = 0xf,
} sedi_fwst_t;

/*!
 * \enum sedi_pm_fail_reason_t
 * \brief PSE PM failure reason
 * \ingroup sedi_driver_ipc
 */
typedef enum {
	PSE_DISABLED = 0,
	AUTH_FAILURE,
	EXCEPTION_OVER_LIMIT,
	INVALID_UMA_REGS,
	PLATFORM_RESET_WAIT,
	WRONG_SEC_MSG,
	DMA_FAILURE,
	OTHER_FAILURE,
	AON_STACK_OVERFLOW      = 9, /**< AON used, stack overflow. */
	NO_FAILURE              = 0xe,
	FAIL_REASON_MAX         = 0xf
} sedi_pm_fail_reason_t;

/*!
 * \enum sedi_pse_pwr_state_t
 * \brief PSE power state
 * \ingroup sedi_driver_ipc
 */
typedef enum {
	PSE_D0                  = 0,
	PSE_D0i0,
	PSE_D0i1,
	PSE_D0i2,
	PSE_D0i3                = 5,
	PSE_D3_WAITING          = 7,
	PSE_PD,
	PSE_PWR_STATE_MAX       = 0xf
} sedi_pse_pwr_state_t;

/*!
 * \struct sedi_aon_checkpoints_t
 * \brief Checkpoints for AON task
 * \ingroup sedi_driver_ipc
 */
typedef enum {
	NOT_IN_AON = 0,
	AON_ENTRY,
	AON_HALT,
	AON_WAKE,
	AON_EXIT,
	AON_CHECKPOINT_MAX = 0x7
} sedi_aon_checkpoints_t;

/*!
 * \fn void sedi_fwst_set(IN sedi_fwst_type_t type, IN uint32_t value)
 * \brief Set firmware status
 * \param[in] type: the type of the status
 * \param[in] value: the value of the status
 * \return void
 */
void sedi_fwst_set(IN sedi_fwst_type_t type, IN uint32_t value);

/*!
 * \fn int32_t sedi_fwst_get(IN sedi_fwst_type_t type, OUT uint32_t *value)
 * \brief Get firmware status
 * \param[in] type: the type of the status
 * \param[out] value: the value the status
 * \return result of getting firmware status
 */
int32_t sedi_fwst_get(IN sedi_fwst_type_t type, OUT uint32_t *value);

/*!
 * \enum sedi_dev_table_t
 * \brief PSE device table
 * \ingroup sedi_driver_ipc
 */
typedef enum {
	PSE_DEV_I2C0 = 0,
	PSE_DEV_I2C1,
	PSE_DEV_I2C2,
	PSE_DEV_I2C3,
	PSE_DEV_I2C4,
	PSE_DEV_I2C5,
	PSE_DEV_I2C6,
	PSE_DEV_I2C7,
	PSE_DEV_UART0,
	PSE_DEV_UART1,
	PSE_DEV_UART2,
	PSE_DEV_UART3,
	PSE_DEV_UART4,
	PSE_DEV_UART5,
	PSE_DEV_SPI0,
	PSE_DEV_SPI1,
	PSE_DEV_SPI2,
	PSE_DEV_SPI3,
	PSE_DEV_GBE0,
	PSE_DEV_GBE1,
	PSE_DEV_CAN0,
	PSE_DEV_CAN1,
	PSE_DEV_GPIO0,
	PSE_DEV_GPIO1,
	PSE_DEV_DMA0,
	PSE_DEV_DMA1,
	PSE_DEV_DMA2,
	PSE_DEV_QEP0,
	PSE_DEV_QEP1,
	PSE_DEV_QEP2,
	PSE_DEV_QEP3,
	PSE_DEV_I2S0,
	PSE_DEV_I2S1,
	PSE_DEV_PWM,
	PSE_DEV_ADC0,
	PSE_DEV_LHIPC,
	PSE_DEV_MAX
} sedi_dev_table_t;

/*!
 * \enum sedi_dev_ownership_t
 * \brief PSE device owenership
 * \ingroup sedi_driver_ipc
 */
typedef enum {
	NO_SUCH_DEV     = -1,
	DEV_PSE_OWNED   = 0,
	DEV_LH_OWNED_MSI,
	DEV_LH_OWNED_SB,
	DEV_NO_OWNER
} sedi_dev_ownership_t;

sedi_dev_ownership_t sedi_get_dev_ownership(sedi_dev_table_t dev);

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_IPC_H_*/
