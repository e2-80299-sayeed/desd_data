#include<stdio.h>

void sunbeam(int *p)
{
	++*p;
	*p++;
}

int main()
{
	int a=4;
	sunbeam(&a);
	printf("value= %d\n",a);

}
