#include<stdio.h>

int main(void)

{

	char ch;
	int val;

	printf("Enter Character :");
	scanf("%c",&ch);

	printf("Enter ASCII :");
	scanf("%d",&val);
	printf("Decimal value of %c: %d\n",ch,ch);
	printf("Hexa value of %c : %x\n",ch,ch);
	printf("octal value of %c: %o\n",ch,ch);
	printf("Character value of %d : %c\n",val,val);



	return 0;
	
}
