#include<stdio.h>
#include<string.h>

// memcpy - copy memory area

// void *memcpy(void *dest, const void *src, size_t n);

int main(void)
{
	int arr1[] = {11, 22, 33, 44, 55};
	
	printf("arr1 : ");
	for(int i = 0 ; i < 5 ; i++)
		printf("%-4d", arr1[i]);
	printf("\n");

	int arr2[3] = {10, 20, 30};

	memcpy(arr2, arr1, 3 * sizeof(arr1[0]));
	//memcpy(arr2, arr1, 12);
	
	printf("arr2 : ");
	for(int i = 0 ; i < 3 ; i++)
		printf("%-4d", arr2[i]);
	printf("\n");

	char str1[20] = "sun";
	char str2[20] = "sunbeam";

	printf("before  : str2 = %s\n", str2);
	
	memcpy(str2+3, str1, 3);

	printf("after : str2 = %s\n", str2);

	return 0;
}































