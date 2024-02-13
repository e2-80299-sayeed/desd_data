#include<iostream>
using namespace std;

class time
{
    int hr,min;
    public:
    time()
    {
        cout<<"\n ----time()---";
        hr=min=0;
    }
    time(int duration)
    {
        cout<<"\n ----time(int)---";
        hr=duration/60;
        min=duration%60;
    }
    void printTime()
    {
        cout<<"\n time="<<hr<<":"<<min<<":0";
    }
    operator int()
    {
        return this->hr*60+min;
    }
    
};


int main()
{

    time t1;
    t1.printTime();
    t1=125;
    t1.printTime();
   
    time t2;
    t2=87;
    t2.printTime();
    int duration=t2;
    cout<<"\n int duration="<<duration;


    return 0;
}