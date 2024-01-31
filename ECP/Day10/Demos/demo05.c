#include<stdio.h>
#include<string.h>

// generic swap function - swap function will be able to swap any type of data

void swap(void *, void *, int);

int main(void)
{
	int num1 = 10, num2 = 20;
	char ch1 = 'A', ch2 = 'B';

	printf("Before : \n");
	printf("num1 = %d, num2 = %d\n", num1, num2);
	printf("ch1 = %c, ch2 = %c\n", ch1, ch2);

	swap(&num1, &num2, sizeof(int));
	swap(&ch1, &ch2, sizeof(char));

	printf("After : \n");
	printf("num1 = %d, num2 = %d\n", num1, num2);
	printf("ch1 = %c, ch2 = %c\n", ch1, ch2);
	return 0;
}

void swap(void *ptr1, void *ptr2, int size)
{
	// ptr1 - address of v1 (*ptr1)
	// ptr2 = address of v2 (*ptr2)
	int temp; 
	memcpy(&temp, ptr1, size);		// temp = *ptr1;
	memcpy(ptr1, ptr2, size);		// *ptr1 = *ptr2;
	memcpy(ptr2, &temp, size);		// *ptr2 = temp
}






























