#include<stdio.h>

struct test1
{
	int num;
	char ch;
};

struct test2
{
	short sh;
	char ch;
};

int main(void)
{
	struct test1 *pt1 = 100;
	struct test2 *pt2 = 100;

	printf("pt1 = %u\n", pt1);					// 0 
	printf("&pt1->num = %u\n", &pt1->num);		// 0
	printf("&pt1->ch = %u\n", &pt1->ch);		// 4

	printf("offset of num(test1) = %d\n", (char *)&pt1->num - (char *)pt1);
	printf("offset of ch(test1) = %d\n", (char *)&pt1->ch - (char *)pt1);

	printf("pt2 = %u\n", pt2);					// 0 
	printf("&pt2->sh = %u\n", &pt2->sh);		// 0
	printf("&pt2->ch = %u\n", &pt2->ch);		// 2

	printf("offset of sh(test2) = %d\n", (char *)&pt2->sh - (char *)pt2);
	printf("offset of ch(test2) = %d\n", (char *)&pt2->ch - (char *)pt2);
	return 0;
}































