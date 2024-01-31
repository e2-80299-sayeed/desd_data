#include<stdio.h>

void swap(int *, int *);
void check_even_odd(int);
void check_divisible_4(int);

int main(void)
{
	int num1 = 5, num2 = 3;

	printf("before swap : num1 = %d, num2 = %d\n", num1, num2);
	swap(&num1, &num2);
	printf("after swap : num1 = %d, num2 = %d\n", num1, num2);

	printf("Enter number : ");
	scanf("%d", &num1);
	check_even_odd(num1);
	check_divisible_4(num1);

	return 0;
}

void swap(int *p1, int *p2)
{
	// num1 	--> *p1
	// num2 	--> *p2
	*p1 = *p1 ^ *p2;
	*p2 = *p1 ^ *p2;
	*p1 = *p1 ^ *p2;
}

void check_even_odd(int num)
{
	if((num & 1) == 1)
		printf("%d number is odd\n", num);
	else
		printf("%d number is even\n", num);
}

void check_divisible_4(int num)
{
	if((num & 3) == 0)
		printf("%d number is divisible by 4\n", num);
	else
		printf("%d number is not divisible by 4\n", num);
}




























