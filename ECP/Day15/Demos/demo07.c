#include<stdio.h>

#define SWAP(v1, v2, type) {type temp = v1; v1 = v2; v2 = temp;}

struct test
{
	int num1;
	int num2;
};

int main(void)
{
	int num1 = 10, num2 = 20;

	printf("before : num1 = %d, num2 = %d\n", num1, num2);
	SWAP(num1, num2, int);
	printf("after : num1 = %d, num2 = %d\n", num1, num2);

	struct test t1 = {10, 20}, t2 = {30, 40};

	printf("before : t1 = {%d %d}, t2 = {%d %d}\n", t1.num1, t1.num2, t2.num1, t2.num2);
	SWAP(t1, t2, struct test);
	printf("after : t1 = {%d %d}, t2 = {%d %d}\n", t1.num1, t1.num2, t2.num1, t2.num2);

	return 0;
}































