/*
 * Copyright (c) 2023 - 2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sedi_driver_common.h"
#include "sedi_driver_core.h"

/* counter for vnn_req/vnn_dereq per vnn_id */
static uint8_t vnn_req_counter[VNN_ID_TOP];

void __attribute__((weak)) sedi_log(int level, const char *fmt, ...)
{
	PARAM_UNUSED(level);
	PARAM_UNUSED(fmt);
}

#ifdef CONFIG_DEBUG
void __attribute__((weak)) sedi_assert_halt(void)
{
	while (1)
		;
}
#endif

/* weak PM functions used by SEDI drivers when SEDI PM driver is not enabled */

void __attribute__((weak)) sedi_pm_set_device_power(IN sedi_devid_t id, IN sedi_power_state_t state)
{
	PARAM_UNUSED(id);
	PARAM_UNUSED(state);
}

sedi_power_state_t __attribute__((weak)) sedi_pm_get_device_power(IN sedi_devid_t id)
{
	PARAM_UNUSED(id);

	return SEDI_POWER_FULL;
}

void PM_VNN_DRIVER_REQ(vnn_id_t vnn_id)
{
	unsigned int key = sedi_core_irq_lock();

	if (!vnn_req_counter[vnn_id])
		write32(PMU_VNN_REQ_31_0, BIT(vnn_id));
	++vnn_req_counter[vnn_id];

	sedi_core_irq_unlock(key);

	while (!(read32(PMU_VNN_REQ_ACK) & PMU_VNN_REQ_ACK_STS))
		;
}

void PM_VNN_DRIVER_DEREQ(vnn_id_t vnn_id)
{
	unsigned int key = sedi_core_irq_lock();

	if (vnn_req_counter[vnn_id] == 0) {
		goto out;
	}
	vnn_req_counter[vnn_id]--;
	if (vnn_req_counter[vnn_id] != 0) {
		goto out;
	}

	write32(PMU_VNN_REQ_31_0, BIT(vnn_id));
	write32(PMU_VNN_REQ_ACK, read32(PMU_VNN_REQ_ACK));
out:
	sedi_core_irq_unlock(key);
}

void PM_VNN_ALL_RESET(void)
{
	unsigned int key = sedi_core_irq_lock();

	write32(PMU_VNN_REQ_31_0, read32(PMU_VNN_REQ_31_0));
	write32(PMU_VNN_REQ_ACK, read32(PMU_VNN_REQ_ACK));

	for (int i = 0; i < VNN_ID_TOP; i++) {
		vnn_req_counter[i] = 0;
	}

	sedi_core_irq_unlock(key);
}

void PM_VNN_DRIVER_RESET(vnn_id_t vnn_id)
{
	unsigned int key = sedi_core_irq_lock();

	write32(PMU_VNN_REQ_31_0, read32(PMU_VNN_REQ_31_0) & BIT(vnn_id));
	vnn_req_counter[vnn_id] = 0;

	sedi_core_irq_unlock(key);
}
