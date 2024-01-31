#include<stdio.h>

// enum
enum operatios{
	EXIT, ADD, SUB, MUL, DIV
};


// menu driven program for basic calculator
int main(void)
{
	int choice;
	int num1, num2, res;

	do
	{
		printf("0. Exit\n");
		printf("1. Addition\n");
		printf("2. Subtraction\n");
		printf("3. Multiplication\n");
		printf("4. Division\n");
		printf("Enter yout choice : ");
		scanf("%d", &choice);
		
		if(choice == 0)
			continue;
		
		printf("Enter two operands : ");
		scanf("%d %d", &num1, &num2);

		switch(choice)
		{
			case ADD:
				res = num1 + num2;
				break;

			case SUB:
				res = num1 - num2;
				break;

			case MUL:
				res = num1 * num2;
				break;

			case DIV:
				if(num2 != 0)
					res = num1 / num2;
				else
					goto L1;
				break;
		}
		
		printf("Result = %d\n", res);
L1:
	printf("");
	}while(choice != EXIT);
	return 0;
}































