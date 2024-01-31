#include<stdio.h>

int print_count(void)
{
	static int count = 0;
	printf("count = %d\n", ++count);
	return count;
}

int main(void)
{
	int ret;
	ret = print_count();
	printf("ret = %d\n", ret);

	ret = print_count();
	printf("ret = %d\n", ret);

	return 0;
}































