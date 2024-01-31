#include<stdio.h>
#include<string.h>

// strlen - calculate length of string
// size_t strlen(const char *s);
	// arg - address of string (character array)
	// return value - no of characters

size_t my_strlen(const char *s)
{
	int len = 0;
	for(int i =  0 ; s[i] != '\0' ; i++)
		len++;
	//s[2] = '@';	-- error
	return len;
}

int main(void)
{
	char str[] = "PG-DESD";
	
	printf("str = %s\n", str);
	printf("length = %lu\n", strlen(str));
	printf("length = %lu\n", my_strlen(str));

	printf("str = %s\n", str);
	return 0;
}































