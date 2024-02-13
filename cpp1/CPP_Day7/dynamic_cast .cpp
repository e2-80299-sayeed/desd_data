

#include <iostream>
using namespace std;
class person
{
protected:
	string name;
	int adhar;
	int age;

public:
	person()
	{
		cout<<"\nparameter less const::person-----";
		name="xxx";
		adhar=0;
		age=1;
	}
	person(string name,int adhar,int age)
	{
		cout<<"\nparameterized less const::person-----";
		this->name=name;
		this->adhar=adhar;
		this->age=age;
	}
	virtual void accept()
	{
		cout<<"\nEnter Name";
		cin>>name;
		cout<<"\nenter adhar no";
		cin>>adhar;
		cout<<"\nenter age";
		cin>>age;
	}
	virtual void print()
	{
		cout<<"\nName : "<<this->name;
		cout<<" adhar : "<<adhar;
		cout<<" age : "<<age;
	}
	void fun1person()
	{
		cout<<"\n fun1person()";
	}

};
class student:public person
{
private:
	int rollNo;
	string schoolName;

public:
	student()
	{
		cout<<"\nparameter less const::student-----";
	}
	student(string name,int adhar,int age,int rollno,string school):person(name,adhar,age)
	{
		this->rollNo=rollno;
		this->schoolName=school;
	}
	void accept()
	{
		//this->
		person::accept();
		cout<<"\nEnter roll no";
		cin>>rollNo;
		cout<<"\n enter School name";
		cin >>schoolName;
	}
	void print()
	{
		person::print();
		cout<<" roll no="<<rollNo;
		cout<<" school name="<<schoolName;
	}
	void fun3student()
	{
		cout<<"\n fun3student()";
	}
};

//used for c lang style type casting
//mainly designed for polymorphic type only
//polymorphic type means atleast one virtual function in base class
// check inheritance  relationship at runtime
//if fails return NULL

//int main()
//{
//	person *p=new person();
//	student *s=p;
//	student *s=dynamic_cast<student*>(p);
//	return 0;
//}
