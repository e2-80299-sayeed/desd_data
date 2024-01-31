#include<stdio.h>

int main(void)
{
	int arr[3][4];
	
	printf("Enter array elements :\n");
	for(int i = 0 ; i < 3; i++)
	{
		for (int j = 0 ; j < 4 ; j ++)
		{
			printf("arr[%d][%d]", i ,j);
			scanf("%d",&arr[i][j]);		
		}
	}	
			
		printf("\n");
	
	printf("Array :\n");
	for(int i = 0; i < 3 ; i++)
	{
		for(int j = 0 ; j < 4 ; j++ )
		{
			printf("%-4d", arr[i][j]);	
		}
			printf("\n");
	}


	return 0;
}
