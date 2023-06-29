/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DW_UART_PRIV_H_
#define _DW_UART_PRIV_H_

#include "stdio.h"
#include "sedi_driver_common.h"

#define HAS_ADVANCED_UART_CONFIGURATION (0)
#define HAS_UART_RS485_SUPPORT (0)
#define HAS_UART_9BIT_SUPPORT (0)
#define HAS_UART_SOFT_RST (0)

/* Data length select mask. */
#define SEDI_UART_LCR_DLS_MASK (BIT(1) | BIT(0))
/* 5 data bits. */
#define SEDI_UART_LCR_5_DATA_BITS (0x0)
/* 6 data bits. */
#define SEDI_UART_LCR_6_DATA_BITS (0x1)
/* 7 data bits. */
#define SEDI_UART_LCR_7_DATA_BITS (0x2)
/* 8 data bits. */
#define SEDI_UART_LCR_8_DATA_BITS (0x3)
/* Number of stop bits. */
#define SEDI_UART_LCR_STOP BIT(2)
/* Parity enable bit. */
#define SEDI_UART_LCR_PEN BIT(3)
/* Even parity select. */
#define SEDI_UART_LCR_EPS BIT(4)
/* Sticky parity. */
#define SEDI_UART_LCR_STICKY_PARITY BIT(5)
/* Break character bit. */
#define SEDI_UART_LCR_BREAK BIT(6)
/* Divisor latch access bit. */
#define SEDI_UART_LCR_DLAB BIT(7)

/* Request to Send Bit. */
#define SEDI_UART_MCR_RTS BIT(1)
/* Loopback Enable Bit. */
#define SEDI_UART_MCR_LOOPBACK BIT(4)
/* Auto Flow Control Enable Bit. */
#define SEDI_UART_MCR_AFCE BIT(5)

/* CTS state of MSR. */
#define SEDI_UART_MSR_CTS BIT(4)

/* FIFO Enable Bit. */
#define SEDI_UART_FCR_FIFOE BIT(0)
/* Reset Receive FIFO. */
#define SEDI_UART_FCR_RFIFOR BIT(1)
/* Reset Transmit FIFO. */
#define SEDI_UART_FCR_XFIFOR BIT(2)

/* Default FIFO RX & TX Thresholds, half full for both. */
#define SEDI_UART_FCR_DEFAULT_TX_RX_THRESHOLD (0xB0)
/* Change TX Threshold to empty, keep RX Threshold to default. */
#define SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD (0x80)

/* No interrupt pending */
#define SEDI_UART_IIR_NO_INTERRUPT_PENDING (0x01)
/* Transmit Holding Register Empty. */
#define SEDI_UART_IIR_THR_EMPTY (0x02)
/* Received Data Available. */
#define SEDI_UART_IIR_RECV_DATA_AVAIL (0x04)
/* Receiver Line Status. */
#define SEDI_UART_IIR_RECV_LINE_STATUS (0x06)
/* Character Timeout. */
#define SEDI_UART_IIR_CHAR_TIMEOUT (0x0C)
/* Interrupt ID Mask. */
#define SEDI_UART_IIR_IID_MASK (0x0F)

/* Data Ready Bit. */
#define SEDI_UART_LSR_DR BIT(0)
/* Overflow Error Bit. */
#define SEDI_UART_LSR_OE BIT(1)
/* Parity Error Bit. */
#define SEDI_UART_LSR_PE BIT(2)
/* Framing Error Bit. */
#define SEDI_UART_LSR_FE BIT(3)
/* Break Interrupt Bit. */
#define SEDI_UART_LSR_BI BIT(4)
/* Transmit Holding Register Empty Bit. */
#define SEDI_UART_LSR_THRE BIT(5)
/* Transmitter Empty Bit. */
#define SEDI_UART_LSR_TEMT BIT(6)
/* Receiver FIFO Error Bit. */
#define SEDI_UART_LSR_RFE BIT(7)
/* Address Received in 9bit mode.*/
#define SEDI_UART_LSR_ADDR_RCVD BIT(8)

/* Enable Received Data Available Interrupt. */
#define SEDI_UART_IER_ERBFI BIT(0)
/* Enable Transmit Holding Register Empty Interrupt. */
#define SEDI_UART_IER_ETBEI BIT(1)
/* Enable Receiver Line Status Interrupt. */
#define SEDI_UART_IER_ELSI BIT(2)
/* Programmable THRE Interrupt Mode. */
#define SEDI_UART_IER_PTIME BIT(7)
/* Controller busy bit for UART. */
#define SEDI_UART_USR_BUSY BIT(0)

/* DMA software acknowledge bit. */
#define SEDI_UART_DMASA BIT(0)

/* SCR bit to indicate updated status for LSR. */
#define SEDI_UART_SCR_STATUS_UPDATE BIT(0)

/* Line Status Errors. */
#define SEDI_UART_LSR_ERROR_BITS                                               \
	(SEDI_UART_LSR_OE | SEDI_UART_LSR_PE | SEDI_UART_LSR_FE |              \
	 SEDI_UART_LSR_BI)

/* FIFO Depth. */
#define SEDI_UART_FIFO_DEPTH (64)
/* FIFO Half Depth. */
#define SEDI_UART_FIFO_HALF_DEPTH (SEDI_UART_FIFO_DEPTH / 2)

/* Maximum value of baud divisor supported (clock_speed /(16*baud_rate)). */
#define SEDI_UART_MAX_BAUD_DIVISOR (0xFFFF)

/* Get the lower byte from the divisor.*/
#define SEDI_UART_GET_DLL(divisor) (divisor & 0xFF)

/* Get the higher byte from the divisor. */
#define SEDI_UART_GET_DLH(divisor) ((divisor & 0xFF00) >> 8)

/* Divisor Latch High Offset. */
#define SEDI_UART_CFG_BAUD_DLH_OFFS 16
/* Divisor Latch Low Offset. */
#define SEDI_UART_CFG_BAUD_DLL_OFFS 8
/* Divisor Latch Fraction Offset. */
#define SEDI_UART_CFG_BAUD_DLF_OFFS 0
/* Divisor Latch High Mask. */
#define SEDI_UART_CFG_BAUD_DLH_MASK (0xFF << SEDI_UART_CFG_BAUD_DLH_OFFS)
/* Divisor Latch Low Mask. */
#define SEDI_UART_CFG_BAUD_DLL_MASK (0xFF << SEDI_UART_CFG_BAUD_DLL_OFFS)
/* Divisor Latch Fraction Mask. */
#define SEDI_UART_CFG_BAUD_DLF_MASK (0xFF << SEDI_UART_CFG_BAUD_DLF_OFFS)

/* Divisor Latch Packing Helper. */
#define SEDI_UART_CFG_BAUD_DL_PACK(dlh, dll, dlf)                              \
	(dlh << SEDI_UART_CFG_BAUD_DLH_OFFS |                                  \
	 dll << SEDI_UART_CFG_BAUD_DLL_OFFS |                                  \
	 dlf << SEDI_UART_CFG_BAUD_DLF_OFFS)

/* Divisor Latch High Unpacking Helper. */
#define SEDI_UART_CFG_BAUD_DLH_UNPACK(packed)                                  \
	((packed & SEDI_UART_CFG_BAUD_DLH_MASK) >> SEDI_UART_CFG_BAUD_DLH_OFFS)
/* Divisor Latch Low Unpacking Helper. */
#define SEDI_UART_CFG_BAUD_DLL_UNPACK(packed)                                  \
	((packed & SEDI_UART_CFG_BAUD_DLL_MASK) >> SEDI_UART_CFG_BAUD_DLL_OFFS)
/* Divisor Latch Fraction Unpacking Helper. */
#define SEDI_UART_CFG_BAUD_DLF_UNPACK(packed)                                  \
	((packed & SEDI_UART_CFG_BAUD_DLF_MASK) >> SEDI_UART_CFG_BAUD_DLF_OFFS)

/* RS485 configuration  macros. */

/* Transceiver controls fields. */

/* Setting the bit 0 enables rs485. */
#define SEDI_UART_TCR_RS485_EN (BIT(0))
/* Receiver enable active high if set. */
#define SEDI_UART_TCR_RE_POL (BIT(1))
/* Receiver enable polarity offset. */
#define SEDI_UART_TCR_RE_POL_OFFSET (0x1)
/* Driver enable active high if set. */
#define SEDI_UART_TCR_DE_POL (BIT(2))
/* Driver enable polarity offset. */
#define SEDI_UART_TCR_DE_POL_OFFSET (0x2)

#define SEDI_UART_TCR_TRANSFER_MODE_OFFSET (3)
#define SEDI_UART_TCR_TRANSFER_MODE_MASK (BIT(3) | BIT(4))

/** Full Duplex mode. */
#define SEDI_UART_XFER_MODE_FULL_DUPLEX (0)

/** Software Controlled Half Duplex mode. */
#define SEDI_UART_XFER_MODE_SW_HALF_DUPLEX (1)

/** Hardware Controlled Half Duplex mode. */
#define SEDI_UART_XFER_MODE_HW_HALF_DUPLEX (2)

/* Receiver Enable. */
#define SEDI_UART_RE_EN_BIT (BIT(0))

/* Driver Enable. */
#define SEDI_UART_DE_EN_BIT (BIT(0))

/* At 100Mhz clock. */
/* Serial clock period in NS. */
#define SEDI_UART_SERIAL_CLK_PERIOD_NS (10)
/* Max DE signal assertion , deassertion time in NS. */
#define SEDI_UART_DE_AT_DT_NS_MAX (2550)
/* Max Turnaround time in NS. */
#define SEDI_UART_TAT_NS_MAX (655350)

/* DE signal assertion time offset. */
#define SEDI_UART_DET_AT_OFFSET (0)
/* DE signal assertion time mask. */
#define SEDI_UART_DET_AT_MASK (0xFF << SEDI_UART_DET_AT_OFFSET)
/* DE signal de-assertion time offset. */
#define SEDI_UART_DET_DT_OFFSET (16)
/* DE signal de-assertion time mask. */
#define SEDI_UART_DET_DT_MASK (0xFF << SEDI_UART_DET_DT_OFFSET)

/* Packs the assertion and deassertion time to a uint32_t. */
#define SEDI_UART_DET_AT_DT_PACK(assertion_time, de_assertion_time)            \
	((uint32_t)(((uint32_t)(assertion_time)) << SEDI_UART_DET_AT_OFFSET |  \
		    ((uint32_t)(de_assertion_time))                            \
			<< SEDI_UART_DET_DT_OFFSET))

/* DE to RE TAT offset. */
#define SEDI_UART_TAT_DE_RE_OFFSET (0)
/* DE to RE TAT Mask. */
#define SEDI_UART_TAT_DE_RE_MASK (0xFFFF << SEDI_UART_TAT_DE_RE_OFFSET)
/* RE to DE TAT offset. */
#define SEDI_UART_TAT_RE_DE_OFFSET (16)
/* RE to DE TAT Mask. */
#define SEDI_UART_TAT_RE_DE_MASK (0xFFFF << SEDI_UART_TAT_RE_DE_OFFSET)

/* Packs the de to re and re to de times to a uint32_t. */
#define SEDI_UART_TAT_PACK(de_to_re, re_to_de)                                 \
	((uint32_t)(((uint32_t)(de_to_re)) << SEDI_UART_TAT_DE_RE_OFFSET |     \
		    ((uint32_t)(re_to_de)) << SEDI_UART_TAT_RE_DE_OFFSET))

/* 9 bit operation mode macros. */

/* Enable 9 bit operation. */
#define SEDI_UART_LCR_EXT_ENABLE_9BIT_MODE (BIT(0))
/* Hardware enabled receive address match mode. */
#define SEDI_UART_LCR_EXT_HW_RECV_ADDRESS_MATCH (BIT(1))
/* Send address control bit.*/
#define SEDI_UART_LCR_EXT_SEND_ADDRESS (BIT(2))
/* Transmit mode : 0 address picked from TAR and sent with 9th bit set
 * 1 sw programs and sets the 9th bit to send address.
 */
#define SEDI_UART_LCR_EXT_SW_TRANSMIT_MODE (BIT(3))
/* Receive Address Mask in RAR. */
#define SEDI_UART_RAR_RECEIVE_ADDRESS_MASK (0xFF)
/* Transmit Address Mask in TAR. */
#define SEDI_UART_TAR_TRANSMIT_ADDRESS_MASK (0xFF)

/* Multiplier for improving rounding accuracy in uart DLF */
#define SEDI_UART_DLF_SCALAR (100)

/** UART register map. */
typedef struct {
	__IO_RW uint32_t
	    rbr_thr_dll;	  /**< Rx Buffer/ Tx Holding/ Div Latch Low. */
	__IO_RW uint32_t ier_dlh; /**< Interrupt Enable / Div Latch High. */
	__IO_RW uint32_t iir_fcr; /**< Interrupt Identification/FIFO Ctrl. */
	__IO_RW uint32_t lcr;     /**< Line Control. */
	__IO_RW uint32_t mcr;     /**< MODEM Control. */
	__IO_R uint32_t lsr;      /**< Line Status. */
	__IO_RW uint32_t msr;     /**< MODEM Status. */
	__IO_RW uint32_t scr;     /**< Scratchpad. */
	__IO_RW uint32_t reserved0[20];
	__IO_RW uint32_t far; /**< Fifo Access Reg. */
	__IO_RW uint32_t reserved1[2];
	__IO_RW uint32_t usr; /**< UART Status. */
	__IO_RW uint32_t reserved2[9];
	__IO_RW uint32_t htx;   /**< Halt Transmission. */
	__IO_RW uint32_t dmasa; /**< DMA Software Acknowledge. */
#if (HAS_UART_RS485_SUPPORT)
	__IO_RW uint32_t tcr;   /**< Transceiver Control Register. */
	__IO_RW uint32_t de_en; /**< Driver Output Enable Register. */
	__IO_RW uint32_t re_en; /**< Receiver Output Enable Register. */
	__IO_RW uint32_t det;   /**< Driver Output Enable Timing Register. */
	__IO_RW uint32_t tat;   /**<  Turnaround Timing Register. */
#else
	__IO_R uint32_t reserved3[5];
#endif
	__IO_RW uint32_t dlf; /**< Divisor Latch Fraction. */
#if (HAS_UART_9BIT_SUPPORT)
	__IO_RW uint32_t rar;     /**<  Receive Address Register. */
	__IO_RW uint32_t tar;     /**<  Transmit Address Register. */
	__IO_RW uint32_t lcr_ext; /**<  Line Extended Control Register. */
#else
	__IO_R uint32_t reserved4[3];
#endif
	__IO_R uint32_t padding[0x3CC]; /**< (0x1000 - 0xD0) / 4. */
} sedi_uart_reg_t;

/**
 * UART context to be saved between sleep/resume.
 *
 * Application should not modify the content.
 * This structure is only intended to be used by the sedi_uart_save_context and
 * sedi_uart_restore_context functions.
 */
typedef struct {
	uint32_t ier; /**< Interrupt Enable Register. */
	uint32_t dlh; /**< Divisor Latch High. */
	uint32_t dll; /**< Divisor Latch Low. */
	uint32_t lcr; /**< Line Control. */
	uint32_t mcr; /**< Modem Control. */
	uint32_t scr; /**< Scratchpad. */
	uint32_t htx; /**< Halt Transmission. */
	uint32_t dlf; /**< Divisor Latch Fraction. */
#if (HAS_UART_RS485_SUPPORT)
	uint32_t tcr;   /**< Transmission Control Register. */
	uint32_t de_en; /**< Driver Enable. */
	uint32_t re_en; /**< Receiver Enable. */
	uint32_t det;   /**< Driver-output Enable Timing. */
	uint32_t tat;   /**< Turn Around Timing. */
#endif
#if (HAS_UART_9BIT_SUPPORT)
	uint32_t rar;     /**< Receive Address Register. */
	uint32_t tar;     /**< Transmit Address Register. */
	uint32_t lcr_ext; /**< Line extended Control Register. */
#endif
	bool context_valid; /**< Indicates whether saved context is valid. */
} sedi_uart_context_t;

#define SEDI_UART sedi_uart

/**
 * UART peripheral driver.
 */

#if HAS_ADVANCED_UART_CONFIGURATION
/**
 * UART Transmit Water Mark
 * Empty trigger level in the transmit FIFO.
 */
typedef enum {
	SEDI_UART_TX_WM_EMPTY = 0, /* FIFO empty */
	SEDI_UART_TX_WM_TWOCHAR,   /* 2 characters in the FIFO */
	SEDI_UART_TX_WM_QUARTER,   /* FIFO 1/4 full */
	SEDI_UART_TX_WM_HALF,      /* FIFO 1/2 full */
} sedi_uart_tx_water_mark_t;

/**
 * UART Receive Water Mark
 * Trigger level in the receiver FIFO.
 */
typedef enum {
	SEDI_UART_RX_WM_ONEBYTE = 0, /* 1 character in the FIFO */
	SEDI_UART_RX_WM_QUARTER,     /* FIFO 1/4 full */
	SEDI_UART_RX_WM_HALF,	/* FIFO 1/2 full */
	SEDI_UART_RX_WM_TWOLESS,     /* FIFO 2 less than full */
} sedi_uart_rx_water_mark_t;
#endif /* HAS_ADVANCED_UART_CONFIGURATION */

/**
 * @}
 */
#endif /* _DW_UART_PRIV_H_ */
