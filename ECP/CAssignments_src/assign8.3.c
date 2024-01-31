/*
3. Write a function to accept array of student’s information from the user. Write another function
to print the array student’s information. Re-use these functions in rest of the assignments
wherever required.
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

	stud_t s1[5];
	
	accept_info(s1);
	
	printf("\n\n");		
	
	printf("Stduents Info : \n");	
	
	print_info(s1);	

	return 0;
}

void accept_info(stud_t *p)
{	
	for(int i = 0 ; i < 5 ; i++)
	{
	printf("Enter student information(%d) : ",i);
	scanf("%d %s %f", &p[i].rollno, p[i].name, &p[i].marks);
	}
}

void print_info(stud_t *p)
{
	for(int i = 0 ; i < 5 ; i++)
	printf(" %-10d %-8s %-2.2f \n",p[i].rollno, p[i].name,p[i].marks);

}
