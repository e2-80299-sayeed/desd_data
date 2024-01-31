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

person_t accept_person(void);
void print_person(person_t);

emp_t accept_employee(void);
void print_employee(emp_t);

int main(void)
{
	emp_t e = accept_employee();
	print_employee(e);

	return 0;
}

person_t accept_person(void)
{
	person_t p;
	printf("Enter personal details (name, age, gender): ");
	scanf("%s %d %c", p.name, &p.age, &p.gender);
	return p;
}
void print_person(person_t p)
{
	printf("%s %d %c\n", p.name, p.age, p.gender);
}

emp_t accept_employee(void)
{
	emp_t emp;
	printf("Enter empid : ");
	scanf("%d", &emp.empid);
	emp.pinfo = accept_person();
	printf("Enter salary : ");
	scanf("%lf", &emp.salary);
	return emp;
}
void print_employee(emp_t emp)
{
	printf("empid : %d\n", emp.empid);
	printf("name, age, gender : ");
	print_person(emp.pinfo);
	printf("Salary : %.2lf\n", emp.salary);
}





























