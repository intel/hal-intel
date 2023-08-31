/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2023-10-11
 */

#ifndef _SEDI_IPC_REGS_H_
#define _SEDI_IPC_REGS_H_

#include <sedi_reg_defs.h>


/* ********* IPC PISR_AGENT2ISH ***********
 *
 * Register of SEDI IPC
 *   PISR_AGENT2ISH: Peripheral Interrupt Status - IRQ to ISH
 *     AddressOffset  : 0x0
 *     AccessType     : RW
 *     WritableBitMask: 0x8000001
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, PISR_AGENT2ISH, 0x0, RW, (uint32_t)0x8000001, (uint32_t)0x0);

/*
 * Bit Field of Register PISR_AGENT2ISH
 *   AGENT2ISH_DB: Inbound Ipc Request From  AGENT2ISH
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PISR_AGENT2ISH, AGENT2ISH_DB, 0, 1, RO_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PISR_AGENT2ISH, AGENT2ISH_DB, 0, 0);
SEDI_RBFV_DEFINE(IPC, PISR_AGENT2ISH, AGENT2ISH_DB, 1, 1);

/*
 * Bit Field of Register PISR_AGENT2ISH
 *   RESERVED1: Reserved Field
 *     BitOffset : 1
 *     BitWidth  : 26
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PISR_AGENT2ISH, RESERVED1, 1, 26, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PISR_AGENT2ISH
 *   AGENT2ISH_BCISC: AGENT2ISH Busy Clear Interrupt
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PISR_AGENT2ISH, AGENT2ISH_BCISC, 27, 1, RW_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PISR_AGENT2ISH, AGENT2ISH_BCISC, 0, 0);
SEDI_RBFV_DEFINE(IPC, PISR_AGENT2ISH, AGENT2ISH_BCISC, 1, 1);

/*
 * Bit Field of Register PISR_AGENT2ISH
 *   RESERVED0: Reserved Field
 *     BitOffset : 28
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PISR_AGENT2ISH, RESERVED0, 28, 4, RO, (uint32_t)0x0);

/* ********* IPC PIMR_AGENT2ISH ***********
 *
 * Register of SEDI IPC
 *   PIMR_AGENT2ISH: Peripheral Interrupt Mask - IRQ to ISH
 *     AddressOffset  : 0x4
 *     AccessType     : RW
 *     WritableBitMask: 0x8000801
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, PIMR_AGENT2ISH, 0x4, RW, (uint32_t)0x8000801, (uint32_t)0x0);

/*
 * Bit Field of Register PIMR_AGENT2ISH
 *   AGENT2ISH_DB: Reserved Field
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_AGENT2ISH, AGENT2ISH_DB, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PIMR_AGENT2ISH, AGENT2ISH_DB, 0, 0);
SEDI_RBFV_DEFINE(IPC, PIMR_AGENT2ISH, AGENT2ISH_DB, 1, 1);

/*
 * Bit Field of Register PIMR_AGENT2ISH
 *   RESERVED2: Reserved Field
 *     BitOffset : 1
 *     BitWidth  : 10
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_AGENT2ISH, RESERVED2, 1, 10, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PIMR_AGENT2ISH
 *   ISH2AGENT_BC: Mask Bit For ISH2AGENT Busy Clear
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_AGENT2ISH, ISH2AGENT_BC, 11, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PIMR_AGENT2ISH, ISH2AGENT_BC, 0, 0);
SEDI_RBFV_DEFINE(IPC, PIMR_AGENT2ISH, ISH2AGENT_BC, 1, 1);

/*
 * Bit Field of Register PIMR_AGENT2ISH
 *   RESERVED1: Reserved Field
 *     BitOffset : 12
 *     BitWidth  : 15
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_AGENT2ISH, RESERVED1, 12, 15, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PIMR_AGENT2ISH
 *   AGENT2ISH_BCISC: Mask Bit For AGENT2IBCISC
 *     BitOffset : 27
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_AGENT2ISH, AGENT2ISH_BCISC, 27, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PIMR_AGENT2ISH, AGENT2ISH_BCISC, 0, 0);
SEDI_RBFV_DEFINE(IPC, PIMR_AGENT2ISH, AGENT2ISH_BCISC, 1, 1);

/*
 * Bit Field of Register PIMR_AGENT2ISH
 *   RESERVED0: Reserved Field
 *     BitOffset : 28
 *     BitWidth  : 4
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_AGENT2ISH, RESERVED0, 28, 4, RO, (uint32_t)0x0);

/* ********* IPC PIMR_ISH2AGENT ***********
 *
 * Register of SEDI IPC
 *   PIMR_ISH2AGENT: Peripheral Interrupt Mask - IRQ to AGENT
 *     AddressOffset  : 0x8
 *     AccessType     : RW
 *     WritableBitMask: 0x101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, PIMR_ISH2AGENT, 0x8, RW, (uint32_t)0x101, (uint32_t)0x0);

/*
 * Bit Field of Register PIMR_ISH2AGENT
 *   ISH2AGENT_DB: Outbound Ipc Request From ISH2AGENT Mask
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_ISH2AGENT, ISH2AGENT_DB, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PIMR_ISH2AGENT, ISH2AGENT_DB, 0, 0);
SEDI_RBFV_DEFINE(IPC, PIMR_ISH2AGENT, ISH2AGENT_DB, 1, 1);

/*
 * Bit Field of Register PIMR_ISH2AGENT
 *   RESERVED1: Reserved Field
 *     BitOffset : 1
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_ISH2AGENT, RESERVED1, 1, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PIMR_ISH2AGENT
 *   AGENT2ISH_BC: AGENT2ISH Busy Clear Interrupt Mask
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_ISH2AGENT, AGENT2ISH_BC, 8, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PIMR_ISH2AGENT, AGENT2ISH_BC, 0, 0);
SEDI_RBFV_DEFINE(IPC, PIMR_ISH2AGENT, AGENT2ISH_BC, 1, 1);

/*
 * Bit Field of Register PIMR_ISH2AGENT
 *   RESERVED0: Reserved Field
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PIMR_ISH2AGENT, RESERVED0, 9, 23, RO, (uint32_t)0x0);

/* ********* IPC PISR_ISH2AGENT ***********
 *
 * Register of SEDI IPC
 *   PISR_ISH2AGENT: Peripheral Interrupt Status - IRQ to AGENT
 *     AddressOffset  : 0x0c
 *     AccessType     : RW
 *     WritableBitMask: 0x101
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, PISR_ISH2AGENT, 0x0c, RW, (uint32_t)0x101, (uint32_t)0x0);

/*
 * Bit Field of Register PISR_ISH2AGENT
 *   ISH2AGENT_DB: Outbound Ipc Request From ISH2AGENT Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PISR_ISH2AGENT, ISH2AGENT_DB, 0, 1, RO_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PISR_ISH2AGENT, ISH2AGENT_DB, 0, 0);
SEDI_RBFV_DEFINE(IPC, PISR_ISH2AGENT, ISH2AGENT_DB, 1, 1);

/*
 * Bit Field of Register PISR_ISH2AGENT
 *   RESERVED1: Reserved Field
 *     BitOffset : 1
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PISR_ISH2AGENT, RESERVED1, 1, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register PISR_ISH2AGENT
 *   AGENT2ISH_BC: AGENT2ISH Busy Clear Interrupt Status
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RW_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PISR_ISH2AGENT, AGENT2ISH_BC, 8, 1, RW_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, PISR_ISH2AGENT, AGENT2ISH_BC, 0, 0);
SEDI_RBFV_DEFINE(IPC, PISR_ISH2AGENT, AGENT2ISH_BC, 1, 1);

/*
 * Bit Field of Register PISR_ISH2AGENT
 *   RESERVED0: Reserved Field
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, PISR_ISH2AGENT, RESERVED0, 9, 23, RO, (uint32_t)0x0);

/* ********* IPC CIM_AGENT ***********
 *
 * Register of SEDI IPC
 *   CIM_AGENT: AGENT Channel Interrupt Mask
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, CIM_AGENT, 0x10, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register CIM_AGENT
 *   CH_INTR_MASK: Channel Intrupt Mask
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, CIM_AGENT, CH_INTR_MASK, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, CIM_AGENT, CH_INTR_MASK, 0, 0);
SEDI_RBFV_DEFINE(IPC, CIM_AGENT, CH_INTR_MASK, 1, 1);

/*
 * Bit Field of Register CIM_AGENT
 *   RESERVED0: Reserved Field
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, CIM_AGENT, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* IPC CIS_AGENT ***********
 *
 * Register of SEDI IPC
 *   CIS_AGENT: AGENT Channel Interrupt Status
 *     AddressOffset  : 0x14
 *     AccessType     : RO
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, CIS_AGENT, 0x14, RO, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register CIS_AGENT
 *   CH_INTR_STATUS: Channel Interrupt Status
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, CIS_AGENT, CH_INTR_STATUS, 0, 1, RO_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, CIS_AGENT, CH_INTR_STATUS, 0, 0);
SEDI_RBFV_DEFINE(IPC, CIS_AGENT, CH_INTR_STATUS, 1, 1);

/*
 * Bit Field of Register CIS_AGENT
 *   RESERVED0: Reserved Field
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, CIS_AGENT, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* IPC ISH_AGENT_FWSTS_AGENT ***********
 *
 * Register of SEDI IPC
 *   ISH_AGENT_FWSTS_AGENT: AGENT Firmware Status
 *     AddressOffset  : 0x34
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, ISH_AGENT_FWSTS_AGENT, 0x34, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AGENT_FWSTS_AGENT
 *   ISH_AGENT_FWSTS: AGENT Firmware Status Register
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, ISH_AGENT_FWSTS_AGENT, ISH_AGENT_FWSTS, 0, 32, RW, (uint32_t)0x0);

/* ********* IPC ISH_AGENT_COMM_AGENT ***********
 *
 * Register of SEDI IPC
 *   ISH_AGENT_COMM_AGENT: AGENT Communication
 *     AddressOffset  : 0x38
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, ISH_AGENT_COMM_AGENT, 0x38, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_AGENT_COMM_AGENT
 *   AGENT_COMM: AGENT Communication Register
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, ISH_AGENT_COMM_AGENT, AGENT_COMM, 0, 32, RW, (uint32_t)0x0);

/* ********* IPC AGENT2ISH_DOORBELL_AGENT ***********
 *
 * Register of SEDI IPC
 *   AGENT2ISH_DOORBELL_AGENT: Inbound Doorbell AGENT To ISH
 *     AddressOffset  : 0x48
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, AGENT2ISH_DOORBELL_AGENT, 0x48, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register AGENT2ISH_DOORBELL_AGENT
 *   PAYLOAD_31BIT: AGENT2ISH Doorbell Payload
 *     BitOffset : 0
 *     BitWidth  : 31
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, AGENT2ISH_DOORBELL_AGENT, PAYLOAD_31BIT, 0, 31, RW, (uint32_t)0x0);

/*
 * Bit Field of Register AGENT2ISH_DOORBELL_AGENT
 *   BUSY: AGENT2ISH Doorbell Busy Bit
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, AGENT2ISH_DOORBELL_AGENT, BUSY, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, AGENT2ISH_DOORBELL_AGENT, BUSY, 0, 0);
SEDI_RBFV_DEFINE(IPC, AGENT2ISH_DOORBELL_AGENT, BUSY, 1, 1);

/* ********* IPC ISH2AGENT_DOORBELL_AGENT ***********
 *
 * Register of SEDI IPC
 *   ISH2AGENT_DOORBELL_AGENT: Outbound DoorbellISH To AGENT
 *     AddressOffset  : 0x54
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, ISH2AGENT_DOORBELL_AGENT, 0x54, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register ISH2AGENT_DOORBELL_AGENT
 *   PAYLOAD_31BIT: ISH2AGENT Doorbell Payload
 *     BitOffset : 0
 *     BitWidth  : 31
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, ISH2AGENT_DOORBELL_AGENT, PAYLOAD_31BIT, 0, 31, RW, (uint32_t)0x0);

/*
 * Bit Field of Register ISH2AGENT_DOORBELL_AGENT
 *   BUSY: ISH2AGENT Doorbell  Busy
 *     BitOffset : 31
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, ISH2AGENT_DOORBELL_AGENT, BUSY, 31, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, ISH2AGENT_DOORBELL_AGENT, BUSY, 0, 0);
SEDI_RBFV_DEFINE(IPC, ISH2AGENT_DOORBELL_AGENT, BUSY, 1, 1);

/* ********* IPC ISH2AGENT_MSG_AGENT ***********
 *
 * Register of SEDI IPC
 *   ISH2AGENT_MSG_AGENT: Outbound Inter Processor Message 1 From ISH To AGENT
 *     AddressOffset  : 0x60
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, ISH2AGENT_MSG_AGENT, 0x60, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register ISH2AGENT_MSG_AGENT
 *   MSG: Outbound message register from ISH to AGENT
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, ISH2AGENT_MSG_AGENT, MSG, 0, 32, RW, (uint32_t)0x0);

/* ********* IPC AGENT2ISH_MSG_AGENT ***********
 *
 * Register of SEDI IPC
 *   AGENT2ISH_MSG_AGENT: Inbound Inter Processor Message 1 From AGENT To ISH
 *     AddressOffset  : 0xe0
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, AGENT2ISH_MSG_AGENT, 0xe0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register AGENT2ISH_MSG_AGENT
 *   MSG: Inbound message register from AGENT to ISH
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, AGENT2ISH_MSG_AGENT, MSG, 0, 32, RW, (uint32_t)0x0);

/* ********* IPC REMAP_AGENT ***********
 *
 * Register of SEDI IPC
 *   REMAP_AGENT: Remap0 For AGENT
 *     AddressOffset  : 0x360
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, REMAP_AGENT, 0x360, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register REMAP_AGENT
 *   REMAP: Remap Address Register
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, REMAP_AGENT, REMAP, 0, 32, RW, (uint32_t)0x0);

/* ********* IPC ISH_IPC_BUSY_CLEAR_AGENT ***********
 *
 * Register of SEDI IPC
 *   ISH_IPC_BUSY_CLEAR_AGENT: ISH IPC Busy Clear For AGENT
 *     AddressOffset  : 0x378
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, ISH_IPC_BUSY_CLEAR_AGENT, 0x378, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register ISH_IPC_BUSY_CLEAR_AGENT
 *   ISH2AGENT_BUSY_CLEAR: Busy Clear Interrupt From ISH2AGENT
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, ISH_IPC_BUSY_CLEAR_AGENT, ISH2AGENT_BUSY_CLEAR, 0, 1, RW_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, ISH_IPC_BUSY_CLEAR_AGENT, ISH2AGENT_BUSY_CLEAR, 0, 0);
SEDI_RBFV_DEFINE(IPC, ISH_IPC_BUSY_CLEAR_AGENT, ISH2AGENT_BUSY_CLEAR, 1, 1);

/*
 * Bit Field of Register ISH_IPC_BUSY_CLEAR_AGENT
 *   RESERVED0: Reserved Field
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, ISH_IPC_BUSY_CLEAR_AGENT, RESERVED0, 1, 31, RO, (uint32_t)0x0);

/* ********* IPC IPC_D0I3C_AGENT ***********
 *
 * Register of SEDI IPC
 *   IPC_D0I3C_AGENT: D0i3 Control For AGENT
 *     AddressOffset  : 0x6d0
 *     AccessType     : RW
 *     WritableBitMask: 0x1f
 *     ResetValue     : (uint32_t)0x8
 */
SEDI_REG_DEFINE(IPC, IPC_D0I3C_AGENT, 0x6d0, RW, (uint32_t)0x1f, (uint32_t)0x8);

/*
 * Bit Field of Register IPC_D0I3C_AGENT
 *   CIP: Command In Progress
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, IPC_D0I3C_AGENT, CIP, 0, 1, RW_1C_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, CIP, 0, 0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, CIP, 1, 1);

/*
 * Bit Field of Register IPC_D0I3C_AGENT
 *   IR: Interrupt Required
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, IPC_D0I3C_AGENT, IR, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, IR, 0, 0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, IR, 1, 1);

/*
 * Bit Field of Register IPC_D0I3C_AGENT
 *   D0i3: D0i3 State
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, IPC_D0I3C_AGENT, D0i3, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, D0i3, 0, 0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, D0i3, 1, 1);

/*
 * Bit Field of Register IPC_D0I3C_AGENT
 *   RR: Restore Required
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW_1C
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(IPC, IPC_D0I3C_AGENT, RR, 3, 1, RW_1C, (uint32_t)0x1);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, RR, 0, 0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, RR, 1, 1);

/*
 * Bit Field of Register IPC_D0I3C_AGENT
 *   IRC: Interrupt Request Capable
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, IPC_D0I3C_AGENT, IRC, 4, 1, RO_V, (uint32_t)0x0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, IRC, 0, 0);
SEDI_RBFV_DEFINE(IPC, IPC_D0I3C_AGENT, IRC, 1, 1);

/*
 * Bit Field of Register IPC_D0I3C_AGENT
 *   RESERVED0: Reserved
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, IPC_D0I3C_AGENT, RESERVED0, 5, 27, RO, (uint32_t)0x0);

/* ********* IPC AGENT2ISH_CSR_AGENT ***********
 *
 * Register of SEDI IPC
 *   AGENT2ISH_CSR_AGENT: AGENT To ISH Control Status
 *     AddressOffset  : 0x6d4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, AGENT2ISH_CSR_AGENT, 0x6d4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register AGENT2ISH_CSR_AGENT
 *   CSR: Control Status
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_1S_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, AGENT2ISH_CSR_AGENT, CSR, 0, 32, RW_1S_V, (uint32_t)0x0);

/* ********* IPC AGENT2ISH_CSR_CLR_AGENT ***********
 *
 * Register of SEDI IPC
 *   AGENT2ISH_CSR_CLR_AGENT: AGENT To ISH Status Clear
 *     AddressOffset  : 0x6d8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, AGENT2ISH_CSR_CLR_AGENT, 0x6d8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register AGENT2ISH_CSR_CLR_AGENT
 *   CSR: Status Clear
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW_1C_V
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, AGENT2ISH_CSR_CLR_AGENT, CSR, 0, 32, RW_1C_V, (uint32_t)0x0);

/* ********* IPC SPARE ***********
 *
 * Register of SEDI IPC
 *   SPARE: Spare Register
 *     AddressOffset  : 0x700
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(IPC, SPARE, 0x700, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register SPARE
 *   SPARE: Spare
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(IPC, SPARE, SPARE, 0, 32, RW, (uint32_t)0x0);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* Peripheral Interrupt Status - IRQ to ISH */
	__IO_RW uint32_t pisr_agent2ish;

	/* Peripheral Interrupt Mask - IRQ to ISH */
	__IO_RW uint32_t pimr_agent2ish;

	/* Peripheral Interrupt Mask - IRQ to AGENT */
	__IO_RW uint32_t pimr_ish2agent;

	/* Peripheral Interrupt Status - IRQ to AGENT */
	__IO_RW uint32_t pisr_ish2agent;

	/* AGENT Channel Interrupt Mask */
	__IO_RW uint32_t cim_agent;

	/* AGENT Channel Interrupt Status */
	__IO_R uint32_t cis_agent;

	/* Reserved */
	__IO_RW uint32_t reserved0[7];

	/* AGENT Firmware Status */
	__IO_RW uint32_t ish_agent_fwsts_agent;

	/* AGENT Communication */
	__IO_RW uint32_t ish_agent_comm_agent;

	/* Reserved */
	__IO_RW uint32_t reserved1[3];

	/* Inbound Doorbell AGENT To ISH */
	__IO_RW uint32_t agent2ish_doorbell_agent;

	/* Reserved */
	__IO_RW uint32_t reserved2[2];

	/* Outbound DoorbellISH To AGENT */
	__IO_RW uint32_t ish2agent_doorbell_agent;

	/* Reserved */
	__IO_RW uint32_t reserved3[2];

	/* Outbound Inter Processor Message 1 From ISH To AGENT */
	__IO_RW uint32_t ish2agent_msg_agent[32];

	/* Inbound Inter Processor Message 1 From AGENT To ISH */
	__IO_RW uint32_t agent2ish_msg_agent[32];

	/* Reserved */
	__IO_RW uint32_t reserved4[128];

	/* Remap0 For AGENT */
	__IO_RW uint32_t remap_agent[6];

	/* ISH IPC Busy Clear For AGENT */
	__IO_RW uint32_t ish_ipc_busy_clear_agent;

	/* Reserved */
	__IO_RW uint32_t reserved5[213];

	/* D0i3 Control For AGENT */
	__IO_RW uint32_t ipc_d0i3c_agent;

	/* AGENT To ISH Control Status */
	__IO_RW uint32_t agent2ish_csr_agent;

	/* AGENT To ISH Status Clear */
	__IO_RW uint32_t agent2ish_csr_clr_agent;

	/* Reserved */
	__IO_RW uint32_t reserved6[9];

	/* Spare Register */
	__IO_RW uint32_t spare;

} sedi_ipc_regs_t;


#endif /* _SEDI_IPC_REGS_H_ */
