#include<stdio.h>

#define offset_of(member, type) ((long)&((type *)0)->member)

struct emp
{
	int empid;
	char name[20];
	float sal;
};

int main(void)
{
	struct emp e = {2, "abc", 12345};

	printf("&e = %u\n", &e);
	printf("&empid = %u\n", (char *)&e + offset_of(empid, struct emp));
	printf("&name = %u\n", (char *)&e + offset_of(name, struct emp));
	printf("&sal = %u\n", (char *)&e + offset_of(sal, struct emp));

	printf("&empid = %d\n", *(int *)((char *)&e + offset_of(empid, struct emp)));
	printf("&name = %s\n", (char *)&e + offset_of(name, struct emp));
	printf("&sal = %f\n", *(float *)((char *)&e + offset_of(sal, struct emp)));
	return 0;
}































