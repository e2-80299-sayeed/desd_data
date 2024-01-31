#include<stdio.h>

// find maximum of three numbers

int main(void)
{
	int num1, num2, num3;
	int max;

	printf("Enter three numbers : ");
	scanf("%d %d %d", &num1, &num2, &num3);

	if(num1 > num2)
	{
		// num1
		if(num1 > num3)
			max = num1;
		else
			max = num3;
	}
	else
	{
		// num2
		if(num2 > num3)
			max = num2;
		else
			max = num3;
	}

	max = num1 > num2 ? 
		num1 > num3 ? 
			num1 : 
			num3 
	: 
		num2 > num3 ? 
			num2 : 
			num3;

	printf("Maximum value : %d\n", max);
	return 0;
}































