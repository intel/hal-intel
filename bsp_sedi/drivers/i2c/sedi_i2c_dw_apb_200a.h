/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _I2C_DW_APB_200A_H_
#define _I2C_DW_APB_200A_H_

#include <sedi_driver_i2c.h>
#include "sedi_driver_dma.h"

typedef struct {
	uint32_t rsv0 : 6;
	uint32_t has_dma : 1;
	uint32_t rsv1 : 1;
	uint32_t rx_buffer_depth : 8;
	uint32_t tx_buffer_depth : 8;
	uint32_t rsv2 : 8;
} i2c_comp_param_t;

typedef struct {
	__IO_RW uint32_t con;
	__IO_RW uint32_t tar;
	__IO_RW uint32_t sar;
	__IO_RW uint32_t hs_maddr;
	__IO_RW uint32_t data_cmd;

	__IO_RW uint32_t ss_scl_hcnt;
	__IO_RW uint32_t ss_scl_lcnt;
	__IO_RW uint32_t fs_scl_hcnt;
	__IO_RW uint32_t fs_scl_lcnt;
	__IO_RW uint32_t hs_scl_hcnt;
	__IO_RW uint32_t hs_scl_lcnt;

	__IO_RW uint32_t intr_stat;
	__IO_RW uint32_t intr_mask;
	__IO_RW uint32_t raw_intr_stat;

	__IO_RW uint32_t rx_tl;
	__IO_RW uint32_t tx_tl;

	__IO_RW uint32_t clr_intr;
	__IO_RW uint32_t clr_rx_under;
	__IO_RW uint32_t clr_rx_over;
	__IO_RW uint32_t clr_tx_over;
	__IO_RW uint32_t clr_rd_req;
	__IO_RW uint32_t clr_tx_abrt;
	__IO_RW uint32_t clr_rx_done;
	__IO_RW uint32_t clr_activity;
	__IO_RW uint32_t clr_stop_det;
	__IO_RW uint32_t clr_start_det;
	__IO_RW uint32_t clr_gen_call;

	__IO_RW uint32_t enable;
	__IO_RW uint32_t status;

	__IO_RW uint32_t txflr;
	__IO_RW uint32_t rxflr;

	__IO_RW uint32_t sda_hold;
	__IO_RW uint32_t tx_abrt_source;
	__IO_RW uint32_t slv_data_nack_only;

	__IO_RW uint32_t dma_cr;
	__IO_RW uint32_t dma_tdlr;
	__IO_RW uint32_t dma_rdlr;

	__IO_RW uint32_t sda_setup;
	__IO_RW uint32_t ack_general_call;
	__IO_RW uint32_t enable_status;
	__IO_RW uint32_t fs_spklen;
	__IO_RW uint32_t hs_spklen;

	__IO_RW uint32_t reserved_a8_f4[(0xf4 - 0xa8) >> 2];

	__IO_RW i2c_comp_param_t comp_param_1;
	__IO_RW uint32_t comp_version;
	__IO_RW uint32_t comp_type;
} i2c_dw_apb200a_regs_t;

#define IC_COMP_TYPE_VALUE 0x44570140

#define BIT_FIFO_EMPTY_CTRL BIT(8)
#define BIT_INTR_RX_UNDER BIT(0)
#define BIT_INTR_RX_OVER BIT(1)
#define BIT_INTR_RX_FULL BIT(2)
#define BIT_INTR_TX_OVER BIT(3)
#define BIT_INTR_TX_EMPTY BIT(4)
#define BIT_INTR_TX_ABORT BIT(6)
#define BIT_INTR_RX_DONE BIT(7)
#define BIT_INTR_ACTIVITY BIT(8)
#define BIT_INTR_STOP_DET BIT(9)
#define BIT_INTR_START_DET BIT(10)
#define BIT_INTR_GEN_CALL BIT(11)

#define BIT_MODE_MASTER BIT(0)
#define BIT_SPEED_STANDARD (1 << 1)
#define BIT_SPEED_FAST (2 << 1)
#define BIT_SPEED_FAST_PLUS (2 << 1)
#define BIT_SPEED_HIGH (3 << 1)
#define BIT_RESTART_ENABLE BIT(5)
#define BIT_SLAVE_DISABLE BIT(6)
#define BIT_MASK_ADDR (0x3FF)

/*
 * if the I2C_DYNAMIC_TAR_UPDATE = 0, bit 4 of IC_CON can be RW, otherwise
 * it is readonly, and mirror to TAR register's bit 12, which is RW.
 */
#define BIT_10BIT_MASTER_STATIC BIT(4)
#define BIT_10BIT_MASTER_DYNAMIC BIT(12)

#define BIT_CMD_WRITE (0)
#define BIT_CMD_READ BIT(8)
#define BIT_CMD_STOP BIT(9)
#define BIT_CMD_RESTART BIT(10)

#define BIT_STATUS_SLAVE_ACTIVE BIT(6)
#define BIT_STATUS_MASTER_ACTIVE BIT(5)
#define BIT_STATUS_RX_FULL BIT(4)
#define BIT_STATUS_RX_NOT_EMPTY BIT(3)
#define BIT_STATUS_TX_EMPTY BIT(2)
#define BIT_STATUS_TX_NOT_FULL BIT(1)
#define BIT_STATUS_ACTIVE BIT(0)

#define BIT_ABORT_TRANSFER BIT(1)

#define BIT_ABORT_SOURCE_NO_ACK (0x1F | BIT(18) | BIT(19))
#define BIT_ABORT_ARB_LOST (BIT(12))

#define BIT_STATUS_ENABLE BIT(0)

#define BIT_DMA_RX_ENABLE BIT(0)
#define BIT_DMA_TX_ENABLE BIT(1)
#define BIT_DMA_ENABLE (BIT(0) | BIT(1))

#define CONFIG_INTR_ERROR                                                                          \
	(BIT_INTR_RX_OVER | BIT_INTR_RX_UNDER | BIT_INTR_TX_OVER | BIT_INTR_TX_ABORT)

#define CONFIG_INTR_SEND (BIT_INTR_TX_EMPTY | BIT_INTR_STOP_DET | CONFIG_INTR_ERROR)

#define CONFIG_INTR_RECV                                                                           \
	(BIT_INTR_TX_EMPTY | BIT_INTR_RX_FULL | BIT_INTR_STOP_DET | CONFIG_INTR_ERROR)

#define CONFIG_INTR_SLAVE                                                                          \
	(BIT_INTR_RD_REQ | BIT_INTR_RX_FULL | BIT_INTR_STOP_DET | CONFIG_INTR_ERROR |              \
	 BIT_INTR_START_DET | BIT_INTR_RESTART_DET)

#define CONFIG_MASTER_DEFAULT                                                                      \
	(BIT_SLAVE_DISABLE | BIT_RESTART_ENABLE | BIT_MODE_MASTER | BIT_FIFO_EMPTY_CTRL)

#define ISR_FLAG_TX (0)
#define ISR_FLAG_RX (1)
#define ISR_FLAG_ABRT (2)

/*
 * For example, standard mode is 100KHz, 10000ns per period, 5000ns for
 * SCL low & high level.
 */
#define I2C_SS_SCL_HIGH 4000
#define I2C_SS_SCL_LOW 4700
#define I2C_FS_SCL_HIGH 600
#define I2C_FS_SCL_LOW 1300
#define I2C_FSP_SCL_HIGH 300
#define I2C_FSP_SCL_LOW 600
#ifndef I2C_SCL_400PF
#define I2C_HS_SCL_HIGH 70
#define I2C_HS_SCL_LOW 590
#else
#define I2C_HS_SCL_HIGH 160
#define I2C_HS_SCL_LOW 320
#endif

#endif
