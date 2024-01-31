#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(void)
{
	printf("Range of unsigned char : %d to %d\n", 0, UCHAR_MAX);
	printf("Range of signed char : %d to %d\n", CHAR_MIN, CHAR_MAX);

	printf("Range of unsigned short : %d to %d\n", 0, USHRT_MAX);
	printf("Range of signed short : %d to %d\n", SHRT_MIN, SHRT_MAX);
	
	printf("Range of float : %e to %e\n", FLT_MIN, FLT_MAX);
	return 0;
}































