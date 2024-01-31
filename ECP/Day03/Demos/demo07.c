#include<stdio.h>


int main(void)
{
	char num1 = 'A';		// 65
	char num2 = 'B';		// 66
	char res;				// -128 to 127

	res = num1 + num2;		//	131

	// -128, -127, -126, -125, -124, ......0....., 125, 126, 127
	// if value of any variable exceed then it roll backs

	printf("num1 = %d, num2 = %d\nres = %d\n", num1, num2, res);

	// typecasting - chaning the type of data/variable for that operation temporary
	// implicit typecasting
		// it is done internally

	// int = int + char (int)
	// int = int + short (int)
	// float = int(float) + float
	// unsigned char = char(unsigned char) + unsigned char

	int n1 = 9, n2 = 2;
	int div;
	float div1;

	printf("n1 = %d, n2 = %d\n", n1, n2);
	div = n1 / n2;			// int = int / int
	printf("%d / %d = %d\n", n1, n2, div);


	// explicit typecasting
		// we need to specify new type in '()'
		// type of data/variable is changed temporary for operation
	div1 = (float)n1 / n2;
	printf("%d / %d = %f\n", n1, n2, div1);

	return 0;
}































