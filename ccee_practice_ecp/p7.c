#include <stdio.h>
int num=5;
void fun(void);
int main(void)
{
int num=3;
for (fun(); ++num<5; fun())
{
fun();
}
}
void fun(void)
{
printf("%d",++num);
}
