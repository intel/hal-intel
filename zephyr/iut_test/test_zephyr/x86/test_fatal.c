/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "iut.h"

int _divider;

static int test_divide0(int argc, char **argv)
{
	int num = 1000;

	num /= _divider;

	iut_case_print("no way to come here, %d\n", num);
	TEST_ASSERT_TRUE(1);

	return IUT_ERR_OK;
}

DEFINE_IUT_CASE(divide0, fatal, IUT_ATTRI_NONE);
