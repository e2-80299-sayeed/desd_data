
#include<stdio.h>


int main(void)
{
	//unsigned char v1 = 5, v2 = 3, res;
	signed char v1 = 5, v2 = 3, res;

	// v1 = 5 0000 0101	(0x05)
	// v2 = 3 0000 0011 (0x03)
	printf("v1 = %x, v2 = %x\n", v1, v2);
	
	// &
	res = v1 & v2;
	printf("v1 & v2 = %x\n", res);

	// |
	res = v1 | v2;
	printf("v1 | v2 = %x\n", res);
	
	// ~
	res = ~v1;
	printf("~v1 = %x\n", res);

	// ^
	res = v1 ^ v2;
	printf("v1 ^ v2 = %x\n", res);
	
	// << (left shift)
	res = v1 << 2;
	printf("v1 << 2 = %x\n", res);

	// >> (right shift)
	res = v1 >> 2;
	printf("v1 >> 2 = %x\n", res);

	return 0;
}































