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

	printf("offset of empid = %d\n", (long)&ptr->empid);
	printf("offset of name = %d\n", (long)&ptr->name);
	printf("offset of sal = %d\n", (long)&ptr->sal);

	return 0;
}































