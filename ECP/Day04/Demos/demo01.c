#include<stdio.h>


int main(void)
{
	int num1, num2;

	printf("Enter numbers : ");
	scanf("%d %d", &num1, &num2);
	
	/*
	if(num1 == num2)
		printf("num1 and num2 are equal\n");
	else if(num1 > num2)
		printf("num1 is greater\n");
	else
		printf("num2 is greater\n");

	*/
	int max;
	if(num1 == num2)
		max = num1;
	else if(num1 < num2)
		max = num2;
	else
		max = num1;

	printf("maximum number : %d\n", max);

	return 0;
}































