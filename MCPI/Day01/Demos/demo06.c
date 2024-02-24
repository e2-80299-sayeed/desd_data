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

	printf("offset of empid = %d\n", (long)&((struct emp *)0)->empid);
	printf("offset of name = %d\n", (long)&((struct emp *)0)->name);
	printf("offset of sal = %d\n", (long)&((struct emp *)0)->sal);

	printf("offset_of(empid, struct emp) = %ld\n", offset_of(empid, struct emp));
	printf("offset_of(name, struct emp) = %ld\n", offset_of(name, struct emp));
	printf("offset_of(sal, struct emp) = %ld\n", offset_of(sal, struct emp));

	return 0;
}































