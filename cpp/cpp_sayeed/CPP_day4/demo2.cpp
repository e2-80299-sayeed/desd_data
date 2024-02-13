#include<iostream>
using namespace std;


class engine
{
    int cc,fuel;
    public:
        void acceptEngine()
        {
            cout<<"\n engine cc and fuel";
            cin>>cc>>fuel;
        }
        void printEngine()
        {
            cout<<" engine cc="<<cc<<" fuel="<<fuel;
        }
};
class car
{
    int price;
    engine e;//e is obj of engine class which is acting as data member of car class
    public:
    void printCar()
    {
        cout<<"\n price="<<price;
        e.printEngine();
    }
    void accpetCar()
    {
        cout<<"\n Enter price";
        cin>>price;
        e.acceptEngine();
    }
};
int main()
{
    //  engine e1;
    //  e1.acceptEngine();
    //  e1.printEngine();

    car c1;
    c1.accpetCar();
    c1.printCar();
    cout<<"\n";
    return 0;
}