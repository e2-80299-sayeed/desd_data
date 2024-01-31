#include<stdio.h>
#include<string.h>


int main(void)
{
	// write strings into file

	//1. open file into write mode
	FILE *fp = fopen("file2.txt", "w");

	// 2. read strings from user and write into file
	char str[20];
	do
	{
		printf("Enter string : ");
		scanf("%s", str);
		fputs(str, fp);
	}while(strcmp(str, "bye"));

	//3. close the opned file
	fclose(fp);

	printf("Strings are written successfully\n");

	return 0;
}































