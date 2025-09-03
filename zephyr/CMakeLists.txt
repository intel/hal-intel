# Copyright (c) 2023 Intel Corporation.
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_INTEL_HAL)

  set(BSP_SEDI_SRC ${CMAKE_CURRENT_SOURCE_DIR}/../bsp_sedi)

  zephyr_interface_library_named(BSP_SEDI)
  target_link_libraries(zephyr_interface INTERFACE BSP_SEDI)
  target_include_directories(BSP_SEDI INTERFACE ${BSP_SEDI_SRC}/include/driver)
  target_include_directories(BSP_SEDI INTERFACE ${BSP_SEDI_SRC}/include)

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

  set(BSP_SEDI_SOC_DIR ${BSP_SEDI_SRC}/soc/${SOC_FAMILY})
  if(DEFINED CONFIG_SOC_FAMILY_INTEL_ISH AND DEFINED CONFIG_PM)
      target_include_directories(BSP_SEDI INTERFACE ${BSP_SEDI_SOC_DIR}/pm/aon/include)
      zephyr_library_sources_ifdef(CONFIG_PM ${BSP_SEDI_SOC_DIR}/pm/sedi_pm.c)
      add_subdirectory(bsp_sedi/pm/aon)
  endif()

  target_include_directories(BSP_SEDI INTERFACE ${BSP_SEDI_SRC}/soc/common/include)

  target_include_directories(BSP_SEDI INTERFACE ${BSP_SEDI_SOC_DIR}/include)
  if(EXISTS ${BSP_SEDI_SOC_DIR}/sedi_soc.c)
      zephyr_library_sources(${BSP_SEDI_SOC_DIR}/sedi_soc.c)
  endif()

  add_subdirectory(subsys/logging/backends)
  add_subdirectory(bsp_sedi)
endif()
