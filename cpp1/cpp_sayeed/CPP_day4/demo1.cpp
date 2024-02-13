#include<iostream>
using namespace std;

class array
{
    int size;
    int *ptr;
    public:
    array(int s=0)//s=5
    {
        this->size=s;
        this->ptr=new int[this->size];
        for (int i = 0; i < this->size; i++)
        {
            this->ptr[i]=1;
        }    
    }
    array(const array& a1) //deep copy
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
        cout<<"\n Array=";
        for (int i = 0; i < this->size; i++)
        {
            cout<<"\n ptr["<<i<<"] = "<<this->ptr[i];
        }  
    }
    void acceptArray()
    {
        cout<<"\n Enter "<<this->size<<" Array elements";
        for (int i = 0; i < this->size; i++)
        {
            cin>>this->ptr[i];
        }  
    }
    ~array()
    {
        if(this->ptr!=NULL)
        {
            delete []this->ptr;
            this->ptr=NULL;
        }
    }
};


int main()
{
    array a1(5);
    a1.printArray();
    a1.acceptArray();
    a1.printArray();

    array ac(a1); //array ac=a1;
    ac.printArray();
    return 0;
}