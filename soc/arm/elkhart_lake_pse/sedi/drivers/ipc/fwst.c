/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "ipc_bsp.h"
#include <sedi_driver.h>

typedef enum { FWST_OFFSET, FWST_MASK, FWST_PARAMS_LAST } FWST_PARAMS;

static uint8_t fwst_offsets[FWST_TYPES_LAST][FWST_PARAMS_LAST] = {
    {0, 0x1},  /* ILUP Host */
    {0, 0x1},  /* ILUP SEC */
    {1, 0x1},  /* HUP */
    {2, 0xf},  /* fail_reason */
    {8, 0xf},  /* reset_id */
    {12, 0xf}, /* fw_state */
    {16, 0x1}, /* DMA0 */
    {17, 0x1}, /* DMA1 */
    {18, 0x1}, /* DMA2 */
    {19, 0x1}, /* DMA3 */
    {20, 0xf}, /* pwr_state	*/
    {24, 0x7}  /* AON CP */
};

int32_t sedi_fwst_get(sedi_fwst_type_t type, uint32_t *value)
{
	DBG_CHECK(NULL != value, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(FWST_TYPES_LAST > type, SEDI_DRIVER_ERROR_PARAMETER);

	if (type == ILUP_SEC) {
		sedi_fwst_stat_reg_t sec;
		sec.dw = read32(IPC_CSME_BASE + IPC_OSE2PEER_FWSTS);
		*value = sec.bits.ilup;
		return SEDI_DRIVER_OK;
	}

	sedi_fwst_stat_reg_t host;
	host.dw = read32(IPC_HOST_BASE + IPC_OSE2PEER_FWSTS);
	*value = (host.dw >> fwst_offsets[type][FWST_OFFSET]) &
		 fwst_offsets[type][FWST_MASK];

	return SEDI_DRIVER_OK;
}

void sedi_fwst_set(sedi_fwst_type_t type, uint32_t value)
{
	sedi_fwst_stat_reg_t host;
	sedi_fwst_stat_reg_t sec;

	/* Only ROM is allowed to change reset count */
	SEDI_ASSERT(RESET_COUNT != type);
	SEDI_ASSERT(FWST_TYPES_LAST > type);
	SEDI_ASSERT((uint32_t)fwst_offsets[type][FWST_MASK] >= value);

	host.dw = read32(IPC_HOST_BASE + IPC_OSE2PEER_FWSTS);
	sec.dw = read32(IPC_CSME_BASE + IPC_OSE2PEER_FWSTS);

	if (type == ILUP_HOST) {
		host.bits.ilup = value;
	} else if (type == ILUP_SEC) {
		sec.bits.ilup = value;
	} else {
		host.dw &= ~(fwst_offsets[type][FWST_MASK]
			     << fwst_offsets[type][FWST_OFFSET]);
		host.dw |= (value << fwst_offsets[type][FWST_OFFSET]);

		sec.dw &= ~(fwst_offsets[type][FWST_MASK]
			    << fwst_offsets[type][FWST_OFFSET]);
		sec.dw |= (value << fwst_offsets[type][FWST_OFFSET]);
	}

	write32(IPC_HOST_BASE + IPC_OSE2PEER_FWSTS, host.dw);
	write32(IPC_CSME_BASE + IPC_OSE2PEER_FWSTS, sec.dw);
}
