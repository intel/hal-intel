/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_H_
#define _SEDI_H_

/*!
 * \defgroup sedi SEDI API
 */
#define __weak __attribute__((__weak__))

#include <sedi_driver.h>

__weak void log_func_trace(const char *func, uint16_t line)
{
	PARAM_UNUSED(func);
	PARAM_UNUSED(line);
}

#define __SEDI_FTRACE__ log_func_trace(__func__, __LINE__);

#endif /* _SEDI_H_*/
