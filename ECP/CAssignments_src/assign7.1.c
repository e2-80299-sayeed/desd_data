/*
1. Write a function to accept a 2-D array from the user. Write another function to print the 2-D
array. Re-use these functions in rest of the assignments wherever required.

*/

#include<stdio.h>

void accept_array(int arr[][3], int , int);
void print_array(int arr[][3], int , int);


int main(void)
{
	
	int arr[3][3];
	

	accept_array(arr,3,3);
	print_array(arr,3,3);


	return 0;
}
void accept_array(int arr[][3], int row, int col)
{

	printf(" Enter Array elements :\n");
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("arr[%d][%d]",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	
	
}
	
void print_array(int arr[][3], int row , int col)
{
	printf("Array Elements are : \n");
	for(int i = 0 ; i < row ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			printf("%-4d",arr[i][j]);
		}
	
		printf("\n");	
	}

}
