
#include<stdio.h>
void printValue(int a)
{
    printf("\n int a=%d",a);
}
void printValue(char a)
{
    printf("\n char a=%c",a);
}
void printValue(int a,int b)
{
    printf("\n int a=%d int b=%d",a,b);
}
void printValue(char ch,int a)
{
    printf("\n char ch=%c  int a=%d",a,ch);
}
void printValue(int a ,char ch)
{
    printf("\n int a=%d  char ch=%c",a,ch);
}
int main()
{
    printValue(11);
    printValue('B');
    printValue(12,'a');
    printValue(11,22);
    printValue('T',7);

    return 0;
}