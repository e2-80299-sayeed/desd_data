#include<stdio.h>


int main(void)
{
	// way 1
	int *ptr = 100;

	// *ptr = *100 --> error
	
	printf("ptr = %u\n", ptr);
	printf("ptr + 1 = %u\n", ptr + 1);		// ptr + SF(ptr) = 100 + 4 = 104
	printf("ptr - 1 = %u\n", ptr - 1);		// ptr - SF(ptr) = 100 - 4 = 96

	printf("ptr + 2 = %u\n", ptr + 2);		// ptr + 2 * SF(ptr) = 100 + 2 * 4 = 108
	printf("ptr - 2 = %u\n", ptr - 2);		// ptr - 2 * SF(ptr) = 100 - 2 * 4 = 92


	// way 2
	int *ptr1 = 100;
	int *ptr2 = 200;

	printf("ptr1 = %u, ptr2 = %u\n", ptr1, ptr2);
	printf("ptr2 - ptr1 = %d\n", ptr2 - ptr1);
	// (ptr2 - ptr1) / SF(ptr2)	= (200 - 100) / 4 = 100 / 4 = 25

	return 0;
}































