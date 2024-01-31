/*
3. Write a function to remove all occurrences of given character from the string.
*/

#include<stdio.h>

int main(void)
{

	char str[20] = "I am a student";
	char ch = ' ';
	
	printf("String Before removing given char : %s\n",str);

	int j,i;
	for( i = 0; str[i] != '\0'; )
	

		if(str[i] != ch)
		str[j++] = str[i];
			
	str[j] = '\0';		
		

 /*
    int j, n = strlen(s);
    for (int i = j = 0; i < n; i++)
        if (s[i] != c)
            s[j++] = s[i];
 
    s[j] = '\0';

*/
	printf("String After removing given char : %s\n",str);

	return 0;
}

/*
void removeChar(char* s, char c)
{
 
    int j, n = strlen(s);
    for (int i = j = 0; i < n; i++)
        if (s[i] != c)
            s[j++] = s[i];
 
    s[j] = '\0';
}*/
