/*
 * Copyright (c) 2023 - 2024 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_DRIVER_COMMON_H_
#define _SEDI_DRIVER_COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#include "sedi_soc_regs.h"
#include "sedi_soc.h"

/*!
 * \defgroup sedi_driver_common Common
 * \ingroup sedi_driver
 */

#ifndef NULL
#define NULL ((void *)0)
#endif

/*!
 * \def BIT
 * \brief Generate a mask with bit x set.
 * \ingroup sedi_driver_common
 */

#ifndef BIT
#define BIT(x) (1U << (x))
#endif

/*!
 * \defgroup sedi_driver_common Common
 * \ingroup sedi_driver
 */

#ifndef TRUE
#define TRUE 1
#endif

/*!
 * \defgroup sedi_driver_common Common
 * \ingroup sedi_driver
 */

#ifndef FALSE
#define FALSE 0
#endif

/*!
 * \defgroup sedi_driver_common Common
 * \ingroup sedi_driver
 */

#ifndef MS_PER_SEC
#define MS_PER_SEC 1000
#endif

#ifndef NS_PER_US
#define NS_PER_US 1000
#endif

/*!
 * \def SEDI_DRIVER_VERSION_MAJOR_MINOR
 * \ingroup sedi_driver_common
 */
#define SEDI_DRIVER_VERSION_MAJOR_MINOR(major, minor) (((major) << 8) | (minor))

/*!
 * \struct sedi_driver_version_t
 * \brief Driver Version
 * \ingroup sedi_driver_common
 */
typedef struct {
	uint16_t api; /**< API version */
	uint16_t drv; /**< Driver version */
} sedi_driver_version_t;

/*!
 * \defgroup return_status  Return Status Codes
 * \ingroup sedi_driver_common
 * \{
 */

/*!
 * \def SEDI_DRIVER_OK
 * \brief Operation succeeded
 */
#define SEDI_DRIVER_OK 0

/*!
 * \def SEDI_DRIVER_ERROR
 * \brief Unspecified error
 */
#define SEDI_DRIVER_ERROR -1

/*!
 * \def SEDI_DRIVER_ERROR_BUSY
 * \brief Driver is busy
 */
#define SEDI_DRIVER_ERROR_BUSY -2

/*!
 * \def SEDI_DRIVER_ERROR_TIMEOUT
 * \brief Timeout occurred
 */
#define SEDI_DRIVER_ERROR_TIMEOUT -3

/*!
 * \def SEDI_DRIVER_ERROR_UNSUPPORTED
 * \brief Operation not supported
 */
#define SEDI_DRIVER_ERROR_UNSUPPORTED -4

/*!
 * \def SEDI_DRIVER_ERROR_PARAMETER
 * \brief Parameter error
 */
#define SEDI_DRIVER_ERROR_PARAMETER -5

/*!
 * \def SEDI_DRIVER_ERROR_TRANSFER
 * \brief transfer error
 */
#define SEDI_DRIVER_ERROR_TRANSFER -6

/*!
 * \def SEDI_DRIVER_ERROR_NO_DEV
 * \brief Device not available
 */
#define SEDI_DRIVER_ERROR_NO_DEV -7

/*!
 * \def SEDI_DRIVER_ERROR_SPECIFIC
 * \brief Start of driver specific errors
 */
#define SEDI_DRIVER_ERROR_SPECIFIC -8

/*!
 * \def SEDI_USART_ERROR_CANCELED
 * \brief Operation was canceled.
 */
#define SEDI_USART_ERROR_CANCELED (SEDI_DRIVER_ERROR_SPECIFIC - 1)

/*!
 * \def SEDI_PM_ERROR_NOMEM
 * \brief No empty entry for client configurations.
 */
#define SEDI_PM_ERROR_NOMEM (SEDI_DRIVER_ERROR_SPECIFIC - 2)

/*!
 * \def SEDI_PM_ERROR_INTR_PENDING
 * \brief Interrupt pending to block clock gating.
 */
#define SEDI_PM_ERROR_INTR_PENDING (SEDI_DRIVER_ERROR_SPECIFIC - 3)

/*!
 * \def SEDI_PM_ERROR_CG_ABORT
 * \brief Clock gating aborted
 */
#define SEDI_PM_ERROR_CG_PG_ABORT (SEDI_DRIVER_ERROR_SPECIFIC - 4)

/*!
 * \def PARAM_UNUSED
 * \brief Parameter Not Used.
 */
#define PARAM_UNUSED(x) (void)(x)

/*!
 * \enum sedi_log_level
 * \brief SEDI logging levels
 * \ingroup sedi_driver_common
 */
enum {
	SEDI_LOG_LEVEL_ERR = 1,
	SEDI_LOG_LEVEL_WRN = 2,
	SEDI_LOG_LEVEL_INF = 3,
	SEDI_LOG_LEVEL_DBG = 4,
};

/*!
 * \function sedi_log
 * \brief SEDI logging function
 * \ingroup sedi_driver_common
 */
void sedi_log(int level, const char *fmt, ...);

#define SEDI_LOG_ERR(...) sedi_log(SEDI_LOG_LEVEL_ERR, __VA_ARGS__)
#define SEDI_LOG_WRN(...) sedi_log(SEDI_LOG_LEVEL_WRN, __VA_ARGS__)
#define SEDI_LOG_INF(...) sedi_log(SEDI_LOG_LEVEL_INF, __VA_ARGS__)
#define SEDI_LOG_DBG(...) sedi_log(SEDI_LOG_LEVEL_DBG, __VA_ARGS__)

/*!
 * \def DBG_CHECK
 * \brief Check error and return for debug mode.
 */
#ifdef CONFIG_DEBUG
#define DBG_CHECK(condition, error)                                            \
	do {                                                                   \
		if (!(condition)) {                                            \
			SEDI_LOG_ERR("SEDI DBG_CHECK error %d @%s:%d:(%s)\n",  \
				error, __func__, __LINE__, #condition);    \
			return error;                                          \
		}                                                              \
	} while (0)
#else
#define DBG_CHECK(condition, error)
#endif

/*!
 * \def SEDI_ASSERT
 * \brief Assert function for debug mode.
 */
#ifdef CONFIG_DEBUG
void sedi_assert_halt(void);
#define SEDI_ASSERT(condition)                                                 \
	do {                                                                   \
		if (!(condition)) {                                            \
			SEDI_LOG_ERR("SEDI ASSERT @%s:%d:(%s)\n",              \
					__func__, __LINE__, #condition);   \
			sedi_assert_halt();                                    \
		}                                                              \
	} while (0)
#else
#define SEDI_ASSERT(condition)
#endif

/*!
 * \def SET_MASK
 * \brief Mask Value for Bit Set.
 */
#define SET_MASK(x) (1UL << (x))

/*!
 * \def SET_MASK
 * \brief Mask Value for Bit Clear.
 */
#define CLEAR_MASK(x) (~(1UL << (x)))

/*!
 * \def SEDI_ISR_DECLARE
 * \brief SEDI interrupt handler prototype
 */
#define SEDI_ISR_DECLARE(func) void func(void)

/*!
 * \def SET_BITS
 * \brief SEDI set certain bit with certain value
 */

#define SET_BITS(reg_name, start, width, value)                                \
	do {                                                                   \
		uint32_t tmp = 1 << (width);                                   \
		reg_name &= ~((tmp - 1) << (start));                           \
		reg_name |= ((value) << (start));                              \
	} while (0)

/*!
 * \def GET_BITS
 * \brief SEDI get value from certain bit
 */

#define GET_BITS(reg_name, start, width)                                       \
	((reg_name) & (((1<<(width)) - 1) << (start)))

/*!
 * \}
 */

/*!
 * \struct sedi_power_state_t
 * \brief General power states
 * \ingroup sedi_driver_common
 */
typedef enum {
	/**< Power off: no operation possible */
	SEDI_POWER_OFF,
	/**< Suspend: context should be saved and restored by driver */
	SEDI_POWER_SUSPEND,
	/**< Force suspend: complete ongoing operation before suspend */
	SEDI_POWER_FORCE_SUSPEND,
	/**< Low Power mode: retain state, detect and signal wake-up events */
	SEDI_POWER_LOW,
	/**< Power on: full operation at maximum performance */
	SEDI_POWER_FULL
} sedi_power_state_t;

#ifndef __IO_R
/*!
 * \def __IO_R
 * \brief 'read only' permissions
 * \ingroup sedi_driver_common
 */
#define __IO_R volatile const
#endif

#ifndef __IO_W
/*!
 * \def __IO_W
 * \brief 'write only' permissions
 * \ingroup sedi_driver_common
 */
#define __IO_W volatile
#endif

#ifndef __IO_RW
/*!
 * \def __IO_RW
 * \brief 'read / write' permissions
 * \ingroup sedi_driver_common
 */
#define __IO_RW volatile
#endif

#ifndef IN
/*!
 * \def IN
 * \brief Input parameter indicator
 * \ingroup sedi_driver_common
 */
#define IN const
#endif

#ifndef OUT
/*!
 * \def OUT
 * \brief Output parameter indicator
 * \ingroup sedi_driver_common
 */
#define OUT
#endif

#ifndef INOUT
/*!
 * \def  INOUT
 * \brief Input/Output parameter indicator
 * \ingroup sedi_driver_common
 */
#define INOUT
#endif

/*!
 * \function read/write address
 * \ingroup sedi_driver_common
 */
/* register read/write help function */
static inline uint8_t read8(IN uint32_t addr)
{
	return *(const volatile uint8_t *)addr;
}

static inline uint16_t read16(IN uint32_t addr)
{
	return *(const volatile uint16_t *)addr;
}

static inline uint32_t read32(IN uint32_t addr)
{
	return *(const volatile uint32_t *)addr;
}

/* Note - 64 bit function isn't atomic */
static inline uint64_t read64(IN uint32_t addr)
{
	return *(const volatile uint64_t *)addr;
}

static inline void write8(uint32_t addr, IN uint8_t val)
{
	*(volatile uint8_t *)addr = (uint8_t)val;
}

static inline void write16(uint32_t addr, IN uint16_t val)
{
	*(volatile uint16_t *)addr = (uint16_t)val;
}

static inline void write32(uint32_t addr, IN uint32_t val)
{
	*(volatile uint32_t *)addr = val;
}

/* Note - 64 bit function isn't atomic */
static inline void write64(uint32_t addr, IN uint64_t val)
{
	*(volatile uint64_t *)addr = val;
}

#define SET_REG_BIT(address, smask)                                           \
	write32(address, read32(address) | (smask))

#define CLEAR_REG_BIT(address, cmask)                                         \
	write32(address, read32(address) & ~(cmask))

uint64_t sedi_rtc_get_us(void);

#define __SEDI_POLL_WAIT(_cond, _ms, _mute)                                                        \
	({                                                                                         \
		int ret = SEDI_DRIVER_OK;                                                          \
		uint64_t us_start;                                                                 \
		us_start = sedi_rtc_get_us();                                                      \
		while (_cond) {                                                                    \
			uint64_t us_cur;                                                           \
			us_cur = sedi_rtc_get_us();                                                \
			if (((int64_t)(us_cur - us_start) > ((_ms) * 1000)) && (_cond)) {          \
				if (!(_mute)) {                                                    \
					SEDI_LOG_ERR("SEDI poll %d ms timeout at %s : %d\n", (_ms),\
						     __func__, __LINE__);                          \
				}                                                                  \
				ret = SEDI_DRIVER_ERROR_TIMEOUT;                                   \
				break;                                                             \
			}                                                                          \
		}                                                                                  \
		ret;                                                                               \
	})

/*!
 * \function SEDI_POLL_WAIT
 * \brief SEDI helper function to poll wait ((_cond) == true) at most (_ms) milliseconds.
 * \return SEDI_DRIVER_OK or SEDI_DRIVER_ERROR_TIMEOUT
 * \ingroup sedi_driver_common
 */
#define SEDI_POLL_WAIT(_cond, _ms) __SEDI_POLL_WAIT(_cond, _ms, false)

/*!
 * \function SEDI_POLL_WAIT_MUTE
 * \brief SEDI helper function to poll wait ((_cond) == true) at most (_ms) milliseconds, and don't
 *	print error log when timeout happens to avoid potential recursive logging.
 * \return SEDI_DRIVER_OK or SEDI_DRIVER_ERROR_TIMEOUT
 * \ingroup sedi_driver_common
 */
#define SEDI_POLL_WAIT_MUTE(_cond, _ms) __SEDI_POLL_WAIT(_cond, _ms, true)
#endif /* _SEDI_DRIVER_COMMON_H_*/
