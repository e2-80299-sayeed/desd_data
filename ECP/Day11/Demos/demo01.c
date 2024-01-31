#include<stdio.h>
#include<string.h>

int main(void)
{
//	int num = 10;
//	float flt;

//	memcpy(&flt, &num, sizeof(num));

//	printf("flt = %f\n", flt);
//	printf("flt = %d\n", *((int *)&flt));

	char str1[] = "123456";
//	char *str2 = "654321";	//error
	char str2[] = "654321";

	printf("before : str1 = %s, str2 = %s\n", str1, str2);

	memcpy(str2, str1, sizeof(str1));

	printf("after : str1 = %s, str2 = %s\n", str1, str2);
	return 0;
}































