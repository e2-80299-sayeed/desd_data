#include<stdio.h>


int main(void)
{
	int num1 = 0, num2 = 10;
	int res;

	printf("num1 = %d, num2 = %d\n", num1, num2);		// 0 10
	res = num1 && ++num2;								// 0
	printf("res = %d\n", res);							// 0
	printf("num1 = %d, num2 = %d\n", num1, num2);		// 0 10
	// if first operand of logical AND is 0 then second operand is never checked
	// and result is always 0

	printf("num1 = %d, num2 = %d\n", num1, num2);		// 0 10
	res = num2 || ++num1;								// 1
	printf("res = %d\n", res);							// 1
	printf("num1 = %d, num2 = %d\n", num1, num2);		// 0 10
	// if first operand of logical OR is 1 (non 0) then second operand is not checked
	// and result is always 1

	// res = num1 || ++num2;			// 0 || 11 = 1 
										// num1 = 0 num2 = 11

	// res = num2 && num1++;			// 10 && 0 = 0
										// num2 = 10, num1 = 1

	return 0;
}































