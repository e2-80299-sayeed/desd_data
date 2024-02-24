#include "uart.h"

void uart_init(uint32_t baud)
{
	uint16_t dl;
	// use P0.0 & P0.1 as UART3 pins - PINSEL0
	LPC_PINCON->PINSEL0 &= ~(BV(3) | BV(2) | BV(1) | BV(0));
	LPC_PINCON->PINSEL0 |= BV(3) | BV(1);

	// config UART - 8-bits, No parity, 1-stop bits - LCR
	LPC_UART3->LCR = BV(LCR_DLAB) | BV(LCR_DL0) | BV(LCR_DL1);

	// calculate dl - dl = (PCLK>>4)/baud
	dl = (PCLK >> 4)/baud;

	// set dl - DLL & DLM (to set ensure DLAB=1)	
	LPC_UART3->DLL = dl & 0x00FF;
	LPC_UART3->DLM = dl >> 8;
	LPC_UART3->LCR &= ~BV(LCR_DLAB);
}

char uart_getch(void)
{
	char ch;
	// check if data is available to read (LSR) & wait if not.
	while( (LPC_UART3->LSR & BV(LSR_RDR)) == 0 )
		;
	// read the data (RBR)	
	ch = LPC_UART3->RBR;
	return ch;
}

void uart_putch(char ch)
{
	// check if last data is transferred (LSR) & waif if not.
	while( (LPC_UART3->LSR & BV(LSR_THRE)) == 0 )
		;
	// write the data (THR)
	LPC_UART3->THR = ch;
}

void uart_puts(char str[])
{
	int i;
	for(i=0; str[i] != '\0'; i++)
		uart_putch(str[i]);
}

void uart_gets(char str[])
{
	int i=0;
	char ch;
	do {
		ch = uart_getch();
		str[i++] = ch;
	} while(ch != '\r');
	str[i++] = '\n';
	str[i] = '\0';
}



