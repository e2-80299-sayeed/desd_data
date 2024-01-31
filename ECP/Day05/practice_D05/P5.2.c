#include<stdio.h>


//function declaration
void print_msg(void);
void print_number(int);
int addition(int,int);

int main(void)
{

int no1,no2,sum;

printf("Enter no1 and no2 :");
scanf("%d %d",&no1,&no2);

print_msg();
print_number(no1);

sum=addition(no1,no2);
print_number(sum);
return 0;
}



	void print_msg(void)
	{	

	printf("I'm feeling tired\n");

	}


void print_number(int num)	
{	

printf("number = %d\n",num);

}

	int addition(int num1,int num2)
	{
	int res;
	res = num1+num2;

	return res;
	}
