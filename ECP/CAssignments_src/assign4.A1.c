#include<stdio.h>

int factorial(int);

int main()
{
	int num=5;
	
	printf("Factorial of %d is %d\n",num,factorial(num));
		

return 0;

}

	

int factorial(int num)	
{
	
	int fact=1;
	for(int i=1;i<=num;i++)
	{
	  fact *= i;
	}
	return fact;
}
