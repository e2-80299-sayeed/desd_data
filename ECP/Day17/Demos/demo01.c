#include<stdio.h>

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
	unsigned char v1 = 5;
	unsigned char v2 = -5;

	printf("decimal : v1 = %d, v2 = %d\n", v1, v2);
	
	printf("v1 : ");
	print_binary_rec(v1);
	printf("\n");

	printf("v2 : ");
	print_binary_rec(v2);
	printf("\n");

	if(v1 > v2)
		printf("v1 is greater\n");
	else
		printf("v2 is greater\n");

	return 0;
}































