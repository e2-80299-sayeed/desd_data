#include<stdio.h>

int add(int,int);
int sub(int,int);
int mul(int,int);
int div(int,int);

typedef int(*ptr_t)(int,int);
ptr_t ptr1, ptr2, ptr3, ptr4; //ptr_t is a type and ptr1, ptr2, ptr3, ptr4 are varaibles. if we do not write typedef then it is only consider as variable only.

int main(void)
{
	ptr1 = add;
	printf("ptr1(10,20) = %d\n",ptr1(10,20));
	
	ptr2 = sub;
	printf("ptr2(10,20) = %d\n",ptr2(10,20));
	
	ptr3 = mul;
	printf("ptr3(10,20) = %d\n",ptr3(10,20));
	
	ptr4 = div;
	printf("ptr4(20,10) = %d\n",ptr4(20,10));
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
