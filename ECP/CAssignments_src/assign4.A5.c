/*

Write a function to print a given character for a given number of times.

*/

#include<stdio.h>

void print_char(int,char);

int main(void)
{

	int num;
	char ch;
	
	printf("Enter character : ");
	scanf("%c",&ch);

	printf("How many times you want character to print : ");
	scanf("%d",&num);
	
	print_char(num,ch);

return 0;
}


	void print_char(int num,char ch)
{

	for(int i = 0; i < num; i++)
		printf("%c\n",ch);

	printf("\n");




}
