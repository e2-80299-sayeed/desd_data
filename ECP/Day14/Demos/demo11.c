#include<stdio.h>


int main(void)
{
	int num1, num2;
	// standard output - stdout

	//printf("Some message\n");
	fprintf(stdout, "Some message\n");

	fprintf(stdout, "Enter two numbers : ");
	// standard input - stdin
	fscanf(stdin, "%d %d", &num1, &num2);

	fprintf(stdout, "num1 = %d, num2 = %d\n", num1, num2);

	if(num2 == 0)
		// standard error - stderr
		fprintf(stderr, "divide by zero error\n");
	else
		fprintf(stdout, "%d / %d = %d\n", num1, num2, num1 / num2);
	return 0;
}































