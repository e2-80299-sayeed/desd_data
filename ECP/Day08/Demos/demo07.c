#include<stdio.h>


int main(void)
{
	//int num = 10;
	//int *ptr = &num;
	
	const int num = 10;
	const int *ptr = &num;
	// ptr is pointer to constant integer

	printf("num = %d\n", num);
	printf("*ptr = %d\n", *ptr);

	//num = 100;			//error
	//*ptr = 100;			//error

	int no = 20;
	ptr = &no;

	printf("*ptr = %d\n", *ptr);
	return 0;
}































