/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sedi_driver_pm.h"
#include <sedi_gpio_regs.h>
#include <sedi_driver_gpio.h>

/* driver version */
#define SEDI_GPIO_DRIVER_VERSION SEDI_DRIVER_VERSION_MAJOR_MINOR(0, 1)

/* GPIO port pin number */
#define GPIO_PORT_PIN_NUM (32U)
#define GPIO_PORT_SHIFT_BITS (5U)
#define GPIO_PORT_MASK (0x1FU)
/* GPIO port access offset unit */
#define GPIO_8_BITS_OFFSET (8U)
#define GPIO_16_BITS_OFFSET (16U)
#define GPIO_32_BITS_OFFSET (32U)

/* Access the correct register */
#define GPIO_SET_BIT(base, reg, index, bit) ((base->reg[index]) |= SET_MASK(bit))
#define GPIO_CLEAR_BIT(base, reg, index, bit) ((base->reg[index]) &= CLEAR_MASK(bit))

#define GPIO_FLAG_INIT (1UL << 0)

/* GPIO runtime context information */
typedef struct {
	sedi_gpio_event_cb_t cb_event;
	void *callback_param;
	uint8_t flag;
	uint32_t outpin_state[SEDI_GPIO_SOC_PORT_NUM];
} gpio_context_t;

/* resource data structure */
typedef struct {
	sedi_gpio_regs_t *reg;
} gpio_resources_t;

typedef enum {
	SEDI_GPIO_32BITS_ACCESS,
	SEDI_GPIO_16BITS_ACCESS,
	SEDI_GPIO_8BITS_ACCESS
} gpio_port_access_t;

static const uint32_t gpio_port_access_mask[] = { 0xFFFFFFFFU, 0xFFFFU, 0xFFU };

/* driver version */
static const sedi_driver_version_t driver_version = { SEDI_GPIO_API_VERSION,
						      SEDI_GPIO_DRIVER_VERSION };

/* driver capabilities */
static sedi_gpio_capabilities_t driver_capabilities[SEDI_GPIO_NUM] = {
	{.support_pins_map = 0x3FFFFFFF},
};

/* gpio instance to source mapping*/
static gpio_resources_t resources_map[SEDI_GPIO_NUM] = {
	{ .reg = (sedi_gpio_regs_t *)SEDI_IREG_BASE(GPIO, 0) },
};

/* gpio context array */
static gpio_context_t gpio_context[SEDI_GPIO_NUM] = { 0 };

static int32_t gpio_set_power(IN sedi_gpio_t gpio_device, IN sedi_power_state_t state)
{
	sedi_devid_t devid = SEDI_DEVID_GPIO0 + gpio_device;
	int32_t ret = SEDI_DRIVER_OK;

	DBG_CHECK(gpio_device < SEDI_GPIO_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	switch (state) {
	case SEDI_POWER_FULL:
		sedi_pm_set_device_power(devid, SEDI_POWER_FULL);
		break;
	case SEDI_POWER_LOW:
	case SEDI_POWER_SUSPEND:
	case SEDI_POWER_FORCE_SUSPEND:
		/* Do nothing now, need to use gpio as wake up */
		break;
	case SEDI_POWER_OFF:
	default:
		ret = SEDI_DRIVER_ERROR_UNSUPPORTED;
		break;
	}

	return ret;
}

static void gpio_reset_register(IN sedi_gpio_t gpio_device)
{
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;
	uint8_t i;

	for (i = 0; i < SEDI_GPIO_SOC_PORT_NUM; i++) {
		reg->gpdr[i] = 0;
		reg->grer[i] = 0;
		reg->gfer[i] = 0;
		reg->gfbr[i] = 0;
		reg->gimr[i] = 0;
		/* Clear all status bits */
		reg->gisr[i] = 0xFFFFFFFF;
		reg->gwmr[i] = 0;
		/* Clear all status bits */
		reg->gwsr[i] = 0xFFFFFFFF;
	}
}

static void gpio_write_pin_port(IN sedi_gpio_t gpio_device, IN gpio_port_access_t access_type,
				IN uint8_t group, IN sedi_gpio_pin_state_t state)
{
	uint8_t port = (group >> access_type);
	uint8_t offset_unit, offset;
	uint32_t pin_bit;
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;
	gpio_context_t *context = &(gpio_context[gpio_device]);

	if (access_type == SEDI_GPIO_8BITS_ACCESS) {
		offset_unit = GPIO_8_BITS_OFFSET;
	} else if (access_type == SEDI_GPIO_16BITS_ACCESS) {
		offset_unit = GPIO_16_BITS_OFFSET;
	} else {
		offset_unit = GPIO_32_BITS_OFFSET;
	}

	offset = (group & (uint32_t)((1U << access_type) - 1U)) * offset_unit;
	pin_bit = (gpio_port_access_mask[access_type] << offset);

	if (state == SEDI_GPIO_STATE_HIGH) {
		reg->gpsr[port] = pin_bit;
		context->outpin_state[port] |= pin_bit;
	} else {
		reg->gpcr[port] = pin_bit;
		context->outpin_state[port] &= (~pin_bit);
	}
}

static uint32_t gpio_read_pin_port(IN sedi_gpio_t gpio_device, IN gpio_port_access_t access_type,
				   IN uint8_t group)
{
	uint8_t port = (group >> access_type);
	uint8_t offset_unit, offset;
	uint32_t pin_bit;
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;
	sedi_gpio_capabilities_t cap;

	/* The port return value will mask the pin maps */
	sedi_gpio_get_capabilities(gpio_device, &cap);
	if (access_type == SEDI_GPIO_8BITS_ACCESS) {
		offset_unit = GPIO_8_BITS_OFFSET;
	} else if (access_type == SEDI_GPIO_16BITS_ACCESS) {
		offset_unit = GPIO_16_BITS_OFFSET;
	} else {
		offset_unit = GPIO_32_BITS_OFFSET;
	}

	offset = (group & (uint32_t)((1U << access_type) - 1U)) * offset_unit;
	pin_bit = (gpio_port_access_mask[access_type] << offset);

	return (((reg->gplr[port] & pin_bit) >> offset) & cap.support_pins_map);
}

void gpio_isr(IN sedi_gpio_t gpio_device)
{
	sedi_gpio_regs_t *gpio = resources_map[gpio_device].reg;
	gpio_context_t *context = &(gpio_context[gpio_device]);
	uint8_t i;
	uint32_t gisr;
	uint32_t gimr;

	for (i = 0; i < SEDI_GPIO_SOC_PORT_NUM; i++) {
		gisr = gpio->gisr[i];
		gimr = gpio->gimr[i];

		gisr &= gimr;

		/* Clear the interrupts */
		gpio->gisr[i] = gisr;

		if ((context->cb_event) && (gisr != 0)) {
			(context->cb_event)(gisr, i, context->callback_param);
		}
	}
}

sedi_driver_version_t sedi_gpio_get_version(void)
{
	return driver_version;
}

int32_t sedi_gpio_get_capabilities(IN sedi_gpio_t gpio_device, OUT sedi_gpio_capabilities_t *cap)
{
	DBG_CHECK(gpio_device < SEDI_GPIO_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	if (sedi_dev_is_self_owned(SEDI_DEVID_GPIO0 + gpio_device)) {
		driver_capabilities[gpio_device].is_available = 1;
	} else {
		driver_capabilities[gpio_device].is_available = 0;
	}

	*cap = driver_capabilities[gpio_device];

	return SEDI_DRIVER_OK;
}

int32_t sedi_gpio_init(IN sedi_gpio_t gpio_device, IN sedi_gpio_event_cb_t cb, INOUT void *param)
{
	DBG_CHECK(gpio_device < SEDI_GPIO_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	if (!sedi_dev_is_self_owned(SEDI_DEVID_GPIO0 + gpio_device)) {
		return SEDI_DRIVER_ERROR_NO_DEV;
	}

	if (gpio_context[gpio_device].flag == GPIO_FLAG_INIT)
		return SEDI_DRIVER_ERROR_BUSY;

	/* Set all registers to default state */
	gpio_reset_register(gpio_device);

	/* Register callback for GPIO */
	gpio_context[gpio_device].cb_event = cb;
	gpio_context[gpio_device].callback_param = param;

	/* Set flag to init */
	gpio_context[gpio_device].flag = GPIO_FLAG_INIT;

	return SEDI_DRIVER_OK;
}

int32_t sedi_gpio_uninit(IN sedi_gpio_t gpio_device)
{
	DBG_CHECK(gpio_device < SEDI_GPIO_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	gpio_context_t *context = &(gpio_context[gpio_device]);
	uint8_t i;

	/* Clear the internal context */
	context->cb_event = NULL;
	context->callback_param = NULL;
	context->flag = 0;
	for (i = 0; i < SEDI_GPIO_SOC_PORT_NUM; i++) {
		context->outpin_state[i] = 0;
	}

	/* Set all registers to default state */
	gpio_reset_register(gpio_device);

	return SEDI_DRIVER_OK;
}

int32_t sedi_gpio_set_power(IN sedi_gpio_t gpio_device, IN sedi_power_state_t state)
{
	DBG_CHECK(gpio_device < SEDI_GPIO_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	return gpio_set_power(gpio_device, state);
}

void sedi_gpio_config_pin(IN sedi_gpio_t gpio_device, IN uint32_t pin,
			  IN sedi_gpio_pin_config_t pin_config)
{
	sedi_gpio_regs_t *base = resources_map[gpio_device].reg;
	uint8_t port = pin >> GPIO_PORT_SHIFT_BITS;
	uint8_t offset = pin & GPIO_PORT_MASK;

	if (pin_config.direction == SEDI_GPIO_DIR_MODE_OUTPUT) {
		GPIO_SET_BIT(base, gpdr, port, offset);
	} else {
		GPIO_CLEAR_BIT(base, gpdr, port, offset);

		/* Clear the interrupt mode first */
		GPIO_CLEAR_BIT(base, gfer, port, offset);
		GPIO_CLEAR_BIT(base, grer, port, offset);

		if (pin_config.interrupt_mode & SEDI_GPIO_INT_MODE_FALLING_EDGE) {
			GPIO_SET_BIT(base, gfer, port, offset);
		}

		if (pin_config.interrupt_mode & SEDI_GPIO_INT_MODE_RISING_EDGE) {
			GPIO_SET_BIT(base, grer, port, offset);
		}

		if (pin_config.enable_interrupt) {
			GPIO_SET_BIT(base, gimr, port, offset);
		} else {
			GPIO_CLEAR_BIT(base, gimr, port, offset);
		}

		if (pin_config.enable_wakeup) {
			GPIO_SET_BIT(base, gwmr, port, offset);
		} else {
			GPIO_CLEAR_BIT(base, gwmr, port, offset);
		}
	}
}

void sedi_gpio_write_pin(IN sedi_gpio_t gpio_device, IN uint32_t pin,
			 IN sedi_gpio_pin_state_t pin_state)
{
	uint8_t port = pin >> GPIO_PORT_SHIFT_BITS;
	uint8_t offset = pin & GPIO_PORT_MASK;
	uint32_t pin_bit = SET_MASK(offset);
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;
	gpio_context_t *context = &(gpio_context[gpio_device]);

	if (pin_state == SEDI_GPIO_STATE_HIGH) {
		reg->gpsr[port] = pin_bit;
		context->outpin_state[port] |= pin_bit;
	} else {
		reg->gpcr[port] = pin_bit;
		context->outpin_state[port] &= (~pin_bit);
	}
}

void sedi_gpio_write_pin_8bits(IN sedi_gpio_t gpio_device, IN uint8_t group,
			       IN sedi_gpio_pin_state_t pin_state)
{
	gpio_write_pin_port(gpio_device, SEDI_GPIO_8BITS_ACCESS, group, pin_state);
}

void sedi_gpio_write_pin_16bits(IN sedi_gpio_t gpio_device, IN uint8_t group,
				IN sedi_gpio_pin_state_t pin_state)
{
	gpio_write_pin_port(gpio_device, SEDI_GPIO_16BITS_ACCESS, group, pin_state);
}

void sedi_gpio_write_pin_32bits(IN sedi_gpio_t gpio_device, IN uint8_t group,
				IN sedi_gpio_pin_state_t pin_state)
{
	gpio_write_pin_port(gpio_device, SEDI_GPIO_32BITS_ACCESS, group, pin_state);
}

sedi_gpio_pin_state_t sedi_gpio_read_pin(IN sedi_gpio_t gpio_device, IN uint32_t pin)
{
	uint8_t port = pin >> GPIO_PORT_SHIFT_BITS;
	uint8_t offset = pin & GPIO_PORT_MASK;
	uint32_t pin_bit = SET_MASK(offset);
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;

	uint32_t pin_val = ((pin_bit & reg->gplr[port]) == pin_bit);

	return pin_val ? SEDI_GPIO_STATE_HIGH : SEDI_GPIO_STATE_LOW;
}

uint8_t sedi_gpio_read_pin_8bits(IN sedi_gpio_t gpio_device, IN uint8_t group)
{
	return gpio_read_pin_port(gpio_device, SEDI_GPIO_8BITS_ACCESS, group);
}

uint16_t sedi_gpio_read_pin_16bits(IN sedi_gpio_t gpio_device, IN uint8_t group)
{
	return gpio_read_pin_port(gpio_device, SEDI_GPIO_16BITS_ACCESS, group);
}

uint32_t sedi_gpio_read_pin_32bits(IN sedi_gpio_t gpio_device, IN uint8_t group)
{
	return gpio_read_pin_port(gpio_device, SEDI_GPIO_32BITS_ACCESS, group);
}

void sedi_gpio_toggle_pin(IN sedi_gpio_t gpio_device, IN uint32_t pin)
{
	uint8_t port = pin >> GPIO_PORT_SHIFT_BITS;
	uint8_t offset = pin & GPIO_PORT_MASK;
	uint32_t pin_bit = SET_MASK(offset);
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;
	gpio_context_t *context = &(gpio_context[gpio_device]);

	if (context->outpin_state[port] & pin_bit) {
		reg->gpcr[port] = pin_bit;
		context->outpin_state[port] &= ~pin_bit;
	} else {
		reg->gpsr[port] = pin_bit;
		context->outpin_state[port] |= pin_bit;
	}
}

uint32_t sedi_gpio_get_gisr(IN sedi_gpio_t gpio_device, IN sedi_gpio_port_t port)
{
	SEDI_ASSERT(gpio_device < SEDI_GPIO_NUM);
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;

	return reg->gisr[port];
}

uint32_t sedi_gpio_get_gwsr(IN sedi_gpio_t gpio_device, IN sedi_gpio_port_t port)
{
	SEDI_ASSERT(gpio_device < SEDI_GPIO_NUM);
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;

	return reg->gwsr[port];
}

void sedi_gpio_clear_gisr(IN sedi_gpio_t gpio_device, IN sedi_gpio_port_t port, IN uint32_t val)
{
	SEDI_ASSERT(gpio_device < SEDI_GPIO_NUM);
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;

	/* The register is w1c */
	reg->gisr[port] = val;
}

void sedi_gpio_clear_gwsr(IN sedi_gpio_t gpio_device, IN sedi_gpio_port_t port, IN uint32_t val)
{
	SEDI_ASSERT(gpio_device < SEDI_GPIO_NUM);
	sedi_gpio_regs_t *reg = resources_map[gpio_device].reg;

	/* The register is w1c */
	reg->gwsr[port] = val;
}

void sedi_gpio_enable_interrupt(IN sedi_gpio_t gpio_device, IN uint32_t pin, bool enable)
{
	SEDI_ASSERT(gpio_device < SEDI_GPIO_NUM);
	sedi_gpio_regs_t *base = resources_map[gpio_device].reg;
	uint8_t port = pin >> GPIO_PORT_SHIFT_BITS;
	uint8_t offset = pin & GPIO_PORT_MASK;

	if (enable) {
		GPIO_SET_BIT(base, gimr, port, offset);
	} else {
		GPIO_CLEAR_BIT(base, gimr, port, offset);
	}
}

void sedi_gpio_enable_wakeup(IN sedi_gpio_t gpio_device, IN uint32_t pin, bool enable)
{
	SEDI_ASSERT(gpio_device < SEDI_GPIO_NUM);
	sedi_gpio_regs_t *base = resources_map[gpio_device].reg;
	uint8_t port = pin >> GPIO_PORT_SHIFT_BITS;
	uint8_t offset = pin & GPIO_PORT_MASK;

	if (enable) {
		GPIO_SET_BIT(base, gwmr, port, offset);
	} else {
		GPIO_CLEAR_BIT(base, gwmr, port, offset);
	}
}
