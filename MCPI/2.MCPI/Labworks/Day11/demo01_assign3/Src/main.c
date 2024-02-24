/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void LedInit(void) {
	// enable GPIO clock
	RCC->AHB1ENR |= BV(3);
	// set GPIO mode as output
	GPIOD->MODER &= ~(BV(24) | BV(25) | BV(26) | BV(27) | BV(28) | BV(29) | BV(30) | BV(31));
	GPIOD->MODER |= BV(24) | BV(26) | BV(28) | BV(30);
	// set GPIO speed as low
	GPIOD->OSPEEDR &= ~(BV(24) | BV(25) | BV(26) | BV(27) | BV(28) | BV(29) | BV(30) | BV(31));
	// set GPIO output type as push-pull
	GPIOD->OTYPER &= ~(BV(15) | BV(14) | BV(13) | BV(12));
	// set GPIO pupd as none
	GPIOD->PUPDR &= ~(BV(24) | BV(25) | BV(26) | BV(27) | BV(28) | BV(29) | BV(30) | BV(31));
}

void LedOn(void) {
	// make pin high
	GPIOD->ODR |= BV(12) | BV(13) | BV(14) | BV(15);
}

void LedOff(void) {
	// make pin low
	GPIOD->ODR &= ~(BV(12) | BV(13) | BV(14) | BV(15));
}

int main(void)
{
	LedInit();
	while(1) {
		GPIOD->ODR |= BV(12);
		DelayMs(200);
		GPIOD->ODR &= ~ BV(12);
		DelayMs(200);


				GPIOD->ODR |= BV(13);
				DelayMs(200);
				GPIOD->ODR &= ~ BV(13);
				DelayMs(200);

				GPIOD->ODR |= BV(14);
						DelayMs(200);
						GPIOD->ODR &= ~ BV(14);
						DelayMs(200);

						GPIOD->ODR |= BV(15);
								DelayMs(200);
								GPIOD->ODR &= ~ BV(15);
								DelayMs(200);


	}
	return 0;
}
