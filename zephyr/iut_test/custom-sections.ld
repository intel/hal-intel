/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

	. = ALIGN(8);
	__iut_cases_start = .;
	KEEP(*(SORT(.iut_cases.*)));
	__iut_cases_end = .;
