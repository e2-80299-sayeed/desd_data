/*
 * extint.c
 *
 *  Created on: Oct 3, 2023
 *      Author: sunbeam
 */
#include"extint.h"
#include"led.h"

void extint_init(void)
{
	//1. set GPIOA.0 pin as input
	RCC->AHB1ENR |= BV(GPIOA_CLK_ENB);
	GPIO_SWITCH->MODER &= ~(BV(0) | BV(1));
	GPIO_SWITCH->PUPDR &= ~(BV(0) | BV(1));

	//2. enable external interrupt in system configuration(STM32F407VG)
	SYSCFG->EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3));
	//3. enable ext interrupt in external interrupt controller
	EXTI->IMR |= BV(0);
	EXTI->RTSR |= BV(0);

	//4. enable ext interrupt in NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void)
{
	// clear pending bit into PR register
	EXTI->PR |= BV(0);
	// led blink
	led_blink(LED_RED);
}




