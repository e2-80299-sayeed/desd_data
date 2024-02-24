#ifndef __I2C_H
#define __I2C_H

#include "LPC17xx.h"

#define CON_ACK 2
#define CON_SIF 3
#define CON_STOP 4
#define	CON_START 5
#define CON_EN 6

#define SCLL_VAL	90
#define SCLH_VAL	90

void i2c_init(void);
void i2c_start(void);
void i2c_rep_start(void);
void i2c_stop(void);
void i2c_send_addr(uint8_t addr);
void i2c_send_data(uint8_t data);
uint8_t i2c_recv_ack(void);
uint8_t i2c_recv_nack(void);

#endif

