#include<stdio.h>


int main(void)
{
	const int num = 10;
	// num is integer constant
	int const num1 = 20;
	// num1 is constant integer

	// location of num (4 bytes) are made non modifiable
	
	printf("before : num = %d\n", num);

	//num = 100;		// error
	//num++;		//num = num + 1		//	error
	//--num;		//num = num - 1		// error
	num + 1;

	printf("after : num = %d\n", num);

	return 0;
}































