#include<iostream>
using namespace std;

class engine
{
    int cc, fuel;

    public:

        void printEngine()
        {
            cout << "engine cc="<<cc<<" fuel="<<fuel;
        }

        void acceptEngine()
        {   cout<<"Enter cc and fuel";
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
            e.printEngine(); 
        }

        void acceptCar()
        {
            cout<<"\n Enter price :";
            cin >> price;
            e.acceptEngine();

        }
};

int main()
{

    class car c1;
    c1.acceptCar();
    c1.printCar();
    cout<<"\n";
    return 0;
}