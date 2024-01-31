#include<stdio.h>
#include<stdlib.h>

// $ ./demo10.out <op1> <opr> <op2>
// argc = 4
// argv[0] = "./demo10.out"
// argv[1] = "<op1>"
// argv[2] = "<opr>"
// argv[3] = "<op2>"
// argv[4] = NULL

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("Run program like : ./demo10.out <op1> <opr> <op2>");
		exit(1);		//return 1;
	}
	
	int op1 = atoi(argv[1]);
	int op2 = atoi(argv[3]);
	char opr = argv[2][0];		// *argv[2] 			// "+"
	int res;

	switch(opr)
	{
		case '+':
			res = op1 + op2;
			break;

		case '-':
			res = op1 - op2;
			break;
		
		case '/':
			res = op1 / op2;
			break;
		
		case '*':
			res = op1 * op2;
			break;
	}

	printf("%d %c %d = %d\n", op1, opr, op2, res);

	return 0;
}































