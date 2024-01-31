#include<stdio.h>


int main(void)
{
	int num1 , num2;

	printf("Enter numbers : ");
	scanf("%d %d", &num1, &num2);

	// condition ? expr1 : expr2;
	// cond - num1 > num2
	// expr1 - printf(num1)
	// expr2 - printf(num2)

	num1 > num2 ? printf("num1 is greater\n") : printf("num2 is greater\n");
	int max = num1 > num2 ? num1 : num2;

	printf("Max value : %d\n", max);

	return 0;
}































