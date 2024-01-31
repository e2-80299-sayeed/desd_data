#include<stdio.h>


int main(void)
{
	int num1 = 0, num2 = 10;
	int res;

	// in case of logical operators will get result either 1 or 0
	// 0 --> 0
	// non 0 --> 1

	// Logical AND (&&)
	// 00 -- 0
	// 01 -- 0
	// 10 -- 0
	// 11 -- 1
	res = num1 && num2;						//0
	printf("%d && %d = %d\n", num1, num2, res);

	// Logical OR (||)
	// 00 -- 0
	// 01 -- 1
	// 10 -- 1
	// 11 -- 1
	res = num1 || num2;						//1
	printf("%d || %d = %d\n", num1, num2, res);

	// Logical NOT (!)
	// 1 -- 0
	// 0 -- 1
	res = !num1;				//1
	printf("!%d = %d\n", num1, res);
	res = !num2;				//0
	printf("!%d = %d\n", num2, res);
	return 0;
}































