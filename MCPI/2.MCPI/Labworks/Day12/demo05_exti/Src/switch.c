/*
 * switch.c
 *
 *  Created on: 19-May-2022
 *      Author: nilesh
 */
#include "switch.h"
#include "led.h"

void SwitchInit(uint32_t pin) {
	// enable GPIO clock
	RCC->AHB1ENR |= BV(AHB1ENR_SWITCH_GPIO_EN);
	// set gpio mode as input
	SWITCH_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// set gpio speed as low
	SWITCH_GPIO->OSPEEDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	// set pupd as none
	SWITCH_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
	/* configure exti to generate interrupt when switch is released */
	// enable falling edge detection
	EXTI->FTSR |= BV(SWITCH_PIN_EXTI);
	// enable (unmask) exti interrupt for switch (exti0)
	EXTI->IMR |= BV(SWITCH_PIN_EXTI);
	// PA0 --> EXTI0 : configure in SYSCFG EXTICR0 regr
	SYSCFG->EXTICR[0] &= ~(BV(0) | BV(1) | BV(2) | BV(3));
	/* configure NVIC to send exti0 interrupt to ARM core */
	// enable exti0 interrupt in ISER
	//NVIC->ISER[0] |= BV(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI0_IRQn);
}

int SwitchGetState(uint32_t pin) {
	// get switch state
	uint32_t state = SWITCH_GPIO->IDR;
	// return 1 when pressed, 0 when released
	return (state & BV(SWITCH_PIN)) ? 1 : 0;
}

// implement interrupt handler for exti0
void EXTI0_IRQHandler(void) {
	// acknowledge the interrupt in exti pending register
	EXTI->PR |= BV(SWITCH_PIN_EXTI);
	// blink a led
	LedBlink(LED_BLUE_PIN, 1000);
}





