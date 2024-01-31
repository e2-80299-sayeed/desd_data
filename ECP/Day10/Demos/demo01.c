#include<stdio.h>


int main(void)
{
	int num = 10;
	char ch = 'A';
	double d = 3.142;

	int *pnum = &num;
	char *pch = &ch;
	double *pd = &d;

	void *ptr = NULL;
	
	printf("num = %d, ch = %c, d = %lf\n", *pnum, *pch, *pd);

	ptr = &num;
	printf("num = %d\n", *(int *)ptr);

	ptr = &ch;
	printf("ch = %c\n", *(char *)ptr);
	
	ptr = &d;
	printf("d = %lf\n", *(double *)ptr);

	return 0;
}































