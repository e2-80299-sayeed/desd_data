/*
 * led.h
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */

#ifndef LED_H_
#define LED_H_

#include<stm32f407xx.h>

#define BV(n)	(1 << (n))

#define GPIOD_CLK_ENB	3

#define LED_GPIO	GPIOD

#define LED_GREEN	12
#define LED_ORANGE	13
#define LED_RED		14
#define LED_BLUE	15

void led_init(uint16_t pin);
void led_on(uint16_t pin);
void led_off(uint16_t pin);
void led_toggle(uint16_t pin);
				  //NOTE: UL = unsigned long
#define BB_BASE			0x40000000UL //This value has been taken from image/datasheet.  
#define BB_ALS_BASE		0x42000000UL //This value has been taken from image/datasheet.

#define BB_ALS_ADDR(regr,bit) (BB_ALS_BASE + ((regr-BB_BASE) << 5) + ((bit) << 2))
#define BB_ALS(regr,bit) (*(uint32_t*)BB_ALS_ADDR((uint32_t)regr,bit))



#endif /* LED_H_ */
