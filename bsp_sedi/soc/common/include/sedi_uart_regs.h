/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * This file has been automatically generated
 * Tool Version: 1.0.0
 * Generation Date: 2023-08-07
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
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, RBR, 0x0, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register RBR
 *
 *     BitOffset :
 *     BitWidth  :
 *     AccessType:
 *     ResetValue:
 */

/* ********* UART IER ***********
 *
 * Register of SEDI UART
 *   IER: Interrupt Enable Register
 *     AddressOffset  : 0x4
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, IER, 0x4, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/**
 * TODO:
 *     the IER register field definitions are missing in the osxml file,
 *     manually added, should fix it in the osxml input.
 **/
SEDI_RBF_DEFINE(UART, IER, ERBFI, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, ERBFI, DISABLE, 0x0);
SEDI_RBFV_DEFINE(UART, IER, ERBFI, ENABLE, 0x1);

SEDI_RBF_DEFINE(UART, IER, ETBEI, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, ETBEI, DISABLE, 0x0);
SEDI_RBFV_DEFINE(UART, IER, ETBEI, ENABLE, 0x1);

SEDI_RBF_DEFINE(UART, IER, ELSI, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, ELSI, DISABLE, 0x9);
SEDI_RBFV_DEFINE(UART, IER, ELSI, ENABLE, 0x1);

SEDI_RBF_DEFINE(UART, IER, PTIME, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IER, PTIME, DISABLE, 0x0);
SEDI_RBFV_DEFINE(UART, IER, PTIME, ENABLE, 0x1);

/*
 * Bit Field of Register IER
 *
 *     BitOffset :
 *     BitWidth  :
 *     AccessType:
 *     ResetValue:
 */

/* ********* UART IIR ***********
 *
 * Register of SEDI UART
 *   IIR: Interrupt Identification Register
 *     AddressOffset  : 0x8
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, IIR, 0x8, RW, (uint32_t)0xffffffff, (uint32_t)0x0);
/**
 * TODO:
 *     the IIR register field definitions are missing in the osxml file,
 *     manually added, should fix it in the osxml input.
 **/
SEDI_RBF_DEFINE(UART, IIR, FIFOE, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, FIFOE, DISABLE, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, FIFOE, ENABLE, 0x1);

SEDI_RBF_DEFINE(UART, IIR, RFIFOR, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, RFIFOR, DISABLE, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, RFIFOR, ENABLE, 0x1);

SEDI_RBF_DEFINE(UART, IIR, XFIFOR, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, IIR, XFIFOR, DISABLE, 0x0);
SEDI_RBFV_DEFINE(UART, IIR, XFIFOR, ENABLE, 0x1);

SEDI_RBF_DEFINE(UART, IIR, IID, 0, 4, RO, 0);

/*
 * Bit Field of Register IIR
 *
 *     BitOffset :
 *     BitWidth  :
 *     AccessType:
 *     ResetValue:
 */

/* ********* UART LCR ***********
 *
 * Register of SEDI UART
 *   LCR: Line Control Register
 *     AddressOffset  : 0xc
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, LCR, 0xc, RW, (uint32_t)0xff, (uint32_t)0x0);

/*
 * Bit Field of Register LCR
 *   DLS:
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, DLS, 0, 2, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, DLS, CHAR_5BITS, 0x0);
SEDI_RBFV_DEFINE(UART, LCR, DLS, CHAR_6BITS, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, DLS, CHAR_7BITS, 0x2);
SEDI_RBFV_DEFINE(UART, LCR, DLS, CHAR_8BITS, 0x3);

/*
 * Bit Field of Register LCR
 *   STOP:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, STOP, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, STOP, STOP_1BIT, 0x0);
SEDI_RBFV_DEFINE(UART, LCR, STOP, STOP_1_5BIT_OR_2BIT, 0x1);

/*
 * Bit Field of Register LCR
 *   PEN:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, PEN, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, PEN, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, LCR, PEN, ENABLED, 0x1);

/*
 * Bit Field of Register LCR
 *   EPS:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, EPS, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, EPS, EVEN_PARITY, 0x1);
SEDI_RBFV_DEFINE(UART, LCR, EPS, ODD_PARITY, 0x0);

/*
 * Bit Field of Register LCR
 *   SP:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, SP, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, SP, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, LCR, SP, ENABLED, 0x1);

/*
 * Bit Field of Register LCR
 *   BC:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, BC, 6, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, BC, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, LCR, BC, ENABLED, 0x1);

/*
 * Bit Field of Register LCR
 *   DLAB:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, DLAB, 7, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR, DLAB, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, LCR, DLAB, ENABLED, 0x1);

/*
 * Bit Field of Register LCR
 *   RSVD_LCR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR, RSVD_LCR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART MCR ***********
 *
 * Register of SEDI UART
 *   MCR: Modem Control Register
 *     AddressOffset  : 0x10
 *     AccessType     : RW
 *     WritableBitMask: 0x3f
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, MCR, 0x10, RW, (uint32_t)0x3f, (uint32_t)0x0);

/*
 * Bit Field of Register MCR
 *   DTR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, DTR, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MCR, DTR, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(UART, MCR, DTR, INACTIVE, 0x0);

/*
 * Bit Field of Register MCR
 *   RTS:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, RTS, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MCR, RTS, ACTIVE, 0x1);
SEDI_RBFV_DEFINE(UART, MCR, RTS, INACTIVE, 0x0);

/*
 * Bit Field of Register MCR
 *   OUT1:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, OUT1, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MCR, OUT1, OUT1_0, 0x0);
SEDI_RBFV_DEFINE(UART, MCR, OUT1, OUT1_1, 0x1);

/*
 * Bit Field of Register MCR
 *   OUT2:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, OUT2, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MCR, OUT2, OUT2_0, 0x0);
SEDI_RBFV_DEFINE(UART, MCR, OUT2, OUT2_1, 0x1);

/*
 * Bit Field of Register MCR
 *   LoopBack:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, LoopBack, 4, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MCR, LoopBack, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, MCR, LoopBack, ENABLED, 0x1);

/*
 * Bit Field of Register MCR
 *   AFCE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, AFCE, 5, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MCR, AFCE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, MCR, AFCE, ENABLED, 0x1);

/*
 * Bit Field of Register MCR
 *   SIRE:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, SIRE, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MCR, SIRE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, MCR, SIRE, ENABLED, 0x1);

/*
 * Bit Field of Register MCR
 *   RSVD_MCR_31to7:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MCR, RSVD_MCR_31to7, 7, 25, RO, (uint32_t)0x0);

/* ********* UART LSR ***********
 *
 * Register of SEDI UART
 *   LSR: Line Status Register
 *     AddressOffset  : 0x14
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x60
 */
SEDI_REG_DEFINE(UART, LSR, 0x14, RO, (uint32_t)0x0, (uint32_t)0x60);

/*
 * Bit Field of Register LSR
 *   DR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, DR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LSR, DR, NOT_READY, 0x0);
SEDI_RBFV_DEFINE(UART, LSR, DR, READY, 0x1);

/*
 * Bit Field of Register LSR
 *   OE:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, OE, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LSR, OE, NO_OVER_RUN_ERROR, 0x0);
SEDI_RBFV_DEFINE(UART, LSR, OE, OVER_RUN_ERROR, 0x1);

/*
 * Bit Field of Register LSR
 *   PE:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, PE, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LSR, PE, NO_PARITY_ERROR, 0x0);
SEDI_RBFV_DEFINE(UART, LSR, PE, PARITY_ERROR, 0x1);

/*
 * Bit Field of Register LSR
 *   FE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, FE, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LSR, FE, FRAMING_ERROR, 0x1);
SEDI_RBFV_DEFINE(UART, LSR, FE, NO_FRAMING_ERROR, 0x0);

/*
 * Bit Field of Register LSR
 *   BI:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, BI, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LSR, BI, BREAK, 0x1);
SEDI_RBFV_DEFINE(UART, LSR, BI, NO_BREAK, 0x0);

/*
 * Bit Field of Register LSR
 *   THRE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, LSR, THRE, 5, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, LSR, THRE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, LSR, THRE, ENABLED, 0x1);

/*
 * Bit Field of Register LSR
 *   TEMT:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, LSR, TEMT, 6, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, LSR, TEMT, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, LSR, TEMT, ENABLED, 0x1);

/*
 * Bit Field of Register LSR
 *   RFE:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, RFE, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LSR, RFE, NO_RX_FIFO_ERROR, 0x0);
SEDI_RBFV_DEFINE(UART, LSR, RFE, RX_FIFO_ERROR, 0x1);

/*
 * Bit Field of Register LSR
 *   ADDR_RCVD:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, ADDR_RCVD, 8, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LSR, ADDR_RCVD, 0, 0);
SEDI_RBFV_DEFINE(UART, LSR, ADDR_RCVD, 1, 1);

/*
 * Bit Field of Register LSR
 *   RSVD_LSR_31to9:
 *     BitOffset : 9
 *     BitWidth  : 23
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LSR, RSVD_LSR_31to9, 9, 23, RO, (uint32_t)0x0);

/* ********* UART MSR ***********
 *
 * Register of SEDI UART
 *   MSR: Modem Status Register
 *     AddressOffset  : 0x18
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, MSR, 0x18, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register MSR
 *   DCTS:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, DCTS, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, DCTS, CHANGE, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, DCTS, NO_CHANGE, 0x0);

/*
 * Bit Field of Register MSR
 *   DDSR:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, DDSR, 1, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, DDSR, CHANGE, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, DDSR, NO_CHANGE, 0x0);

/*
 * Bit Field of Register MSR
 *   TERI:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, TERI, 2, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, TERI, CHANGE, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, TERI, NO_CHANGE, 0x0);

/*
 * Bit Field of Register MSR
 *   DDCD:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, DDCD, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, DDCD, CHANGE, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, DDCD, NO_CHANGE, 0x0);

/*
 * Bit Field of Register MSR
 *   CTS:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, CTS, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, CTS, ASSERTED, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, CTS, DEASSERTED, 0x0);

/*
 * Bit Field of Register MSR
 *   DSR:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, DSR, 5, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, DSR, ASSERTED, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, DSR, DEASSERTED, 0x0);

/*
 * Bit Field of Register MSR
 *   RI:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, RI, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, RI, ASSERTED, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, RI, DEASSERTED, 0x0);

/*
 * Bit Field of Register MSR
 *   DCD:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, DCD, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, MSR, DCD, ASSERTED, 0x1);
SEDI_RBFV_DEFINE(UART, MSR, DCD, DEASSERTED, 0x0);

/*
 * Bit Field of Register MSR
 *   RSVD_MSR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, MSR, RSVD_MSR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART SCR ***********
 *
 * Register of SEDI UART
 *   SCR: Scratchpad Register
 *     AddressOffset  : 0x1c
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, SCR, 0x1c, RW, (uint32_t)0xff, (uint32_t)0x0);

/*
 * Bit Field of Register SCR
 *   SCR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, SCR, SCR, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register SCR
 *   RSVD_SCR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, SCR, RSVD_SCR_31to8, 8, 24, RO, (uint32_t)0x0);

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
 *   FAR:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, FAR, FAR, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, FAR, FAR, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, FAR, FAR, ENABLED, 0x1);

/*
 * Bit Field of Register FAR
 *   RSVD_FAR_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, FAR, RSVD_FAR_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART USR ***********
 *
 * Register of SEDI UART
 *   USR: UART Status register
 *     AddressOffset  : 0x7c
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x6
 */
SEDI_REG_DEFINE(UART, USR, 0x7c, RO, (uint32_t)0x0, (uint32_t)0x6);

/*
 * Bit Field of Register USR
 *   RSVD_BUSY:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, USR, RSVD_BUSY, 0, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, USR, RSVD_BUSY, BUSY, 0x1);
SEDI_RBFV_DEFINE(UART, USR, RSVD_BUSY, IDLE, 0x0);

/*
 * Bit Field of Register USR
 *   TFNF:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, USR, TFNF, 1, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, USR, TFNF, FULL, 0x0);
SEDI_RBFV_DEFINE(UART, USR, TFNF, NOT_FULL, 0x1);

/*
 * Bit Field of Register USR
 *   TFE:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, USR, TFE, 2, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, USR, TFE, EMPTY, 0x1);
SEDI_RBFV_DEFINE(UART, USR, TFE, NOT_EMPTY, 0x0);

/*
 * Bit Field of Register USR
 *   RFNE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, USR, RFNE, 3, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, USR, RFNE, EMPTY, 0x0);
SEDI_RBFV_DEFINE(UART, USR, RFNE, NOT_EMPTY, 0x1);

/*
 * Bit Field of Register USR
 *   RFF:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, USR, RFF, 4, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, USR, RFF, FULL, 0x1);
SEDI_RBFV_DEFINE(UART, USR, RFF, NOT_FULL, 0x0);

/*
 * Bit Field of Register USR
 *   RSVD_USR_31to5:
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, USR, RSVD_USR_31to5, 5, 27, RO, (uint32_t)0x0);

/* ********* UART TFL ***********
 *
 * Register of SEDI UART
 *   TFL: Transmit FIFO Level
 *     AddressOffset  : 0x80
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, TFL, 0x80, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register TFL
 *   tfl:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TFL, tfl, 0, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register TFL
 *   RSVD_TFL_31toADDR_WIDTH:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TFL, RSVD_TFL_31toADDR_WIDTH, 7, 25, RO, (uint32_t)0x0);

/* ********* UART RFL ***********
 *
 * Register of SEDI UART
 *   RFL: Receive FIFO Level
 *     AddressOffset  : 0x84
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, RFL, 0x84, RO, (uint32_t)0x0, (uint32_t)0x0);

/*
 * Bit Field of Register RFL
 *   rfl:
 *     BitOffset : 0
 *     BitWidth  : 7
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RFL, rfl, 0, 7, RO, (uint32_t)0x0);

/*
 * Bit Field of Register RFL
 *   RSVD_RFL_31toADDR_WIDTH:
 *     BitOffset : 7
 *     BitWidth  : 25
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RFL, RSVD_RFL_31toADDR_WIDTH, 7, 25, RO, (uint32_t)0x0);

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
 *   HTX:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, HTX, HTX, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, HTX, HTX, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, HTX, HTX, ENABLED, 0x1);

/*
 * Bit Field of Register HTX
 *   RSVD_HTX_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, HTX, RSVD_HTX_31to1, 1, 31, RO, (uint32_t)0x0);

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
 *   DMASA:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DMASA, DMASA, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, DMASA, DMASA, SOFT_ACK, 0x1);

/*
 * Bit Field of Register DMASA
 *   RSVD_DMASA_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DMASA, RSVD_DMASA_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART TCR ***********
 *
 * Register of SEDI UART
 *   TCR: Transceiver Control Register
 *     AddressOffset  : 0xac
 *     AccessType     : RW
 *     WritableBitMask: 0x1f
 *     ResetValue     : (uint32_t)0x6
 */
SEDI_REG_DEFINE(UART, TCR, 0xac, RW, (uint32_t)0x1f, (uint32_t)0x6);

/*
 * Bit Field of Register TCR
 *   RS485_EN:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TCR, RS485_EN, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, TCR, RS485_EN, 0, 0);
SEDI_RBFV_DEFINE(UART, TCR, RS485_EN, 1, 1);

/*
 * Bit Field of Register TCR
 *   RE_POL:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, TCR, RE_POL, 1, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, TCR, RE_POL, 0, 0);
SEDI_RBFV_DEFINE(UART, TCR, RE_POL, 1, 1);

/*
 * Bit Field of Register TCR
 *   DE_POL:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, TCR, DE_POL, 2, 1, RW, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, TCR, DE_POL, 0, 0);
SEDI_RBFV_DEFINE(UART, TCR, DE_POL, 1, 1);

/*
 * Bit Field of Register TCR
 *   XFER_MODE:
 *     BitOffset : 3
 *     BitWidth  : 2
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TCR, XFER_MODE, 3, 2, RW, (uint32_t)0x0);

/*
 * Bit Field of Register TCR
 *   RSVD_TCR_31to5:
 *     BitOffset : 5
 *     BitWidth  : 27
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TCR, RSVD_TCR_31to5, 5, 27, RO, (uint32_t)0x0);

/* ********* UART DE_EN ***********
 *
 * Register of SEDI UART
 *   DE_EN: Driver Output Enable Register
 *     AddressOffset  : 0xb0
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, DE_EN, 0xb0, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register DE_EN
 *   DE_Enable:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DE_EN, DE_Enable, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, DE_EN, DE_Enable, 0, 0);
SEDI_RBFV_DEFINE(UART, DE_EN, DE_Enable, 1, 1);

/*
 * Bit Field of Register DE_EN
 *   RSVD_DE_EN_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DE_EN, RSVD_DE_EN_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART RE_EN ***********
 *
 * Register of SEDI UART
 *   RE_EN: Receiver Output Enable Register
 *     AddressOffset  : 0xb4
 *     AccessType     : RW
 *     WritableBitMask: 0x1
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, RE_EN, 0xb4, RW, (uint32_t)0x1, (uint32_t)0x0);

/*
 * Bit Field of Register RE_EN
 *   RE_Enable:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RE_EN, RE_Enable, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, RE_EN, RE_Enable, 0, 0);
SEDI_RBFV_DEFINE(UART, RE_EN, RE_Enable, 1, 1);

/*
 * Bit Field of Register RE_EN
 *   RSVD_RE_EN_31to1:
 *     BitOffset : 1
 *     BitWidth  : 31
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RE_EN, RSVD_RE_EN_31to1, 1, 31, RO, (uint32_t)0x0);

/* ********* UART DET ***********
 *
 * Register of SEDI UART
 *   DET: Driver Output Enable Timing Register
 *     AddressOffset  : 0xb8
 *     AccessType     : RW
 *     WritableBitMask: 0xff00ff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, DET, 0xb8, RW, (uint32_t)0xff00ff, (uint32_t)0x0);

/*
 * Bit Field of Register DET
 *   DE_Assertion_Time:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DET, DE_Assertion_Time, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DET
 *   RSVD_DE_AT_15to8:
 *     BitOffset : 8
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DET, RSVD_DE_AT_15to8, 8, 8, RO, (uint32_t)0x0);

/*
 * Bit Field of Register DET
 *   DE_De_assertion_Time:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DET, DE_De_assertion_Time, 16, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DET
 *   RSVD_DE_DEAT_31to24:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DET, RSVD_DE_DEAT_31to24, 24, 8, RO, (uint32_t)0x0);

/* ********* UART TAT ***********
 *
 * Register of SEDI UART
 *   TAT: TurnAround Timing Register
 *     AddressOffset  : 0xbc
 *     AccessType     : RW
 *     WritableBitMask: 0xffffffff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, TAT, 0xbc, RW, (uint32_t)0xffffffff, (uint32_t)0x0);

/*
 * Bit Field of Register TAT
 *   DE_to_RE:
 *     BitOffset : 0
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TAT, DE_to_RE, 0, 16, RW, (uint32_t)0x0);

/*
 * Bit Field of Register TAT
 *   RE_to_DE:
 *     BitOffset : 16
 *     BitWidth  : 16
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TAT, RE_to_DE, 16, 16, RW, (uint32_t)0x0);

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
 *   DLF:
 *     BitOffset : 0
 *     BitWidth  : 4
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DLF, DLF, 0, 4, RW, (uint32_t)0x0);

/*
 * Bit Field of Register DLF
 *   RSVD_DLF:
 *     BitOffset : 4
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, DLF, RSVD_DLF, 4, 28, RO, (uint32_t)0x0);

/* ********* UART RAR ***********
 *
 * Register of SEDI UART
 *   RAR: Receive Address Register
 *     AddressOffset  : 0xc4
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, RAR, 0xc4, RW, (uint32_t)0xff, (uint32_t)0x0);

/*
 * Bit Field of Register RAR
 *   RAR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, RAR, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register RAR
 *   RSVD_RAR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, RAR, RSVD_RAR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART TAR ***********
 *
 * Register of SEDI UART
 *   TAR: Transmit Address Register
 *     AddressOffset  : 0xc8
 *     AccessType     : RW
 *     WritableBitMask: 0xff
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, TAR, 0xc8, RW, (uint32_t)0xff, (uint32_t)0x0);

/*
 * Bit Field of Register TAR
 *   TAR:
 *     BitOffset : 0
 *     BitWidth  : 8
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TAR, TAR, 0, 8, RW, (uint32_t)0x0);

/*
 * Bit Field of Register TAR
 *   RSVD_TAR_31to8:
 *     BitOffset : 8
 *     BitWidth  : 24
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, TAR, RSVD_TAR_31to8, 8, 24, RO, (uint32_t)0x0);

/* ********* UART LCR_EXT ***********
 *
 * Register of SEDI UART
 *   LCR_EXT: Line Extended Control Register
 *     AddressOffset  : 0xcc
 *     AccessType     : RW
 *     WritableBitMask: 0xf
 *     ResetValue     : (uint32_t)0x0
 */
SEDI_REG_DEFINE(UART, LCR_EXT, 0xcc, RW, (uint32_t)0xf, (uint32_t)0x0);

/*
 * Bit Field of Register LCR_EXT
 *   DLS_E:
 *     BitOffset : 0
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR_EXT, DLS_E, 0, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR_EXT, DLS_E, 0, 0);
SEDI_RBFV_DEFINE(UART, LCR_EXT, DLS_E, 1, 1);

/*
 * Bit Field of Register LCR_EXT
 *   ADDR_MATCH:
 *     BitOffset : 1
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR_EXT, ADDR_MATCH, 1, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR_EXT, ADDR_MATCH, 0, 0);
SEDI_RBFV_DEFINE(UART, LCR_EXT, ADDR_MATCH, 1, 1);

/*
 * Bit Field of Register LCR_EXT
 *   SEND_ADDR:
 *     BitOffset : 2
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR_EXT, SEND_ADDR, 2, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR_EXT, SEND_ADDR, 0, 0);
SEDI_RBFV_DEFINE(UART, LCR_EXT, SEND_ADDR, 1, 1);

/*
 * Bit Field of Register LCR_EXT
 *   TRANSMIT_MODE:
 *     BitOffset : 3
 *     BitWidth  : 1
 *     AccessType: RW
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR_EXT, TRANSMIT_MODE, 3, 1, RW, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, LCR_EXT, TRANSMIT_MODE, 0, 0);
SEDI_RBFV_DEFINE(UART, LCR_EXT, TRANSMIT_MODE, 1, 1);

/*
 * Bit Field of Register LCR_EXT
 *   RSVD_LCR_EXT:
 *     BitOffset : 4
 *     BitWidth  : 28
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, LCR_EXT, RSVD_LCR_EXT, 4, 28, RO, (uint32_t)0x0);

/* ********* UART CPR ***********
 *
 * Register of SEDI UART
 *   CPR: Component Parameter Register
 *     AddressOffset  : 0xf4
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x43532
 */
SEDI_REG_DEFINE(UART, CPR, 0xf4, RO, (uint32_t)0x0, (uint32_t)0x43532);

/*
 * Bit Field of Register CPR
 *   APB_DATA_WIDTH:
 *     BitOffset : 0
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x2
 */
SEDI_RBF_DEFINE(UART, CPR, APB_DATA_WIDTH, 0, 2, RO, (uint32_t)0x2);
SEDI_RBFV_DEFINE(UART, CPR, APB_DATA_WIDTH, APB_16BITS, 0x1);
SEDI_RBFV_DEFINE(UART, CPR, APB_DATA_WIDTH, APB_32BITS, 0x2);
SEDI_RBFV_DEFINE(UART, CPR, APB_DATA_WIDTH, APB_8BITS, 0x0);

/*
 * Bit Field of Register CPR
 *   RSVD_CPR_3to2:
 *     BitOffset : 2
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, CPR, RSVD_CPR_3to2, 2, 2, RO, (uint32_t)0x0);

/*
 * Bit Field of Register CPR
 *   AFCE_MODE:
 *     BitOffset : 4
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, CPR, AFCE_MODE, 4, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, CPR, AFCE_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, AFCE_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   THRE_MODE:
 *     BitOffset : 5
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, CPR, THRE_MODE, 5, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, CPR, THRE_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, THRE_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   SIR_MODE:
 *     BitOffset : 6
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, CPR, SIR_MODE, 6, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, CPR, SIR_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, SIR_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   SIR_LP_MODE:
 *     BitOffset : 7
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, CPR, SIR_LP_MODE, 7, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, CPR, SIR_LP_MODE, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, SIR_LP_MODE, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   ADDITIONAL_FEAT:
 *     BitOffset : 8
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, CPR, ADDITIONAL_FEAT, 8, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, CPR, ADDITIONAL_FEAT, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, ADDITIONAL_FEAT, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   FIFO_ACCESS:
 *     BitOffset : 9
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, CPR, FIFO_ACCESS, 9, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_ACCESS, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_ACCESS, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   FIFO_STAT:
 *     BitOffset : 10
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, CPR, FIFO_STAT, 10, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_STAT, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_STAT, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   SHADOW:
 *     BitOffset : 11
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, CPR, SHADOW, 11, 1, RO, (uint32_t)0x0);
SEDI_RBFV_DEFINE(UART, CPR, SHADOW, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, SHADOW, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   UART_ADD_ENCODED_PARAMS:
 *     BitOffset : 12
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, CPR, UART_ADD_ENCODED_PARAMS, 12, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, CPR, UART_ADD_ENCODED_PARAMS, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, UART_ADD_ENCODED_PARAMS, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   DMA_EXTRA:
 *     BitOffset : 13
 *     BitWidth  : 1
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x1
 */
SEDI_RBF_DEFINE(UART, CPR, DMA_EXTRA, 13, 1, RO, (uint32_t)0x1);
SEDI_RBFV_DEFINE(UART, CPR, DMA_EXTRA, DISABLED, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, DMA_EXTRA, ENABLED, 0x1);

/*
 * Bit Field of Register CPR
 *   RSVD_CPR_15to14:
 *     BitOffset : 14
 *     BitWidth  : 2
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, CPR, RSVD_CPR_15to14, 14, 2, RO, (uint32_t)0x0);

/*
 * Bit Field of Register CPR
 *   FIFO_MODE:
 *     BitOffset : 16
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x4
 */
SEDI_RBF_DEFINE(UART, CPR, FIFO_MODE, 16, 8, RO, (uint32_t)0x4);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_0, 0x0);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_1024, 0x40);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_128, 0x8);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_16, 0x1);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_2048, 0x80);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_256, 0x10);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_32, 0x2);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_512, 0x20);
SEDI_RBFV_DEFINE(UART, CPR, FIFO_MODE, FIFO_MODE_64, 0x4);

/*
 * Bit Field of Register CPR
 *   RSVD_CPR_31to24:
 *     BitOffset : 24
 *     BitWidth  : 8
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x0
 */
SEDI_RBF_DEFINE(UART, CPR, RSVD_CPR_31to24, 24, 8, RO, (uint32_t)0x0);

/* ********* UART UCV ***********
 *
 * Register of SEDI UART
 *   UCV: UART Component Version
 *     AddressOffset  : 0xf8
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x3430322a
 */
SEDI_REG_DEFINE(UART, UCV, 0xf8, RO, (uint32_t)0x0, (uint32_t)0x3430322a);

/*
 * Bit Field of Register UCV
 *   UART_Component_Version:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x3430322a
 */
SEDI_RBF_DEFINE(UART, UCV, UART_Component_Version, 0, 32, RO, (uint32_t)0x3430322a);

/* ********* UART CTR ***********
 *
 * Register of SEDI UART
 *   CTR: Component Type Register
 *     AddressOffset  : 0xfc
 *     AccessType     : RO
 *     WritableBitMask: 0x0
 *     ResetValue     : (uint32_t)0x44570110
 */
SEDI_REG_DEFINE(UART, CTR, 0xfc, RO, (uint32_t)0x0, (uint32_t)0x44570110);

/*
 * Bit Field of Register CTR
 *   Peripheral_ID:
 *     BitOffset : 0
 *     BitWidth  : 32
 *     AccessType: RO
 *     ResetValue: (uint32_t)0x44570110
 */
SEDI_RBF_DEFINE(UART, CTR, Peripheral_ID, 0, 32, RO, (uint32_t)0x44570110);

/*
 * Registers' Address Map Structure
 */

typedef struct {
	/* Rx Buffer/ Tx Holding/ Div Latch Low register  */
	__IO_RW uint32_t rbr_thr_dll;

	/* Interrupt Enable / Div Latch High register */
	__IO_RW uint32_t ier_dlh;

	/* Interrupt Identification/FIFO Ctrl register */
	__IO_RW uint32_t iir_fcr;

	/* Line Control Register */
	__IO_RW uint32_t lcr;

	/* Modem Control Register */
	__IO_RW uint32_t mcr;

	/* Line Status Register */
	__IO_R uint32_t lsr;

	/* Modem Status Register */
	__IO_R uint32_t msr;

	/* Scratchpad Register */
	__IO_RW uint32_t scr;

	/* Reserved */
	__IO_RW uint32_t reserved0[20];

	/* FIFO Access Register */
	__IO_R uint32_t far;

	/* Reserved */
	__IO_RW uint32_t reserved1[2];

	/* UART Status register */
	__IO_R uint32_t usr;

	/* Transmit FIFO Level */
	__IO_R uint32_t tfl;

	/* Receive FIFO Level */
	__IO_R uint32_t rfl;

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
	__IO_RW uint32_t rar;

	/* Transmit Address Register */
	__IO_RW uint32_t tar;

	/* Line Extended Control Register */
	__IO_RW uint32_t lcr_ext;

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
