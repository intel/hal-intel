/*
 * Copyright (c) 2023 Intel Corporation
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "sedi_driver_uart.h"
#include "sedi_dw_uart.h"
#include "sedi_driver_pm.h"

static sedi_uart_reg_t *sedi_uart[SEDI_UART_NUM];
static sedi_uart_context_t uart_context[SEDI_UART_NUM];

/* Transmit & Receive control. */
typedef struct {
	uint8_t tx_disable : 1;
	uint8_t rx_disable : 1;
} uart_xfer_ctrl_t;

static uart_xfer_ctrl_t uart_xfer_ctrl[SEDI_UART_NUM];

/* Buffer pointers to store transmit / receive data for UART. */
static uint32_t write_pos[SEDI_UART_NUM];
static uint32_t read_pos[SEDI_UART_NUM];
static const sedi_uart_transfer_t *uart_read_transfer[SEDI_UART_NUM];
static const sedi_uart_transfer_t *uart_write_transfer[SEDI_UART_NUM];
static uint32_t iir_cache[SEDI_UART_NUM];
static uint32_t baud_rate_cache[SEDI_UART_NUM];
static uint32_t clk_speed_cache[SEDI_UART_NUM];
static uint32_t status_report_mask[SEDI_UART_NUM];

typedef struct {
	uint32_t enable_unsol_rx;
	int32_t read_idx;
	int32_t write_idx;
	int32_t curr_len;
	const sedi_uart_unsol_rx_t *unsol_rx;
} unsol_read_context_t;

unsol_read_context_t unsol_read_ctxt[SEDI_UART_NUM];

typedef struct {
	sedi_uart_transfer_t xfer;
	const sedi_uart_io_vec_xfer_t *vec;
	uint32_t curr_count;
	uint8_t active;
} io_vec_cntxt_t;

static io_vec_cntxt_t vec_read_ctxt[SEDI_UART_NUM];
static io_vec_cntxt_t vec_write_ctxt[SEDI_UART_NUM];

typedef enum { WRITE, READ } dma_operation_type_t;

typedef struct {
	const sedi_uart_dma_xfer_t *dma_xfer;
	sedi_uart_t uart;
	dma_operation_type_t operation; /* READ/WRITE */
} uart_dma_ctxt_t;

static uint32_t uart_dma_hs_id[SEDI_UART_NUM];

static uart_dma_ctxt_t dma_write_ctxt[SEDI_UART_NUM];

static uart_dma_ctxt_t dma_read_ctxt[SEDI_UART_NUM];

/* DMA driver requires to have a callback to be provided during init even
 * when in polled mode. Adding a dummy callback for this.
 */
static void sedi_dma_poll_dummy_cb(IN sedi_dma_t dma_dev, IN int channel,
				   IN int event, INOUT void *param)
{
	PARAM_UNUSED(event);
	PARAM_UNUSED(param);
	PARAM_UNUSED(dma_dev);
	PARAM_UNUSED(channel);
}

static void sedi_dma_event_cb(IN sedi_dma_t dma_device, IN int channel_id,
			      IN int event, INOUT void *param)
{
	(void)dma_device;
	(void)channel_id;
	uart_dma_ctxt_t *ctxt = (uart_dma_ctxt_t *)(param);
	sedi_uart_dma_xfer_t *xfer = (sedi_uart_dma_xfer_t *)(ctxt->dma_xfer);

	/* Program next transfer. */
	sedi_uart_reg_t *const regs = SEDI_UART[ctxt->uart];
	uint32_t line_err_status = (regs->lsr & SEDI_UART_LSR_ERROR_BITS);

	if (ctxt->operation == READ) {
		if (event == SEDI_DMA_EVENT_TRANSFER_DONE) {
			if (xfer->callback) {
				xfer->callback(xfer->cb_param, SEDI_DRIVER_OK,
					       line_err_status, xfer->len);
			}
		} else {
			if (xfer->callback) {
				xfer->callback(xfer->cb_param,
					       SEDI_DRIVER_ERROR,
					       line_err_status, xfer->len);
			}
		}
	} else if (ctxt->operation == WRITE) {
		if (event == SEDI_DMA_EVENT_TRANSFER_DONE) {
			/* wait for transfer to complete as data may
			 * still be in the fifo/ tx shift regs.
			 */
			while (!(regs->lsr & SEDI_UART_LSR_TEMT)) {
			}
			if (xfer->callback) {
				xfer->callback(xfer->cb_param, SEDI_DRIVER_OK,
					       line_err_status, xfer->len);
			}
		} else {
			if (xfer->callback) {
				xfer->callback(xfer->cb_param,
					       SEDI_DRIVER_ERROR,
					       line_err_status, xfer->len);
			}
		}
	}

	ctxt->dma_xfer = NULL;
}

#if HAS_UART_SOFT_RST
/* Soft reset all instances if not done before */
static void uart_soft_rst(void)
{
	static bool uart_rst_done;
	volatile uint32_t *rst_reg = (uint32_t *)(SEDI_UART_SFT_RST_REG);

	if (!uart_rst_done) {
		*rst_reg = SEDI_UART_SFT_RST_MASK;
		*rst_reg = 0;
		uart_rst_done = true;
	}
}

static void uart_soft_rst_instance(sedi_uart_t uart)
{
	volatile uint32_t *rst_reg = (uint32_t *)(SEDI_UART_SFT_RST_REG);

	*rst_reg |= (1 << uart);
	*rst_reg &= (~(1 << uart));

	/* Wait till reset bit is cleared */
	while (*rst_reg & (1 << uart)) {
		__asm volatile("nop");
	}
}
#endif

static void io_vec_write_callback(void *data, int error, uint32_t status,
				  uint32_t len)
{

	sedi_uart_t uart = (sedi_uart_t)(data);
	const sedi_uart_io_vec_xfer_t *const vec_xfer =
	    vec_write_ctxt[uart].vec;

	uint32_t current_count;

	/* Increment the next count */
	current_count = ++vec_write_ctxt[uart].curr_count;
	PARAM_UNUSED(len);

	/* Error in write or transfer completed , call user callback.*/
	if (status || (current_count == vec_xfer->count)) {
		if (vec_xfer->callback) {

			/* Call callback with error. */
			vec_xfer->callback(vec_xfer->cb_data, error, status,
					   current_count);
		}
		/* Set active xfer to false. */
		vec_write_ctxt[uart].active = false;
		return;
	}

	/* Program next transfer. */
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	vec_write_ctxt[uart].xfer.data = vec_xfer->vec[current_count].base;
	vec_write_ctxt[uart].xfer.data_len = vec_xfer->vec[current_count].len;
	write_pos[uart] = 0;
	uart_write_transfer[uart] = &vec_write_ctxt[uart].xfer;

	/* Wait for last write transfer to finish completely. */
	while (!(regs->lsr & SEDI_UART_LSR_TEMT)) {
	}

	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD);

	/* Enable TX holding reg empty interrupt. */
	regs->ier_dlh |= SEDI_UART_IER_ETBEI;
}

static void io_vec_read_callback(void *data, int error, uint32_t status,
				 uint32_t len)
{
	sedi_uart_t uart = (sedi_uart_t)(data);
	const sedi_uart_io_vec_xfer_t *const vec_xfer = vec_read_ctxt[uart].vec;
	uint32_t current_count;

	PARAM_UNUSED(len);

	/* Increment the next count */
	current_count = ++vec_read_ctxt[uart].curr_count;

	/* Error in read or read completes, call user callback.*/
	if (status || (current_count == vec_xfer->count)) {
		if (vec_xfer->callback) {
			/* Call callback with error. */
			vec_xfer->callback(vec_xfer->cb_data, error, status,
					   current_count);
		}
		/* Set active xfer to false. */
		vec_read_ctxt[uart].active = false;
		return;
	}

	/* Program next transfer */
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	vec_read_ctxt[uart].xfer.data = vec_xfer->vec[current_count].base;
	vec_read_ctxt[uart].xfer.data_len = vec_xfer->vec[current_count].len;
	read_pos[uart] = 0;
	uart_read_transfer[uart] = &vec_read_ctxt[uart].xfer;

	/* Set threshold. */
	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD);

	/*
	 * Enable both 'Receiver Data Available' and 'Receiver
	 * Line Status' interrupts.
	 */
	regs->ier_dlh |= SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI;
}

static bool is_read_xfer_complete(const sedi_uart_t uart)
{
	const sedi_uart_transfer_t *const transfer = uart_read_transfer[uart];

	return read_pos[uart] >= transfer->data_len;
}

static bool is_write_xfer_complete(const sedi_uart_t uart)
{
	const sedi_uart_transfer_t *const transfer = uart_write_transfer[uart];

	return write_pos[uart] >= transfer->data_len;
}

static void handle_unsol_rx_data(const sedi_uart_t uart)
{
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	uint32_t lsr = regs->lsr;
	const sedi_uart_unsol_rx_t *const unsol_rx =
	    unsol_read_ctxt[uart].unsol_rx;
	int32_t write_idx = unsol_read_ctxt[uart].write_idx;
	int32_t read_idx = unsol_read_ctxt[uart].read_idx;

	while (lsr & SEDI_UART_LSR_DR) {
		write_idx++;
		if (write_idx == unsol_rx->size) {
			write_idx = 0;
		}
		unsol_rx->buffer[write_idx] = regs->rbr_thr_dll;
		lsr = regs->lsr;
	}
	unsol_read_ctxt[uart].write_idx = write_idx;
	if (read_idx < write_idx) {
		unsol_read_ctxt[uart].curr_len = write_idx - read_idx;
	} else {
		unsol_read_ctxt[uart].curr_len =
		    unsol_rx->size - read_idx + write_idx;
	}
	unsol_rx->unsol_rx_callback(unsol_rx->cb_data, SEDI_DRIVER_OK,
				    SEDI_UART_IDLE,
				    unsol_read_ctxt[uart].curr_len);
}

static void handle_unsol_rx_error(const sedi_uart_t uart, uint32_t line_status)
{
	const sedi_uart_unsol_rx_t *const unsol_rx =
	    unsol_read_ctxt[uart].unsol_rx;
	unsol_rx->unsol_rx_callback(unsol_rx->cb_data, SEDI_DRIVER_ERROR,
				    line_status,
				    unsol_read_ctxt[uart].curr_len);
}

static bool is_tx_disabled(const sedi_uart_t uart)
{
	return uart_xfer_ctrl[uart].tx_disable;
}

static bool is_rx_disabled(const sedi_uart_t uart)
{
	return uart_xfer_ctrl[uart].rx_disable;
}

void sedi_uart_isr_handler(const sedi_uart_t uart)
{
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	uint8_t interrupt_id = regs->iir_fcr & SEDI_UART_IIR_IID_MASK;
	const sedi_uart_transfer_t *const read_transfer =
	    uart_read_transfer[uart];
	const sedi_uart_transfer_t *const write_transfer =
	    uart_write_transfer[uart];
	uint32_t line_status;

	/*
	 * Interrupt ID priority levels (from highest to lowest):
	 * 1: SEDI_UART_IIR_RECV_LINE_STATUS
	 * 2: SEDI_UART_IIR_RECV_DATA_AVAIL and SEDI_UART_IIR_CHAR_TIMEOUT
	 * 3: SEDI_UART_IIR_THR_EMPTY
	 */
	switch (interrupt_id) {
	/* Spurious interrupt */
	case SEDI_UART_IIR_NO_INTERRUPT_PENDING:
		break;

	case SEDI_UART_IIR_THR_EMPTY:
		if (write_transfer) {
			if (is_write_xfer_complete(uart)) {
				regs->ier_dlh &= ~SEDI_UART_IER_ETBEI;
				/*
				 * At this point the FIFOs are empty, but the
				 * shift
				 * register still is transmitting the last 8
				 * bits. So if
				 * we were to read LSR, it would say the device
				 * is still
				 * busy. Use the SCR Bit 0 to indicate an irq tx
				 * is
				 * complete.
				 */
				regs->scr |= SEDI_UART_SCR_STATUS_UPDATE;
				if (write_transfer->callback) {
					write_transfer->callback(
					    write_transfer->callback_data, 0,
					    SEDI_UART_IDLE, write_pos[uart]);
				}

				if (vec_write_ctxt[uart].active == false) {
					uart_write_transfer[uart] = NULL;
				}
				return;
			}
			/*
			 * If we are starting the transfer then the TX FIFO is
			 * empty.
			 * In that case we set 'count' variable to
			 * SEDI_UART_FIFO_DEPTH
			 * in order to take advantage of the whole FIFO
			 * capacity.
			 */
			int count = (write_pos[uart] == 0)
					? SEDI_UART_FIFO_DEPTH
					: SEDI_UART_FIFO_HALF_DEPTH;
			while (count-- && !is_write_xfer_complete(uart)) {
				regs->rbr_thr_dll =
				    write_transfer->data[write_pos[uart]++];
			}

			/*
			 * Change the threshold level to trigger an interrupt
			 * when the
			 * TX buffer is empty.
			 */
			if (is_write_xfer_complete(uart)) {
				regs->iir_fcr =
				    SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD |
				    SEDI_UART_FCR_FIFOE;
			}
		}
		break;

	case SEDI_UART_IIR_CHAR_TIMEOUT:
	case SEDI_UART_IIR_RECV_DATA_AVAIL:
		if (read_transfer) {
			/*
			 * Copy data from RX FIFO to xfer buffer as long as the
			 * xfer
			 * has not completed and we have data in the RX FIFO.
			 */
			while (!is_read_xfer_complete(uart)) {
				uint32_t lsr = regs->lsr;
				/*
				 * A break condition may cause a line status
				 * interrupt to follow very closely after a
				 * char timeout interrupt, but reading the lsr
				 * effectively clears the pending interrupts so
				 * we issue here the callback
				 * instead, otherwise we would miss it.
				 * NOTE: Returned len is 0 for now, this might
				 * change in the future.
				 */
				if (lsr & status_report_mask[uart]) {
					regs->ier_dlh &= ~(SEDI_UART_IER_ERBFI |
							   SEDI_UART_IER_ELSI);
					if (read_transfer->callback) {
						read_transfer->callback(
						    read_transfer
							->callback_data,
						    SEDI_DRIVER_ERROR,
						    lsr &
						       SEDI_UART_LSR_ERROR_BITS,
						    0);
					}
					uart_read_transfer[uart] = NULL;
					return;
				}
				if (lsr & SEDI_UART_LSR_DR) {
					read_transfer->data[read_pos[uart]++] =
					    regs->rbr_thr_dll;
				} else {
					/* No more data in the RX FIFO. */
					break;
				}
			}

			if (is_read_xfer_complete(uart)) {
				/*
				 * Disable both 'Receiver Data Available' and
				 * 'Receiver Line Status' interrupts.
				 */
				regs->ier_dlh &=
				    ~(SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI);
				if (read_transfer->callback) {
					read_transfer->callback(
					    read_transfer->callback_data, 0,
					    SEDI_UART_IDLE, read_pos[uart]);
				}

				if (vec_read_ctxt[uart].active == false) {
					uart_read_transfer[uart] = NULL;
				}
			}
		} else {
			if (unsol_read_ctxt[uart].enable_unsol_rx) {
				handle_unsol_rx_data(uart);
			}
		}
		break;

	case SEDI_UART_IIR_RECV_LINE_STATUS:

		line_status = regs->lsr & (SEDI_UART_LSR_ADDR_RCVD |
					   SEDI_UART_LSR_ERROR_BITS);
		if (status_report_mask[uart] & line_status) {
			if (read_transfer) {
				regs->ier_dlh &=
				    ~(SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI);
				if (read_transfer->callback) {
					/*
					 * Return the number of bytes read
					 * a zero as a line status error
					 * was detected.
					 */
					read_transfer->callback(
					    read_transfer->callback_data,
					    SEDI_DRIVER_ERROR,
					    (status_report_mask[uart] &
					     line_status),
					    0);
					uart_read_transfer[uart] = NULL;
				}
			} else {
				if (unsol_read_ctxt[uart].enable_unsol_rx) {
					handle_unsol_rx_error(uart,
							      line_status);
				}
			}
		}
		if (line_status & SEDI_UART_LSR_ADDR_RCVD) {
			/* Remove the address from FIFO as address match is
			 * confirmed with hardware address match.
			 */
			regs->rbr_thr_dll;
		}
		break;

	default:
		/* Unhandled interrupt occurred, disable uart interrupts.
		 * and report error.
		 */
		if (read_transfer && read_transfer->callback) {
			regs->ier_dlh &=
			    ~(SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI);
			read_transfer->callback(read_transfer->callback_data,
						SEDI_DRIVER_ERROR,
						SEDI_UART_UNHANDLED_INT, 0);
			uart_read_transfer[uart] = NULL;
		}
		if (write_transfer && write_transfer->callback) {
			regs->ier_dlh &= ~SEDI_UART_IER_ETBEI;
			write_transfer->callback(write_transfer->callback_data,
						 SEDI_DRIVER_ERROR,
						 SEDI_UART_UNHANDLED_INT, 0);
			uart_write_transfer[uart] = NULL;
		}
	}
}

int sedi_uart_set_config(IN sedi_uart_t uart, IN sedi_uart_config_t *cfg)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	int32_t ret;

#if HAS_UART_SOFT_RST
	uart_soft_rst();
#endif

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	volatile uint32_t unused_lsr __attribute__((unused));

	ret = sedi_uart_set_baud_rate(uart, cfg->baud_rate,
			sedi_pm_get_hbw_clock());
	if (ret != SEDI_DRIVER_OK) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	/* Set line parameters. This also unsets the DLAB. */
	regs->lcr = cfg->line_control;

	/* Hardware automatic flow control. */
	regs->mcr = 0;
	if (true == cfg->hw_fc) {
		regs->mcr |= SEDI_UART_MCR_AFCE | SEDI_UART_MCR_RTS;
	}

	/* FIFO's enable and reset, set interrupt threshold. */
	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_RFIFOR | SEDI_UART_FCR_XFIFOR |
	     SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD);

	/* Clear interrupt settings set by bootloader uart init.*/
	regs->ier_dlh = 0;

	/* Enable the programmable fifo threshold interrupt.
	 * NOTE: This changes the interpretation of the THRE bit in LSR.
	 * It indicates FIFO Full status instead of THR Empty.
	 */
	regs->ier_dlh |= SEDI_UART_IER_PTIME;

	/* Clear LSR. */
	unused_lsr = regs->lsr;

	/* Enable both tx and rx in default configuration. */
	uart_xfer_ctrl[uart].tx_disable = false;
	uart_xfer_ctrl[uart].rx_disable = false;

	return SEDI_DRIVER_OK;
}

int sedi_uart_get_status(IN sedi_uart_t uart, OUT uint32_t *const status)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(status != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	uint32_t lsr = regs->lsr;

	*status = (lsr & (SEDI_UART_LSR_OE | SEDI_UART_LSR_PE |
			  SEDI_UART_LSR_FE | SEDI_UART_LSR_BI));

	/*
	 * Check as an IRQ TX completed, if so, the Shift register may still be
	 * busy.An IRQ TX might have completed after we read the lsr.
	 * This will be reflected in the scr.
	 */
	if (regs->scr & SEDI_UART_SCR_STATUS_UPDATE) {
		regs->scr &= ~SEDI_UART_SCR_STATUS_UPDATE;
	} else if (!(lsr & (SEDI_UART_LSR_TEMT))) {
		*status |= SEDI_UART_TX_BUSY;
	}

	if (lsr & SEDI_UART_LSR_DR) {
		*status |= SEDI_UART_RX_BUSY;
	}

	return SEDI_DRIVER_OK;
}

int sedi_uart_write(IN sedi_uart_t uart, IN uint8_t data)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	while (!(regs->lsr & SEDI_UART_LSR_TEMT)) {
	}

	regs->rbr_thr_dll = data;
	/* Wait for transaction to complete. */
	while (!(regs->lsr & SEDI_UART_LSR_TEMT)) {
	}
	return SEDI_DRIVER_OK;
}

int sedi_uart_read(IN sedi_uart_t uart, OUT uint8_t *const data,
		   OUT uint32_t *status)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(data != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(unsol_read_ctxt[uart].enable_unsol_rx == false,
		  SEDI_DRIVER_ERROR_UNSUPPORTED);

	if (is_rx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	uint32_t lsr = regs->lsr;

	while (!(lsr & SEDI_UART_LSR_DR)) {
		lsr = regs->lsr;
	}
	/* Check if there are any errors on the line. */
	if (lsr & status_report_mask[uart]) {
		if (status) {
			*status = (lsr & SEDI_UART_LSR_ERROR_BITS);
		}
		return SEDI_DRIVER_ERROR;
	}
	*data = regs->rbr_thr_dll;

	return SEDI_DRIVER_OK;
}

int sedi_uart_write_non_block(IN sedi_uart_t uart, IN uint8_t data)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->rbr_thr_dll = data;

	return SEDI_DRIVER_OK;
}

int sedi_uart_read_non_block(IN sedi_uart_t uart, OUT uint8_t *const data)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(data != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	if (is_rx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	*data = regs->rbr_thr_dll;

	return SEDI_DRIVER_OK;
}

int sedi_uart_write_buffer(IN sedi_uart_t uart, IN uint8_t *const data,
			   IN uint32_t len)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(data != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	uint32_t write_length = len;
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	uint8_t *d = (uint8_t *)data;

	while (write_length--) {
		/*
		 * Because FCR_FIFOE and IER_PTIME are enabled, LSR_THRE
		 * behaves as a TX FIFO full indicator.
		 */
		while ((regs->lsr & SEDI_UART_LSR_THRE)) {
		}
		regs->rbr_thr_dll = *d;
		d++;
	}
	/* Wait for transaction to complete. */
	while (!(regs->lsr & SEDI_UART_LSR_TEMT)) {
	}
	return SEDI_DRIVER_OK;
}

int sedi_uart_read_buffer(IN sedi_uart_t uart, OUT uint8_t *const data,
			  IN uint32_t req_len, OUT uint32_t *comp_len,
			  OUT uint32_t *status)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(data != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(status != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(comp_len != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(unsol_read_ctxt[uart].enable_unsol_rx == false,
		  SEDI_DRIVER_ERROR_UNSUPPORTED);

	if (is_rx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	uint8_t *d = data;
	uint32_t read_len = req_len;
	uint32_t lsr = 0;
	*comp_len = 0;
	while (read_len--) {
		while (!(lsr & SEDI_UART_LSR_DR)) {
			lsr = regs->lsr;
		}

		*status = (lsr & status_report_mask[uart]);

		if (*status) {
			return SEDI_DRIVER_ERROR;
		}
		*d = regs->rbr_thr_dll;
		(*comp_len)++;
		d++;
		lsr = 0;
	}
	return SEDI_DRIVER_OK;
}

int sedi_uart_write_async(IN sedi_uart_t uart,
			  IN sedi_uart_transfer_t *const xfer)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(uart_write_transfer[uart] == 0, SEDI_DRIVER_ERROR_BUSY);

	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	write_pos[uart] = 0;
	uart_write_transfer[uart] = xfer;

	/* Set threshold. */
	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD);

	/* Enable TX holding reg empty interrupt. */
	regs->ier_dlh |= SEDI_UART_IER_ETBEI;
	return SEDI_DRIVER_OK;
}

int sedi_uart_read_async(IN sedi_uart_t uart,
			 IN sedi_uart_transfer_t *const xfer)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(uart_read_transfer[uart] == 0, SEDI_DRIVER_ERROR_BUSY);

	DBG_CHECK(unsol_read_ctxt[uart].enable_unsol_rx == false,
		  SEDI_DRIVER_ERROR_UNSUPPORTED);

	if (is_rx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	read_pos[uart] = 0;
	uart_read_transfer[uart] = xfer;

	/* Set threshold. */
	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD);

	/*
	 * Enable both 'Receiver Data Available' and 'Receiver
	 * Line Status' interrupts.
	 */
	regs->ier_dlh |= SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI;

	return SEDI_DRIVER_OK;
}

int sedi_uart_async_write_terminate(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	const sedi_uart_transfer_t *const transfer = uart_write_transfer[uart];

	/* No ongoing write transaction to be terminated. */
	if (transfer == NULL) {
		return SEDI_DRIVER_ERROR;
	}

	/* Disable TX holding reg empty interrupt. */
	regs->ier_dlh &= ~SEDI_UART_IER_ETBEI;
	if (transfer) {
		if (transfer->callback) {
			transfer->callback(transfer->callback_data,
					   SEDI_USART_ERROR_CANCELED,
					   SEDI_UART_IDLE, write_pos[uart]);
		}
		uart_write_transfer[uart] = NULL;
		write_pos[uart] = 0;
	}

	return SEDI_DRIVER_OK;
}

int sedi_uart_async_read_terminate(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	const sedi_uart_transfer_t *const transfer = uart_read_transfer[uart];

	/* No ongoing read transaction to be terminated. */
	if (transfer == NULL) {
		return SEDI_DRIVER_ERROR;
	}

	/*
	 * Disable both 'Receiver Data Available' and 'Receiver Line Status'
	 * interrupts.
	 */
	regs->ier_dlh &= ~(SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI);

	if (transfer) {
		if (transfer->callback) {
			transfer->callback(transfer->callback_data,
					   SEDI_USART_ERROR_CANCELED,
					   SEDI_UART_IDLE, read_pos[uart]);
		}
		uart_read_transfer[uart] = NULL;
		read_pos[uart] = 0;
	}
	return SEDI_DRIVER_OK;
}

#if (HAS_UART_RS485_SUPPORT)

int sedi_uart_rs485_set_config(IN sedi_uart_t uart,
			       IN sedi_uart_rs485_config_t *cfg)
{

	uint32_t de_assertion_cycles;
	uint32_t de_deassertion_cycles;
	uint32_t de_re_tat_cycles;
	uint32_t re_de_tat_cycles;

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	DBG_CHECK(cfg != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg->de_assertion_time < SEDI_UART_DE_AT_DT_NS_MAX,
		  SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg->de_deassertion_time < SEDI_UART_DE_AT_DT_NS_MAX,
		  SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg->de_re_tat < SEDI_UART_TAT_NS_MAX,
		  SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg->re_de_tat < SEDI_UART_TAT_NS_MAX,
		  SEDI_DRIVER_ERROR_PARAMETER);

	/* Setting configuration for supporting RS-485 extension. */

	/* Setting the bit enable writes to RS485 registers. */
	regs->tcr |= SEDI_UART_TCR_RS485_EN;

	de_assertion_cycles =
	    (cfg->de_assertion_time / SEDI_UART_SERIAL_CLK_PERIOD_NS);
	de_deassertion_cycles =
	    (cfg->de_deassertion_time / SEDI_UART_SERIAL_CLK_PERIOD_NS);

	/* Set the values of assertion and de-assertion time. */
	regs->det = SEDI_UART_DET_AT_DT_PACK(de_assertion_cycles,
					     de_deassertion_cycles);

	/* Clearing previous values of transfer mode in TCR. */
	regs->tcr &= ~(SEDI_UART_TCR_TRANSFER_MODE_MASK);

	/* The TAT values are valid only in half duplex mode. */
	if (cfg->transfer_mode == SEDI_UART_RS485_XFER_MODE_HALF_DUPLEX) {
		/* Setting the transfer mode in TCR. */
		regs->tcr |=
		    (uint32_t)(SEDI_UART_XFER_MODE_HW_HALF_DUPLEX
			       << (SEDI_UART_TCR_TRANSFER_MODE_OFFSET));

		/* Set the values of de-re and re-de tat.*/
		de_re_tat_cycles =
		    cfg->de_re_tat / SEDI_UART_SERIAL_CLK_PERIOD_NS;
		re_de_tat_cycles =
		    cfg->re_de_tat / SEDI_UART_SERIAL_CLK_PERIOD_NS;
		regs->tat =
		    SEDI_UART_TAT_PACK(de_re_tat_cycles, re_de_tat_cycles);
	} else {
		regs->tcr |=
		    (uint32_t)(SEDI_UART_XFER_MODE_FULL_DUPLEX
			       << (SEDI_UART_TCR_TRANSFER_MODE_OFFSET));
	}

	/* Clearing previous values of DE & RE polarity in TCR. */
	regs->tcr &= ~(SEDI_UART_TCR_RE_POL | SEDI_UART_TCR_DE_POL);
	regs->tcr |= (((cfg->re_polarity) << SEDI_UART_TCR_RE_POL_OFFSET) |
		      ((cfg->de_polarity) << SEDI_UART_TCR_DE_POL_OFFSET));

	/* Enable or disable the driver based on config. */
	regs->de_en = cfg->de_en;

	/* Enable or disable the receiver based on config. */
	regs->re_en = cfg->re_en;

	regs->tcr &= ~(SEDI_UART_TCR_RS485_EN);
	return SEDI_DRIVER_OK;
}

int sedi_uart_rs485_disable(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->tcr &= ~(SEDI_UART_TCR_RS485_EN);
	return SEDI_DRIVER_OK;
}

int sedi_uart_rs485_enable(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->tcr |= (SEDI_UART_TCR_RS485_EN);

	/* Reset rx_fifo right after enable to clear any error conditions
	 * generated as rx line held low when rs485 is not enabled.
	 */
	regs->iir_fcr |= (SEDI_UART_FCR_RFIFOR);
	regs->lsr;
	return SEDI_DRIVER_OK;
}

int sedi_uart_rs485_get_config(IN sedi_uart_t uart,
			       sedi_uart_rs485_config_t *cfg)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	cfg->de_assertion_time = (uint32_t)(
	    ((regs->det & SEDI_UART_DET_AT_MASK) >> SEDI_UART_DET_AT_OFFSET) *
	    SEDI_UART_SERIAL_CLK_PERIOD_NS);

	cfg->de_deassertion_time = (uint32_t)(
	    ((regs->det & SEDI_UART_DET_DT_MASK) >> SEDI_UART_DET_DT_OFFSET) *
	    SEDI_UART_SERIAL_CLK_PERIOD_NS);
	cfg->de_re_tat = (uint32_t)(((regs->tat & SEDI_UART_TAT_DE_RE_MASK) >>
				     SEDI_UART_TAT_DE_RE_OFFSET) *
				    SEDI_UART_SERIAL_CLK_PERIOD_NS);

	cfg->re_de_tat = (uint32_t)(((regs->tat & SEDI_UART_TAT_RE_DE_MASK) >>
				     SEDI_UART_TAT_RE_DE_OFFSET) *
				    SEDI_UART_SERIAL_CLK_PERIOD_NS);

	cfg->transfer_mode = (regs->tcr & SEDI_UART_TCR_TRANSFER_MODE_MASK) >>
			     SEDI_UART_TCR_TRANSFER_MODE_OFFSET;

	if (regs->tcr & (SEDI_UART_TCR_DE_POL)) {
		cfg->de_polarity = SEDI_UART_RS485_POL_ACTIVE_HIGH;
	} else {
		cfg->de_polarity = SEDI_UART_RS485_POL_ACTIVE_LOW;
	}

	if (regs->tcr & (SEDI_UART_TCR_RE_POL)) {
		cfg->re_polarity = SEDI_UART_RS485_POL_ACTIVE_HIGH;
	} else {
		cfg->re_polarity = SEDI_UART_RS485_POL_ACTIVE_LOW;
	}

	cfg->de_en = regs->de_en;
	cfg->re_en = regs->re_en;
	return SEDI_DRIVER_OK;
}

/* Clear the RS485 configuration registers. */
int sedi_uart_rs485_clear_config(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->tcr |= SEDI_UART_TCR_RS485_EN;
	regs->det = 0;
	regs->tat = 0;
	regs->de_en = 0;
	regs->re_en = 0;
	regs->tcr = 0;
	return SEDI_DRIVER_OK;
}

#endif /* HAS_UART_RS485_SUPPORT */

#if (HAS_UART_9BIT_SUPPORT)
int sedi_uart_9bit_set_config(IN sedi_uart_t uart,
			      IN sedi_uart_9bit_config_t *cfg)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->lcr_ext = (SEDI_UART_LCR_EXT_ENABLE_9BIT_MODE);

	if (cfg->addr_ctrl == SEDI_UART_9BIT_HW_ADDR_CTRL) {
		regs->lcr_ext &= ~(SEDI_UART_LCR_EXT_SW_TRANSMIT_MODE);
		regs->rar = (cfg->receive_address &
			     (SEDI_UART_RAR_RECEIVE_ADDRESS_MASK));
		regs->lcr_ext |= (SEDI_UART_LCR_EXT_HW_RECV_ADDRESS_MATCH);
	} else {
		regs->lcr_ext |= (SEDI_UART_LCR_EXT_SW_TRANSMIT_MODE);
		regs->lcr_ext &= ~(SEDI_UART_LCR_EXT_HW_RECV_ADDRESS_MATCH);
	}

	regs->lcr_ext &= ~(SEDI_UART_LCR_EXT_ENABLE_9BIT_MODE);

	return SEDI_DRIVER_OK;
}

int sedi_uart_9bit_disable(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->lcr_ext &= ~(SEDI_UART_LCR_EXT_ENABLE_9BIT_MODE);
	return SEDI_DRIVER_OK;
}

int sedi_uart_9bit_enable(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->lcr_ext |= (SEDI_UART_LCR_EXT_ENABLE_9BIT_MODE);
	return SEDI_DRIVER_OK;
}

int sedi_uart_9bit_send_address(IN sedi_uart_t uart, uint8_t address)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	if (regs->lcr_ext & SEDI_UART_LCR_EXT_ENABLE_9BIT_MODE) {

		if ((regs->lcr_ext & SEDI_UART_LCR_EXT_SW_TRANSMIT_MODE)) {
			regs->rbr_thr_dll = (BIT(8) | (uint32_t)address);

			/* Wait for address to be sent. */
			while (!(regs->lsr & SEDI_UART_LSR_TEMT)) {
			}
		} else {
			regs->tar = address;
			/* Sending the address. */
			regs->lcr_ext |= SEDI_UART_LCR_EXT_SEND_ADDRESS;
			/* Wait for address to be sent. */
			while (regs->lcr_ext & SEDI_UART_LCR_EXT_SEND_ADDRESS)
				;
		}
	} else {
		/* UART not configured for 9 bit operation. */
		return SEDI_DRIVER_ERROR;
	}

	return SEDI_DRIVER_OK;
}

int sedi_uart_9bit_get_config(IN sedi_uart_t uart, sedi_uart_9bit_config_t *cfg)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	/* Address of this  node when hardware address match enabled. */
	cfg->receive_address = regs->rar & SEDI_UART_RAR_RECEIVE_ADDRESS_MASK;

	/* Transmit Addr Ctrl s/w or h/w  enabled address transmit. */
	if (regs->lcr_ext & SEDI_UART_LCR_EXT_SW_TRANSMIT_MODE) {
		cfg->addr_ctrl = SEDI_UART_9BIT_SW_ADDR_CTRL;
	} else {
		cfg->addr_ctrl = SEDI_UART_9BIT_HW_ADDR_CTRL;
	}

	return SEDI_DRIVER_OK;
}

int sedi_uart_read_rx_fifo(IN sedi_uart_t uart, uint16_t *rx_buff,
			   uint16_t *length_read)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(rx_buff != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(length_read != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	if (is_rx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	uint16_t data;
	uint16_t i = 0;
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	uint32_t lsr = regs->lsr;
	*length_read = 0;

	if (!(lsr & SEDI_UART_LSR_DR)) {
		return SEDI_DRIVER_ERROR;
	}

	while ((lsr & SEDI_UART_LSR_DR)) {
		if (lsr & status_report_mask[uart]) {
			return SEDI_DRIVER_ERROR;
		}
		data = regs->rbr_thr_dll;
		rx_buff[i] = data;
		lsr = regs->lsr;
		++i;
	}

	*length_read = i;
	return SEDI_DRIVER_OK;
}

int sedi_uart_9bit_clear_config(IN sedi_uart_t uart)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->rar = 0;
	regs->tar = 0;
	regs->lcr_ext = 0;
	return SEDI_DRIVER_OK;
}
#endif /* HAS_UART_9BIT_SUPPORT */

static void sedi_uart_save_context(IN sedi_uart_t uart)
{

	sedi_uart_reg_t *IN regs = SEDI_UART[uart];
	sedi_uart_context_t *ctx = &uart_context[uart];

	ctx->ier = regs->ier_dlh;
	ctx->lcr = regs->lcr;
	ctx->mcr = regs->mcr;
	ctx->scr = regs->scr;
	ctx->htx = regs->htx;
	ctx->dlf = regs->dlf;
	regs->lcr |= SEDI_UART_LCR_DLAB;
	ctx->dlh = regs->ier_dlh;
	ctx->dll = regs->rbr_thr_dll;
	regs->lcr &= ~SEDI_UART_LCR_DLAB;

#if (HAS_UART_RS485_SUPPORT)
	/* Save registers for RS485 operation. */
	ctx->tcr = regs->tcr;
	ctx->de_en = regs->de_en;
	ctx->re_en = regs->re_en;
	ctx->det = regs->det;
	ctx->tat = regs->tat;
#endif

#if (HAS_UART_9BIT_SUPPORT)
	/* Save registers for 9-bit operation. */
	ctx->rar = regs->rar;
	ctx->tar = regs->tar;
	ctx->lcr_ext = regs->lcr_ext;
#endif
	ctx->context_valid = true;
}

static void sedi_uart_restore_context(IN sedi_uart_t uart)
{
	sedi_uart_context_t *ctx = &uart_context[uart];
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	if (ctx->context_valid == true) {
		uint32_t clk_speed;

#if HAS_UART_SOFT_RST
		uart_soft_rst_instance(uart);
#endif
		clk_speed = sedi_pm_get_hbw_clock();
		sedi_uart_set_baud_rate(uart, baud_rate_cache[uart], clk_speed);

		/* When DLAB is set, DLL and DLH registers can be accessed. */
		regs->ier_dlh = ctx->ier;
		regs->lcr = ctx->lcr;
		regs->mcr = ctx->mcr;
		regs->scr = ctx->scr;
		regs->htx = ctx->htx;

#if (HAS_UART_RS485_SUPPORT)
		/* Restore registers for RS485 operation. */
		regs->tcr |= SEDI_UART_TCR_RS485_EN;
		regs->de_en = ctx->de_en;
		regs->re_en = ctx->re_en;
		regs->det = ctx->det;
		regs->tat = ctx->tat;
		regs->tcr = ctx->tcr;
#endif

#if (HAS_UART_9BIT_SUPPORT)
		/* Restore registers for 9-bit operation. */
		regs->rar = ctx->rar;
		regs->tar = ctx->tar;
		regs->lcr_ext = ctx->lcr_ext;
#endif

		/*
		 * FIFO control register cannot be read back,
		 * default config is applied for this register.
		 * Application will need to restore its own parameters.
		 */
		regs->iir_fcr = (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_RFIFOR |
				 SEDI_UART_FCR_XFIFOR |
				 SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD);
		ctx->context_valid = false;
	}
}

static bool is_tx_fifo_full(sedi_uart_t uart)
{
	/* As fifos are enabled and ptime is enabled the thre bit
	 * acts as a fifo full indicator.
	 */
	return !!(SEDI_UART[uart]->lsr & SEDI_UART_LSR_THRE);
}

bool sedi_uart_irq_tx_ready(IN sedi_uart_t uart)
{
	uint32_t id;

	id = iir_cache[uart] & SEDI_UART_IIR_IID_MASK;
	return id == SEDI_UART_IIR_THR_EMPTY;
}

static bool sedi_is_rx_data_available(sedi_uart_t uart)
{
	return SEDI_UART[uart]->lsr & SEDI_UART_LSR_DR;
}

bool sedi_uart_is_irq_rx_ready(IN sedi_uart_t uart)
{
	uint32_t id = (iir_cache[uart] & SEDI_UART_IIR_IID_MASK);

	return (id == SEDI_UART_IIR_RECV_DATA_AVAIL) ||
	       (id == SEDI_UART_IIR_CHAR_TIMEOUT);
}

bool sedi_uart_is_irq_pending(IN sedi_uart_t uart)
{
	return !(iir_cache[uart] & SEDI_UART_IIR_NO_INTERRUPT_PENDING);
}

int sedi_uart_fifo_fill(IN sedi_uart_t uart, IN uint8_t *data, IN uint32_t size)
{
	uint32_t i;

	if (is_tx_disabled(uart))
		return 0;

	for (i = 0; ((i < size) && (!is_tx_fifo_full(uart))); i++) {
		SEDI_UART[uart]->rbr_thr_dll = data[i];
	}
	return i;
}

int sedi_uart_fifo_read(IN sedi_uart_t uart, OUT uint8_t *data,
			IN uint32_t size)
{
	int i;

	if (is_rx_disabled(uart))
		return 0;

	for (i = 0; i < size && sedi_is_rx_data_available(uart); i++) {
		data[i] = SEDI_UART[uart]->rbr_thr_dll;
	}
	return i;
}

int sedi_uart_irq_tx_enable(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	SEDI_UART[uart]->ier_dlh |= SEDI_UART_IER_ETBEI;
	return SEDI_DRIVER_OK;
}

int sedi_uart_irq_tx_disable(IN sedi_uart_t uart)
{
	SEDI_UART[uart]->ier_dlh &= ~SEDI_UART_IER_ETBEI;
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	return SEDI_DRIVER_OK;
}

bool sedi_uart_is_tx_complete(IN sedi_uart_t uart)
{
	return !!(SEDI_UART[uart]->lsr & SEDI_UART_LSR_TEMT);
}

int sedi_uart_irq_rx_enable(IN sedi_uart_t uart)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	SEDI_UART[uart]->ier_dlh |= SEDI_UART_IER_ERBFI;
	return SEDI_DRIVER_OK;
}

int sedi_uart_irq_rx_disable(IN sedi_uart_t uart)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	SEDI_UART[uart]->ier_dlh &= ~SEDI_UART_IER_ERBFI;
	return SEDI_DRIVER_OK;
}

int sedi_uart_update_irq_cache(IN sedi_uart_t uart)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	iir_cache[uart] = SEDI_UART[uart]->iir_fcr;
	return SEDI_DRIVER_OK;
}

int sedi_uart_irq_err_enable(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	SEDI_UART[uart]->ier_dlh |= SEDI_UART_IER_ELSI;
	return SEDI_DRIVER_OK;
}

int sedi_uart_irq_err_disable(IN sedi_uart_t uart)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	SEDI_UART[uart]->ier_dlh &= ~SEDI_UART_IER_ELSI;
	return SEDI_DRIVER_OK;
}

int sedi_uart_set_baud_rate(IN sedi_uart_t uart, IN uint32_t baud_rate,
			    IN uint32_t clk_speed_hz)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	/* Divisor = clock_speed_hz /(16* baudrate) */
	uint32_t divisor = clk_speed_hz / (baud_rate << 4);

	DBG_CHECK(divisor <= (SEDI_UART_MAX_BAUD_DIVISOR),
		  SEDI_DRIVER_ERROR_PARAMETER);

	uint32_t dlf = (clk_speed_hz % (baud_rate << 4)) / baud_rate;
	uint32_t scaled_dlf =
	    ((clk_speed_hz % (baud_rate << 4)) * SEDI_UART_DLF_SCALAR) /
	    baud_rate;

	dlf = dlf + ((scaled_dlf % SEDI_UART_DLF_SCALAR) >=
		     (SEDI_UART_DLF_SCALAR / 2));

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	/* Store LCR before making changes. */
	uint32_t lcr_saved = regs->lcr;

	/* Set divisor latch registers (integer + fractional part). */
	regs->lcr = SEDI_UART_LCR_DLAB;
	regs->ier_dlh = SEDI_UART_GET_DLH(divisor);
	regs->rbr_thr_dll = SEDI_UART_GET_DLL(divisor);
	regs->dlf = dlf;

	/* Restore the lcr to its previous value. */
	regs->lcr = lcr_saved;
	baud_rate_cache[uart] = baud_rate;
	clk_speed_cache[uart] = clk_speed_hz;
	return SEDI_DRIVER_OK;
}

int sedi_uart_get_config(IN sedi_uart_t uart, OUT sedi_uart_config_t *cfg)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(cfg != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	uint32_t fc_setting;

	cfg->line_control = regs->lcr;
	fc_setting = (regs->mcr & (SEDI_UART_MCR_AFCE | SEDI_UART_MCR_RTS));
	cfg->hw_fc = (fc_setting == (SEDI_UART_MCR_AFCE | SEDI_UART_MCR_RTS));
	cfg->baud_rate = baud_rate_cache[uart];
	cfg->clk_speed_hz = clk_speed_cache[uart];
	return SEDI_DRIVER_OK;
}

/* Set the given UART port to loopback mode. */
int sedi_uart_set_loopback_mode(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	/* Setting to loopback. */
	regs->mcr |= SEDI_UART_MCR_LOOPBACK;
	return SEDI_DRIVER_OK;
}

/* Clear loopback mode */
int sedi_uart_clr_loopback_mode(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	/* Clearing loopback. */
	regs->mcr &= ~(SEDI_UART_MCR_LOOPBACK);
	return SEDI_DRIVER_OK;
}

int sedi_uart_get_loopback_mode(IN sedi_uart_t uart, uint32_t *p_mode)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(p_mode != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	*p_mode = !!(regs->mcr & (SEDI_UART_MCR_LOOPBACK));
	return SEDI_DRIVER_OK;
}

/* Generate Break condition */
int sedi_uart_set_break_con(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->lcr |= SEDI_UART_LCR_BREAK;
	return SEDI_DRIVER_OK;
}

/* Clear Break condition */
int sedi_uart_clr_break_con(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->lcr &= ~SEDI_UART_LCR_BREAK;
	return SEDI_DRIVER_OK;
}

/* Enable auto flow control */
int sedi_uart_auto_fc_enable(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->mcr |= (SEDI_UART_MCR_AFCE | SEDI_UART_MCR_RTS);
	return SEDI_DRIVER_OK;
}

/* Disable auto flow control */
int sedi_uart_auto_fc_disable(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->mcr &= ~(SEDI_UART_MCR_AFCE | SEDI_UART_MCR_RTS);
	return SEDI_DRIVER_OK;
}

int sedi_set_ln_status_report_mask(IN sedi_uart_t uart, IN uint32_t mask)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	status_report_mask[uart] = mask;
	return SEDI_DRIVER_OK;
}

int sedi_uart_enable_unsol_rx(IN sedi_uart_t uart,
			      IN sedi_uart_unsol_rx_t *const unsol_rx)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(unsol_rx != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(unsol_rx->buffer != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(unsol_rx->size != 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(unsol_rx->unsol_rx_callback != NULL,
		  SEDI_DRIVER_ERROR_PARAMETER);

	if (is_rx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	/* Report error if there is an ongoing async read. */
	if (uart_read_transfer[uart]) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	/* Setting initial conditions for read and write index */
	unsol_read_ctxt[uart].read_idx = -1;
	unsol_read_ctxt[uart].write_idx = -1;
	unsol_read_ctxt[uart].curr_len = 0;
	unsol_read_ctxt[uart].unsol_rx = unsol_rx;

	unsol_read_ctxt[uart].enable_unsol_rx = true;

	/* Enable receive data available interrupt */
	SEDI_UART[uart]->ier_dlh |= (SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI);
	return SEDI_DRIVER_OK;
}

int sedi_uart_disable_unsol_rx(IN sedi_uart_t uart)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	if (uart_read_transfer[uart]) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	if (!unsol_read_ctxt[uart].enable_unsol_rx) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	SEDI_UART[uart]->ier_dlh &= ~(SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI);

	unsol_read_ctxt[uart].enable_unsol_rx = false;
	unsol_read_ctxt[uart].unsol_rx = NULL;
	return SEDI_DRIVER_OK;
}

int sedi_uart_get_unsol_data(IN sedi_uart_t uart, uint8_t *buffer, int len)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(buffer != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	if (!unsol_read_ctxt[uart].enable_unsol_rx) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	int i, count = 0, start_idx, end_idx;
	int read_comp = 0;
	const sedi_uart_unsol_rx_t *const unsol_rx =
	    unsol_read_ctxt[uart].unsol_rx;

	if ((len == 0) || (len > unsol_read_ctxt[uart].curr_len + 1)) {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	SEDI_UART[uart]->ier_dlh &= ~(SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI);

	/* read_idx is the last read location so adding 1 for next valid
	 * location, similarly write_idx is the last written location thus
	 * adding 1 for getting the end condition.
	 */
	start_idx = unsol_read_ctxt[uart].read_idx + 1;
	end_idx = unsol_read_ctxt[uart].write_idx + 1;
	if (start_idx < end_idx) {
		for (i = start_idx; i < end_idx; i++) {
			buffer[count++] = unsol_rx->buffer[i];
			if (count == len) {
				break;
			}
		}

	} else {
		for (i = start_idx; i < unsol_rx->size; i++) {
			buffer[count++] = unsol_rx->buffer[i];
			if (count == len) {
				read_comp = true;
				break;
			}
		}
		if (!read_comp) {
			for (i = 0; i < end_idx; i++) {
				buffer[count++] = unsol_rx->buffer[i];
				if (count == len) {
					break;
				}
			}
		}
	}

	/* Update the read idx to last read location. */
	unsol_read_ctxt[uart].read_idx =
	    (unsol_read_ctxt[uart].read_idx + len) % unsol_rx->size;
	unsol_read_ctxt[uart].curr_len = (unsol_read_ctxt[uart].curr_len - len);

	/* Enable receive data available interrupt */
	SEDI_UART[uart]->ier_dlh |= (SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI);

	return SEDI_DRIVER_OK;
}

int sedi_uart_get_unsol_data_len(sedi_uart_t uart, int *p_len)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(p_len != NULL, SEDI_DRIVER_ERROR_PARAMETER);

	if (!unsol_read_ctxt[uart].enable_unsol_rx) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	*p_len = unsol_read_ctxt[uart].curr_len;
	return SEDI_DRIVER_OK;
}

int sedi_get_ln_status_report_mask(IN sedi_uart_t uart, OUT uint32_t *p_mask)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(p_mask != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	*p_mask = status_report_mask[uart];
	return SEDI_DRIVER_OK;
}

int sedi_uart_assert_rts(IN sedi_uart_t uart)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	if (regs->mcr & SEDI_UART_MCR_AFCE) {
		return SEDI_DRIVER_ERROR;
	}

	regs->mcr |= SEDI_UART_MCR_RTS;
	return SEDI_DRIVER_OK;
}
int sedi_uart_de_assert_rts(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	if (regs->mcr & SEDI_UART_MCR_AFCE) {
		return SEDI_DRIVER_ERROR;
	}

	regs->mcr &= ~(SEDI_UART_MCR_RTS);
	return SEDI_DRIVER_OK;
}

int sedi_uart_read_rts(IN sedi_uart_t uart, uint32_t *p_rts)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	*p_rts = !!(regs->mcr & SEDI_UART_MCR_RTS);
	return SEDI_DRIVER_OK;
}

int sedi_uart_read_cts(IN sedi_uart_t uart, OUT uint32_t *p_cts)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	*p_cts = !!(regs->msr & SEDI_UART_MSR_CTS);
	return SEDI_DRIVER_OK;
}

int sedi_uart_write_vec_async(IN sedi_uart_t uart,
			      IN sedi_uart_io_vec_xfer_t *const vec_xfer)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(vec_xfer != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(vec_xfer->count != 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(uart_write_transfer[uart] == 0, SEDI_DRIVER_ERROR_BUSY);

	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	vec_write_ctxt[uart].vec = vec_xfer;
	write_pos[uart] = 0;
	vec_write_ctxt[uart].curr_count = 0;
	vec_write_ctxt[uart].active = true;

	/* Initiate transfer with the first member of the vector. */
	vec_write_ctxt[uart].xfer.data = vec_xfer->vec[0].base;
	vec_write_ctxt[uart].xfer.data_len = vec_xfer->vec[0].len;
	vec_write_ctxt[uart].xfer.callback_data = (void *)uart;
	vec_write_ctxt[uart].xfer.callback = io_vec_write_callback;

	uart_write_transfer[uart] = &vec_write_ctxt[uart].xfer;

	/* Set threshold. */
	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD);

	/* Enable TX holding reg empty interrupt. */
	regs->ier_dlh |= SEDI_UART_IER_ETBEI;
	return SEDI_DRIVER_OK;
}

int sedi_uart_read_vec_async(IN sedi_uart_t uart,
			     IN sedi_uart_io_vec_xfer_t *const vec_xfer)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(vec_xfer != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(vec_xfer->count != 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(uart_read_transfer[uart] == 0, SEDI_DRIVER_ERROR_BUSY);

	if (is_rx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	vec_read_ctxt[uart].vec = vec_xfer;
	read_pos[uart] = 0;
	vec_read_ctxt[uart].curr_count = 0;
	vec_read_ctxt[uart].active = true;

	/* Initiate transfer with the first member of the vector. */
	vec_read_ctxt[uart].xfer.data = vec_xfer->vec[0].base;
	vec_read_ctxt[uart].xfer.data_len = vec_xfer->vec[0].len;
	vec_read_ctxt[uart].xfer.callback_data = (void *)uart;
	vec_read_ctxt[uart].xfer.callback = io_vec_read_callback;
	uart_read_transfer[uart] = &vec_read_ctxt[uart].xfer;

	/* Set threshold. */
	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_TX_0_RX_1_2_THRESHOLD);

	/*
	 * Enable both 'Receiver Data Available' and 'Receiver
	 * Line Status' interrupts.
	 */
	regs->ier_dlh |= SEDI_UART_IER_ERBFI | SEDI_UART_IER_ELSI;

	return SEDI_DRIVER_OK;
}

/* UART DMA functions. */
static int sedi_uart_dma_config(IN sedi_dma_t dma, int32_t channel,
				IN sedi_dma_event_cb_t cb, void *param,
				dma_operation_type_t op)
{
	int32_t ret = 0;

	PARAM_UNUSED(ret);

	ret = sedi_dma_init(dma, channel, cb, param);
	DBG_CHECK(SEDI_DRIVER_OK == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_set_power(dma, channel, SEDI_POWER_FULL);
	DBG_CHECK(SEDI_DRIVER_OK == ret, SEDI_DRIVER_ERROR);

	if (op == READ) {
		ret =
		    sedi_dma_control(dma, channel, SEDI_CONFIG_DMA_BURST_LENGTH,
				     DMA_BURST_TRANS_LENGTH_1);
	} else if (op == WRITE) {
		ret =
		    sedi_dma_control(dma, channel, SEDI_CONFIG_DMA_BURST_LENGTH,
				     DMA_BURST_TRANS_LENGTH_32);
	} else {
		return SEDI_DRIVER_ERROR_PARAMETER;
	}

	DBG_CHECK(SEDI_DRIVER_OK == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, channel, SEDI_CONFIG_DMA_SR_TRANS_WIDTH,
			       DMA_TRANS_WIDTH_8);
	DBG_CHECK(SEDI_DRIVER_OK == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, channel, SEDI_CONFIG_DMA_DT_TRANS_WIDTH,
			       DMA_TRANS_WIDTH_8);
	DBG_CHECK(SEDI_DRIVER_OK == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma, channel, SEDI_CONFIG_DMA_HS_POLARITY,
			       DMA_HS_POLARITY_HIGH);

	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	return SEDI_DRIVER_OK;
}

static int sedi_uart_dma_io_async(sedi_uart_t uart,
				  const sedi_uart_dma_xfer_t *const xfer,
				  dma_operation_type_t op)
{
	int32_t ret;
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	dma_channel_direction_t dma_dir;
	dma_hs_per_rtx_t dma_hs_per;
	uint32_t src, dst;

	if (op == WRITE) {
		dma_write_ctxt[uart].dma_xfer = xfer;
		ret = sedi_uart_dma_config(
		    xfer->dma_dev, xfer->channel, sedi_dma_event_cb,
		    (void *)(&dma_write_ctxt[uart]), WRITE);
		if (ret != SEDI_DRIVER_OK) {
			return ret;
		}
		dma_dir = DMA_MEMORY_TO_PERIPHERAL;
		dma_hs_per = DMA_HS_PER_TX;
		src = (uint32_t)xfer->data;
		dst = (uint32_t)(&regs->rbr_thr_dll);
	} else if (op == READ) {
		dma_read_ctxt[uart].dma_xfer = xfer;
		ret = sedi_uart_dma_config(
		    xfer->dma_dev, xfer->channel, sedi_dma_event_cb,
		    (void *)(&dma_read_ctxt[uart]), READ);
		if (ret != SEDI_DRIVER_OK) {
			return ret;
		}
		dma_dir = DMA_PERIPHERAL_TO_MEMORY;
		dma_hs_per = DMA_HS_PER_RX;
		dst = (uint32_t)xfer->data;
		src = (uint32_t)(&regs->rbr_thr_dll);
		regs->dmasa |= SEDI_UART_DMASA;
	} else {
		return SEDI_DRIVER_ERROR;
	}

	ret = sedi_dma_control(xfer->dma_dev, xfer->channel,
			       SEDI_CONFIG_DMA_HS_DEVICE_ID,
			       uart_dma_hs_id[uart]);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret =
	    sedi_dma_control(xfer->dma_dev, xfer->channel,
			     SEDI_CONFIG_DMA_HS_DEVICE_ID_PER_DIR, dma_hs_per);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(xfer->dma_dev, xfer->channel,
			       SEDI_CONFIG_DMA_DIRECTION, dma_dir);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_DEFAULT_TX_RX_THRESHOLD);
	ret = sedi_dma_start_transfer(xfer->dma_dev, xfer->channel, src, dst,
				      xfer->len);
	return ret;
}

static int sedi_uart_dma_io_polled(sedi_uart_t uart, sedi_dma_t dma_dev,
				   uint32_t channel, const uint8_t *buff,
				   uint32_t length, dma_operation_type_t op)
{
	int ret;
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
	dma_channel_direction_t dma_dir;
	dma_hs_per_rtx_t dma_hs_per;
	uint32_t src, dst;

	if (op == WRITE) {
		dma_dir = DMA_MEMORY_TO_PERIPHERAL;
		dma_hs_per = DMA_HS_PER_TX;
		src = (uint32_t)buff;
		dst = (uint32_t)(&regs->rbr_thr_dll);
	} else if (op == READ) {
		dma_dir = DMA_PERIPHERAL_TO_MEMORY;
		dma_hs_per = DMA_HS_PER_RX;
		dst = (uint32_t)buff;
		src = (uint32_t)(&regs->rbr_thr_dll);
		regs->dmasa |= SEDI_UART_DMASA;
	} else {
		return SEDI_DRIVER_ERROR;
	}

	ret = sedi_uart_dma_config(dma_dev, channel, sedi_dma_poll_dummy_cb,
				   NULL, op);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}
	ret = sedi_dma_control(dma_dev, channel, SEDI_CONFIG_DMA_HS_DEVICE_ID,
			       uart_dma_hs_id[uart]);

	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(
	    dma_dev, channel, SEDI_CONFIG_DMA_HS_DEVICE_ID_PER_DIR, dma_hs_per);
	DBG_CHECK(0 == ret, SEDI_DRIVER_ERROR);

	ret = sedi_dma_control(dma_dev, channel, SEDI_CONFIG_DMA_DIRECTION,
			       dma_dir);
	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}

	regs->iir_fcr =
	    (SEDI_UART_FCR_FIFOE | SEDI_UART_FCR_DEFAULT_TX_RX_THRESHOLD);

	ret =
	    sedi_dma_start_transfer_polling(dma_dev, channel, src, dst, length);

	if (ret != SEDI_DRIVER_OK) {
		return ret;
	}
	/* wait for transfer to complete */
	if (op == WRITE) {
		while (!(regs->lsr & SEDI_UART_LSR_TEMT)) {
		}
	}

	return SEDI_DRIVER_OK;
}

int sedi_uart_dma_write_async(IN sedi_uart_t uart,
			      IN sedi_uart_dma_xfer_t *const xfer)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer->dma_dev < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer->data != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer->callback != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	int32_t ret;

	ret = sedi_uart_dma_io_async(uart, xfer, WRITE);
	return ret;
}

int sedi_uart_dma_write_terminate(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	const sedi_uart_dma_xfer_t *xfer = dma_write_ctxt[uart].dma_xfer;
	int ret;

	/* No ongoing write transaction to be terminated. */
	if (xfer == NULL) {
		return SEDI_DRIVER_ERROR;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->dmasa |= SEDI_UART_DMASA;

	ret = sedi_dma_set_power(xfer->dma_dev, xfer->channel, SEDI_POWER_OFF);
	DBG_CHECK(SEDI_DRIVER_OK == ret, SEDI_DRIVER_ERROR);
	ret = sedi_dma_uninit(xfer->dma_dev, xfer->channel);
	if (xfer->callback && (ret == SEDI_DRIVER_OK)) {
		xfer->callback(xfer->cb_param, SEDI_USART_ERROR_CANCELED, 0, 0);
		dma_write_ctxt[uart].dma_xfer = NULL;
	}

	return ret;
}

int sedi_uart_dma_read_async(IN sedi_uart_t uart,
			     IN sedi_uart_dma_xfer_t *const xfer)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer->dma_dev < SEDI_DMA_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer->data != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(xfer->callback != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	if (is_rx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	int32_t ret;

	ret = sedi_uart_dma_io_async(uart, xfer, READ);
	return ret;
}

int sedi_uart_dma_read_terminate(IN sedi_uart_t uart)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	const sedi_uart_dma_xfer_t *xfer = dma_read_ctxt[uart].dma_xfer;
	int ret;

	/* No ongoing read transaction to be terminated. */
	if (xfer == NULL) {
		return SEDI_DRIVER_ERROR;
	}

	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	regs->dmasa |= SEDI_UART_DMASA;

	ret = sedi_dma_set_power(xfer->dma_dev, xfer->channel, SEDI_POWER_OFF);
	DBG_CHECK(SEDI_DRIVER_OK == ret, SEDI_DRIVER_ERROR);
	ret = sedi_dma_uninit(xfer->dma_dev, xfer->channel);
	if (xfer->callback && (ret == SEDI_DRIVER_OK)) {
		xfer->callback(xfer->cb_param, SEDI_USART_ERROR_CANCELED, 0, 0);
		dma_read_ctxt[uart].dma_xfer = NULL;
	}

	return ret;
}

int sedi_uart_dma_write_polled(IN sedi_uart_t uart, IN sedi_dma_t dma_dev,
			       IN uint32_t channel, IN uint8_t *buff,
			       IN uint32_t length)
{
	int ret;

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(buff != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(length != 0, SEDI_DRIVER_ERROR_PARAMETER);
	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}

	ret = sedi_uart_dma_io_polled(uart, dma_dev, channel, buff, length,
				      WRITE);
	return ret;
}

int sedi_uart_dma_read_polled(IN sedi_uart_t uart, IN sedi_dma_t dma_dev,
			      IN uint32_t channel, OUT uint8_t *buff,
			      IN uint32_t length, OUT uint32_t *status)
{
	int ret;

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(buff != NULL, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(length != 0, SEDI_DRIVER_ERROR_PARAMETER);
	DBG_CHECK(status != 0, SEDI_DRIVER_ERROR_PARAMETER);
	if (is_tx_disabled(uart)) {
		return SEDI_DRIVER_ERROR_UNSUPPORTED;
	}
	sedi_uart_reg_t *const regs = SEDI_UART[uart];

	ret = sedi_uart_dma_io_polled(uart, dma_dev, channel,
			buff, length, READ);
	*status = (regs->lsr & SEDI_UART_LSR_ERROR_BITS);
	return ret;
}

int sedi_uart_set_tx_only_mode(IN sedi_uart_t uart, bool tx_only)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
#if (HAS_UART_RS485_SUPPORT)
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
#endif

	if (tx_only) {
		uart_xfer_ctrl[uart].tx_disable = false;
		uart_xfer_ctrl[uart].rx_disable = true;

#if (HAS_UART_RS485_SUPPORT)
		regs->de_en = true;
		regs->re_en = false;
#endif
	} else {
		uart_xfer_ctrl[uart].tx_disable = false;
		uart_xfer_ctrl[uart].rx_disable = false;

#if (HAS_UART_RS485_SUPPORT)
		regs->de_en = true;
		regs->re_en = true;
#endif
	}
	return SEDI_DRIVER_OK;
}

int sedi_uart_set_rx_only_mode(IN sedi_uart_t uart, bool rx_only)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);
#if (HAS_UART_RS485_SUPPORT)
	sedi_uart_reg_t *const regs = SEDI_UART[uart];
#endif

	if (rx_only) {
		uart_xfer_ctrl[uart].tx_disable = true;
		uart_xfer_ctrl[uart].rx_disable = false;

#if (HAS_UART_RS485_SUPPORT)
		regs->de_en = false;
		regs->re_en = true;
#endif
	} else {
		uart_xfer_ctrl[uart].tx_disable = false;
		uart_xfer_ctrl[uart].rx_disable = false;

#if (HAS_UART_RS485_SUPPORT)
		regs->de_en = true;
		regs->re_en = true;
#endif
	}

	return SEDI_DRIVER_OK;
}

static void sedi_uart_disable_tx_rx(IN sedi_uart_t uart)
{
	uart_xfer_ctrl[uart].tx_disable = true;
	uart_xfer_ctrl[uart].rx_disable = true;
}

static void sedi_uart_enable_tx_rx(IN sedi_uart_t uart)
{
	uart_xfer_ctrl[uart].tx_disable = false;
	uart_xfer_ctrl[uart].rx_disable = false;
}

int32_t sedi_uart_set_power(IN sedi_uart_t uart, IN sedi_power_state_t state)
{

	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	sedi_devid_t id = SEDI_DEVID_UART0 + uart;
	int32_t ret = SEDI_DRIVER_OK;

	switch (state) {
	case SEDI_POWER_FULL:

		/* Enable clocks */
		sedi_pm_set_device_power(id, state);
		sedi_uart_restore_context(uart);
		sedi_uart_enable_tx_rx(uart);
		break;

	case SEDI_POWER_SUSPEND:
		/* Disable both tx and rx in configuration. */
		sedi_uart_disable_tx_rx(uart);
		sedi_uart_save_context(uart);
		sedi_pm_set_device_power(id, state);
		break;

	case SEDI_POWER_FORCE_SUSPEND:
		sedi_uart_disable_tx_rx(uart);
		sedi_pm_set_device_power(id, state);
		break;

	case SEDI_POWER_LOW:

		sedi_uart_disable_tx_rx(uart);
		/* Clock gating for uart */
		sedi_pm_set_device_power(id, state);
		break;

	case SEDI_POWER_OFF:
		ret = SEDI_DRIVER_ERROR_UNSUPPORTED;
		break;
	}
	return ret;
}

int32_t sedi_uart_init(IN sedi_uart_t uart, void *base)
{
	DBG_CHECK(uart < SEDI_UART_NUM, SEDI_DRIVER_ERROR_PARAMETER);

	sedi_uart[uart] = (sedi_uart_reg_t *)base;

	return SEDI_DRIVER_OK;
}
