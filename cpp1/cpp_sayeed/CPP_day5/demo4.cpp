
#include<iostream>
using namespace std;
class shape
{
    public:
        virtual void input()
        {
            //?
            cout<<"\n ------shape::input()----";
        }
        virtual void calArea()
        {
            //?
            cout<<"\n ------shape::calArea()----";
        }
};

class rect:public shape
{
    int l,b;
    public:
        void input()
        {
            cout<<"\n enter l and b";
            cin>>l>>b;  
        }
        void calArea()
        {
            int a;
            a=l*b;
            cout<<"\n Area of Rect="<<a; 
        }
};

class circle:public shape
{
    int r;
    public:
        void input()
        {
            cout<<"\n enter redius";
            cin>>r;  
        }
        void calArea()
        {
            int a;
            a=3.14*r*r;
            cout<<"\n Area of Circle="<<a; 
        }
};
int main()
{
    shape *sptr=NULL;
    rect r1;
    circle c1;
    int ch;
    do
    {
        cout<<"\n Enter choice 1:rect 2:circle 0:Exit";
        cin>>ch;
        switch (ch)
        {
        case 1: //rect
            sptr=&r1;
            break;
        case 2://circle
            sptr=&c1;
            break;
        }
        if(sptr != NULL)
        {
            sptr->input();
            sptr->calArea();
        }
       sptr = NULL;
    } while (ch!=0);
    











    // shape sh;
    // sh.input();
    // sh.calArea();

    // rect r1;
    // r1.input();
    // r1.calArea();

    // circle c1;
    // c1.input();
    // c1.calArea();
    cout<<"\n";
    return 0;
}