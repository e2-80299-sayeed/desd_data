#include<stdio.h>


int main(void)
{
	const int num = 10;

	int *ptr = &num;

	printf("before : num = %d\n", num);

	*ptr = 11;
	
	printf("after : num = %d\n", num);
	return 0;
}































