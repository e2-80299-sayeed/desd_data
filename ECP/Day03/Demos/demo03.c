#include<stdio.h>

// sizeof()
	// this is an operator
	// this gives size of datatypes/variables/constants
	// syntax:
		// sizeof(datatype/variable/constant/expression)

int main(void)
{
	int num = 10;
	char ch = 'A';
	double pi = 3.142;

	printf("size of char = %d\n", sizeof(char));
	printf("size of short = %d\n", sizeof(short));
	printf("size of int = %d\n", sizeof(int));
	printf("size of float = %d\n", sizeof(float));
	printf("size of long = %d\n", sizeof(long));
	printf("size of double = %d\n", sizeof(double));

	printf("size of num = %d\n", sizeof(num));
	printf("size of ch = %d\n", sizeof(ch));
	printf("size of pi = %d\n", sizeof(pi));

	printf("size of 10  = %d\n", sizeof(10));
	printf("size of A  = %d\n", sizeof('A'));
	printf("size of 2.5  = %d\n", sizeof(2.5));			// 8 bytes
	printf("size of 2.5f  = %d\n", sizeof(2.5f));		// 4 bytes

	int res = 0;
	printf("before res = %d\n", res);
	printf("sizeof(10 + 20) = %d\n", sizeof(res = 10 + 20));		// 4 bytes
	printf("after res = %d\n", res);

	// when we use expression in sizeof() operator, that expression is not solved
	// only size of its results is predicted and printed on console

	res = sizeof(res = 10 + 20);			// 4 bytes
	return 0;
}































