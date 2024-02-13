#include<stdio.h>

int add(int a,int b);

int main()
{
    int r;
    r=add(22,33);
    printf("result=%d",r);
    return 0;
}

int add(int a,int b)
{
    int c=a+b;
    return c;
}