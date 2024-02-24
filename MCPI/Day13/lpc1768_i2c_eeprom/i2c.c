#include "i2c.h"
#include "uart.h"

void i2c_init(void)
{
	// enable i2c0 pins
	LPC_PINCON->PINSEL1 &= ~(BV(25)|BV(24)|BV(23)|BV(22));
	LPC_PINCON->PINSEL1 |= BV(22) | BV(24);
	// setup prescalar
	LPC_I2C0->I2SCLL = SCLL_VAL;
	LPC_I2C0->I2SCLH = SCLH_VAL;
	// clear all flags
	LPC_I2C0->I2CONCLR = BV(CON_ACK) | BV(CON_SIF) | BV(CON_START) | BV(CON_EN);
	// enable I2C
	LPC_I2C0->I2CONSET = BV(CON_EN);
}	

void i2c_start(void)
{
	// send start signal
	LPC_I2C0->I2CONSET = BV(CON_START);
	// wait for transmission
	while((LPC_I2C0->I2CONSET & BV(CON_SIF))==0);
	// clear SI flag
	LPC_I2C0->I2CONCLR = BV(CON_SIF) | BV(CON_START);
}

void i2c_rep_start(void)
{
	i2c_start();
}

void i2c_stop(void)
{
	// send stop signal
	LPC_I2C0->I2CONSET = BV(CON_STOP);
	// do not poll for SIF.
}

void i2c_send_addr(uint8_t addr)
{
	// send address
	LPC_I2C0->I2DAT = addr;
	// set i2c en
	LPC_I2C0->I2CONSET = 0;	
	// wait for transmission
	while((LPC_I2C0->I2CONSET & BV(CON_SIF))==0);
	// clear SI flag
	LPC_I2C0->I2CONCLR = BV(CON_SIF);
}

void i2c_send_data(uint8_t data)
{
	// send data
	LPC_I2C0->I2DAT = data;
	// set i2c en
	LPC_I2C0->I2CONSET = 0;	
	// wait for transmission
	while((LPC_I2C0->I2CONSET & BV(CON_SIF))==0);	
	// clear SI flag
	LPC_I2C0->I2CONCLR = BV(CON_SIF);
}

uint8_t i2c_recv_ack(void)
{
	uint8_t data;
	// set i2c en
	LPC_I2C0->I2CONSET = BV(CON_ACK);	
	// wait for receive
	while((LPC_I2C0->I2CONSET & BV(CON_SIF))==0);	
	// recv data
	data = LPC_I2C0->I2DAT;
	// clear SI flag
	LPC_I2C0->I2CONCLR = BV(CON_SIF) | BV(CON_ACK);
	return data;
}

uint8_t i2c_recv_nack(void)
{
	uint8_t data;
	// set i2c en
	LPC_I2C0->I2CONSET = 0;	
	// wait for receive
	while((LPC_I2C0->I2CONSET & BV(CON_SIF))==0);	
	// recv data
	data = LPC_I2C0->I2DAT;
	// clear SI flag 
	LPC_I2C0->I2CONCLR = BV(CON_SIF);	
	return data;
}


