#include<stdio.h>

int accept_number(void);
int division(int, int);
void print_result(int);

static int flag = 0;

int main(void)
{
	int op1, op2, q;
	op1 = accept_number();
	op2 = accept_number();
	q = division(op1, op2);
	if(flag == 0)
		print_result(q);
	return 0;
}

int accept_number(void)
{
	int num;
	printf("Enter number : ");
	scanf("%d", &num);
	return num;
}

int division(int num1, int num2)
{
	if(num2 != 0)
		return num1 / num2;
	else
	{
		printf("divide by 0 error\n");
		flag = 1;
	}
}

void print_result(int res)
{
	printf("Result = %d\n", res);
}






























