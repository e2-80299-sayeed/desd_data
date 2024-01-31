#include<stdio.h>


int main(void)
{
	int num = 11;
	// num is integer variable
	int *pnum = &num;
	// pnum is pointer to integer
	int **ppnum = &pnum;
	// ppnum is pointer to integer pointer

	printf("num = %d\n", num);				//11
	printf("*pnum = %d\n", *pnum);			//11	
	printf("**ppnum = %d\n", **ppnum);		//11

	printf("&num = %u\n", &num);			//100
	printf("pnum = %u\n", pnum);			//100
	printf("&pnum = %u\n", &pnum);			//200
	printf("ppnum = %u\n", ppnum);			//200
						// &ppnum			//300


	return 0;
}































