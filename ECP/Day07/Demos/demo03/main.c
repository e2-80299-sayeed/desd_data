#include<stdio.h>
#include"header.h"

int main(void)
{
	int num, f;
	int b, i, p;

	printf("Enter number : ");
	scanf("%d", &num);

	f = factorial(num);
	printf("%d! = %d\n", num, f);

	printf("Enter base and index : ");
	scanf("%d %d", &b, &i);

	p = my_power(b, i);
	printf("%d ^ %d = %d\n", b, i, p);

	printf("Enter number : ");
	scanf("%d", &num);

	printf("Digits in reverse order : ");
	reverse_digits(num);
	printf("\n");

	printf("Digits in forward order : ");
	forward_digits(num);
	printf("\n");

	return 0;
}





