/*
 * Copyright (c) 2021-2024 Intel Corporation. All Rights Reserved.
 *
 * This software and the related documents are Intel copyrighted materials,
 * and your use of them is governed by the express license under which they
 * were provided to you ("License"). Unless the License provides otherwise,
 * you may not use, modify, copy, publish, distribute, disclose or transmit
 * this software or the related documents without Intel's prior written
 * permission.
 *
 * This software and the related documents are provided as is, with no express
 * or implied warranties, other than those that are expressly stated in the
 * License.
 */

#include <string.h>
#include <zephyr/kernel.h>
#include <sedi_driver_pm.h>
#include "iut.h"

#define TEST_PM_D0I0_MS_SLEEP (1)
#define TEST_PM_D0I1_MS_SLEEP (3)
#define TEST_PM_D0I2_MS_SLEEP (1000)
#define TEST_PM_D0I3_MS_SLEEP (5000)

#define PM_ENTER_D0             0
#define PM_ENTER_D0i1           1
#define PM_ENTER_D0i2           2
#define PM_ENTER_D0i3           3

extern void iut_shell_suspend(void);
extern void iut_shell_resume(void);
extern void reset_pm_stats(void);
extern void command_idle_stats(void);

/* usage: iut_run test_pm [pm level: 0-D0, 1-D0i1, 2-D0i2, 3-D0i3] [ms_sleep]*/
static int test_pm_d0ix(int argc, char **argv);
DEFINE_IUT_CASE(pm_d0ix, test_pm, IUT_ATTRI_NONE);

static int test_pm_d0i3(int argc, char **argv);
DEFINE_IUT_CASE(pm_d0i3, test_pm, IUT_ATTRI_AUTORUN);

static int test_pm_d0i2(int argc, char **argv);
DEFINE_IUT_CASE(pm_d0i2, test_pm, IUT_ATTRI_NONE);

static int test_pm_d0i1(int argc, char **argv);
DEFINE_IUT_CASE(pm_d0i1, test_pm, IUT_ATTRI_NONE);

static int test_pm_d0(int argc, char **argv);
DEFINE_IUT_CASE(pm_d0, test_pm, IUT_ATTRI_NONE);

static int test_pm_stress(int argc, char **argv);
DEFINE_IUT_CASE(pm_stress, test_pm, IUT_ATTRI_NONE);

static const char *const pm_level_str[PM_ENTER_D0i3 + 1] = {
	"D0",
	"D0i1",
	"D0i2",
	"D0i3",
};

static inline void clear_pm_stats(void)
{
	reset_pm_stats();
}

static void dump_pm_stats(uint32_t ms_sleep)
{
	ARG_UNUSED(ms_sleep);
	command_idle_stats();
}

static void _test_pm(uint32_t pm_level, uint32_t ms_sleep)
{
	clear_pm_stats();

	iut_case_print("test [%s]: going to sleep %u ms\n",
			pm_level_str[pm_level], ms_sleep);

	iut_shell_suspend();

	k_msleep(ms_sleep);

	iut_shell_resume();

	dump_pm_stats(ms_sleep);
}

static inline int _test_pm_d0(uint32_t ms_sleep)
{
	_test_pm(PM_ENTER_D0, ms_sleep);
	TEST_ASSERT_TRUE(1);

	return IUT_ERR_OK;
}

static int test_pm_d0(int argc, char **argv)
{
	return _test_pm_d0(TEST_PM_D0I0_MS_SLEEP);
}

static inline int _test_pm_d0i1(uint32_t ms_sleep)
{
	_test_pm(PM_ENTER_D0i1, ms_sleep);
	TEST_ASSERT_TRUE(1);

	return IUT_ERR_OK;
}

static int test_pm_d0i1(int argc, char **argv)
{
	return _test_pm_d0i1(TEST_PM_D0I1_MS_SLEEP);
}

static inline int _test_pm_d0i2(uint32_t ms_sleep)
{
	_test_pm(PM_ENTER_D0i2, ms_sleep);
	TEST_ASSERT_TRUE(1);

	return IUT_ERR_OK;
}

static int test_pm_d0i2(int argc, char **argv)
{
	return _test_pm_d0i2(TEST_PM_D0I2_MS_SLEEP);
}

static inline int _test_pm_d0i3(uint32_t ms_sleep)
{
	_test_pm(PM_ENTER_D0i3, ms_sleep);
	TEST_ASSERT_TRUE(1);

	return IUT_ERR_OK;
}

static int test_pm_d0i3(int argc, char **argv)
{
	return _test_pm_d0i3(TEST_PM_D0I3_MS_SLEEP);
}

static int test_pm_d0ix(int argc, char **argv)
{
	uint32_t ms_sleep = TEST_PM_D0I3_MS_SLEEP;
	uint32_t pm_level = PM_ENTER_D0i3;

	if (argc) {
		pm_level = (uint32_t)strtoul(argv[0], NULL, 0);
	}
	if (argc > 1) {
		ms_sleep = (uint32_t)strtoul(argv[1], NULL, 0);
	}

	switch (pm_level) {
	case PM_ENTER_D0:
		_test_pm_d0(ms_sleep);
		break;
	case PM_ENTER_D0i1:
		_test_pm_d0i1(ms_sleep);
		break;
	case PM_ENTER_D0i2:
		_test_pm_d0i2(ms_sleep);
		break;
	case PM_ENTER_D0i3:
		_test_pm_d0i3(ms_sleep);
		break;
	default:
		iut_case_print("wrong pm_level %u out of (0 - 3), exit\n",
				pm_level);
		TEST_ASSERT_TRUE(0);
	}

	return IUT_ERR_OK;
}

typedef int (*pm_test_fn)(int argc, char **argv);
static pm_test_fn pm_test_funcs[] = {
	&test_pm_d0i1,
	&test_pm_d0i2,
	&test_pm_d0i3,
};

#define PM_TEST_FUNC_NUM (ARRAY_SIZE(pm_test_funcs))

static int test_pm_stress(int argc, char **argv)
{
	uint32_t round = 5;

	if (argc) {
		round = (uint32_t)strtoul(argv[0], NULL, 0);
	}
	while (round--) {
		uint32_t idx = (uint32_t)z_tsc_read() % PM_TEST_FUNC_NUM;

		k_msleep(1000);
		pm_test_funcs[idx](0, NULL);
	}

	return IUT_ERR_OK;
}
