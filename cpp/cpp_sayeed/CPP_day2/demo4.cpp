#include<stdio.h>
class time
{
    private:
        int hr;
        int min;
        int sec;
    public:
        time() //Parameterless constructor 
        {
            printf("\n -----time()-----");
            this->hr=0;
            this->min=0;
            this->sec=0;
        }
        time(int h,int m,int s) //Parameterized constructor / Constructor overloading
        {
            printf("\n -----time(int,int,int)-----");
            this->hr=h;
            this->min=m;
            this->sec=s;
        }
        void initTime()
        {
            this->hr=0;
            this->min=0;
            this->sec=0;
        }
        void setMin(int min) //Mutators / setter 
        {
            this->min=min;
        }
        void setHr(int hr) //Mutators / setter 
        {
            this->hr=hr;
        }
        void setSec(int sec) //Mutators / setter 
        {
            this->sec=sec;
        }
        int getSec()//inspector/getter 
        {
            return this->sec;
        }
        int getHr()//inspector/getter 
        {
            return this->hr;
        }
        int getMin()//inspector/getter 
        {
            return this->min;
        }
        void printTime()//Facilitator
        {
            printf("\n Time = %d:%d:%d",hr,min,sec);
        }
        void acceptTime() //Facilitator
        {
            printf("\n Enter Time");
            scanf("%d%d%d",&hr,&min,&sec);
        }
        ~time() //Destructor
        {
            printf("\n ----- ~time() -----");
        }
};
int main()
{
    // time t1;
    // t1.printTime();

    // time t2;
    // t2.printTime();

    time t_p(8,15,20); //8:15:20
    // t_p.min=5;
    t_p.printTime();
    t_p.setMin(5);
    t_p.printTime();
    int s=t_p.getSec();
    printf("\n value of sec=%d",s);




    // time t_n(9,30,45); //9:30:45
    // t_n.printTime();
    return 0;
}
