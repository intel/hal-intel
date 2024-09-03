/*
 * Copyright (c) 2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "aon/aon_share.h"
#include "ish_dma.h"
#include "ish_pm.h"
#include "sedi_driver_core.h"
#include "sedi_driver_uart.h"
#include <sedi_driver_rtc.h>
#include <zephyr/sys/printk.h>
#include <zephyr/irq.h>
#include <zephyr/drivers/interrupt_controller/ioapic.h>
#include <zephyr/arch/x86/ia32/segmentation.h>

/* defined in link script: soc/x86/intel_ish/scripts/ish_linker.ld */
extern uint32_t __text_region_start;
extern uint32_t __rodata_region_end;
extern uint32_t _image_ram_start;
extern uint32_t _image_ram_end;

/* Disable debug print by default */
#define PM_DEBUG_PRINTS 1

#ifdef PM_DEBUG_PRINTS
#define PM_LOG(...) printk(__VA_ARGS__)
#else
#define PM_LOG(...)
#endif

#define DLL	0x0
#define DLH	0x4
#define LCR	0xC
#define DLF	0xC0

static sedi_uart_config_t uart0_cfg, uart1_cfg, uart2_cfg;

static void uart_to_idle(void)
{
	sedi_uart_get_config(SEDI_UART_0, &uart0_cfg);
	write32(SEDI_IREG_BASE(UART, 0) + LCR, 0x80);
	write32(SEDI_IREG_BASE(UART, 0)  + DLL, 0x1);
	write32(SEDI_IREG_BASE(UART, 0)  + DLH, 0x0);
	write32(SEDI_IREG_BASE(UART, 0)  + LCR, 0);

	sedi_uart_get_config(SEDI_UART_0, &uart1_cfg);
	write32(SEDI_IREG_BASE(UART, 1)  + LCR, 0x80);
	write32(SEDI_IREG_BASE(UART, 1)  + DLL, 0x1);
	write32(SEDI_IREG_BASE(UART, 1)  + DLH, 0x0);
	write32(SEDI_IREG_BASE(UART, 1)  + LCR, 0);

	sedi_uart_get_config(SEDI_UART_0, &uart2_cfg);
	write32(SEDI_IREG_BASE(UART, 2)  + LCR, 0x80);
	write32(SEDI_IREG_BASE(UART, 2)  + DLL, 0x1);
	write32(SEDI_IREG_BASE(UART, 2)  + DLH, 0x0);
	write32(SEDI_IREG_BASE(UART, 2)  + LCR, 0);
}

static void uart_port_restore(void)
{
	sedi_uart_set_config(SEDI_UART_0, &uart0_cfg);
	sedi_uart_set_config(SEDI_UART_1, &uart1_cfg);
	sedi_uart_set_config(SEDI_UART_2, &uart2_cfg);
}

static void pg_exit_restore_hw(void)
{
	write32(LAPIC_SPUR, LAPIC_ENABLE | LAPIC_SPUR_RESET);

	write32(CCU_RST_HST, read32(CCU_RST_HST));
	write32(CCU_TCG_ENABLE, 0);
	write32(CCU_BCG_ENABLE, 0);

	write32(CCU_BCG_MIA, 0);
	write32(CCU_BCG_DMA, 0);
	write32(CCU_BCG_I2C, 0);
	write32(CCU_BCG_SPI, 0);
	write32(CCU_BCG_UART, 0);
	write32(CCU_BCG_GPIO, 0);
}

/**
 * ISH PMU does not support both-edge interrupt triggered gpio configuration.
 * If both edges are configured, then the ISH can't stay in low power mode
 * because it will exit immediately.
 *
 * To keep LPM fucntions intact and still support both edge configuration,
 * the alternative way is:
 * Before entering LPM, scan all gpio pins which are configured to be
 * triggered by both-edge, and temporarily set each gpio pin to the single
 * edge expected to be triggered next time, that is, opposite to its value.
 * After exiting LPM, then restore the both-edge trigger configuration.
 **/
static uint32_t convert_both_edge_gpio_to_single_edge(void)
{
	uint32_t both_edge_pins = 0;
	int i = 0;

	/*
	 * scan GPIO GFER, GRER and GIMR registers to find the both edge
	 * interrupt trigger mode enabled pins.
	 */
	for (i = 0; i < 32; i++) {
		if (read32(ISH_GPIO_GIMR) & BIT(i) && read32(ISH_GPIO_GRER) & BIT(i) &&
		    read32(ISH_GPIO_GFER) & BIT(i)) {
			/* Record the pin so we can restore it later */
			both_edge_pins |= BIT(i);

			if (read32(ISH_GPIO_GPLR) & BIT(i)) {
				/* pin is high, just keep falling edge mode */
				write32(ISH_GPIO_GRER, read32(ISH_GPIO_GRER) & ~BIT(i));
			} else {
				/* pin is low, just keep rising edge mode */
				write32(ISH_GPIO_GFER, read32(ISH_GPIO_GFER) & ~BIT(i));
			}
		}
	}

	return both_edge_pins;
}

static void restore_both_edge_gpio_config(uint32_t both_edge_pin_map)
{
	write32(ISH_GPIO_GRER, read32(ISH_GPIO_GRER) | both_edge_pin_map);
	write32(ISH_GPIO_GFER, read32(ISH_GPIO_GFER) | both_edge_pin_map);
}

/* power management internal context data structure */
struct pm_context {
	/* aontask image valid flag */
	int aon_valid;
	/* point to the aon shared data in aontask */
	struct ish_aon_share *aon_share;
	/* TSS segment selector for task switching */
	int aon_tss_selector[2];
} __attribute__((packed));

static struct pm_context pm_ctx = {
	.aon_valid = 0,
	/* aon shared data located in the start of aon memory */
	.aon_share = (struct ish_aon_share *)CONFIG_AON_RAM_BASE,
};

/* D0ix statistics data, including each state's count and total stay time */
struct pm_stat {
	uint64_t count;
	uint64_t total_time_us;
};

struct pm_statistics {
	struct pm_stat d0i0;
	struct pm_stat d0i1;
	struct pm_stat d0i2;
	struct pm_stat d0i3;
	struct pm_stat pg;
};

static struct pm_statistics pm_stats;

/*
 * Log a new statistic
 *
 * t0: start time, in us
 * t1: end time, in us
 */
static void log_pm_stat(struct pm_stat *stat, uint64_t t0, uint64_t t1)
{
	stat->total_time_us += t1 - t0;
	stat->count++;
}

extern struct pseudo_descriptor _gdt;

/* TSS descriptor for saving main FW's cpu context during aontask switching */
static struct tss_entry main_tss;

/**
 * add new entry in GDT
 *
 * @param desc_lo	lower DWORD of the entry descriptor
 * @param desc_up	upper DWORD of the entry descriptor
 *
 * @return		the descriptor selector index of the added entry
 */
static uint32_t add_gdt_entry(uint32_t desc_lo, uint32_t desc_up)
{
	int index;
	struct gdt_header *gdt_ptr = (struct gdt_header *)&_gdt;
	struct gdt_entry *__gdt = (struct gdt_entry *)(gdt_ptr->entries);

	/**
	 * get the first empty entry of GDT which defined in crt0.S
	 * each entry has a fixed size of 8 bytes
	 */
	index = (gdt_ptr->limit + 1) >> 3;

	/* add the new entry descriptor to the GDT */
	__gdt[index].dword_lo = desc_lo;
	__gdt[index].dword_up = desc_up;

	/* update GDT's limit size */
	gdt_ptr->limit += sizeof(struct gdt_entry);

	return ((index + 1) << 3) - sizeof(struct gdt_entry);
}

static void init_aon_task(void)
{
	uint32_t desc_lo, desc_up, main_tss_index;
	struct ish_aon_share *aon_share = pm_ctx.aon_share;
	struct tss_entry *aon_tss = aon_share->aon_tss;

	if (aon_share->magic_id != AON_MAGIC_ID) {
		pm_ctx.aon_valid = 0;
		return;
	}

	pm_ctx.aon_valid = 1;

	pm_ctx.aon_tss_selector[0] = 0;

	main_tss.iomap_base_addr = GDT_DESC_TSS_LIMIT;

	desc_lo = GEN_GDT_DESC_LO((uint32_t)&main_tss,
			GDT_DESC_TSS_LIMIT, GDT_DESC_TSS_FLAGS);
	desc_up = GEN_GDT_DESC_UP((uint32_t)&main_tss,
			GDT_DESC_TSS_LIMIT, GDT_DESC_TSS_FLAGS);
	main_tss_index = add_gdt_entry(desc_lo, desc_up);

	desc_lo = GEN_GDT_DESC_LO((uint32_t)aon_tss,
			GDT_DESC_TSS_LIMIT, GDT_DESC_TSS_FLAGS);
	desc_up = GEN_GDT_DESC_UP((uint32_t)aon_tss,
			GDT_DESC_TSS_LIMIT, GDT_DESC_TSS_FLAGS);
	pm_ctx.aon_tss_selector[1] = add_gdt_entry(desc_lo, desc_up);

	desc_lo = GEN_GDT_DESC_LO((uint32_t)aon_share->aon_ldt,
				  aon_share->aon_ldt_size, GDT_DESC_LDT_FLAGS);
	desc_up = GEN_GDT_DESC_UP((uint32_t)aon_share->aon_ldt,
				  aon_share->aon_ldt_size, GDT_DESC_LDT_FLAGS);
	aon_tss->ldt_seg_selector = add_gdt_entry(desc_lo, desc_up);

	__asm__ volatile("lgdt _gdt;\n"
			 "push %%eax;\n"
			 "movw %0, %%ax;\n"
			 "ltr %%ax;\n"
			 "pop %%eax;\n"
			 :
			 : "r"((uint16_t)main_tss_index));

	aon_share->main_fw_ro_addr = (uint32_t)&__text_region_start;
	aon_share->main_fw_ro_size = (uint32_t)&__rodata_region_end -
				     (uint32_t)&__text_region_start;

	aon_share->main_fw_rw_addr = (uint32_t)&_image_ram_start;
	aon_share->main_fw_rw_size = (uint32_t)&_image_ram_end -
				     (uint32_t)&_image_ram_start;

	aon_share->uma_msb = read32(IPC_UMA_RANGE_LOWER_1);

	ish_dma_init();
}

static inline void check_aon_task_status(void)
{
	struct ish_aon_share *aon_share = pm_ctx.aon_share;

	if (aon_share->last_error != AON_SUCCESS) {
		PM_LOG("aontask has errors:\n");
		PM_LOG("    last error:   %d\n", aon_share->last_error);
		PM_LOG("    error counts: %d\n", aon_share->error_count);
	}
}

static void pm_disable_irqs(uint64_t current_ioapic_state)
{
	int i;

	for (i = 0; i < IOAPIC_NUM_RTES; i++) {
		if ((((uint64_t)1) << i & current_ioapic_state) && (i != SEDI_IRQ_PMU2IOAPIC)
			&& (i != SEDI_IRQ_RESET_PREP))
			sedi_core_irq_disable(i);
	}
}

static void pm_enable_irqs(uint64_t current_ioapic_state)
{
	int i;

	for (i = 0; i < IOAPIC_NUM_RTES; i++) {
		if ((((uint64_t)1) << i & current_ioapic_state) && (i != SEDI_IRQ_PMU2IOAPIC)
			&& (i != SEDI_IRQ_RESET_PREP))
			sedi_core_irq_enable(i);
	}
}

static void switch_to_aontask(void)
{
	unsigned int eflags = sedi_core_irq_lock();

	__sync_synchronize();

	/* disable cache and flush cache */
	__asm__ volatile("movl %%cr0, %%eax;\n"
			 "orl $0x60000000, %%eax;\n"
			 "movl %%eax, %%cr0;\n"
			 "wbinvd;"
			 :
			 :
			 : "eax");

	/* switch to aontask through a far call with aontask's TSS selector */
	__asm__ volatile("lcall *%0;" ::"m"(*pm_ctx.aon_tss_selector) :);

	/* clear TS (Task Switched) flag and enable cache */
	__asm__ volatile("clts;\n"
			 "movl %%cr0, %%eax;\n"
			 "andl $0x9FFFFFFF, %%eax;\n"
			 "movl %%eax, %%cr0;"
			 :
			 :
			 : "eax");

	sedi_core_irq_unlock(eflags);
}

static void handle_reset_in_aontask(enum ish_pm_state pm_state)
{
	uint64_t ioapic_state;

	pm_ctx.aon_share->pm_state = pm_state;

	ioapic_state = sedi_core_get_irq_map();
	pm_disable_irqs(ioapic_state);
	sedi_core_irq_enable(SEDI_IRQ_PMU2IOAPIC);
	sedi_core_irq_enable(SEDI_IRQ_RESET_PREP);

	/* enable Trunk Clock Gating (TCG) of ISH */
	write32(CCU_TCG_EN, 1);

	/* enable power gating of RF(Cache) and ROMs */
	write32(PMU_RF_ROM_PWR_CTRL, 1);

	switch_to_aontask();

	__builtin_unreachable();
}

static void enter_d0i0(void)
{
	uint64_t t0, t1;

	t0 = sedi_rtc_get_us();
	pm_ctx.aon_share->pm_state = ISH_PM_STATE_D0I0;

	/* halt ISH cpu, will wakeup from any interrupt */
	ish_mia_halt();

	t1 = sedi_rtc_get_us();
	pm_ctx.aon_share->pm_state = ISH_PM_STATE_D0;
	log_pm_stat(&pm_stats.d0i0, t0, t1);
}

static void enter_d0i1(void)
{
#ifndef CONFIG_SOC_INTEL_ISH_5_6_0
	uint64_t ioapic_state;
#endif
	uint64_t t0, t1;
	uint32_t both_edge_gpio_pins;

#ifndef CONFIG_SOC_INTEL_ISH_5_6_0
	ioapic_state = sedi_core_get_irq_map();
	pm_disable_irqs(ioapic_state);
#endif
	sedi_core_irq_enable(SEDI_IRQ_PMU2IOAPIC);
	sedi_core_irq_enable(SEDI_IRQ_RESET_PREP);

	t0 = sedi_rtc_get_us();
	pm_ctx.aon_share->pm_state = ISH_PM_STATE_D0I1;

	both_edge_gpio_pins = convert_both_edge_gpio_to_single_edge();

#ifndef CONFIG_SOC_INTEL_ISH_5_6_0
	/* enable Trunk Clock Gating (TCG) of ISH */
	write32(CCU_TCG_EN, 1);
#else
	write32(CCU_BCG_MIA, read32(CCU_BCG_MIA) | CCU_BCG_BIT_MIA);
#endif

	/* halt ISH cpu, will wakeup from PMU wakeup interrupt */
	ish_mia_halt();

#ifndef CONFIG_SOC_INTEL_ISH_5_6_0
	/* disable Trunk Clock Gating (TCG) of ISH */
	write32(CCU_TCG_EN, 0);
#else
	write32(CCU_BCG_MIA, read32(CCU_BCG_MIA) & (~CCU_BCG_BIT_MIA));
#endif

	restore_both_edge_gpio_config(both_edge_gpio_pins);

	pm_ctx.aon_share->pm_state = ISH_PM_STATE_D0;
	t1 = sedi_rtc_get_us();
	log_pm_stat(&pm_stats.d0i1, t0, t1);

#ifndef CONFIG_SOC_INTEL_ISH_5_6_0
	/* restore interrupts */
	pm_enable_irqs(ioapic_state);
#endif
	sedi_core_irq_disable(SEDI_IRQ_PMU2IOAPIC);
}

static void enter_d0i2(void)
{
	uint64_t ioapic_state;
	uint64_t t0, t1;
	uint32_t both_edge_gpio_pins;

	ioapic_state = sedi_core_get_irq_map();
	pm_disable_irqs(ioapic_state);
	sedi_core_irq_enable(SEDI_IRQ_PMU2IOAPIC);
	sedi_core_irq_enable(SEDI_IRQ_RESET_PREP);

	t0 = sedi_rtc_get_us();
	pm_ctx.aon_share->pm_state = ISH_PM_STATE_D0I2;

	both_edge_gpio_pins = convert_both_edge_gpio_to_single_edge();

	/* enable Trunk Clock Gating (TCG) of ISH */
	write32(CCU_TCG_EN, 1);

	/* enable power gating of RF(Cache) and ROMs */
	write32(PMU_RF_ROM_PWR_CTRL, 1);

	switch_to_aontask();

	/* returned from aontask */

	if (pm_ctx.aon_share->pg_exit)
		pg_exit_restore_hw();

	/* disable power gating of RF(Cache) and ROMs */
	write32(PMU_RF_ROM_PWR_CTRL, 0);

	/* disable Trunk Clock Gating (TCG) of ISH */
	write32(CCU_TCG_EN, 0);

	t1 = sedi_rtc_get_us();
	pm_ctx.aon_share->pm_state = ISH_PM_STATE_D0;
	log_pm_stat(&pm_stats.d0i2, t0, t1);

	restore_both_edge_gpio_config(both_edge_gpio_pins);

	if (pm_ctx.aon_share->pg_exit)
		log_pm_stat(&pm_stats.pg, t0, t1);

	/* restore interrupts */
	pm_enable_irqs(ioapic_state);
	sedi_core_irq_disable(SEDI_IRQ_PMU2IOAPIC);
}

static void enter_d0i3(void)
{
	uint64_t ioapic_state;
	uint64_t t0, t1;
	uint32_t both_edge_gpio_pins;

	ioapic_state = sedi_core_get_irq_map();
	pm_disable_irqs(ioapic_state);
	sedi_core_irq_enable(SEDI_IRQ_PMU2IOAPIC);
	sedi_core_irq_enable(SEDI_IRQ_RESET_PREP);

	t0 = sedi_rtc_get_us();
	pm_ctx.aon_share->pm_state = ISH_PM_STATE_D0I3;

	both_edge_gpio_pins = convert_both_edge_gpio_to_single_edge();

	/* enable Trunk Clock Gating (TCG) of ISH */
	write32(CCU_TCG_EN, 1);

	/* enable power gating of RF(Cache) and ROMs */
	write32(PMU_RF_ROM_PWR_CTRL, 1);

	switch_to_aontask();

	/* returned from aontask */

	if (pm_ctx.aon_share->pg_exit)
		pg_exit_restore_hw();

	/* disable power gating of RF(Cache) and ROMs */
	write32(PMU_RF_ROM_PWR_CTRL, 0);

	/* disable Trunk Clock Gating (TCG) of ISH */
	write32(CCU_TCG_EN, 0);

	restore_both_edge_gpio_config(both_edge_gpio_pins);

	t1 = sedi_rtc_get_us();
	pm_ctx.aon_share->pm_state = ISH_PM_STATE_D0;
	log_pm_stat(&pm_stats.d0i3, t0, t1);

	if (pm_ctx.aon_share->pg_exit)
		log_pm_stat(&pm_stats.pg, t0, t1);

	/* restore interrupts */
	pm_enable_irqs(ioapic_state);
	sedi_core_irq_disable(SEDI_IRQ_PMU2IOAPIC);
}

static void pre_setting_d0ix(void)
{
	write32(PMU_VNN_REQ, read32(PMU_VNN_REQ));
	uart_to_idle();
}

static void post_setting_d0ix(void)
{
	uart_port_restore();
}

void sedi_pm_enter_power_state(int state)
{
	switch (state) {
	case ISH_PM_STATE_D0I1:
#ifndef CONFIG_SOC_INTEL_ISH_5_6_0
		pre_setting_d0ix();
#endif
		enter_d0i1();
#ifndef CONFIG_SOC_INTEL_ISH_5_6_0
		post_setting_d0ix();
#endif
		break;
	case ISH_PM_STATE_D0I2:
		pre_setting_d0ix();
		enter_d0i2();
		post_setting_d0ix();
		check_aon_task_status();
		break;
	case ISH_PM_STATE_D0I3:
		pre_setting_d0ix();
		enter_d0i3();
		post_setting_d0ix();
		check_aon_task_status();
		break;
	default:
		enter_d0i0();
		break;
	}
}

static void reset_bcg(void)
{
	write32(CCU_BCG_MIA, 0);
	write32(CCU_BCG_DMA, 0);
	write32(CCU_BCG_I2C, 0);
	write32(CCU_BCG_SPI, 0);
	write32(CCU_BCG_UART, 0);
	write32(CCU_BCG_GPIO, 0);
}

static void handle_d3(uint32_t irq_vec)
{
	write32(PMU_D3_STATUS, read32(PMU_D3_STATUS));

	if (read32(PMU_D3_STATUS) & (PMU_D3_BIT_RISING_EDGE_STATUS | PMU_D3_BIT_SET)) {
		/*
		 * Indicate completion of servicing the interrupt to IOAPIC
		 * first then indicate completion of servicing the interrupt
		 * to LAPIC
		 */
		write32(SEDI_IOAPIC_EOI, irq_vec);
		write32(LAPIC_EOI, 0x0);

		if (!(pm_ctx.aon_share->host_in_suspend))
			ish_pm_reset(ISH_PM_STATE_D3);
	}
}

static void pcie_dev_isr(void)
{
	handle_d3(SEDI_VEC_PCIEDEV);
}
/**
 * main FW only need handle PMU wakeup interrupt for D0i1 state, aontask will
 * handle PMU wakeup interrupt for other low power states
 */
static void pmu_wakeup_isr(void)
{
	/* at current nothing need to do */
}

static void reset_prep_isr(void)
{
	/* mask reset prep avail interrupt */
	write32(PMU_RST_PREP, PMU_RST_PREP_INT_MASK);

	/*
	 * Indicate completion of servicing the interrupt to IOAPIC first
	 * then indicate completion of servicing the interrupt to LAPIC
	 */
	write32(SEDI_IOAPIC_EOI, SEDI_VEC_RESET_PREP);
	write32(LAPIC_EOI, 0x0);

	ish_mia_reset();
	__builtin_unreachable();
}

void sedi_pm_init(void)
{
	/* clear reset bit */
	write32(ISH_RST_REG, 0);

	/* clear reset history register in CCU */
	write32(CCU_RST_HST, read32(CCU_RST_HST));

	/* disable TCG and disable BCG */
	write32(CCU_TCG_EN, 0);
	reset_bcg();

	init_aon_task();

	write32(PMU_GPIO_WAKE_MASK0, 0);
	write32(PMU_GPIO_WAKE_MASK1, 0);

	/* unmask all wake up events */
	write32(PMU_MASK_EVENT, ~PMU_MASK_EVENT_BIT_ALL);

	write32(PMU_ISH_FABRIC_CNT, (read32(PMU_ISH_FABRIC_CNT) & 0xffff0000) | FABRIC_IDLE_COUNT);
	write32(PMU_PGCB_CLKGATE_CTRL, TRUNK_CLKGATE_COUNT);

	IRQ_CONNECT(SEDI_IRQ_RESET_PREP, 5, reset_prep_isr, 0, IOAPIC_LEVEL);
	IRQ_CONNECT(SEDI_IRQ_PMU2IOAPIC, 5, pmu_wakeup_isr, 0, IOAPIC_LEVEL);
	IRQ_CONNECT(SEDI_IRQ_PCIEDEV, 5, pcie_dev_isr, 0, IOAPIC_LEVEL);

	/* unmask reset prep avail interrupt */
	write32(PMU_RST_PREP, 0);
	sedi_core_irq_enable(SEDI_IRQ_RESET_PREP);

	/* unmask D3 and BME interrupts */
	write32(PMU_D3_STATUS, read32(PMU_D3_STATUS) & (PMU_D3_BIT_SET | PMU_BME_BIT_SET));

	if ((!(read32(PMU_D3_STATUS) & PMU_D3_BIT_SET)) &&
	    (read32(PMU_D3_STATUS) & PMU_BME_BIT_SET))
		write32(PMU_D3_STATUS, read32(PMU_D3_STATUS));

	sedi_core_irq_enable(SEDI_IRQ_PCIEDEV);
}

void ish_pm_reset(enum ish_pm_state pm_state)
{
	if (pm_ctx.aon_valid) {
		handle_reset_in_aontask(pm_state);
	} else {
		ish_mia_reset();
	}

	__builtin_unreachable();
}

void sedi_pm_reset(void)
{
	ish_mia_reset();
}

void sedi_pm_host_suspend(uint32_t suspend)
{
	pm_ctx.aon_share->host_in_suspend = suspend;
}

/*
 * helper for print idle_stats
 */
static void print_stats(const char *name, const struct pm_stat *stat)
{
	if (stat->count)
		PM_LOG("    %s:\n"
		       "        counts: %llu\n"
		       "        time:   %.6llu ms\n",
		       name, stat->count, (stat->total_time_us)/1000);
}

/**
 * Print low power idle statistics
 */
void command_idle_stats(void)
{
#ifdef PM_DEBUG_PRINTS
	struct ish_aon_share *aon_share = pm_ctx.aon_share;
#endif
	uint64_t tall;

	tall = sedi_rtc_get_us();

	PM_LOG("Aontask exists: %s\n", pm_ctx.aon_valid ? "Yes" : "No");
	PM_LOG("Total time on: %.6llu ms\n", tall/1000);
	PM_LOG("Idle sleep:\n");
	print_stats("D0i0", &pm_stats.d0i0);

	PM_LOG("Deep sleep:\n");
	print_stats("D0i1", &pm_stats.d0i1);
	print_stats("D0i2", &pm_stats.d0i2);
	print_stats("D0i3", &pm_stats.d0i3);
	print_stats("IPAPG", &pm_stats.pg);

	if (pm_ctx.aon_valid) {
		PM_LOG("    Aontask status:\n");
		PM_LOG("        last error:   %u\n", aon_share->last_error);
		PM_LOG("        error counts: %u\n", aon_share->error_count);
	}
}
