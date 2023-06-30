/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SPI_BSP_H_
#define _SPI_BSP_H_

#include <sedi_driver_spi.h>
#include "sedi_driver_dma.h"

#define BITMASK(b, a) ((BIT(b - a + 1) - 1) << a)

/******************************************************************************
 * RTL configuration
 *****************************************************************************/

#define SSI_NUM_SLAVES (1)
#define SSI_TX_ABW (16)
#define SSI_PRESCALE_MIN (2)
#define SSI_FIFO_DEPTH_MIN (2)
#define SSI_FIFO_DEPTH (64)

/******************************************************************************
 * LLD interface
 *****************************************************************************/

#define REG_VERSION (0x3430312A)

#define REG_INT_ERROR (BIT(1) | BIT(2) | BIT(3))
#define REG_INT_TX BIT(0)
#define REG_INT_RX BIT(4)
#define REG_INT_NONE (0)

#define REG_SR_BUSY BIT(0)
#define REG_SR_TX_EMPTY BIT(2)
#define REG_SR_TX_NOT_FULL BIT(1)
#define REG_SR_RX_NOT_EMPTY BIT(3)
#define REG_SR_ERROR BIT(5)

#define REG_DMA_ENABLE (BIT(0) | BIT(1))
#define REG_INT_ENABLE (0x1F)

#ifdef SPI_DW_2_0
#define REG_CTRL0_CPHA BIT(8)
#define REG_CTRL0_CPOL BIT(9)
#define REG_CTRL0_LOOPBACK BIT(13)
#define REG_CTRL0_SSTE BIT(14)
#define SPI_CTRL0_TMOD_MASK (0xC00)
#define REG_CTRL0_FRF_MASK (0xC0)
#define REG_CTRL0_FRF_TI_SSP (0x40)
#define REG_CTRL0_FRF_MICROWIRE (0x80)

#define SPI_CTRL0_BOTH_MODE (0)
#define SPI_CTRL0_SEND_MODE (1 << 10U)
#define SPI_CTRL0_RECEIVE_MODE (2 << 10U)
#define SPI_CTRL0_EEPROM_MODE (0)
#define SPI_FRAME_FORMAT_MASK (BIT(22) | BIT(23))
#define SPI_FRAME_FORMAT_SHIFT (22)
#define SPI_TXFTLR_TXFTHR_MASK (0xFFFF0000)
#define SPI_TXFTLR_TXFTHR_SHIFT (16)
#define MASK_CTRL0_WIDTH (0x1F)
#define SSI_IC_FREQ (100000000)
#else
#define REG_CTRL0_CPHA BIT(6)
#define REG_CTRL0_CPOL BIT(7)
#define REG_CTRL0_LOOPBACK BIT(11)
#define REG_CTRL0_SSTE BIT(24)
#define SPI_CTRL0_TMOD_MASK (0x300)
#define REG_CTRL0_FRF_MASK (0x30)
#define REG_CTRL0_FRF_TI_SSP (0x10)
#define REG_CTRL0_FRF_MICROWIRE (0x20)

#define SPI_CTRL0_BOTH_MODE (0)
#define SPI_CTRL0_SEND_MODE (1 << 8U)
#define SPI_CTRL0_RECEIVE_MODE (2 << 8U)
#define SPI_CTRL0_EEPROM_MODE (0)
#define SPI_FRAME_FORMAT_MASK (BIT(21) | BIT(22))
#define SPI_FRAME_FORMAT_SHIFT (21)
#define MASK_CTRL0_WIDTH (0xF)
#define SSI_IC_FREQ (sedi_pm_get_lbw_clock())
#endif

#define REG_MWCR_MWMOD_SHIFT (0)
#define REG_MWCR_MDD_SHIFT (1)
#define REG_MWCR_MHS_SHIFT (2)

#define OFFSET_CTRL0_WIDTH 0

#define SEDI_SPI_DRV_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(1, 0)

#define SPI_CS_MODE_UNUSED 0
#define SPI_CS_MODE_HW 1
#define SPI_CS_MODE_SW 2

#define SPI_CS_MASK_DEFAULT BIT(0)

#define SPI_BITWIDTH_4BITS (4)
#define SPI_BITWIDTH_8BITS (8)
#define SPI_BITWIDTH_16BITS (16)

#define SPI_FRAME_SIZE_1_BYTE (1)
#define SPI_FRAME_SIZE_2_BYTES (2)

#define SPI_RECEIVE_MODE_MAX_SIZE (65536)
#define DEFAULT_PRESCALE (20)

#define SPI_CTRLR0_ADDR_L_MASK (0x3C)
#define SPI_CTRLR0_ADDR_L_SHIFT (2)
#define SPI_CTRLR0_INST_L_MASK (0x300)
#define SPI_CTRLR0_INST_L_SHIFT (8)
#define SPI_CTRLR0_WAIT_CYCLE_MASK (0xF800)
#define SPI_CTRLR0_WAIT_CYCLE_SHIFT (11)

#define SPI_DMA_MAX_SIZE (4096)
#define SPI_DMA_MAX_SIZE_SHIFT (12)

/* SPI transfer mode */
typedef enum {
	SPI_TRANSFER_MODE_BOTH = 0,
	SPI_TRANSFER_MODE_SEND,
	SPI_TRANSFER_MODE_RECEIVE,
	SPI_TRANSFER_MODE_EEPROM
} spi_transfer_mode_t;

typedef struct spi_registers {
	__IO_RW uint32_t ctrl0;
	__IO_RW uint32_t ctrl1;
	__IO_RW uint32_t ssienr;
	__IO_RW uint32_t mwcr;
	__IO_RW uint32_t ser;
	__IO_RW uint32_t baudr;
	__IO_RW uint32_t txftlr;
	__IO_RW uint32_t rxftlr;
	__IO_RW uint32_t txflr;
	__IO_RW uint32_t rxflr;
	__IO_RW uint32_t sr;
	__IO_RW uint32_t imr;
	__IO_RW uint32_t isr;
	__IO_RW uint32_t risr;
	__IO_RW uint32_t txoicr;
	__IO_RW uint32_t rxoicr;
	__IO_RW uint32_t rxuicr;
	__IO_RW uint32_t msticr;
	__IO_RW uint32_t icr;
	__IO_RW uint32_t dmacr;
	__IO_RW uint32_t dmatdlr;
	__IO_RW uint32_t dmardlr;
	__IO_RW uint32_t idr;
	__IO_RW uint32_t ssic_version_id;
	__IO_RW uint32_t dr;
	__IO_RW uint32_t dr_rsvd[35];
	__IO_RW uint32_t rx_sample_delay;
	__IO_RW uint32_t spi_ctrl0;
	__IO_RW uint32_t txd_drive_edge;
	__IO_RW uint32_t rsvd;
} spi_reg_t;

struct spi_context {
	/* hardware config */
	spi_reg_t *base;
	uint32_t dma_handshake;
	uint32_t rx_handshake;

	/* sedi required */
	sedi_spi_capabilities_t capability;
	sedi_spi_status_t status;
	sedi_spi_event_cb_t cb_event;
	void *cb_param;

	/* ioctl info */
	uint8_t frame_size; /* Frame size in byte */
	uint8_t tx_watermark;
	uint8_t rx_watermark;
	uint32_t prescale;
	uint32_t dummy_data;
	bool is_lsb;
	bool is_cs_continuous;

	/* transfer info */
	spi_transfer_mode_t transfer_mode;
	uint8_t *data_tx;
	uint8_t *data_rx;
	uint32_t tx_data_len;
	uint32_t rx_data_len;
	uint32_t data_tx_idx;
	uint32_t data_rx_idx;

	/* For dma transfer */
	bool dma_tx_finished;
	bool dma_rx_finished;
	uint32_t tx_dma;
	uint32_t rx_dma;
	uint8_t tx_channel;
	uint8_t rx_channel;
	uint32_t dma_cycles; /* For large data DMA transfer */
	uint32_t dma_idx; /* For large data DMA transfer */
	uint32_t last_dma_counts; /* For large data DMA transfer */

	/* For qspi */
	bool is_quad;
	const sedi_spi_enhanced_config_t *quad_config;
};

#endif
