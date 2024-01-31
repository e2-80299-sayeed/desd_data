#include<stdio.h>


int main(void)
{
	int arr[5];


	printf("Enter array elements : \n");
	for(int i = 0 ; i < 5 ; i++)
	{
		printf("arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}

	printf("arr = %u\n", arr);

	for(int i = 0 ; i < 5 ; i++)
		printf("arr[%d] = %d [ %u ] \n", i, arr[i], &arr[i]);

	return 0;
}































