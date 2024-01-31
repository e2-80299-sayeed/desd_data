#include<stdio.h>

int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);

typedef int(*ptr_t)(int,int);

int main(void)
{
	//ptr_t arr[4] = {add, sub, mul, div};
	 int(*arr[4])(int,int) = {add, sub, mul, div};
	
	for(int i = 0 ; i < 4 ; i++)
		printf("arr[%d](10, 20) = %d\n ", i, arr[i](10,20));
	
	
	

	return 0;
}


int add(int num1,int num2)
{
	return num1 + num2;

}
int sub(int num1,int num2)
{
	return num1 - num2;
}
int mul(int num1 ,int num2)
{
	return num1 * num2;
}
int div(int num1 ,int num2)
{
	return num1 / num2;
}
