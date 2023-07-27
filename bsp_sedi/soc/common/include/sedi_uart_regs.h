/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2023-07-27
 */

#ifndef _SEDI_UART_REGS_H_
#define _SEDI_UART_REGS_H_

#include <sedi_reg_defs.h>


/* ********* UART RBR ***********
 *
 * Register of SEDI UART
 *   RBR: Receive Buffer Register
 *     AddressOffset  : 0x0
 *     AccessType     : RW
 *     WritableBitMask: 0xfe
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, RBR, 0x0, RW, (uint32_t)0xfe, (uint32_t)0x0);

/*
 * Bit Field of Register RBR
 *   DLS:
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RBR, DLS, 0, 2, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RBR, DLS, CHAR_5BITS, 0x0);
SEDI_RBFV_DEFINE(UART, RBR, DLS, CHAR_6BITS, 0x1);
SEDI_RBFV_DEFINE(UART, RBR, DLS, CHAR_7BITS, 0x2);
SEDI_RBFV_DEFINE(UART, RBR, DLS, CHAR_8BITS, 0x3);

/*
 * Bit Field of Register RBR
 *   STOP:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RBR, STOP, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RBR, STOP, STOP_1BIT, 0x0);
SEDI_RBFV_DEFINE(UART, RBR, STOP, STOP_1_5BIT_OR_2BIT, 0x1);

/*
 * Bit Field of Register RBR
 *   PEN:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RBR, PEN, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RBR, PEN, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RBR, PEN, ENABLED, 0x1);

/*
 * Bit Field of Register RBR
 *   EPS:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RBR, EPS, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RBR, EPS, EVEN_PARITY, 0x1);
SEDI_RBFV_DEFINE(UART, RBR, EPS, ODD_PARITY, 0x0);

/*
 * Bit Field of Register RBR
 *   SP:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RBR, SP, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RBR, SP, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RBR, SP, ENABLED, 0x1);

/*
 * Bit Field of Register RBR
 *   BC:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RBR, BC, 6, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RBR, BC, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RBR, BC, ENABLED, 0x1);

/*
 * Bit Field of Register RBR
 *   DLAB:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RBR, DLAB, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RBR, DLAB, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RBR, DLAB, ENABLED, 0x1);

/*
 * Bit Field of Register RBR
 *   RSVD_LCR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RBR, RSVD_LCR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART IER ***********
 *
 * Register of SEDI UART
 *   IER: Interrupt Enable Register
 *     AddressOffset  : 0x4
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, IER, 0x4, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register IER
 *   DTR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IER, DTR, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, DTR, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(UART, IER, DTR, INACTIVE, 0x0);

/*
 * Bit Field of Register IER
 *   RTS:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IER, RTS, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, RTS, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(UART, IER, RTS, INACTIVE, 0x0);

/*
 * Bit Field of Register IER
 *   OUT1:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IER, OUT1, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, OUT1, OUT1_0, 0x0);
SEDI_RBFV_DEFINE(UART, IER, OUT1, OUT1_1, 0x1);

/*
 * Bit Field of Register IER
 *   OUT2:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IER, OUT2, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, OUT2, OUT2_0, 0x0);
SEDI_RBFV_DEFINE(UART, IER, OUT2, OUT2_1, 0x1);

/*
 * Bit Field of Register IER
 *   LoopBack:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IER, LoopBack, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, LoopBack, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, IER, LoopBack, ENABLED, 0x1);

/*
 * Bit Field of Register IER
 *   AFCE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IER, AFCE, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, AFCE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, IER, AFCE, ENABLED, 0x1);

/*
 * Bit Field of Register IER
 *   SIRE:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IER, SIRE, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, SIRE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, IER, SIRE, ENABLED, 0x1);

/*
 * Bit Field of Register IER
 *   RSVD_MCR_31to7:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IER, RSVD_MCR_31to7, 7, 25, RO, (uint32_t)0x0);

/* ********* UART IIR ***********
 *
 * Register of SEDI UART
 *   IIR: Interrupt Identification Register
 *     AddressOffset  : 0x8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x60
 */
SEDI_REG_DEFINE(UART, IIR, 0x8, RO, (uint32_t)0x0, (uint32_t)0x60);

/*
 * Bit Field of Register IIR
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IIR, DR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, DR, NOT_READY, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, DR, READY, 0x1);

/*
 * Bit Field of Register IIR
 *   OE:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IIR, OE, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, OE, NO_OVER_RUN_ERROR, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, OE, OVER_RUN_ERROR, 0x1);

/*
 * Bit Field of Register IIR
 *   PE:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IIR, PE, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, PE, NO_PARITY_ERROR, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, PE, PARITY_ERROR, 0x1);

/*
 * Bit Field of Register IIR
 *   FE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IIR, FE, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, FE, FRAMING_ERROR, 0x1);
SEDI_RBFV_DEFINE(UART, IIR, FE, NO_FRAMING_ERROR, 0x0);

/*
 * Bit Field of Register IIR
 *   BI:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IIR, BI, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, BI, BREAK, 0x1);
SEDI_RBFV_DEFINE(UART, IIR, BI, NO_BREAK, 0x0);

/*
 * Bit Field of Register IIR
 *   THRE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, IIR, THRE, 5, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, IIR, THRE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, THRE, ENABLED, 0x1);

/*
 * Bit Field of Register IIR
 *   TEMT:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, IIR, TEMT, 6, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, IIR, TEMT, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, TEMT, ENABLED, 0x1);

/*
 * Bit Field of Register IIR
 *   RFE:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IIR, RFE, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, RFE, NO_RX_FIFO_ERROR, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, RFE, RX_FIFO_ERROR, 0x1);

/*
 * Bit Field of Register IIR
 *   ADDR_RCVD:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IIR, ADDR_RCVD, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, ADDR_RCVD, 0, 0);
SEDI_RBFV_DEFINE(UART, IIR, ADDR_RCVD, 1, 1);

/*
 * Bit Field of Register IIR
 *   RSVD_LSR_31to9:
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, IIR, RSVD_LSR_31to9, 9, 23, RO, (uint32_t)0x0);

/* ********* UART LCR ***********
 *
 * Register of SEDI UART
 *   LCR: Line Control Register
 *     AddressOffset  : 0xc
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, LCR, 0xc, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register LCR
 *   DCTS:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, DCTS, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, DCTS, CHANGE, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, DCTS, NO_CHANGE, 0x0);

/*
 * Bit Field of Register LCR
 *   DDSR:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, DDSR, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, DDSR, CHANGE, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, DDSR, NO_CHANGE, 0x0);

/*
 * Bit Field of Register LCR
 *   TERI:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, TERI, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, TERI, CHANGE, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, TERI, NO_CHANGE, 0x0);

/*
 * Bit Field of Register LCR
 *   DDCD:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, DDCD, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, DDCD, CHANGE, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, DDCD, NO_CHANGE, 0x0);

/*
 * Bit Field of Register LCR
 *   CTS:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, CTS, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, CTS, ASSERTED, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, CTS, DEASSERTED, 0x0);

/*
 * Bit Field of Register LCR
 *   DSR:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, DSR, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, DSR, ASSERTED, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, DSR, DEASSERTED, 0x0);

/*
 * Bit Field of Register LCR
 *   RI:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, RI, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, RI, ASSERTED, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, RI, DEASSERTED, 0x0);

/*
 * Bit Field of Register LCR
 *   DCD:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, DCD, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, DCD, ASSERTED, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, DCD, DEASSERTED, 0x0);

/*
 * Bit Field of Register LCR
 *   RSVD_MSR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, RSVD_MSR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART MCR ***********
 *
 * Register of SEDI UART
 *   MCR: Modem Control Register
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x80
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, MCR, 0x10, RW, (uint32_t)0x80, (uint32_t)0x0);

/*
 * Bit Field of Register MCR
 *   SCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, SCR, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register MCR
 *   RSVD_SCR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, RSVD_SCR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART LSR ***********
 *
 * Register of SEDI UART
 *   LSR: Line Status Register
 *     AddressOffset  : 0x14
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, LSR, 0x14, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register LSR
 *   FAR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, FAR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LSR, FAR, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, LSR, FAR, ENABLED, 0x1);

/*
 * Bit Field of Register LSR
 *   RSVD_FAR_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, RSVD_FAR_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART MSR ***********
 *
 * Register of SEDI UART
 *   MSR: Modem Status Register
 *     AddressOffset  : 0x18
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x6
 */
SEDI_REG_DEFINE(UART, MSR, 0x18, RO, (uint32_t)0x0, (uint32_t)0x6);

/*
 * Bit Field of Register MSR
 *   RSVD_BUSY:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, RSVD_BUSY, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, RSVD_BUSY, BUSY, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, RSVD_BUSY, IDLE, 0x0);

/*
 * Bit Field of Register MSR
 *   TFNF:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, MSR, TFNF, 1, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, MSR, TFNF, FULL, 0x0);
SEDI_RBFV_DEFINE(UART, MSR, TFNF, NOT_FULL, 0x1);

/*
 * Bit Field of Register MSR
 *   TFE:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, MSR, TFE, 2, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, MSR, TFE, EMPTY, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, TFE, NOT_EMPTY, 0x0);

/*
 * Bit Field of Register MSR
 *   RFNE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, RFNE, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, RFNE, EMPTY, 0x0);
SEDI_RBFV_DEFINE(UART, MSR, RFNE, NOT_EMPTY, 0x1);

/*
 * Bit Field of Register MSR
 *   RFF:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, RFF, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, RFF, FULL, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, RFF, NOT_FULL, 0x0);

/*
 * Bit Field of Register MSR
 *   RSVD_USR_31to5:
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, RSVD_USR_31to5, 5, 27, RO, (uint32_t)0x0);

/* ********* UART SCR ***********
 *
 * Register of SEDI UART
 *   SCR: Scratchpad Register
 *     AddressOffset  : 0x1c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, SCR, 0x1c, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register SCR
 *   tfl:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, SCR, tfl, 0, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register SCR
 *   RSVD_TFL_31toADDR_WIDTH:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, SCR, RSVD_TFL_31toADDR_WIDTH, 7, 25, RO, (uint32_t)0x0);

/* ********* UART FAR ***********
 *
 * Register of SEDI UART
 *   FAR: FIFO Access Register
 *     AddressOffset  : 0x70
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, FAR, 0x70, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register FAR
 *   rfl:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, FAR, rfl, 0, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register FAR
 *   RSVD_RFL_31toADDR_WIDTH:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, FAR, RSVD_RFL_31toADDR_WIDTH, 7, 25, RO, (uint32_t)0x0);

/* ********* UART USR ***********
 *
 * Register of SEDI UART
 *   USR: UART Status register
 *     AddressOffset  : 0x7c
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, USR, 0x7c, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register USR
 *   HTX:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, USR, HTX, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, USR, HTX, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, USR, HTX, ENABLED, 0x1);

/*
 * Bit Field of Register USR
 *   RSVD_HTX_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, USR, RSVD_HTX_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART TFL ***********
 *
 * Register of SEDI UART
 *   TFL: Transmit FIFO Level
 *     AddressOffset  : 0x80
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, TFL, 0x80, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register TFL
 *   DMASA:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TFL, DMASA, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, TFL, DMASA, SOFT_ACK, 0x1);

/*
 * Bit Field of Register TFL
 *   RSVD_DMASA_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TFL, RSVD_DMASA_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART RFL ***********
 *
 * Register of SEDI UART
 *   RFL: Receive FIFO Level
 *     AddressOffset  : 0x84
 *     AccessType     : RW
 *     WritableBitMask: 0x17
 *     ResetValue     : (uint32_t)0x6
 */
SEDI_REG_DEFINE(UART, RFL, 0x84, RW, (uint32_t)0x17, (uint32_t)0x6);

/*
 * Bit Field of Register RFL
 *   RS485_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RFL, RS485_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RFL, RS485_EN, 0, 0);
SEDI_RBFV_DEFINE(UART, RFL, RS485_EN, 1, 1);

/*
 * Bit Field of Register RFL
 *   RE_POL:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, RFL, RE_POL, 1, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, RFL, RE_POL, 0, 0);
SEDI_RBFV_DEFINE(UART, RFL, RE_POL, 1, 1);

/*
 * Bit Field of Register RFL
 *   DE_POL:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, RFL, DE_POL, 2, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, RFL, DE_POL, 0, 0);
SEDI_RBFV_DEFINE(UART, RFL, DE_POL, 1, 1);

/*
 * Bit Field of Register RFL
 *   XFER_MODE:
 *     BitOffset : 3
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RFL, XFER_MODE, 3, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register RFL
 *   RSVD_TCR_31to5:
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RFL, RSVD_TCR_31to5, 5, 27, RO, (uint32_t)0x0);

/* ********* UART HTX ***********
 *
 * Register of SEDI UART
 *   HTX: Halt TX
 *     AddressOffset  : 0xa4
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, HTX, 0xa4, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register HTX
 *   DE_Enable:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, HTX, DE_Enable, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, HTX, DE_Enable, 0, 0);
SEDI_RBFV_DEFINE(UART, HTX, DE_Enable, 1, 1);

/*
 * Bit Field of Register HTX
 *   RSVD_DE_EN_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, HTX, RSVD_DE_EN_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART DMASA ***********
 *
 * Register of SEDI UART
 *   DMASA: DMA Software Acknowledge Register
 *     AddressOffset  : 0xa8
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, DMASA, 0xa8, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register DMASA
 *   RE_Enable:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DMASA, RE_Enable, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, DMASA, RE_Enable, 0, 0);
SEDI_RBFV_DEFINE(UART, DMASA, RE_Enable, 1, 1);

/*
 * Bit Field of Register DMASA
 *   RSVD_RE_EN_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DMASA, RSVD_RE_EN_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART TCR ***********
 *
 * Register of SEDI UART
 *   TCR: Transceiver Control Register
 *     AddressOffset  : 0xac
 *     AccessType     : RW
 *     WritableBitMask: 0x800080
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, TCR, 0xac, RW, (uint32_t)0x800080, (uint32_t)0x0);

/*
 * Bit Field of Register TCR
 *   DE_Assertion_Time:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TCR, DE_Assertion_Time, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register TCR
 *   RSVD_DE_AT_15to8:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TCR, RSVD_DE_AT_15to8, 8, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register TCR
 *   DE_De_assertion_Time:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TCR, DE_De_assertion_Time, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register TCR
 *   RSVD_DE_DEAT_31to24:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TCR, RSVD_DE_DEAT_31to24, 24, 8, RO, (uint32_t)0x0);

/* ********* UART DE_EN ***********
 *
 * Register of SEDI UART
 *   DE_EN: Driver Output Enable Register
 *     AddressOffset  : 0xb0
 *     AccessType     : RW
 *     WritableBitMask: 0x80008000
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, DE_EN, 0xb0, RW, (uint32_t)0x80008000, (uint32_t)0x0);

/*
 * Bit Field of Register DE_EN
 *   DE_to_RE:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DE_EN, DE_to_RE, 0, 16, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DE_EN
 *   RE_to_DE:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DE_EN, RE_to_DE, 16, 16, RW, (uint32_t)0x0);

/* ********* UART RE_EN ***********
 *
 * Register of SEDI UART
 *   RE_EN: Receiver Output Enable Register
 *     AddressOffset  : 0xb4
 *     AccessType     : RW
 *     WritableBitMask: 0x8
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, RE_EN, 0xb4, RW, (uint32_t)0x8, (uint32_t)0x0);

/*
 * Bit Field of Register RE_EN
 *   DLF:
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RE_EN, DLF, 0, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register RE_EN
 *   RSVD_DLF:
 *     BitOffset : 4
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RE_EN, RSVD_DLF, 4, 28, RO, (uint32_t)0x0);

/* ********* UART DET ***********
 *
 * Register of SEDI UART
 *   DET: Driver Output Enable Timing Register
 *     AddressOffset  : 0xb8
 *     AccessType     : RW
 *     WritableBitMask: 0x80
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, DET, 0xb8, RW, (uint32_t)0x80, (uint32_t)0x0);

/*
 * Bit Field of Register DET
 *   RAR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DET, RAR, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DET
 *   RSVD_RAR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DET, RSVD_RAR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART TAT ***********
 *
 * Register of SEDI UART
 *   TAT: TurnAround Timing Register
 *     AddressOffset  : 0xbc
 *     AccessType     : RW
 *     WritableBitMask: 0x80
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, TAT, 0xbc, RW, (uint32_t)0x80, (uint32_t)0x0);

/*
 * Bit Field of Register TAT
 *   TAR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TAT, TAR, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register TAT
 *   RSVD_TAR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TAT, RSVD_TAR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART DLF ***********
 *
 * Register of SEDI UART
 *   DLF: Divisor Latch Fraction Register
 *     AddressOffset  : 0xc0
 *     AccessType     : RW
 *     WritableBitMask: 0xf
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, DLF, 0xc0, RW, (uint32_t)0xf, (uint32_t)0x0);

/*
 * Bit Field of Register DLF
 *   DLS_E:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DLF, DLS_E, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, DLF, DLS_E, 0, 0);
SEDI_RBFV_DEFINE(UART, DLF, DLS_E, 1, 1);

/*
 * Bit Field of Register DLF
 *   ADDR_MATCH:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DLF, ADDR_MATCH, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, DLF, ADDR_MATCH, 0, 0);
SEDI_RBFV_DEFINE(UART, DLF, ADDR_MATCH, 1, 1);

/*
 * Bit Field of Register DLF
 *   SEND_ADDR:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DLF, SEND_ADDR, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, DLF, SEND_ADDR, 0, 0);
SEDI_RBFV_DEFINE(UART, DLF, SEND_ADDR, 1, 1);

/*
 * Bit Field of Register DLF
 *   TRANSMIT_MODE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DLF, TRANSMIT_MODE, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, DLF, TRANSMIT_MODE, 0, 0);
SEDI_RBFV_DEFINE(UART, DLF, TRANSMIT_MODE, 1, 1);

/*
 * Bit Field of Register DLF
 *   RSVD_LCR_EXT:
 *     BitOffset : 4
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DLF, RSVD_LCR_EXT, 4, 28, RO, (uint32_t)0x0);

/* ********* UART RAR ***********
 *
 * Register of SEDI UART
 *   RAR: Receive Address Register
 *     AddressOffset  : 0xc4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x43532
 */
SEDI_REG_DEFINE(UART, RAR, 0xc4, RO, (uint32_t)0x0, (uint32_t)0x43532);

/*
 * Bit Field of Register RAR
 *   APB_DATA_WIDTH:
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(UART, RAR, APB_DATA_WIDTH, 0, 2, RO, (uint32_t)0x2);
SEDI_RBFV_DEFINE(UART, RAR, APB_DATA_WIDTH, APB_16BITS, 0x1);
SEDI_RBFV_DEFINE(UART, RAR, APB_DATA_WIDTH, APB_32BITS, 0x2);
SEDI_RBFV_DEFINE(UART, RAR, APB_DATA_WIDTH, APB_8BITS, 0x0);

/*
 * Bit Field of Register RAR
 *   RSVD_CPR_3to2:
 *     BitOffset : 2
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, RSVD_CPR_3to2, 2, 2, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RAR
 *   AFCE_MODE:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, RAR, AFCE_MODE, 4, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, RAR, AFCE_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, AFCE_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   THRE_MODE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, RAR, THRE_MODE, 5, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, RAR, THRE_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, THRE_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   SIR_MODE:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, SIR_MODE, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RAR, SIR_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, SIR_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   SIR_LP_MODE:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, SIR_LP_MODE, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RAR, SIR_LP_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, SIR_LP_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   ADDITIONAL_FEAT:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, RAR, ADDITIONAL_FEAT, 8, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, RAR, ADDITIONAL_FEAT, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, ADDITIONAL_FEAT, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   FIFO_ACCESS:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, FIFO_ACCESS, 9, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_ACCESS, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_ACCESS, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   FIFO_STAT:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, RAR, FIFO_STAT, 10, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_STAT, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_STAT, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   SHADOW:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, SHADOW, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RAR, SHADOW, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, SHADOW, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   UART_ADD_ENCODED_PARAMS:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, RAR, UART_ADD_ENCODED_PARAMS, 12, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, RAR, UART_ADD_ENCODED_PARAMS, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, UART_ADD_ENCODED_PARAMS, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   DMA_EXTRA:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, RAR, DMA_EXTRA, 13, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, RAR, DMA_EXTRA, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, DMA_EXTRA, ENABLED, 0x1);

/*
 * Bit Field of Register RAR
 *   RSVD_CPR_15to14:
 *     BitOffset : 14
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, RSVD_CPR_15to14, 14, 2, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RAR
 *   FIFO_MODE:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x4
 */
SEDI_RBF_DEFINE(UART, RAR, FIFO_MODE, 16, 8, RO, (uint32_t)0x4);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_0, 0x0);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_1024, 0x40);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_128, 0x8);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_16, 0x1);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_2048, 0x80);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_256, 0x10);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_32, 0x2);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_512, 0x20);
SEDI_RBFV_DEFINE(UART, RAR, FIFO_MODE, FIFO_MODE_64, 0x4);

/*
 * Bit Field of Register RAR
 *   RSVD_CPR_31to24:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, RSVD_CPR_31to24, 24, 8, RO, (uint32_t)0x0);

/* ********* UART TAR ***********
 *
 * Register of SEDI UART
 *   TAR: Transmit Address Register
 *     AddressOffset  : 0xc8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x3430322a
 */
SEDI_REG_DEFINE(UART, TAR, 0xc8, RO, (uint32_t)0x0, (uint32_t)0x3430322a);

/*
 * Bit Field of Register TAR
 *   UART_Component_Version:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3430322a
 */
SEDI_RBF_DEFINE(UART, TAR, UART_Component_Version, 0, 32, RO, (uint32_t)0x3430322a);

/* ********* UART LCR_EXT ***********
 *
 * Register of SEDI UART
 *   LCR_EXT: Line Extended Control Register
 *     AddressOffset  : 0xcc
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x44570110
 */
SEDI_REG_DEFINE(UART, LCR_EXT, 0xcc, RO, (uint32_t)0x0, (uint32_t)0x44570110);

/*
 * Bit Field of Register LCR_EXT
 *   Peripheral_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x44570110
 */
SEDI_RBF_DEFINE(UART, LCR_EXT, Peripheral_ID, 0, 32, RO, (uint32_t)0x44570110);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* Line Control Register */
	__IO_R uint32_t lcr;

	/* Modem Control Register */
	__IO_RW uint32_t mcr;

	/* Line Status Register */
	__IO_R uint32_t lsr;

	/* Modem Status Register */
	__IO_R uint32_t msr;

	/* Scratchpad Register */
	__IO_R uint32_t scr;

	/* Reserved */
	__IO_RW uint32_t reserved0[20];

	/* FIFO Access Register */
	__IO_R uint32_t far;

	/* Reserved */
	__IO_RW uint32_t reserved1[2];

	/* UART Status register */
	__IO_RW uint32_t usr;

	/* Transmit FIFO Level */
	__IO_RW uint32_t tfl;

	/* Receive FIFO Level */
	__IO_RW uint32_t rfl;

	/* Reserved */
	__IO_RW uint32_t reserved2[7];

	/* Halt TX */
	__IO_RW uint32_t htx;

	/* DMA Software Acknowledge Register */
	__IO_RW uint32_t dmasa;

	/* Transceiver Control Register */
	__IO_RW uint32_t tcr;

	/* Driver Output Enable Register */
	__IO_RW uint32_t de_en;

	/* Receiver Output Enable Register */
	__IO_RW uint32_t re_en;

	/* Driver Output Enable Timing Register */
	__IO_RW uint32_t det;

	/* TurnAround Timing Register */
	__IO_RW uint32_t tat;

	/* Divisor Latch Fraction Register */
	__IO_RW uint32_t dlf;

	/* Receive Address Register */
	__IO_R uint32_t rar;

	/* Transmit Address Register */
	__IO_R uint32_t tar;

	/* Line Extended Control Register */
	__IO_R uint32_t lcr_ext;

	/* Reserved */
	__IO_RW uint32_t reserved3[9];

	/* Component Parameter Register */
	__IO_R uint32_t cpr;

	/* UART Component Version */
	__IO_R uint32_t ucv;

	/* Component Type Register */
	__IO_R uint32_t ctr;

} sedi_uart_regs_t;


#endif /* _SEDI_UART_REGS_H_ */
