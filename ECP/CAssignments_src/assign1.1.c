#include<stdio.h>

int main(void)

{
	//signed  num1, num2;
	//unsigned char  num1, num2;
	//int  num1, num2;
	long  num1, num2;
	printf("Enter two Numbers :");
	scanf("%ld %ld",&num1, &num2);
	
	printf("sum = %ld\n",num1 + num2);

	printf("difference = %ld\n",num1 - num2);

	printf("product = %ld\n",num1 * num2);

	return 0;
	
}
