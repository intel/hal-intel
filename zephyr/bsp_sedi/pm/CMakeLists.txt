# Copyright (c) 2025 Intel Corporation.
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_PM)
  zephyr_library_sources(${BSP_SEDI_SOC_DIR}/pm/sedi_pm.c)

  add_subdirectory(aon)
endif()

