/*
 * led.c
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */
#include"led.h"

void led_init(uint16_t pin)
{
	// enable clock for gpio D port
	RCC->AHB1ENR |= BV(GPIOD_CLK_ENB);

	// select mode of GPIO pins as output
	BB_ALS(&(LED_GPIO->MODER), 2 * pin) = 1;
	BB_ALS(&(LED_GPIO->MODER), 2 * pin + 1) = 0;

	// select output type as push pull
	BB_ALS(&(LED_GPIO->OTYPER),pin) = 0;

	// select output speed as low
	BB_ALS(&(LED_GPIO->OSPEEDR), 2 * pin) = 0;
	BB_ALS(&(LED_GPIO->OSPEEDR), 2 * pin + 1) = 0;

	// do not select pull up / pull down resistor
	BB_ALS(&(LED_GPIO->PUPDR), 2 * pin) = 0;
	BB_ALS(&(LED_GPIO->PUPDR), 2 * pin + 1) = 0;
}
void led_on(uint16_t pin)
{
	// write 1 on respective bits of ODR
	BB_ALS(&(LED_GPIO->ODR),pin) = 1;
}
void led_off(uint16_t pin)
{
	// write 0 on respective bits of ODR
	BB_ALS(&(LED_GPIO->ODR),pin) = 0;
}
void led_toggle(uint16_t pin)
{
	LED_GPIO->ODR ^= BV(pin);
}
