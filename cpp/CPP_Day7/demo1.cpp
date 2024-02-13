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
    virtual void accept()
    {
        cout<<"\nenter name and age";
        cin>>name>>age;
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
    void accept()
    {
        person::accept();
        cout<<"\n enter sal and empid";
        cin>>sal>>empid;
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
    
    // person p1;
    // person *pptr=NULL;
    // pptr=&p1;
    // pptr->printPerson();

    // emp e1("rajiv",32,20000,84);
    // emp *eptr=NULL;
    // eptr=&e1;
    // eptr->printEmp();
    // eptr->updateName("Rajeev");
    // eptr->printPerson();

     emp e1("rajiv",32,20000,84);
     person *pptr=NULL;
     pptr=&e1;
     pptr->printPerson();
     pptr->accept();
    





    

    cout<<"\n";
    return 0;
}