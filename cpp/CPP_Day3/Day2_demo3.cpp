#include<stdio.h>

class time
{
    private:
    int hr;
    int min;
    int sec;
    public:
    // time()//Constructor : object initialization
    // {
    //     printf("\n ---- time()------ ");
    //     this->hr=0;
    //     this->min=0;
    //     this->sec=0;
    // }

    //Constructor : object initialization
    time(int h=0,int m=0,int s=0):hr(h),min(m),sec(s)
    {
        printf("\n ---- time(int h,int m,int s)------ ");
        // this->hr=h;
        // this->min=m;
        // this->sec=s;
    }
    void initTime()
    {
        this->hr=0;
        this->min=0;
        this->sec=0;
    }
    void setMin(int min)  //Mutators / setter 
    {
        if(min<60 && min>=0)
                this->min=min;
        else
            printf("\n invalid data");
    }
    //setHr(int hr){}
    //setSec(int sec){}
    int getHr()  //inspector/getter
    {
        return this->hr;
    }
    //getMin()
    //getSec()
    void acceptTime() //Facilitator
    {
        printf("Enter hr ,min, sec");
        scanf("%d%d%d",&this->hr,&this->min,&this->sec);
    }
    void printTime()//Facilitator
    {
        printf("\n time=%d:%d:%d",hr,min,sec);
    }
    void incrTimeByOneSec()  //Facilitator
    {
        this->sec++;
        if(this->sec>=60)
        {
            this->sec=0;
            this->min++;
        }
        if(this->min>=60)
        {
            this->min=0;
            this->hr++;
        }
        if(this->hr>=24)
        {
            this->hr=0;
        }
    }
    ~time()  //Destructor
    {
        printf("\n ----- ~time()----");
    }
};//end of class

int main()
{   
    time t1;
    t1.printTime();

    time t2;
    t2.acceptTime();
    t2.printTime();
    t2.incrTimeByOneSec();
    t2.printTime();

    time t_p(8,30,23);
    t_p.setMin(88);
    t_p.setMin(20);
   // t_p.min=20;
    //8:20:44
    t_p.printTime();

   int hr= t_p.getHr();
   printf("\n hr=%d",hr);

    time t_v(7,15,44);
    t_v.printTime();
    
    
    return 0;
}