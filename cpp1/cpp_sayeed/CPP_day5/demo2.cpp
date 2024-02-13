#include<iostream>
using namespace std;
//base class
//parent class
class person
{
    protected:
        int age;
        string name;
    public:
    person()
    {
        age=26;
        name="Rajesh";
    }
    void printPerson()
    {
        cout<<"\n  Name="<<name<<" age="<<age;
    }
};
//emp is-a person
//child 
//derived
class emp: public person
{
    int empid;
    int sal;
    public:
    emp()
    {
        empid=124;
        sal=25000;
    }
    void printEmp()  //4
    {
        this->printPerson();  //2
        cout<<"\n empid="<<empid<<" sal="<<sal; //2
    }
    void updateName(string newName)
    {
        this->name=newName; //valid
    }
};
int main()
{
    // person p1;
    // p1.printPerson();

    emp e1;
    e1.printEmp();

    person p2;
    p2=e1;
    p2.printPerson();
    return 0;
}