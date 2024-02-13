#include<iostream>
using namespace std;

class complex
{
    int real;
    int imag;
    public:
    complex(int r=0,int i=0)
    {
       // cout<<"\n -----complex(int,int)-----";
        this->real=r;
        this->imag=i;
    }
	void printComplexNumber()
    {
        cout<<"complex number="<<this->real<<"+j"<<this->imag;
    }   
};



template<class T>
void mySwap(T& refa,T& refb)
{
    T t=refa;
    refa=refb;
    refb=t; 
}
int main()
{
    complex c1(11,99),c2(55,44);
    cout<<"\n before swap:";
    cout<<"c1=";
    c1.printComplexNumber();
    cout<<"\nc2=";
    c2.printComplexNumber();
    mySwap(c1,c2);
    cout<<"\n after swap ";
    cout<<"c1=";
    c1.printComplexNumber();
    cout<<"\nc2=";
    c2.printComplexNumber();
    


    int a=99,b=11;
    cout<<"\n before swap a="<<a<<"  b="<<b;
    mySwap(a,b);
    cout<<"\n after swap a="<<a<<"  b="<<b;

    char ch1='A',ch2='Z';
    cout<<"\n before swap a="<<ch1<<"  b="<<ch2;
    mySwap(ch1,ch2);
    cout<<"\n after swap a="<<ch1<<"  b="<<ch2;

     return 0;
}
