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
            this->ptr[i]=i+2;
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
    int& operator[](int index)
    {
        if (index >= this->size) 
        {
            cout << "Array index out of bound, exiting";
            exit(0);
        }
        return this->ptr[index];
    }
};

int main()
{ 
    // int a[5]={22,55,33,77,88};
    // int t=a[2];
    // cout<<"\n value at a[2]="<<t;
    // //update value at a[3] as 10;
    // a[3]=10;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<"\n a["<<i<<"]="<<a[i];
    // }
    
     array a1(5);
     a1.printArray();
     int n=a1[2];  
     // int t=a[2];
     cout<<"\n value at a1[2]="<<n;

    a1[3]=300;
    a1.printArray();
    
    return 0;
}