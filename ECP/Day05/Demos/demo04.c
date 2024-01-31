#include<stdio.h>

// Register storage class
	// register keyword is used
	// by writing register keyword, we are just requesting CPU to give CPU register
	// if CPU denied then that variable will be treated as local variable

// we can not create register storage class variables in global space
// register int num;		// not allowed

int main(void)
{
	register int num = 10;

	printf("num = %d\n", num);

	printf("Enter num : ");
	scanf("%d", &num);		// not allowed
	// address of CPU register can not accessed/demanded out side the CPU

	num = 100;		// allowed
	//num = variable	// allowed
	printf("num = %d\n", num);
	return 0;
}































