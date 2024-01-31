#include<stdio.h>


int main(void)
{
	const int num = 10;

	const int * const ptr  = & num;
	// ptr is constant pointer to constant int

	printf("*ptr = %d\n", *ptr);			//allowed

	*ptr = 11;			//error
	ptr++;				//error		

	return 0;
}































