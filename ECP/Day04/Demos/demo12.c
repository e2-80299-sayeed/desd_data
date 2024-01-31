#include<stdio.h>


int main(void)
{
	int num;
	int i = 2; 
	int count = 0;
	printf("Enter num : ");
	scanf("%d", &num);
	
	while(i <= num)
	{
		if(num % i == 0)		// check if number is divisible by i
			count++;
		
		if(count > 1)
			break;

		i++;
	}

	if(count == 1)
		printf("%d Number is prime\n", num);
	else
		printf("%d Number is not prime\n", num);
	
	return 0;
}































