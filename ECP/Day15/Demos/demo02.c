#include<stdio.h>

// size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
	// arg1 - address where you want to store data read from file
	// arg2 - size of one item
	// arg3 - number of items to be read from file
	// arg4 - file pointer returned from fopen
	// return - number of items read from file (0 - EOF/error)

// size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
	// arg1 - address from where you want to write data into file
	// arg2 - size of one item
	// arg3 - number of items to be written into file
	// arg4 - file pointer returned from fopen
	// return - number of items written into file (0 - EOF/error)

int main(void)
{
	// writing data into file
	int arr1[5] = {11, 22, 33, 44, 55};

	//1. open file into write mode
	FILE *fp = fopen("arr.txt", "wb");

	//2. write array elements into file
	int ret = fwrite(arr1, sizeof(arr1[0]), 5, fp);

	printf("ret = %d\n", ret);
	
	//3. close the opened file
	fclose(fp);

	// reading data from file
	//1. open file into read mode
	fp = fopen("arr.txt", "rb");

	//2. read data from file and print on console
	int arr2[5];
	ret = fread(arr2, sizeof(arr2[0]), 5, fp);
	
	printf("Array : ");
	for(int i = 0 ; i < 5 ; i++)
		printf("%-4d", arr2[i]);
	printf("\n");
	
	printf("ret = %d\n", ret);

	//3. close the file 
	fclose(fp);

	return 0;
}































