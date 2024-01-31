#include<stdio.h>
#include<string.h>

// strcat - concatenate two string
// char *strcat(char *dest, const char *src);

int main(void)
{
	char str1[20];
	char str2[20];

	printf("Enter str1 : ");
	scanf("%s", str1);

	printf("Enter str2 : ");
	scanf("%s", str2);

	printf("str1 = %s, str2 = %s\n", str1, str2);
	
	strcat(str2, str1);

	printf("After strcat : \nstr1 = %s, str2 = %s\n", str1, str2);

	return 0;
}































