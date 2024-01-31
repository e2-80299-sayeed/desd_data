#include<stdio.h>


int main(void)
{
	int num1 = 10, num2 = 20;
	int res;
	printf("num1 + num2 = %d\n", num1 + num2);
	printf("num1 - num2 = %d\n", num1 - num2);
	printf("num1 * num2 = %d\n", num1 * num2);
	printf("num2 / num1 = %d\n", num2 / num1);
	printf("num2 %% num1 = %d\n", num2 % num1);

	res = num1 + num2;
	printf("res = %d\n", res);

	num1 += num2;			// num1 = num1 + num2
	printf("num1 = %d\n", num1);

	return 0;
}































