#include<iostream>
using namespace std;

class singleton
{
    private:
        static singleton *ptr;
        singleton()
        {
            cout<<"\n ----- singleton() ---";
        }
    public:
        static singleton* getObject()
        {
            if(ptr==NULL)
                ptr=new singleton();
            return ptr;
        }
};
singleton* singleton::ptr=NULL;
int main()
{
    singleton *ptr1=singleton::getObject();
    singleton *ptr2=singleton::getObject();
    singleton *ptr3=singleton::getObject();
    singleton *ptr4=singleton::getObject();
    return 0;
}