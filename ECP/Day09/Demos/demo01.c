#include<stdio.h>
#include<string.h>


int main(void)
{
	char str1[20];
	char str2[20];

	printf("Enter str1 : ");
	scanf("%s", str1);


	printf("str1 = %s, str2 = %s\n", str1, str2);
	
	strcpy(str2, str1);

	printf("After strcpy : \nstr1 = %s, str2 = %s\n", str1, str2);

	return 0;
}































