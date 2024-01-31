#include<stdio.h>

char *strupr(char *s);
char *strlwr(char *s);

int main(void)
{
	char str[20] = "DesD";

	printf("str = %s\n", str);
	strupr(str);
	printf("after strupr : str = %s\n", str);
	strlwr(str);
	printf("after strlwr : str = %s\n", str);
	
	return 0;
}

char *strupr(char *s)
{
	for(int i = 0 ; s[i] != '\0' ; i++)
	{
		if(s[i] >= 97 && s[i] <= 122)
			s[i] -=32;			// s[i] = s[i] - 32
	}
	return s;
}

char *strlwr(char *s)
{
	for(int i= 0 ; s[i] != '\0' ; i++)
	{
		if(s[i] >= 65 && s[i] <= 90)
			s[i] += 32;
	}
	return s;
}





























