#include<stdio.h>

void print_binary(unsigned char var)	// 0001	0011	
{
	unsigned char mask = 128;		//0X80;			//	1000 0000
	
	while(mask)
	{
		if(var & mask)
			printf("1");
		else
			printf("0");

		mask = mask >> 1;				// mask /= 2;
	}
	printf("\n");
}

int main(void)
{
	unsigned char var = 10;

	print_binary(var);

	return 0;
}































