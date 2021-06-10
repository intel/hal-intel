/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_TSN_H_
#define _SEDI_DRIVER_TSN_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "sedi_driver_common.h"

/*!
 * \defgroup sedi_driver_tsn TSN
 * \ingroup sedi_driver
 */

#define SEDI_TSN_API_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

#define PHYIF_REGION_AONRF_ADDR (0x70008800)

#define PCI_ECAM_MASK (0x001FF000)
#define PSE_GBE0_ECAM (0x000E9000) /* PCI bus: 0, dev: 29, func: 1 */
#define PSE_GBE1_ECAM (0x000EA000) /* PCI bus: 0, dev: 29, func: 2 */

#ifndef TSN_PORT_MAX
#define TSN_PORT_MAX 4
#endif

#define PSE_MAX_GBE_PORTS 2

/*!
 * \enum pse_gbe_port
 * \brief GBE port in PSE.
 * \ingroup sedi_driver_tsn
 */
enum pse_gbe_port {
	PSE_GBE0,
	PSE_GBE1,
};

/*!
 * \enum pse_phyif_type
 * \brief GBE PHY interface type.
 * \ingroup sedi_driver_tsn
 */
enum pse_phyif_type {
	PHY_NOT_CONNECTED,
	PHY_RGMII,
	PHY_SGMII,
	PHY_SGMII_PLUS,
};

/*!
 * \struct tsn_phyif_data
 * \brief TSN PHY info.
 * \ingroup sedi_driver_tsn
 */
struct tsn_phyif_data {
	uint32_t bus_dev_fnc; /* associated PCI(Bus:Dev:Fnc), ECAM format */
	uint32_t phy_intf_type;   /* 0: not connected;1: RGMII;2: SGMII;3: SGMII+ */
} __attribute__((packed));

/*!
 * \struct phyif_config_data
 * \brief TSN PHY config data.
 * \ingroup sedi_driver_tsn
 */
struct phyif_config_data {
	/* data format version */
	uint32_t version;
	/* number of valid tsn_phyif_data in this structure */
	uint32_t num_ports;
	/* TSN PHY interface info structures */
	struct tsn_phyif_data port[TSN_PORT_MAX];
};

/**
 * \brief Search for PSE GbE port PHY interface data entry and return the entry number
 * \param[in] gbeport PSE GbE port number
 * \return GbE port number or error codes
 */
static inline int locate_pse_gbe_entry(int gbeport)
{
	struct phyif_config_data *pphyif_data = (void *)PHYIF_REGION_AONRF_ADDR;
	/* PSE GbE PCI Devices ECAM Table */
	uint32_t pse_gbe_ecam_tabl[PSE_MAX_GBE_PORTS] = {PSE_GBE0_ECAM,
		PSE_GBE1_ECAM};

	/* ToDo: check data struct version */

	/* Check number of valid entries in data struct */
	if (!pphyif_data->num_ports || pphyif_data->num_ports > TSN_PORT_MAX) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	/* Locate the entry number by comparing the PSE GbE PCI BDF */
	for (int i = 0; i < pphyif_data->num_ports; i++) {
		if ((pphyif_data->port[i].bus_dev_fnc & PCI_ECAM_MASK) ==
				pse_gbe_ecam_tabl[gbeport]) {
			return i;
		}
	}

	return SEDI_DRIVER_ERROR;
}

/**
 * \brief Get the PSE GbE port PHY interface value from BIOS pass-in data struct
 * \param[in] gbeport PSE GbE port number
 * \return PSE GbE PHY interface type from enum pse_phyif_type
 */
static inline uint32_t pse_gbe_get_phyif(int gbeport)
{
	int ret;
	struct phyif_config_data *pphyif_data = (void *)PHYIF_REGION_AONRF_ADDR;

	ret = locate_pse_gbe_entry(gbeport);
	if (ret < 0) {
		/* return PHY_NOT_CONNECTED if no data entry found from
		 * BIOS pass-in struct
		 */
		return PHY_NOT_CONNECTED;
	}

	return pphyif_data->port[ret].phy_intf_type;
}

#ifdef __cplusplus
}
#endif

#endif /*_SEDI_DRIVER_TSN_H_*/
