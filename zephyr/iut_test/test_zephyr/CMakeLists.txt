# Copyright (c) 2023 Intel Corporation Inc.
#
# SPDX-License-Identifier: Apache-2.0
#

if(CONFIG_DMA)
  target_sources(app PRIVATE dma/test_dma_m2m.c)
endif()
