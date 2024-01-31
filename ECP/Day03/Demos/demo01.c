#include<stdio.h>


int main(void)
{
	int num = 10;
	char ch = 'A';
	float pi = 3.142;

	printf("num  = %d\n", num);
	printf("ch = %c\n", ch);
	printf("pi = %f\n", pi);

	printf("Enter number, character, float number : ");
	scanf("%d %c %f", &num, &ch, &pi);

	printf("After scan : num = %d, ch = %c, pi = %f\n", num, ch, pi);

	return 0;
}






























