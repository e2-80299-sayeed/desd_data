#include<stdio.h>

class time
{
    private:
    int hr;
    int min;
    int sec;
    public:
    void acceptTime()
    {
        printf("Enter hr ,min, sec");
        scanf("%d%d%d",&this->hr,&this->min,&this->sec);
    }
    void printTime()
    {
        printf("\n time=%d:%d:%d",hr,min,sec);
    }
};//end of class

int main()
{   //class object
     time    t;
    // t.min=47;
    // t.sec=33;
    t.acceptTime();//t-> current object
    //t.hr=10;
    t.printTime();

    time t1;
    t1.acceptTime();
    t1.printTime();

    time t2;
    t2.acceptTime();
    t2.printTime();
    return 0;
}