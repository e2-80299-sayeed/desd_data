#include<stdio.h>


int main(void)
{
	int op1, op2, res;
	char opr;

	//1. open input file into read mode
	FILE *in = fopen("input.txt", "r");
	
	//2. read input (op1, opr and op2) from file
	fscanf(in, "%d %c %d", &op1, &opr, &op2);
	
	printf("op1 = %d, opr = %c, op2 = %d\n", op1, opr, op2);

	// 3. close the opened
	fclose(in);

	// 4. perform operation
	switch(opr)
	{
		case '+':
			res = op1 + op2;
			break;

		case '-':
			res = op1 - op2;
			break;
	}

	//5. open output file in append mode
	FILE *out = fopen("output.txt", "a");

	//6. write result into file
	fprintf(out, "%d %c %d = %d\n", op1, opr, op2, res);

	//7. close the output file
	fclose(out);

	return 0;
}































