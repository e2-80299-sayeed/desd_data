#include<stdio.h>
#define SIZE 9
int linear_search( int arr[],int key);

int main()
{
	int arr[SIZE] = {33,55,22,66,44,11,77,99,88}; 
	int key;
	
	printf("Enter the value of key : ");
	scanf("%d",&key);
	
	int index = linear_search(arr,key);
	if(index != -1)
		printf("\nkey found at index = %d\n",index);
	else	
		printf("Key not found !!\n");
	
	return 0;
}

int linear_search( int arr[],int key)
{
	for(int i = 0; i < SIZE; i++)
		{
			if (key == arr[i])
			return i;
		}
	return -1;
}
