#include<iostream>
using namespace std;

class complex
{
    int real;
    int imag;
    static int count;
    public:
        complex(int r=1,int i=1)
        {
            count++;
            cout<<"\n -----complex(int,int)------";
            this->real=r;
            this->imag=i; 
        }
        static void printCount()
        {
            cout<<"\n value of count="<<count<<" address of count="<<&count;
        }
        void printComplexNumber()
        {
            cout<<"\n Complex Number="<<this->real<<"+j"<<this->imag;
        }     
};
int complex::count=0;
int main()
{
    complex::printCount();
    return 0;
}

