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
    time(int duration)//1 para
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
        return hr*60+min;
    }
};


int main()
{
    time t1=130;
    t1.printTime();

    time t2;
    t2.printTime();
    t2=140;  //constructor as a conversion function
    t2.printTime();

    int duration=t2;
    cout<<"\nDuration="<<duration;


    return 0;
}