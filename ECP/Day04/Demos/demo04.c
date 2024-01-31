#include<stdio.h>

// basic calculator

int main(void)
{
	double op1, op2;
	char opr;
	double res;

	printf("Enter op1 opr op2 : ");
	scanf("%lf %c %lf", &op1, &opr, &op2);

	if(opr == '+')
		res = op1 + op2;
	else if(opr == '-')
		res = op1 - op2;
	else if(opr == '*')
		res = op1 * op2;
	else if(opr == '/')
		if(op2 != 0)
			res = op1 / op2;
		else
		{
			printf("divide by zero error\n");
			goto END;	
		}
	else
	{
		printf("Invalid operator\n");
		goto END;
	}
	printf("%.2lf %c %.2lf = %.2lf\n", op1, opr, op2, res);
END:
	return 0;
}































