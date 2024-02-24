#include <stdio.h>

int main() 
{
	int num1, num2, res;
	
	scanf("%d%d", &num1, &num2); // scan from stdin
	//fscanf(stdin, "%d%d", &num1, &num2); // scan from stdin
	
	res=num1+num2;
	printf("sum: %d\n", res);	// print on stdout

	res=num1*num2;
	fprintf(stdout, "product: %d\n", res);	// print on stdout

	if(num2 != 0) {
		res=num1/num2;
		fprintf(stdout, "division: %d\n", res);	// print on stdout
	}
	else
		fprintf(stderr, "denominator cannot be zero.\n"); // print on stderr
	return 0;
}

