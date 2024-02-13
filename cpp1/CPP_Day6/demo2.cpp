#include<iostream>
using namespace std;
class person
{
    protected:
    string name;
    int age;
    public:
    person(string name="aaa",int a=22)
    {
        this->name=name;
        this->age=a;
    }
    void printPerson()
    {
        cout<<"\n name="<<name<<" age="<<age;
    }
};
//emp-> child
//person->parent
//emp is a person
// (derived)     (base)
class emp:public person
{
    private:
    int sal;
    int empid;
    public:
    emp(string name="aaa",int age=22,int sal=10000,int id=100):person(name,age)
    {
        this->sal=sal;
        this->empid=id;
    }
    void printEmp()
    {
        this->printPerson();
        cout<<" sal="<<sal<<" empid="<<empid;   
    }
    void  updateName(string newName)
    {
        name=newName;
    }
};


int main()
{
    person p("rajiv",34);
    p.printPerson();

    emp e1("rajiv",34,20000,84);
    //rajeev
    e1.updateName("rajeev");
   // e1.name="zzz";

    e1.printEmp();


    person p2=e1;
    p2.printPerson();


    person *pptr=NULL;
    pptr=&e1;  // no error
    // base class pointer can hold derived class object
    pptr->printPerson();


    cout<<"\n";
    return 0;
}