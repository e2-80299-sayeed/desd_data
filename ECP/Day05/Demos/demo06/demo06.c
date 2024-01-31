#include<stdio.h>
#include"mymath.h"

int main(void)
{
	int num1 = 10, num2 = 5;

	printf("sum = %d\n", add(num1, num2));
	printf("diff = %d\n", sub(num1, num2));
	printf("product = %d\n", mul(num1, num2));
	printf("quotient = %d\n", div(num1, num2));
	printf("factorial = %d\n", factorial(num2));
	printf("power = %d\n", _power(2, 3));
	

	return 0;
}































