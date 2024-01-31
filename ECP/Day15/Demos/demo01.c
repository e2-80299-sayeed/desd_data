#include<stdio.h>


int main(void)
{
	int num1, num2;
	int res;

	fprintf(stdout, "Enter two numbers : ");
	fscanf(stdin, "%d %d", &num1, &num2);

	fprintf(stdout, "num1 = %d, num2 = %d\n", num1, num2);

	res = num1 + num2;

	fprintf(stdout, "res = %d\n", res);

	return 0;
}































