#include<stdio.h>

void reverse_digits(int num)
{
	if(num == 0)
		return;
	int rem = num % 10;
	printf("%4d", rem);
	reverse_digits(num / 10);
}

void forward_digits(int num)
{
	if(num == 0)
		return;
	int rem = num % 10;
	forward_digits(num / 10);
	printf("%4d", rem);
}
