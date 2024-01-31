#include<stdio.h>

int main(void)
{

	int year,days;
	
	printf("Enter year : ");
	scanf("%d", &year);
	
	if(year % 4 != 0)
		days = 365;	
	
	else if (year % 100 != 0 )
	{	
		printf(" %d is a leap year.\n",year);	
		days = 366;
	}

	printf("Days = %d\n ", days);
	

	return 0;

}
