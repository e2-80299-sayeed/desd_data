#include<stdio.h>


int main(void)
{
	char str1[] = "123456";

	printf("str1 = %u\n", str1);		// base address of str1 (address of first character)
	printf("str1 = %s\n", str1);		// string
	
	printf("&str1 = %u\n", &str1);		// address of str1 (address of whole str1 array)

	printf("str1 + 1 = %u\n", str1 + 1);
	printf("&str1 + 1 = %u\n", &str1 + 1);

	char *ptr1 = str1;
	// ptr1 is pointer '*' to character 'char'
	printf("str1 = %u, ptr1 = %u, *ptr1 = %c\n", str1, ptr1, *ptr1);

	char (*ptr2)[7] = &str1;
	// ptr2 is pointer '*' to collction '()' of 7 '[7]' characters 'char'
	printf("&str1 = %u, ptr2 = %u, *ptr2 = %u\n", &str1, ptr2, *ptr2);

	return 0;
}































