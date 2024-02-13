#include<stdio.h>
int g=10;
namespace ns1
{
    int connector=3307;
    namespace nns
    {
        int var_nns=100;
    }
}
namespace ns2
{
    int connector=2208;
    int num1=11;
    int num2=12;
    int num3=13;
    int num4=14;
    int num5=15;
}
int main()
{
    int n;
    printf("\n value of g=%d",g);
    printf("\n value of g=%d",::g);

    printf("\n connector=%d",ns1::connector);
    printf("\n connector=%d",ns2::connector);
    printf("\n ns1::nns::var_nns=%d",ns1::nns::var_nns);

    //printf("\n num1=%d",num1);
    printf("\n ns2::num1=%d",ns2::num1);
    using namespace ns2;
    printf("\n num1=%d",num1);
    return 0;
}