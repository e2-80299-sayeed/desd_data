#include<iostream>
using namespace std;
//cout ==> printf()  == <<
//cin ==> scanf()  ==> >>
int main()
{
    printf("Good morning");
    cout<<"Good Morning";

    int n1=12;
    printf("\n value of n1=%d",n1);
    cout<<"\n value of n1="<<n1;

    int a=55,b=66;
    printf("\n value of a=%d value of b=%d",a,b);
    cout<<"\n value of a="<<a<<" value of b="<<b;

    int num1;
    cout<<"\n Enter value for num1";
    //scanf("%d",&num1);
    cin>>num1;
    cout<<"\n value of num1="<<num1;

    int a1=100,b1=200;
    char ch;
    cout<<"\n Enter values for int a1,b1 and char ch";
    //scanf("%d%d%c",&a1,&b1,&ch);
    cin>>a1>>b1>>ch;
    cout<<"\n value of a1="<<a1<<" value of b1="<<b1<<" char ch="<<ch;



    return 0;
}