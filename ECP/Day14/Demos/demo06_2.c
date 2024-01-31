#include<stdio.h>


int main(void)
{
	// read character by character from file
	char ch;

	//1. open file into read mode
	FILE *fp = fopen("file1.txt", "r");

	//2. read data from file character by character and print on console
	printf("File content : \n");
	while((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	//3. close the opened file
	fclose(fp);

	return 0;
}































