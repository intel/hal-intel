# Copyright (c) 2024 Intel Corporation Inc.
#
# SPDX-License-Identifier: BSD-3-Clause
#

zephyr_sources_ifdef(CONFIG_LOG_BACKEND_I2C log_backend_i2c.c)
