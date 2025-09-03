# Copyright (c) 2025 Intel Corporation.
#
# SPDX-License-Identifier: BSD-3-Clause

zephyr_library_named(intel_hal_aontask)

zephyr_library_include_directories(${BSP_SEDI_AON_DIR}/include)

zephyr_library_sources(${BSP_SEDI_AON_DIR}/ish_aontask.c)
zephyr_library_sources(${BSP_SEDI_AON_DIR}/ish_dma.c)
zephyr_library_sources(${BSP_SEDI_AON_DIR}/ish_ipapg.S)

zephyr_library_compile_options(${COMPILER_OPTIMIZE_FOR_SIZE_FLAG} -mno-80387)

