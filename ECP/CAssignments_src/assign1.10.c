/*
10. Write a program to calculate Area and Perimeter of Triangle for given length of three sides of
triangle. Use sqrt() function from math.h to calculate square root.
Perimeter = a + b + c
Area = 
Test the program using values 3,4,5 and 1, 2, 3 and 1, 2, 4 for a, b, c. Observe the results.

*/
#include<stdio.h>
#include<math.h>

int main(void)
{
	
	int P,A,a,b,c,s;
	
	printf("Enter length of three sides of triangle :  ");
	scanf("%d%d%d",&a,&b,&c);
	
	P = a+b+c;
	printf("Perimeter of Triangle = %d\n",P);
	
	s = (a+b+c) / 2;
	A = (s * (s - a) * (s - b)*(s - c));

	printf("Area of Triangle = %lf\n",sqrt(A));

return 0;

}
