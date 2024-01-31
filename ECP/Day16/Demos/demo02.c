#include<stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

/*
int (*ptr1)(int, int);
int (*ptr2)(int, int);
int (*ptr3)(int, int);
int (*ptr4)(int, int);
*/

// int (*ptr)(int, int);		// function pointer variable 
typedef int (*ptr_t)(int, int);	// function pointer type
ptr_t ptr1, ptr2, ptr3, ptr4;

int main(void)
{
	ptr1 = add;
	printf("ptr(10, 20) = %d\n", ptr1(10, 20));

	ptr2 = sub;
	printf("ptr(10, 20) = %d\n", ptr2(10, 20));

	ptr3 = mul;
	printf("ptr(10, 20) = %d\n", ptr3(10, 20));
	
	ptr4 = div;
	printf("ptr(10, 20) = %d\n", ptr4(10, 20));
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

int mul(int num1, int num2)
{
	return num1 * num2;
}

int div(int num1, int num2)
{
	return num1 / num2;
}
