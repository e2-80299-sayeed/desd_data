#include<iostream>
using namespace std;

int main()
{
    int n1;
    n1=12;
    n1=55;

    int& ref=n1;
    ref=66;

    
    cout<<"\n value of n1="<<n1<<" address of n1="<<&n1;
    cout<<"\n value of ref="<<ref<<" address of ref="<<&ref;
    return 0;
}