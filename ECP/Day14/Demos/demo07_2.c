#include<stdio.h>


int main(void)
{
	// read from file string by string
	char str[4];

	// 1. open file into read mode
	FILE *fp = fopen("file2.txt", "r");

	// 2. read string from file and print on console
	while(fgets(str, sizeof(str), fp) != NULL)
		printf("%s\n", str);

	// 3. close the opend file
	fclose(fp);
	return 0;
}































