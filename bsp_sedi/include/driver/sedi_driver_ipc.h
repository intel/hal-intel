/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_IPC_H_
#define _SEDI_DRIVER_IPC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

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
 * Received an incoming ipc message
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

/****** IPC Capability *****/

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

#define IPC_DRBL_BUSY_BIT 31
#define IPC_DATA_LEN_MAX  128

#define IPC_HEADER_LENGTH_MASK (0x03FF)
#define IPC_HEADER_PROTOCOL_MASK (0x0F)
#define IPC_HEADER_MNG_CMD_MASK (0x0F)

#define IPC_HEADER_LENGTH_OFFSET 0
#define IPC_HEADER_PROTOCOL_OFFSET 10
#define IPC_HEADER_MNG_CMD_OFFSET 16
#define IPC_DRBL_BUSY_OFFS 31

#define IPC_HEADER_GET_LENGTH(drbl_reg)        \
	(((drbl_reg) >> IPC_HEADER_LENGTH_OFFSET) & IPC_HEADER_LENGTH_MASK)
#define IPC_HEADER_GET_PROTOCOL(drbl_reg) \
	(((drbl_reg) >> IPC_HEADER_PROTOCOL_OFFSET) & IPC_HEADER_PROTOCOL_MASK)
#define IPC_HEADER_GET_MNG_CMD(drbl_reg) \
	(((drbl_reg) >> IPC_HEADER_MNG_CMD_OFFSET) & IPC_HEADER_MNG_CMD_MASK)
#define IPC_IS_BUSY(drbl) ((drbl) & BIT(IPC_DRBL_BUSY_OFFS))
#define IPC_SET_BUSY(drbl) ((drbl) | BIT(IPC_DRBL_BUSY_OFFS))

#define IPC_BUILD_DRBL(length, protocol)             \
	((1 << IPC_DRBL_BUSY_OFFS)                    \
	 | ((protocol) << IPC_HEADER_PROTOCOL_OFFSET) \
	 | ((length) << IPC_HEADER_LENGTH_OFFSET))

#define IPC_BUILD_MNG_DRBL(cmd, length)                              \
	(((1) << IPC_DRBL_BUSY_OFFS)                          \
	 | ((IPC_PROTOCOL_MNG) << IPC_HEADER_PROTOCOL_OFFSET) \
	 | ((cmd) << IPC_HEADER_MNG_CMD_OFFSET)               \
	 | ((length) << IPC_HEADER_LENGTH_OFFSET))

/* CSR bit definition */
#define IPC_CSR_NO_MSG			0
#define IPC_CSR_RESET_ENTRY		BIT(0)
#define IPC_CSR_RESET_EXIT		BIT(1)
#define IPC_CSR_QUERY			BIT(2)
#define IPC_CSR_ASSERT_VALID		BIT(3)
#define IPC_CSR_ACKED_VALID		BIT(4)
#define IPC_CSR_DEASSERT_VALID		BIT(5)
#define IPC_CSR_SRAM_CLAIM		BIT(31)

/****** IPC Driver API *****/

/*
 * ipc_event_handler IPC Event Handler Callback
 * typedef sedi_ipc_event_cb_t
 * Callback function type for signal ipc event.
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
 * write CSR message to peer.
 * param[in] ipc_device: ipc device id
 * param[in] csr: the csr content to sent
 * return return status
 */
int32_t sedi_ipc_write_csr(IN sedi_ipc_t ipc_device, IN uint32_t csr);

/*
 * read CSR message from peer.
 * param[in] ipc_device: ipc device id
 * param[out] csr: the pointer storing the csr msg
 * return return status
 */
int32_t sedi_ipc_read_csr(IN sedi_ipc_t ipc_device, OUT uint32_t *csr);

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
 * Uninitialize the device
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

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_IPC_H_*/
