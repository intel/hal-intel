/*
 * Copyright (c) 2020-2023 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef I3C_HCI_H_
#define I3C_HCI_H_

#include "sedi_driver_i3c.h"
#include <sedi_i3c_regs.h>

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif

#define I3C_DEBUG_PRINTS

/* i3c controller registers */
#define DEVICE_HCI_VERSION          0x0
#define HCI_V0P5                    0x50
#define HCI_V0P5_R02                0x52
#define HCI_V0P7                    0x70
#define HCI_V0P8                    0x80
#define HCI_V0P8_R05                0x85
#define HCI_V1P0                    0x100
#define HCI_V1P2                    0x120

#define DEVICE_ADDR                 0x8
#define DYNAMIC_ADDRESS             0x51
#define DEVICE_RESET_ALL            0x3e
#define DEVICE_SOFT_RESET           (0x1 << 0)
#define RESP_QUEUE_RST              (0x1 << 2)

/* in hci_version >= 0.7,
 * following fields are moved to registers in PIO section
 */
#define INTR_STATUS_TX_THLD_EN              (1 << 0)
#define INTR_STATUS_RX_THLD_EN              (1 << 1)
#define INTR_STATUS_IBI_THLD_EN             (1 << 2)
#define INTR_STATUS_CMD_QUEUE_RDY_EN        (1 << 3)
#define INTR_STATUS_RESP_READY_EN           (1 << 4)
#define INTR_STATUS_TRX_ABT_EN              (1 << 5)
#define INTR_STATUS_TRX_ERR_EN              (1 << 9)

/* hci_version >= 0.7 */
#define PIO_INTR_MASK     (SEDI_RBFVM(I3C, PIO_INTR_STATUS, TX_THLD_STAT, 1) | \
	 SEDI_RBFVM(I3C, PIO_INTR_STATUS, RX_THLD_STAT, 1) | \
	 SEDI_RBFVM(I3C, PIO_INTR_STATUS, IBI_STATUS_THLD_STAT, 1) | \
	 SEDI_RBFVM(I3C, PIO_INTR_STATUS, CMD_QUEUE_READY_STAT, 1) | \
	 SEDI_RBFVM(I3C, PIO_INTR_STATUS, RESP_READY_STAT, 1) | \
	 SEDI_RBFVM(I3C, PIO_INTR_STATUS, TRANSFER_ABORT_STAT, 1) | \
	 SEDI_RBFVM(I3C, PIO_INTR_STATUS, TRANSFER_ERR_STAT, 1))
#define INTR_STATUS_HC_INTERNAL_ERR_EN    (SEDI_RBFVM(I3C, INTR_STATUS, HC_INTERNAL_ERR_STAT, 1))

/* hci_version >= 0.7 */
#define INTR_MASK  (SEDI_RBFVM(I3C, INTR_STATUS, HC_INTERNAL_ERR_STAT, 1))

#define INTR_STATUS_ALL_EN    (PIO_INTR_MASK | INTR_STATUS_HC_INTERNAL_ERR_EN)

#define DEV_ADDR_TBL_START          0x80

/* PIO section starts */
#define RESP_ERR_STATUS_MASK        0xf0000000
#define RESP_ERR_STATUS_SHIFT       28
#define RESP_SUCCESS                0
#define RESP_NACK                   5
#define RESP_TID_MASK               0x0f000000
#define RESP_TID_SHIFT              24
#define RESP_DATA_LEN_MASK          0x0000FFFF
#define RESP_DATA_SHIFT             0
#define TX_RX_DATA_PORT             0x08

#define IBI_STS                     (1 << 31)

#define IBI_DATA_DEFAULT            (0x7)

#define RESP_BUF_THLD_MASK          0x0000ff00
#define RESP_BUF_THLD_SHIFT         8
#define RESP_DEFAULT                (0x0 << RESP_BUF_THLD_SHIFT)

#define CMD_BUF_THLD_MASK           0x000000ff
#define CMD_BUF_THLD_SHIFT          0
#define CMD_DEFAULT                 0x1

#define DEV_CHAR_TBL_START 0x100

/* PIO section ends */


#define I3C_MST_FREE_DEFAULT        0x20

/* Extended capabilities header */
#define EXT_CAPS_HEADER_OFFSET      0x00
typedef union {
	uint32_t value;
	struct {
		uint32_t cap_id:8;
		uint32_t cap_length: 16; /* In DWORDs! */
		uint32_t reserved:8;
	};
} ext_cap_header_t, *p_ext_cap_header_t;
#define EXT_CAP_INVALID             0x00
#define EXT_CAP_HW_ID               0x01
#define EXT_CAP_MASTER_CONFIG       0x02
#define EXT_CAP_MULTI_BUS           0x03
#define EXT_CAP_DEBUG               0x0C
#define EXT_CAP_VENDER_C0           0xC0
#define EXT_CAP_VENDER_C1           0xC1

/*
 * End of HCI MMIO.
 */
#define I3C_MMIO_MAX                0x400

#define I3C_DAT_ENTRY_ASSEMBLER(s_addr, has_payload, sir_rej, mr_rej, ts, d_addr, ring_id, dev_type) \
	(uint32_t)(((s_addr & 0x7F) | ((has_payload & 0x1) << 12) | ((sir_rej & 0x1) << 13) | ((mr_rej & 0x1) << 14) | \
				((ts & 0x1) << 15) | ((d_addr & 0xFF) << 16) | ((ring_id & 0x7) << 26) | ((dev_type & 0x1) << 31)))

/* Regular Transfer Command */
#define I3C_CMD_RGL_ASSEMBLER(cmd_attr, tid, cmd, cp, dev_idx, mode, rw, roc, toc) \
	(uint32_t)(((cmd_attr & 0x7) | (tid & 0xF) << 3 | (cmd & 0xFF) << 7 |  \
				(cp & 0x1) << 15 | (dev_idx & 0x7F) << 16 | (mode & 0x7) << 26 | \
				(rw & 0x1) << 29 | (roc & 0x1) << 30 | (toc & 0x1) << 31))

/* Regular transfer command struct */
typedef struct _regular_cmd_desc_t {
	union {
		struct {
			uint32_t cmd_attr : 3;
			uint32_t tid : 4;
			uint32_t cmd : 8;
			uint32_t cp : 1;
			uint32_t dev_index : 5;
			uint32_t reserved_0 : 5;
			uint32_t mode : 3;
			uint32_t rnw : 1;
			uint32_t roc : 1;
			uint32_t toc : 1;
		};
		uint32_t as_uint32;
	} cmd_low;
	union {
		struct {
			uint32_t reserved_0 : 16;
			uint32_t data_length : 16;
		};
		uint32_t as_uint32;
	} cmd_high;
} regular_cmd_desc_t, *p_regular_cmd_desc_t;

/* Address Assign Command */
#define I3C_CMD_AAC_ASSEMBLER(cmd_attr, tid, cmd, dev_idx, dev_cnt, roc, toc) \
	(uint32_t)(((cmd_attr & 0x7) | (tid & 0xF) << 3 | (cmd & 0xFF) << 7 | \
				(dev_idx & 0x7F) << 16 | (dev_cnt & 0xF) << 26 | (roc & 0x1) << 30 | (toc & 0x1) << 31))

/* Immediate Transfer Command */
#define I3C_CMD_IMM_ASSEMBLER(cmd_attr, tid, cmd, cp, dev_idx, byte_cnt, mode, rw, roc, toc) \
	(uint32_t)(((cmd_attr & 0x7) | (tid & 0xF) << 3 | (cmd & 0xFF) << 7 |  \
				(cp & 0x1) << 15 | (dev_idx & 0x1F) << 16 | (byte_cnt & 0x7) << 23 | (mode & 0x7) << 26 | \
				(rw & 0x1) << 29 | (roc & 0x1) << 30 | (toc & 0x1) << 31))

/* Combo Command */
#define I3C_CMD_COMBO_ASSEMBLER(cmd_attr, tid, cmd, cp, dev_idx, fpm, sub_offset, mode, rw, roc, toc) \
	(uint32_t)(((cmd_attr & 0x7) | (tid & 0xF) << 3 | (cmd & 0xFF) << 7 |  \
				(cp & 0x1) << 15 | (dev_idx & 0x1F) << 16 | (fpm & 0x1) << 24 | (sub_offset & 0x1) << 25 |  \
				(mode & 0x7) << 26 | (rw & 0x1) << 29 | (roc & 0x1) << 30 | (toc & 0x1) << 31))

#define IS_VALID_DCT_ENTRY(entry)    ((((entry) & 0xFF) != 0xFF) && (((entry) & 0xFF) != 0x00))

/*
 * Command Descriptor definition
 * Transfer attributes
 */
#define I3C_CMD_ATTR_XFER                   0x0
#define I3C_CMD_ATTR_IMMED_DATA_XFER        0x1
#define I3C_CMD_ATTR_ASSGN_CMD              0x2
#define I3C_CMD_ATTR_WWR_COMBO_XFER         0x3
#define I3C_CMD_ATTR_INTERNAL_CTRL          0x7

/* Address Assignment Command ID */
#define I3C_CMD_ADDR_ASSGN_TID              0x2
/* Transaction ID */
#define I3C_CMD_RGL_XFER_TID                0x3
/* Combo Transfer ID */
#define I3C_CMD_COMBO_XFER_TID              0x4
/* Direct W/R Command */
#define I3C_DIRECT_WR_TID                   0x5

/* Data Transfer Response on Completion */
#define I3C_CMD_ROC_NOT_REQUIRED            0x0
#define I3C_CMD_ROC_REQUIRED                0x1

/* Data Transfer Terminate on Completion */
#define I3C_CMD_TOC_RESTART                 0x0
#define I3C_CMD_TOC_STOP                    0x1

/* Common */
#define I3C_HCNT_SHIFT                      16

#define I3C_SCL_TIMING(hcnt, lcnt) (hcnt << I3C_HCNT_SHIFT | lcnt)

typedef struct {
	uint32_t low;
	uint32_t high;
} dat_reg;

#define i3c_mmio_write(offset, data)  \
	write32((uint32_t)((unsigned char *)(ctx->base) + (offset)), (data))

#define i3c_mmio_read(offset)  \
	read32((uint32_t)((unsigned char *)(ctx->base) + (offset)))

typedef enum {
	INTR_REG_STATUS = 0x0,
	INTR_REG_STATUS_ENABLE = 0x4,
	INTR_REG_SIGNAL_ENABLE = 0x8,
	INTR_REG_FORCE = 0xC,
} intr_reg_t;

typedef struct {
	uint8_t     dat_cnt;
	dat_reg     dat_sec[SEDI_I3C_DEVICE_NUM_MAX];
	/* DEVICE_CONTROL(0x4) */
	uint32_t    dev_ctrl;
	uint32_t    dev_addr;
	/* INTR_STATUS_EN(0x24) INTR_SIGNAL_EN(0x28) */
	uint32_t    intr_en[2];
	/* PIO section: INTR_STATUS_EN(+0x24) INTR_SIGNAL_EN(+0x28) */
	uint32_t    pio_intr_en[2];
	/* QUEUE_THLD_CTRL(0xd0)  DATA_BUFFER_THLD_CTRL(0xd4)  QUEUE_SIZE_CTRL(0xd8) */
	uint32_t    thld_ctrl[2];
	/* SCL_TIMING (0x214 ~ 0x224)   BUS_FREE_TIMING (0x234) */
	uint32_t    od_timing;
	uint32_t    pp_timing;
	uint32_t    fm_timing;
	uint32_t    fmp_timing;
	uint32_t    ss_timing;
	uint32_t    termn_timing;
	uint32_t    bus_free_timing;
} restore_section_t;

typedef struct _sedi_i3c_context_t {
	uint32_t                *base;
	uint32_t                base_freq;
	uint32_t                hci_version;
	uint32_t                pio_offset;
	uint32_t                debug_offset;
	uint32_t                timing_offset;
	uint32_t                tx_fifo_size; /* in DW */
	uint32_t                rx_fifo_size; /* in DW */

	bool                    initialized;
	restore_section_t       restore_reg;

	uint32_t                intr_signal_mask;

	/* temparory storage for incoming ibi */
	sedi_ibi_t              ibi;

	/* temparory storage for write/read */
	uint8_t                 *buf;
	uint32_t                buf_len;
	uint32_t                buf_index;
	sedi_i3c_direction_t    direction;
	sedi_i3c_position_t     position;

	/* log cb */
	sedi_i3c_log_cb_t       log_cb;
	/* delay cb */
	sedi_i3c_udelay_cb_t    udelay_cb;

	/* event cb */
	sedi_i3c_event_cb_t     event_cb;
	/* ibi cb */
	sedi_i3c_ibi_cb_t       ibi_cb;

	/* private data, context and others */
	void                    *prv_data;

	sedi_i3c_bus_info_t          bus_info;
} sedi_i3c_context_t;

#endif
