#include<iostream>
using namespace std;

class person 
{
    protected:
        string name;
        int age;
    public:
        person()
        {
            this->name="sayeed";
            this->age = 22;
        }

    virtual void accept()
        {
            cout<<"Enter name of emp: "; 
            cin>>name;
            cout<<"Enter age: ";
            cin>>age;
        }

        void print_person()
        {
            cout<<"name= "<<name<<"\n";
            cout<<"age= "<<age<<"\n";
            
        }

};

class emp : public person
{
    int empid;
    int sal;

    public:
        emp()
        {
            empid = 123;
            sal = 30000;

        }

         void accept()
        {
            person::accept();
            cout<<"Enter empid: "; 
            cin>>empid;
            cout<<"Enter salary: ";
            cin>>sal;
        }

        void print_emp()
        {
            this->print_person();
            cout<<"empid= "<<empid<<"\n";
            cout<<"salary= "<<sal<<"\n";
        }

        void updateName(string newName)
        {
            this->name = newName;
        }

};

int main()
{
    //person p1;
    //p1.print_person();

    emp e1;
    // e1.print_emp();
    
    // e1.accept();
    // e1.print_emp();

    // person p2;
    // p2=e1;
    // p2.print_person();

    emp *eptr = NULL;
    eptr = &e1;
    eptr->accept();
    eptr->print_emp();


    person *pptr = NULL;
    pptr=&e1;
    pptr->accept();
    pptr->print_person();

    // pptr->updateName();


    return 0;
}
