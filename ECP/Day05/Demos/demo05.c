#include<stdio.h>

// static storage class
	// static keyword is used

//static int num1 = 20;
int num2 = 20;
void print(void);

int main(void)
{
	static int num = 10;

	printf("main : num = %d\n", num);
	print();
	return 0;
}

void print(void)
{
	printf("print : num = %d\n", num);
}































