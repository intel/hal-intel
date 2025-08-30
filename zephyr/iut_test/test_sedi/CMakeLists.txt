# Copyright (c) 2023 Intel Corporation Inc.
#
# SPDX-License-Identifier: Apache-2.0
#

target_sources(app PRIVATE test_sedi_rtc.c)

if(CONFIG_DMA_SEDI)
  target_sources(app PRIVATE test_sedi_dma.c)
endif()
