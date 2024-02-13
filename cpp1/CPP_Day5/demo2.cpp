#include<iostream>
using namespace std;

class complex
{
    private:
        int real;
        int imag;
    public:
    
    complex(int r=0,int i=0)
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
    // complex sum(const complex& c2)
    // {
    //     complex c3;
    //     c3.real=this->real+c2.real;
    //     c3.imag=this->imag+c2.imag;
    //     return c3;
    // }
    complex operator+(const complex& c2)
    {
        complex c3;
        c3.real=this->real+c2.real;
        c3.imag=this->imag+c2.imag;
        return c3;
    }   
    friend complex operator-(complex& c1,complex& c2);
};//end of class

complex operator-(complex& c1,complex& c2)
{
    complex c4;
    c4.real=c1.real-c2.real;
    c4.imag=c1.imag-c2.imag;
    return c4;
}

int main()
{
    

    complex c1(6,7),c2(3,2),c3,c4;
    //c2.printComplexNumber();

    //c3=c1.sum(c2);
    c3=c1+c2;  //c3=c1.operator+(c2);
    c3.printComplexNumber();

    c4=c1-c2;  //operator-(c1,c2);
    c4.printComplexNumber();

    return 0;
}