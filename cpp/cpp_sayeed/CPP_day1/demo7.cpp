#include<stdio.h>

struct time
{
    int hr;
    int min;
    int sec;
};
void printTime(struct time t1 )
{
    printf("\n Time = %d:%d:%d",t1.hr,t1.min,t1.sec);
}

void acceptTime(struct time *t1)
{
    printf("\n Enter Time");
    scanf("%d%d%d",&t1->hr,&t1->min,&t1->sec);
}
int main()
{
    int n1;
    struct time t1;
    t1.hr=10;
    t1.min=59;
    t1.sec=44;
    printTime(t1);
    acceptTime(&t1);
    printTime(t1);
    return 0;
}