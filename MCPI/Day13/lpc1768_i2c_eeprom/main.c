#include "LPC17xx.h"
#include "uart.h"
#include "eeprom.h"
#include <stdio.h>

// EEPROM --> P0.28 [SCL0] & P0.27 [SDA0] --> I2C0
char string[32];
int main()
{
	int choice;
	SystemInit();
	uart_init(9600);
	uart_puts("I2C EEPROM DEMO!\r\n");
	eeprom_init();
	while(1)
	{
		uart_puts("\r\n1. Write EEPROM\r\n2. Read EEPROM\r\nEnter Choice : \r\n");
		uart_gets(string);
		sscanf(string, "%d", &choice);
		switch(choice)
		{
		case 1:
			uart_puts("Enter string to write (max 32 chars) : \r\n");
			uart_gets(string);
			uart_puts("Data writing to EEPROM\r\n");
			eeprom_write(0x0000, (uint8_t*)string, sizeof(string));
			uart_puts("Data written to EEPROM\r\n");
			break;
		case 2:
			uart_puts("String reading from EEPROM : \r\n");
			eeprom_read(0x0000, (uint8_t*)string, sizeof(string));
			uart_puts("String read from EEPROM : \r\n");
			uart_puts(string);
			uart_puts("\r\n");
			break;
		default:
			sprintf(string, "Invalid Choice : %d\r\n", choice);
			uart_puts(string);
		}
	}
}

