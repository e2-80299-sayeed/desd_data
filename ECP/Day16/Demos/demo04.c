#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// void qsort(void *base, size_t nmemb, size_t size,int (*compar)(const void *, const void *));
	// arg1 - base address of array
	// arg2 - number of elements in array
	// arg3 - size of individual element
	// arg4 - address of compare function
 
//compare function:	// which takes addresses of two elements
		  	// and return differance between them
			// arg1 < arg2 	-> -ve
			// arg1 = arg2	-> 0
			// arg1 > arg2	-> +ve

#define SIZE 6

// ptr1 - address of first element to be compared		*(int *)ptr1
// ptr2 - address of second element to be compared		*(int *)ptr2
int compare1(const void *ptr1, const void *ptr2)
{
	return *(int *)ptr1 - *(int *)ptr2;
}

int compare2(const void *ptr1, const void *ptr2)
{
	return *(char *)ptr1 - *(char *)ptr2;
}

int compare3(const void *ptr1, const void *ptr2)
{
	return strcmp((char *)ptr1, (char *)ptr2);
}

int main(void)
{
	//int arr[SIZE] = {33, 22, 66, 44, 11, 55};
	//char arr[SIZE] = {'c', 'b', 'e', 'a', 'd'};
	char arr[SIZE][20] = {"sohail", "devendra", "nilesh", "vrushabh", "saurabh", "nitin"};
	
	printf("Array before sort : ");
	for(int i = 0 ; i < SIZE ; i++)
		//printf("%-4d", arr[i]);
		//printf("%-4c", arr[i]);
		printf("%s ", arr[i]);
	printf("\n");
	
	//qsort(arr, SIZE, sizeof(int), compare1);
	//qsort(arr, SIZE, sizeof(char), compare2);
	qsort(arr, SIZE, 20, compare3);

	printf("Array after sort : ");
	for(int i = 0 ; i < SIZE ; i++)
		//printf("%-4d", arr[i]);
		//printf("%-4c", arr[i]);
		printf("%s ", arr[i]);
	printf("\n");
	return 0;
}































