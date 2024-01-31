#include<stdio.h>
#include<math.h>


int main(void)
{
	int num1, num2;
	char ch;


	printf("Enter two numbers : ");
	scanf("%d %d", &num1, &num2);

	printf("Enter ch : ");
	scanf("%*c%c", &ch);
	
	printf("num1 = %d, num2 = %d\n", num1, num2);
	printf("ch = %d\n", ch);

	printf("sqrt = %lf\n",sqrt(num2));

	return 0;
}































