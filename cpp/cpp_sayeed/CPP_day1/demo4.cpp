#include<stdio.h>

void printValue(int a)
{
    printf("\n int a=%d",a);
}
// int printValue(int a)
// {
//     printf("\n int a=%d",a);
//     return 0;
// }
void printValue(int a,int b)
{
    printf("\n int a=%d int b=%d",a,b);
}
void printValue(char a)
{
    printf("\n char a=%c",a);
}
void printValue(int a,char b)
{
    printf("\n int a=%d char b=%c",a,b);
}
void printValue(char a,int b)
{
    printf("\n char a=%c int b=%d",a,b);
}
int main()
{
    printValue(10);
    printValue(11,22);
    printValue('A');
    printValue('S',88);
    printValue(44,'V');
    return 0;
}