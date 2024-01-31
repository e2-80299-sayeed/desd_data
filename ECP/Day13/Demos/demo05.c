#include<stdio.h>

typedef unsigned int uint32_t;

typedef struct date
{
	uint32_t dd:5;						// 4 
	uint32_t mm:4;						// 4
	uint32_t yyyy:16;						// 4
}date_t;								// 12

int main(void)
{
	date_t d;
	uint32_t temp;
	
	printf("Enter date : (dd, mm, yyyy) : ");
	scanf("%d", &temp);
	d.dd = temp;
	
	scanf("%d", &temp);
	d.mm = temp;
	
	scanf("%d", &temp);
	d.yyyy = temp;

	printf("Date : %d/%d/%d\n", d.dd, d.mm, d.yyyy);

	printf("sizeof(date_t) = %ld\n", sizeof(date_t));
	return 0;
}































