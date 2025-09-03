# Copyright (c) 2025 Intel Corporation.
#
# SPDX-License-Identifier: BSD-3-Clause

if (CONFIG_DMA_SEDI)
	zephyr_library_ootree_compile_options(-DSEDI_SPI_USE_DMA)
endif()

zephyr_library_ootree_sources(${BSP_SEDI_DIR}/drivers/spi/sedi_spi_dw_apb.c)

