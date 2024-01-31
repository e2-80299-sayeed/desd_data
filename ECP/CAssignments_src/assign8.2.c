/*
2. Write a function to accept student information from the user. Write another function to print
student’s information. Re-use these functions in rest of the assignments whereever required.

*/

#include<stdio.h>

typedef struct student
{
	int rollno;
	char name[20];
	float marks;

}stud_t;

void accept_info(stud_t *p);
void print_info(stud_t *);

int main(void)
{

	stud_t s1,s2,s3;
	
	accept_info(&s1);
 	accept_info(&s2);
	accept_info(&s3);
	
	printf("\n\n");		
	
	printf("Stduents Info : \n");	
	
	print_info(&s1);	
	print_info(&s2);	
	print_info(&s3);	

	return 0;
}

void accept_info(stud_t *p)
{	
	printf("Enter student information : ");
	scanf("%d %s %f", &p -> rollno, p -> name, &p -> marks);
}

void print_info(stud_t *p)
{
	printf(" %-10d %-8s %-2.2f \n",p -> rollno, p -> name, p -> marks);

}
