/*
Write a function to implement four function calculator. Function would take operands and
operator as arguments and returns result.
*/

#include<stdio.h>
#include"fun.h"

int main()
{
	double op1,op2;
	char opr,ch;

do{	

	printf("Enter operand1 operator and operand2: ");
	scanf("%lf %c %lf",&op1,&opr,&op2);


	
	if(opr=='+')
	ADD(op1,opr,op2);

else if(opr=='-')
	SUB(op1,opr,op2);

else if(opr=='*')	
	MUL(op1,opr,op2);

else if(opr=='/'&&op2!=0)
	DIV(op1,opr,op2);
else 
      {	printf("Error!!\n");
	
      }

	printf("Do you want to continue?(y/n) :");
	scanf("%*c%c",&ch);
}while(ch=='y');

	return 0;
}


