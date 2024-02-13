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
        //complex obj=c1
        complex(const complex& obj)
        {
            cout<<"\n address of obj="<<&obj;
            cout<<"\n -----complex(complex&)------";
            this->real=obj.real;
            this->imag=obj.imag; 
           // obj.real=99;
        }
        void printComplexNumber()
        {
            cout<<"\n Complex Number="<<this->real<<"+j"<<this->imag;
        }
};
int main()
{
    complex c1(5,7);
    c1.printComplexNumber();

    complex cc(c1);    //complex cc=c1;
    cc.printComplexNumber();
    cout<<"\n address of c1="<<&c1;
    return 0;
}

