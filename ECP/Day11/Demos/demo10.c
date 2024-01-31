#include<stdio.h>
#include<stdlib.h>

// calloc - used to allocate memory dynamically
// void *calloc(size_t nmemb, size_t size);
// 	arg1 - no of elements
// arg2 - size of individual element
// return value - starting address of allocated block if successfull otherwise NULL


int main(void)
{
	int count;

	printf("Enter no of students : ");
	scanf("%d", &count);

	// float *marks = (float *)malloc(count * sizeof(float));  		// count * 4
	float *marks = (float *)calloc(count, sizeof(float));  		// count * 4
	// err check

	printf("Enter %d student marks : \n", count);
	for(int i = 0 ; i < count ; i++)
		scanf("%f", &marks[i]);

	printf("Student marks :\n");
	for(int i = 0 ; i < count ; i++)
		printf("%-6.2f", marks[i]);
	printf("\n");

	free(marks);
	return 0;
}































