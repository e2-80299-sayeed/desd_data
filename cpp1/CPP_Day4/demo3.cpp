
#include<iostream>
using namespace std;

class array
{
    int *ptr;
    int size;
    public:
    array(int s)
    {
        this->size=s;
        this->ptr=new int[size];
        for (int i = 0; i < this->size; i++)
        {
            this->ptr[i]=0;
        }  
    }
    array(const array& a1)
    {
        this->size=a1.size;
        this->ptr=new int[this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->ptr[i]=a1.ptr[i];
        }  
    }
    void printArray()
    {
        for (int i = 0; i < 5; i++)
        {
            cout<<"\n ptr["<<i<<"]="<<this->ptr[i];
        }
    }
    ~array()
    {
        cout<<"\n --- ~array()---";
        if(this->ptr!=NULL)
            delete[]this->ptr;
        this->ptr=NULL;
    }
};

int main()
{
    array a1(5);
    a1.printArray();
    cout<<"\n A2==========";
    array a2=a1;  //array a2(a1);
    a2.printArray();
    cout<<"\n";
    return 0;
}