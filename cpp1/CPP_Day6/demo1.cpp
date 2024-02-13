#include<iostream>
using namespace std;

class base
{
    public:
    int b;
    void funB()
    {
        cout<<"\n ---B::funB()--";
    }
};

//child:parent
class derived:public base
{
    public:
    int d;
    void funD()
    {
        cout<<"\n ---D::funD()--";
    }
};


int main()
{
    base b1;
    cout<<"\n size of b1="<<sizeof(b1);
    b1.funB();

    derived d1;
    cout<<"\n size of d1="<<sizeof(d1);
    d1.funD();
    d1.funB();

    cout<<"\n";
    return 0;
}