#include<stdio.h>


int main(void)
{
	int num = 0;

	while(num <= 50)
	{
		num++;
		if(num == 10)
			continue;
		printf("%d\n", num);
	}

	return 0;
}































