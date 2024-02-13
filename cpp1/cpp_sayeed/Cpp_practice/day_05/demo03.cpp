#include<iostream>
using namespace std;

class complex
{
    int real,imag;
    static int count;
    public:
        complex(int r=1,int i=1)
        {   
            count++;
            this->real = r;
            this->imag = i;
        }
        
    static void printCount()// this-> is not available inside static member function/global function/ friend function 
        {
            cout<<"\n value of count= "<<count<<"\n address of count= "<<&count;
        }

        void printComplexNumber()
        {
            cout<<"\n Complex Number= "<<this->real<<"+j"<<this->imag;
        }
    
};
int complex::count=0;

int main()
{
    complex c1;
    c1.printComplexNumber();
    cout<<"\nsizeof obj c1= "<<sizeof(c1);
    c1.printCount();
    cout<<"\n";

    complex::printCount();
    return 0;
}