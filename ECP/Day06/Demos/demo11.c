#include<stdio.h>

typedef enum test{
	TEST
}test_t;

int main(void)
{
	printf("sizeof(char *) = %ld\n", sizeof(char *));
	printf("sizeof(short *) = %ld\n", sizeof(short *));
	printf("sizeof(int *) = %ld\n", sizeof(int *));
	printf("sizeof(long *) = %ld\n", sizeof(long *));
	printf("sizeof(float *) = %ld\n", sizeof(float *));
	printf("sizeof(double *) = %ld\n", sizeof(double *));
	printf("sizeof(test_t *) = %ld\n", sizeof(test_t *));

	printf("SF(char *) = %ld\n", sizeof(char));
	printf("SF(short *) = %ld\n", sizeof(short));
	printf("SF(int *) = %ld\n", sizeof(int));
	printf("SF(long *) = %ld\n", sizeof(long));
	printf("SF(float *) = %ld\n", sizeof(float));
	printf("SF(double *) = %ld\n", sizeof(double));
	printf("SF(test_t *) = %ld\n", sizeof(test_t));
	return 0;
}































