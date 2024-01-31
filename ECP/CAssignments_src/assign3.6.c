/*

Write a program to accept a number and print all factors excluding the number
Input: 24
Output: all factors: 1, 2, 3, 4, 6, 8, 12

*/

#include<stdio.h>

int main (void)
{
		
	int num;
	int factors=1;
	
	printf("Enter number : ");
	scanf("%d",&num);
	

	printf("all factors: ");	
	while(factors != num )
	{

		factors = num/2;
		printf("%d",factors);


	}
	


	return 0;
}
