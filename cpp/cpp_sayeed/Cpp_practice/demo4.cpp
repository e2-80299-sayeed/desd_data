#include<iostream>
using namespace std;

//every emp is-a person 

class person
{
    protected: // this gives access to derived class to modifiy private data member of parent class  
        int age;
        string name;

    public:
        person()
        {
            age = 22;
            name = "Sayeed";
        }

        void printPerson()
        {
            cout<<"\n Name= "<<name<<"\n age= "<<age;
        }
};

class emp : public person
{
    int empid;
    float sal;
   
    public:
        emp()
        {
            empid=124;
            sal=25000;
        }

        void printEmployee()
        {
            this->printPerson();
            cout<<"\n empid= "<<empid<<"\n sal= "<<sal;

        }

        void updateName(string newName)
        {
            this->name = newName;
        }
};

int main()
{
    // person p1;
    // p1.printPerson();
    // cout<<"\n";

    emp e1;
    e1.printEmployee();
    cout<<"\n";
    e1.updateName("Mohammad Sayeed");
    e1.printEmployee();
    cout<<"\n";
    return 0;
}