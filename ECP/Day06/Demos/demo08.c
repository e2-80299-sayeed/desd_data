#include<stdio.h>



void swap(int, int);

int main(void)
{
	int num1 = 10, num2 = 20;
	printf("before swap : num1 = %d, num2 = %d\n", num1, num2);
	printf("after swap : num1 = %d, num2 = %d\n", num1, num2);
	swap(num1, num2);
	// call by value - value of actual argument is copied into formal argument

	return 0;
}


void swap(int num1, int num2)
{
	printf("before swap : num1 = %d, num2 = %d\n", num1, num2);
	int temp = num1;
	num1 = num2;
	num2 = temp;
	printf("after swap : num1 = %d, num2 = %d\n", num1, num2);
}





























