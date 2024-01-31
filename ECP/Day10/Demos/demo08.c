#include<stdio.h>


int main(void)
{
	char *arr[] = {"PG-DESD", "PG-DAC", "PG-DBDA", "PG-DMC", "PG-DITISS"};
	
	printf("Array : \n");
	for(int i = 0 ; i < 5 ; i++)
		printf("arr[%d] = %s [ %u ]\n", i, arr[i], arr[i]);;
	
	return 0;
}































