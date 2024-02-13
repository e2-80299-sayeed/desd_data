
#include<iostream>
using namespace std;

int main()
{
    int n;
    n=5;

    int& ref =n;
    

    cout<<"\n value of n="<<n<<" address of n="<<&n;
    cout<<"\n value of ref="<<ref<<"  address of ref="<<&ref;

    cout<<"\n";
    return 0;
}