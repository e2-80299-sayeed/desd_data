#include<stdio.h>
#include<string.h>

// memmove - copy overlapping memory area 
// void *memmove(void *dest, const void *src, size_t n);

int main(void)
{
	int arr[6] = {11, 22, 33, 44, 55, 66};

	printf("Arr : ");
	for(int i = 0 ; i < 6 ; i++)
		printf("%-4d", arr[i]);
	printf("\n");

	// copy first 4 elements of array into last 4 elements of array
	// base address = 100
	// src = 100		--> arr
	// dest = 108		-->	arr+2
	// n = 16 bytes

	memmove(arr+2, arr, 4 * sizeof(arr[0]));
	
	printf("After memmove : \n");
	printf("Arr : ");
	for(int i = 0 ; i < 6 ; i++)
		printf("%-4d", arr[i]);
	printf("\n");
	return 0;
}































