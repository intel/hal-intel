/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _IUT_H_
#define _IUT_H_

#include <stdint.h>

typedef int (*iut_test_func)(int argc, char **argv);

struct iut_case {

	const char *const name;

	const char *const group;

	/* test function to run */
	const iut_test_func func;

	uint32_t attri;
};

#define IUT_ATTRI_NONE    ((uint32_t)0x0)
#define IUT_ATTRI_AUTORUN ((uint32_t)(0x1 << 0))

#define DEFINE_IUT_CASE(_name, _group, _attri) \
	struct iut_case iut_##_name\
			__attribute__((__used__)) \
			__attribute__((__section__(".iut_cases."#_group"."#_name))) = { \
		.name = #_name, \
		.group = #_group, \
		.func = &test_##_name, \
		.attri = _attri, \
	}

extern const char __iut_cases_start[];
extern const char __iut_cases_end[];

#include <zephyr/sys/printk.h>
#define iut_print(fmt, arg...) printk(fmt, ## arg)

extern const struct iut_case *iut_running;

#define iut_case_print(fmt, arg...) \
	iut_print("IUT: (%s, %s): "fmt, iut_running->group, iut_running->name, ## arg)

/* for strtoul */
#include <stdlib.h>

#ifndef ARG_UNUSED
#define ARG_UNUSED(arg) ((void)arg)
#endif

#define IUT_ERR_OK (0)
#define IUT_ERR_ASSERT (-1)

#define TEST_ASSERT_TRUE(_expr) \
	do { \
		if (_expr) \
			break; \
		printk("%s:%d: ASSERT failed\n", __FILE__, __LINE__); \
		return IUT_ERR_ASSERT; \
	} while (0)

#define TEST_ASSERT_EQUAL(_expr1, _expr2) \
		TEST_ASSERT_TRUE((_expr1) == (_expr2))

#endif
