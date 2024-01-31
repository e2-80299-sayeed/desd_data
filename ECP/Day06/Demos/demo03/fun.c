#include<stdio.h>
#include"fun.h"
extern int flag;

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
	{
		int res =  num1 / num2;
		print_result(res);
		return res;
	}
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
