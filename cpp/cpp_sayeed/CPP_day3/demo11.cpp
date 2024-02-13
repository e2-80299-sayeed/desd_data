#include<iostream>
using namespace std;

class complex
{
    int real;
    int imag;
    public:
        complex(int r=1,int i=1)
        {
            cout<<"\n -----complex(int,int)------";
            this->real=r;
            this->imag=i; 
        }
        void printComplexNumber()
        {
            cout<<"\n Complex Number="<<this->real<<"+j"<<this->imag;
        }    
        ~complex()
        {
            cout<<"\n ------- ~complex()-----";
        }
};
int main()
{
    complex c1(7,6);
    c1.printComplexNumber();

    complex *cptr=new complex(11,22);
    cptr->printComplexNumber();
    delete cptr;
    cptr=NULL;

    complex c2(3,2);
    c2.printComplexNumber();

    
    return 0;
}

