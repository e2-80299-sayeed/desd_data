#include<stdio.h>
#include<string.h>

// memset - fill memory by given character

// void *memset(void *s, int c, size_t n);

int main(void)
{
	int num;
	
	memset(&num, 0, sizeof(num));
	printf("num = %d\n", num);			// 0
	
	memset(&num, 1, sizeof(num));
	printf("num = %d\n", num);			// 0x 01 01 01 01
	printf("num = %x\n", num);			// 0x 01 01 01 01

	double d;

	memset(&d, 0, sizeof(d));
	printf("d = %lf\n", d);

	int arr[5];

	memset(arr, 0, sizeof(arr));
	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)	
		printf("%-4d", arr[i]);
	printf("\n");

	memset(arr, '#', sizeof(arr));
	// arr[i] -- *(arr + i) - 4 bytes
	//	?	- 1 byte
	// char *ptr = (char *)arr;
	// *ptr - 1 bytes

	printf("Individul characters of arr : ");
	char *ptr = (char *)arr;
	for(int i = 0 ; i < 20 ; i++)
		printf("%-3c", ptr[i]);
	printf("\n");

	char str[128] =  "sunbeam institue of Information technology";

	printf("str = %s\n", str);

	memset(str+7, '@', 10);		// str->100	str+7->107

	printf("str = %s\n", str);

	return 0;
}































