#include<stdio.h>


int main(void)
{
	int arr[5] = {11, 22, 33, 44, 55};
	// arr  - represents base address of array (address of first element of array)
	// 0th element - integer type
	// address of 0th element - integer type (integer pointer)

	int *ptr = arr;

	printf("arr = %u\n", arr);
	printf("ptr = %u\n", ptr);

	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)
		printf("%-4d", ptr[i]);
	printf("\n");

	return 0;
}































