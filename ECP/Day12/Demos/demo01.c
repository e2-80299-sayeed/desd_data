#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int length = 20;
	
	// allocate memory dynamically for 20 bytes
	// char *name = (char *)malloc(length * sizeof(char));
	char *name = (char *)calloc(length, sizeof(char));
	// err check

	// store name (string) in allocated space
	printf("Enter name : ");
	scanf("%s", name);

	// read and display name from memory
	printf("Name : %s\n", name);

	// release the allocated space
	free(name);

	return 0;
}































