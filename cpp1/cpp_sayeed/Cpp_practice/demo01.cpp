#include<iostream>

void add(int a, int b, int c , int d =0)
{
    int r;
    r = a+b+c+d;
    std::cout<<"a=" << a <<", b=" << b << ", c=" <<c <<", d=" << d <<", r=" <<r << std::endl; 
} 

int main()
{
    std::cout << "Good morning" << std::endl;
    add(1,2,3,4);
    return 0;
}