#include<stdio.h>

class time
{    
    int hr;
    int min;
    int sec;

public:
    time()// 1. name of constructor is same as its class.
          // 2. this fun is automatically called at runtime when object of that class is created, only once in its lifetime.   
          // 3. It is designed to call implicitly.
          // 4. It doesn't have any return type.  
    {
        printf("---------time()-------\n");
        this->hr = 0;//hr = 0;
        this->min = 0;
        this->sec = 0;
    }

    time(int h, int m, int s)
    {
        this->hr = h;
        this->min = m;
        this->sec = s;
    }

    // void initTime()
    // {
    //     this->hr = 0;//hr = 0;
    //     this->min = 0;
    //     this->sec = 0;
    // }

    void printTime()
    {
        printf("\n Time = %d:%d:%d\n ",hr,min,sec);
    }

    void acceptTime()
    {
        printf("\n Enter Time : ");
        scanf("%d%d%d",&hr,&min,&sec);
    }

};

int main()
{
    int n1;
    time t1;
    //t1.initTime();
    t1.printTime();
    t1.acceptTime();
    t1.printTime();

    time t2(12,11,25);
    t2.printTime();
    t2.acceptTime();
    t2.printTime();
    return 0;
}

//constructor are of three types :
//1. parameterless constructor
//2. paramteterized constructor
//3. Default constructor
