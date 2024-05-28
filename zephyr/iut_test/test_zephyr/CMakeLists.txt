# Copyright (c) 2023 Intel Corporation Inc.
#
# SPDX-License-Identifier: Apache-2.0
#

if(CONFIG_DMA_SEDI)
  target_sources(app PRIVATE dma/test_dma_m2m.c)
endif()

if(CONFIG_I2C_SEDI)
  target_sources(app PRIVATE i2c/test_i2c_log.c)
endif()

if(CONFIG_GPIO_SEDI)
  target_sources(app PRIVATE gpio/test_gpio.c)
endif()

target_sources(app PRIVATE x86/test_fatal.c)
target_sources(app PRIVATE timer/test_sys_clock.c)
