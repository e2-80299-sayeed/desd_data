#include<stdio.h>


int main(void)
{
	int num = 10;
	char ch = 'A';
	double pi = 3.142;

	//1. Open file into write mode
	FILE *fp = fopen("file3.txt", "w");

	printf("%d %c %lf\n", num, ch, pi);
	// printf("format string", ...);
	
	//2. write data(variables) into file
	// fprintf(File stream, "format string", ...);
	fprintf(fp, "%d %c %lf\n", num, ch, pi);

	//3. close the opened file
	fclose(fp);

	printf("Variable values are written successfully\n");

	return 0;
}































