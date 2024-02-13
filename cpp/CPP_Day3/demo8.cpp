
#include<iostream>
using namespace std;

void  MySwap(int& refa,int& refb)
{
    int t=refa;
    refa=refb;
    refb=t; 
}

int main()
{

    int a=55,b=99;
    cout<<"\n before swap a="<<a<<" b="<<b;
    MySwap(a,b);
     cout<<"\n after swap a="<<a<<" b="<<b;

    cout<<"\n";
    return 0;
}