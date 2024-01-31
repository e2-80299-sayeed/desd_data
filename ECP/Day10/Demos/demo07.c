#include<stdio.h>


int main(void)
{
	// <data type> <name of array>[<size of array>];

	int arr1[3];
	// arr1 is collection '[]' of 3 integers 'int'
	// arr1 - integers will be stored

	int *arr[3];
	// arr is collection '[]' of 3 integer pointers 'int *'
	// arr - addresses of type integer pointers will be stored

	int num1 = 10, num2 = 20, num3 = 30;

	arr[0] = &num1;
	arr[1] = &num2;
	arr[2] = &num3;

	printf("num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);
	printf("&num1 = %u, &num2 = %u, &num3 = %u\n", &num1, &num2, &num3);

	printf("Array (arr[i]) : ");
	for(int i = 0 ; i < 3 ; i++)
		printf("%u\t", arr[i]);
	printf("\n");
	
	printf("Values (*arr[i]) : ");
	for(int i = 0 ; i < 3 ; i++)
		printf("%u\t", *arr[i]);
	printf("\n");

	return 0;
}































