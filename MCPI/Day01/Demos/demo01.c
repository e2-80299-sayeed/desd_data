#include<stdio.h>

struct emp
{
	int empid;
	char name[20];
	float sal;
};

int main(void)
{
	struct emp e = {2, "abc", 12345};
	struct emp *ptr = &e;

	printf("Empid = %d\n", e.empid);
	printf("Name = %s\n", e.name);
	printf("Salary = %f\n", e.sal);

	printf("Empid = %d\n", ptr->empid);
	printf("Name = %s\n", ptr->name);
	printf("Salary = %f\n", ptr->sal);

	printf("&e = %u\n", &e);
	printf("&e.empid = %u\n", &e.empid);
	printf("&e.name = %u\n", &e.name);
	printf("&e.sal = %u\n", &e.sal);

	printf("offset of empid = %d\n", (char *)&e.empid - (char *)&e);
	printf("offset of name = %d\n", (char *)&e.name - (char *)&e);
	printf("offset of sal = %d\n", (char *)&e.sal - (char *)&e);
	
	return 0;
}































