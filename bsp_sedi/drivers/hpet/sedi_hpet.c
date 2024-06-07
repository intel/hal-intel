/*
 * Copyright (c) 2023 - 2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <sedi_driver_hpet.h>
#include <sedi_hpet_regs.h>
#include <string.h>

/* define two 64-bit registers for easy access with SEDI REG APIs */
SEDI_REG_DEFINE(HPET, T0CV, 0x108, RW, (uint64_t)-1, (uint64_t)-1);
SEDI_REG_DEFINE(HPET, MCV, 0x0f0, RW, (uint64_t)-1, (uint64_t)0x0);

/* driver version */
#define SEDI_HPET_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

#define PICOSECS_PER_USEC 1000000

#define US_TO_HPET_CYCLE(us) ((uint64_t)(us)*PICOSECS_PER_USEC / hpet_clock_period_pico)
#define HPET_CYCLE_TO_US(cycle) ((uint64_t)(cycle)*hpet_clock_period_pico / PICOSECS_PER_USEC)

/* control and status register macros */
#define CTRL_STS_GENERAL_CONFIG SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS0)
#define CTRL_STS_GENERAL_INT_STATUS SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS1)
#define CTRL_STS_MAIN_COUNTER_VALUE                                                                \
	(SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS2) |                                          \
	 SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS3))
#define CTRL_STS_TIMER0_CONFIG_CAPS SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS4)
#define CTRL_STS_TIMER1_CONFIG_CAPS SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS5)
#define CTRL_STS_TIMER2_CONFIG_CAPS SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS6)
#define CTRL_STS_TIMER0_COMPARATOR                                                                 \
	(SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS7) |                                          \
	 SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS8))
#define CTRL_STS_TIMER1_COMPARATOR SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS9)
#define CTRL_STS_TIMER2_COMPARATOR SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS10)
#define CTRL_STS_MAIN_COUNTER_VALUE_INVALID SEDI_RBFM(HPET, HPET_CTRL_STS, HPET_CTRL_STS13)

/*Macro for interrupt routing*/
#define TIMER2_INT_ROUTE (0x0b)

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

static uint32_t hpet_clock_period_pico = 30517578; /* picoseconds */
static uint32_t hpet_min_delay = 5; /* HPET cycles */
/* driver version */
static const sedi_driver_version_t driver_version = { SEDI_HPET_API_VERSION,
						      SEDI_HPET_DRIVER_VERSION };
/* Capabilities for hpet */
static const sedi_hpet_capabilities_t hpet_cap = { 0 };

static inline void wait_for_idle(uint32_t bits)
{
	SEDI_POLL_WAIT(SEDI_REG_GET(HPET, HPET_CTRL_STS) & bits, 10);
}

uint32_t sedi_hpet_get_min_delay(void)
{
	return hpet_min_delay;
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

static int sedi_hpet_update_comparator(IN sedi_hpet_t timer_id, IN uint64_t value)
{
	switch (timer_id) {
	case HPET_0:
		SEDI_REG_SET(HPET, T0CV, value);
		break;
	case HPET_1:
		SEDI_REG_SET(HPET, T1CV_LOW, (uint32_t)value);
		break;
	case HPET_2:
		SEDI_REG_SET(HPET, T2CV_LOW, (uint32_t)value);
		break;
	default:
		return SEDI_DRIVER_ERROR_NO_DEV;
	}

	return SEDI_DRIVER_OK;
}

int sedi_hpet_set_comparator(IN sedi_hpet_t timer_id, IN uint64_t value)
{
	uint64_t _value = value;
	/* need to wait until INT clearing is finished, or HPET
	 * goes out of work
	 */
	uint32_t sts_wait = CTRL_STS_GENERAL_INT_STATUS | CTRL_STS_TIMER0_COMPARATOR |
			    CTRL_STS_TIMER1_COMPARATOR | CTRL_STS_TIMER2_COMPARATOR;
	uint64_t now;
	int64_t diff;

	if ((timer_id != HPET_0) && (value >> 32)) {
		/* it's wrong to set into a 32-bits timer */
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

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

	return sedi_hpet_update_comparator(timer_id, _value);
}

void sedi_hpet_set_main_counter(uint64_t value)
{
	wait_for_idle(CTRL_STS_MAIN_COUNTER_VALUE);
	SEDI_REG_SET(HPET, MCV, value);
}

uint64_t sedi_hpet_get_main_counter(void)
{
	uint32_t highBits;
	uint32_t lowBits;

	wait_for_idle(CTRL_STS_MAIN_COUNTER_VALUE_INVALID);
	do {
		highBits = SEDI_REG_GET(HPET, MCV_HIGH);
		lowBits = SEDI_REG_GET(HPET, MCV_LOW);
	} while (highBits != SEDI_REG_GET(HPET, MCV_HIGH));

	return ((uint64_t)highBits << 32) | lowBits;
}

uint64_t sedi_hpet_get_us(void)
{
	return HPET_CYCLE_TO_US(sedi_hpet_get_main_counter());
}

void sedi_hpet_enable_interrupt(IN sedi_hpet_t timer_id)
{
	switch (timer_id) {
	case HPET_0:
		wait_for_idle(CTRL_STS_TIMER0_CONFIG_CAPS);
		SEDI_REG_RBFV_SET(HPET, T0C_LOW, IE, 1);
		break;
	case HPET_1:
		wait_for_idle(CTRL_STS_TIMER1_CONFIG_CAPS);
		SEDI_REG_RBFV_SET(HPET, T1C_LOW, IE, 1);
		break;
	case HPET_2:
		wait_for_idle(CTRL_STS_TIMER2_CONFIG_CAPS);
		SEDI_REG_RBFV_SET(HPET, T2C_LOW, IE, 1);
		break;
	default:
		break;
	}
}

void sedi_hpet_disable_interrupt(IN sedi_hpet_t timer_id)
{
	switch (timer_id) {
	case HPET_0:
		wait_for_idle(CTRL_STS_TIMER0_CONFIG_CAPS);
		SEDI_REG_RBFV_SET(HPET, T0C_LOW, IE, 0);
		break;
	case HPET_1:
		wait_for_idle(CTRL_STS_TIMER1_CONFIG_CAPS);
		SEDI_REG_RBFV_SET(HPET, T1C_LOW, IE, 0);
		break;
	case HPET_2:
		wait_for_idle(CTRL_STS_TIMER2_CONFIG_CAPS);
		SEDI_REG_RBFV_SET(HPET, T2C_LOW, IE, 0);
		break;
	default:
		break;
	}
}

int32_t sedi_hpet_init(uint32_t clk_divisor, uint32_t min_delay)
{
	wait_for_idle(CTRL_STS_GENERAL_CONFIG | CTRL_STS_MAIN_COUNTER_VALUE |
		      CTRL_STS_TIMER0_CONFIG_CAPS | CTRL_STS_TIMER0_COMPARATOR |
		      CTRL_STS_TIMER1_CONFIG_CAPS | CTRL_STS_TIMER1_COMPARATOR |
		      CTRL_STS_TIMER2_CONFIG_CAPS | CTRL_STS_TIMER2_COMPARATOR);
	/*
	 * Initial state of HPET is unknown, so put it back in a reset-like
	 * state (i.e. set main counter to 0 and disable interrupts)
	 */
	 sedi_hpet_update_comparator(HPET_0, (uint64_t)-1);
	 sedi_hpet_update_comparator(HPET_1, (uint64_t)-1);
	 sedi_hpet_update_comparator(HPET_2, (uint64_t)-1);
	SEDI_REG_RBFV_SET(HPET, GCFG_LOW, EN, 0);
	SEDI_REG_SET(HPET, GIS_LOW, SEDI_REG_GET(HPET, GIS_LOW));
	SEDI_REG_SET(HPET, MCV, (uint64_t)0x0);

	/* Set interrupt router and trigger mode */
	SEDI_REG_SET(HPET, T0C_LOW,
		     SEDI_RBFM_VALUE(HPET, T0C_LOW, IR, SEDI_IRQ_HPET_TIMER_0) |
			     SEDI_RBFVM(HPET, T0C_LOW, IT, 1));
	SEDI_REG_SET(HPET, T1C_LOW,
		     SEDI_RBFM_VALUE(HPET, T1C_LOW, IR, SEDI_IRQ_HPET_TIMER_1) |
			     SEDI_RBFVM(HPET, T1C_LOW, IT, 1));
	SEDI_REG_SET(HPET, T2C_LOW,
		     SEDI_RBFM_VALUE(HPET, T2C_LOW, IR, TIMER2_INT_ROUTE) |
			     SEDI_RBFVM(HPET, T2C_LOW, IT, 1));

	/* Get source clock for this paltform */
	hpet_clock_period_pico = SEDI_REG_RBFV_GET(HPET, GCID_HIGH, CTP) * clk_divisor;
	hpet_min_delay = min_delay;

	wait_for_idle(CTRL_STS_GENERAL_CONFIG);
	/* Enable global settings */
	SEDI_REG_SET(HPET, GCFG_LOW,
		     SEDI_RBFVM(HPET, GCFG_LOW, LRE, 1) | SEDI_RBFVM(HPET, GCFG_LOW, EN, 1));

	return 0;
}

uint32_t sedi_hpet_get_int_status(void)
{
	wait_for_idle(CTRL_STS_GENERAL_INT_STATUS);
	return SEDI_REG_GET(HPET, GIS_LOW);
}

void sedi_hpet_set_int_status(IN uint32_t val)
{
	SEDI_REG_SET(HPET, GIS_LOW, val);
	wait_for_idle(CTRL_STS_GENERAL_INT_STATUS);
}

void sedi_hpet_timer_int_handler(IN sedi_hpet_t timer_id)
{
	if (!(SEDI_REG_GET(HPET, GIS_LOW) & BIT(timer_id)))
		return;

	/* Clear the GIS flags */
	sedi_hpet_set_int_status(BIT(timer_id));

	if (bsp_timers[timer_id].callback) {
		bsp_timers[timer_id].callback(bsp_timers[timer_id].param);
	}

	if (bsp_timers[timer_id].one_shot) {
		sedi_hpet_kill_timer(timer_id);
	} else {
		bsp_timers[timer_id].expires =
			sedi_hpet_get_main_counter() + bsp_timers[timer_id].timeout;
		/* Set new comparator */
		sedi_hpet_set_comparator(timer_id, bsp_timers[timer_id].expires);
	}
}

int32_t sedi_hpet_config_timer(IN sedi_hpet_t timer_id, IN uint64_t microseconds,
			       IN hpet_callback_t callback, IN void *param, IN bool one_shot)
{
	DBG_CHECK(timer_id < SEDI_HPET_SOC_TIMER_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	/* Check if timer is being used */
	DBG_CHECK(bsp_timers[timer_id].valid == 0, SEDI_DRIVER_ERROR_BUSY);

	/* Just save here, will use when starting the timer */
	bsp_timers[timer_id].valid = 1;
	bsp_timers[timer_id].start = 0;
	bsp_timers[timer_id].one_shot = one_shot ? 1 : 0;
	bsp_timers[timer_id].microsec = microseconds;
	bsp_timers[timer_id].timeout = US_TO_HPET_CYCLE(microseconds + HPET_CYCLE_TO_US(1));
	bsp_timers[timer_id].expires = 0;
	bsp_timers[timer_id].callback = callback;
	bsp_timers[timer_id].param = (void *)param;
	if (bsp_timers[timer_id].timeout < hpet_min_delay) {
		bsp_timers[timer_id].timeout = hpet_min_delay;
	}

	return SEDI_DRIVER_OK;
}

int32_t sedi_hpet_kill_timer(IN sedi_hpet_t timer_id)
{
	DBG_CHECK(timer_id < SEDI_HPET_SOC_TIMER_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	/* Disable interrupt */
	sedi_hpet_disable_interrupt(timer_id);
	sedi_hpet_set_int_status(BIT(timer_id));

	/* Set comparator all bits as 1 */
	sedi_hpet_update_comparator(timer_id, (uint64_t)-1);

	memset(&bsp_timers[timer_id], 0, sizeof(hpet_timer_ctx_t));

	return SEDI_DRIVER_OK;
}

int32_t sedi_hpet_start_timer(IN sedi_hpet_t timer_id)
{
	DBG_CHECK(timer_id < SEDI_HPET_SOC_TIMER_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	/* Enable interrupt */
	sedi_hpet_enable_interrupt(timer_id);

	bsp_timers[timer_id].start = 1;
	bsp_timers[timer_id].expires = sedi_hpet_get_main_counter() + bsp_timers[timer_id].timeout;

	/* Set comparator to correct value */
	sedi_hpet_set_comparator(timer_id, bsp_timers[timer_id].expires);

	return SEDI_DRIVER_OK;
}

uint32_t sedi_hpet_get_period(void)
{
	return (uint32_t)(hpet_clock_period_pico);
}
