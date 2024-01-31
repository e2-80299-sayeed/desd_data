#include<stdio.h>
#include<string.h>

// strstr - locate a substring
//  char *strstr(const char *haystack, const char *needle);


int main(void)
{
	char string[128] = "i am learing sunbeam. i am in desd course";
	char substring[20] = "am";

	char *ptr = strstr(string, substring);

	printf("ptr = %s\n", ptr);

	return 0;
}































