#include<stdio.h>
/*
Array
	- collection of similar type of data elements
	- array elements are stored into contiguous memory locations
	- array locations are identifed by array name
	- every array element has one unique index and it is used to access that element
	- '[]' operator is used to access array elements
	- syntax:
		<datatype> <array name>[<size of array>];
		eg. int arr[5];			--> arr is an array of 5 integers
	- array indices always starts with 0
	- to access 1st element --> arr[0]
	- to access 2nd element --> arr[1]
	- to access 3rd element --> arr[2]
	- to access 4th element --> arr[3]
	- to access nth element --> arr[n-1]	

*/

int main(void)
{
	//int arr[5];
	int arr[5] = {11, 22, 33, 44, 55};		// array initialiser list
	//int arr[5] = {11, 22, 33};				// partial initialisation - remaining elements will be made 0
	//int arr[] = {11, 22, 33, 44, 55};		// array size is inferred
	//int arr[];			// error

	printf("arr[0] = %d\n", arr[0]);
	printf("arr[1] = %d\n", arr[1]);
	printf("arr[2] = %d\n", arr[2]);
	printf("arr[3] = %d\n", arr[3]);
	printf("arr[4] = %d\n", arr[4]);

	printf("Array : ");
	for(int index = 0 ; index < 5 ; index++)
		printf("%-4d", arr[index]);
	printf("\n");

	printf("sizeof(arr) = %ld\n", sizeof(arr));

	return 0;
}































