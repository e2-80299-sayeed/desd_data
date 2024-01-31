#include<stdio.h>


int main(int argc, char *argv[], char *envp[])
{
	printf("Env Variables : \n");
	for(int i = 0 ; envp[i] != NULL ; i++)
		printf("envp[%d] = %s\n", i, envp[i]);

	return 0;
}































