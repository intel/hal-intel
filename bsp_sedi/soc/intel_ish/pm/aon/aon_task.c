/*
 * Copyright (c) 2023 -2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "aon_share.h"
#include "aon_defs.h"
#include "../ish_dma.h"
/**
 * Due to very limit AON memory size (typically total 8KB), we don't want to
 * define and allocate whole 256 entries for aontask'IDT, that almost need 2KB
 * (256 * 8), so we just defined the only needed IDT entries:
 * AON_IDT_ENTRY_VEC_FIRST ~  AON_IDT_ENTRY_VEC_LAST
 */
#define AON_IDT_ENTRY_VEC_FIRST		SEDI_VEC_RESET_PREP
#define AON_IDT_ENTRY_VEC_LAST		SEDI_VEC_PMU2IOAPIC

#define PMU_RST_AP_REBOOT 0x40
static void handle_reset(enum ish_pm_state pm_state);

/* ISR for PMU wakeup interrupt */
static void pmu_wakeup_isr(void)
{
	/**
	 * Indicate completion of servicing the interrupt to IOAPIC first
	 * then indicate completion of servicing the interrupt to LAPIC
	 */
	write32(SEDI_IOAPIC_EOI, SEDI_VEC_PMU2IOAPIC);
	write32(LAPIC_EOI, 0x0);

	__asm__ volatile ("iret;");

	__builtin_unreachable();
}

/* ISR for reset prep interrupt */
static void reset_prep_isr(void)
{
	/* mask reset prep avail interrupt */
	write32(PMU_RST_PREP, PMU_RST_PREP_INT_MASK);

	/**
	 * Indicate completion of servicing the interrupt to IOAPIC first
	 * then indicate completion of servicing the interrupt to LAPIC
	 */
	write32(SEDI_IOAPIC_EOI, SEDI_VEC_RESET_PREP);
	write32(LAPIC_EOI, 0x0);

	handle_reset(ISH_PM_STATE_RESET_PREP);

	__builtin_unreachable();
}

/**
 * Use a static data array for aon IDT, and setting IDT header for IDTR
 * register
 *
 * Since on x86, the IDT entry index (count from 0) is also the interrupt
 * vector number, for IDT header, the 'start' filed still need to point to
 * the entry 0, and 'size' must count from entry 0.
 */

static struct idt_entry aon_idt[AON_IDT_ENTRY_VEC_LAST -
				AON_IDT_ENTRY_VEC_FIRST + 1];

static struct idt_header aon_idt_hdr = {

	.limit = (sizeof(struct idt_entry) * (AON_IDT_ENTRY_VEC_LAST + 1)) - 1,
	.entries = (struct idt_entry *)((uint32_t)&aon_idt -
			(sizeof(struct idt_entry) * AON_IDT_ENTRY_VEC_FIRST))
};

/* TSS segment for aon task */
struct tss_entry aon_tss = {
	.prev_task_link = 0,
	.reserved1 = 0,
	.esp0 = (uint8_t *)(CONFIG_AON_PERSISTENT_BASE - AON_SP_RESERVED),
	/* entry 1 in LDT for data segment */
	.ss0 = 0xc,
	.reserved2 = 0,
	.esp1 = 0,
	.ss1 = 0,
	.reserved3 = 0,
	.esp2 = 0,
	.ss2 = 0,
	.reserved4 = 0,
	.cr3 = 0,
	/* task execute entry point */
	.eip = (uint32_t)&ish_aon_main,
	.eflags = 0,
	.eax = 0,
	.ecx = 0,
	.edx = 0,
	.ebx = 0,
	/* set stack top pointer at the end of usable aon memory */
	.esp = CONFIG_AON_PERSISTENT_BASE - AON_SP_RESERVED,
	.ebp = CONFIG_AON_PERSISTENT_BASE - AON_SP_RESERVED,
	.esi = 0,
	.edi = 0,
	/* entry 1 in LDT for data segment */
	.es = 0xc,
	.reserved5 = 0,
	/* entry 0 in LDT for code segment */
	.cs = 0x4,
	.reserved6 = 0,
	/* entry 1 in LDT for data segment */
	.ss = 0xc,
	.reserved7 = 0,
	/* entry 1 in LDT for data segment */
	.ds = 0xc,
	.reserved8 = 0,
	/* entry 1 in LDT for data segment */
	.fs = 0xc,
	.reserved9 = 0,
	/* entry 1 in LDT for data segment */
	.gs = 0xc,
	.reserved10 = 0,
	.ldt_seg_selector = 0,
	.reserved11 = 0,
	.trap_debug = 0,

	/**
	 * TSS's limit specified as 0x67, to allow the task has permission to
	 * access I/O port using IN/OUT instructions,'iomap_base_addr' field
	 * must be greater than or equal to TSS' limit
	 * see 'I/O port permissions' on
	 *	https://en.wikipedia.org/wiki/Task_state_segment
	 */
	.iomap_base_addr = GDT_DESC_TSS_LIMIT
};

/**
 * define code and data LDT segements for aontask
 * code : base = 0x0, limit = 0xFFFFFFFF, Present = 1, DPL = 0
 * data : base = 0x0, limit = 0xFFFFFFFF, Present = 1, DPL = 0
 */
static ldt_entry aon_ldt[2] = {

	/**
	 * entry 0 for code segment
	 * base: 0x0
	 * limit: 0xFFFFFFFF
	 * flag: 0x9B, Present = 1, DPL = 0, code segment
	 */
	{
		.dword_lo = GEN_GDT_DESC_LO(0x0, 0xFFFFFFFF,
				GDT_DESC_CODE_FLAGS),

		.dword_up = GEN_GDT_DESC_UP(0x0, 0xFFFFFFFF,
				GDT_DESC_CODE_FLAGS)
	},

	/**
	 * entry 1 for data segment
	 * base: 0x0
	 * limit: 0xFFFFFFFF
	 * flag: 0x93, Present = 1, DPL = 0, data segment
	 */
	{
		.dword_lo = GEN_GDT_DESC_LO(0x0, 0xFFFFFFFF,
				GDT_DESC_DATA_FLAGS),

		.dword_up = GEN_GDT_DESC_UP(0x0, 0xFFFFFFFF,
				GDT_DESC_DATA_FLAGS)
	}
};


/* shared data structure between main FW and aon task */
struct ish_aon_share aon_share = {
	.magic_id = AON_MAGIC_ID,
	.error_count = 0,
	.last_error = AON_SUCCESS,
	.aon_tss = &aon_tss,
	.aon_ldt = &aon_ldt[0],
	.aon_ldt_size = sizeof(aon_ldt),
};

/* snowball structure */
#define SNOWBALL_BASE	(CONFIG_AON_PERSISTENT_BASE + 256)

struct snowball_struct *snowball = (void *)SNOWBALL_BASE;


/* In IMR DDR, ISH FW image has a manifest header */
#define ISH_FW_IMAGE_MANIFEST_HEADER_SIZE (0x1000)

/* simple count based delay */
static inline void delay(uint32_t count)
{
	while (count)
		count--;
}

static inline void enable_dma_bcg(void)
{
	write32(CCU_BCG_DMA, 1);
}

static inline void disable_dma_bcg(void)
{
	write32(CCU_BCG_DMA, 0);
}

static int store_main_fw(void)
{
	int ret;
	uint64_t imr_fw_addr;
	uint64_t imr_fw_rw_addr;

	imr_fw_addr = (((uint64_t)snowball->uma_base_hi << 32) +
		       snowball->uma_base_lo +
		       snowball->fw_offset +
		       ISH_FW_IMAGE_MANIFEST_HEADER_SIZE);

	imr_fw_rw_addr = (imr_fw_addr
			  + aon_share.main_fw_rw_addr
			  - CONFIG_RAM_BASE);

	/* disable BCG (Block Clock Gating) for DMA, DMA can be accessed now */
	disable_dma_bcg();

	/* store main FW's read and write data region to IMR/UMA DDR */
	ret = ish_dma_copy(
		PAGING_CHAN,
		imr_fw_rw_addr,
		aon_share.main_fw_rw_addr,
		aon_share.main_fw_rw_size,
		SRAM_TO_UMA);

	/* enable BCG for DMA, DMA can't be accessed now */
	enable_dma_bcg();

	if (ret != DMA_RC_OK) {

		aon_share.last_error = AON_ERROR_DMA_FAILED;
		aon_share.error_count++;

		return AON_ERROR_DMA_FAILED;
	}

	return AON_SUCCESS;
}

static int restore_main_fw(void)
{
	int ret;
	uint64_t imr_fw_addr;
	uint64_t imr_fw_ro_addr;
	uint64_t imr_fw_rw_addr;

	imr_fw_addr = (((uint64_t)snowball->uma_base_hi << 32) +
		       snowball->uma_base_lo +
		       snowball->fw_offset +
		       ISH_FW_IMAGE_MANIFEST_HEADER_SIZE);

	imr_fw_ro_addr = (imr_fw_addr
			  + aon_share.main_fw_ro_addr
			  - CONFIG_RAM_BASE);

	imr_fw_rw_addr = (imr_fw_addr
			  + aon_share.main_fw_rw_addr
			  - CONFIG_RAM_BASE);

	/* disable BCG (Block Clock Gating) for DMA, DMA can be accessed now */
	disable_dma_bcg();

	/* restore main FW's read only code and data region from IMR/UMA DDR */
	ret = ish_dma_copy(
		PAGING_CHAN,
		aon_share.main_fw_ro_addr,
		imr_fw_ro_addr,
		aon_share.main_fw_ro_size,
		UMA_TO_SRAM);

	if (ret != DMA_RC_OK) {

		aon_share.last_error = AON_ERROR_DMA_FAILED;
		aon_share.error_count++;

		/* enable BCG for DMA, DMA can't be accessed now */
		enable_dma_bcg();

		return AON_ERROR_DMA_FAILED;
	}

	/* restore main FW's read and write data region from IMR/UMA DDR */
	ret = ish_dma_copy(
			PAGING_CHAN,
			aon_share.main_fw_rw_addr,
			imr_fw_rw_addr,
			aon_share.main_fw_rw_size,
			UMA_TO_SRAM
			);

	/* enable BCG for DMA, DMA can't be accessed now */
	enable_dma_bcg();

	if (ret != DMA_RC_OK) {

		aon_share.last_error = AON_ERROR_DMA_FAILED;
		aon_share.error_count++;

		return AON_ERROR_DMA_FAILED;
	}

	return AON_SUCCESS;
}

#define SRAM_POWER_OFF_BANKS	CONFIG_RAM_BANKS

/* SRAM needs time to enter retention mode */
#define CYCLES_PER_US                  100
#ifdef CONFIG_SOC_INTEL_ISH_5_8_0
#define SRAM_RETENTION_US_DELAY        20
#else
#define SRAM_RETENTION_US_DELAY        5
#endif
#define SRAM_RETENTION_CYCLES_DELAY    (SRAM_RETENTION_US_DELAY * CYCLES_PER_US)

#ifdef CONFIG_SOC_INTEL_ISH_5_6_0
#define SRAM_WARM_UP_COUNTER	(1000)
#define SRAM_CTRL_ERASE_SIZE_BIT	2
#define SRAM_CTRL_ERASE_BYTE_TO_QWORD	3
#define SRAM_BANK_ERASE_SIZE                                                   \
	((CONFIG_RAM_BANK_SIZE >> SRAM_CTRL_ERASE_BYTE_TO_QWORD)               \
	 << SRAM_CTRL_ERASE_SIZE_BIT)
#define SRAM_TILES		(CONFIG_RAM_BANKS * 2)

static uint32_t sram_toggle_tile(uint32_t tile_id, uint32_t enable)
{
	uint32_t pmu_sram_val = read32(PMU_SRAM_PG_EN);
	uint32_t pmu_toggle_bit = (1 << tile_id);
	uint32_t u = 0;

	if (enable && (pmu_sram_val & pmu_toggle_bit)) {
		pmu_sram_val &= ~pmu_toggle_bit;
		write32(PMU_SRAM_PG_EN, pmu_sram_val);
		while (!(pmu_toggle_bit & read32(PMU_SRAM_PWR_STATUS)))
			;
		for (u = 0; u < SRAM_WARM_UP_COUNTER; ++u)
			__asm__ volatile ("nop");
	} else if (!enable && (~pmu_sram_val & pmu_toggle_bit)) {
		pmu_sram_val |= pmu_toggle_bit;
		write32(PMU_SRAM_PG_EN, pmu_sram_val);
		while ((pmu_toggle_bit & read32(PMU_SRAM_PWR_STATUS)))
			;
		for (u = 0; u < SRAM_WARM_UP_COUNTER; ++u)
			__asm__ volatile ("nop");
	} else {
		enable = 0;
	}
	return enable;
}

static void sram_toggle_bank(unsigned int bank_number, unsigned int enable)
{
	uint32_t tile_id = bank_number << 1;

	if (enable) {
		if (sram_toggle_tile(tile_id, enable) &&
		    sram_toggle_tile((tile_id + 1), enable)) {
			write32(ISH_SRAM_CTRL_ERASE_ADDR,
				CONFIG_RAM_BASE +
					bank_number * CONFIG_RAM_BANK_SIZE);
			write32(ISH_SRAM_CTRL_ERASE_CTRL, (SRAM_BANK_ERASE_SIZE | 0x1));
			while (read32(ISH_SRAM_CTRL_ERASE_CTRL) & 0x1)
				;
		}
	} else {
		sram_toggle_tile(tile_id, enable);
		sram_toggle_tile((tile_id + 1), enable);
	}

	write32(ISH_SRAM_CTRL_INTR, read32(ISH_SRAM_CTRL_INTR));
}

static void sram_power(int on)
{
	int i;

	for (i = 0; i < SRAM_POWER_OFF_BANKS; i++) {
		sram_toggle_bank(i, on);
	}
}
#else

/**
 * check SRAM bank i power gated status in PMU_SRAM_PG_EN register
 * 1: power gated 0: not power gated
 */
#define BANK_PG_STATUS(i)	(read32(PMU_SRAM_PG_EN) & (0x1 << (i)))

/* enable power gate of a SRAM bank */
#define BANK_PG_ENABLE(i)	(write32(PMU_SRAM_PG_EN, (read32(PMU_SRAM_PG_EN) | (0x1 << (i)))))

/* disable power gate of a SRAM bank */
#define BANK_PG_DISABLE(i)                                                     \
	(write32(PMU_SRAM_PG_EN, (read32(PMU_SRAM_PG_EN) & (~(0x1 << (i))))))

/**
 * check SRAM bank i disabled status in ISH_SRAM_CTRL_CSFGR register
 * 1: disabled 0: enabled
 */
#define BANK_DISABLE_STATUS(i)	(read32(ISH_SRAM_CTRL_CSFGR) & (0x1 << ((i) + 4)))

/* enable a SRAM bank in ISH_SRAM_CTRL_CSFGR register */
#define BANK_ENABLE(i)                                                         \
	(write32(ISH_SRAM_CTRL_CSFGR,                                          \
		 (read32(ISH_SRAM_CTRL_CSFGR) & (~(0x1 << ((i) + 4))))))

/* disable a SRAM bank in ISH_SRAM_CTRL_CSFGR register */
#define BANK_DISABLE(i)                                                        \
	(write32(ISH_SRAM_CTRL_CSFGR,                                          \
		 (read32(ISH_SRAM_CTRL_CSFGR) | (0x1 << ((i) + 4)))))

/* SRAM needs time to warm up after power on */
#define SRAM_WARM_UP_DELAY_CNT		10

static void sram_power(int on)
{
	int i;
	uint32_t bank_size;
	uint32_t sram_addr;
	uint32_t erase_cfg;

	bank_size = CONFIG_RAM_BANK_SIZE;
	sram_addr = CONFIG_RAM_BASE;

	/**
	 * set erase size as one bank, erase control register using DWORD as
	 * size unit, and using 0 based length, i.e if set 0, will erase one
	 * DWORD
	 */
	erase_cfg = ((bank_size >> 3) << 2) | 0x1;

	for (i = 0; i < SRAM_POWER_OFF_BANKS; i++) {

		if (on && (BANK_PG_STATUS(i))) {

			/* power on and enable a bank */
			BANK_PG_DISABLE(i);

			delay(SRAM_WARM_UP_DELAY_CNT);

			/* erase a bank */
			write32(ISH_SRAM_CTRL_ERASE_ADDR, sram_addr + (i * bank_size));
			write32(ISH_SRAM_CTRL_ERASE_CTRL, erase_cfg);

			/* wait erase complete */
			while (read32(ISH_SRAM_CTRL_ERASE_CTRL) & 0x1)
				continue;

		} else {
			/* disable and power off a bank */
			BANK_PG_ENABLE(i);
		}

		/**
		 * clear interrupt status register, not allow generate SRAM
		 * interrupts. Bringup already masked all SRAM interrupts when
		 * booting ISH
		 */
		write32(ISH_SRAM_CTRL_INTR, 0xFFFFFFFF);

	}
}
#endif

#define RTC_TICKS_IN_SECOND 32768

static uint64_t get_rtc(void)
{
	uint32_t lower;
	uint32_t upper;

	do {
		upper = read32(MISC_ISH_RTC_COUNTER1);
		lower = read32(MISC_ISH_RTC_COUNTER0);
	} while (upper != read32(MISC_ISH_RTC_COUNTER1));

	return ((uint64_t)upper << 32) | lower;
}

static int is_ipapg_allowed(void)
{
	uint32_t power_ctrl_enabled, sw_power_req, power_ctrl_wake;
	int system_power_state;

	system_power_state = ((read32(PMU_PMC_HOST_RST_CTL) & PMU_HOST_RST_B) == 0);

	write32(PMU_PMC_HOST_RST_CTL, read32(PMU_PMC_HOST_RST_CTL));

	power_ctrl_enabled = read32(PMU_D3_STATUS);
	sw_power_req = read32(PMU_SW_PG_REQ);
	power_ctrl_wake = read32(PMU_PMC_PG_WAKE);

	if (system_power_state)
		power_ctrl_enabled |= PMU_PCE_PG_ALLOWED;

	write32(PMU_INTERNAL_PCE, ((power_ctrl_enabled & PMU_PCE_SHADOW_MASK) |
			   PMU_PCE_CHANGE_DETECTED | PMU_PCE_CHANGE_MASK));

	write32(PMU_SW_PG_REQ, (sw_power_req | PMU_SW_PG_REQ_B_RISE |
			PMU_SW_PG_REQ_B_FALL));
	write32(PMU_PMC_PG_WAKE, (power_ctrl_wake | PMU_PMC_PG_WAKE_RISE |
			  PMU_PMC_PG_WAKE_FALL));
	write32(PMU_D3_STATUS, (read32(PMU_D3_STATUS) & (PMU_D0I3_ENABLE_MASK |
					   PMU_D3_BIT_SET | PMU_BME_BIT_SET)));

	power_ctrl_enabled = read32(PMU_D3_STATUS);
	sw_power_req = read32(PMU_SW_PG_REQ);
	power_ctrl_wake = read32(PMU_PMC_PG_WAKE);

	if (system_power_state) {
		uint64_t rtc_start = get_rtc();
		uint64_t rtc_end;

		while (power_ctrl_wake & PMU_PMC_PG_WAKE_VAL) {
			power_ctrl_wake = read32(PMU_PMC_PG_WAKE);
			rtc_end = get_rtc();
			if (rtc_end - rtc_start > RTC_TICKS_IN_SECOND)
				break;
		}
	}

	if (((power_ctrl_enabled & PMU_PCE_PG_ALLOWED) || system_power_state) &&
	    (((sw_power_req & PMU_SW_PG_REQ_B_VAL) == 0) ||
	     ((power_ctrl_enabled & PMU_PCE_PMCRE) == 0)))
		return 1;
	else
		return 0;
}

#define NUMBER_IRQ_PINS 30
static uint32_t ioapic_rte[NUMBER_IRQ_PINS];

static int do_ipapg(void)
{
	int ret;
	uint32_t rte_offset = SEDI_IOAPIC_IOREDTBL;

	for (int pin = 0; pin < NUMBER_IRQ_PINS; pin++) {
		write32(SEDI_IOAPIC_IDX, rte_offset + pin * 2);
		ioapic_rte[pin] = read32(SEDI_IOAPIC_WDW);
	}

	ret = ipapg();

	rte_offset = SEDI_IOAPIC_IOREDTBL;
	for (int pin = 0; pin < NUMBER_IRQ_PINS; pin++) {
		write32(SEDI_IOAPIC_IDX, rte_offset + pin * 2);
		write32(SEDI_IOAPIC_WDW, ioapic_rte[pin]);
	}

	return ret;
}

static inline void set_vnnred_aoncg(void)
{
	write32(PMU_VNNAON_RED, 1);
	write32(CCU_AONCG_EN, 1);

	write32(CCU_TCG_EN, 1);
	write32(CCU_TCG_ENABLE, 0);
	write32(CCU_BCG_ENABLE, 0);
}

static inline void clear_vnnred_aoncg(void)
{
	write32(PMU_VNNAON_RED, 0);
	write32(CCU_AONCG_EN, 0);

	write32(CCU_TCG_EN, 0);
	write32(CCU_TCG_ENABLE, 1);
	write32(CCU_BCG_ENABLE, 1);
}

#if (defined(CONFIG_SOC_INTEL_ISH_5_6_0) || defined(CONFIG_SOC_INTEL_ISH_5_8_0))
#define STRINGIFY(x)			#x
#define SLINE(num)			STRINGIFY(num)
#define RETENTION_EXIT_CYCLES_DELAY	5
#ifdef CONFIG_SOC_INTEL_ISH_5_8_0
#define SRAM_PG_BITS(i) (0x3 << (2 * i))
#define BANK_PWR_STATUS(i) (read32(PMU_SRAM_PWR_STATUS) & SRAM_PG_BITS(i))
#define BANK_DS_ENABLE(i) \
		(write32(PMU_SRAM_DEEPSLEEP, read32(PMU_SRAM_DEEPSLEEP) | (0x3 << (2 * i))))

#define BANK_DS_DISABLE(i) \
		(write32(PMU_SRAM_DEEPSLEEP, read32(PMU_SRAM_DEEPSLEEP) & ~(0x3 << (2 * i))))
#endif


static void sram_enter_sleep_mode(void)
{
#if defined(CONFIG_SOC_INTEL_ISH_5_6_0)
	uint32_t val, sum_mask, mask;

	sum_mask = mask = 0x1;
	val = read32(PMU_SRAM_DEEPSLEEP);
	while (sum_mask <= CONFIG_RAM_BANK_TILE_MASK) {
		if (!(val & mask)) {
			write32(PMU_SRAM_DEEPSLEEP, val | sum_mask);
			while (read32(PMU_SRAM_PWR_STATUS) & mask)
				;
		}
		mask <<= 1;
		sum_mask += mask;
	}
#else
	for (int i = 0; i < SRAM_POWER_OFF_BANKS; i++) {
		BANK_DS_ENABLE(i);
		while (BANK_PWR_STATUS(i))
			;
	}
#endif
}

static void sram_exit_sleep_mode(void)
{
#if defined(CONFIG_SOC_INTEL_ISH_5_6_0)
	uint32_t val, sum_mask, mask;

	sum_mask = mask = 0x1;
	val = read32(PMU_SRAM_DEEPSLEEP);
	while (sum_mask <= CONFIG_RAM_BANK_TILE_MASK) {
		if ((val & mask)) {
			write32(PMU_SRAM_DEEPSLEEP, val & ~sum_mask);
			while (!(read32(PMU_SRAM_PWR_STATUS) & mask))
				;
			__asm__ volatile (
					"movl $"SLINE(RETENTION_EXIT_CYCLES_DELAY)", %%ecx;"
					"loop .;\n\t"
					:
					:
					: "ecx"
					);
		}
		mask <<= 1;
		sum_mask += mask;
	}
#else
	for (int i = 0; i < SRAM_POWER_OFF_BANKS; i++) {
		if (!BANK_PWR_STATUS(i)) {
			BANK_DS_DISABLE(i);
			delay(RETENTION_EXIT_CYCLES_DELAY);
			while (!BANK_PWR_STATUS(i))
				;
		}
	}
#endif
}
#endif

static void handle_d0i2(void)
{
	uint32_t reg_val;

	pg_exit_save_ctx();
	aon_share.pg_exit = 0;

#if (defined(CONFIG_SOC_INTEL_ISH_5_6_0) || defined(CONFIG_SOC_INTEL_ISH_5_8_0))
	sram_enter_sleep_mode();
#else
	/* set main SRAM into retention mode*/
	write32(PMU_LDO_CTRL, (PMU_LDO_ENABLE_BIT
		| PMU_LDO_RETENTION_BIT));
#endif
	/* delay some cycles before halt */
	delay(SRAM_RETENTION_CYCLES_DELAY);

	set_vnnred_aoncg();

	if (is_ipapg_allowed()) {
		uint32_t sram_cfg_reg;

		sram_cfg_reg = read32(ISH_SRAM_CTRL_CSFGR);

		aon_share.pg_exit = do_ipapg();

		if (aon_share.pg_exit)
			write32(ISH_SRAM_CTRL_CSFGR, sram_cfg_reg);
	} else {
		ish_mia_halt();
	}

	/* wakeup from PMU interrupt */

	clear_vnnred_aoncg();

#if (defined(CONFIG_SOC_INTEL_ISH_5_6_0) || defined(CONFIG_SOC_INTEL_ISH_5_8_0))
	sram_exit_sleep_mode();
#else
	/* set main SRAM intto normal mode */
	write32(PMU_LDO_CTRL, PMU_LDO_ENABLE_BIT);

	/**
	 * poll LDO_READY status to make sure SRAM LDO is on
	 * (exited retention mode)
	 */
	while (!(read32(PMU_LDO_CTRL) & PMU_LDO_READY_BIT))
		continue;
#endif

	reg_val = read32(PMU_RST_PREP);
	if ((reg_val & PMU_RST_PREP_AVAIL) ||
		((reg_val & PMU_RST_PREP_RESET_TYPE) == PMU_RST_AP_REBOOT)) {
		handle_reset(ISH_PM_STATE_RESET_PREP);
	}

	if (aon_share.pg_exit)
		ish_dma_set_msb(PAGING_CHAN, aon_share.uma_msb,
				aon_share.uma_msb);
}

static void handle_d0i3(void)
{
	int ret;
	uint32_t reg_val;

	pg_exit_save_ctx();
	aon_share.pg_exit = 0;

	/* store main FW 's context to IMR DDR from main SRAM */
	ret = store_main_fw();

	/* if store main FW failed, then switch back to main FW */
	if (ret != AON_SUCCESS)
		return;

	/* power off main SRAM */
	sram_power(0);

	set_vnnred_aoncg();

	if (is_ipapg_allowed()) {
		uint32_t sram_cfg_reg;

		sram_cfg_reg = read32(ISH_SRAM_CTRL_CSFGR);

		aon_share.pg_exit = do_ipapg();

		if (aon_share.pg_exit)
			write32(ISH_SRAM_CTRL_CSFGR, sram_cfg_reg);
	} else {
		ish_mia_halt();
	}

	/* wakeup from PMU interrupt */

	clear_vnnred_aoncg();

	reg_val = read32(PMU_RST_PREP);
	if ((reg_val & PMU_RST_PREP_AVAIL) ||
		((reg_val & PMU_RST_PREP_RESET_TYPE) == PMU_RST_AP_REBOOT)) {
		handle_reset(ISH_PM_STATE_RESET_PREP);
	}

	/* power on main SRAM */
	sram_power(1);

	if (aon_share.pg_exit)
		ish_dma_set_msb(PAGING_CHAN, aon_share.uma_msb,
				aon_share.uma_msb);

	/* restore main FW 's context to main SRAM from IMR DDR */
	ret = restore_main_fw();

	if (ret != AON_SUCCESS) {
		/* we can't switch back to main FW now, reset ISH */
		handle_reset(ISH_PM_STATE_RESET);
	}
}

static void handle_d3(void)
{
	/* handle D3 */
	handle_reset(ISH_PM_STATE_RESET);
}

static inline void disable_csme_csrirq(void)
{
	write32(IPC_PIMR_CIM_SEC, 1);
}

static void handle_reset(enum ish_pm_state pm_state)
{
	(void)(pm_state);

	/* disable watch dog */
	write32(WDT_CONTROL, (read32(WDT_CONTROL) & (~WDT_CONTROL_ENABLE_BIT)));

	/* disable all gpio interrupts */
	write32(ISH_GPIO_GRER, 0);
	write32(ISH_GPIO_GFER, 0);
	write32(ISH_GPIO_GIMR, 0);

	/* disable CSME CSR irq */
	disable_csme_csrirq();

	while (1) {
		/* clear ISH2HOST doorbell register */
		write32(IPC_ISH2HOST_DOORBELL_ADDR, 0);

		/* clear error register in MISC space */
		write32(MISC_ISH_ECC_ERR_SRESP, 1);

		/*
		 * Disable power gating of RF(Cache) and ROMs.
		 *
		 * Before switch to aon task, RF and ROMs are already
		 * power gated, so we need disable the power gating
		 * before reset to ROM, to make sure ROM code runs
		 * correctly.
		 */
		write32(PMU_RF_ROM_PWR_CTRL, 0);

		/* reset ISH minute-ia cpu core, will goto ISH ROM */
		ish_mia_reset();

		__builtin_unreachable();

		ish_mia_halt();
	}

}

static void handle_unknown_state(void)
{
	aon_share.last_error = AON_ERROR_NOT_SUPPORT_POWER_MODE;
	aon_share.error_count++;

	/* switch back to main FW */
}

void ish_aon_main(void)
{

	/* set PMU wakeup interrupt gate using LDT code segment selector(0x4) */
	aon_idt[AON_IDT_ENTRY_VEC_LAST -
		AON_IDT_ENTRY_VEC_FIRST].dword_lo =
		GEN_IDT_DESC_LO(&pmu_wakeup_isr, 0x4, IDT_DESC_FLAGS);

	aon_idt[AON_IDT_ENTRY_VEC_LAST -
		AON_IDT_ENTRY_VEC_FIRST].dword_up =
		GEN_IDT_DESC_UP(&pmu_wakeup_isr, 0x4, IDT_DESC_FLAGS);

	/*
	 * set reset prep interrupt gate using LDT code segment
	 * selector(0x4)
	 */
	aon_idt[0].dword_lo = GEN_IDT_DESC_LO(&reset_prep_isr,
		0x4, IDT_DESC_FLAGS);

	aon_idt[0].dword_up = GEN_IDT_DESC_UP(&reset_prep_isr,
		0x4, IDT_DESC_FLAGS);

	while (1) {

		/**
		 *  will start to run from here when switched to aontask from
		 *  the second time
		 */

		/* save main FW's IDT and load aontask's IDT */
		__asm__ volatile (
				"sidtl %0;\n"
				"lidtl %1;\n"
				:
				: "m" (aon_share.main_fw_idt_hdr),
				  "m" (aon_idt_hdr)
				);

		aon_share.last_error = AON_SUCCESS;

		switch (aon_share.pm_state) {
		case ISH_PM_STATE_D0I2:
			handle_d0i2();
			break;
		case ISH_PM_STATE_D0I3:
			handle_d0i3();
			break;
		case ISH_PM_STATE_D3:
			handle_d3();
			break;
		case ISH_PM_STATE_RESET:
		case ISH_PM_STATE_RESET_PREP:
			handle_reset(aon_share.pm_state);
			break;
		default:
			handle_unknown_state();
			break;
		}

		/* check if D3 rising status */
		if (read32(PMU_D3_STATUS) &
		    (PMU_D3_BIT_RISING_EDGE_STATUS | PMU_D3_BIT_SET)) {
			if (!(aon_share.host_in_suspend)) {
				aon_share.pm_state = ISH_PM_STATE_D3;
				handle_d3();
			}
		}

		/* restore main FW's IDT and switch back to main FW */
		__asm__ volatile(
				"lidtl %0;\n"
				:
				: "m" (aon_share.main_fw_idt_hdr)
				);

		if (aon_share.pg_exit) {
			mainfw_gdt.entries[tr / sizeof(struct gdt_entry)]
				.flags &= 0xfd;
			pg_exit_restore_ctx();
		}

		__asm__ volatile ("iret;");
	}
}
