/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SEDI_REG_DEFS_H_
#define _SEDI_REG_DEFS_H_

#define __SEDI_CONST_RO const
#define __SEDI_CONST_WO
#define __SEDI_CONST_RW
#define __SEDI_CONST_RO_V const
#define __SEDI_CONST_RW_V
#define __SEDI_CONST_RW_L
#define __SEDI_CONST_RW_1C
#define __SEDI_CONST_RW_1C_V
#define __SEDI_CONST_RW_1S_V
#define __SEDI_CONST_RSV const

#define __SEDI_UNUSED __attribute__((unused))

/* *************************************************
 * Macros for constants defined for a SEDI register.
 */

/*
 * The constant for the register base address of instance <N> of a SEDI component IP
 */
#define SEDI_IREG_BASE(_comp, _instance) SEDI_##_comp##_##_instance##_REG_BASE

/*
 * The constant for the register base address of the only instance of a SEDI component IP
 */
#define SEDI_REG_BASE(_comp) SEDI_##_comp##_REG_BASE

/*
 * REGO: The constant for a REGister address Offset.
 */
#define SEDI_REGO(_comp, _reg) SEDI_REGO_##_comp##_##_reg

/*
 * REGR: The constant for a REGister Reset value.
 */
#define SEDI_REGR(_comp, _reg) SEDI_REGR_##_comp##_##_reg

/*
 * REGT: The REGister Type.
 *   uint32_t or uint64_t (BitWidth)
 *   const (RO) or un-const (RW or WO)
 */
#define SEDI_REGT(_comp, _reg) __typeof__(SEDI_REGR(_comp, _reg))

/*
 * REGBM: The REGister Bit Mask of a specific bit with offset _bit_off.
 */
#define _SEDI_REGBM(_comp, _reg, _bit_off) ((SEDI_REGT(_comp, _reg))0x1 << (_bit_off))

/* ***********************************************************
 * Macros for constants defined for a SEDI register Bit Field.
 */

/*
 * RBFO: The constant for the Bit Offset of a Register Bit Field.
 */
#define SEDI_RBFO(_comp, _reg, _bf) SEDI_RBFO_##_comp##_##_reg##_##_bf

/*
 * RBFW: The constant for the Bit Width of a Register Bit Field.
 */
#define SEDI_RBFW(_comp, _reg, _bf) SEDI_RBFW_##_comp##_##_reg##_##_bf

/*
 * RBFM: The constant for the Bit Mask of a Register Bit Field.
 */
#define SEDI_RBFM(_comp, _reg, _bf) SEDI_RBFM_##_comp##_##_reg##_##_bf

/*
 * RBFR: The constant for the Reset value of a Register Bit Field.
 */
#define SEDI_RBFR(_comp, _reg, _bf) SEDI_RBFR_##_comp##_##_reg##_##_bf

/*
 * RBFV: The constant for a Register Bit Field Value with name _value_name.
 */
#define SEDI_RBFV(_comp, _reg, _bf, _value_name) SEDI_RBFV_##_comp##_##_reg##_##_bf##_##_value_name

/*
 * RBFVM: The Bit Mask of a Register Bit Field Value with name _value_name.
 */
#define SEDI_RBFVM(_comp, _reg, _bf, _value_name)                                                  \
	(SEDI_RBFV(_comp, _reg, _bf, _value_name) << SEDI_RBFO(_comp, _reg, _bf))

/*
 * RBFM_VALUE: The Bit Mask of a Register Bit Field with value _value.
 */
#define SEDI_RBFM_VALUE(_comp, _reg, _bf, _value)                                                  \
	(((SEDI_REGT(_comp, _reg))(_value) << SEDI_RBFO(_comp, _reg, _bf)) &                       \
	 SEDI_RBFM(_comp, _reg, _bf))

/*
 * RBFT: The Rister Bit Field Type.
 *   uint32_t or uint64_t (BitWidth)
 *   const (RO) or un-const (RW or WO)
 */
#define SEDI_RBFT(_comp, _reg, _bf) __typeof__(SEDI_RBFR(_comp, _reg, _bf))

/* **********************************************
 * Macros to define constants for a SEDI register.
 */

#define SEDI_REG_BASE_DEFINE(_comp, _base_addr)                                                    \
	static const uint32_t SEDI_REG_BASE(_comp) = (_base_addr)

#define SEDI_IREG_BASE_DEFINE(_comp, _instance, _base_addr)                                        \
	static const uint32_t SEDI_IREG_BASE(_comp, _instance) = (_base_addr)

/*
 * Define constants for a SEDI register.
 * - REGO (REGister address Offset): address offset from the IP base address.
 * - REGR (REGister Reset value)   : reset value after reset. It's const if the register is RO.
 */
#define SEDI_REG_DEFINE(_comp, _reg, _offset, _access, _writable_bitmask, _reset_val)              \
	static const uint32_t SEDI_REGO(_comp, _reg) = (_offset);                                  \
	static __SEDI_CONST_##_access __typeof__(_reset_val)                                       \
		__SEDI_UNUSED SEDI_REGR(_comp, _reg) = (_reset_val)

/*
 * Define constants for a Register Bit Field (RBF)
 * - RBFO (Register Bit Field Offset): bit offset of the RBF.
 * - RBFW (Register Bit Field Width) : bit width of the RBF.
 * - RBFM (Register Bit Field Mask)  : bit mask of the RBF.
 */
#define SEDI_RBF_DEFINE(_comp, _reg, _bf, _offset, _width, _access, _reset_val)                    \
	static const uint32_t SEDI_RBFO(_comp, _reg, _bf) = (_offset);                             \
	static const uint32_t SEDI_RBFW(_comp, _reg, _bf) = (_width);                              \
	static const SEDI_REGT(_comp, _reg) SEDI_RBFM(_comp, _reg, _bf) =                          \
		(((_offset) + (_width)) >= sizeof(SEDI_REGT(_comp, _reg)) * 8) ?                   \
			((SEDI_REGT(_comp, _reg))(-1) &                                            \
			 ~(_SEDI_REGBM(_comp, _reg, _offset) - 1)) :                               \
			((_SEDI_REGBM(_comp, _reg, _width) - 1) << (_offset));                     \
	static __SEDI_CONST_##_access __typeof__(_reset_val)                                       \
		__SEDI_UNUSED SEDI_RBFR(_comp, _reg, _bf) = (_reset_val)

/*
 * Define a Register Bit Field Value (RBFV) with name _value_name
 */
#define SEDI_RBFV_DEFINE(_comp, _reg, _bf, _value_name, _value)                                    \
	static const SEDI_REGT(_comp, _reg) SEDI_RBFV_##_comp##_##_reg##_##_bf##_##_value_name =   \
		(SEDI_REGT(_comp, _reg))(_value)

/* ***************************************************************
 * Macro operations of a register.
 *   PREG: a register with pointer.
 *   IREG: a register of instance <N> of a SEDI component IP.
 *   REG : a register of the only instance of a SEDI component IP.
 */

/*
 * The pointer of a SEDI register with/without const qualifier
 */

#define SEDI_IREG_PTR(_comp, _instance, _reg)                                                      \
	(volatile(SEDI_REGT(_comp, _reg) *)(SEDI_IREG_BASE(_comp, _instance) +                     \
					    SEDI_REGO(_comp, _reg)))

#define SEDI_REG_PTR(_comp, _reg)                                                                  \
	((volatile SEDI_REGT(_comp, _reg) *)(SEDI_REG_BASE(_comp) + SEDI_REGO(_comp, _reg)))

/*
 * Get the register value
 */

#define SEDI_PREG_GET(_comp, _reg, _reg_addr)                                                      \
	({                                                                                         \
		volatile SEDI_REGT(_comp, _reg) * _addr = (_reg_addr);                             \
		*_addr;                                                                            \
	})

#define SEDI_IREG_GET(_comp, _instance, _reg)                                                      \
	SEDI_PREG_GET(_comp, _reg, SEDI_IREG_PTR(_comp, _instance, _reg))

#define SEDI_REG_GET(_comp, _reg) SEDI_PREG_GET(_comp, _reg, SEDI_REG_PTR(_comp, _reg))

/*
 * Set a value into a register.
 */
#define SEDI_PREG_SET(_comp, _reg, _value, _reg_addr)                                              \
	({                                                                                         \
		volatile SEDI_REGT(_comp, _reg) * _addr = (_reg_addr);                             \
		*_addr = _value;                                                                   \
	})

#define SEDI_IREG_SET(_comp, _instance, _reg, _value)                                              \
	SEDI_PREG_SET(_comp, _reg, _value, SEDI_IREG_PTR(_comp, _instance, _reg))

#define SEDI_REG_SET(_comp, _reg, _value)                                                          \
	SEDI_PREG_SET(_comp, _reg, _value, SEDI_REG_PTR(_comp, _reg))

/*
 * Check if a register has a specific RBFV with name _value_name set.
 */
#define SEDI_PREG_RBFV_IS_SET(_comp, _reg, _bf, _value_name, _reg_addr)                            \
	((SEDI_PREG_GET(_comp, _reg, _reg_addr) & SEDI_RBFM(_comp, _reg, _bf)) ==                  \
	 SEDI_RBFVM(_comp, _reg, _bf, _value_name))

#define SEDI_IREG_RBFV_IS_SET(_comp, _instance, _reg, _bf, _value_name)                            \
	SEDI_PREG_RBFV_IS_SET(_comp, _reg, _bf, _value_name, SEDI_IREG_PTR(_comp, _instance, _reg))

#define SEDI_REG_RBFV_IS_SET(_comp, _reg, _bf, _value_name)                                        \
	SEDI_PREG_RBFV_IS_SET(_comp, _reg, _bf, _value_name, SEDI_REG_PTR(_comp, _reg))

/*
 * Get the value of a Register Bit Field from a register.
 */
#define SEDI_PREG_RBFV_GET(_comp, _reg, _bf, _reg_addr)                                            \
	((SEDI_PREG_GET(_comp, _reg, _reg_addr) & SEDI_RBFM(_comp, _reg, _bf)) >>                  \
	 SEDI_RBFO(_comp, _reg, _bf))

#define SEDI_IREG_RBFV_GET(_comp, _instance, _reg, _bf)                                            \
	SEDI_PREG_RBFV_GET(_comp, _reg, _bf, SEDI_IREG_PTR(_comp, _instance, _reg))

#define SEDI_REG_RBFV_GET(_comp, _reg, _bf)                                                        \
	SEDI_PREG_RBFV_GET(_comp, _reg, _bf, SEDI_REG_PTR(_comp, _reg))

/*
 * Set a RBFV with name _value_name into a register.
 */
#define SEDI_PREG_RBFV_SET(_comp, _reg, _bf, _value_name, _reg_addr)                               \
	*(volatile SEDI_RBFT(_comp, _reg, _bf) *)(_reg_addr) =                                     \
		((SEDI_PREG_GET(_comp, _reg, _reg_addr) & ~SEDI_RBFM(_comp, _reg, _bf)) |          \
		 SEDI_RBFVM(_comp, _reg, _bf, _value_name))

#define SEDI_IREG_RBFV_SET(_comp, _instance, _reg, _bf, _value_name)                               \
	SEDI_PREG_RBFV_SET(_comp, _reg, _bf, _value_name, SEDI_IREG_PTR(_comp, _instance, _reg))

#define SEDI_REG_RBFV_SET(_comp, _reg, _bf, _value_name)                                           \
	SEDI_PREG_RBFV_SET(_comp, _reg, _bf, _value_name, SEDI_REG_PTR(_comp, _reg))

/*
 * Set a specific value into a Register Bit Field.
 */
#define SEDI_PREG_RBF_SET(_comp, _reg, _bf, _value, _reg_addr)                                     \
	*(volatile SEDI_RBFT(_comp, _reg, _bf) *)(_reg_addr) =                                     \
		((SEDI_PREG_GET(_comp, _reg, _reg_addr) & ~SEDI_RBFM(_comp, _reg, _bf)) |          \
		 SEDI_RBFM_VALUE(_comp, _reg, _bf, _value))

#define SEDI_IREG_RBF_SET(_comp, _instance, _reg, _bf, _value)                                     \
	SEDI_PREG_RBF_SET(_comp, _reg, _bf, _value, SEDI_IREG_PTR(_comp, _instance, _reg))

#define SEDI_REG_RBF_SET(_comp, _reg, _bf, _value)                                                 \
	SEDI_PREG_RBF_SET(_comp, _reg, _bf, _value, SEDI_REG_PTR(_comp, _reg))

#endif
