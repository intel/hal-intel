/*
 * Copyright (c) 2023-2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_CORE_H_
#define _SEDI_DRIVER_CORE_H_
#include <stdint.h>
#include <sedi_driver_common.h>

#include "sedi_soc_regs.h"

#define SEDI_DCACHE_LINE_SIZE ((uint32_t)16)

/*!
 * \brief   Clean & Invalidate D-Cache
 * \details Cleans and Invalidates D-Cache
 */
static inline void sedi_core_inv_clean_dcache(void)
{
	__asm__ volatile("wbinvd;\n\t");

	__asm__ volatile("lock; addl $0,-4(%%esp);\n\t" ::: "memory", "cc");
}

/*!
 * \brief   D-Cache Clean and Invalidate by address
 * \details Cleans and invalidates D_Cache for the given address
 * \param[in]   addr    address (aligned to 32-byte boundary)
 * \param[in]   dsize   size of memory block (in number of bytes)
 */
static inline int sedi_core_inv_clean_dcache_by_addr(uint32_t *addr, int32_t dsize)
{
	DBG_CHECK((addr && dsize > 0), SEDI_DRIVER_ERROR_PARAMETER);
	uint32_t start = (uint32_t)addr;
	uint32_t end = start + dsize;

	end = (end + (SEDI_DCACHE_LINE_SIZE - 1)) & ~(SEDI_DCACHE_LINE_SIZE - 1);

	for (; start < end; start += SEDI_DCACHE_LINE_SIZE) {
		__asm__ volatile("clflush %0;\n\t" : "+m"(*(volatile char *)start));
	}

	__asm__ volatile("lock; addl $0,-4(%%esp);\n\t" ::: "memory", "cc");

	return SEDI_DRIVER_OK;
}

/*!
 * \brief   D-Cache Clean by address
 * \details Cleans D-Cache for the given address
 * \param[in]   addr    address (aligned to 32-byte boundary)
 * \param[in]   dsize   size of memory block (in number of bytes)
 */
static inline int sedi_core_clean_dcache_by_addr(uint32_t *addr, int32_t dsize)
{
	return sedi_core_inv_clean_dcache_by_addr(addr, dsize);
}

static inline void sedi_core_cpu_idle(void)
{
	__asm__ volatile(
			"sti;\n\t"
			"hlt;\n\t"
			"nop;\n\t"
			"nop;\n\t"
			"cli;\n\t");
}

static inline uint32_t sedi_core_get_eflags(void)
{
	uint32_t ret;

	__asm__ volatile(
		"pushfl;\n\t"
		"popl  %0;\n\t"
		: "=r"(ret));

	return ret;
}

static inline void write_ioapic_reg(const uint32_t reg, const uint32_t val)
{
	write32(SEDI_IOAPIC_IDX, (unsigned char)reg);
	write32(SEDI_IOAPIC_WDW, val);
}

static inline unsigned int read_ioapic_reg(const uint32_t reg)
{
	write32(SEDI_IOAPIC_IDX, (unsigned char)reg);
	return read32(SEDI_IOAPIC_WDW);
}

static inline void send_ioapic_eoi(const uint32_t vector)
{
	write32(SEDI_IOAPIC_EOI, vector);
}

static inline void update_ioapic_redtbl_raw_lo(const unsigned int irq, const unsigned int val)
{
	/* [IOAPIC], 3.2.4. "IOREDTBL[23:0] I/O REDIRECTION TABLE REGISTERS" */
	const uint32_t redtbl_lo = SEDI_IOAPIC_IOREDTBL + 2 * irq;

	write_ioapic_reg(redtbl_lo, val);
}

static inline int lapic_pending_interrupt_reqs(void)
{
	for (int i = 0; i < SEDI_LAPIC_IRR_COUNT; i++) {
		if (read32(SEDI_LAPIC_IRR + SEDI_LAPIC_IRR_INST_OFF * i)) {
			return 1;
		}
	}
	return 0;
}

static inline void lapic_enable(void)
{
	write32(SEDI_LAPIC_SPUR, SEDI_LAPIC_ENABLE | SEDI_LAPIC_SPUR_RESET);
}

static inline void sedi_core_irq_enable(unsigned int irq)
{
	const uint32_t redtbl_lo = SEDI_IOAPIC_IOREDTBL + 2 * irq;
	unsigned int val = read_ioapic_reg(redtbl_lo);

	val &= ~SEDI_IOAPIC_REDTBL_MASK;
	update_ioapic_redtbl_raw_lo(irq, val);
}

static inline void sedi_core_irq_disable(unsigned int irq)
{
	const uint32_t redtbl_lo = SEDI_IOAPIC_IOREDTBL + 2 * irq;
	unsigned int val = read_ioapic_reg(redtbl_lo);

	val |= SEDI_IOAPIC_REDTBL_MASK;
	update_ioapic_redtbl_raw_lo(irq, val);
}

static inline unsigned int sedi_core_irq_lock(void)
{
	unsigned int key;

	__asm__ volatile("pushfl; cli; popl %0" : "=g"(key)::"memory");

	return key;
}

static inline void sedi_core_irq_unlock(unsigned int key)
{
	if ((key & 0x00000200U) != 0U) { /* 'IF' bit */
		__asm__ volatile("sti" ::: "memory");
	}
}

static inline uint64_t sedi_core_get_irq_map(void)
{
	uint64_t irq_map = 0;

	for (int pin = 0; pin < 30; pin++) {
		write32(SEDI_IOAPIC_IDX, SEDI_IOAPIC_IOREDTBL + pin * 2);
		if (!(read32(SEDI_IOAPIC_WDW) & SEDI_IOAPIC_REDTBL_MASK)) {
			irq_map |= ((uint64_t)0x1) << pin;
		}
	}

	return irq_map;
}

/*!
 * \brief sedi_virt_to_phys
 * \param[in] virt: virtual address
 * \return physical address of the virtual address
 */
uintptr_t sedi_core_virt_to_phys(uintptr_t virt);

/*!
 * \brief sedi_phys_to_virt
 * \param[in] phys: physical address
 * \return virtual address of the physical address
 */
uintptr_t sedi_core_phys_to_virt(uintptr_t phys);
#endif
