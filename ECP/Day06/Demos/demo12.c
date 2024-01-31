#include<stdio.h>

void swap(int *, int *);


int main(void)
{
	int num1 = 10, num2 = 20;

	printf("before swap : num1 = %d, num2 = %d\n", num1, num2);
	swap(&num1, &num2);	
	// call by address - address of actual arguments is cpoied into formal argument
	printf("after swap : num1 = %d, num2 = %d\n", num1, num2);

	return 0;
}

void swap(int *pnum1, int *pnum2)
{
	// *pnum1 - accessing location of num1 which is created inside main()
	// *pnum2 - accessing location of num2 which is created inside main()
	int temp = *pnum1;
	*pnum1 = *pnum2;
	*pnum2 = temp;
}






























