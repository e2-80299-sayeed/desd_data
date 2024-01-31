#include<stdio.h>

/*
Pointer
	- is a variable which is used to store address of another variable
	- address - unsigned int
	- Declaration
		<data type> *<pointer variable name>;
		- pointer type will be same as variable for which you want to store address
		eg. int num;		-->		int *ptr;
			char ch;		-->		char *ptr;

	- Operators
		- &	(address of/referance/direction)
			- is used to take address of variable
			- eg. &num 		---> this will give you address of num variable

		- * (value at/dereferance/indirection)
			- is used to access value of variable
			- eg. *ptr		---> we are accessing the location where ptr is pointing
			- *ptr = ?		--> write
			- ? = *ptr		--> read
*/ 

int main(void)
{
	int num = 11;
	// num is int variable
	int *ptr = &num;
	// ptr is pointer to int variable
	printf("num = %d\n", num);
	printf("value of num using ptr = %d\n", *ptr);


	printf("&num = %p\n", &num);
	printf("ptr = %p\n", ptr);

	*ptr = 22;
	
	printf("num = %d\n", num);

	return 0;
}































