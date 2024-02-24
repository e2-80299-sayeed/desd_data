#include<stdio.h>

#pragma pack(1)

#define offset_of(member, type) ((long)&((type *)0)->member)

struct test
{
	int a;		// 4
	char b;		// 1
	short c;	// 2
	int d;		// 4
	short e;	// 2
	char f;		// 1
	int g;		// 4
};				// 18 bytes


int main(void)
{
	printf("sizeof(struct test) = %d\n", sizeof(struct test));
	
	printf("offset(a) = %ld\n", offset_of(a, struct test));
	printf("offset(b) = %ld\n", offset_of(b, struct test));
	printf("offset(c) = %ld\n", offset_of(c, struct test));
	printf("offset(d) = %ld\n", offset_of(d, struct test));
	printf("offset(e) = %ld\n", offset_of(e, struct test));
	printf("offset(f) = %ld\n", offset_of(f, struct test));
	printf("offset(g) = %ld\n", offset_of(g, struct test));

	return 0;
}































