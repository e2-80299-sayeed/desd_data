#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int len;
	
	printf("Enter lenght of array : ");
	scanf("%d", &len);
	
	int  *ptr = (int *)malloc(len * sizeof(int));
	
	if(ptr == NULL)
	{
		printf("malloc() is failed to allocate memory\n");
		exit(-1);
	}	
	
	for(int i = 0 ; i < len ; i++)
		ptr[i] = i + 10;
	
	printf("stored values: ");
	for(int i = 0 ; i < len ; i++)
		printf("%-4d", ptr[i]);
	printf("\n");
	
	free(ptr);
	
	return  0;
}
