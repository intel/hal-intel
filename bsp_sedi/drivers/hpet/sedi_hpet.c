/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sedi_hpet.h"
#include "sedi_driver_hpet.h"
#include <string.h>

/* driver version */
#define SEDI_HPET_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)
#define ULLONG_MAX 18446744073709551615ULL

#define PICOSECS_PER_USEC 1000000

#define CURRENT_HPET_CYCLE sedi_hpet_get_main_counter()
#define US_TO_HPET_CYCLE(us) ((uint64_t)us * PICOSECS_PER_USEC / hpet_clock_period_pico)
#define HPET_CYCLE_TO_US(cycle) ((uint64_t)cycle * hpet_clock_period_pico / PICOSECS_PER_USEC)

/* general capabilities register macros */

#define HPET_COUNTER_CLK_PERIOD(caps) (caps >> 32)
#define HPET_NUM_TIMERS(caps) (((caps >> 8) & 0x1f) + 1)
#define HPET_IS64BITS(caps) (caps & 0x1000)

/* general configuration register macros */

#define HPET_ENABLE_CNF (1 << 0)
#define HPET_LEGACY_RT_CNF (1 << 1)

/* general interrupt status register */
#define HPET_GIS_TIMER0 (1 << 0)
#define HPET_GIS_TIMER1 (1 << 1)
#define HPET_GIS_TIMER2 (1 << 2)
#define HPET_GIS_CLEAR_MASK (HPET_GIS_TIMER0 | HPET_GIS_TIMER1 | HPET_GIS_TIMER2)

/* timer N configuration and capabilities register macros */

#define HPET_Tn_INT_ROUTE_CAP(caps) (caps >> 32)
#define HPET_Tn_FSB_INT_DEL_CAP(caps) (caps & (1 << 15))
#define HPET_Tn_FSB_EN_CNF (1 << 14)
#define HPET_Tn_INT_ROUTE_CNF_MASK (0x1f << 9)
#define HPET_Tn_INT_ROUTE_CNF_SHIFT 9
#define HPET_Tn_32MODE_CNF (1 << 8)
#define HPET_Tn_VAL_SET_CNF (1 << 6)
#define HPET_Tn_SIZE_CAP(caps) (caps & (1 << 5))
#define HPET_Tn_PER_INT_CAP(caps) (caps & (1 << 4))
#define HPET_Tn_TYPE_CNF (1 << 3)
#define HPET_Tn_INT_ENB_CNF (1 << 2)
#define HPET_Tn_INT_TYPE_CNF (1 << 1)

/* control and status register macros */
#define GENERAL_CONFIG (1 << 0)
#define GENERAL_INT_STATUS (1 << 1)
#define MAIN_COUNTER_VALUE (3 << 2)
#define TIMER0_CONFIG_CAPS (1 << 4)
#define TIMER1_CONFIG_CAPS (1 << 5)
#define TIMER2_CONFIG_CAPS (1 << 6)
#define TIMER0_COMPARATOR (3 << 7)
#define TIMER1_COMPARATOR (1 << 9)
#define TIMER2_COMPARATOR (1 << 10)
#define MAIN_COUNTER_INVALID (1 << 13)

/*Macro for interrupt routing*/
#define TIMER2_INT_ROUTE 0x0b

typedef struct {
	uint32_t start : 1; /* start flag */
	uint32_t one_shot : 1; /* select period/non-period mode */
	uint32_t rsvd : 29; /* reserved */
	uint32_t valid : 1; /* Check if the position has been token */
	uint64_t microsec; /* user's parameter */
	uint64_t timeout; /* translated parameter, for sort */
	uint64_t expires; /* current + timeout, for sort */
	hpet_callback_t callback; /* callback */
	void *param; /* callback param, user defined */
} hpet_timer_ctx_t;

static hpet_timer_ctx_t bsp_timers[SEDI_HPET_SOC_TIMER_NUM];

static hpet_regs_t *hpet_reg = (hpet_regs_t *)SEDI_HPET_BASE;
static uint32_t hpet_clock_period_pico = 30517578;
static uint32_t hpet_min_delay = 5; /* HPET cycles */
/* driver version */
static const sedi_driver_version_t driver_version = { SEDI_HPET_API_VERSION,
						      SEDI_HPET_DRIVER_VERSION };
/* Capabilities for hpet */
static const sedi_hpet_capabilities_t hpet_cap = { 0 };

static inline void wait_for_idle(uint32_t bits)
{
	while (hpet_reg->hpet_ctrl_sts & bits)
		;
}

void sedi_hpet_set_min_delay(uint32_t min_delay)
{
	hpet_min_delay = min_delay;
}

sedi_driver_version_t sedi_hpet_get_version(void)
{
	return driver_version;
}

sedi_hpet_capabilities_t sedi_hpet_get_capabilities(void)
{
	return hpet_cap;
}

int32_t sedi_hpet_uninit(void)
{
	return SEDI_DRIVER_OK;
}

int32_t sedi_hpet_set_power(IN sedi_power_state_t state)
{
	PARAM_UNUSED(state);
	return SEDI_DRIVER_OK;
}

int sedi_hpet_set_comparator(IN sedi_hpet_t timer_id, IN uint64_t value)
{
	uint32_t tncv_addr;
	uint32_t sts_wait;
	uint64_t _value = value;

	if ((timer_id != HPET_0) && (value >> 32)) {
		/* it's wrong to set into a 32-bits timer */
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	switch (timer_id) {
	case HPET_0:
		sts_wait = TIMER0_COMPARATOR;
		tncv_addr = (uint32_t)(&(hpet_reg->t0cv_low));
		break;
	case HPET_1:
		sts_wait = TIMER1_COMPARATOR;
		tncv_addr = (uint32_t)(&(hpet_reg->t1cv_low));
		break;
	case HPET_2:
		sts_wait = TIMER2_COMPARATOR;
		tncv_addr = (uint32_t)(&(hpet_reg->t2cv_low));
		break;
	default:
		return SEDI_DRIVER_ERROR_NO_DEV;
	}

	/* need to wait until INT clearing is finished, or HPET
	 * goes out of work
	 * */
	sts_wait |= GENERAL_INT_STATUS;

	if (hpet_reg->hpet_ctrl_sts & sts_wait) {
		uint64_t now;
		int64_t diff;

		wait_for_idle(sts_wait);
		now = sedi_hpet_get_main_counter();

		if (timer_id == HPET_0) {
			diff = (int64_t)(value - now);
		} else {
			diff = (int32_t)((uint32_t)value - (uint32_t)now);
		}
		if (diff < hpet_min_delay) {
			_value = now + hpet_min_delay;
		}
	}

	if (timer_id == HPET_0) {
		write64(tncv_addr, _value);
	} else {
		write32(tncv_addr, (uint32_t)_value);
	}

	return SEDI_DRIVER_OK;
}

void sedi_hpet_set_main_counter(uint64_t value)
{
	wait_for_idle(MAIN_COUNTER_INVALID);
	write64((uint32_t)(&(hpet_reg->mcv_low)), value);
}

uint64_t sedi_hpet_get_main_counter(void)
{
	uint32_t highBits;
	uint32_t lowBits;

	do {
		highBits = hpet_reg->mcv_high;
		lowBits = hpet_reg->mcv_low;
	} while (highBits != hpet_reg->mcv_high);

	return ((uint64_t)highBits << 32) | lowBits;
}

void sedi_hpet_enable_interrupt(IN sedi_hpet_t timer_id)
{
	switch (timer_id) {
	case HPET_0:
		wait_for_idle(TIMER0_CONFIG_CAPS);
		hpet_reg->t0c_low |= HPET_Tn_INT_ENB_CNF;
		break;
	case HPET_1:
		wait_for_idle(TIMER1_CONFIG_CAPS);
		hpet_reg->t1c_low |= HPET_Tn_INT_ENB_CNF;
		break;
	case HPET_2:
		wait_for_idle(TIMER2_CONFIG_CAPS);
		hpet_reg->t2c_low |= HPET_Tn_INT_ENB_CNF;
		break;
	default:
		break;
	}
}

void sedi_hpet_disable_interrupt(IN sedi_hpet_t timer_id)
{
	switch (timer_id) {
	case HPET_0:
		wait_for_idle(TIMER0_CONFIG_CAPS);
		hpet_reg->t0c_low &= ~HPET_Tn_INT_ENB_CNF;
		break;
	case HPET_1:
		wait_for_idle(TIMER1_CONFIG_CAPS);
		hpet_reg->t1c_low &= ~HPET_Tn_INT_ENB_CNF;
		break;
	case HPET_2:
		wait_for_idle(TIMER2_CONFIG_CAPS);
		hpet_reg->t2c_low &= ~HPET_Tn_INT_ENB_CNF;
		break;
	default:
		break;
	}
}

uint32_t sedi_hpet_get_int_status(IN sedi_hpet_t timer_id)
{
	wait_for_idle(GENERAL_INT_STATUS);
	return (hpet_reg->gis_low & BIT(timer_id)) ? 1 : 0;
}

#include <string.h>
static char buffer[3];
int32_t sedi_hpet_init(void)
{
	static int sedi_hpet_inited;

	if (sedi_hpet_inited)
		return 0;

	memcpy(&buffer[0], &hpet_reg, sizeof(hpet_reg));
	sedi_hpet_inited = 1;

	wait_for_idle(GENERAL_CONFIG | MAIN_COUNTER_VALUE | TIMER0_CONFIG_CAPS | TIMER0_COMPARATOR |
		      TIMER1_CONFIG_CAPS | TIMER1_COMPARATOR | TIMER2_CONFIG_CAPS |
		      TIMER2_COMPARATOR);
	/*
	 * Initial state of HPET is unknown, so put it back in a reset-like
	 * state (i.e. set main counter to 0 and disable interrupts)
	 */
	hpet_reg->gcfg_low &= ~HPET_ENABLE_CNF;
	hpet_reg->gis_low = HPET_GIS_CLEAR_MASK;
	hpet_reg->mcv_low = 0;
	hpet_reg->mcv_high = 0;

	/* Set interrupt router and trigger mode */
	hpet_reg->t0c_low = HPET_Tn_INT_TYPE_CNF |
			    (hpet_reg->t0c_low & ~HPET_Tn_INT_ROUTE_CNF_MASK) |
			    (SEDI_IRQ_HPET_TIMER_0 << HPET_Tn_INT_ROUTE_CNF_SHIFT);
	hpet_reg->t1c_low = HPET_Tn_INT_TYPE_CNF |
			    (hpet_reg->t1c_low & ~HPET_Tn_INT_ROUTE_CNF_MASK) |
			    (SEDI_IRQ_HPET_TIMER_1 << HPET_Tn_INT_ROUTE_CNF_SHIFT);
	hpet_reg->t2c_low = HPET_Tn_INT_TYPE_CNF |
			    (hpet_reg->t2c_low & ~HPET_Tn_INT_ROUTE_CNF_MASK) |
			    (TIMER2_INT_ROUTE << HPET_Tn_INT_ROUTE_CNF_SHIFT);

	/* Get source clock for this paltform */
	hpet_clock_period_pico = hpet_reg->gcid_high;

	wait_for_idle(GENERAL_CONFIG);
	/* Enable global settings */
	hpet_reg->gcfg_low = (HPET_ENABLE_CNF | HPET_LEGACY_RT_CNF);
	return 0;
}

void sedi_hpet_clear_int_status(IN sedi_hpet_t timer_id)
{
	wait_for_idle(GENERAL_INT_STATUS);
	hpet_reg->gis_low = BIT(timer_id);
}

void hpet_timer_isr(IN sedi_hpet_t timer_id)
{
	uint64_t curtick = CURRENT_HPET_CYCLE;

	if (!(hpet_reg->gis_low & BIT(timer_id)))
		return;

	/* Clear the GIS flags */
	wait_for_idle(GENERAL_INT_STATUS);
	hpet_reg->gis_low = BIT(timer_id);

	if (bsp_timers[timer_id].callback) {
		bsp_timers[timer_id].callback(bsp_timers[timer_id].param);
	}

	if (bsp_timers[timer_id].one_shot) {
		sedi_hpet_kill_timer(timer_id);
	} else {
		bsp_timers[timer_id].expires = curtick + bsp_timers[timer_id].timeout;
		/* Set new comparator */
		sedi_hpet_set_comparator(timer_id, bsp_timers[timer_id].expires);
	}
}

SEDI_ISR_DECLARE(sedi_hpet_timer_0_isr)
{
	hpet_timer_isr(0);
}

SEDI_ISR_DECLARE(sedi_hpet_timer_1_isr)
{
	hpet_timer_isr(1);
}

SEDI_ISR_DECLARE(sedi_hpet_timer_2_isr)
{
	hpet_timer_isr(2);
}

int32_t sedi_hpet_config_timer(IN sedi_hpet_t timer_id, IN uint64_t microseconds,
			       IN hpet_callback_t callback, IN void *param, IN bool one_shot)
{
	SEDI_ASSERT(timer_id < SEDI_HPET_SOC_TIMER_NUM);

	/* Check if timer is being used */
	SEDI_ASSERT(bsp_timers[timer_id].valid == 0);

	/* Just save here, will use when starting the timer */
	bsp_timers[timer_id].valid = 1;
	bsp_timers[timer_id].start = 0;
	bsp_timers[timer_id].one_shot = one_shot;
	bsp_timers[timer_id].microsec = microseconds;
	bsp_timers[timer_id].timeout = US_TO_HPET_CYCLE(microseconds);
	bsp_timers[timer_id].expires = 0;
	bsp_timers[timer_id].callback = callback;
	bsp_timers[timer_id].param = (void *)param;

	return SEDI_DRIVER_OK;
}

int32_t sedi_hpet_kill_timer(IN sedi_hpet_t timer_id)
{
	SEDI_ASSERT(timer_id < SEDI_HPET_SOC_TIMER_NUM);

	memset(&bsp_timers[timer_id], 0, sizeof(hpet_timer_ctx_t));

	/* Set comparator to 0 */
	sedi_hpet_set_comparator(timer_id, 0xFFFFFFFF);
	/* Disable interrupt */
	sedi_hpet_disable_interrupt(timer_id);

	return SEDI_DRIVER_OK;
}

int32_t sedi_hpet_start_timer(IN sedi_hpet_t timer_id)
{
	SEDI_ASSERT(timer_id < SEDI_HPET_SOC_TIMER_NUM);

	bsp_timers[timer_id].start = 1;
	bsp_timers[timer_id].expires = CURRENT_HPET_CYCLE + bsp_timers[timer_id].timeout;

	/* Set comparator to correct value */
	sedi_hpet_set_comparator(timer_id, bsp_timers[timer_id].expires);
	/* Enable interrupt */
	sedi_hpet_enable_interrupt(timer_id);

	return SEDI_DRIVER_OK;
}

uint32_t sedi_hpet_get_period(void)
{
	return (uint32_t)(hpet_reg->gcid_high);
}
