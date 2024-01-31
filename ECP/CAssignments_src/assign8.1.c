/*

1. Declare a structure to store data for student information. The structure contains roll number,
name, marks for students. Write a program to accept information of student from user and print
the same.

*/

#include<stdio.h>

typedef struct student
{
	int rollno;
	char name[20];
	float marks;

}stud_t;

int main(void)
{

	stud_t s1,s2,s3;

	
	printf("Enter student information : ");
	scanf("%d %s %f", &s1.rollno, s1.name, &s1.marks);
	
	printf("Enter student information : ");
	scanf("%d %s %f", &s2.rollno, s2.name, &s2.marks);
	
	printf("Enter student information : ");
	scanf("%d %s %f", &s3.rollno, s3.name, &s3.marks);
	
	printf("\n\n");	
	
	printf("Student info : %-10d %-8s %-2.2f \n",s1.rollno, s1.name, s1.marks);
	printf("Student info : %-10d %-8s %-2.2f \n",s2.rollno, s2.name, s2.marks);
	printf("Student info : %-10d %-8s %-2.2f \n",s3.rollno, s3.name, s3.marks);


	return 0;

}
