#include<stdio.h>

// int fseek(FILE *stream, long offset, int whence);
	// arg1 - file pointer which position you want to change
	// arg2 - offset (number of bytes) by which you want change the position
		// offset can be positive or negative
		// positive - go ahead by specifed number of bytes
		// negative - go behind by specified number of bytes
	// arg3 - from where you want to change the position
		// SEEK_SET - from starting of file (+)
		// SEEK_CUR - from current position (+/-)
		// SEEK_END - from end of file (-)

int main(void)
{
	char ch;
	FILE *fp = fopen("fseek.txt", "r");
	
	//fseek(fp, 5, SEEK_SET);			// change by 5 bytes from starting of file
	//fseek(fp, -5, SEEK_END);			// change by 5 bytes from ending of file

	fseek(fp, 10, SEEK_SET);		// 11
	//fseek(fp, 5, SEEK_CUR);			// 16
	fseek(fp, -5, SEEK_CUR);			// 6

	while((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	fclose(fp);

	return 0;
}































