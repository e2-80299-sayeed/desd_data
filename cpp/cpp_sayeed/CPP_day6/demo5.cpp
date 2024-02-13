#include<iostream>
using namespace std;

template<class T>
class array
{
    T *ptr;
    int size;
    public:
    array(int s)
    {
        this->size=s;
        this->ptr=new T[size];
        for (int i = 0; i < this->size; i++)
        {
            this->ptr[i]=0;
        }  
    }
    void acceptArray()
    {
        cout<<"\n Enter "<<size<<" eles";
        for (int i = 0; i < size; i++)
        {
            cin>>this->ptr[i];
        }
    }
    void printArray()
    {
        for (int i = 0; i < size; i++)
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
    array<int> a1(5);
    a1.acceptArray();
    a1.printArray();

    array<char> a2(5);
    a2.acceptArray();
    a2.printArray();
    return 0;
}