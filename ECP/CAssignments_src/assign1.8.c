/*

Write a program to accept three integer numbers and find its average.

*/

#include<stdio.h>

int main()
{

	int num1,num2,num3,avg;

	printf("Enter three numbers: ");
	scanf("%d %d %d",&num1,&num2,&num3);

	avg=(num1+num2+num3)/3;
	printf("Average of three = %d\n",avg);

return 0;
}
