#include<stdio.h>

int main()
{
	char str1[20];
	char str2[20];
	
	printf("Enter Str1 : ");
	scanf("%[^\n]s", str1);
	
	printf("Enter Str2 : ");
	scanf("%s", str2);
	
	printf("str1 = %s\n, str2 = %s\n",str1,str2);

	return 0;
}
