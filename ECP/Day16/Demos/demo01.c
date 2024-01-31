#include<stdio.h>

int add(int, int);
int sub(int, int);
//float mul(float, int);


// int main(int argc, char *argv[]);
// int (*ptr)(int, char *[]) = main;

// int (*ptr)(void) = main
int main(void)
{

	printf("add(10, 20) = %d\n", add(10, 20));
	
	int (*ptr)(int, int);
	// ptr is pointer '*' to set of instruction(fuction) '()'
	// which takes two arguments of type int '(int, int)'and 
	// returns one integer 'int'

	ptr = add;

	printf("sizeof(ptr) = %ld\n", sizeof(ptr));			// 8 bytes
	printf("add = %u\n", add);
	printf("ptr = %u\n", ptr);

	printf("ptr(10, 20) = %d\n", ptr(10, 20));

	ptr = sub;
	
	printf("ptr(10, 20) = %d\n", ptr(10, 20));

	return 0;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

























