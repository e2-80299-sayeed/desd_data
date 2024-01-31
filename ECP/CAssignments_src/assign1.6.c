#include<stdio.h>

int main(void)
{

int num;

printf(" Multiplication table of : ");
scanf("%d",&num);

for(int i=1;i<=10;i++)
printf(" %d x %d = %d\n",num,i,num*i);


return 0;
}
