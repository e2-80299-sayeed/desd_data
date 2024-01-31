#include<stdio.h>
#include<stdlib.h>

// malloc - used to allocate memory dynamically
// void *malloc(size_t size);
	// arg1 - size (in bytes)
	// return value 
		// - starting address of allocated block if successful
		// - NULL if unsuccessful (requested size block is not available)
	// malloc(0) - NULL

// free - used to free memory allocated by malloc
//  void free(void *ptr);
	// arg1 - starting address(return value of malloc) of memory which is to be freed

int main(void)
{
	// allocate memory to 1D array
	int length;
	
	//1. take size of array from user
	printf("Enter length of array : ");
	scanf("%d", &length);			// 5

	//2. allocate memory dynamically to the user entered size
	int *ptr = (int *)malloc(length * sizeof(int));			// 5 * 4 = 20
	if(ptr == NULL)
	{
		printf("malloc() is failed to allocate memory\n");
		exit(-1);
	}

	//3. use allocated memory
	
	for(int i = 0 ; i < length ; i++)
		//*(ptr + i) = i + 10;
		ptr[i] = i + 10;

	printf("Stored values : ");
	for(int i = 0 ; i < length ; i++)
		//printf("%-4d", *(ptr + i));
		printf("%-4d", ptr[i]);
	printf("\n");

	//4. free allocated memory
	free(ptr);

	return 0;
}































