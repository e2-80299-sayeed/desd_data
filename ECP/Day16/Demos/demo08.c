#include<stdio.h>

int factorial(int num)
{
	int fact = 1;
	for(int i = 1 ; i <= num ; i++)
		fact *= i;
	return fact;
}

int main(void)
{
	int n = 5;

	printf("num = %d\n", n);

	int f = factorial(n);

	printf("%d! = %d\n", n, f);

	return 0;
}































