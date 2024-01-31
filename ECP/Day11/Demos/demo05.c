#include<stdio.h>


int main(void)
{
	int arr[5] = {11, 22, 33, 44, 55};
	// arr is an array of 5 integers
	
	int *ptr1 = arr;
	// ptr1 is a pointer to integer
	// arr is base address of array (address of first element)

	int (*ptr2)[5] = &arr;
	// ptr2 is a pointer to collection of 5 integers
	// &arr is address of array (address of whole array)

	for(int i = 0 ; i < 5 ; i++)
		printf("ptr1[%d] = %d\n", i, ptr1[i]);
	
	// ptr1[i] = *(ptr1 + i) = *(ptr1 + i * SF(ptr1))
	// *(100 + 0) = *100 = 11
	// *(100 + 1) = *(100 + 4) = *(104) = 22
	// ...
	
	for(int i = 0 ; i < 5 ; i++)
		printf("ptr2[%d] = %u\n", i, ptr2[i]);

	// ptr2[i] = *(ptr2 + i) = *(ptr2 + i * SF(ptr2))
	// *(100 + 0) = *(100) = 100
	// *(100 + 1) = *(100 + 20) = *(120) = 120
	// ...

	return 0;
}































