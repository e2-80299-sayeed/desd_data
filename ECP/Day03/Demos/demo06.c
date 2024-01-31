#include<stdio.h>

// increment/decrement (++/--)
// Before operand (Pre)
	//value of operand is modified first and then updated value is used
// After operand (Post)
	//value of operand is used first and then it is modified

int main(void)
{
	int num = 9;
	int res;

	printf("num = %d\n", num);			// 9
	res = ++num;
					// num = num + 1	//10
					// res = num		//10
	printf("res = %d, num = %d\n", res, num);

	num = 9;
	printf("num = %d\n", num);			// 9
	res = --num;
					// num = num - 1	// 8
					// res = num		// 8
	printf("res = %d, num = %d\n", res, num);

	num = 9;
	printf("num = %d\n", num);			// 9
	res = num++;
					// res = num		// 9
					// num = num + 1	// 10	

	printf("res = %d, num = %d\n", res, num);

	num = 9;
	printf("num = %d\n", num);			// 9
	res = num--;
					// res = num		// 9
					// num = num - 1	// 8
	printf("res = %d, num = %d\n", res, num);
	
	return 0;
}































