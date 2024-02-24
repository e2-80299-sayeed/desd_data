/*
 * switch.c
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */
#include"switch.h"

void switch_init(uint16_t pin)
{
	// enable clock for GPIO A Port
	RCC->AHB1ENR |= BV(GPIOA_CLK_ENB);

	// select mode of GPIOA as input
	SWITCH_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));

	// disable internal pull up/ pull down resistor
	SWITCH_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
}
uint16_t switch_status(uint16_t pin)
{
	return SWITCH_GPIO->IDR & BV(pin) ? 1 : 0;
}
