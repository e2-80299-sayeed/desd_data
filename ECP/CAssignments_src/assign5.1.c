/*
1. Write a program to accept marks of five subjects, calculate its total and average.
*/

#include<stdio.h>

int main(void)
{
	float arr[5], total, avg;
	
	printf("Enter marks of 5 subjects : ");
	
	for(int i = 0; i < 5; i++)
	scanf("%f",&arr[i]);	
	
	//printf("Marks of 5 subjects : ");
		
	//for(int i = 0; i < 5; )
	//{
		total = arr[0] + arr[1] + arr[2] + arr[3] + arr[4];
	
	//}
	
	printf(" total = %.2f\n", total);
	printf("Average = %.2f\n",total/5);





	return 0;
}
