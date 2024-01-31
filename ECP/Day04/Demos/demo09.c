#include<stdio.h>


int main(void)
{
	int num;

	printf("Enter num : ");
	scanf("%d", &num);

	printf("Table of %d : \n", num);
	int loop_var = 1;						// init	- 1 time
	
	do
	{
		printf("%d\n", loop_var * num);		// body	- N times
		loop_var++;							// mod	- N times
	}while(loop_var <= 10);					// cond	- N times

	// num = ?
	//	loop_var	loop_var <= 10		loop_var * num		loop_var++
	//	1			T					1 * num
	//	2			T					2 * num
	//	3			T					3 * num
	// 	4			T					4 * num
	//	...
	//	10			T					10 * num
	//	11			F


	return 0;
}































