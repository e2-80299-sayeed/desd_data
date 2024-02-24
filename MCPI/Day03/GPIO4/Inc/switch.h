/*
 * switch.h
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include<stm32f407xx.h>

#define BV(n)	(1 << (n))

#define GPIOA_CLK_ENB	0

#define SWITCH_GPIO		GPIOA

#define SWITCH_PIN		0

void switch_init(uint16_t pin);
uint16_t switch_status(uint16_t pin);

#endif /* SWITCH_H_ */
