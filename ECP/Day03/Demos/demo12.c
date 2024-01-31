#include<stdio.h>

// Take age from user and check whether that person can vote or not

//1. Analysis
	// will need variable to store age
	// person whose age is >= 18 can vote

//2. Algorithm - (step by step solution to given problem statement in human understandable language)
	//1. Declare variable to store age
	//2. take value of age from user
	//3. check if age is greater or eqaul to 18
	//4. if true then person can vote
	//5. if false then person can not vote

//3. Flow chart
//4. Coding

int main(void)
{
	//1. Declare variable to store age
	unsigned int age;

	//2. take value of age from user
	printf("Enter person's age : ");
	scanf("%u", &age);

	//3. check if age is greater or eqaul to 18
	if(age >= 18)
	{
		//4. if true then person can vote
		printf("Person can Vote !!!\n");
	}
	else
	{
		//5. if false then person can not vote
		printf("Persopn can not Vote !!!\n");
	}

	return 0;
}































