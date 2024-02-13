#include<iostream>
using namespace std;

class constDemo
{
    int n;
    const int c,c1;
    mutable int m;
    public:
        constDemo():c(22),c1(23)
        {
            n=11;
           //c=22;
            m=33;
        }
        void printData()const
        {
           // n++;
            //c++;
            m++;
            cout<<"\n n="<<n;
            cout<<"\n c="<<c;
            cout<<"\n m="<<m;
        }
};
int main()
{
    constDemo d1;
    d1.printData();
    return 0;
}