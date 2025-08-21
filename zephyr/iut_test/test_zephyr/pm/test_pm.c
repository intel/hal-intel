/*
 * Copyright (c) 2025 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "iut.h"
#include "iut_zephyr.h"
#include <zephyr/kernel.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>
#include <zephyr/pm/state.h>
#include <zephyr/sys/__assert.h>

#define TEST_PM_MS_SLEEP_LONG (5 * 1000)

static int set_pm_states(uint32_t level, bool to_restore)
{
	int ret = -EINVAL;
	const struct pm_state_info *cpu_states;
	uint8_t num_cpu_states = pm_state_cpu_get_all(0U, &cpu_states);

	for (uint8_t i = 0; i < num_cpu_states; ++i) {
		if (cpu_states[i].substate_id == level) {
			ret = 0;
			break;
		}
	}

	if (ret) {
		return ret;
	}

	for (uint8_t i = 0; i < num_cpu_states; ++i) {
		if (cpu_states[i].substate_id == level) {
			__ASSERT_NO_MSG(!pm_policy_state_lock_is_active(cpu_states[i].state,
					cpu_states[i].substate_id));
			continue;
		}

		if (!to_restore) {
			__ASSERT_NO_MSG(!pm_policy_state_lock_is_active(cpu_states[i].state,
				cpu_states[i].substate_id));
			pm_policy_state_lock_get(
					cpu_states[i].state, cpu_states[i].substate_id);
		} else {
			__ASSERT_NO_MSG(pm_policy_state_lock_is_active(cpu_states[i].state,
				cpu_states[i].substate_id));
			pm_policy_state_lock_put(
					cpu_states[i].state, cpu_states[i].substate_id);
		}
	}

	return ret;
}

/* usage: iut_run pm_d0ix [pm level: ISH_PM_STATE_D0i0/1/2/3] [ms_sleep] */
static int test_pm_d0ix(int argc, char **argv)
{
	int ret = 0;
	uint32_t ms_sleep = TEST_PM_MS_SLEEP_LONG;
	uint32_t pm_level = 0;

	if (argc) {
		pm_level = (uint32_t)strtoul(argv[0], NULL, 0);
	}
	if (argc > 1) {
		ms_sleep = (uint32_t)strtoul(argv[1], NULL, 0);
	}

	iut_case_print("Test D0i%u: going to sleep %u ms ...\n", pm_level, ms_sleep);
	ret = set_pm_states(pm_level, false);
	if (ret) {
		iut_case_print("Failed to set PM state %u, ret = %d\n", pm_level, ret);
		TEST_ASSERT_TRUE(0);
	}
	iut_shell_suspend();

	k_msleep(ms_sleep);

	iut_shell_resume();
	(void)set_pm_states(pm_level, true);

	TEST_ASSERT_EQUAL(ret, 0);
	return 0;
}

DEFINE_IUT_CASE(pm_d0ix, pm, IUT_ATTRI_NONE);
