#include"HeaderDemo.h"
#include<iostream>
using namespace std;



complex::complex()
{
    this->real=11;
    this->imag=22;
}
void complex::show()
{
    cout<<"\n complex number="<<this->real<<"+j"<<this->imag;
}

point::point()
{
    this->x=-3;
    this->y=7;
}
void point::show()
{
    cout<<"\n point =("<<this->x<<","<<this->y<<")";
}

int main()
{
    complex c1;
    c1.show();

    point p1;
    p1.show();

    cout<<"\n";
    return 0;
}
