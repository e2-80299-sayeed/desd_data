#include<stdio.h>

struct emp
{
	int empid;
	char name[20];
	float sal;
};

int main(void)
{
	struct emp *ptr = NULL;

	printf("ptr = %u\n", ptr);
	printf("&ptr->empid = %u\n", &ptr->empid);
	printf("&ptr->name = %u\n", &ptr->name);
	printf("&ptr->sal = %u\n", &ptr->sal);

	printf("offset of empid = %d\n", (char *)&ptr->empid - (char *)ptr);
	printf("offset of name = %d\n", (char *)&ptr->name - (char *)ptr);
	printf("offset of sal = %d\n", (char *)&ptr->sal - (char *)ptr);

	return 0;
}































