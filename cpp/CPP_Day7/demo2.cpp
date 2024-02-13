#include<iostream>
using namespace std;

class shape
{
    public:
    virtual void  calArea()=0;
    virtual void calPeri()=0;
};
class rect:public shape
{
    int l,b;
    public:
    rect(int ll=1,int bb=1)
    {
        l=ll;
        b=bb;
    }
    void calArea()
    {
        cout<<"\narea of rect="<<l*b;
    }
    void calPeri()
    {
        cout<<"\nperi of rect="<<2*(l+b);
    }
};
class circle:public shape
{
    int r;
    public:
    circle(int rr=3)
    {
        r=rr;
    }
    void calArea()
    {
        cout<<"\narea of circle="<<3.14*r*r;
    }
    void calPeri()
    {
        cout<<"\nperi of circle="<<2*3.14*r;
    }
};


int main()
{
    shape *sptr=NULL;
    rect r1(3,5);
    circle c1(12);
    int ch=1;
    do
    {
       cout<<"\nEnter 1:rect  2:circle 0:exit";
       cin>>ch;
       switch (ch)
       {
       case 1: sptr=&r1;
           break;
       case 2: sptr=&c1;
           break;
       }
        if(sptr!=NULL)
        {
            sptr->calArea();
            sptr->calPeri();
        }
        sptr=NULL;
    } while (ch!=0);
    


    // shape sp;
    // sp.calArea();
    // sp.calPeri();

    // shape *sptr=NULL;
    // rect r1(3,5);
    // sptr=&r1;
    // // r1.calArea();
    // // r1.calPeri();
    // sptr->calArea();
    // sptr->calPeri();


    // circle c1;
    // //c1.calArea();
    // //c1.calPeri();
    // shape *sptr=NULL;
    // sptr=&c1;
    // sptr->calArea();
    // sptr->calPeri();






}
