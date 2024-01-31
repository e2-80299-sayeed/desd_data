#include<stdio.h>

// $ ./mycp.out <src> <dest>
// argv[0] = ./mycp.out
// argv[1] = src			--> read
// argv[2] = dest			--> write

int main(int argc, char *argv[])
{	
	printf("src = %s, dest = %s\n", argv[1], argv[2]);
	char ch;
	//1. open src file into read mode
	FILE *fs = fopen(argv[1], "r");

	//2. open dest file into write mode
	FILE *fd = fopen(argv[2], "w");

	//3. read character by character from src file and write into dest file
	while((ch = fgetc(fs)) != EOF)
		fputc(ch, fd);

	//4. close src file
	fclose(fs);

	//5. close dest file
	fclose(fd);

	printf("File is copied successfully\n");
	return 0;
}































