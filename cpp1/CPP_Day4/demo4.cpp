#include<iostream>
using namespace std;

class complex
{
    private:
        int real;
        int imag;
        static int count;
    public:
    complex(int r=0,int i=0)
    {
        count++;
        this->real=r;
        this->imag=i;
    }
    void printComplexNumber()
    {
        cout<<"\ncomplex number="<<real<<"+j"<<imag;
    }  
    static void printCount()
    {
        cout<<"\n count="<<count<<"  address of count="<<&count;
    } 
};//end of class
int complex::count=0;

int main()
{
     complex c1(11,22);
    // c1.printCount();
    // cout<<"\n size of c1="<<sizeof(c1);

      complex c2(1,2);
    //   c2.printCount();

    //cout<<"\n static count="<<complex::count;
   
   complex::printCount();


    return 0;
}