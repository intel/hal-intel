/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "iut.h"

static int test_example_1(int argc, char **argv)
{
	iut_case_print("argc=%d\n", argc);
	for (int i = 0; i < argc; i++)
		iut_case_print("argv=\"%s\"\n", argv[i]);

	TEST_ASSERT_TRUE(1);

	return IUT_ERR_OK;
}
DEFINE_IUT_CASE(example_1, examples, IUT_ATTRI_AUTORUN);

static int test_example_2(int argc, char **argv)
{
	iut_case_print("argc=%d\n", argc);
	for (int i = 0; i < argc; i++)
		iut_case_print("argv=\"%s\"\n", argv[i]);

	TEST_ASSERT_TRUE(0);
	TEST_ASSERT_TRUE(1);

	return IUT_ERR_OK;
}
DEFINE_IUT_CASE(example_2, examples, IUT_ATTRI_AUTORUN);
