#include<stdio.h>


int main(void)
{
	// 2D array - character
	char courses[5][20] = {"PG-DESD", "PG-DAC", "PG-DITISS", "PG-DBDA", "PG-DMC"};

	for(int i = 0 ; i < 5 ; i++)
		printf("courses[%d] = %s\n", i, courses[i]);

	return 0;
}































