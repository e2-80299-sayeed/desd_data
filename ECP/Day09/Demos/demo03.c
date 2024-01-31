#include<stdio.h>
#include<string.h>

// strcmp - comapre two strings
// int strcmp(const char *s1, const char *s2);
// return value - int
	// < 0		--> if s1 is less than s2
	// = 0		--> if s1 and s2 are equal
	// > 0		--> if s1 is greater than s2

// both strings are compared character by character
// if both characters are equal then go for next character
// if both characters are not equal then return differece between *s1 and *s2

int main(void)
{
	char str1[20];
	char str2[20];

	printf("Enter str1  : ");
	scanf("%s", str1);

	printf("Enter str2  : ");
	scanf("%s", str2);

	printf("str1 = %s, str2 = %s\n", str1, str2);

	int ret = strcmp(str1, str2);
	printf("ret = %d\n", ret);
	if(ret == 0)
		printf("str1 and str2 are equal\n");
	else if(ret < 0)
		printf("str1 is less than str2\n");
	else	// ret > 0
		printf("str1 is greater than str2\n");

	return 0;
}































