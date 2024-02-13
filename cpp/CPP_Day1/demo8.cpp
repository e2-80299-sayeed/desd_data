#include<stdio.h>

struct time
{
    private:
    int hr;
    int min;
    int sec;
    public:
    void acceptTime()
    {
        printf("Enter hr ,min, sec");
        scanf("%d%d%d",&hr,&min,&sec);
    }
    void printTime()
    {
        printf("\n time=%d:%d:%d",hr,min,sec);
    }
};//end of struct

int main()
{
    struct time t;
    
    // t.min=47;
    // t.sec=33;
    t.acceptTime();
    //t.hr=10;
    t.printTime();
    return 0;
}