/*

4. Write a program to find maximum of two numbers using
 	a. If – else
 	b. conditional operator.

*/

#include<stdio.h>

int main(void)
{

	int num1,num2;
		
	printf("Enter two numbers : ");
	scanf("%d %d", &num1, &num2);
	
/*	
	if(num1 > num2)
		printf("%d is maximum.\n", num1);
	else 	
		printf("%d is maximuim.\n", num2);

*/

	num1 == num2 ? printf("Num1 = Num2.\n") : num1 > num2 ? printf("%d is maximum.\n", num1) : printf("%d is maximum.\n", num2);
	
	return 0;

}
