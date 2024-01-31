#include<stdio.h>


int main(void)
{
	int arr[5] = {10, 20, 30, 40, 50};

	printf("arr + 0 = %u\n", arr + 0);			// 100
	printf("arr + 1 = %u\n", arr + 1);			// 100 + 1 = 100 + SF = 104
	printf("arr + 2 = %u\n", arr + 2);			// 100 + 2 = 100 + 2 * SF = 108
	printf("arr + 3 = %u\n", arr + 3);			// 112
	printf("arr + 4 = %u\n", arr + 4);			// 116

	printf("*arr = %d\n", *arr);
	printf("arr[0] = %u\n", *(arr + 0));			// *(100 + 0) = 10
	printf("arr[1] = %u\n", *(arr + 1));			// *(100 + 1) = *(100 + SF) = *104 = 20
	printf("arr[2] = %u\n", *(arr + 2));			// *(100 + 2) = *(100 + 2 * SF) = *108 = 30
	printf("arr[3] = %u\n", *(arr + 3));			// 40
	printf("arr[4] = %u\n", *(arr + 4));			// 50
	
	return 0;
}































