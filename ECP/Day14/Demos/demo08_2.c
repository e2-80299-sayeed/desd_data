#include<stdio.h>


int main(void)
{
	int num;
	char ch;
	double d;

	//1. open file into read mode
	FILE *fp = fopen("file3.txt", "r");

	//2. read data from file and print on console
	// fscanf(file pointer, "format string", ...);
	fscanf(fp, "%d %c %lf", &num, &ch, &d);

	printf("num = %d\nch = %c\nd = %lf\n", num , ch, d);

	return 0;
}































