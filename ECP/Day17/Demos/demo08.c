#include<stdio.h>


int main(void)
{
	int num = 0x11223344;
	unsigned char *ptr = (unsigned char *)&num;

	if(*ptr == 0x44)
		printf("Little Endian\n");
	else
		printf("Big Endian\n");

	return 0;
}































