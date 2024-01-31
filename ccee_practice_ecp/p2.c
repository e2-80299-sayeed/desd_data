#include<stdio.h>

int main()
{
	register int x = 3;
	printf("%p, %x\n",&x, x);
	return 0;
}
