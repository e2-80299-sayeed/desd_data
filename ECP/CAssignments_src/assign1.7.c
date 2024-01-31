/*
Write a program to accept a 4 digit number and
a. Display face value of each decimal digit
b. Display place value of each decimal digit
c. Display no in reverse order by changing decimal place values
If user enters a 4 digit number 9361 output should be
a. 9361
b. 9361 = 9000 + 300 + 60 + 9
c. 1639

*/

#include<stdio.h>

int main(void)

{

	int num,q1,q2,q3,r1,r2,r3;

	printf("Enter a four digit number:");
	scanf("%d",&num);

	r1 = num % 10;
	q1 = num / 10;
	r2 = q1 % 10;
	q2 = q1 / 10;
	r3 = q2 % 10;
	q3 = q2 / 10;
		
	printf("face value of %d = %d\t  %d\t %d\t %d\t\n",num,q3,r3,r2,r1);
	
	
	printf("place value of %d = %d + %d + %d + %d \n",num,q3*1000,r3*100,r2*10,r1);

	printf("Digits of entered number in reverse order: %d%d%d%d\n ",r1,r2,r3,q3);



return 0;
}
