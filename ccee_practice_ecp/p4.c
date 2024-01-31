#include<stdio.h>
#define print_mul(x,y) printf(#x "*" #y "= %d", x*y)


int main()
{
	int a = 3;
	print_mul(a,3);
	return 0;
}
