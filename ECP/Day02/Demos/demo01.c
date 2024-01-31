#include<stdio.h>


int main(void)
{
	// syntax : <datatype> <variable name> = <value>;

	int num1 = 10;
	int num2 = 20;
	char ch = 'A';

	// printf(<format string>);
	// printf(<format string>, [List of variables])

	printf("num1 = %d\n", num1);
	printf("%d %d\n", num1, num2);
	printf("ch = %c\n", ch);
	printf("num1 = %d, ch = %c\n", num1, ch);

	// scanf(<format string>, [List of addresses of variables]);

	printf("Enter number : ");
	scanf("%d", &num1);

	printf("num1 after scanf = %d\n", num1);
	return 0;
}









