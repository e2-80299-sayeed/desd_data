#include<stdio.h>

int calculate(int, int, char);

int main(void)
{
	int op1, op2;
	char opr, ch;

	do
	{
		printf("Enter op1 opr op2 : ");
		scanf("%d %c %d", &op1, &opr, &op2);
		
		if(opr == '/' && op2 == 0)
		{
			printf("Divide by zero error\n");
			goto label;
		}
		printf("%d %c %d = %d\n", op1, opr, op2, calculate(op1, op2, opr));
label:
		printf("Do you want to continue (y/n) : ");
		scanf("%*c%c", &ch);

	}while(ch != 'n');


	return 0;
}

int calculate(int op1, int op2, char opr)
{
	int res;
	switch(opr)
	{
		case '+':
			res = op1 + op2;
			break;
		case '-':
			res = op1 - op2;
			break;
		case '*':
			res = op1 * op2;
			break;
		case '/':
			res = op1 / op2;
			break;
	}
	return res;
}






























