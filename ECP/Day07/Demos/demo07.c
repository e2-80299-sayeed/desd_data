#include<stdio.h>

void accept_array(double *ptr, int size);
void print_array(double *ptr, int size);

int main(void)
{
	double arr[5];

	accept_array(arr, 5);
	print_array(arr, 5);

	return 0;
}

void accept_array(double *ptr, int size)
{
	printf("Enter array elements : \n");
	for(int i = 0 ; i < size ; i++)
		scanf("%lf", &ptr[i]);
}


void print_array(double *ptr, int size)
{
	printf("Array : ");
	for(int i = 0 ; i < size ; i++)
		printf("%-6.2lf", ptr[i]);
	printf("\n");
}






























