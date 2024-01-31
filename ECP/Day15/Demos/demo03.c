#include<stdio.h>
#include<string.h>


int main(void)
{
	char str1[64] = "PG-DESD Sunbeam Infotech";

	//1. Write array into file
	FILE *fp = fopen("str.txt", "wb");
	int ret = fwrite(str1, sizeof(char), strlen(str1), fp);
	printf("%d bytes are written into file\n", ret);
	fclose(fp);


	//2. Read from file
	char ch;
	fp = fopen("str.txt", "rb");

	printf("Data read from file :\n");
	while((fread(&ch, sizeof(char), 1, fp)) != 0)
		printf("%c", ch);
	printf("\n");

	fclose(fp);

	return 0;
}































