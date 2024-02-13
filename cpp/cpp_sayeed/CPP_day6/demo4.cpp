
#include<iostream>
using namespace std;
class complex
{
    int real;
    int imag;
    public:
    complex(int r=1,int i=1)
    {
        this->real=r;
        this->imag=i;
    }
	void printComplexNumber()
    {
        cout<<"complex number="<<this->real<<"+j"<<this->imag;
    }   
};
template<class T>
void mySwap(T& a,T& b)
{
    T t=a;
    a=b;
    b=t;
}
int main()
{

    complex c1(11,11),c2(9,9);
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
    // int a=11,b=99;
    // cout<<"\n before swap a="<<a<<" b="<<b;
    // mySwap(a,b);
    // cout<<"\n after swap a="<<a<<" b="<<b;
    // char aa='A',bb='B';
    // cout<<"\n before swap aa="<<aa<<" ba="<<bb;
    // mySwap(aa,bb);
    // cout<<"\n after swap aa="<<aa<<" bb="<<bb;

    cout<<"\n";
    return 0;
}