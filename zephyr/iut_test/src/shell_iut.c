/*
 * Copyright (c) 2023 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>
#include "iut.h"
#include <zephyr/shell/shell_uart.h>

extern int iut_trigger(size_t argc, char **argv);

static int cmd_iut_list(const struct shell *shell,
			      size_t argc, char **argv)
{
	const struct iut_case *ut = (void *)__iut_cases_start;

	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	shell_fprintf(shell, SHELL_NORMAL, "IUT test cases:\n");
	while ((char *)ut < __iut_cases_end) {
		shell_fprintf(shell, SHELL_NORMAL, "\t- %s, %s, 0x%x\n",
				ut->group, ut->name, ut->attri);
		ut++;
	};

	return 0;
}

static int cmd_iut_run(const struct shell *shell,
			      size_t argc, char **argv)
{
	if (argc < 2)
		return -EPERM;

	return iut_trigger(argc, argv);
}

static int cmd_iut_grun(const struct shell *shell,
			      size_t argc, char **argv)
{
	if (argc < 2)
		return -EPERM;

	return iut_trigger(argc, argv);
}

SHELL_STATIC_SUBCMD_SET_CREATE(sub_iut,
	SHELL_CMD(list, NULL, "List unit cases", cmd_iut_list),
	SHELL_CMD(run, NULL, "run one unit case", cmd_iut_run),
	SHELL_CMD(grun, NULL, "run one group of unit cases", cmd_iut_grun),
	SHELL_SUBCMD_SET_END /* Array terminated. */
);

SHELL_CMD_REGISTER(iut, &sub_iut, "IUT commands", NULL);

#ifdef _CONFIG_PM
static const struct shell_uart *sh_uart;

void iut_shell_suspend(void)
{
	if (!sh_uart) {
		/*get current uart shell pointer*/
		const struct shell *shell_ptr = shell_backend_uart_get_ptr();

		if (shell_ptr == NULL) {
			iut_print("get shell pointer error!!!\n");
			return;
		}

		/*get shell uart backend*/
		sh_uart = (const struct shell_uart *)shell_ptr->iface->ctx;

		if (sh_uart == NULL) {
			iut_print("get shell UART pointer error!!!\n");
			return;
		}
	}

	k_timer_stop(sh_uart->timer);
}

void iut_shell_resume(void)
{
	if (sh_uart) {
		k_timer_start(sh_uart->timer, K_NO_WAIT,
			K_MSEC(CONFIG_SHELL_BACKEND_SERIAL_RX_POLL_PERIOD));
	}
}
#endif
