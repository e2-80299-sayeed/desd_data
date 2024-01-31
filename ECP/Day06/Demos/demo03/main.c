#include<stdio.h>
#include"fun.h"

int flag = 0;

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

