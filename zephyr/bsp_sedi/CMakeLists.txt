# Copyright (c) 2023-2025 Intel Corporation.
#
# SPDX-License-Identifier: BSD-3-Clause

SET(INTEL_HAL_LIB_NAME intel_hal_bsp_sedi)

zephyr_interface_library_named(intel_hal_interface)
zephyr_library_named(${INTEL_HAL_LIB_NAME})
zephyr_library_link_libraries(intel_hal_interface)
target_link_libraries(zephyr_interface INTERFACE intel_hal_interface)
target_include_directories(intel_hal_interface INTERFACE ${BSP_SEDI_DIR}/include)
target_include_directories(intel_hal_interface INTERFACE ${BSP_SEDI_DIR}/include/driver)
target_include_directories(intel_hal_interface INTERFACE ${BSP_SEDI_SOC_DIR}/include)
target_include_directories(intel_hal_interface INTERFACE ${BSP_SEDI_SOC_DIR}/../common/include)

if(EXISTS ${BSP_SEDI_SOC_DIR}/sedi_soc.c)
  zephyr_library_sources(${BSP_SEDI_SOC_DIR}/sedi_soc.c)
endif()

zephyr_library_sources(${BSP_SEDI_DIR}/drivers/rtc/sedi_rtc.c)
zephyr_library_sources(${BSP_SEDI_DIR}/drivers/hpet/sedi_hpet.c)

zephyr_sources(bsp_sedi_rtos_utils.c)

add_subdirectory(pm)
