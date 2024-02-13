#include<iostream>
using namespace std;

//int a1=a

//int& a1=a  //int a1=111
void mySwap(int& a1,int& b1)
{
    int t=a1;
    a1=b1;
    b1=t;
}

int main()
{
    int a=111;
    int b=999;
    cout<<"\n before swap a="<<a<<" b="<<b;
    mySwap(a,b);
    cout<<"\n after swap a="<<a<<" b="<<b;
    return 0;
}