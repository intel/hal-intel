/*
 * Copyright (c) 2025 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* {sum, count, max, min, unit string} */
#define DEFINE_DSTATS(_name, _unit_str)                                                            \
	uint64_t __dstats_sum_##_name;                                                             \
	uint32_t __dstats_cnt_##_name;                                                             \
	uint32_t __dstats_max_##_name = (uint32_t)0;                                               \
	uint32_t __dstats_min_##_name = (uint32_t)0;                                               \
	const char *const __dstats_unit_str_##_name = _unit_str

#define DECLARE_DSTATS(_name)                                                                      \
	extern uint64_t __dstats_sum_##_name;                                                      \
	extern uint32_t __dstats_cnt_##_name;                                                      \
	extern uint32_t __dstats_max_##_name;                                                      \
	extern uint32_t __dstats_min_##_name;                                                      \
	extern const char *const __dstats_unit_str_##_name

#define DSTATS_SUM(_name)      __dstats_sum_##_name
#define DSTATS_CNT(_name)      __dstats_cnt_##_name
#define DSTATS_MAX(_name)      __dstats_max_##_name
#define DSTATS_MIN(_name)      __dstats_min_##_name
#define DSTATS_UNIT_STR(_name) __dstats_unit_str_##_name

#define dstats_reset(_name)                                                                        \
	do {                                                                                       \
		__dstats_sum_##_name = 0;                                                          \
		__dstats_cnt_##_name = 0;                                                          \
		__dstats_max_##_name = 0;                                                          \
		__dstats_min_##_name = 0;                                                          \
	} while (0)

#define dstats_update(_name, _value)                                                               \
	do {                                                                                       \
		__dstats_sum_##_name += _value;                                                    \
		__dstats_cnt_##_name++;                                                            \
		if ((_value) > __dstats_max_##_name) {                                             \
			__dstats_max_##_name = (_value);                                           \
		}                                                                                  \
		if (!__dstats_min_##_name || _value < __dstats_min_##_name) {                      \
			__dstats_min_##_name = (_value);                                           \
		}                                                                                  \
		if (__dstats_cnt_##_name >= (uint32_t)-1) {                                        \
			/* About to wrap around, clear sum and cnt and insert one average */       \
			__dstats_sum_##_name =                                                     \
				(uint32_t)(__dstats_sum_##_name / __dstats_cnt_##_name);           \
			__dstats_cnt_##_name = 1;                                                  \
		}                                                                                  \
	} while (0)

#define dstats_get_avrg(_name)                                                                     \
	((__dstats_cnt_##_name == 0) ? 0 : (uint32_t)(__dstats_sum_##_name / __dstats_cnt_##_name))

/* dump out as (sum, mean, max, min) */
#define dstats_dump(_name, _log_func)                                                              \
	do {                                                                                       \
		if (__dstats_cnt_##_name == 0) {                                                   \
			break;                                                                     \
		}                                                                                  \
		_log_func("DSTATS " #_name "(cnt, (aveg, max, min)): "                             \
			  "(%u, (%u, %u, %u)%s)\n",                                                \
			  __dstats_cnt_##_name,                                                    \
			  (uint32_t)(__dstats_sum_##_name / __dstats_cnt_##_name),                 \
			  __dstats_max_##_name, __dstats_min_##_name, __dstats_unit_str_##_name);  \
	} while (0)

#define DEFINE_DSEQ(_name, _cells_num, _unit_str)                                                  \
	uint32_t __dseq_cells_##_name[_cells_num] = {0};                                           \
	const uint32_t __dseq_cells_num_##_name = (_cells_num);                                    \
	uint32_t __dseq_num_##_name = 0;                                                           \
	const char *const __dseq_unit_str_##_name = _unit_str;                                     \
	uint32_t __dseq_head_##_name = 0

#define DECLARE_DSEQ(_name)                                                                        \
	extern uint32_t __dseq_cells_##_name[];                                                    \
	extern const uint32_t __dseq_cells_num_##_name;                                            \
	extern uint32_t __dseq_num_##_name;                                                        \
	extern const char *const __dseq_unit_str_##_name;                                          \
	extern uint32_t __dseq_head_##_name

#define dseq_reset(_name)                                                                          \
	do {                                                                                       \
		for (uint32_t i = 0; i < __dseq_cells_num_##_name; i++) {                          \
			__dseq_cells_##_name[i] = 0;                                               \
		}                                                                                  \
		__dseq_num_##_name = 0;                                                            \
		__dseq_head_##_name = 0;                                                           \
	} while (0)

#define dseq_update(_name, _value)                                                                 \
	do {                                                                                       \
		uint32_t next = __dseq_head_##_name + __dseq_num_##_name;                          \
		next = next % __dseq_cells_num_##_name;                                            \
		__dseq_cells_##_name[next] = (_value);                                             \
		__dseq_num_##_name++;                                                              \
		if (__dseq_num_##_name > __dseq_cells_num_##_name) {                               \
			__dseq_num_##_name = __dseq_cells_num_##_name;                             \
			__dseq_head_##_name = (next + 1) % __dseq_cells_num_##_name;               \
		}                                                                                  \
	} while (0)

#define dseq_dump(_name, _log_func)                                                                \
	do {                                                                                       \
		for (uint32_t i = 0; i < __dseq_num_##_name; i++) {                                \
			uint32_t idx = __dseq_head_##_name + i;                                    \
			idx = idx % __dseq_cells_num_##_name;                                      \
			_log_func("DSEQ " #_name " (%u/%u): 0x%x %s\n", i, __dseq_num_##_name,     \
				  __dseq_cells_##_name[idx], __dseq_unit_str_##_name);             \
		}                                                                                  \
	} while (0)
