#include<stdio.h>
#include<stdlib.h>

int *fun(void)
{
	int num = 10;			// addr = 100
	// ...
	printf("&num = %u\n", &num);
	return &num;		// return 100
}


int main(void)
{
	int *ptr;
	
	// ....

	// upto this line ptr is dangling

	ptr = (int *)malloc(20);

	printf("ptr = %u\n", ptr);

	free(ptr);


	// after this line ptr is dangling
	printf("After free()\n");
	printf("ptr = %u\n", ptr);

	*ptr = 10;
	
	ptr = fun();			// 100

	// ptr will be dangling
	printf("after fun : ptr = %u\n", ptr);

	return 0;
}































