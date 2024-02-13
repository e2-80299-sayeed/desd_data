#include<stdio.h>

class time
{    
    int hr;
    int min;
    int sec;

public:
    	time()// 1. name of constructor is same as its class. //parameterless
          // 2. this fun is automatically called at runtime when object of that class is created, only once in its lifetime.   
          // 3. It is designed to call implicitly.
          // 4. It doesn't have any return type.  
    {
        printf("---------time()-------\n");
        this->hr = 0;//hr = 0;
        this->min = 0;
        this->sec = 0;
    }

    time(int h, int m, int s) //parameterized constructor / constrcutor overloading
    {
        printf("---------time()-------\n");
        this->hr = h;
        this->min = m;
        this->sec = s;
    }

     void initTime()
     {
         this->hr = 0;//hr = 0;
         this->min = 0;
         this->sec = 0;
     }

    void setMin(int min) //Mutators / setter
    {
        this->min = min;// here this pointer is compulsory because min which is a local will be assign itself if we write min=min 
                        // as it has higher priority than min data member which is global 
    }

    int getSec() //inspector / getter
    {
        return this->sec;
    }

    int getMin()
    {
        return this->min;
    }

    int getHr()
    {
        return this->hr;
    }

    void printTime() // Facilitator
    {
        printf("\n Time = %d:%d:%d\n ",hr,min,sec);
    }

    void acceptTime() // Facilitator
    {
        printf("\n Enter Time : ");
        scanf("%d%d%d",&hr,&min,&sec);
    }

    ~time() // Destructor : 1. " ~ " is used before function name indicates it is a destructor.
            //              2. destructor cannot be overloaded. 

    {
        printf("---------~time()--------\n");
    }

};

int main()
{
    int n1;
    time t1;
    t1.initTime();
    t1.setMin(5);
    t1.printTime();
    t1.acceptTime();
    t1.printTime();

    time t2(12,11,25);
    int hr = t2.getHr();
    t2.printTime();
    printf("t2 hr = %d", hr);
    t2.acceptTime();
    t2.printTime();
    return 0;
}


