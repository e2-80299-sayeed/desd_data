#include<stdio.h>

int _power(int,int);

int main()
{

//int base,index;

//printf("Enter base and index:");
//scanf("%d %d",&base,&index);

printf("Power= %d\n",_power(2,3));

return 0;

}

int _power(int base,int index)
{
	int p = 1;
	for(int i = 0;i < index;i++)
	p*=base;
	
	return p; 
}

