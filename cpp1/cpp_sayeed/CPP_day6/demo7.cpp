#include <iostream>
using namespace std;
class a
{
    int aa;
    public: 
    a()
    {
        aa=55;
    }
    void print()
    {
        cout<<"\n aa="<<aa;
    }
    void fun1()
    {
        cout << "\n fun1";
    }
    void fun2()
    {
        cout << "\n fun2";
    }
};
class SmartPtr
{
    a *ptr;
    public:
    SmartPtr(a *p = NULL) 
    { 
        ptr = p; 
    }
    ~SmartPtr() 
    { 
        delete (ptr); 
    }
    a& operator*() { return *ptr; }
    a* operator->()
    {
        return ptr;
    }
};

int main()
{
    SmartPtr sptr(new a());
    sptr->print();
    sptr->fun1();
    sptr->fun2();
    
    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, the destructor for it is automatically
    // called and destructor does delete ptr.
    return 0;
}