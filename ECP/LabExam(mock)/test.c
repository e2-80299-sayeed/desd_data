#include<stdio.h>
#include"test.h"

enum operations{
ADD = 1, SUB, DIV, MULTI
};


int main(void)
{
	int op1, op2, choice;
	float res;
	
	do 
	{
	
	printf("Enter OP1 and OP2 :");
	scanf("%d %d", &op1, &op2 );
	
	
	printf("1. Addition.\n2. Subtraction.\n3. Division\n4. Multiplication.\n5. Exit.\n\n");
	

	printf("Enter choice : ");
	scanf("%d",&choice);
		switch(choice)		
		{
			case ADD : res = add(op1,op2);
				   printf("Addition of  %d + %d = %.2f \n\n", op1, op2, res);
				   break;

			case SUB : res = sub(op1,op2);
				   printf("Subtraction of  %d - %d = %.2f \n\n", op1, op2, res);
			           break;
				
			case DIV : if(op2 != 0)
			  	   { 	res = div(op1,op2);
			 	   	printf("Divide of  %d / %d = %.2f \n\n", op1, op2, res);
				   }
				else 
					printf("Divide by zero Error!!\n\n");	
				   break;
		
			case MULTI : res = multi(op1, op2);
				     printf("Multiplication of  %d * %d = %.2f \n\n", op1, op2, res);
				     break;	
			
			default : 
				  goto EXIT;

		}


		}while(choice != 0);
EXIT :	
	return 0;

}


