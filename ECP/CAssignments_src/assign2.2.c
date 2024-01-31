/*

2. Input a number and display whether number is Even or Odd.

*/

#include<stdio.h>

int main(void)
{
	unsigned int n1;
	
	printf("Enter Number : ");
	scanf("%u", &n1);
	
	if (n1 % 2 == 0)
		printf("NUmber is EVEN !!\n");
	else 
		
		printf("NUmber is ODD !!\n");
	

	return 0;
}
