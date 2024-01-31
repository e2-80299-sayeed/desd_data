#include<stdio.h>


int main(void)
{
	unsigned char v1 = -5;		// 1111 1011
	signed char v2 = -5;		// 1111 1011
	
	printf("v1 = %x, v2 = %x\n", v1, v2);


	printf("v1 << 2 = %x\n", v1 << 2);	// 1110 1100	EC
	printf("v1 >> 2 = %x\n", v1 >> 2);	// 0011 1110	3E
	printf("v2 << 2 = %x\n", v2 << 2);	// 1110 1100	EC
	printf("v2 >> 2 = %x\n", v2 >> 2);	// 1111 1110	FE
	return 0;
}































