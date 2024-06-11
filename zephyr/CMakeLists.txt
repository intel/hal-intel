# Copyright (c) 2023 Intel Corporation.
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_INTEL_HAL)

  set(BSP_SEDI_SRC ${CMAKE_CURRENT_SOURCE_DIR}/../bsp_sedi)

  zephyr_interface_library_named(BSP_SEDI)
  target_link_libraries(zephyr_interface INTERFACE BSP_SEDI)
  target_include_directories(BSP_SEDI INTERFACE ${BSP_SEDI_SRC}/include/driver)

  zephyr_library_named(modules_intel_hal)
  zephyr_library_link_libraries(BSP_SEDI)

  zephyr_library_sources(${BSP_SEDI_SRC}/drivers/rtc/sedi_rtc.c)
  zephyr_library_sources_ifdef(CONFIG_I2C_SEDI ${BSP_SEDI_SRC}/drivers/i2c/sedi_i2c_dw_apb_200a.c)
  zephyr_library_sources_ifdef(CONFIG_UART_SEDI ${BSP_SEDI_SRC}/drivers/usart/sedi_dw_uart.c)
  zephyr_library_sources_ifdef(CONFIG_GPIO_SEDI ${BSP_SEDI_SRC}/drivers/gpio/sedi_gpio.c)
  zephyr_library_sources_ifdef(CONFIG_SPI_SEDI ${BSP_SEDI_SRC}/drivers/spi/sedi_spi_dw_apb.c)
  if(CONFIG_DMA_SEDI OR CONFIG_I2C_SEDI OR CONFIG_SPI_SEDI)
    zephyr_library_sources(${BSP_SEDI_SRC}/drivers/dma/sedi_dma_ann_1p0.c)
  endif()
  zephyr_library_sources_ifdef(CONFIG_IPM_SEDI ${BSP_SEDI_SRC}/drivers/ipc/sedi_ipc.c)
  zephyr_library_sources(${BSP_SEDI_SRC}/drivers/hpet/sedi_hpet.c)

  if(DEFINED CONFIG_SOC_FAMILY_INTEL_ISH)
      zephyr_library_sources_ifdef(CONFIG_PM ${BSP_SEDI_SRC}/soc/intel_ish/pm/ish_pm.c)
      zephyr_library_sources_ifdef(CONFIG_PM ${BSP_SEDI_SRC}/soc/intel_ish/pm/ish_dma.c)
      zephyr_library_sources_ifdef(CONFIG_PM ${BSP_SEDI_SRC}/soc/intel_ish/pm/aon/aon_task.c)
      zephyr_library_sources_ifdef(CONFIG_PM ${BSP_SEDI_SRC}/soc/intel_ish/pm/aon/ipapg.S)
  endif()

  target_include_directories(BSP_SEDI INTERFACE ${BSP_SEDI_SRC}/soc/common/include)

  set(BSP_SEDI_SOC_DIR ${BSP_SEDI_SRC}/soc/${SOC_FAMILY})
  target_include_directories(BSP_SEDI INTERFACE ${BSP_SEDI_SOC_DIR}/include)
  if(EXISTS ${BSP_SEDI_SOC_DIR}/sedi_soc.c)
      zephyr_library_sources(${BSP_SEDI_SOC_DIR}/sedi_soc.c)
  endif()

  add_subdirectory(subsys/logging/backends)
endif()
