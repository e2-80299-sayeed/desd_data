#include<stdio.h>


int main(void)
{
	char str1[20] = "Sunbeam Hinjawadi";
	char str2[] = "Sunbeam Hinjawadi";
	char *ptr = "Sunbeam Hinjawadi";

	printf("str1 = %s, [ sizeof(str1) = %ld ]\n", str1, sizeof(str1));
	printf("str2 = %s, [ sizeof(str2) = %ld ]\n", str2, sizeof(str2));
	printf("ptr = %s, [ sizeof(ptr) = %ld ]\n", ptr, sizeof(ptr));

	*ptr = 'F';

	printf("ptr = %s\n", ptr);
	return 0;
}































