/*
 * uart.c
 *
 *  Created on: Nov 10, 2021
 *      Author: sunbeam
 */
#include <stdio.h>
#include "uart.h"

static char *tx_string = NULL;
static int tx_index = 0;
static volatile int tx_complete = 1;

void UsartGpioInit(void) {
	// usart gpio config
	// enable gpio clock
	RCC->AHB1ENR |= BV(RCC_AHB1ENR_GPIOAEN_Pos);
	// set gpio altfn for PA.2 & PA.3 = 0x07
	USART_AFR = (USART_ALT_FN << GPIO_AFRL_AFSEL3_Pos) | (USART_ALT_FN << GPIO_AFRL_AFSEL2_Pos);
	// set gpio mode as alt (10)
	USART_GPIO->MODER &= ~(BV(USART_TX_PIN*2) | BV(USART_RX_PIN*2));
	USART_GPIO->MODER |= BV(USART_TX_PIN*2 + 1) | BV(USART_RX_PIN*2 + 1);
	// set gpio speed as low (00)
	USART_GPIO->OSPEEDR &= ~(BV(USART_TX_PIN*2+1) | BV(USART_TX_PIN*2) | BV(USART_RX_PIN*2+1) | BV(USART_RX_PIN*2));
	// set push-pull type (0)
	USART_GPIO->OTYPER &= ~(BV(USART_TX_PIN) | BV(USART_RX_PIN));
	// set no pull-up and pull-down resistor (00)
	USART_GPIO->PUPDR &= ~(BV(USART_TX_PIN*2+1) | BV(USART_TX_PIN*2) | BV(USART_RX_PIN*2+1) | BV(USART_RX_PIN*2));
}

void UsartBusInit(uint32_t baud) {
	// usart config
	// enable usart clock
	RCC->APB1ENR |= BV(RCC_APB1ENR_USART2EN_Pos);
	// enable usart tx (TE=1), rx (RE=1), word len=8 (M=0), parity=off (PCE=0), oversampling by 16 (OVER8=0) -- CR1
	USART->CR1 = BV(USART_CR1_TE_Pos) | BV(USART_CR1_RE_Pos);
	// one stop bit, no clock (clock is for usart not uart) -- CR2
	USART->CR2 = 0x00;
	// no hw flow control, no dma, no interrupt enable -- CR3
	USART->CR3 = 0x00;
	// config baud rate
	if(baud == BAUD_9600)
		USART->BRR = BRR_9600_Val;
	else if(baud == BAUD_38400)
		USART->BRR = BRR_38400_Val;
	else //if(baud == BAUD_115200)
		USART->BRR = BRR_115200_Val;
	// enable uart
	USART->CR1 |= BV(USART_CR1_UE_Pos);
}

void UsartInit(uint32_t baud) {
	UsartGpioInit();
	UsartBusInit(baud);
	// Enable Usart interrupt in NVIC
	NVIC_EnableIRQ(USART_IRQn);
}

void UsartPuts(char *str) {
	// wait for last string to be transmitted
	while(tx_complete == 0)
		;
	// store str into a global pointer
	tx_string = str;
	tx_index = 0;
	tx_complete = 0;
	// Enable Usart interrupt in Peri
	USART->CR1 |= BV(USART_CR1_TXEIE_Pos);
}


void USART2_IRQHandler(void) {
	char ch;
	// acknowledge the interrupt -- identify the interrupt
	if((USART->CR1 & BV(USART_CR1_TXEIE_Pos)) && (USART->SR & BV(USART_SR_TXE_Pos)))
	{
		// handle the TXE interrupt -- send next char
		ch = tx_string[tx_index];
		if(ch != '\0') {
			USART->DR = ch;
			tx_index++;
		} else {
			tx_complete = 1;
			tx_string = NULL;
			USART->CR1 &= ~BV(USART_CR1_TXEIE_Pos);
		}
	}
	if((USART->CR1 & BV(USART_CR1_RXNEIE_Pos)) && (USART->SR & BV(USART_SR_RXNE_Pos)))
	{
		// handle the RXNE interrupt -- get the next char
	}
}

/*
void UsartPutch(int ch) {
	// wait for last char to transmit
	while((USART->SR & BV(USART_SR_TXE_Pos)) == 0)
		;
	// write the char
	USART->DR = ch & 0x000000FF;
}

int UsartGetch(void) {
	int ch;
	// wait for char to receive
	while((USART->SR & BV(USART_SR_RXNE_Pos)) == 0)
		;
	// read the char
	ch = USART->DR;
	return ch;
}
*/
