/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _IPC_BSP_H_
#define _IPC_BSP_H_

#include <sedi_driver_common.h>
#include <sedi_driver_ipc.h>

#define SEDI_S0Ix_SUPPORT 0
/* TODO: remove this macro and logic while sideband driver is ready */
#undef SEDI_SB_SUPPORT

#define SEDI_IPC_API_VERSION 0
/* driver version */
#define SEDI_IPC_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/* IPC register description */
typedef struct {
	__IO_RW uint32_t pisr_in;                       /**<PISR_*2LOCAL */
	__IO_RW uint32_t pimr_in;                       /**<PIMR_*2LOCAL */
	__IO_RW uint32_t pimr_out;                      /**<PIMR_*LOCAL2 */
	__IO_RW uint32_t pisr_out;                      /**<PISR_*LOCAL2 */
	__IO_RW uint32_t channel_intr_mask;             /**<CIM */
	__IO_RW uint32_t channel_intr_st;               /**<CIS */
	__IO_R uint32_t reserved0[(0x48 - 0x18) >> 2];
	__IO_RW uint32_t drbl_in;                       /**< *2LOCAL DOORBELL */
	__IO_R uint32_t reserved1[2];
	__IO_RW uint32_t drbl_out;                      /**< LOCAL2* DOORBELL */
	__IO_R uint32_t reserved2[2];
	__IO_RW uint32_t msgs_out[IPC_DATA_LEN_MAX>>2];     /**< LOCAL2* MSG */
	__IO_RW uint32_t msgs_in[IPC_DATA_LEN_MAX>>2];      /**< *2LOCAL MSG */
	__IO_R uint32_t reserved3[(0x378 - 0x160) >> 2];
	__IO_RW uint32_t ipc_busy_clear_peer2local;
	__IO_R uint32_t reserved4[(0x6d4 - 0x37c) >> 2];
	__IO_RW uint32_t csr;
} ipc_reg_t;

#define IPC_LOCAL2PEER_FWSTS 0x34
#define IPC_D0I3C_REG 0x6D0
#define IPC_D0I3C_INT_BIT 0
#define IPC_D0I3C_STATUS_BIT 2

#define IPC_BUSY_BIT 31
#define IPC_INT_STAT_BIT 0
#define IPC_INT_MASK_IN_BIT 0
#define IPC_INT_MASK_BC_BIT 11
#define IPC_INT_MASK_OUT_BIT 0

#define IPC_REG_SB_LOCAL2PMC_DRBL 0x1804
#define IPC_REG_SB_LOCAL2PMC_MSG 0x1808
#define IPC_REG_SB_PMC2LOCAL_DRBL_MIRROR 0x1888
#define IPC_REG_SB_PMC2LOCAL_DRBL_MIRROR 0x1888

#define IPC_REG_SB_LOCAL2CSE_CSR 0x3c
#define IPC_REG_SB_LOCAL2CSE_DRBL 0x0
#define IPC_REG_SB_LOCAL2CSE_MSG 0x40
#define IPC_REG_SB_CSE2LOCAL_DRBL_MIRROR 0x4

#define SINGLE_BIT 1

#define IPC_INT_MASK 0
#define IPC_INT_UNMASK 1
#endif
