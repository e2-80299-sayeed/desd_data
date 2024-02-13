#include<iostream>
#include<unistd.h>
using namespace std;

class shape // class with atleast 1 pure virtual function is declared as Abstract class
            
{   
    public:
    virtual void input()=0; // function overriding eg. of runtime polymorphism
    virtual void calArea()=0;//pure virtual function are assigned to zero
};

class rect : public shape
{
    int l,b;
    int area;
    public:
        void input()
        {
            cout<<"\n enter l and b of rectangle: ";
            cin>>l>>b;
        
        }

        void calArea()
        {
            area = l * b;
            cout<<"Area of rectangle= "<<area;
        }
};

class circle : public shape
{
    int rad;
    float area;
    public:
        void input()
        {
            cout<<"Enter radius= ";
            cin>>rad;
        }

        void calArea()
        {
            area = 3.142*rad*rad;
            cout<<"Area= "<<area ;
        }


};

class square : public shape
{
    int s;
    int area;
    public:

        void input()
        {
            cout<<"Enter side of square :";
            cin>>s;
        }

        void calArea()
        {
            area = s * s;
            cout<<"Area of square= "<<area;
        }
};

int main()
{

    // shape sh;  // we cannot create a object of abstract class.
    // sh.input();
    // sh.calArea();

    shape *sptr=NULL; //but we can create its pointer to achive runtime polymorphism.
    rect r1;
    circle c1;
    square sq1;
    int ch;
    do
    {
        cout<<"\n0.Exit\n1.Rectangle\n2.Circle\n3.Sqaure\n";
        cout<<"Enter choice : ";
        cin>>ch;

        switch (ch)
        {
        case 0:
            _exit(0);
            break;
        case 1:
            sptr=&r1;
            break;
        case 2:
            sptr=&c1;
            break;
        case 3:
            sptr=&sq1;
            break;
        default:
            cout<<"Enter valid choice !!";
            sptr = NULL;
            break;
        }
        if(sptr != NULL)
        {
            sptr->input();
            sptr->calArea();
        }

    }while(ch != 0);

   cout<<"\n";
    return 0;
}