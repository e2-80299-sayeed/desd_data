/*
 * led.h
 *
 *  Created on: 19-May-2022
 *      Author: nilesh
 */

#ifndef LED_H_
#define LED_H_

#include "stm32f4xx.h"

#define LED_GREEN_PIN	12
#define LED_ORANGE_PIN	13
#define LED_RED_PIN		14
#define LED_BLUE_PIN	15

#define LED_GPIO			GPIOD
#define AHB1ENR_LEDGPIO_EN	3

#define BB_BASE			0x40000000UL
#define BB_ALS_BASE		0x42000000UL

//#define BB_ALS_ADDR(regr,bit) (BB_ALS_BASE + ((regr-BB_BASE) * 32) + (bit * 4))
#define BB_ALS_ADDR(regr,bit) (BB_ALS_BASE + ((regr-BB_BASE) << 5) + (bit << 2))
#define BB_ALS(regr,bit) (*(uint32_t*)BB_ALS_ADDR((uint32_t)regr,bit))

void LedInit(uint32_t pin);
void LedOn(uint32_t pin);
void LedOff(uint32_t pin);
void LedBlink(uint32_t pin, uint32_t ms);

#endif /* LED_H_ */
