#ifndef __UART_H
#define __UART_H

#include "LPC17xx.h"

#define		LCR_DL0		0
#define		LCR_DL1		1
#define		LCR_STOP	2
#define		LCR_PAREN	3
#define		LCR_DLAB	7

#define		LSR_RDR		0
#define		LSR_THRE	5

#define		FCR_EN		0

void uart_init(uint32_t baud);
char uart_getch(void);
void uart_putch(char ch);
void uart_gets(char str[]);
void uart_puts(char str[]);

#endif

