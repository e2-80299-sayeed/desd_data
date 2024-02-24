/*
 * led.c
 *
 *  Created on: 19-May-2022
 *      Author: nilesh
 */

#ifndef LED_C_
#define LED_C_

#include "led.h"

void LedInit(uint32_t pin) {
	// enable GPIO clock
	RCC->AHB1ENR |= BV(AHB1ENR_LEDGPIO_EN);
	// set GPIO mode as output
	//LED_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	//LED_GPIO->MODER |= BV(pin * 2);
	BB_ALS(&LED_GPIO->MODER, pin * 2) = 1;
	BB_ALS(&LED_GPIO->MODER, pin * 2 + 1) = 0;
	// set GPIO speed as low
	//LED_GPIO->OSPEEDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	BB_ALS(&LED_GPIO->OSPEEDR, pin * 2) = 0;
	BB_ALS(&LED_GPIO->OSPEEDR, pin * 2 + 1) = 0;
	// set GPIO output type as push-pull
	//LED_GPIO->OTYPER &= ~BV(pin);
	BB_ALS(&LED_GPIO->OTYPER, pin) = 0;
	// set GPIO pupd as none
	//LED_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	BB_ALS(&LED_GPIO->PUPDR, pin * 2) = 0;
	BB_ALS(&LED_GPIO->PUPDR, pin * 2 + 1) = 0;
}

void LedOn(uint32_t pin) {
	// make pin high
	//LED_GPIO->ODR |= BV(pin);
	BB_ALS(&LED_GPIO->ODR, pin) = 1;
}

void LedOff(uint32_t pin) {
	// make pin low
	//LED_GPIO->ODR &= ~BV(pin);
	BB_ALS(&LED_GPIO->ODR, pin) = 0;
}

void LedBlink(uint32_t pin, uint32_t ms) {
	LedOn(pin);
	DelayMs(ms);
	LedOff(pin);
}

#endif /* LED_C_ */
