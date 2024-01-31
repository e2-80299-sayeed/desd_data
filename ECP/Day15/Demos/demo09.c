#include<stdio.h>

// #	- stringizing operator -  converts into string
// ##	- token pasting operator - combine two tokens

#define PRINT(str) printf(#str);
#define PASTE(t1, t2) t1##t2

int main(void)
{
	printf("Line no = %d\n", __LINE__);
	printf("File name = %s\n", __FILE__);
	printf("Date = %s\n", __DATE__);
	printf("Time = %s\n", __TIME__);

	PRINT(DESD);
	PRINT(10 + 20);
	
	int totalSum = 10;

	printf("totalSum = %d\n", totalSum);
	printf("totalSum = %d\n", PASTE(total,Sum));

	return 0;
}































