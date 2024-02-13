#include<iostream>
using namespace std;

class engine
{
    int cc,fuel;
    public:
    void printEngine()
    {
        cout<<"\n engine cc="<<cc<<"  fuel="<<fuel;
    }
    void acceptEngine()
    {
        cout<<"enter engine cc and fuel";
        cin>>this->cc>>this->fuel;
    }
};
class car
{
    int price;
    engine e;
    public:
    void printCar()
    {
        cout<<"  price="<<this->price;
        e.printEngine();
    }
    void acceptCar()
    {
        cout<<"\n enter car price";
        cin>>this->price;
        e.acceptEngine();
    }
};

int main()
{

    // engine e1;
    // e1.acceptEngine();
    // e1.printEngine();


    car c1;
    c1.acceptCar();
    c1.printCar();
    
    cout<<"\n";
    return 0;
}