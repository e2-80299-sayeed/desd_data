#include<stdio.h>

int add(int, int);
int sub(int, int);

int main(void)
{
	printf("add(10, 20) = %d\n", add(10, 20));

	//int (*ptr)(int, int);
	//ptr = add;

	int (*ptr)(int, int) = add;
	
	printf("ptr(10, 20) = %d\n", ptr(10, 20));

	ptr = sub;
	
	printf("ptr(10, 20) = %d\n", ptr(10, 20));

	return 0;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}





























