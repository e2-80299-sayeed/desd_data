#include<stdio.h>


int main(void)
{
	int num = 1;

	while(num <= 50)
	{
		printf("%d\n", num);
		if(num == 10)
			break;
		num++;
	}
	printf("After loop num = %d\n", num);

	return 0;
}































