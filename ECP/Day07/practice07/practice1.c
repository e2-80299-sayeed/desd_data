#include<stdio.h>

int main()
{
	int num=15;
	int *pnum = &num;
	int **ppnum = &pnum;
	
	printf("num = %d\n",num);
	printf("*pnum = %d\n", *pnum);
	
	printf("&num = %d\n", &num);
	printf("pnum = %d\n", pnum);
	printf("&pnum = %d\n", &pnum);
	printf("ppnum = %d\n", ppnum);


return 0;
}
