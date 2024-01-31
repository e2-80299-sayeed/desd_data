#include<stdio.h>


int main(void)
{
	//int num = 10, 20, 30; 			// error
	int num = (10, 20, 30);

	printf("num = %d\n",  num);

	int res = (num++, num++, num++);
	// num = 30, 31, 32, 33
	// res = (30, 31, 32);
	printf("num = %d\n",  num);
	printf("res = %d\n", res);

	res = (++num, ++num, ++num);
	// num = 33, 34, 35, 36
	// res = (34, 35, 36);
	printf("num = %d\n",  num);
	printf("res = %d\n", res);

	return 0;
}































