#include<stdio.h>

// num1 and num2 - giving input - in parameters
// pdiff - getting result	- out parameter

int calculate(int num1, int num2, int *pdiff)
{
	// *pdiff - accessing location of diff variable
	*pdiff = num1 - num2;
	return num1 + num2;
	//return num1 - num2;
}

int main(void)
{
	int num1 = 30, num2 = 20, sum, diff;

	sum = calculate(num1, num2, &diff);
	printf("sum = %d, diff = %d\n", sum , diff);
	return 0;
}































