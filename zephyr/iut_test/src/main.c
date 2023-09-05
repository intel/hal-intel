/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include <zephyr/kernel.h>
#include "iut.h"
#include <zephyr/sys/__assert.h>

#define ARGC_MIN_NUM 2
#define ARGC_MAX_NUM 8
static char argv_buf[1024];
static uint32_t argv_buf_pos;
static int argc_run;
static char *argv_run[ARGC_MAX_NUM];

static K_SEM_DEFINE(sem_trigger, 1, 1);
static K_SEM_DEFINE(sem_run, 0, 1);

static uint32_t iut_cnt_run;
static uint32_t iut_cnt_fail;

const struct iut_case *iut_running;

static int iut_run(const char *name, const char *group, uint32_t attri,
		int argc, char **argv)
{
	const struct iut_case *ut = NULL;
	int ret;

	iut_print("\nIUT: (%s, %s, 0x%x): Start running cases ......\n",
			group ? group : "NULL", name ? name : "NULL", attri);

	if (argc) {
		iut_print("\targc=%d\n", argc);
		for (int i = 0; i < argc; i++)
			iut_print("\targv[%d]=\"%s\"\n", i, argv[i]);
	}

	iut_cnt_run = iut_cnt_fail = 0;

	while (1) {
		if (ut == NULL) {
			ut = (void *)__iut_cases_start;
		} else {
			ut++;
		}
		if ((char *)ut >= __iut_cases_end) {
			break;
		}

		if (group && strncmp(group, ut->group, strlen(group))) {
			continue;
		}
		if (name && strncmp(ut->name, name, strlen(ut->name) + 1)) {
			continue;
		}
		if (attri && ((ut->attri & attri) != attri)) {
			continue;
		}

		iut_print("IUT: (%s, %s): Case %u, run\n",
				ut->group, ut->name, iut_cnt_run);
		iut_running = ut;

		ret = ut->func(argc, argv);

		iut_print("IUT: (%s, %s): Case %u, %s\n",
				ut->group, ut->name, iut_cnt_run,
				(ret == IUT_ERR_OK) ? "pass" : "fail");
		iut_cnt_run++;
		if (ret != IUT_ERR_OK) {
			iut_cnt_fail++;
		}
	}

	iut_print("\nIUT: (%s, %s, 0x%x): Finished %u cases, %u failed ......\n",
			group ? group : "NULL", name ? name : "NULL", attri,
			iut_cnt_run, iut_cnt_fail);

	return 0;
}

int iut_trigger(size_t argc, char **argv)
{
	if (k_sem_take(&sem_trigger, K_NO_WAIT) != 0) {
		iut_print("busy running (%s: %s: %s), please wait and try later!\n",
				argv_run[0], argv_run[1],
				(argc_run >= 3) ? argv_run[2] : "NULL");
		return -EBUSY;
	}

	if ((argc < ARGC_MIN_NUM) || (argc > ARGC_MAX_NUM)) {
		goto err_out;
	}

	argv_buf_pos = 0;

	for (int i = 0; i < argc; i++) {
		uint32_t len = strlen(argv[i]);

		if ((argv_buf_pos + len + 1) > sizeof(argv_buf)) {
			goto err_out;
		}

		argv_run[i] = &argv_buf[argv_buf_pos];
		memcpy(argv_run[i], argv[i], len + 1);
		argv_buf_pos += (len + 1);
	}

	argc_run = argc;
	k_sem_give(&sem_run);

	return 0;

err_out:
	iut_print("wrong parameters to run, argc=%d", (int)argc);
	return -EPERM;
}

int main(void)
{
	k_msleep(2000);

#ifndef CONFIG_DEBUG
	/* iut_run(NULL, NULL, IUT_ATTRI_AUTORUN, 0, NULL); */
#endif

	while (1) {
		const char *name = NULL;
		const char *group = NULL;

		k_sem_take(&sem_run, K_FOREVER);

		if (strncmp(argv_run[0], "grun", strlen(argv_run[0])) == 0) {
			group = argv_run[1];
		} else {
			__ASSERT_NO_MSG(strncmp(argv_run[0], "run",
						strlen(argv_run[0])) == 0);
			name = argv_run[1];
		}

		iut_run(name, group, 0x0, (argc_run - 2),
				(argc_run - 2) ? (&argv_run[2]) : NULL);

		k_sem_give(&sem_trigger);
	};

	return 0;
}
