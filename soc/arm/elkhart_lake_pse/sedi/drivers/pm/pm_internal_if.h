/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _PM_INTERNAL_IF_H_
#define _PM_INTERNAL_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "pm_regs.h"
#include "sedi_driver_common.h"

#define NUM_OF_SX_CLIENT_CONFIGS (10)
#define NUM_OF_S0IX_CLIENT_CONFIGS (10)

/*!
 * \defgroup driver_pm_internal PM_INTERNAL
 * \ingroup driver_internal
 */

/*!
 * \enum driver_id_t
 * \brief Driver ID for different driver
 * \ingroup driver_pm_internal
 */
typedef enum {
	FIRST_DRIVER,
	/* Peripheral devices */
	DRIVER_ID_UART0 = FIRST_DRIVER,
	DRIVER_ID_UART1,
	DRIVER_ID_UART2,
	DRIVER_ID_UART3,
	DRIVER_ID_UART4,
	DRIVER_ID_UART5,
	DRIVER_ID_DMA0,
	DRIVER_ID_DMA1,
	DRIVER_ID_DMA2,
	DRIVER_ID_I2C0,
	DRIVER_ID_I2C1,
	DRIVER_ID_I2C2,
	DRIVER_ID_I2C3,
	DRIVER_ID_I2C4,
	DRIVER_ID_I2C5,
	DRIVER_ID_I2C6,
	DRIVER_ID_I2C7,
	DRIVER_ID_SPI0,
	DRIVER_ID_SPI1,
	DRIVER_ID_SPI2,
	DRIVER_ID_SPI3,
	DRIVER_ID_GPIO0,
	DRIVER_ID_GPIO1,
	DRIVER_ID_TGPIO0,
	DRIVER_ID_TGPIO1,
	DRIVER_ID_I2S0,
	DRIVER_ID_I2S1,
	DRIVER_ID_TSN0,
	DRIVER_ID_TSN1,
	DRIVER_ID_SRAM,
	DRIVER_ID_QEP0,
	DRIVER_ID_QEP1,
	DRIVER_ID_QEP2,
	DRIVER_ID_QEP3,
	DRIVER_ID_PWM0,
	DRIVER_ID_PWM1,
	DRIVER_ID_ADC,
	DRIVER_ID_CAN0,
	DRIVER_ID_CAN1,
	/* Add more peripheral devices before LAST_DRIVER_CG */
	LAST_DRIVER_CG,
	/* IPC */
	DRIVER_ID_IPC_OSE2PMC = LAST_DRIVER_CG,
	DRIVER_ID_IPC_OSE2HOST,
	DRIVER_ID_IPC_OSE2HOST_CLR,
	/* HPET */
	DRIVER_ID_TIMER_HIGH_RES,
	LAST_DRIVER_ARMCG,
	/* TSYNC */
	DRIVER_ID_TSYNC = LAST_DRIVER_ARMCG,
	LAST_DRIVER
} driver_id_t;

/*!
 * \def PM_VNN_DRIVER_REQ
 * \brief Macro for assert VNNREQ.
 * \ingroup driver_pm_internal
 */
#define PM_VNN_DRIVER_REQ(vnn_id)                                              \
	do {                                                                   \
		if ((read32(PMU_VNN_REQ_31_0) & BIT(vnn_id)) == 0) {           \
			write32(PMU_VNN_REQ_31_0, BIT(vnn_id));                \
			while (                                                \
			    !(read32(PMU_VNN_REQ_ACK) & PMU_VNN_REQ_ACK_STS))  \
				;                                              \
		}                                                              \
	} while (0)

/*!
 * \def PM_VNN_DRIVER_DEREQ
 * \brief Macro for de-assert VNNREQ.
 * \ingroup driver_pm_internal
 */
#define PM_VNN_DRIVER_DEREQ(vnn_id)                                            \
	do {                                                                   \
		if ((read32(PMU_VNN_REQ_31_0) & BIT(vnn_id)) != 0) {           \
			write32(PMU_VNN_REQ_31_0, BIT(vnn_id));                \
			write32(PMU_VNN_REQ_ACK, read32(PMU_VNN_REQ_ACK));     \
		}                                                              \
	} while (0)

/*!
 * \def PM_SET_CLOCK_DIV_WDT
 * \brief Macro for set WDT clock divider.
 * \ingroup driver_pm_internal
 */
#define PM_SET_CLOCK_DIV_WDT(div_val) write32(CCU_CKDIV_WD, (div_val))

/*!
 * \fn void pm_driver_start_trans(IN driver_id_t id)
 * \brief Every driver must call this function when starting a HW transaction.
 * This function cannot be called from an ISR or from the context of swapper.
 * This could cause a suspension of the calling task. GPIO should not be called,
 * since clock gating it will stop delivery of interrupts from controller
 * (not relevant in trunk clock gating). If a power transition is occurring this
 * function will block.
 * \param[in] id: driver id
 * \return void
 */
void pm_driver_start_trans(IN driver_id_t id);

/*!
 * \fn void pm_driver_end_trans(IN driver_id_t id)
 * \brief Every driver must call this function when it finishes a HW
 * transaction. GPIO should not be called, since clock gating it will stop
 * delivery of interrupts from controller (not relevant in trunk clock gating).
 * Without calling this function - deeper idle states will not be achieved.
 * \param[in] id: driver id
 * \return void
 */
void pm_driver_end_trans(IN driver_id_t id);

/*!
 * \fn void pm_set_wdt_cg(IN uint32_t enable)
 * \brief Enable/disable watchdog clock gate
 * \param[in] enable: 0 to disable, non-zero to enable
 * \return void
 */
void pm_set_wdt_cg(IN uint32_t enable);

/*!
 * \fn void pm_set_s0ix_event(IN uint32_t s0ix_entry)
 * \brief Set S0ix entry/exit event notification
 * \param[in] s0ix_entry: 1 for s0ix entry, 0 for s0ix exit
 * \return void
 */
void pm_set_s0ix_event(IN uint32_t s0ix_entry);

#ifdef __cplusplus
}
#endif

#endif /* _PM_INTERNAL_IF_H_*/
