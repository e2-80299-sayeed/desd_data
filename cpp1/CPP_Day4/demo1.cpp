#include<iostream>
using namespace std;

class complex
{
    private:
        int real;
        int imag;
    public:
    complex()
    {
        this->real=1;
        this->imag=1;
    }
    complex(int r,int i)
    {
        this->real=r;
        this->imag=i;
    }
    complex(const complex& c1)
    {
        cout<<"\n ----- complex(const complex& c1)----";
        this->real=c1.real;
        this->imag=c1.imag;
    }
    void printComplexNumber()
    {
        cout<<"\ncomplex number="<<real<<"+j"<<imag;
    }
    void acceptComplexNumber()
    {
        cout<<"\n Enter real and imag";
        cin>>this->real>>this->imag;
    }
    void setReal(int r)
    {
        this->real=r;
    }
    void setImag(int i)
    {
        this->imag=i;
    }
    int getReal()
    {
        return this->real;
    }
    int getImag()
    {
        return this->imag;
    }
    complex sum(const complex& c2)
    {
        complex c3;
        c3.real=this->real+c2.real;
        c3.imag=this->imag+c2.imag;
        return c3;
    }
    ~complex()
    {
        cout<<"\n----- ~complex()-----";
    }
};//end of class

int main()
{
    complex c1(7,6);
    c1.printComplexNumber();
    
    complex *cptr=new complex(11,22);
    cptr->printComplexNumber();
    delete cptr;
    cptr=NULL;

    complex cp=c1;  //complex cp(c1);
    cp.printComplexNumber();



    // complex c2(3,2),c3;
    // c2.printComplexNumber();

    // c3=c1.sum(c2);
    // c3.printComplexNumber();
    return 0;
}