#include "eeprom.h"
#include "uart.h"

void eeprom_init(void)
{
	i2c_init();
	i2c_start();
	i2c_send_addr(EEPROM_R);
	i2c_stop();
}

void eeprom_write(uint16_t addr, uint8_t bytes[], uint8_t n)
{
	uint8_t i, hiaddr = addr >> 8, loaddr = addr & 0xFF;
	i2c_init();
	i2c_start();
	i2c_send_addr(EEPROM_W);
	i2c_send_data(hiaddr);
	i2c_send_data(loaddr);
	for(i=0; i<n; i++)
	{
		i2c_send_data(bytes[i]);
	}
	i2c_stop();
}

void eeprom_read(uint16_t addr, uint8_t bytes[], uint8_t n)
{
	uint8_t i, hiaddr = addr >> 8, loaddr = addr & 0xFF;
	i2c_init();
	i2c_start();
	i2c_send_addr(EEPROM_W);
	i2c_send_data(hiaddr);
	i2c_send_data(loaddr);
	i2c_rep_start();
	i2c_send_addr(EEPROM_R);
	for(i=0; i<n-1; i++)
	{
		bytes[i] = i2c_recv_ack();
	}
	bytes[i] = i2c_recv_nack();
	i2c_stop();
}

