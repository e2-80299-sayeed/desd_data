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
};

int main()
{
    complex c1(5,7);
    c1.printComplexNumber();
    c1.acceptComplexNumber();
    c1.printComplexNumber();
    return 0;
}