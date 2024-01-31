#include<stdio.h>

int add(int,int);
int sub(int,int);

int main(void)
{
	printf("add(10,20) = %d\n",add(10,20));
	
	int (*ptr)(int,int) = add;
	
	//ptr = add;
	
	printf("add = %u\n",add);
	printf("ptr = %u\n",ptr);
	
	
	printf("ptr(10,20) = %d\n",ptr(10,20));
		
	ptr = sub;
	
	printf("ptr(10,20) = %u\n",ptr);
	printf("sub(10,20) = %u\n",sub);
	
	printf("sub(10,20) = %d\n",sub(10,20));
	printf("ptr(10,20) = %d\n",ptr(10,20));
	
	return 0;
}


int add(int num1 ,int num2)
{
	return num1 + num2;

}

int sub(int num1 ,int num2)
{
	return num1 - num2;	

}
