#include<stdio.h>

// symbolic constant
#define PI 3.142
#define SIZE 5

// macros
#define ADD(v1, v2) v1 + v2
#define SQR(n) (n) * (n)

int main(void)
{
	int arr[SIZE];
	int num = 5;
	printf("SQR(5) = %d\n", SQR(5));
	printf("SQR(num) = %d\n", SQR(num));
	printf("SQR(2 + 3) = %d\n", SQR(2 + 3));


	printf("This is exam code\n");
	printf("PI=%f\n", PI);

	printf("ADD(10, 20) = %d\n", ADD(10, 20));

	int num1 = 10, num2 = 20;
	printf("ADD(10, 20) = %d\n", ADD(num1, num2));
	return 0;
}































