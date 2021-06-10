/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_SIDEBAND_H_
#define _SEDI_DRIVER_SIDEBAND_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_sideband SIDEBAND
 * \ingroup sedi_driver
 */

#define SEDI_SB_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/*!
 * \defgroup sideband_control_mode  SIDEBAND Control
 * \ingroup sedi_driver_sideband
 */

enum sedi_sideband_ioctl {
	/*!
	 * message address type, arg is sideband_addr_t
	 */
	SEDI_SIDEBAND_ADDRESS_TYPE,

	SEDI_SIDEBAND_IOCTL_NUM
};

/*!
 * \defgroup sideband_event SIDEBAND Event
 * \ingroup sedi_driver_sideband
 */

/*! already send out */
#define SEDI_SIDEBAND_EVENT_SENT (1UL << 0)

/*! target device ack 'ok' */
#define SEDI_SIDEBAND_EVENT_COMPLETED (1UL << 1)

/*! target device ack 'unsupported request' */
#define SEDI_SIDEBAND_EVENT_UNSUPPORTED (1UL << 2)

/*! received a message from target */
#define SEDI_SIDEBAND_EVENT_MSG_ARRIVE (1UL << 2)

/*!
 * \defgroup sedi_sideband_t SIDEBAND instance id
 * \ingroup sedi_driver_sideband
 */
typedef enum { SEDI_SIDEBAND_0 = 0, SEDI_SIDEBAND_NUM } sedi_sideband_t;

/*!
 * \defgroup sideband_port SIDEBAND Portlist
 * \ingroup sedi_driver_sideband
 */
typedef enum {
	SB_CSME,
	SB_PMC,
	SB_ISP,
	SB_AUDIO,
	SB_PSE_BRIDGE,

	SB_GPIO_COMM0,
	SB_GPIO_COMM1,
	SB_GPIO_COMM2,
	SB_GPIO_COMM3,

	SB_GPIO_COMM4,

	SB_XHCI,                /**< XHCI entry port */
	SB_HPD,                 /**< HPD entry port */
	SB_FIA,                 /**< FIA entry port */
	SB_EXI,                 /**< EXI entry port */
	SB_PCIE,                /**< PCIE entry port */
	SB_GPIO_PINMODE,        /**< GPIO PinMode entry port */
	SB_DEKEL_PHY0,          /**< Dekel PHY 0 port */
	SB_DEKEL_PHY1,          /**< Dekel PHY 1 port */
	SB_DRNG,

	SB_TOTAL
} sb_port_t;

/*!
 * \defgroup sideband_down_client SIDEBAND downstream client
 * \ingroup sedi_driver_sideband
 */
typedef enum {
	SB_DOWN_PMC     = 0,
	SB_DOWN_TSYNC   = 1,
	SB_DOWN_AUDIO   = 2,
	SB_DOWN_ISP     = 3,
	SB_DOWN_CSME    = 4,
	SB_DOWN_GPIO    = 5,
	SB_DOWN_CLIENT_MAX,
} sideband_down_client_t;

/*!
 * \defgroup sideband_action SIDEBAND Action
 * \ingroup sedi_driver_sideband
 */
typedef enum {
	SEDI_SIDEBAND_ACTION_WRITE,
	SEDI_SIDEBAND_ACTION_READ,
} sideband_action_t;

/*!
 * \defgroup sideband_response SIDEBAND Response status
 * \ingroup sedi_driver_sideband
 */
typedef enum {
	SEDI_SIDEBAND_RESPONSE_COMPLETE,
	SEDI_SIDEBAND_RESPONSE_UNSUPPORTED,
} sideband_response_t;

/*!
 * \defgroup sideband_addr_type SIDEBAND message address type
 * \ingroup sedi_driver_sideband
 */
typedef enum {
	SEDI_SIDEBAND_ADDRESS_16BITS,
	SEDI_SIDEBAND_ADDRESS_48BITS
} sideband_addr_t;

/*!
 * \struct sedi_sideband_capabilities_t
 * \brief SIDEBAND Capabilities, the hardware feature
 * \ingroup sedi_driver_sideband
 */
typedef struct {
	uint32_t reserved : 32;
} sedi_sideband_capabilities_t;

/*!
 * \defgroup sideband_event_handler SIDEBAND Event Handler Callback
 * \ingroup sedi_driver_sideband
 * \{
 */

/*!
 * \typedef sedi_sideband_event_cb_t
 * \brief Callback function type for signal sideband event.
 * \param[in] event: event type. see \ref sideband_event
 * \param[inout] param: user parameter
 * \return    void
 */
typedef void (*sedi_sideband_event_cb_t)(IN uint32_t event, INOUT void *param);

/*!
 * \}
 */

/*!
 * \defgroup sideband_function_calls SIDEBAND Driver Function Calls
 * \ingroup sedi_driver_sideband
 * \{
 */

/*!
 * \brief Get the sideband driver's API version.
 * \return the version of current sideband driver's API
 */
sedi_driver_version_t sedi_sideband_get_version(void);

/*!
 * \brief Get the device's capabilities.
 * \param[in] sideband_device: sideband device id
 * \param[out] cap: sideband device capabilities
 * \return  \ref return_status
 */
int32_t sedi_sideband_get_capabilities(IN sedi_sideband_t sideband_device,
				       OUT sedi_sideband_capabilities_t *cap);

/*!
 * \brief Initialize the device
 * \param[in] sideband_device: sideband device id
 * \return  \ref return_status
 */
int32_t sedi_sideband_init(IN sedi_sideband_t sideband_device);

/*!
 * \brief Uninitailize the device
 * \param[in] sideband_device: sideband device id
 * \return  \ref return_status
 */
int32_t sedi_sideband_uninit(IN sedi_sideband_t sideband_device);

/*!
 * \brief Set the device's power
 * \param[in] sideband_device: sideband device id
 * \param[in] state: the power state to be set to the device
 * \return  \ref return_status
 */
int32_t sedi_sideband_set_power(IN sedi_sideband_t sideband_device,
				IN sedi_power_state_t state);

/*!
 * \brief Register a downstream client
 * \param[in] sideband_device: sideband device id
 * \param[in] client: sideband downstream client id
 * \param[in] opcode: Opcode for this downstream
 * \param[in] callback: Callback function for dowmstrem irq
 * \param[inout] param: Callback user parameter
 * \return  \ref return_status
 */
int32_t sedi_sideband_register_client(IN sedi_sideband_t sideband_device,
				      IN sideband_down_client_t client,
				      IN uint32_t opcode,
				      IN sedi_sideband_event_cb_t callback,
				      INOUT void *param);

/*!
 * \brief Uninitailize the device
 * \param[in] sideband_device: sideband device id
 * \param[in] client: sideband downstream client id
 * \return  \ref return_status
 */
int32_t sedi_sideband_unregister_client(IN sedi_sideband_t sideband_device,
					IN sideband_down_client_t client);

/*!
 * \brief  Control the sideband device
 * \param[in] sideband_device: sideband device id
 * \param[in] control: control operation code. see \ref sideband_control_codes
 * \param[in] arg: argument of operation (optional)
 * \return  \ref return_status
 */
int32_t sedi_sideband_control(IN sedi_sideband_t sideband_device,
			      IN uint32_t control, IN uint32_t arg);

/*!
 * \brief Start send data to sideband target
 * \param[in] sideband_device: sideband device id
 * \param[in] port: sideband target port
 * \param[in] action: sideband action
 * \param[in] addr: address in target's address space
 * \param[in] data: data to be written to target
 * \return  \ref return_status
 */
int32_t sedi_sideband_send(IN sedi_sideband_t sideband_device,
			   IN sb_port_t port, IN sideband_action_t action,
			   IN uint64_t addr, IN uint32_t data);

/*!
 * \brief Wait for ack from target
 * \param[in] sideband_device: sideband device id
 * \param[in] port: sideband target port
 * \param[in] action: sideband action
 * \param[out] data: data from target
 * \return  \ref return_status
 */
int32_t sedi_sideband_wait_ack(IN sedi_sideband_t sideband_device,
			       IN sb_port_t port, IN sideband_action_t action,
			       OUT uint32_t *data);

/*!
 * \brief Receive data from target in polling way
 * \param[in] sideband_device: sideband device id
 * \param[in] port: sideband target port
 * \param[in] opcode: Opcode need to receive, 0 means any opcode.
 * \param[out] addr: address in target's address space
 * \param[out] data: data to be read
 * \return  \ref return_status
 */
int32_t sedi_sideband_recv(IN sedi_sideband_t sideband_device,
			   IN sb_port_t port, IN uint32_t opcode,
			   OUT uint64_t *addr, OUT uint64_t *data);

/*!
 * \brief Receive data from target in irq mode
 * \param[in] sideband_device: sideband device id
 * \param[in] port: sideband target port
 * \param[out] addr: address in target's address space
 * \param[out] data: data to be read
 * \return  \ref return_status
 */
int32_t sedi_sideband_recv_async(IN sedi_sideband_t sideband_device,
				 IN sb_port_t port, OUT uint64_t *addr,
				 OUT uint64_t *data);

/*!
 * \brief Send ack to target
 * \param[in] sideband_device: sideband device id
 * \param[in] port: sideband target port
 * \param[in] action: sideband action
 * \param[in] status: notify the response message's type
 * \param[in] data: data to target
 * \return  \ref return_status
 */
int32_t sedi_sideband_send_ack(IN sedi_sideband_t sideband_device,
			       IN sb_port_t port, IN sideband_action_t action,
			       IN sideband_response_t status, IN uint32_t data);

/*!
 * \brief Directly write attribute and sairs registers
 * \param[in] sideband_device: sideband device id
 * \param[in] addr_low: address in target's address space
 * \param[in] addr_high: address in target's address space
 * \param[in] attr: attr value
 * \param[in] data: data to be written to target
 * \param[in] cmd: Command data
 * \param[in] sairs: sairs register value
 * \param[in] action: Read or write
 * \return  \ref return_status
 */
int32_t sedi_sideband_upstream_write_raw(IN sedi_sideband_t sideband_device,
					 IN uint32_t addr_low,
					 IN uint32_t addr_high,
					 IN uint32_t attr, IN uint32_t data,
					 IN uint32_t cmd, IN uint32_t sairs,
					 sideband_action_t action);

/*!
 * \brief Directly write attribute and sairs registers
 * \param[in] sideband_device: sideband device id
 * \param[in] addr_low: address in target's address space
 * \param[in] addr_high: address in target's address space
 * \param[in] attr: attr value
 * \param[in] sairs: sairs register value
 * \param[in] data: data pointer to be read
 * \return  \ref return_status
 */
int32_t sedi_sideband_downstream_read_raw(IN sedi_sideband_t sideband_device,
					  uint32_t *addr_low,
					  uint32_t *addr_high, uint32_t *attr,
					  uint32_t *data0, uint32_t *data1,
					  uint32_t *sairs);

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_SIDEBAND_H_ */
