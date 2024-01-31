#include<stdio.h>


int main(void)
{
	int op1, op2;
	char opr;
	int res;

	printf("Enter op1 opr op2 : ");
	scanf("%d %c %d", &op1, &opr, &op2);

	switch(opr)
	{
		//case 1:		// valid
		//case 1.5:		// invalid
		// case "sunbeam"		// invalid
		// case 1 < 2:			// allowed
		// case var1 > var2:	// invalid
		// case pi:				// invalid
		// case 1 + 2:
		case '+':
			res = op1 + op2;
			//break;

		case '-':
			res = op1 - op2;
			break;

		case '*':
			res = op1 * op2;
			break;

		case '/':
			if(op2 != 0)
				res = op1 / op2;
			else
			{
				printf("Divide by zero error\n");
				goto L1;	
			}
			break;

		default:
			printf("Invalid operator\n");
			goto L1;
			break;
	}
	printf("%d %c %d = %d\n", op1, opr, op2, res);
L1:
	return 0;
}































