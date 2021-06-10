/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _BSP_CONFIG_H_
#define _BSP_CONFIG_H_

/*********************
 * clocks
 *********************
 */
#define CONFIG_CLK_FREQUENCY_MHZ                        100
#define CONFIG_RTC_FREQUENCY_HZ                         32768

/*********************
 * memory
 *********************
 */
#define PSE_CONFIG_ICCM_BASE                    0x00000000
#define PSE_CONFIG_DCCM_BASE                    0x20000000
#define PSE_CONFIG_CCM_SIZE                     0x60000
#define PSE_CONFIG_REDUNDANT_CCM_SIZE           0x10000
#define PSE_CONFIG_L2SRAM_BASE                  0x60000000
#define PSE_CONFIG_L2SRAM_SIZE                  0x100000
#define PSE_CONFIG_SRAM_BANK_SIZE               0x8000
#define PSE_CONFIG_SRAM_BANK_MASK               0xFFFFFFFF  /* To check how to operate bank mask */
#define PSE_CONFIG_AON_BASE                     0x70000000
#define PSE_CONFIG_AON_SIZE                     0x10000
#define PSE_CONFIG_AON_ROM_MEM_SIZE             64
#define PSE_CONFIG_BRINGUP_LOAD_ADDRESS         0x7000C000  /* Do not change it, since
							     * ROM has hardcoded it.
							     */
/*snowball*/
#define SNOWBALL_BASE (AON_BASE + AON_SIZE - PSE_CONFIG_AON_ROM_MEM_SIZE)


/*********************
 * power
 *********************
 */
#define PSE_CONFIG_SUPPORT_BME_AND_D3_EDGE_INTERRUPT           1
#define PSE_CONFIG_SUPPORT_SX                                  1
#define PSE_CONFIG_SUPPORT_RESET_PREP                          1
#define PSE_CONFIG_SUPPORT_SRAM_PG                             0

/*********************
 * drivers
 *********************
 */
/* I2C */
#define PSE_CONFIG_NUM_I2C_DEVICES                             2
#define PSE_CONFIG_I2C_CLK_SOURCE_MHZ                          100

#endif /*_BSP_CONFIG_H_*/
