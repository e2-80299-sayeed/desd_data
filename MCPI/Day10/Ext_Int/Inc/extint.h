/*
 * extint.h
 *
 *  Created on: Oct 3, 2023
 *      Author: sunbeam
 */

#ifndef EXTINT_H_
#define EXTINT_H_

#include<stm32f407xx.h>

#define GPIOA_CLK_ENB	0

#define GPIO_SWITCH		GPIOA
#define SWITCH_PIN	0

void extint_init(void);

#endif /* EXTINT_H_ */
