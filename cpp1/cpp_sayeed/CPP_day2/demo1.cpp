#include<stdio.h>

struct time
{
    private:
        int hr;
        int min;
        int sec;
    public:
        void printTime( )
        {
            printf("\n Time = %d:%d:%d",hr,min,sec);
        }
        void acceptTime()
        {
            printf("\n Enter Time");
            scanf("%d%d%d",&hr,&min,&sec);
        }
        void incrTimeByOneSec()
        {

        }
};//end of struct
int main()
{
    int n1;
    struct time t1; //if time is struct then t1-> veri of struct
    t1.acceptTime();
    //t1.hr=1;
    t1.printTime();
    return 0;
}