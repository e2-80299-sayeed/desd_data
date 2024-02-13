
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{

    //cout-->printf
    printf("\n Welcome.. :)");
    cout<<"\n Welcome.. :)";

    int n=11;
    printf("\n value of n=%d",n);
    cout<<"\n value of n="<<n;

    int a=22,b=33;
    printf("\n value of a=%d  value of b=%d",a,b);
    cout<<"\n value of a="<<a<<"  value of b="<<b;

   // cin-->scanf

   int x;
   cout<<"\nEnter X ";
   //scanf("%d",&x);
   cin>>x;
   cout<<"\n x="<<x;


   int y,z;
   cout<<"\nEnter y,z ";
   //scanf("%d%d",&y,&z);
    cin>>y>>z;
   cout<<"\n value of y="<<y<<"  value of z="<<z;
    return 0;
}