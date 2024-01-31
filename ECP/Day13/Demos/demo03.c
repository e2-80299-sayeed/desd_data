#include<stdio.h>

// Nested structure
// struct employee - outer structure
// struct date - inner structure

typedef struct employee
{
	int empid;
	char name[20];
	char address[20];
	char email[20];
	char mobile_no[20];
	struct date
	{
		int dd;
		int mm;
		int yyyy;
	} doj;
}emp_t;

int main(void)
{
	emp_t emp = {100, "abc", "pune", "abc@test.com", "1234567890", 22, 9, 2023};

	printf(" EmpId : %d\n", emp.empid);
	printf("Name : %s\n", emp.name);
	printf("Address : %s\n", emp.address);
	printf("Email Id : %s\n", emp.email);
	printf("Mobile No : %s\n", emp.mobile_no);
	printf("DOJ : %d/%d/%d\n", emp.doj.dd, emp.doj.mm, emp.doj.yyyy);

	return 0;
}































