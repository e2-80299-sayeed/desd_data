#include<stdio.h>

typedef struct person
{
	char name[20];
	int age;
	char gender;
}person_t;

typedef struct employee
{
	int empid;
	person_t pinfo;
	double salary;
}emp_t;

void accept_person(person_t *);
void print_person(person_t);

void accept_employee(emp_t *);
void print_employee(emp_t);

int main(void)
{
	emp_t e;
	accept_employee(&e);
	print_employee(e);

	return 0;
}

void accept_person(person_t *p)
{
	printf("Enter personal details (name, age, gender): ");
	scanf("%s %d %c", p->name, &p->age, &p->gender);
}
void print_person(person_t p)
{
	printf("%s %d %c\n", p.name, p.age, p.gender);
}

void accept_employee(emp_t *emp)
{
	printf("Enter empid : ");
	scanf("%d", &emp->empid);
	//accept_person(&emp->pinfo);
	printf("Enter personal details (name, age, gender) : ");
	scanf("%s %d %c", emp->pinfo.name, &emp->pinfo.age, &emp->pinfo.gender); 
	printf("Enter salary : ");
	scanf("%lf", &emp->salary);
}
void print_employee(emp_t emp)
{
	printf("empid : %d\n", emp.empid);
	printf("name, age, gender : ");
	print_person(emp.pinfo);
	printf("Salary : %.2lf\n", emp.salary);
}





























