/*Write a program to convert temperature in Celsius to Fahrenheit and vice versa. Formula for
conversion is 
*/

#include<stdio.h>

int main()
{
 
	float  cel,fahren;

	printf("Enter Temperature in fahrenheit : ");
	scanf("%f",&fahren);
	
	cel =(fahren-32)*5.00/9.00;
		
	printf("celsius= %f\n",cel);
	
	fahren = (9*cel)/5+32;
	
	printf("fahren= %f\n",fahren);

return 0;
}
