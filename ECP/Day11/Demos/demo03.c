#include<stdio.h>


int main(void)
{
	char str1[20], str2[20];

	printf("Enter str1 : ");
	scanf("%[^\n]s", str1);
	
	printf("Enter str2 : ");
	scanf("%*c%[^\n]s", str2);

	printf("str1 = %s, str2 = %s\n", str1, str2);
	return 0;
}































