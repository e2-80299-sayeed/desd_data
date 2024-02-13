#include<iostream>
using namespace std;

//parent class
class base 
{
    public:
        int b;
        void funBase()
        {
            cout<<"\n -----funBase()-----";
        } 
};

//child class
class derived : public base // inheritance  default mode is private
{
    public:
    int d;
    void funDerived()
    {
        cout<<"\n -----funDerived()-----";
    }

};

int main()
{
    base b1;
    cout<<"\n size of base b1="<<sizeof(b1);
    b1.funBase();

    derived d1;
    cout<<"\n size of derived d1="<<sizeof(d1);
    d1.funDerived();

    return 0;
}