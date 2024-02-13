
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

    // int operator[](int index)
    // {
    //     return this->ptr[index];
    // }
    int& operator[](int index)
    {
        return this->ptr[index];
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
    // int arr[5]={11,66,44,77,88};
    // int n=arr[2];
    // cout<<"\n arr[2]="<<n;
    // int n1=22;
    // arr[3]=n1;
    // for (int i = 0; i < 5; i++)
    // {
    //    cout<<"\n arr["<<i<<"]="<<arr[i];
    // }


    array a1(5);
    a1.printArray();
    // int n=arr[2];
    int n=a1[2];
    cout<<"\n \n arr[2]="<<n;

     // arr[3]=n1;
     a1[3]=100;
     a1.printArray();
    return 0;
}