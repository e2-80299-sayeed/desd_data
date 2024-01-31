//1. Write a function to count number of ‘1’ bits into a given number.

#include<stdio.h>

int binary_recursion(unsigned char num)
{
	static int count;
		
	if(num == 0)
		return count;
	unsigned char rem = num % 2;
	
	if(rem == 1)
		count++;
	binary_recursion(num/2); 


}
int main (void)
{
	int num;
	
	printf("Enter number: ");
	scanf("%d",&num);
	
    int	count = binary_recursion(num);
	printf("count = %d \n",count);
	return 0;

}

