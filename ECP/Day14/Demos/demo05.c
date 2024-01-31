#include<stdio.h>

union test
{
	char arr[2];
	short num;
};			// 2 bytes

union test1
{
	char ch;
	short num;
	union test2
	{
		int num;
		char ch;
	}t2;
};


int main(void)
{
	union test t1;
	
	t1.arr[0] = 'A';
	t1.arr[1] = 'B';

	printf("arr[0] = %c, arr[1] = %c\n", t1.arr[0], t1.arr[1]);
	printf("arr[0] = %x, arr[1] = %x\n", t1.arr[0], t1.arr[1]);
	printf("num = %x\n", t1.num);

	t1.num = 0x0202;		// 0000 0010 0000 0010
	
	printf("num = %x\n", t1.num);
	printf("arr[0] = %x, arr[1] = %x\n", t1.arr[0], t1.arr[1]);
	return 0;
}































