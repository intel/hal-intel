/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _ISH_AON_SHARE_H_
#define _ISH_AON_SHARE_H_

#include "ish_ia_structs.h"

/* magic ID for valid aontask image check */
#define AON_MAGIC_ID			        0x544E4F41  /*"AONT"*/

/* aontask error code  */
#define AON_SUCCESS				0
#define AON_ERROR_NOT_SUPPORT_POWER_MODE	1
#define AON_ERROR_DMA_FAILED			2

/* power states for ISH */
enum ish_pm_state {
	/* D0 state: active mode */
	ISH_PM_STATE_D0 = 0,
	/* sleep state: cpu halt */
	ISH_PM_STATE_D0I0,
	/* deep sleep state 1: Trunk Clock Gating(TCG), cpu halt*/
	ISH_PM_STATE_D0I1,
	/* deep sleep state 2: TCG, SRAM retention, cpu halt */
	ISH_PM_STATE_D0I2,
	/* deep sleep state 3: TCG, SRAM power off, cpu halt*/
	ISH_PM_STATE_D0I3,
	/**
	 * D3 state: power off state, on ISH5.0, can't do real power off,
	 * similar to D0I3, but will reset ISH
	 */
	ISH_PM_STATE_D3,
	/**
	 * reset ISH, main FW received 'reboot' command
	 */
	ISH_PM_STATE_RESET,
	/**
	 * reset ISH, main FW received reset_prep interrupt during
	 * S0->Sx transition.
	 */
	ISH_PM_STATE_RESET_PREP,
	ISH_PM_STATE_NUM
};

/* shared data structure between main FW and aontask */
struct ish_aon_share {
	/* magic ID */
	uint32_t magic_id;
	/* error counter */
	uint32_t error_count;
	/* last error */
	int last_error;
	/* successfully exit from IPAPG or not */
	uint32_t pg_exit;
	/* high 32bits of 64 bits dram address for dma */
	uint32_t uma_msb;
	/* aontask's TSS segment entry */
	struct tss_entry *aon_tss;
	/* aontask's LDT start address */
	ldt_entry *aon_ldt;
	/* aontask's LDT's limit size */
	uint32_t aon_ldt_size;
	/* current power state, see chip/ish/power_mgt.h */
	enum ish_pm_state pm_state;
	/* for store/restore main FW's IDT */
	struct idt_header main_fw_idt_hdr;

	/**
	 * main FW's read only code and data region in main SRAM,
	 * address need 64 bytes align due to DMA requirement
	 */
	uint32_t main_fw_ro_addr;
	uint32_t main_fw_ro_size;

	/**
	 * main FW's read and write data region in main SRAM,
	 * address need 64 bytes align due to DMA requirement
	 */
	uint32_t main_fw_rw_addr;
	uint32_t main_fw_rw_size;

	/* host suspend state */
	uint32_t host_in_suspend;
};

extern struct ish_aon_share aon_share;

#endif /* _AON_SHARE_H_ */
