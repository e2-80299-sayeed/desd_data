#include<stdio.h>
//To store address of object compiler implicitly declare one pointer as a parameter inside member function. Such parameter is called this pointer.

class time
{
    private:
        int hr;
        int min;
        int sec;
    public:
        void printTime( )
        {
            printf("\n Time = %d:%d:%d",this->hr,this->min,this->sec);
        }
        void acceptTime()
        {
            printf("\n Enter Time");
            scanf("%d%d%d",&this->hr,&this->min,&this->sec);
        }
        void incrTimeByOneSec()
        {

        }
};//end of class
int main()
{
    int n1;
    time t1; //if time is class then t1-> object of time class
    printf("\n size of t1=%d",sizeof(t1)); //=>12
    t1.acceptTime();
    t1.printTime();

    time t2;
    t2.acceptTime();
    t2.printTime();

    time t3;
    t3.acceptTime();
    t3.printTime();

    return 0;
}