#include<stdio.h>


int main(void)
{
	int num1 = 10, num2 = 9;
	int res;

	printf("num1 = %d, num2 = %d\n", num1, num2);

	// in case of relational operators result will be either 1 or 0
	// 1 - if true
	// 0 - if false

	res = num1 == num2;				// 0
	printf("== : %d\n", res);

	res = num1 != num2;				// 1
	printf("!= : %d\n", res);

	res = num1 < num2;				// 0
	printf("< : %d\n", res);
	
	res = num1 > num2;				// 1
	printf("> : %d\n", res);

	res = num1 <= num2;				// 0
	printf("<= : %d\n", res);
	
	res = num1 >= num2;				// 1
	printf(">= : %d\n", res);
	return 0;
}































