/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "iut.h"
#include "sedi_driver_gpio.h"
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>

#define DT_DRV_COMPAT intel_sedi_gpio

#define GPIO_TEST_NUM (8)
#define GPIO_LOOP_INPUT (1)
#define GPIO_LOOP_OUTPUT (4)

#if DEBUG_GPIO
static void dump_gpio_regs(void)
{
	uint32_t regs = SEDI_IREG_BASE(GPIO, 0);

	iut_print("GPLR register is 0x%x\n", read32(regs + 0x4));
	iut_print("GPDR register is 0x%x\n", read32(regs + 0x1C));
	iut_print("GRER register is 0x%x\n", read32(regs + 0x64));
	iut_print("GFER register is 0x%x\n", read32(regs + 0x7c));
	iut_print("GIMR register is 0x%x\n", read32(regs + 0xac));
	iut_print("GISR register is 0x%x\n", read32(regs + 0xc4));
	iut_print("\n");
}
#else
static void dump_gpio_regs(void)
{
}
#endif

static int test_gpio_output(int argc, char **argv)
{
	const struct device *gpio_dev = DEVICE_DT_GET(DT_DRV_INST(0));
	int ret, i;

	for (i = 0; i < 8; i++) {
		iut_case_print("starting to test gpio pin %d output ...\n", i);

		/* Configure gpio pin to output mode, set to high */
		gpio_pin_configure(gpio_dev, i, GPIO_OUTPUT);
		dump_gpio_regs();
		gpio_pin_set_raw(gpio_dev, i, 1);
		dump_gpio_regs();

		/* Set pin to input mode and check the level */
		gpio_pin_configure(gpio_dev, i, GPIO_INPUT);
		dump_gpio_regs();
		ret = gpio_pin_get_raw(gpio_dev, i);
		TEST_ASSERT_EQUAL(1, ret);

		/* Set pin to output and set to low */
		gpio_pin_configure(gpio_dev, i, GPIO_OUTPUT);
		dump_gpio_regs();
		gpio_pin_set_raw(gpio_dev, i, 0);
		dump_gpio_regs();

		/* Set pin to input mode and check the level */
		gpio_pin_configure(gpio_dev, i, GPIO_INPUT);
		ret = gpio_pin_get_raw(gpio_dev, i);
		dump_gpio_regs();
		TEST_ASSERT_EQUAL(0, ret);

		iut_case_print("Pin %d Test done\n", i);
	}

	return IUT_ERR_OK;
}
DEFINE_IUT_CASE(gpio_output, gpio, IUT_ATTRI_NONE);

static struct gpio_callback gp_cb;
static uint32_t times;

static void test_callback(const struct device *port,
				struct gpio_callback *cb,
				gpio_port_pins_t pins)
{
	(void)port;
	(void)cb;
	times++;
	iut_print("trigger callback %d times, pin index is 0x%x\n", times, pins);
}

static int test_gpio_loopback(int argc, char **argv)
{
	const struct device *gpio_dev = DEVICE_DT_GET(DT_DRV_INST(0));
	int i;

	/* Configure gpio output pin */
	gpio_pin_configure(gpio_dev, GPIO_LOOP_OUTPUT, GPIO_OUTPUT | GPIO_OUTPUT_INIT_HIGH);
	dump_gpio_regs();

	/* Configure gpio input pin */
	gpio_pin_configure(gpio_dev, GPIO_LOOP_INPUT, GPIO_INPUT);
	dump_gpio_regs();

	/* Enable input pin interrupts and callbacks */
	gpio_pin_interrupt_configure(gpio_dev, GPIO_LOOP_INPUT,
					GPIO_INT_MODE_EDGE | GPIO_INT_LOW_0);

	gpio_init_callback(&gp_cb, test_callback, BIT(GPIO_LOOP_INPUT));
	gpio_add_callback(gpio_dev, &gp_cb);

	for (i = 0; i < 20; i++) {
		gpio_pin_set(gpio_dev, GPIO_LOOP_OUTPUT, 0);
		k_msleep(100);
		gpio_pin_toggle(gpio_dev, GPIO_LOOP_OUTPUT);
		k_msleep(100);
	}


	return IUT_ERR_OK;
}

DEFINE_IUT_CASE(gpio_loopback, gpio, IUT_ATTRI_NONE);
