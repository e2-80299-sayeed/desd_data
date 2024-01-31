#include<stdio.h>
#include"header.h"
#include"header.h"


// conditional compilation
// #if, #elif, #else #endif
// #ifdef, #ifndef

#define VERSION 3

int main(void)
{

#if VERSION == 1
	printf("This is version 1\n");
#elif VERSION == 2
	printf("This is version 2\n");
#else
	printf("This is else version\n");
#endif
	return 0;
}































