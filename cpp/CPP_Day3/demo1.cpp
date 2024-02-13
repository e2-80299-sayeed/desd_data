#include<stdio.h>

int num1=11;

namespace ns1
{
    int connector=3703;
}

namespace ns2 //ns2 part1
{
    int connector=4470;
}
namespace ns2  //ns2 part2
{
    int connector1=4470;
     int num3=22;
     int num4=23;
     int num5=24;
     int num6=25;
     int num7=26;
     int num8=27;
     //....

}

namespace ns
{
    namespace nns
    {
        int num2=22;
    }
}
int main()
{
    num1=12;
    ::num1=13;
    int n=9;

    ns1::connector=2209;
    ns2::connector=5505;

    ns::nns::num2=23;

    using namespace ns2;
    num4=876;

    printf("\n");
    return 0;
}
