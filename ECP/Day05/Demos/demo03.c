#include<stdio.h>

// local/auto storage class
	// auto keyword is used
	// by default all variables are of this storage class

// Block
	// set of instructions written in { }
	// function block
	// Control block (if else, switch case, loops)
	// {} - anonymous block

void test(int num)
{
	int res = num + 1;
	printf("res = %d\n", res);
}

int main(void)
{
	int no1 = 10, no2 = 20;
	printf("Main : no1 = %d, no2 = %d\n", no1, no2);
	{
		//block1
		int no3 = 30;
		printf("Block1 : no1 = %d, no2 = %d\n", no1, no2);
		printf("Block1 : no2 = %d\n", no3);
		{
			// block2
			printf("Block2 : no1 = %d, no2 = %d\n", no1, no2);
			printf("Block2 : no2 = %d\n", no3);
		}
	}
	printf("Main : no2 = %d\n", no3);		// not accessible
	// local variables are accessible in all its inner blocks
	// local variables are not accessible in outer blocks
	// if variable is not found in current block then it is searched inside its all outer blocks
	return 0;
}































