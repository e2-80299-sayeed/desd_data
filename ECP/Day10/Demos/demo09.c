#include<stdio.h>


int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);
	printf("Executable name : %s\n", argv[0]);
	
	printf("Cmd Line args : \n");
	for(int i = 0 ; i < argc ; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	/*
	printf("Cmd Line args : \n");
	while(*argv != NULL)
	{
		printf("*argv = %s\n", *argv);
		argv++;
	}
	printf("argv = %u\n", *argv);
	*/
	
	printf("Cmd Line args : \n");
	int i = 0;
	while(*(argv + i) != NULL)
	{
		printf("*(argv + %d) = %s\n", i, *(argv + i));
		i++;
	}
	return 0;
}































