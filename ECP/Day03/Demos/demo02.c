#include<stdio.h>


int main(void)
{
	// int printf("format", ...);
		// printf returns number of characters printed on console
	// int scanf("format", ...);
		// scanf returns number of items(variables) scanned from user

	int num;
	char ch;
	int ret;
	ret = printf("desd");
	printf("\nret = %d\n", ret);
/*
	printf("Enter number : ");
	ret = scanf("%d", &num);
	printf("ret = %d\n", ret);

	printf("Enter number, character : ");
	ret = scanf("%d %c", &num, &ch);
	printf("ret = %d\n", ret);

*/
	num = 100;
	ret =  printf("%d", num);
	//ret =  printf("num = %d\n", num);
	printf("\nret = %d\n", ret);

	return 0;
}































