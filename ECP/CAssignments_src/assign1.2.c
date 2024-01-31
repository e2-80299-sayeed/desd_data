#include<stdio.h>

int main(void)

{
	int num;

	printf("Enter Number : ");
	scanf("%d",&num);

	printf("Character value of %d is : %c\n",num,num);
	printf("Decimal value of %d is : %d\n",num,num);
	printf("Octal value of %d is : %o\n",num,num);
	printf("Hexa-decimal value of %d is : %x\n",num,num);

	return 0;
	
}
