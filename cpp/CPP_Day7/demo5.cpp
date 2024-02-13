#include<iostream>
using namespace std;

class rect
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
class SmartPtr
{
    rect *ptr;
    public:
    SmartPtr(rect *p = NULL) 
    { 
        ptr = p; 
    }
    ~SmartPtr() { delete (ptr); }
    rect& operator*() { return *ptr; }
    rect* operator->()
    {
        return ptr;
    }
};
int main()
{
    SmartPtr ptr(new rect());
    ptr->calArea();
    ptr->calPeri();  
    return 0;
}