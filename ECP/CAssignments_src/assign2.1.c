/*
1. Write a program to accept two numbers and display division of the two numbers. Check for
divide by zero error. If divider is zero then display appropriate error message.
*/

#include<stdio.h>

int main(void)
{
	double num1,num2;
	
	printf("Enter num 1 : ");
	scanf("%lf",&num1);
	
	printf("Enter num 2 : ");
	scanf("%lf",&num2);
	
	if(num2 != 0)
		printf("%.2lf / %.2lf = %.2lf \n", num1, num2, num1/num2);
	else 
		printf("Divide by zero error !!\n");
	

	return 0;
} 
