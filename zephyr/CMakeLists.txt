# Copyright (c) 2025 Intel Corporation.
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_INTEL_HAL)

  set(ZEPHYR_BASE_OOTREE ${CMAKE_CURRENT_SOURCE_DIR})

  function(zephyr_library_ootree_sources_ifdef feature_toggle source)
    zephyr_library_get_current_dir_lib_name(${ZEPHYR_BASE_OOTREE} lib_name)
    if(${${feature_toggle}})
      target_sources(${lib_name} PRIVATE ${source} ${ARGN})
    endif()
  endfunction()

  function(zephyr_library_ootree_sources source)
    zephyr_library_get_current_dir_lib_name(${ZEPHYR_BASE_OOTREE} lib_name)
    target_sources(${lib_name} PRIVATE ${source} ${ARGN})
  endfunction()

  function(zephyr_library_ootree_compile_options option)
    zephyr_library_get_current_dir_lib_name(${ZEPHYR_BASE_OOTREE} lib_name)
    target_compile_options(${lib_name} PRIVATE ${option} ${ARGN})
  endfunction()

  macro(zephyr_library_ootree)
    zephyr_library_get_current_dir_lib_name(${ZEPHYR_BASE_OOTREE} lib_name)
    zephyr_library_named(${lib_name})
  endmacro()

  function(zephyr_library_ootree_include_directories )
    zephyr_library_get_current_dir_lib_name(${ZEPHYR_BASE_OOTREE} lib_name)
    target_include_directories(${lib_name} PRIVATE ${ARGN})
  endfunction()

  set(BSP_SEDI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../bsp_sedi)
  set(BSP_SEDI_SOC_DIR ${BSP_SEDI_DIR}/soc/${SOC_FAMILY})
  set(BSP_SEDI_AON_DIR ${BSP_SEDI_SOC_DIR}/pm/aon)

  add_subdirectory(bsp_sedi)
  add_subdirectory(drivers)
  add_subdirectory(subsys)

endif()
