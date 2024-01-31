/*
1.
Write a program to accept a character and a number, and print the character number times
Input:
Character: *
Number: 6
Output: ******
*/

#include<stdio.h>

int main(void)
{
	int num;
	char ch;
	
	printf("Enter number : ");
	scanf("%d", &num);
			
	printf("Enter character :");
	scanf("%*c%c",&ch);
	
	int i = 0;
	
	while( i != num)
	{
		printf("%c",ch);
		
		i++;
	}	
		
	printf("\n");
			
	return 0;
}
