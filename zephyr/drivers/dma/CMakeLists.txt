# Copyright (c) 2025 Intel Corporation.
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_SOC_INTEL_ISH_5_4_1 OR CONFIG_SOC_INTEL_ISH_5_6_0)
  zephyr_library_ootree_sources(${BSP_SEDI_DIR}/drivers/dma/sedi_dma_ann_1p0.c)
else()
  zephyr_library_ootree_sources(${BSP_SEDI_DIR}/drivers/dma/sedi_dma_dw_axi.c)
endif()
