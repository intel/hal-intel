/*
 * Copyright (c) 2023-2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "ish_dma.h"

#ifdef CONFIG_SOC_INTEL_ISH_5_8_0
void ish_dma_set_msb(uint32_t chan, uint32_t dst_msb, uint32_t src_msb)
{
	/* nothing to do */
	(void)chan;
	(void)dst_msb;
	(void)src_msb;
}

int ish_dma_copy(uint32_t chan, uint64_t dst, uint64_t src, uint32_t length,
		enum dma_mode mode)
{
	int rc = DMA_RC_OK;
	uint32_t src_osr_lmt = (mode & SRC_IS_DRAM) ? DMA_OSR_LMT_DRAM : DMA_OSR_LMT_SRAM;
	uint32_t dst_osr_lmt = (mode & DST_IS_DRAM) ? DMA_OSR_LMT_DRAM : DMA_OSR_LMT_SRAM;

	if (!length) {
		return DMA_RC_OK;
	}

	/* Bringup VNN power rail for accessing SoC fabric */
	write32(PMU_VNN_REQ, (1 << VNN_ID_DMA(chan)));
	while (!(read32(PMU_VNN_REQ_ACK) & PMU_VNN_REQ_ACK_STATUS))
		continue;

	write64(DMAC_CFG_REG, DMAC_CFG_EN);
	mode |= RD_NON_SNOOP | WR_NON_SNOOP;
	write32(MISC_DMA_CTL_REG(chan), mode);
	write64(DMA_CH_CTRL_REG(chan), DMA_CH_CTRL_VAL);
	write64(DMA_CH_CFG2_REG(chan), DMA_CFG_H_VAL(dst_osr_lmt, src_osr_lmt));
	write64(DMA_CH_LLP_REG(chan), 0x0);
	write64(DMA_CH_INT_EN_REG(chan), DMA_CH_INT_EN_VAL);
	write64(DMA_CH_INT_CLR_REG(chan), read64(DMA_CH_INT_STS_REG(chan)));

	while (length) {
		uint32_t chunk = (length > DMA_MAX_BLOCK_SIZE) ?
			DMA_MAX_BLOCK_SIZE : length;
		uint32_t block_ts = chunk >> DMA_SRC_TR_WIDTH;

		if (chunk % block_ts) {
			block_ts++;
		}
		write64(DMA_CH_BLOCK_TS_REG(chan), block_ts - 1);

		write64(DMA_CH_SAR_REG(chan), src);
		write64(DMA_CH_DAR_REG(chan), dst);

		write64(DMAC_CHEN_REG, DMAC_CHEN_CH_BITS(chan));
		while (read64(DMAC_CHEN_REG) & DMAC_CHEN_CH_BITS(chan)) {
			;
		}

		if (read64(DMA_CH_INT_STS_REG(chan)) != DMA_INT_XFER_DONE) {
			write64(DMA_CH_INT_CLR_REG(chan), read64(DMA_CH_INT_STS_REG(chan)));
			rc = DMA_RC_HW;
			break;
		}
		src += chunk;
		dst += chunk;
		length -= chunk;
		write64(DMA_CH_INT_CLR_REG(chan), read64(DMA_CH_INT_STS_REG(chan)));
	}

	/* Mark the DMA VNN power rail as no longer needed */
	write32(PMU_VNN_REQ, (1 << VNN_ID_DMA(chan)));

	return rc;
}

void ish_dma_disable(void)
{
	/* Based on [ROM FAS], 2.1.3 "DMA Controller initialization". */
	uint32_t counter = 0;

	do {
		++counter;
	} while ((uint8_t)read64(DMAC_CHEN_REG) && (counter < (UINT32_MAX / 64)));

	if ((uint8_t)read64(DMAC_CHEN_REG))
		write64(DMAC_RESET_REG, 1);

	write64(DMAC_INTSTS_EN_REG, 0);
	write64(DMAC_INTSIG_EN_REG, 0);
	write64(DMAC_INT_CLR_REG, read64(DMAC_INT_STAT_REG));
	write64(DMAC_CFG_REG, 0);
}
#else
static int dma_init_called; /* If ish_dma_init is called */

static int dma_poll(uint32_t addr, uint32_t expected, uint32_t mask)
{
	int retval = -1;
	uint32_t counter = 0;

	/*
	 * The timeout is approximately 2.2 seconds according to
	 * value of UINT32_MAX, 120MHZ ISH clock frequency and
	 * instruction count which is around 4.
	 */
	while (counter < (UINT32_MAX / 64)) {
		/* test condition */
		if ((read32(addr) & mask) == expected) {
			retval = DMA_RC_OK;
			break;
		}
		counter++;
	}

	return retval;
}

static inline uint32_t interrupt_lock(void)
{
	uint32_t eflags = 0;

	__asm__ volatile("pushfl;" /* save eflag value */
			 "popl  %0;"
			 "cli;"
			 : "=r"(eflags)); /* shut off interrupts */
	return eflags;
}

static inline void interrupt_unlock(uint32_t eflags)
{
	__asm__ volatile("pushl  %0;" /* restore elfag values */
			 "popfl;"
			 :
			 : "r"(eflags));
}

void dma_configure_psize(void)
{
	/* Give chan0 512 bytes for high performance, and chan1 128 bytes. */
	write32(DMA_PSIZE_01, (DMA_PSIZE_UPDATE |
		       (DMA_PSIZE_CHAN1_SIZE << DMA_PSIZE_CHAN1_OFFSET) |
		       (DMA_PSIZE_CHAN0_SIZE << DMA_PSIZE_CHAN0_OFFSET)));
}

void ish_dma_init(void)
{
	uint32_t uma_msb;

	/* configure DMA partition size */
	dma_configure_psize();

	/* set DRAM address 32 MSB for DMA transactions on UMA */
	uma_msb = read32(IPC_UMA_RANGE_LOWER_1);
	ish_dma_set_msb(PAGING_CHAN, uma_msb, uma_msb);

	dma_init_called = 1;
}

int ish_dma_copy(uint32_t chan, uint64_t dst, uint64_t src, uint32_t length,
		 enum dma_mode mode)
{
	uint32_t chan_reg = DMA_REG_BASE + (DMA_CH_REGS_SIZE * chan);
	int rc = DMA_RC_OK;
	uint32_t eflags;
	uint32_t chunk;

	__asm__ volatile("\twbinvd\n"); /* Flush cache before dma start */

	/* Bringup VNN power rail for accessing SoC fabric */
	write32(PMU_VNN_REQ, (1 << VNN_ID_DMA(chan)));
	while (!(read32(PMU_VNN_REQ_ACK) & PMU_VNN_REQ_ACK_STATUS))
		continue;

	/*
	 * shut off interrupts to assure no simultanious
	 * access to DMA registers
	 */
	eflags = interrupt_lock();

	write32(MISC_CHID_CFG_REG, chan); /* Set channel to configure */

	mode |= NON_SNOOP;
	write32(MISC_DMA_CTL_REG(chan), mode); /* Set transfer direction */

	write32(DMA_CFG_REG, DMA_ENABLE);  /* Enable DMA module */
	write32(DMA_LLP(chan_reg), 0);     /* Linked lists are not used */
	write32(DMA_CTL_LOW(chan_reg),
		0 /* Set transfer parameters */ |
		(DMA_CTL_TT_FC_M2M_DMAC << DMA_CTL_TT_FC_SHIFT) |
		(DMA_CTL_ADDR_INC << DMA_CTL_SINC_SHIFT) |
		(DMA_CTL_ADDR_INC << DMA_CTL_DINC_SHIFT) |
		(SRC_TR_WIDTH << DMA_CTL_SRC_TR_WIDTH_SHIFT) |
		(DEST_TR_WIDTH << DMA_CTL_DST_TR_WIDTH_SHIFT) |
		(SRC_BURST_SIZE << DMA_CTL_SRC_MSIZE_SHIFT) |
		(DEST_BURST_SIZE << DMA_CTL_DEST_MSIZE_SHIFT));

	interrupt_unlock(eflags);
	while (length) {
		chunk = (length > DMA_MAX_BLOCK_SIZE) ? DMA_MAX_BLOCK_SIZE
						      : length;

		if (rc != DMA_RC_OK)
			break;

		eflags = interrupt_lock();
		write32(MISC_CHID_CFG_REG, chan); /* Set channel to configure */
		write32(DMA_CTL_HIGH(chan_reg), chunk);	/* Set number of bytes to transfer */
		write32(DMA_DAR(chan_reg), (uint32_t)dst); /* Destination address */
		write32(DMA_SAR(chan_reg), (uint32_t)src); /* Source address */
		write32(DMA_EN_REG, DMA_CH_EN_BIT(chan) |
			     DMA_CH_EN_WE_BIT(chan)); /* Enable the channel */
		interrupt_unlock(eflags);

		rc = ish_wait_for_dma_done(
			chan); /* Wait for trans completion */

		dst += chunk;
		src += chunk;
		length -= chunk;
	}

	/* Mark the DMA VNN power rail as no longer needed */
	write32(PMU_VNN_REQ, (1 << VNN_ID_DMA(chan)));
	return rc;
}

void ish_dma_disable(void)
{
	uint32_t channel;
	uint32_t counter;

	/* Disable DMA on per-channel basis. */
	for (channel = 0; channel <= DMA_MAX_CHANNEL; channel++) {
		write32(MISC_CHID_CFG_REG, channel);
		if (read32(DMA_EN_REG) & DMA_CH_EN_BIT(channel)) {
			/* Write 0 to channel enable bit ... */
			write32(DMA_EN_REG, DMA_CH_EN_WE_BIT(channel));

			/* Wait till it shuts up. */
			counter = 0;
			while ((read32(DMA_EN_REG) & DMA_CH_EN_BIT(channel)) &&
			       counter < (UINT32_MAX / 64))
				counter++;
		}
	}
	write32(DMA_CLR_ERR_REG, 0xFFFFFFFF);
	write32(DMA_CLR_BLOCK_REG, 0xFFFFFFFF);

	write32(DMA_CFG_REG, 0); /* Disable DMA module */
}

int ish_wait_for_dma_done(uint32_t ch)
{
	return dma_poll(DMA_EN_REG_ADDR, 0, DMA_CH_EN_BIT(ch));
}

void ish_dma_set_msb(uint32_t chan, uint32_t dst_msb, uint32_t src_msb)
{
	uint32_t eflags = interrupt_lock();

	write32(MISC_CHID_CFG_REG, chan); /* Set channel to configure */
	write32(MISC_SRC_FILLIN_DMA(chan), src_msb);
	write32(MISC_DST_FILLIN_DMA(chan), dst_msb);
	interrupt_unlock(eflags);
}
#endif
