/*

4. Write a program to find factorial of given number.
Input: 5
Output: 1 * 2 * 3 * 4 * 5 = 120

*/

#include<stdio.h>

int main(void)
{
	int num;
	int fact = 1;
	
	printf("Enter Number : ");
	scanf("%d",&num);

	while(num != 1)
	{

	fact = fact * num;
	
	num--;
	
	
	}

	printf("factorial = %d \n", fact);
	return 0;
}
