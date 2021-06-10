/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _IPC_BSP_H_
#define _IPC_BSP_H_

#include <sedi.h>

#define SEDI_IPC_API_VERSION 0
/* driver version */
#define SEDI_IPC_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/* IPC register description */
typedef struct {
	__IO_RW uint32_t pisr_in;                       /**<PISR_*2OSE */
	__IO_RW uint32_t pimr_in;                       /**<PIMR_*2OSE */
	__IO_RW uint32_t pimr_out;                      /**<PIMR_*OSE2 */
	__IO_RW uint32_t pisr_out;                      /**<PISR_*OSE2 */
	__IO_RW uint32_t channel_intr_en;               /**<CIM_PSE */
	__IO_RW uint32_t channel_intr_st;               /**<CIS_PSE */

	__IO_R uint32_t reserved0[(0x48 - 0x18) >> 2];
	__IO_RW uint32_t drbl_in;                       /**< *2OSE DOORBELL */

	__IO_R uint32_t reserved1[2];
	__IO_RW uint32_t drbl_out;                      /**< OSE2* DOORBELL */

	__IO_R uint32_t reserved2[2];
	__IO_RW uint8_t msgs_out[IPC_DATA_LEN_MAX];     /**< OSE2* MSG */
	__IO_RW uint8_t msgs_in[IPC_DATA_LEN_MAX];      /**< *2OSE MSG */

	__IO_R uint32_t reserved3[(0x378 - 0x160) >> 2];
	__IO_RW uint32_t ipc_busy_clear_lh2ose;
} ipc_reg_t;

/*!
 * \union sedi_fwst_stat_reg_t
 * \brief Bit field for firmware status register
 * \ingroup sedi_driver_pm
 */
typedef union {
	struct {
		/**< IPC reset sync */
		uint32_t ilup : 1;
		/**< HECI is up */
		uint32_t hup : 1;
		/**< in case of fatal error, refer to sedi_pm_fail_reason_t */
		uint32_t fail_reason : 4;
		uint32_t reserved1 : 2;
		/**< PSE reset count, incremented by ROM on each PSE Reset */
		uint32_t reset_id : 4;
		/**< progress of FW */
		uint32_t fw_state : 4;
		/**< marking the Host not to go to D3 */
		uint32_t dma0_in_progress : 1;
		uint32_t dma1_in_progress : 1;
		uint32_t dma2_in_progress : 1;
		uint32_t dma3_in_progress : 1;
		/**< PSE power state, refer to sedi_pse_pwr_state_t */
		uint32_t pse_power_state : 4;
		/**< progress of AON task, refer to sedi_aon_checkpoints_t */
		uint32_t aon_checkpoints : 3;
		uint32_t reserved2 : 4;
		uint32_t sv_reserved : 1;
	} bits;
	uint32_t dw;
} sedi_fwst_stat_reg_t;

#define IPC_OSE2PEER_FWSTS 0x34
#define IPC_D0I3C_REG 0x6D0
#define IPC_D0I3C_INT_BIT 0
#define IPC_D0I3C_STATUS_BIT 2

#define IPC_OWNERSHIP_REG_OFFSET 0x900
#define IPC_OWNERSHIP_BIT_FILED_LEN 4
#define IPC_OWNERSHIP_INTR_MASK (1 << (IPC_OWNERSHIP_BIT_FILED_LEN - 1))
#define IPC_OWNERSHIP_OWNER_MASK (IPC_OWNERSHIP_INTR_MASK - 1)
#define IPC_OWNERSHIP_DEV_OFF 1
#define IPC_OWNERSHIP_DEV_MSK 1
#define IPC_DEV_OWNED_BY_PSE_BITS 0x0
#define IPC_DEV_OWNED_BY_HOST_BITS 0x1
#define IPC_HOST_DEV_MSI_INT 0x0
#define IPC_HOST_DEV_SB_INT 0x1

#define IPC_BUSY_BIT 31
#define IPC_INT_STAT_BIT 0
#define IPC_INT_MASK_IN_BIT 0
#define IPC_INT_MASK_BC_BIT 11
#define IPC_INT_MASK_OUT_BIT 0

#define IPC_REG_SB_OSE2PMC_DRBL 0x1804
#define IPC_REG_SB_OSE2PMC_MSG 0x1808
#define IPC_REG_SB_PMC2OSE_DRBL_MIRROR 0x1888

#define SINGLE_BIT 1

#define IPC_INT_MASK 0
#define IPC_INT_UNMASK 1
#endif
