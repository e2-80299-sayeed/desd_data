#include<stdio.h>


int main(void)
{
	//char str[7] = {'P', 'G', '-', 'D', 'E', 'S', 'D'};
	char str[] = {'P', 'G', '-', 'D', 'E', 'S', 'D', '\0'};
	char str1[] = "PG-DESD";		// by default string terminating character is added
									// at the last of array ( '\0' )
	char str2[20];

	printf("str : ");
	for(int i = 0 ; i < 7 ; i++)
		printf("%c", str[i]);
	printf("\n");

	printf("str : %s\n", str);
	printf("str1 : %s\n", str1);

	printf("sizeof(str) = %ld\n", sizeof(str));
	printf("sizeof(str1) = %ld\n", sizeof(str1));

	printf("Enter string : ");
	//scanf("%s", str2);			// only one word will be scanned
	scanf("%[^\n]s", str2);			// scan upto new line character (\n)
	//scanf("%[^.]s", str2);			// scan upto .
	//scanf("%[^#]s", str2);			// scan upto #


	printf("str2 = %s\n", str2);
	return 0;
}































