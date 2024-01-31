#include<stdio.h>


int main(void)
{
	int row;

	printf("Enter number of rows : ");
	scanf("%d", &row);

	// to count number of rows
	for(int i = 1 ; i <= row ; i++)
	{
		// to count number of *
		for(int j = 1 ; j <= i ; j++)
		{
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}































