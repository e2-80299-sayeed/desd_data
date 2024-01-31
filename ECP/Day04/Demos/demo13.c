#include<stdio.h>


int main(void)
{
	int num, rem;
	int cnt = 0, sum = 0;

	printf("Enter number : ");
	scanf("%d", &num);								// init

	printf("Entered Number : %d\n", num);
	printf("Digits of entered number : ");
	while( num > 0 )								// cond
	{
		rem = num % 10;								// body	
		printf("%d ", rem);							// body
		num = num / 10;								// mod	
		cnt++;
		sum += rem;
	}
	printf("\n");
	// 	num			num > 0		rem			num/=10
	//	1234		T			4
	//	123			T			3
	//	12			T			2
	//	1			T			1
	//	0			F

	printf("Number of digits : %d\n", cnt);
	printf("Sum of digits : %d\n", sum);
	return 0;
}































