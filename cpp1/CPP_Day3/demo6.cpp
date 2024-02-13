
#include<iostream>
using namespace std;

class constDemo
{
        int n;
        const int c;
        mutable int m;
    public:
    constDemo():c(22)
    {
        n=11;
      // c=22;
        m=33;
    }
    void printData() const
    {
       // n++;
        //c++;
        m++;
        cout<<"\n n="<<n;
        cout<<"   c="<<c;
        cout<<"   m="<<m;
    }
};

int main()
{
    constDemo d1;
    d1.printData();
    cout<<"\n";
    return 0;
}