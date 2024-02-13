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
   virtual void accept()
    {
        cout<<"\n Enter name and age";
        cin>>name>>age;
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
        cout<<" empid="<<empid<<" sal="<<sal; //2
    }
    void accept() //4
    {
        person::accept();//2
        cout<<"\n Enter Empid and sal";
        cin>>empid>>sal;
    }
    void updateName(string newName)
    {
        this->name=newName; //valid
    }
};
int main()
{
    // person p1;
    // person *pptr=NULL;
    // pptr=&p1;
    // pptr->accept();
    // pptr->printPerson();

    // emp e1;
    // emp *eptr=NULL;
    // eptr=&e1;
    // eptr->accept();
    // eptr->printEmp();

    emp e1;
    person *pptr=NULL;
    pptr=&e1;//base class pointer can hold the obj of derived class
    pptr->accept();
    pptr->printPerson(); //2
   // pptr->updateName("abc");









    // person p1;
    // p1.accept();
    // p1.printPerson();

    // emp e1;
    // e1.accept();
    // e1.printEmp();



    
    return 0;
}