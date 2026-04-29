/*
 * Copyright (c) 2026 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/sys/__assert.h>

#include <zephyr/bluetooth/buf.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/atomic.h>
#include <stdatomic.h>
#include <zephyr/bluetooth/hci_raw.h>
#include "common/bt_str.h"
#include "sedi_driver_rtc.h"

#include "iut.h"

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(hci_test, 3);

static K_FIFO_DEFINE(rx_queue);
static K_THREAD_STACK_DEFINE(rx_thread_stack, 4096);
static struct k_thread rx_thread;
static K_SEM_DEFINE(sem_cc, 0, 1);
static atomic_t cc_opcode = (atomic_t)UINT16_MAX;
static atomic_t cc_status = (atomic_t)UINT8_MAX;
static uint64_t cc_us;

static void handle_cmd_complete_event(struct net_buf *evt_buf)
{
	struct bt_hci_evt_cmd_complete *cc;
	struct bt_hci_evt_cc_status *status;

	if (evt_buf->len < sizeof(*cc) + sizeof(*status)) {
		LOG_ERR("Invalid Command Complete event length: %u", evt_buf->len);
		return;
	}

	cc = net_buf_pull_mem(evt_buf, sizeof(*cc));
	status = net_buf_pull_mem(evt_buf, sizeof(*status));

	/* Store status and opcode atomically and publish before giving semaphore */
	atomic_set(&cc_status, (atomic_val_t)status->status);
	atomic_set(&cc_opcode, (atomic_val_t)sys_le16_to_cpu(cc->opcode));
	atomic_thread_fence(memory_order_release);

	cc_us = sedi_rtc_get_us() - cc_us;
	LOG_INF("Received Command Complete for opcode 0x%04x: 0x%02x(%s) after %llu us",
		(unsigned int)atomic_get(&cc_opcode), (unsigned int)atomic_get(&cc_status),
		atomic_get(&cc_status) ? "Error" : "Success", cc_us);

	k_sem_give(&sem_cc);
}

void bt_data_parse(struct net_buf_simple *ad, bool (*func)(struct bt_data *data, void *user_data),
		   void *user_data)
{
	while (ad->len > 1) {
		struct bt_data data;
		uint8_t len;

		len = net_buf_simple_pull_u8(ad);
		if (len == 0U) {
			/* Early termination */
			return;
		}

		if (len > ad->len) {
			LOG_WRN("malformed advertising data %u / %u", len, ad->len);
			return;
		}

		data.type = net_buf_simple_pull_u8(ad);
		data.data_len = len - 1;
		data.data = ad->data;

		if (!func(&data, user_data)) {
			return;
		}

		net_buf_simple_pull(ad, len - 1);
	}
}

#if 0
static bool print_ad_field(struct bt_data *data, void *user_data)
{
	ARG_UNUSED(user_data);

	LOG_INF("    AD type 0x%02x len %u", data->type, data->data_len);
	LOG_HEXDUMP_INF(data->data, data->data_len, "    AD data:");

	return true;
}
#endif

static void handle_le_meta_event(struct net_buf *evt_buf)
{
	struct bt_hci_evt_le_meta_event *meta;

	if (evt_buf->len < sizeof(*meta)) {
		LOG_ERR("Invalid LE Meta event length: %u", evt_buf->len);
		return;
	}

	meta = net_buf_pull_mem(evt_buf, sizeof(*meta));
	if (meta->subevent != BT_HCI_EVT_LE_EXT_ADVERTISING_REPORT) {
		LOG_ERR("Unexpected LE Meta subevent 0x%02x", meta->subevent);
		return;
	}

	if (evt_buf->len < sizeof(struct bt_hci_evt_le_ext_advertising_report)) {
		LOG_ERR("Invalid LE Extended Advertising Report event length: %u", evt_buf->len);
		return;
	}

	struct bt_hci_evt_le_ext_advertising_report *report =
		net_buf_pull_mem(evt_buf, sizeof(*report));

	for (uint8_t i = 0; i < report->num_reports; i++) {
		struct bt_hci_evt_le_ext_advertising_info *info;

		if (evt_buf->len < sizeof(*info)) {
			LOG_ERR("Invalid LE Extended Advertising Info event length: %u",
				evt_buf->len);
			break;
		}

		info = net_buf_pull_mem(evt_buf, sizeof(*info));
		LOG_INF("Received LE Extended Advertising Report: "
			"sid=0x%02x, evt_type=0x%04x, addr=%s, rssi=%d",
			info->sid, sys_le16_to_cpu(info->evt_type), bt_addr_le_str(&info->addr),
			info->rssi);

		if (info->length) {
			if (evt_buf->len < info->length) {
				LOG_ERR("Invalid LE Extended Advertising Info data length: %u",
					evt_buf->len);
				break;
			}
#if 0

			uint8_t *adv_data = net_buf_pull_mem(evt_buf, info->length);
			struct net_buf_simple ad;

			net_buf_simple_init_with_data(&ad, adv_data, info->length);
			bt_data_parse(&ad, print_ad_field, NULL);
#endif
		} else {
			LOG_INF("  No advertising data");
		}
	}
}

static void rx_thread_process(void *p1, void *p2, void *p3)
{
	while (1) {
		struct bt_hci_evt_hdr *hdr;
		struct net_buf *evt_buf;

		evt_buf = k_fifo_get(&rx_queue, K_FOREVER);

		if (evt_buf->len < sizeof(*hdr)) {
			LOG_ERR("Invalid HCI event length: %u", evt_buf->len);
			net_buf_unref(evt_buf);
			continue;
		}

		hdr = net_buf_pull_mem(evt_buf, sizeof(*hdr));
		if (evt_buf->len < hdr->len) {
			LOG_ERR("HCI event length mismatch, hdr=%u, actual=%u", hdr->len,
				evt_buf->len);
			net_buf_unref(evt_buf);
			continue;
		}

		if (hdr->evt == BT_HCI_EVT_CMD_COMPLETE) {
			handle_cmd_complete_event(evt_buf);
		} else if (hdr->evt == BT_HCI_EVT_LE_META_EVENT) {
			handle_le_meta_event(evt_buf);
		} else {
			LOG_INF("Received unexpected HCI event 0x%02x, just discard!", hdr->evt);
		}

		net_buf_unref(evt_buf);
	}
}

static int hci_send_cmd(struct net_buf *cmd_buf, const char *cmd_info)
{
	int ret;
	struct bt_hci_cmd_hdr *hdr = (void *)(cmd_buf->data + 1); /* skip H4 type byte */
	uint16_t opcode = sys_le16_to_cpu(hdr->opcode);

	atomic_set(&cc_opcode, (atomic_val_t)UINT16_MAX);
	atomic_set(&cc_status, (atomic_val_t)UINT8_MAX);
	while (k_sem_take(&sem_cc, K_NO_WAIT) == 0) {
		/* drained stale give */
	}

	LOG_INF("Send out command 0x%04x with parameter len %u: %s", opcode, hdr->param_len,
		cmd_info);

	cc_us = sedi_rtc_get_us();
	ret = bt_send(cmd_buf);
	if (ret != 0) {
		TEST_ASSERT_EQUAL(0, ret);
		net_buf_unref(cmd_buf);
		return ret;
	}

	do {
		ret = k_sem_take(&sem_cc, K_MSEC(1000));
		if (ret) {
			LOG_ERR("Timed out waiting for Command Complete for opcode 0x%04x", opcode);
			TEST_ASSERT_EQUAL(0, ret);
			return -ETIMEDOUT;
		}

		/* Ensure we see the values published by the handler */
		atomic_thread_fence(memory_order_acquire);

		if ((atomic_val_t)atomic_get(&cc_opcode) == (atomic_val_t)opcode) {
			if ((atomic_val_t)atomic_get(&cc_status) != 0) {
				ret = -EIO;
			}

			atomic_set(&cc_opcode, (atomic_val_t)UINT16_MAX);
			atomic_set(&cc_status, (atomic_val_t)UINT8_MAX);
			break;
		}
		LOG_ERR("Received Command Complete for unexpected opcode 0x%04x, expected 0x%04x",
			(unsigned int)atomic_get(&cc_opcode), opcode);
		atomic_set(&cc_opcode, (atomic_val_t)UINT16_MAX);
		atomic_set(&cc_status, (atomic_val_t)UINT8_MAX);
	} while (1);

	return ret;
}

static int bt_raw_init(void)
{
	int ret = bt_enable_raw(&rx_queue);
	if (ret) {
		LOG_ERR("Failed to enable raw mode, ret %d", ret);
		return ret;
	}

	k_thread_create(&rx_thread, rx_thread_stack, K_THREAD_STACK_SIZEOF(rx_thread_stack),
			rx_thread_process, NULL, NULL, NULL, K_PRIO_COOP(4), 0, K_NO_WAIT);
	k_thread_name_set(&rx_thread, "HCI uart RX");

	return 0;
}

SYS_INIT(bt_raw_init, APPLICATION, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);

size_t bt_data_get_len(const struct bt_data data[], size_t data_count)
{
	size_t total_len = 0;

	for (size_t i = 0; i < data_count; i++) {
		total_len += sizeof(data[i].data_len) + sizeof(data[i].type) + data[i].data_len;
	}

	return total_len;
}

static int _adv_set_data(const struct bt_data data[], size_t data_count)
{
	struct bt_hci_cmd_hdr *hdr;
	struct bt_hci_cp_le_set_ext_adv_data *param_data;
	struct net_buf *cmd_buf;
	uint8_t *ad_buf;

	/* Compute serialized advertising data length */
	size_t ad_len = bt_data_get_len(data, data_count);

	/* Ensure the parameter length fits in a single octet as used by HCI */
	if (ad_len > UINT8_MAX - sizeof(struct bt_hci_cp_le_set_ext_adv_data)) {
		LOG_ERR("Advertising data too large: %zu", ad_len);
		return -EINVAL;
	}

	uint8_t param_len = sizeof(struct bt_hci_cp_le_set_ext_adv_data) + ad_len;

	cmd_buf = bt_buf_get_tx(BT_BUF_CMD, K_FOREVER, NULL, 0);
	if (cmd_buf == NULL) {
		TEST_ASSERT_NOT_EQUAL(NULL, cmd_buf);
		return -ENOMEM;
	}

	hdr = net_buf_add(cmd_buf, sizeof(*hdr));
	hdr->opcode = sys_cpu_to_le16(BT_HCI_OP_LE_SET_EXT_ADV_DATA);
	hdr->param_len = param_len;

	param_data = net_buf_add(cmd_buf, sizeof(*param_data));
	param_data->handle = 0x0;
	param_data->op = BT_HCI_LE_EXT_ADV_OP_COMPLETE_DATA;
	param_data->frag_pref = BT_HCI_LE_EXT_ADV_FRAG_DISABLED;
	param_data->len = ad_len;

	ad_buf = net_buf_add(cmd_buf, ad_len);

	for (size_t i = 0; i < data_count; i++) {
		*ad_buf++ = data[i].data_len + 1;
		*ad_buf++ = data[i].type;
		memcpy(ad_buf, data[i].data, data[i].data_len);
		ad_buf += data[i].data_len;
	}

	return hci_send_cmd(cmd_buf, "HCI_LE_Set_Extended_Advertising_Data");
}
/*
 * Set Advertisement data. Based on the Eddystone specification:
 * https://github.com/google/eddystone/blob/master/protocol-specification.md
 * https://github.com/google/eddystone/tree/master/eddystone-url
 */
static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, BT_LE_AD_NO_BREDR),
	BT_DATA_BYTES(BT_DATA_UUID16_ALL, 0xaa, 0xfe),
	BT_DATA_BYTES(BT_DATA_SVC_DATA16, 0xaa, 0xfe, /* Eddystone UUID */
		      0x10,                           /* Eddystone-URL frame type */
		      0x00,                           /* Calibrated Tx power at 0m */
		      0x00,                           /* URL Scheme Prefix http://www. */
		      'z', 'e', 'p', 'h', 'y', 'r', 'p', 'r', 'o', 'j', 'e', 'c', 't',
		      0x08) /* .org */
};

static int test_adv_set_data(int argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	return _adv_set_data(ad, ARRAY_SIZE(ad));
}
DEFINE_IUT_CASE(adv_set_data, hci, IUT_ATTRI_NONE);

static uint8_t mfg_data[194] = {0};
static const struct bt_data ad_200[] = {
	BT_DATA(BT_DATA_MANUFACTURER_DATA, mfg_data, sizeof(mfg_data)),
};

static int test_adv_set_data_200(int argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	for (size_t i = 0; i < sizeof(mfg_data); i++) {
		mfg_data[i] = i;
	}
	return _adv_set_data(ad_200, ARRAY_SIZE(ad_200));
}
DEFINE_IUT_CASE(adv_set_data_200, hci, IUT_ATTRI_NONE);

static int _test_adv_enable(bool to_enable)
{
	struct bt_hci_cmd_hdr *hdr;
	struct bt_hci_cp_le_set_ext_adv_enable *param_enable;
	struct net_buf *cmd_buf;
	uint8_t param_len = sizeof(*param_enable) + sizeof(param_enable->s[0]);

	cmd_buf = bt_buf_get_tx(BT_BUF_CMD, K_FOREVER, NULL, 0);
	if (cmd_buf == NULL) {
		TEST_ASSERT_NOT_EQUAL(NULL, cmd_buf);
		return -ENOMEM;
	}

	hdr = net_buf_add(cmd_buf, sizeof(*hdr));
	hdr->opcode = sys_cpu_to_le16(BT_HCI_OP_LE_SET_EXT_ADV_ENABLE);
	hdr->param_len = param_len;

	param_enable = net_buf_add(cmd_buf, param_len);
	if (to_enable) {
		param_enable->enable = BT_HCI_LE_ADV_ENABLE;
	} else {
		param_enable->enable = BT_HCI_LE_ADV_DISABLE;
	}
	param_enable->set_num = 1;
	param_enable->s[0].handle = 0x0;
	param_enable->s[0].duration = 0x0;
	param_enable->s[0].max_ext_adv_evts = 0x0;

	return hci_send_cmd(cmd_buf, to_enable ? "HCI_LE_Set_Extended_Advertising_Enable, ENABLE"
					       : "HCI_LE_Set_Extended_Advertising_Enable, DISABLE");
}

static int test_adv_enable(int argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	return _test_adv_enable(true);
}
DEFINE_IUT_CASE(adv_enable, hci, IUT_ATTRI_NONE);

static int test_adv_disable(int argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	return _test_adv_enable(false);
}
DEFINE_IUT_CASE(adv_disable, hci, IUT_ATTRI_NONE);

static int test_scan_set_param(int argc, char **argv)
{
	ARG_UNUSED(argc);
	ARG_UNUSED(argv);

	struct bt_hci_cmd_hdr *hdr;
	struct bt_hci_cp_le_set_ext_scan_param *set_param;
	struct bt_hci_ext_scan_phy *phy_1m;
	struct net_buf *cmd_buf;
	uint8_t param_len = sizeof(*set_param) + sizeof(*phy_1m);

	cmd_buf = bt_buf_get_tx(BT_BUF_CMD, K_FOREVER, NULL, 0);
	if (cmd_buf == NULL) {
		TEST_ASSERT_NOT_EQUAL(NULL, cmd_buf);
		return -ENOMEM;
	}

	hdr = net_buf_add(cmd_buf, sizeof(*hdr));
	hdr->opcode = sys_cpu_to_le16(BT_HCI_OP_LE_SET_EXT_SCAN_PARAM);
	hdr->param_len = param_len;
	set_param = net_buf_add(cmd_buf, param_len);
	set_param->own_addr_type = BT_ADDR_LE_RANDOM;
	set_param->filter_policy = BT_HCI_LE_SCAN_FP_BASIC_NO_FILTER;
	set_param->phys = BT_HCI_LE_EXT_SCAN_PHY_1M;
	phy_1m = set_param->p;
	phy_1m->type = BT_HCI_LE_SCAN_PASSIVE;
	phy_1m->interval = sys_cpu_to_le16(BT_GAP_SCAN_FAST_INTERVAL);
	phy_1m->window = sys_cpu_to_le16(BT_GAP_SCAN_FAST_WINDOW);

	return hci_send_cmd(cmd_buf, "HCI_LE_Set_Extended_Scan_Parameters");
}
DEFINE_IUT_CASE(scan_set_param, hci, IUT_ATTRI_NONE);

static int test_send_hci(int argc, char **argv)
{
	struct bt_hci_cmd_hdr *hdr;
	struct net_buf *cmd_buf;
	int ret = 0;

	if (argc < 1) {
		LOG_ERR("Missing HCI raw bytes");
		ret = -EINVAL;
		goto f_out;
	}
	if (argc < sizeof(*hdr)) {
		LOG_ERR("Not enough bytes for HCI command header");
		ret = -EINVAL;
		goto f_out;
	}

	cmd_buf = bt_buf_get_tx(BT_BUF_CMD, K_FOREVER, NULL, 0);
	if (cmd_buf == NULL) {
		TEST_ASSERT_NOT_EQUAL(NULL, cmd_buf);
		ret = -ENOMEM;
		goto f_out;
	}
	hdr = (struct bt_hci_cmd_hdr *)cmd_buf->data;

	for (uint32_t i = 0; i < sizeof(*hdr); i++) {
		uint8_t byte = (uint8_t)strtoul(argv[0], NULL, 0);
		net_buf_add_u8(cmd_buf, byte);
		argv++;
		argc--;
	}
	if (argc < hdr->param_len) {
		LOG_ERR("Not enough bytes for HCI command parameters, expected %u, got %u",
			hdr->param_len, argc);
		net_buf_unref(cmd_buf);
		ret = -EINVAL;
		goto f_out;
	}
	while (argc > 0) {
		uint8_t byte = (uint8_t)strtoul(argv[0], NULL, 0);
		net_buf_add_u8(cmd_buf, byte);
		argv++;
		argc--;
	}
	LOG_HEXDUMP_INF(cmd_buf->data, cmd_buf->len, "HCI raw command data:");

	ret = hci_send_cmd(cmd_buf, "Unknown from input");

f_out:
	TEST_ASSERT_EQUAL(0, ret);
	return ret;
}
DEFINE_IUT_CASE(send_hci, hci, IUT_ATTRI_NONE);
