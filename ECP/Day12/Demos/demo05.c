#include<stdio.h>
#include<stdlib.h>

// realloc - used to re allocate the dynamically allocated space
// void *realloc(void *ptr, size_t size);
	// arg1 = pointer to the memeory (which is to be reallocated)
	// arg2 = new size after reallocation
	// return - returns starting address of reallocated memory

// realloc(NULL, size)	- malloc(size)
// realloc(ptr, 0)	- free(ptr)

// if new_size < old_size (shrink)
	// memory will be shrinked to new size
	// extra memory will be freed
	// same starting address will be return
// if new_size > old_size (grow)
	// if immediate memory block is available
		// memory will be grown
		// same starting address will be return
	// if immediate memory block is not available
		// new block of new size is allocated
		// old content is copied as it is into new block
		// old block is freed
		// address of new block will be return



int main(void)
{
	int size = 5;
	int *ptr = (int *)malloc(size * sizeof(int));
	
	for(int i = 0 ; i < size ; i++)
		ptr[i] = i + 10;

	int new_size = 4;

	ptr = (int *)realloc(ptr, new_size * sizeof(int));

	//ptr[5] = 100;
	//ptr[6] = 50;

	printf("Array : ");
	for(int i = 0 ; i < new_size ; i++)
		printf("%-4d", ptr[i]);
	printf("\n");
	

	free(ptr);

	return 0;
}































