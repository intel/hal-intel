/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sedi_driver_common.h"
#include "sedi_driver_pm.h"

/* weak PM functions used by SEDI drivers when SEDI PM driver is not enabled */

void sedi_pm_set_device_power(IN sedi_devid_t id, IN sedi_power_state_t state)
{
	PARAM_UNUSED(id);
	PARAM_UNUSED(state);
}

sedi_power_state_t sedi_pm_get_device_power(IN sedi_devid_t id)
{
	PARAM_UNUSED(id);
	return SEDI_POWER_FULL;
}
