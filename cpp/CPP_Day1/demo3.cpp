#include<stdio.h>

int add(int a=0,int b=0,int c=0,int d=0)
{
    int r=a+b+c+d;
    printf("\n a=%d  b=%d  c=%d   d=%d ",a,b,c,d);
    return r;
}

int main()
{
    int r;
    r=add();
    r=add(1);
    r=add(1,2);
    r=add(1,2,3);
    r=add(1,2,3,4);

   // printf("result=%d",r);
    return 0;
   
}