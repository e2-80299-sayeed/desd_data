#include<stdio.h>

/*
Function
	- function can take input via its arguments
	- function can give output via its return value
	- Every function has three different things:
		- declaration
			- information to compiler
			- syntax:
				<return type> <function name>([List of datatypes of arguments]);
			- eg. int fun(int, char);

		- definition
			- body, logic, code
			- syntax
				<return type> <function name>([List of variables])
				{
					// code
				}
			- eg int fun(int n, char c)
				 {
				 	// process the input via variable names (n , c);
				 }
		
		- calling
			- function is not automatically called, we need to call it
			in flow of execution of program
			- syntax:
				<funaction name>([List of input varaibles]);
			- eg. int n1 = 10; char ch = 'A';
				  fun(n1, ch);

*/

// function declaration/prototype/signature
void print_msg(void);
void print_number(int);
int addition(int, int);

// global space

int main(void)
{
	// local space
	int no1 = 10, no2 = 20, sum;
	// function calling
	print_msg();
	print_number(no1);
	// variable which are passed during function call, are called as "actual arguments"
	// when any function is called, actual arguments are copied into formal arguments
	// at the time calling, datatype is not written
	// we can return only one value from function
	sum = addition(no1, no2);
	print_number(sum);
	return 0;
}


// function definition
void print_msg(void)
{
	printf("This is my first function\n");
}

// variables which are used in function definition are called as "formal arguments"
void print_number(int num)
{
	printf("number = %d\n", num);
}

int addition(int num1, int num2)
{
	int res = num1 + num2;
	print_number(res);
	return res;
}





























