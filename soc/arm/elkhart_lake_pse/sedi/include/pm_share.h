/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PM_SHARE_H_
#define _PM_SHARE_H_

#define NR_IRQ 107
#define WAIT_NOP_COUNTS 50
#define SRAM_SLEEP_WAIT 5

#define SET_REG_BIT(address, smask)                                            \
	*((uint32_t *)(address)) =                                             \
	(uint32_t)(*((uint32_t *)(address)) | (smask));

#define CLEAR_REG_BIT(address, cmask)                                          \
	*((uint32_t *)(address)) =                                             \
	(uint32_t)(*((uint32_t *)(address)) & ~(cmask));

#define MODIFY_REG_BIT(address, cmask, smask)                                  \
	*((uint32_t *)(address)) =                                             \
	(uint32_t)(*((uint32_t *)(address)) & ~(cmask) | (smask));


/* Structure used by AON task during IPAPG entry/exit */
typedef struct {
	/* The DDR IMR address for D0i3 DMA copy */
	uint32_t uma_msb;
	/* PSP of idle task */
	uint32_t psp_idle;
	/* Stack pointer of AON task */
	uint32_t sp_aon;
	/* Last basepri value */
	uint32_t basepri;
	/* Vector table address on SRAM */
	uint32_t sram_vtor;
	/* MSP in sram */
	uint32_t msp;
	/* Device ownership */
	uint64_t device_ownership;

	union {
		uint32_t bcg;
		struct {
			/* To record BCG status */
			uint32_t bcg_hpet : 1;
			uint32_t bcg_uart : 3;
			uint32_t bcg_i2c : 3;
			uint32_t bcg_spi : 2;
			uint32_t bcg_gpio : 1;
			uint32_t bcg_sram : 2;
			uint32_t bcg_qep : 4;
			uint32_t bcg_dma : 1;
			uint32_t bcg_pwm : 1;
			uint32_t bcg_adc : 1;
			uint32_t bcg_canbus : 2;
			uint32_t bcg_gbe : 1;
			uint32_t bcg_tgpio : 1;
			/* reserved */
			uint32_t bcg_reserved : 9;
		};
	};

	/* Flag to record IPAGP exit */
	uint32_t pg_exit : 1;
	/* Flag to record SX entry */
	uint32_t sx_entry : 1;
	/* Flag to record shutdown entry */
	uint32_t shutdown : 1;
	/* Flag to record D0i2 entry */
	uint32_t perform_d0i2 : 1;
	/* Flag to record if WOL is enabled */
	uint32_t wol_en : 1;
	/* reserved */
	uint32_t reserved : 27;
} aon_pointer_t;

#endif /* _PM_SHARE_H_ */
