#include<stdio.h>

/*
// FILE *fopen(const char *pathname, const char *mode);
	// arg1 - path to the file
	// arg2 - mode (r/w/a)
			- r - file is opened for reading 
				(if file doesn't exist it will not be created, error)
			- w - file is opened for writing 
				(if file doesn't exist it will be created)
				(if file exist old data will be over written)
			- a - file is opned to append data at the end
				(if file doesn't exist it will be created)
				(if file exist new data will be appended at the end)

			- r+ - read + write
			- w+ - write + read
			- a+ - append + read


		// Text file - r/w/a/r+/w+/a+
		// Binary file - rb/wb/ab/rb+/wb+/ab+

	// return type - FILE * 


//  int fclose(FILE *stream);
	// arg1 - file pointer
*/

int main(void)
{
	// write character by character into file
	char ch;

	//1. open file into write mode
	FILE *fp = fopen("file1.txt", "w");

	//2. take data from user and write it into file
	printf("Enter data to be added into file : ");
	do
	{
		scanf("%c", &ch);
		fputc(ch, fp);
	}while(ch != '\n');	

	//3. close the opend file
	fclose(fp);

	printf("Data is written successfully\n");
	return 0;
}































