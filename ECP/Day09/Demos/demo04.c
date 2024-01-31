#include<stdio.h>
#include<string.h>

// strchr - used to search(locate) character in string
//  char *strchr(const char *s, int c);
	// returns address of first occurence of given character
//  char *strrchr(const char *s, int c);
	// returns address of last occurence of given character


int main(void)
{
	char str[64] = "I love my work";			// 100 address
	char ch = 'o';

	printf("str = %u\n", str);				// 100
	
	//char *ptr = strchr(str, ch);
	char *ptr = strrchr(str, ch);

	printf("ptr = %u\n", ptr);				// 103
	printf("ptr = %s\n", ptr);				// 103		--> ove my work
	printf("ptr = %c\n", *ptr);				// *103		--> o


	return 0;
}































