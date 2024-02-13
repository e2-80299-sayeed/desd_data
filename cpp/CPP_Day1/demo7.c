#include<stdio.h>

struct time
{
    int hr;
    int min;
    int sec;
};//end of struct

void acceptTime(struct time *t)
{
    printf("Enter hr ,min, sec");
    scanf("%d%d%d",&t->hr,&t->min,&t->sec);
}
void printTime(struct time t)
{
    printf("\n time=%d:%d:%d",t.hr,t.min,t.sec);
}

int main()
{
    struct time t;
    // t.hr=10;
    // t.min=47;
    // t.sec=33;
    acceptTime(&t);
    printTime(t);
    return 0;
}