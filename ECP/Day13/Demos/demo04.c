#include<stdio.h>

typedef unsigned int uint32_t;
// Bit field
// when we are not utilising all bits of any variable, we can specify bit field
// we can use bit fields with only integer datatypes (char, short, int, long)
// we can not use bit fields with float, double, derived datatypes
// we cannot take address of bit-fields (directly can not be scanned from user)



typedef struct date
{
	uint32_t dd:5;						// 4 
	uint32_t mm:4;						// 4
	uint32_t yyyy:16;						// 4
}date_t;								// 12

int main(void)
{
	date_t dt = {22, 9, 2023};
	date_t d;

	printf("Today's Date : %d/%d/%d\n", dt.dd, dt.mm, dt.yyyy);

	//printf("Enter Date : (dd/mm/yyy) : ");
	//scanf("%d %d %d", &d.dd, &d.mm, &d.yyyy);

	d.dd = 31;		// = temp;
	d.mm = 12;		// = temp;
	d.yyyy = 2023;	// = temp;

	printf("Date : %d/%d/%d\n", d.dd, d.mm, d.yyyy);

	printf("sizeof(date_t) = %ld\n", sizeof(date_t));
	return 0;
}































