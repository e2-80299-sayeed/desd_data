/*
 * uart.h
 *
 *  Created on: Nov 10, 2021
 *      Author: sunbeam
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"

#define USART		USART2
#define USART_IRQn	USART2_IRQn

#define USART_GPIO		GPIOA
#define USART_TX_PIN	2
#define USART_RX_PIN	3
#define USART_AFR		GPIOA->AFR[0]
#define USART_ALT_FN	7

// default STM32 clock settings
#define PCLK			16000000UL

#define BAUD_9600		9600
#define BAUD_38400		38400
#define BAUD_115200		115200

#define BRR_9600_Val	0x683
#define BRR_38400_Val	0x1A1
#define BRR_115200_Val	0x8B

void UsartGpioInit(void);
void UsartBusInit(uint32_t baud);
void UsartInit(uint32_t baud);

void UsartPutch(int ch);
void UsartPuts(char *str);

//int UsartGetch(void);

#endif /* UART_H_ */





