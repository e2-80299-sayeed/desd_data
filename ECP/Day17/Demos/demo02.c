#include<stdio.h>

void print_binary(unsigned char v)
{
	while(v > 0)
	{
		unsigned char rem = v % 2;
		printf("%d", rem);
		v /= 2;
	}
}

void print_binary_rec(unsigned char v)
{
	if(v == 0)
		return;
	unsigned char rem = v % 2;
	print_binary_rec(v / 2);
	printf("%d", rem);
}

int main(void)
{
	print_binary(10);
	printf("\n");
	print_binary_rec(10);
	printf("\n");
	return 0;
}































