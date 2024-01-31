#include<stdio.h>
#include<string.h>

// strtok - extract tokens from string
// char *strtok(char *str, const char *delim);

int main(void)
{
	char str[64] = "I am student of DESD course";
	char *ptr = NULL;
	
	printf("str = %s\n", str);

	ptr = strtok(str, " ");
	printf("ptr = %s\n", ptr);

	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	ptr = strtok(NULL, " ");
	printf("ptr = %s\n", ptr);
	
	return 0;
}































