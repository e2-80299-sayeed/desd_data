#include<iostream>
using namespace std;

class singleton
{
    private:
        static singleton* ptr;
        int data;
        singleton()
        {
            cout<<"\n---singleton()--- ";
            data=33;
        }
    public:
        static singleton* getObject()
        {
            if(ptr==NULL)
                ptr=new singleton();
            return ptr;
        }
    void printdata()
    {
        cout<<"\n data="<<data;
    }
};

singleton* singleton::ptr=NULL;

int main()
{

    singleton* ptr3=singleton::getObject();
    ptr3->printdata();
    singleton* ptr1=singleton::getObject();
    ptr1->printdata();
    singleton* ptr2=singleton::getObject();
    ptr2->printdata();

    cout<<"\n";
    return 0;
}