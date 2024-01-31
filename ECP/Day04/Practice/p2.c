#include<stdio.h>


int main(void)
{
	int row;

	printf("Enter number of rows : ");
	scanf("%d", &row);

	// to count number of rows
	for(int i = 1 ; i <= row ; i++)
	{
		// to count number of spaces
		for(int j = i ; j <= row-1; j++)
		{

			printf(" ");
		}	
		//to count *
		for(int k=1;k<=i;k++)
		{
			printf("*");
	
		}
		printf("\n");
	 }

	return 0;
}































