/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DMA_ANN_1P0_H_
#define _DMA_ANN_1P0_H_

#include "sedi_driver_common.h"
#include "sedi_driver_dma.h"

/* driver version */
#define SEDI_DMA_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

#define DMA_MAX_BLOCK_SIZE 4096
#define DMA_MISC_REG_OFFSET 0x1000

/** DMA channel register map. */
typedef struct {
	__IO_RW uint32_t sar_low;                       /**< SAR */
	__IO_RW uint32_t sar_high;                      /**< SAR */
	__IO_RW uint32_t dar_low;                       /**< DAR */
	__IO_RW uint32_t dar_high;                      /**< DAR */
	__IO_RW uint32_t llp_low;                       /**< LLP */
	__IO_RW uint32_t llp_high;                      /**< LLP */
	__IO_RW uint32_t ctrl_low;                      /**< CTL */
	__IO_RW uint32_t ctrl_high;                     /**< CTL */
	__IO_RW uint32_t src_stat_low;                  /**< SSTAT */
	__IO_RW uint32_t src_stat_high;                 /**< SSTAT */
	__IO_RW uint32_t dst_stat_low;                  /**< DSTAT */
	__IO_RW uint32_t dst_stat_high;                 /**< DSTAT */
	__IO_RW uint32_t src_stat_addr_low;             /**< SSTATAR */
	__IO_RW uint32_t src_stat_addr_high;            /**< SSTATAR */
	__IO_RW uint32_t dst_stat_addr_low;             /**< DSTATAR */
	__IO_RW uint32_t dst_stat_addr_high;            /**< DSTATAR */
	__IO_RW uint32_t cfg_low;                       /**< CFG */
	__IO_RW uint32_t cfg_high;                      /**< CFG */
	__IO_R uint32_t reserved0[(0x58 - 0x48) >> 2];  /**< Reserved (SW HS) */
} dma_chan_reg_t;

/** DMA interrupt register map. */
typedef struct {
	__IO_RW uint32_t raw_tfr_low;           /**< RawTfr */
	__IO_RW uint32_t raw_tfr_high;          /**< RawTfr */
	__IO_RW uint32_t raw_block_low;         /**< RawBlock */
	__IO_RW uint32_t raw_block_high;        /**< RawBlock */
	__IO_RW uint32_t raw_src_trans_low;     /**< RawSrcTran */
	__IO_RW uint32_t raw_src_trans_high;    /**< RawSrcTran */
	__IO_RW uint32_t raw_dst_trans_low;     /**< RawDstTran */
	__IO_RW uint32_t raw_dst_trans_high;    /**< RawDstTran */
	__IO_RW uint32_t raw_err_low;           /**< RawErr */
	__IO_RW uint32_t raw_err_high;          /**< RawErr */
	__IO_RW uint32_t status_tfr_low;        /**< StatusTfr */
	__IO_RW uint32_t status_tfr_high;       /**< StatusTfr */
	__IO_RW uint32_t status_block_low;      /**< StatusBlock */
	__IO_RW uint32_t status_block_high;     /**< StatusBlock */
	__IO_RW uint32_t status_src_trans_low;  /**< StatusSrcTran */
	__IO_RW uint32_t status_src_trans_high; /**< StatusSrcTran */
	__IO_RW uint32_t status_dst_trans_low;  /**< StatusDstTran */
	__IO_RW uint32_t status_dst_trans_high; /**< StatusDstTran */
	__IO_RW uint32_t status_err_low;        /**< StatusErr */
	__IO_RW uint32_t status_err_high;       /**< StatusErr */
	__IO_RW uint32_t mask_tfr_low;          /**< MaskTfr */
	__IO_RW uint32_t mask_tfr_high;         /**< MaskTfr */
	__IO_RW uint32_t mask_block_low;        /**< MaskBlock */
	__IO_RW uint32_t mask_block_high;       /**< MaskBlock */
	__IO_RW uint32_t mask_src_trans_low;    /**< MaskSrcTran */
	__IO_RW uint32_t mask_src_trans_high;   /**< MaskSrcTran */
	__IO_RW uint32_t mask_dst_trans_low;    /**< MaskDstTran */
	__IO_RW uint32_t mask_dst_trans_high;   /**< MaskDstTran */
	__IO_RW uint32_t mask_err_low;          /**< MaskErr */
	__IO_RW uint32_t mask_err_high;         /**< MaskErr */
	__IO_RW uint32_t clear_tfr_low;         /**< ClearTfr */
	__IO_RW uint32_t clear_tfr_high;        /**< ClearTfr */
	__IO_RW uint32_t clear_block_low;       /**< ClearBlock */
	__IO_RW uint32_t clear_block_high;      /**< ClearBlock */
	__IO_RW uint32_t clear_src_trans_low;   /**< ClearSrcTran */
	__IO_RW uint32_t clear_src_trans_high;  /**< ClearSrcTran */
	__IO_RW uint32_t clear_dst_trans_low;   /**< ClearDstTran */
	__IO_RW uint32_t clear_dst_trans_high;  /**< ClearDstTran */
	__IO_RW uint32_t clear_err_low;         /**< ClearErr */
	__IO_RW uint32_t clear_err_high;        /**< ClearErr */
	__IO_RW uint32_t status_int_low;        /**< StatusInt */
	__IO_RW uint32_t status_int_high;       /**< StatusInt */
} dma_int_reg_t;

/** DMA miscellaneous register map. */
typedef struct {
	__IO_RW uint32_t cfg_low;                       /**< DmaCfgReg */
	__IO_RW uint32_t cfg_high;                      /**< DmaCfgReg */
	__IO_RW uint32_t chan_en_low;                   /**< ChEnReg */
	__IO_RW uint32_t chan_en_high;                  /**< ChEnReg */
	__IO_R uint32_t
		reserved0[(0x3b8 - 0x3a8) >> 2];        /**< Reserved (SW HS) */
	__IO_RW uint32_t class_pri0_low;                /**< ClassPriority0 */
	__IO_RW uint32_t class_pri0_high;               /**< ClassPriority0 */
	__IO_RW uint32_t class_pri1_low;                /**< ClassPriority1 */
	__IO_RW uint32_t class_pri1_hign;               /**< ClassPriority1 */
	__IO_R uint32_t
		reserved1[(0x400 - 0x3c8) >> 2];        /**< Reserved (SW HS) */
	__IO_RW uint32_t fifo_pri0_low;                 /**< FifoPriority0 */
	__IO_RW uint32_t fifo_pri0_high;                /**< FifoPriority0 */
	__IO_RW uint32_t fifo_pri1_low;                 /**< FifoPriority1 */
	__IO_RW uint32_t fifo_pri1_hign;                /**< FifoPriority1 */
	__IO_RW uint32_t sar_err_low;                   /**< SAR_ERR */
	__IO_RW uint32_t sar_err_high;                  /**< SAR_ERR */
	__IO_RW uint32_t global_cfg_low;                /**< GLOBAL_CFG */
	__IO_RW uint32_t global_cfg_high;               /**< GLOBAL_CFG */
} dma_chann_misc_reg_t;

/* dma misc register*/
typedef struct {
	__IO_RW uint32_t dma_ctl_ch[DMA_CHANNEL_NUM]; /**< DMA_CTL_CH> */
	__IO_R uint32_t reserved0[(0x100 - 0x20) >> 2];
	__IO_RW uint32_t iosf_addr_fillin_dma_ch[DMA_CHANNEL_NUM];
	/**< IOSF_ADDR_FILLIN_DMA_CH> */
	__IO_R uint32_t reserved1[(0x200 - 0x120) >> 2];
	__IO_RW uint32_t iosf_dest_addr_fillin_dma_ch[DMA_CHANNEL_NUM];
	/** <IOSF_DEST_ADDR_FILLIN_DMA_CH> */
	__IO_R uint32_t reserved2[(0x300 - 0x220) >> 2];
	__IO_RW uint32_t dma_xbar_sel[DMA_CHANNEL_NUM]; /**< DMA_XBAR_SEL>*/
	__IO_R uint32_t reserved3[(0x400 - 0x320) >> 2];
	/**<DMA_REGACCESS_CHID >*/
	__IO_RW uint32_t dma_regaccess_chid;
	/**<DMA_ECC_ERR_SRESP >*/
	__IO_RW uint32_t dma_ecc_err_sresp;
	__IO_RW uint32_t d0i3c;                         /**<D0I3C>*/
} dma_misc_regs_t;

/*dma registers address map structure */
typedef struct {
	/**< Channel Register */
	__IO_RW dma_chan_reg_t chan_reg[DMA_CHANNEL_NUM];
	/**< Interrupt Register */
	__IO_RW dma_int_reg_t int_reg;
	__IO_R uint32_t reserved0[(0x398 - 0x368) >> 2];
	/**< Miscellaneous Register */
	__IO_RW dma_chann_misc_reg_t misc_reg;
	__IO_R uint32_t reserved1[(0x1000 - 0x420) >> 2];
	__IO_RW dma_misc_regs_t dev_misc_reg;
} dma_ann_1p0_regs_t;

/* dma channel control register bit map details*/
/* location, part of bits are defined in sedi_driver_dma.h*/
#define CH_CLASS_LOC 29
#define CH_WEIGHT_LOC 18
#define DONE_LOC 17
#define BLOCK_TS_LOC 0
#define DST_SCATTER_EN_LOC 18
#define SRC_GATHER_EN_LOC 17
/* bit field length */
#define CH_CLASS_LEN 3
#define CH_WEIGHT_LEN 11
#define DONE_LEN 1
#define BLOCK_TS_LEN 17
#define LLP_SRC_EN_LEN 1
#define LLP_DST_EN_LEN 1
#define TT_FC_LEN 2
#define DST_SCATTER_EN_LEN 1
#define SRC_GATHER_EN_LEN 1
#define SRC_MSIZE_LEN 3
#define DEST_MSIZE_LEN 3
#define SINC_LEN 1
#define DINC_LEN 1
#define SRC_TR_WIDTH_LEN 3
#define DST_TR_WIDTH_LEN 3
#define INT_EN_LEN 1

/* dma channel config register bit map details*/
/* location */
#define DST_PER_EXT_LOC 30
#define SRC_PER_EXT_LOC 28
#define WR_ISSUE_THD_LOC 18
#define ED_ISSUE_THD_LOC 8
#define DST_PER_LOC 4
#define SRC_PER_LOC 0
#define RELOAD_DST_LOC 31
#define RELOAD_SRC_LOC 30
#define SRC_OPT_BL_LOC 21
#define DST_OPT_BL_LOC 20
#define SRC_HS_POL_LOC 19
#define DST_HS_POL_LOC 18
#define WR_CTLHI_SNP_LOC 17
#define WR_STAT_SNP_LOC 16
#define RD_STAT_SNP_LOC 15
#define RD_LLP_SNP_LOC 14
#define WR_SNP_LOC 13
#define RD_SNP_LOC 12
#define CH_DRAIN_LOC 10
#define FIFO_EMPTY_LOC 9
#define CH_SUSP_LOC 8
#define SS_UPD_EN_LOC 7
#define DS_UPD_EN_LOC 6
#define CTL_HI_UPD_EN_LOC 5
#define HSHAKE_NP_WR_LOC 3
#define ALL_NP_WR_LOC 2
#define SRC_BURST_ALIGN_LOC 1
#define DST_BURST_ALIGN_LOC 0
/* bit field length */
#define DST_PER_EXT_LEN 2
#define SRC_PER_EXT_LEN 2
#define WR_ISSUE_THD_LEN 10
#define ED_ISSUE_THD_LEN 10
#define DST_PER_LEN 4
#define SRC_PER_LEN 4
#define RELOAD_DST_LEN 1
#define RELOAD_SRC_LEN 1
#define SRC_OPT_BL_LEN 1
#define DST_OPT_BL_LEN 1
#define SRC_HS_POL_LEN 1
#define DST_HS_POL_LEN 1
#define WR_CTLHI_SNP_LEN 1
#define WR_STAT_SNP_LEN 1
#define RD_STAT_SNP_LEN 1
#define RD_LLP_SNP_LEN 1
#define WR_SNP_LEN 1
#define RD_SNP_LEN 1
#define CH_DRAIN_LEN 1
#define FIFO_EMPTY_LEN 1
#define CH_SUSP_LEN 1
#define SS_UPD_EN_LEN 1
#define DS_UPD_EN_LEN 1
#define CTL_HI_UPD_EN_LEN 1
#define HSHAKE_NP_WR_LEN 1
#define ALL_NP_WR_LEN 1
#define SRC_BURST_ALIGN_LEN 1
#define DST_BURST_ALIGN_LEN 1

/* dma controller config reg bit map */
#define DMA_EN_LOC 1
#define DMA_EN_LEN 1

/* dma crossbar hs interface select register bit map */
#define RX_TX_LOC 16
#define DEVID_LOC 0
#define RX_TX_LEN 1
#define DEVID_LEN 16

/* dma misc control channel reg content */
/* location*/
#define IOSF_WR_VC01_LOC 11
#define IOSF_RD_VC01_LOC 10
#define WR_NON_SNOOP_LOC 9
#define RD_NON_SNOOP_LOC 8
#define WR_RS_LOC 5
#define RD_RS_LOC 3
#define NON_SNOOP_LOC 2
#define M2M_TYPE_LOC 0

/* bit field length*/
#define IOSF_WR_VC01_LEN 1
#define IOSF_RD_VC01_LEN 1
#define WR_NON_SNOOP_LEN 1
#define RD_NON_SNOOP_LEN 1
#define NON_SNOOP_LEN 1
#define WR_RS_LEN 2
#define RD_RS_LEN 2
#define M2M_TYPE_LEN 2

#endif /* _DMA_ANN_1P0_H_ */
