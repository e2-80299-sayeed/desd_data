#include<stdio.h>


int main(void)
{
	int num = 10;
	
	int * const ptr = &num;
	// ptr is constant pointer to int

	printf("before : \n");
	printf("num = %d\n", num);
	printf("*ptr = %d\n", *ptr);

	*ptr = 11;

	printf("after : \n");
	printf("num = %d\n", num);
	printf("*ptr = %d\n", *ptr);

	int no = 22;
	//ptr = &no;		//error

	return 0;
}































