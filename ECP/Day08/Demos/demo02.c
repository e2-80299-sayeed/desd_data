#include<stdio.h>

// Array notation - internally all array notations are converted into pointer notation
void accept_array(int [], int);
void print_array(int [], int);

// Pointer notation
//void accept_array(int *ptr, int size);
//void print_array(int *ptr, int size);

int main(void)
{
	int arr[5];
	accept_array(arr, 5);
	print_array(arr, 5);
	return 0;
}

void accept_array(int ptr[], int size)
{
	printf("Enter array elements : \n");
	for(int i = 0 ; i < size ; i++)
		scanf("%d", &ptr[i]);
}

void print_array(int ptr[], int size)
{
	printf("Array elements : ");
	for(int i = 0 ; i < size ; i++)
		printf("%-4d", ptr[i]);
	printf("\n");
}






























