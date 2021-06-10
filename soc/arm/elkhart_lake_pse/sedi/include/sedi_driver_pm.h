/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_PM_H_
#define _SEDI_DRIVER_PM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"
#include "sedi_driver_ipc.h"

/*!
 * \defgroup sedi_driver_pm PM
 * \ingroup sedi_driver
 */

#define SEDI_PM_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/*!
 * \enum sedi_pm_ioctl_t
 * \brief control option for PM driver
 * \ingroup sedi_driver_pm
 */
typedef enum {
	/*!
	* Enable CCU_TCG_GBE1_RGMII_PHY_RX and
	* CCU_TCG_GBE2_RGMII_PHY_RX trunk clock
	*/
	SEDI_PM_IOCTL_TCG_GBE_RGMII_PHY_RX,
	/*!
	 * OOB support, to keep PSE alive when
	 * host reboots or shutdowns
	 * arg: zero to disable, none-zero to enable
	 */
	SEDI_PM_IOCTL_OOB_SUPPORT,
	/*!
	 * WOL support, D0i3 would not be available
	 * arg: zero to disable, none-zero to enable
	 */
	SEDI_PM_IOCTL_WOL_SUPPORT,
	SEDI_PM_IOCTL_MAX
} sedi_pm_ioctl_t;

/*!
 * \enum vnn_id_t
 * \brief VNN ID bit for different device
 * \ingroup sedi_driver_pm
 */
typedef enum {
	FIRST_VNN_ID            = 0,
	VNN_ID_AON_TASK         = FIRST_VNN_ID,
	VNN_ID_IPC_PMC_W        = 1,    /**< DO NOT CHANGE. USED BY ROM. */
	VNN_ID_IPC_CSE_W        = 2,    /**< DO NOT CHANGE. USED BY ROM. */
	VNN_ID_IPC_HOST_W       = 3,    /**< DO NOT CHANGE. USED BY ROM. */
	VNN_ID_DMA0             = 4,
	VNN_ID_DMA1             = 5,
	VNN_ID_DMA2             = 6,
	VNN_ID_AON              = 8, /**< DO NOT CHANGE. USED BY ROM. */
	VNN_ID_IPC_PMC_R        = 9,
	VNN_ID_IPC_CSE_R        = 10,
	VNN_ID_IPC_HOST_R       = 11,
	VNN_ID_EXC_LOG          = 17,
	VNN_ID_SRAM             = 19,
	VNN_ID_HIGH_FREQUENCY   = 20,
	VNN_ID_SIDEBAND         = 21,
	VNN_ID_ROM_DEBUG        = 22, /**< DO NOT CHANGE. USED BY ROM. */
	VNN_ID_GBE0             = 23,
	VNN_ID_GBE1             = 24,
	VNN_ID_PM               = 25, /**< for host owned devices */
	VNN_ID_BRIDGE           = 26,
	LAST_VNN_ID,
} vnn_id_t;

/*!
 * \enum sedi_callback_priority_t
 * \brief Priority of callback function
 * \ingroup sedi_driver_pm
 */
typedef enum {
	CALLBACK_PRI_LOW        = 1,
	CALLBACK_PRI_NORMAL,
	CALLBACK_PRI_HIGH,
	CALLBACK_PRI_MAX        = 0x4
} sedi_pm_callback_priority_t;

/*!
 * \enum sedi_pm_callback_type_t
 * \brief Type of callback function
 * \ingroup sedi_driver_pm
 */
typedef enum {
	CALLBACK_TYPE_RESET_PREP = 1,
	CALLBACK_TYPE_CLOCK_CHANGE,
	CALLBACK_TYPE_MAX
} sedi_pm_callback_type_t;

/*!
 * \enum sedi_pm_sx_event_t
 * \brief Type of host Sx event
 * \ingroup sedi_driver_pm
 */
typedef enum {
	PM_EVENT_HOST_SX_ENTRY, /* Host entered Sx state. */
	PM_EVENT_HOST_SX_EXIT,  /* Host exit Sx state. */
} sedi_pm_sx_event_t;

/*!
 * \enum sedi_pm_d3_event_t
 * \brief Type of host D3 event
 * \ingroup sedi_driver_pm
 */
typedef enum {
	PM_EVENT_HOST_D3_ENTRY, /* Host entered D3 state. */
	PM_EVENT_HOST_D3_EXIT,  /* Host exit D3 state. */
} sedi_pm_d3_event_t;

/*!
 * \enum sedi_pm_s0ix_event_t
 * \brief Type of host S0ix event
 * \ingroup sedi_driver_pm
 */
typedef enum {
	PM_EVENT_HOST_S0IX_ENTRY,       /* Host entered S0ix state. */
	PM_EVENT_HOST_S0IX_EXIT,        /* Host exit S0ix state. */
} sedi_pm_s0ix_event_t;

/*!
 * \enum sedi_pm_reset_type_t
 * \brief Type of reset type
 * \ingroup sedi_driver_pm
 */
typedef enum {
	PM_RESET_TYPE_S0                = 0x0,  /* S0 */
	PM_RESET_TYPE_S3                = 0x3,  /* S3 */
	PM_RESET_TYPE_S4,                       /* S4 */
	PM_RESET_TYPE_S5,                       /* S5 */
	PM_RESET_TYPE_WARM_RESET        = 0x10, /* Warm reset */
} sedi_pm_reset_type_t;

/*!
 * \enum sedi_pm_prep_type_t
 * \brief Type of reset prep type
 * \ingroup sedi_driver_pm
 */
typedef enum {
	PM_PREP_TYPE_GENERAL = 0x0, /* General Prep */
} sedi_pm_prep_type_t;

/*!
 * \def PM_RSTPREP_TYPE_BIOS_SETTING_CHANGED
 * \brief used as special prep_type/reset_type to notify sedi_pm_rstprep_cb
 *	that BIOS setting was just changed and FW will reset
 */
#define PM_RSTPREP_TYPE_BIOS_SETTING_CHANGED ((uint32_t)-1)

/*!
 * \fn sedi_pm_rstprep_cb
 * \brief Callback function after reset prepare message received.
 * \ingroup sedi_driver_pm
 */
typedef void (*sedi_pm_rstprep_cb)(uint32_t prep_type, uint32_t reset_type,
				   void *ctx);

/*!
 * \fn sedi_pm_clkchange_cb
 * \brief Callback function after clock changed.
 * \ingroup sedi_driver_pm
 */
typedef void (*sedi_pm_clkchange_cb)(uint32_t core_clk_freq,
				     uint32_t hbw_clk_freq, void *ctx);

/*!
 * \fn sedi_pm_sx_cb
 * \brief Callback function of host sx entry/exit notification.
 * \ingroup sedi_driver_pm
 */
typedef void (*sedi_pm_sx_cb)(sedi_pm_sx_event_t sx_event, void *ctx);

/*!
 * \fn sedi_pm_d3_cb
 * \brief Callback function of host device D3 entry/exit notification.
 * \ingroup sedi_driver_pm
 */
typedef void (*sedi_pm_d3_cb)(sedi_pm_d3_event_t d3_event, void *ctx);

/*!
 * \fn sedi_pm_s0ix_cb
 * \brief Callback function of host s0ix entry/exit notifcation.
 * \ingroup sedi_driver_pm
 */
typedef void (*sedi_pm_s0ix_cb)(sedi_pm_s0ix_event_t s0ix_event, void *ctx);

/*!
 * \union sedi_pm_callback_fn_t
 * \brief Union for PM callback function
 * Caution: don't call blocked function in rstprep_cb, or PM reset flow might
 * be delayed and miss its time window to acknowledge PMC
 * \ingroup sedi_driver_pm
 */
typedef union {
	sedi_pm_rstprep_cb rstprep_cb;
	sedi_pm_clkchange_cb clk_change_cb;
} sedi_pm_callback_fn_t;

/*!
 * \struct sedi_pm_callback_config_t
 * \brief Structure for setting PM callback
 * \ingroup sedi_driver_pm
 */
typedef struct {
	sedi_pm_callback_type_t type;           /**< Callback type */
	sedi_pm_callback_fn_t func;             /**< Callback function */
	sedi_pm_callback_priority_t pri;        /**< Callback function priority */
	void *ctx;                              /**< Context for callback */
} sedi_pm_callback_config_t;

/*!
 * \defgroup pm_function_calls PM Driver Function Calls
 * \ingroup sedi_driver_pm
 * \{
 */

/*!
 * \fn int32_t sedi_pm_init(void)
 * \brief Initialize the PM, at very beginning
 * \return result of PM initialization
 */
int32_t sedi_pm_init(void);

/*!
 * \fn int32_t sedi_pm_late_init(void)
 * \brief Some operations should be performed after the initialization of
 * peripheral drivers. That's why this late init API is needed.
 * \return result of PM late initialization
 */
int32_t sedi_pm_late_init(void);

/*!
 * \fn uint32_t sedi_pm_get_hbw_clock(void)
 * \brief Get current HBW clock frequency
 * \return uint32_t current HBW clock frequency
 */
uint32_t sedi_pm_get_hbw_clock(void);

/*!
 * \fn int32_t sedi_pm_set_control(IN uint32_t control, IN uint32_t arg)
 * \brief Set control flag for pm driver
 * \param[in] control: control operation code.
 * \param[in] arg: argument of control operation, it's optional
 * \return 0 or error codes
 */
int32_t sedi_pm_set_control(IN uint32_t control, IN uint32_t arg);

/*!
 * \fn void sedi_pm_handle_events(void)
 * \brief Handle D3/BME or reset events. It would be called in a thread loop
 * with high priority. A hook function __pm_reset_prep_callback() which is
 * provided by PMA service would be invoked to notify the thread when D3 or
 * reset event received.
 * \return void
 */
void sedi_pm_handle_events(void);

/*!
 * \fn int32_t sedi_pm_register_callback(sedi_pm_callback_config_t
 * *callback_config)
 * \brief register callback functions for apps and PMA
 * \param[in] callback_config: the pointer to sedi_pm_callback_config_t, include
 * callback type, callback function pointer and priority
 * \return 0 or error codes
 */
int32_t sedi_pm_register_callback(sedi_pm_callback_config_t *callback_config);

/*!
 * \fn int32_t sedi_pm_vnn_request(IN vnn_id_t id, IN int32_t enable)
 * \brief request/release SoC VNN resource
 * \param[in] id: vnn_id_t for device
 * \param[in] enable: 1 for request, 0 for release
 * \return 0 or error codes
 */
int32_t sedi_pm_vnn_request(IN vnn_id_t id, IN int32_t enable);

/*!
 * \fn sedi_hw_rev_t sedi_pm_get_hw_rev(void)
 * \brief Get HW Rev
 * \return HW Rev or SEDI_HW_REV_INVALID
 */
static inline sedi_hw_rev_t sedi_pm_get_hw_rev(void)
{
	uint32_t val;
	sedi_hw_rev_t ret;

	val = read32(SEDI_HW_REVID);
	switch (val) {
	case SEDI_HW_REVID_A0:
		ret = SEDI_HW_REV_A0;
		break;
	case SEDI_HW_REVID_B0:
		ret = SEDI_HW_REV_B0;
		break;
	default:
		ret = SEDI_HW_REV_INVALID;
		break;
	}

	return ret;
}

/*!
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* _SEDI_DRIVER_PM_H_*/
