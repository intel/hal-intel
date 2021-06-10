/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_CORE_H_
#define _SEDI_DRIVER_CORE_H_
#include <stdint.h>
#include "sedi_driver_common.h"
#include "sedi_soc.h"
#include <core_cm7.h>

#define SRAM_CTRL_BASE 0x50400000
#define ICCM_BASE_ADDR 0x0
#define DCCM_BASE_ADDR 0x20000000
#define SRAM_CTRL_CCM_ERASE_CTRL (SRAM_CTRL_BASE + 0x0C)
#define SRAM_CTRL_CCM_ERASE_ADDR (SRAM_CTRL_BASE + 0x10)
#define SRAM_CTRL_DCCM_ERASE_CTRL (SRAM_CTRL_BASE + 0x220)
#define SRAM_CTRL_DCCM_ERASE_ADDR (SRAM_CTRL_BASE + 0x224)
#define SRAM_CTRL_CCM_ERASE_SIZE_BIT 2
#define SRAM_CTRL_ERASE_START_BIT BIT(0)

/*define cache line size*/
#define CACHE_LINE_SIZE (32)

/**
 * brief   Enable I-Cache
 * details Turns on I-Cache
 */
static inline void sedi_core_enable_icache(void)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		SCB_EnableICache();
	}
}

/**
 * brief   Disable I-Cache
 * details Turns off I-Cache
 */
static inline void sedi_core_disable_icache(void)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		SCB_DisableICache();
	}
}

/**
 * brief   Invalidate I-Cache
 * details Invalidates I-Cache
 */
static inline void sedi_core_invalid_icache(void)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		SCB_InvalidateICache();
	}
}

/**
 * brief   Enable D-Cache
 * details Turns on D-Cache
 */
static inline void sedi_core_enable_dcache(void)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		SCB_EnableDCache();
	}
}

/**
 * brief   Disable D-Cache
 * details Turns off D-Cache
 */
static inline void sedi_core_disable_dcache(void)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		SCB_DisableDCache();
	}
}

/**
 * brief   Invalidate D-Cache
 * details Invalidates D-Cache
 */
static inline void sedi_core_invalid_dcache(void)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		SCB_InvalidateDCache();
	}
}

/**
 * brief   Clean D-Cache
 * details Cleans D-Cache
 */
static inline void sedi_core_clean_dcache(void)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		SCB_CleanDCache();
	}
}

/**
 * brief   Clean & Invalidate D-Cache
 * details Cleans and Invalidates D-Cache
 */
static inline void sedi_core_inv_clean_dcache(void)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		SCB_CleanInvalidateDCache();
	}
}

/**
 * brief   D-Cache Invalidate by address
 * details Invalidates D-Cache for the given address
 * param[in]   addr    address (aligned to 32-byte boundary)
 * param[in]   dsize   size of memory block (in number of bytes)
 */
static inline int sedi_core_inv_dcache_by_addr(uint32_t *addr, int32_t dsize)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		DBG_CHECK((!addr || dsize <= 0), SEDI_DRIVER_ERROR);
		SCB_InvalidateDCache_by_Addr(addr, dsize);
	}

	return SEDI_DRIVER_OK;
}

/**
 * brief   D-Cache Clean by address
 * details Cleans D-Cache for the given address
 * param[in]   addr    address (aligned to 32-byte boundary)
 * param[in]   dsize   size of memory block (in number of bytes)
 */
static inline int sedi_core_clean_dcache_by_addr(uint32_t *addr, int32_t dsize)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		DBG_CHECK((!addr || dsize <= 0), SEDI_DRIVER_ERROR);
		SCB_CleanDCache_by_Addr(addr, dsize);
	}

	return SEDI_DRIVER_OK;
}

/**
 * brief   D-Cache Clean and Invalidate by address
 * details Cleans and invalidates D_Cache for the given address
 * param[in]   addr    address (aligned to 32-byte boundary)
 * param[in]   dsize   size of memory block (in number of bytes)
 */
static inline int sedi_core_inv_clean_dcache_by_addr(uint32_t *addr,
						     int32_t dsize)
{
	if (sedi_get_config(SEDI_CONFIG_CACHE_DISABLE, NULL) !=
	    SEDI_CONFIG_SET) {
		DBG_CHECK((!addr || dsize <= 0), SEDI_DRIVER_ERROR);
		SCB_CleanInvalidateDCache_by_Addr(addr, dsize);
	}

	return SEDI_DRIVER_OK;
}

/**
 * brief   Scrub ICCM partition by address
 * details Scrub ICCM partition for the given address
 * param[in]   addr    start address (aligned to 64KB)
 * param[in]   dsize   size of ICCM partition (in number of bytes)
 */
static inline void sedi_core_scrub_iccm(uint32_t addr, uint32_t dsize)
{
	/* Erase ICCM */
	write32(SRAM_CTRL_CCM_ERASE_ADDR, addr - ICCM_BASE_ADDR);
	write32(SRAM_CTRL_CCM_ERASE_CTRL,
		((dsize >> 3) << SRAM_CTRL_CCM_ERASE_SIZE_BIT) |
		SRAM_CTRL_ERASE_START_BIT);
	__asm__ __volatile__ ("" : : : "memory");

	/* Waiting for erasing done */
	while (read32(SRAM_CTRL_CCM_ERASE_CTRL) & SRAM_CTRL_ERASE_START_BIT)
		;
}

/**
 * brief   Scrub DCCM partition by address
 * details Scrub DCCM partition for the given address
 * param[in]   addr    start address (aligned to 64KB)
 * param[in]   dsize   size of DCCM partition (in number of bytes)
 */
static inline void sedi_core_scrub_dccm(uint32_t addr, uint32_t dsize)
{
	/* Erase DCCM */
	write32(SRAM_CTRL_DCCM_ERASE_ADDR, addr - DCCM_BASE_ADDR);
	write32(SRAM_CTRL_DCCM_ERASE_CTRL,
		((dsize >> 3) << SRAM_CTRL_CCM_ERASE_SIZE_BIT) |
		SRAM_CTRL_ERASE_START_BIT);
	__asm__ __volatile__ ("" : : : "memory");

	/* Waiting for erasing done */
	while (read32(SRAM_CTRL_DCCM_ERASE_CTRL) & SRAM_CTRL_ERASE_START_BIT)
		;
}

#endif
