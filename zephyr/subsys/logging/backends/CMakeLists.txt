# Copyright (c) 2024 Intel Corporation Inc.
#
# SPDX-License-Identifier: Apache-2.0
#

if (CONFIG_LOG)
  zephyr_sources_ifdef(CONFIG_LOG_BACKEND_I2C log_backend_i2c.c)
endif()
