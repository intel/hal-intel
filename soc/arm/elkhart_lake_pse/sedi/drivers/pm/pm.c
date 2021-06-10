/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "config.h"
#include "dashboard_reg.h"
#include "pm_internal_if.h"
#include "pm_regs.h"
#include "pm_share.h"
#include "sedi_soc.h"
#include <sedi.h>
#include <sedi_driver.h>
#include <string.h>

/* Disable debug print by default */
#undef __PM_DEBUG__

extern void printk(const char *fmt, ...);

#define PM_ERR(...) printk(__VA_ARGS__)

#ifdef __PM_DEBUG__
#define PM_LOG(...) printk(__VA_ARGS__)
#else
#define PM_LOG(...)
#endif

#define AON_POINTER_BUF_START 0x70003800

#define DIV8_BITS_SHIFT 3
#define DIV32_BITS_SHIFT 5
#define MOD32_BIT_MASK 0x1F

#define PMU_PCI_FUNCTION_REGS_COUNT                                            \
	(((PMU_TOTAL_PCI_FUNCTION) >> (DIV32_BITS_SHIFT)) + 1)

/* Defines the number client configurations that can be set. */
#define NUM_OF_CLIENT_CONFIGS (PMU_TOTAL_PCI_FUNCTION)

#define GBE_0_OWNRSHIP_POS BIT(18)
#define GBE_1_OWNRSHIP_POS BIT(19)
#define TGPIO_0_OWNRSHIP_POS BIT(22)
#define TGPIO_1_OWNRSHIP_POS BIT(23)
#define ADC_OWNRSHIP_POS (1ULL << 34)

#define LCPLL_REF_CLK_OWNERS                                                   \
	(GBE_0_OWNRSHIP_POS | GBE_1_OWNRSHIP_POS | TGPIO_0_OWNRSHIP_POS |      \
	 TGPIO_1_OWNRSHIP_POS)

#define TGPIO_REF_CLK_OWNERS (TGPIO_0_OWNRSHIP_POS | TGPIO_1_OWNRSHIP_POS)

#define GBE_REF_CLK_OWNERS (GBE_0_OWNRSHIP_POS | GBE_1_OWNRSHIP_POS)

#define PMU_MASK_D3_BME_CLEAR()                                                \
	do {                                                                   \
		uint32_t addr;                                                 \
		for (int i = 0; i < PMU_PCI_FUNCTION_REGS_COUNT; i++) {        \
			addr = PMU_BRIDGE_INTR_MASK_D3_FALL +                  \
			       i * sizeof(uint32_t);                           \
			write32(addr, PMU_BRIDGE_INTR_MASK_ALL);               \
			addr = PMU_BRIDGE_INTR_MASK_BME_FALL +                 \
			       i * sizeof(uint32_t);                           \
			write32(addr, PMU_BRIDGE_INTR_MASK_ALL);               \
		}                                                              \
	} while (0)

typedef struct {
	sedi_pm_sx_cb func; /**< Callback function */
	void *ctx;	  /**< Context for callback */
} sedi_pm_sx_cb_t;

typedef struct {
	sedi_pm_d3_cb func; /**< Callback function */
	void *ctx;	  /**< Context for callback */
	uint32_t pci_func;
} sedi_pm_d3_cb_t;

typedef struct {
	sedi_pm_s0ix_cb func; /**< Callback function */
	void *ctx;	    /**< Context for callback */
} sedi_pm_s0ix_cb_t;

enum sedi_pm_hook_interrupt_type {
	RESET_PREP_AVAIL,
	PCIEDEV_D3_SET,
	HOST_SX_ENTRY,
	HOST_SX_EXIT,
	HOST_S0IX_SET,
	BIOS_SETTING_CHANGED,
	BOOT_PREP_EVENT,
};

static const uint32_t clock_sel[] = {S0IX_CLK, MAIN_CLK_200M, MAIN_CLK_400M,
				     MAX_CLK_500M};

static const driver_id_t dev_driverid_map[PSE_DEV_MAX] = {
	DRIVER_ID_I2C0,  DRIVER_ID_I2C1,  DRIVER_ID_I2C2,  DRIVER_ID_I2C3,
	DRIVER_ID_I2C4,  DRIVER_ID_I2C5,  DRIVER_ID_I2C6,  DRIVER_ID_I2C7,
	DRIVER_ID_UART0, DRIVER_ID_UART1, DRIVER_ID_UART2, DRIVER_ID_UART3,
	DRIVER_ID_UART4, DRIVER_ID_UART5, DRIVER_ID_SPI0,  DRIVER_ID_SPI1,
	DRIVER_ID_SPI2,  DRIVER_ID_SPI3,  DRIVER_ID_TSN0,  DRIVER_ID_TSN1,
	DRIVER_ID_CAN0,  DRIVER_ID_CAN1,  DRIVER_ID_GPIO0, DRIVER_ID_GPIO1,
	DRIVER_ID_DMA0,  DRIVER_ID_DMA1,  DRIVER_ID_DMA2,  DRIVER_ID_QEP0,
	DRIVER_ID_QEP1,  DRIVER_ID_QEP2,  DRIVER_ID_QEP3,  DRIVER_ID_I2S0,
	DRIVER_ID_I2S1,  DRIVER_ID_PWM0,  DRIVER_ID_ADC,   LAST_DRIVER};

struct pm_ctx_t {
	/* transition is in progress */
	uint8_t pm_transition_in_progress;
	/* received D3 interrupt */
	uint8_t d3_interrupt_raised;
	/* received reset-prepare interrupt */
	uint8_t reset_prep_raised;
	/* received host device D0i3 exit interrupt */
	int8_t host_d0i3_exit_interrupt_raised;
	/* received notification of BIOS setting changed */
	int8_t bios_setting_changed;
	/* Pointer to shared memory on AON */
	aon_pointer_t *p_aon;
	/* LTR value configured from apps */
	uint16_t ltr_values[NUM_OF_CLIENT_CONFIGS + 1];
	/* TTNE value configured from apps */
	uint16_t ttne_values[NUM_OF_CLIENT_CONFIGS + 1];
	/* reset_prep callback registered from apps or PMA */
	sedi_pm_callback_config_t rst_prep_callback[NUM_OF_CLIENT_CONFIGS];
	/* clock_change callback registered from apps or PMA */
	sedi_pm_callback_config_t clk_change_callback[NUM_OF_CLIENT_CONFIGS];
	/* registered reset callback func count */
	uint32_t reset_prep_cb_cnt;
	/* registered clock change callback func count */
	uint32_t clk_change_cb_cnt;
	/* Bitmask to record index of configs which is in use */
	uint32_t client_config_in_use;
	/* Bitmask to record in-transaction status for drivers */
	uint64_t driver_transactions;
	/* Bitmask to record device ownership, 1 means host-owned */
	uint64_t device_ownership;
	/* device which are neither PSE nor host owned. */
	uint64_t device_no_ownership;
	/* Bitmask to record power state of host owned devices */
	uint64_t host_devices_states;
	/* Bitmask to record enable/disable status for all irqs */
	uint8_t current_irq_state[(NR_IRQ >> DIV8_BITS_SHIFT) + 1];
	/* Flag to record if interrupts were disabled */
	uint8_t pm_irq_disabled;
	/* Flag to keep in D0 */
	uint8_t keep_in_d0;
	/* core clock before enter into D0ix */
	uint32_t d0_core_clk;
	/* core clock before system enter into sx */
	uint32_t s0_core_clk;
	/* Trunk clock need to enable */
	uint32_t tcg_req;
	/* GbE PHY interface type */
	uint32_t gbe_phy_intf_type[PSE_MAX_GBE_PORTS];
	/* On FPGA if TCG_GBE_RGMII_PHY_RX needs to be gated/ungated */
	uint32_t tcg_gbe_rgmii_phy_rx_flag;
	/* S0/Sx state change notification */
	sedi_pm_sx_cb_t sx_notify[NUM_OF_SX_CLIENT_CONFIGS];
	sedi_pm_s0ix_cb_t s0ix_notify[NUM_OF_S0IX_CLIENT_CONFIGS];
	/*Host owned device's D3 notifcation */
	sedi_pm_d3_cb_t d3_notify[CONFIG_PM_NUM_OF_D3_CLIENT];
	/* save TCG status. */
	uint32_t tcg_reg_status;
	/* save reset_prep */
	uint32_t reset_prep;
	/* OOB enable */
	uint8_t oob_en;
	/* WOL enable */
	uint8_t wol_en;
	/* received host Sx exit event */
	uint8_t host_sx_entry;
	uint8_t host_sx_exit;
	uint8_t host_s0ix_entry;
	uint8_t host_s0ix_exit;
} __attribute__((packed));

/* Context for PM driver */
static struct pm_ctx_t pm_ctx = {.pm_transition_in_progress = 0,
				 .d3_interrupt_raised = 0,
				 .reset_prep_raised = 0,
				 .host_d0i3_exit_interrupt_raised = -1,
				 .bios_setting_changed = 0,
				 .p_aon =
				     (aon_pointer_t *)AON_POINTER_BUF_START,
				 .ltr_values = {0},
				 .ttne_values = {0},
				 .rst_prep_callback = {
					{0},
				 },
				 .clk_change_callback = {
					{0},
				 },
				 .reset_prep_cb_cnt = 0,
				 .clk_change_cb_cnt = 0,
				 .client_config_in_use = 0,
				 .driver_transactions = 0LLU,
				 .device_ownership = 0LLU,
				 .device_no_ownership = 0x7FFFFFFFF,
				 .host_devices_states = 0LLU,
				 .current_irq_state = {0},
				 .pm_irq_disabled = 0,
				 .keep_in_d0 = 0,
				 .d0_core_clk = 0,
				 .s0_core_clk = 0,
				 .tcg_req = 0,
				 .gbe_phy_intf_type = {0},
				 .tcg_gbe_rgmii_phy_rx_flag = 0,
				 .reset_prep = 0,
				 .oob_en = 0,
				 .wol_en = 0,
				 .host_s0ix_entry = 0,
				 .host_s0ix_exit = 0};

void __attribute__((__weak__)) __pm_reset_prep_callback(int interrupt_type)
{
	PARAM_UNUSED(interrupt_type);
}

static void notify_d3_status(int pci_func, sedi_pm_d3_event_t d3_event)
{
	PARAM_UNUSED(pci_func);
	PARAM_UNUSED(d3_event);
}

static void pm_clear_pmc_wake_intr_sts(void)
{
	/* Clear the pmc_ish_pg rise and fall interrupt status bit */
	SET_REG_BIT(PMU_PMC_PG_WAKE_INTR,
		    PMU_PMC_PG_WAKE_INTR_FALL | PMU_PMC_PG_WAKE_INTR_RISE);
	/* Clear the sw_pg_req_rise rise and fall interrupt status bit */
	SET_REG_BIT(PMU_SW_PG_REQ_INTR,
		    PMU_SW_PG_REQ_B_INTR_FALL | PMU_SW_PG_REQ_B_INTR_RISE);
	/* Clear the br_host_rst_isol_ack risse and fall interrupt status bit */
	SET_REG_BIT(PMU_BRIDGEISOL_CTL_REG,
		    PMU_BR_ISOL_ACK_FALL | PMU_BR_ISOL_ACK_RISE);
	/* Clear the host_rstb rise and fall interrupt status bit */
	SET_REG_BIT(PMU_HOST_RSTB_INTR,
		    PMU_HOST_RST_B_INTR_FALL | PMU_HOST_RST_B_INTR_RISE);
}

static void get_gbe_phy_interface(void)
{
	for (int i = 0; i < PSE_MAX_GBE_PORTS; i++) {
		pm_ctx.gbe_phy_intf_type[i] = pse_gbe_get_phyif(i);
	}
}

static void trunk_clock_configure(uint32_t bitmask, bool gate_en)
{
	if (gate_en) {
		SET_REG_BIT(CCU_TCG_EN, bitmask);
		if ((bitmask == BIT(CCU_TCG_GBE1_SGMII_PHY_RX_POS)) ||
		    (bitmask == BIT(CCU_TCG_GBE2_SGMII_PHY_RX_POS)) ||
		    (bitmask == BIT(CCU_TCG_GBE1_RGMII_PHY_RX_POS)) ||
		    (bitmask == BIT(CCU_TCG_GBE2_RGMII_PHY_RX_POS))) {
			/* from HW: for PHY_RX clocks, not to
			 * wait for status bit because it is from
			 * external PHY without req/ack handshake
			 */
			__NOP();
			return;
		}
		while (!(read32(CCU_TCG_STATUS) & bitmask))
			;
	} else {
		CLEAR_REG_BIT(CCU_TCG_EN, bitmask);
		if ((bitmask == BIT(CCU_TCG_GBE1_SGMII_PHY_RX_POS)) ||
		    (bitmask == BIT(CCU_TCG_GBE2_SGMII_PHY_RX_POS)) ||
		    (bitmask == BIT(CCU_TCG_GBE1_RGMII_PHY_RX_POS)) ||
		    (bitmask == BIT(CCU_TCG_GBE2_RGMII_PHY_RX_POS))) {
			/* from HW: for PHY_RX clocks, not to
			 * wait for status bit because it is from
			 * external PHY without req/ack handshake
			 */
			__NOP();
			return;
		}
		while (read32(CCU_TCG_STATUS) & bitmask)
			;
	}
}

static void pm_read_wake_status(void)
{
	uint32_t sts, addr;

	for (int i = 0; i < PMU_PCI_FUNCTION_REGS_COUNT; i++) {
		addr = PMU_BRIDGE_INTR_D3_RISE + i * sizeof(uint32_t);
		sts = read32(addr);
		if (sts) {
			PM_LOG("PMU: bridge D3 rising interrupt status: "
			       "0x%x(addr):0x%x\n",
			       addr, sts);
			write32(addr, sts);
		}
	}

	for (int i = 0; i < PMU_PCI_FUNCTION_REGS_COUNT; i++) {
		addr = PMU_BRIDGE_INTR_D3_FALL + i * sizeof(uint32_t);
		sts = read32(addr);
		if (sts) {
			PM_LOG("PMU: bridge D3 falling interrupt status: "
			       "0x%x(addr):0x%x\n",
			       addr, sts);
			write32(addr, sts);
		}
	}

	for (int i = 0; i < PMU_PCI_FUNCTION_REGS_COUNT; i++) {
		addr = PMU_BRIDGE_INTR_BME_RISE + i * sizeof(uint32_t);
		sts = read32(addr);
		if (sts) {
			PM_LOG("PMU: bridge BME rising interrupt status: "
			       "0x%x(addr):0x%x\n",
			       addr, sts);
			write32(addr, sts);
		}
	}

	for (int i = 0; i < PMU_PCI_FUNCTION_REGS_COUNT; i++) {
		addr = PMU_BRIDGE_INTR_BME_FALL + i * sizeof(uint32_t);
		sts = read32(addr);
		if (sts) {
			PM_LOG("PMU: bridge BME falling interrupt status: "
			       "0x%x(addr):0x%x\n",
			       addr, sts);
			write32(addr, sts);
		}
	}

	for (int i = 0; i < PMU_PCI_FUNCTION_REGS_COUNT; i++) {
		addr = PMU_BRIDGE_INTR_D3 + i * sizeof(uint32_t);
		sts = read32(addr);
		if (sts) {
			PM_LOG("PMU: bridge D3 interrupt status: "
			       "0x%x(addr):0x%x\n",
			       addr, sts);
			write32(addr, sts);
		}
	}

	if (read32(PMU_D0i3_BIT0_STATUS_REG0)) {
		PM_LOG("PMU: D0i3C_0 %x\n", read32(PMU_D0i3_BIT0_STATUS_REG0));
		write32(PMU_D0i3_BIT0_STATUS_REG0,
			read32(PMU_D0i3_BIT0_STATUS_REG0));
	}

	if (read32(PMU_D0i3_BIT0_STATUS_REG1)) {
		PM_LOG("PMU: D0i3C_1 %x\n", read32(PMU_D0i3_BIT0_STATUS_REG1));
		write32(PMU_D0i3_BIT0_STATUS_REG1,
			read32(PMU_D0i3_BIT0_STATUS_REG1));
	}

	sts = read32(PMU_INTR_GPIO0);
	if (sts) {
		PM_LOG("PMU: GPIO0 interrupt status: 0x%x\n", sts);
		write32(PMU_INTR_GPIO0, sts);
	}

	sts = read32(PMU_INTR_GPIO1);
	if (sts) {
		PM_LOG("PMU: GPIO1 interrupt status: 0x%x\n", sts);
		write32(PMU_INTR_GPIO1, sts);
	}

	sts = read32(PMU_INTR2_GPIO0);
	if (sts) {
		PM_LOG("PMU: GPIO2 interrupt status: 0x%x\n", sts);
		write32(PMU_INTR2_GPIO0, sts);
	}

	sts = read32(PMU_INTR_PWM);
	if (sts) {
		PM_LOG("PMU: PWM/I2S interrupt status: 0x%x\n", sts);
		write32(PMU_INTR_PWM, sts);
	}

	sts = read32(PMU_INTR_GBE);
	if (sts) {
		PM_LOG("PMU: GBE/CAN interrupt status: 0x%x\n", sts);
		write32(PMU_INTR_GBE, sts);
	}

	sts = read32(PMU_INTR_QEP_ADC);
	if (sts) {
		PM_LOG("PMU: QEP/ADC interrupt status: 0x%x\n", sts);
		write32(PMU_INTR_QEP_ADC, sts);
	}
}

SEDI_ISR_DECLARE(sedi_cru_clk_ack_isr)
{
	write32(CCU_TCG_RISE_INTR_STS, read32(CCU_TCG_RISE_INTR_STS));
	write32(CCU_TCG_FALL_INTR_STS, read32(CCU_TCG_FALL_INTR_STS));
}

SEDI_ISR_DECLARE(sedi_pm_pciedev_isr)
{
	uint32_t status;
	uint64_t dev_states;

	PM_LOG("PMU pciedev interrupt received\n");
	PM_LOG("Device ownership: 0x%llx\n", pm_ctx.device_ownership);
	PM_LOG("Host owned device states: 0x%llx\n",
	       pm_ctx.host_devices_states);
	PM_LOG("PMU D3 live status0: 0x%x\n", read32(PMU_D3_STATUS_REG0));
	PM_LOG("PMU D3 live status1: 0x%x\n", read32(PMU_D3_STATUS_REG1));
	PM_LOG("PMU D0i3 bit0[CIP] live status0: 0x%x\n",
	       read32(PMU_D0i3_BIT0_STATUS_REG0));
	PM_LOG("PMU D0i3 bit0[CIP] live status1: 0x%x\n",
	       read32(PMU_D0i3_BIT0_STATUS_REG1));
	PM_LOG("PMU D0i3 bit2 live status0: 0x%x\n",
	       read32(PMU_D0i3_BIT2_STATUS_REG0));
	PM_LOG("PMU D0i3 bit2 live status1: 0x%x\n",
	       read32(PMU_D0i3_BIT2_STATUS_REG1));
	for (int i = 0; i < PMU_TOTAL_PCI_FUNCTION; i++) {
		/* only need to check host-owned devices */
		if (0 == (pm_ctx.device_ownership & (1LLU << i))) {
			continue;
		}
		status = read32(PMU_D3_STATUS + i * sizeof(uint32_t));
		PM_LOG("PMU PCE shadow [%d]: 0x%x\n", i, status);
		/* check for D0i3 */
		if ((status & PMU_D0I3_LIVESTS) &&
		    (status & PMU_D0I3_CIP_LIVESTS) &&
		    (0 == (pm_ctx.host_devices_states & (1LLU << i)))) {
			/* D0i3 bit set */
			PM_LOG("D0i3 bit set, device %d\n", i);
			dev_states = pm_ctx.host_devices_states;
			dev_states |= (1LLU << i);
			pm_ctx.host_devices_states = dev_states;
			/* clear shadowed CIP bit0 */
			write32(PMU_D0i3_BIT0_STATUS_REG0 +
				    sizeof(uint32_t) * (i >> DIV32_BITS_SHIFT),
				BIT(i & MOD32_BIT_MASK));
			/* if all host owned devices except IPC
			 * are in D0i3/D3, de-request VNN
			 */
			if ((pm_ctx.device_ownership &
			     PMU_ALL_PCIDEV_EXCEPT_IPC_MASK) ==
			    (pm_ctx.host_devices_states &
			     PMU_ALL_PCIDEV_EXCEPT_IPC_MASK)) {
				PM_VNN_DRIVER_DEREQ(VNN_ID_PM);
			}
		} else if ((pm_ctx.host_devices_states & (1LLU << i)) &&
			   (0 == (status & PMU_D0I3_LIVESTS)) &&
			   (status & PMU_D0I3_CIP_LIVESTS)) {
			/* D0i3 bit clear */
			PM_LOG("D0i3 bit cleared, device %d\n", i);
			dev_states = pm_ctx.host_devices_states;
			dev_states &= ~(1LLU << i);
			pm_ctx.host_devices_states = dev_states;
			/* request VNN if any of host owned device
			 * except IPC is not in D0i3/D3
			 */
			if (i != PMU_IPC_PCI_DEV_FUNC) {
				PM_VNN_DRIVER_REQ(VNN_ID_PM);
			}
			/* Clear CIP bit if not in transistion, otherwise
			 * set host_d0i3_exit_interrupt_raised
			 */
			if (!pm_ctx.pm_transition_in_progress) {
				write32(PMU_D0i3_BIT0_STATUS_REG0 +
					    sizeof(uint32_t) *
						(i >> DIV32_BITS_SHIFT),
					BIT(i & MOD32_BIT_MASK));
			} else {
				pm_ctx.host_d0i3_exit_interrupt_raised = i;
			}
		}
		/* check for D3 */
		if ((status & (PMU_D3_LIVESTS | PMU_D3_RISE_INTR_STATUS)) &&
		    (0 == (pm_ctx.host_devices_states & (1LLU << i)))) {
			/* D3 bit set */
			PM_LOG("D3 bit set, device %d\n", i);
			dev_states = pm_ctx.host_devices_states;
			dev_states |= (1LLU << i);
			pm_ctx.host_devices_states = dev_states;
			/*notify D3 rising interrupts to registered clients. */
			notify_d3_status(i, PM_EVENT_HOST_D3_ENTRY);

			/* if all host owned devices except IPC
			 * are in D0i3/D3, de-request VNN
			 */
			if ((pm_ctx.device_ownership &
			     PMU_ALL_PCIDEV_EXCEPT_IPC_MASK) ==
			    (pm_ctx.host_devices_states &
			     PMU_ALL_PCIDEV_EXCEPT_IPC_MASK)) {
				PM_VNN_DRIVER_DEREQ(VNN_ID_PM);
			}
			/* if all host owned devices are in
			 * D0i3/D3
			 */
			if (pm_ctx.device_ownership ==
			    pm_ctx.host_devices_states) {
				pm_ctx.d3_interrupt_raised = 1;
				/* call PMA hook to notify the thread
				 * which handle this event
				 */
				__pm_reset_prep_callback(PCIEDEV_D3_SET);
			}
		} else if ((pm_ctx.host_devices_states & (1LLU << i)) &&
			   ((status & PMU_D3_FALL_INTR_STATUS) ||
			    !(status & PMU_D3_LIVESTS))) {
			/* D3 bit clear */
			PM_LOG("D3 bit cleared, device %d\n", i);
			dev_states = pm_ctx.host_devices_states;
			dev_states &= ~(1LLU << i);
			pm_ctx.host_devices_states = dev_states;
			/*notify D3 Falling interrupts to registered clients. */
			notify_d3_status(i, PM_EVENT_HOST_D3_EXIT);

			/* request VNN if any of host owned device
			 * except IPC is not in D0i3/D3
			 */
			if (i != PMU_IPC_PCI_DEV_FUNC) {
				PM_VNN_DRIVER_REQ(VNN_ID_PM);
			}
		}

		/* Clear status/mask */
		write32(PMU_D3_STATUS + i * sizeof(uint32_t), status);
		write32(PMU_D3_STATUS + i * sizeof(uint32_t), 0);
		/* REG 02B8, clear status */
		write32(PMU_D0I3_CIP_INTR_REG_0 +
			    sizeof(uint32_t) * (i >> DIV32_BITS_SHIFT),
			read32(PMU_D0I3_CIP_INTR_REG_0 +
			       sizeof(uint32_t) * (i >> DIV32_BITS_SHIFT)));
		/* REG 0F30, clear PMU_PCE_LOCAL status and set mask */
		SET_REG_BIT(PMU_PCE_LOCAL,
			    PMU_PCE_LOCAL_CHG_DETECTED_INTR_STS |
				PMU_PCE_LOCAL_CHG_DETECTED_INTR_MASK);
		/* Clear PME status interrupt status */
		SET_REG_BIT(PMU_PME_STATUS_CLR_INTR_STS0 +
				sizeof(uint32_t) * (i >> DIV32_BITS_SHIFT),
			    BIT(i & MOD32_BIT_MASK));
	}
}

SEDI_ISR_DECLARE(sedi_pm_reset_prep_isr)
{
	uint32_t reset_prep_val;
	uint32_t status;

	PM_LOG("Reset_prep interrupt!\n");
	pm_ctx.reset_prep_raised = 1;
	pm_ctx.keep_in_d0 = 1;
	reset_prep_val = read32(PMU_RESET_PREP);
	if (reset_prep_val & PMU_RESET_PREP_AVAIL) {
		/* save reset_type */
		pm_ctx.reset_prep = reset_prep_val;
	}
	/* Set mask bit to clear interrupt, will be cleared in next write */
	SET_REG_BIT(PMU_RESET_PREP, PMU_RESET_PREP_INT_MASK);
	/* mask PCE interrupt */
	for (int i = 0; i < PMU_TOTAL_PCI_FUNCTION; i++) {
		status = read32(PMU_D3_STATUS + i * sizeof(uint32_t));

		/* only for host-owned devices */
		if (0 == (pm_ctx.device_ownership & (1LLU << i))) {
			continue;
		}
		SET_REG_BIT(PMU_D3_STATUS + i * sizeof(uint32_t),
			    PMU_PCE_EN_CHANGE_MASK | PMU_D3_INTR_MASK |
				PMU_BME_INTR_MASK);
	}
	/* clear D3/BME/D0i3C interrupt status and set mask */
	PMU_MASK_D3_BME_CLEAR();
	SET_REG_BIT(D0I3C_INTR_STATUS_CLR_MSK_0_REG, D0I3_MASK_0);
	SET_REG_BIT(D0I3C_INTR_STATUS_CLR_MSK_1_REG, D0I3_MASK_1);
	/* call PMA hook to notify the thread which handle this event */
	__pm_reset_prep_callback(RESET_PREP_AVAIL);
}

SEDI_ISR_DECLARE(sedi_pm_wake_isr)
{
	uint32_t rstb;

	PM_LOG("PMU wake interrupt received!\n");
	pm_ctx.keep_in_d0 = 0;
	pm_read_wake_status();

	rstb = read32(PMU_HOST_RSTB_INTR);
	/* Handle host_rst_b falling interrupt on host enter Sx state. */
	if (rstb & PMU_HOST_RST_B_INTR_FALL) {
		PM_LOG("Host entered Sx state\n");
		/* Clear the host_rstb fall interrupt status bit */
		SET_REG_BIT(PMU_HOST_RSTB_INTR, PMU_HOST_RST_B_INTR_FALL);
		pm_ctx.host_sx_entry = 1;
		__pm_reset_prep_callback(HOST_SX_ENTRY);
	}

	/* Handle host_rst_b rising interrupt on host exit Sx state. */
	if (rstb & (PMU_HOST_RST_B_INTR_RISE | PMU_HOST_RST_B_LIVESTS)) {
		PM_LOG("Host entered S0 state\n");
		/* Clear the host_rstb rise interrupt status bit */
		SET_REG_BIT(PMU_HOST_RSTB_INTR, PMU_HOST_RST_B_INTR_RISE);
		/* unmask PCE interrupt */
		for (int i = 0; i < PMU_TOTAL_PCI_FUNCTION; i++) {
			/* only for host-owned devices */
			if (0 == (pm_ctx.device_ownership & (1LLU << i))) {
				continue;
			}

			CLEAR_REG_BIT(PMU_D3_STATUS + i * sizeof(uint32_t),
				      PMU_PCE_EN_CHANGE_MASK |
					  PMU_D3_INTR_MASK | PMU_BME_INTR_MASK);
		}

		pm_ctx.host_sx_exit = 1;
		/* reset reset_prep */
		pm_ctx.reset_prep = 0;
		__pm_reset_prep_callback(HOST_SX_EXIT);
	}
}

SEDI_ISR_DECLARE(sedi_pm_pmu2nvic_isr)
{
	PM_LOG("PMU 2 nvic interrupt received!\n");
}

SEDI_ISR_DECLARE(sedi_dashboard_isr)
{
	uint32_t sts = read32(DASHBOARD_INT_STS);
	uint32_t boot_cfg = read32(DASHBOARD_BOOT_CFG);

	write32(DASHBOARD_INT_STS, sts);

	if (!(boot_cfg & DASHBOARD_CFG_TO_RESET)) {
		return;
	}

	write32(DASHBOARD_BOOT_CFG,
		boot_cfg & ~((uint32_t)DASHBOARD_CFG_TO_RESET));
	pm_ctx.bios_setting_changed = 1;
	__pm_reset_prep_callback(BIOS_SETTING_CHANGED);
}

static void pm_driver_change_cg_state(driver_id_t id, bool perform_cg)
{
	uint32_t bits, bcg_reg;
	uint32_t old_val, new_val;

	switch (id) {
	case DRIVER_ID_UART0:
		bcg_reg = CCU_BCG_UART;
		bits = CCU_BCG_UART0;
		break;
	case DRIVER_ID_UART1:
		bcg_reg = CCU_BCG_UART;
		bits = CCU_BCG_UART1;
		break;
	case DRIVER_ID_UART2:
		bcg_reg = CCU_BCG_UART;
		bits = CCU_BCG_UART2;
		break;
	case DRIVER_ID_UART3:
		bcg_reg = CCU_BCG_UART;
		bits = CCU_BCG_UART3;
		break;
	case DRIVER_ID_UART4:
		bcg_reg = CCU_BCG_UART;
		bits = CCU_BCG_UART4;
		break;
	case DRIVER_ID_UART5:
		bcg_reg = CCU_BCG_UART;
		bits = CCU_BCG_UART5;
		break;
	case DRIVER_ID_DMA0:
		bcg_reg = CCU_BCG_DMA;
		bits = CCU_BCG_DMA0;
		break;
	case DRIVER_ID_DMA1:
		bcg_reg = CCU_BCG_DMA;
		bits = CCU_BCG_DMA1;
		break;
	case DRIVER_ID_DMA2:
		bcg_reg = CCU_BCG_DMA;
		bits = CCU_BCG_DMA2;
		break;
	case DRIVER_ID_I2C0:
		bcg_reg = CCU_BCG_I2C;
		bits = CCU_BCG_I2C0;
		break;
	case DRIVER_ID_I2C1:
		bcg_reg = CCU_BCG_I2C;
		bits = CCU_BCG_I2C1;
		break;
	case DRIVER_ID_I2C2:
		bcg_reg = CCU_BCG_I2C;
		bits = CCU_BCG_I2C2;
		break;
	case DRIVER_ID_I2C3:
		bcg_reg = CCU_BCG_I2C;
		bits = CCU_BCG_I2C3;
		break;
	case DRIVER_ID_I2C4:
		bcg_reg = CCU_BCG_I2C;
		bits = CCU_BCG_I2C4;
		break;
	case DRIVER_ID_I2C5:
		bcg_reg = CCU_BCG_I2C;
		bits = CCU_BCG_I2C5;
		break;
	case DRIVER_ID_I2C6:
		bcg_reg = CCU_BCG_I2C;
		bits = CCU_BCG_I2C6;
		break;
	case DRIVER_ID_I2C7:
		bcg_reg = CCU_BCG_I2C;
		bits = CCU_BCG_I2C7;
		break;
	case DRIVER_ID_SPI0:
		bcg_reg = CCU_BCG_SPI;
		bits = CCU_BCG_SPI0;
		break;
	case DRIVER_ID_SPI1:
		bcg_reg = CCU_BCG_SPI;
		bits = CCU_BCG_SPI1;
		break;
	case DRIVER_ID_SPI2:
		bcg_reg = CCU_BCG_SPI;
		bits = CCU_BCG_SPI2;
		break;
	case DRIVER_ID_SPI3:
		bcg_reg = CCU_BCG_SPI;
		bits = CCU_BCG_SPI3;
		break;
	case DRIVER_ID_GPIO0:
		bcg_reg = CCU_BCG_GPIO;
		bits = CCU_BCG_GPIO0;
		break;
	case DRIVER_ID_GPIO1:
		bcg_reg = CCU_BCG_GPIO;
		bits = CCU_BCG_GPIO1;
		break;
	case DRIVER_ID_TGPIO0:
		bcg_reg = CCU_BCG_TGPIO;
		bits = CCU_BCG_TGPIO0;
		break;
	case DRIVER_ID_TGPIO1:
		bcg_reg = CCU_BCG_TGPIO;
		bits = CCU_BCG_TGPIO1;
		break;
	case DRIVER_ID_I2S0:
		bcg_reg = CCU_BCG_I2S;
		bits = CCU_BCG_I2S0;
		break;
	case DRIVER_ID_I2S1:
		bcg_reg = CCU_BCG_I2S;
		bits = CCU_BCG_I2S1;
		break;
	case DRIVER_ID_TSN0:
		bcg_reg = CCU_BCG_GBE;
		bits = CCU_BCG_GBE0;
		break;
	case DRIVER_ID_TSN1:
		bcg_reg = CCU_BCG_GBE;
		bits = CCU_BCG_GBE1;
		break;
	case DRIVER_ID_SRAM:
		bcg_reg = CCU_BCG_SRAM;
		bits = CCU_BCG_SRAM0;
		break;
	case DRIVER_ID_QEP0:
		bcg_reg = CCU_BCG_QEP;
		bits = CCU_BCG_QEP0;
		break;
	case DRIVER_ID_QEP1:
		bcg_reg = CCU_BCG_QEP;
		bits = CCU_BCG_QEP1;
		break;
	case DRIVER_ID_QEP2:
		bcg_reg = CCU_BCG_QEP;
		bits = CCU_BCG_QEP2;
		break;
	case DRIVER_ID_QEP3:
		bcg_reg = CCU_BCG_QEP;
		bits = CCU_BCG_QEP3;
		break;
	case DRIVER_ID_PWM0:
		bcg_reg = CCU_BCG_PWM;
		bits = CCU_BCG_PWM0;
		break;
	case DRIVER_ID_PWM1:
		bcg_reg = CCU_BCG_PWM;
		bits = CCU_BCG_PWM1;
		break;
	case DRIVER_ID_ADC:
		bcg_reg = CCU_BCG_ADC;
		bits = CCU_BCG_ADC0;
		break;
	case DRIVER_ID_CAN0:
		bcg_reg = CCU_BCG_CANBUS;
		bits = CCU_BCG_CANBUS0;
		break;
	case DRIVER_ID_CAN1:
		bcg_reg = CCU_BCG_CANBUS;
		bits = CCU_BCG_CANBUS1;
		break;
	default:
		return;
	}

	old_val = read32(bcg_reg);

	if (perform_cg) {
		new_val = old_val | bits;
	} else {
		new_val = old_val & ~bits;
	}

	write32(bcg_reg, new_val);
}

static void identify_trunk_clk_req(void)
{
	/* S0ix clock will gated separately during IPAPG or D0i1. */
	pm_ctx.tcg_req = CCU_TCG_S0IX_XTAL;

	pm_ctx.tcg_req |= CCU_TCG_CPU_FAST;

	if ((pm_ctx.device_no_ownership & LCPLL_REF_CLK_OWNERS) !=
	    LCPLL_REF_CLK_OWNERS) {
		pm_ctx.tcg_req |= CCU_TCG_LCPLL_REF;
	}

	if (!(pm_ctx.device_no_ownership & ADC_OWNRSHIP_POS)) {
		pm_ctx.tcg_req |= (CCU_TCG_ADC_HIP | CCU_TCG_ADC_CTRL);
	}

	if ((pm_ctx.device_no_ownership & TGPIO_REF_CLK_OWNERS) !=
	    TGPIO_REF_CLK_OWNERS) {
		pm_ctx.tcg_req |= CCU_TCG_PLL_PTP;
	}

	if ((pm_ctx.device_no_ownership & GBE_REF_CLK_OWNERS) !=
	    GBE_REF_CLK_OWNERS) {
		/* Use PLL_PTP clock as PTP */
		pm_ctx.tcg_req |= CCU_TCG_PLL_PTP;
		if (pm_ctx.gbe_phy_intf_type[0] == PHY_RGMII) {
			pm_ctx.tcg_req |= CCU_TCG_GBE1_RGMII_TX;
			pm_ctx.tcg_req |= CCU_TCG_GBE1_RGMII_PHY_RX;
		}
		if (pm_ctx.gbe_phy_intf_type[1] == PHY_RGMII) {
			pm_ctx.tcg_req |= CCU_TCG_GBE2_RGMII_TX;
			pm_ctx.tcg_req |= CCU_TCG_GBE2_RGMII_PHY_RX;
		}
	}
}

static void setup_tcg_all_except_s0ix(bool gate_en)
{
	int cdc_number = 0x1;

	/* S0ix clock is BIT0, so cdc_number start with 1 */
	for (cdc_number = 1; cdc_number < NUM_OF_TCG_FSMS; cdc_number++) {
		if (!((pm_ctx.tcg_req >> cdc_number) & 0x1)) {
			/* skip if no one have ownership and keep clock gated.
			 */
			continue;
		}
		/* for ADC the HIP has to disable before ADC CTRL CLK and so
		 * will be taken care out side this loop
		 */
		if ((cdc_number == CCU_TCG_ADC_CTRL_POS) ||
		    (cdc_number == CCU_TCG_ADC_HIP_POS)) {
			continue;
		}
		trunk_clock_configure(BIT(cdc_number), gate_en);
	}

	if (pm_ctx.tcg_req & (CCU_TCG_ADC_HIP | CCU_TCG_ADC_CTRL)) {
		if (gate_en) {
			/* Need to clock gate ADC CTRL first then ADC HIP */
			trunk_clock_configure(CCU_TCG_ADC_CTRL, true);
			trunk_clock_configure(CCU_TCG_ADC_HIP, true);
		} else {
			trunk_clock_configure(CCU_TCG_ADC_HIP, false);
			trunk_clock_configure(CCU_TCG_ADC_CTRL, false);
		}
	}
}

static void pm_pll_enable(void)
{
	uint32_t val;

	/* Un-gate LCPLL Reference clock */
	CLEAR_REG_BIT(CCU_TCG_EN, CCU_TCG_LCPLL_REF);
	/* Poll LCPLL Reference clock status bit == 0 */
	while (read32(CCU_TCG_STATUS) & CCU_TCG_STS_LCPLL_REF)
		;

	/* mask PLL unlock interrupt */
	SET_REG_BIT(PMU_PLL_INT_REG, PMU_PLL_UNLOCK_RISE_INTR_MASK);

	val = read32(PMU_PLL_POWERUP_SEQ);
	if (!(val & PMU_PLL_POWERUP_SEQ_FWEN_B)) {
		/* Error: PLL_PUSEQ_FWEN_B bit is not 1 */
		PM_LOG("PLL_PUSEQ_FWEN_B bit is not 1\n");
	}
	/* CRI Reset */
	SET_REG_BIT(PMU_PLL_POWERUP_SEQ, PMU_PLL_POWERUP_SEQ_CRI_RESET);
	val = read32(PMU_PLL_POWERUP_SEQ);
	if (!(val & PMU_PLL_POWERUP_SEQ_FWEN_B) ||
	    !(val & PMU_PLL_POWERUP_SEQ_CRI_RESET)) {
		/* Unexpected PLL PUSEQ value */
		PM_LOG("Unexpected PLL PUSEQ value\n");
	}

	/* Set the Full CAL Reset */
	SET_REG_BIT(PMU_PLL_POWERUP_SEQ, PMU_PLL_POWERUP_SEQ_FULL_CAL_RESET);
	/* Enable PLL */
	SET_REG_BIT(PMU_PLL_POWERUP_SEQ, PMU_PLL_POWERUP_SEQ_PLL_EN);
	/* Wait for PLL_AFC_DONE_BIT == 1 */
	while (!(read32(PMU_PLL_POWERUP_SEQ) & PMU_PLL_POWERUP_SEQ_AFC_DONE))
		;
	/* Wait for PLL Lock = 1 */
	while (!(read32(PMU_PLL_INT_REG) & PMU_PLL_LOCK_LIVE))
		;
	/* Clear interrupt status */
	SET_REG_BIT(PMU_PLL_INT_REG, PMU_PLL_LOCK_RISE_INTR);
	/* Reset PPL divider */
	SET_REG_BIT(PMU_PLL_POWERUP_SEQ, PMU_PLL_POWERUP_SEQ_PLL_DIV_RESET);
	/* Enable all required PLL Dividers */
	if (pm_ctx.tcg_req & (CCU_TCG_GBE1_RGMII_TX | CCU_TCG_GBE2_RGMII_TX)) {
		/* 125Mhz */
		SET_REG_BIT(PMU_PLL_POWERUP_SEQ, PMU_PLL_POWERUP_SEQ_CK125_EN);
		while (!(read32(PMU_PLL_INT_REG) & PMU_PLL_CK125_VALID_LIVE))
			;
	}

	/* 200Mhz */
	if (pm_ctx.tcg_req & CCU_TCG_PLL_PTP) {
		SET_REG_BIT(PMU_PLL_POWERUP_SEQ, PMU_PLL_POWERUP_SEQ_CK200_EN);
		while (!(read32(PMU_PLL_INT_REG) & PMU_PLL_CK200_VALID_LIVE))
			;
	}
	/* 500Mhz */
	SET_REG_BIT(PMU_PLL_POWERUP_SEQ, PMU_PLL_POWERUP_SEQ_CK500_EN);
	while (!(read32(PMU_PLL_INT_REG) & PMU_PLL_CK500_VALID_LIVE))
		;
}

static void pm_ccu_trunk_clock_gate_disable_entry(void)
{
	write32(CCU_TCG_RISE_INTR_MASK, CCU_TCG_INTR_MASK_ALL);
	write32(CCU_TCG_RISE_INTR_STS, read32(CCU_TCG_RISE_INTR_STS));
	/* Enable PLL */
	pm_pll_enable();
	/* Un-gate all CCU trunk clocks except S0ix clock */
	setup_tcg_all_except_s0ix(false);
}

static uint64_t get_host_device_status(void)
{
	uint32_t d0i3_cip_reg0, d0i3_cip_reg1;
	uint32_t d3_reg0, d3_reg1;
	uint64_t d0i3_data, d3_data;

	/* Read D0i3 CIP status for all 36 PCI functions */
	d0i3_cip_reg0 = read32(PMU_D0i3_BIT2_STATUS_REG0);
	d0i3_cip_reg1 = read32(PMU_D0i3_BIT2_STATUS_REG1);
	d0i3_data = (d0i3_cip_reg0 | ((uint64_t)d0i3_cip_reg1 << 32));
	/* Read D3 status for all 36 PCI functions */
	d3_reg0 = read32(PMU_D3_STATUS_REG0);
	d3_reg1 = read32(PMU_D3_STATUS_REG1);
	d3_data = (d3_reg0 | ((uint64_t)d3_reg1 << 32));

	return (d0i3_data | d3_data);
}

static void pm_driver_toggle_active(driver_id_t id, bool is_active)
{
	uint64_t new_trans, cur_trans;

	cur_trans = pm_ctx.driver_transactions;
	if (is_active) {
		new_trans = cur_trans | (1LLU << id);
	} else {
		new_trans = cur_trans & (~(1LLU << id));
	}

	pm_ctx.driver_transactions = new_trans;
}

static void insert_reset_callback(sedi_pm_callback_config_t *cb_config)
{
	int i, ins_pos, cb_count;
	sedi_pm_callback_priority_t cur_pri, ins_pri;
	sedi_pm_callback_config_t *cb_config_array;

	switch (cb_config->type) {
	case CALLBACK_TYPE_RESET_PREP:
		cb_count = pm_ctx.reset_prep_cb_cnt;
		cb_config_array = pm_ctx.rst_prep_callback;
		pm_ctx.reset_prep_cb_cnt++;
		break;
	case CALLBACK_TYPE_CLOCK_CHANGE:
		cb_count = pm_ctx.clk_change_cb_cnt;
		cb_config_array = pm_ctx.clk_change_callback;
		pm_ctx.clk_change_cb_cnt++;
		break;
	default:
		return;
	}

	ins_pos = -1;
	ins_pri = cb_config->pri;
	for (i = 0; i < cb_count; i++) {
		cur_pri = (cb_config_array + i)->pri;
		if (ins_pri > cur_pri) {
			/* mark ins_pos */
			ins_pos = i;
			break;
		}
	}
	if (-1 != ins_pos) {
		/* insert to ins_pos */
		memmove(
		    cb_config_array + ins_pos + 1, cb_config_array + ins_pos,
		    sizeof(sedi_pm_callback_config_t) * (cb_count - ins_pos));
		(cb_config_array + ins_pos)->func = cb_config->func;
		(cb_config_array + ins_pos)->pri = cb_config->pri;
		(cb_config_array + ins_pos)->ctx = cb_config->ctx;
	} else if (cb_count == i) {
		/* add to tail */
		(cb_config_array + i)->func = cb_config->func;
		(cb_config_array + i)->pri = cb_config->pri;
		(cb_config_array + i)->ctx = cb_config->ctx;
	}
}

static void get_device_ownership(void)
{
	int i;
	sedi_dev_ownership_t ownership;

	/* Get ownership for other devices */
	for (i = 0; i < PMU_TOTAL_PCI_FUNCTION - 1; i++) {
		ownership = sedi_get_dev_ownership(i);
		if (ownership == DEV_PSE_OWNED) {
			pm_ctx.device_no_ownership &= ~(1ULL << i);
		} else if ((ownership == DEV_LH_OWNED_MSI) ||
			   (ownership == DEV_LH_OWNED_SB)) {
			pm_ctx.device_ownership |= (1ULL << i);
			pm_ctx.device_no_ownership &= ~(1ULL << i);
		}
	}

	/* Host IPC is always owned by host */
	pm_ctx.device_ownership |= 1ULL << PMU_IPC_PCI_DEV_FUNC;
}

static void pm_bcg_unused_devices(void)
{
	for (int i = 0; i < PSE_DEV_MAX - 1; i++) {
		if (pm_ctx.device_no_ownership & (1ULL << i)) {
			pm_driver_change_cg_state(dev_driverid_map[i], true);
			/* 2 PWM instances share same PCI function */
			if (i == PSE_DEV_PWM) {
				pm_driver_change_cg_state(DRIVER_ID_PWM1, true);
			}
			/* GPIO/TGPIO share same PCI function */
			else if (i == PSE_DEV_GPIO0) {
				pm_driver_change_cg_state(DRIVER_ID_TGPIO0,
							  true);
			} else if (i == PSE_DEV_GPIO1) {
				pm_driver_change_cg_state(DRIVER_ID_TGPIO1,
							  true);
			}
		}
	}
}

int32_t __attribute__((__weak__)) sedi_pm_init(void)
{
	uint32_t i;
	uint32_t boot_cfg = read32(DASHBOARD_BOOT_CFG);

	if (boot_cfg & DASHBOARD_CFG_TO_RESET) {
		write32(DASHBOARD_BOOT_CFG,
			boot_cfg & ~((uint32_t)DASHBOARD_CFG_TO_RESET));
	}

	/* Get GbE PHY interface type */
	get_gbe_phy_interface();
	/* Get host owned device list from IPC driver */
	get_device_ownership();

	/* Update trunk clock requirements */
	identify_trunk_clk_req();

	/* Clear reset history register in CCU */
	write32(CCU_RST_HST, read32(CCU_RST_HST));

	/* Clear TCG clk ack interrupt status */
	write32(CCU_TCG_RISE_INTR_STS, read32(CCU_TCG_RISE_INTR_STS));
	write32(CCU_TCG_FALL_INTR_STS, read32(CCU_TCG_FALL_INTR_STS));
	/* unmask interrupt for TCG clk ack */
	write32(CCU_TCG_FALL_INTR_MASK, 0);
	write32(CCU_TCG_RISE_INTR_MASK, 0);

	/* PM PLL enable and CCU clock-ungate */
	CLEAR_REG_BIT(CCU_TCG_EN, CCU_TCG_S0IX_XTAL);
	pm_ccu_trunk_clock_gate_disable_entry();

	/* Set UART HSU in idle mask */
	write32(PMU_UART_IDLE_MASK, PMU_UART_IDLE_MASK_ALL);

	/* Clear D3 Rise and Fall Interrupt status and mask */
	for (i = 0; i < PMU_TOTAL_PCI_FUNCTION; i++) {
		write32(PMU_PCE_D3_STATUS_0 + i * sizeof(uint32_t),
			read32(PMU_PCE_D3_STATUS_0 + i * sizeof(uint32_t)));
		write32(PMU_PCE_D3_STATUS_0 + i * sizeof(uint32_t), 0);
	}

	/* Clear pmc wake interrupt status */
	pm_clear_pmc_wake_intr_sts();
	/* Unmask wake interrupt */
	write32(PMU_PSE_MASK_EVENT, 0x0);
	write32(PMU_PSE_MASK_EVENT2, 0x0);

	/* Remove mask from RESET_PREP_INT if exists. */
	write32(PMU_RESET_PREP, 0);
	/* Enable TCG */
	write32(CCU_TCG_DISABLE, 0);
	/* Enable BCG */
	CLEAR_REG_BIT(CCU_BCG_DISABLE, BIT(0));
	/* BCG unused devices */
	pm_bcg_unused_devices();
	/* Ungate RF ROM power */
	write32(PMU_RF_ROM_PWR_CTRL, 0);

	/* Turn on dynamic clock gating for SBEP */
	write32(SBEP_SIDE_CLK_GATE_EN, SBEP_SIDE_CLK_GATE_EN_LOCAL_GATED |
					   SBEP_SIDE_CLK_GATE_EN_TRUNK_GATED);

	/* Set idle counter value used by Func clock gate FSM
	 * Keep upper 16 bits to avoid function clock CG abort issue
	 */
	write32(PMU_PSE_FABRIC_CNT,
		(read32(PMU_PSE_FABRIC_CNT) & PMU_PSE_FABRIC_CNT_TIMEOUT_MASK) |
		    PMU_PSE_FABRIC_CNT_TIMEOUT);

	/* Configure maximal delay for PGCB clock gating - the delay is in
	 * func clock cycles.
	 */
	write32(PMU_PGCB_CLKGATE_CTRL, PMU_PGCB_T_CG_TIMER_VALUE_MASK);
	/* Clear VNN Rise and Fall Interrupt status */
	SET_REG_BIT(PMU_VNN_REQ_ACK,
		    PMU_VNN_ACK_RISE_INTR_MASK | PMU_VNN_ACK_FALL_INTR_MASK);
	write32(PMU_VNN_REQ_ACK, read32(PMU_VNN_REQ_ACK));

	/* get host owned device power states */
	if (pm_ctx.device_ownership) {
		pm_ctx.host_devices_states = get_host_device_status();
		/* request VNN for host owned device */
		if ((pm_ctx.host_devices_states &
		     PMU_ALL_PCIDEV_EXCEPT_IPC_MASK) !=
		    (pm_ctx.device_ownership &
		     PMU_ALL_PCIDEV_EXCEPT_IPC_MASK)) {
			PM_VNN_DRIVER_REQ(VNN_ID_PM);
		}
	}
	/* Set firmware status to FW_IS_RUNNING */
	sedi_fwst_set(FW_STATE, FW_IS_RUNNING);

	return SEDI_DRIVER_OK;
}

void __attribute__((__weak__)) pm_driver_start_trans(driver_id_t id)
{
	SEDI_ASSERT((id >= FIRST_DRIVER) && (id < LAST_DRIVER));

	pm_driver_toggle_active(id, 1);

	if ((id >= FIRST_DRIVER) && (id < LAST_DRIVER_CG)) {
		pm_driver_change_cg_state(id, FALSE);
	}
}

void __attribute__((__weak__)) pm_driver_end_trans(driver_id_t id)
{
	SEDI_ASSERT((id >= FIRST_DRIVER) && (id < LAST_DRIVER));
	SEDI_ASSERT(pm_ctx.driver_transactions & (1LLU << id));

	if ((id >= FIRST_DRIVER) && (id < LAST_DRIVER_CG)) {
		pm_driver_change_cg_state(id, TRUE);
	}

	pm_driver_toggle_active(id, 0);
}

uint32_t __attribute__((__weak__)) sedi_pm_get_hbw_clock(void)
{
	int idx = read32(CCU_HBW_CLK_SWITCHING) & CCU_HBW_CLK_SEL;

	return clock_sel[idx];
}

void __attribute__((__weak__)) pm_set_wdt_cg(uint32_t enable)
{
	uint32_t val = read32(CCU_BCG_DISABLE) & CCU_BCG_DISABLE_WDT;

	if (enable && val) {
		/* to enable WDT CG */
		CLEAR_REG_BIT(CCU_BCG_DISABLE, CCU_BCG_DISABLE_WDT);
	} else if (!enable && !val) {
		/* to disable WDT CG */
		SET_REG_BIT(CCU_BCG_DISABLE, CCU_BCG_DISABLE_WDT);
	}
}

int32_t __attribute__((__weak__))
sedi_pm_set_control(uint32_t control, uint32_t arg)
{
	int32_t ret = SEDI_DRIVER_OK;

	DBG_CHECK(control < SEDI_PM_IOCTL_MAX, SEDI_DRIVER_ERROR_PARAMETER);

	switch (control) {
	case SEDI_PM_IOCTL_TCG_GBE_RGMII_PHY_RX:
		/* On FPGA, set a flag to indicate if GBE AOB PHY
		 * daughter board is plugged in or not
		 */
		pm_ctx.tcg_gbe_rgmii_phy_rx_flag = arg;
		break;
	default:
		break;
	}

	return ret;
}

int32_t __attribute__((__weak__))
sedi_pm_register_callback(sedi_pm_callback_config_t *callback_config)
{
	int32_t ret = SEDI_DRIVER_OK;

	if (callback_config == NULL) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	switch (callback_config->type) {
	case CALLBACK_TYPE_RESET_PREP:
		if (callback_config->func.rstprep_cb == NULL) {
			return SEDI_DRIVER_ERROR_PARAMETER;
		}
		if (pm_ctx.reset_prep_cb_cnt == NUM_OF_CLIENT_CONFIGS) {
			return SEDI_PM_ERROR_NOMEM;
		}
		break;
	case CALLBACK_TYPE_CLOCK_CHANGE:
		if (callback_config->func.clk_change_cb == NULL) {
			return SEDI_DRIVER_ERROR_PARAMETER;
		}
		if (pm_ctx.clk_change_cb_cnt == NUM_OF_CLIENT_CONFIGS) {
			return SEDI_PM_ERROR_NOMEM;
		}
		break;
	default:
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	insert_reset_callback(callback_config);

	return ret;
}

int32_t __attribute__((__weak__))
sedi_pm_vnn_request(vnn_id_t id, int32_t enable)
{
	if ((id < FIRST_VNN_ID) || (id >= LAST_VNN_ID)) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	if (enable) {
		PM_VNN_DRIVER_REQ(id);
	} else {
		PM_VNN_DRIVER_DEREQ(id);
	}

	return SEDI_DRIVER_OK;
}
