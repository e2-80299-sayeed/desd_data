#include<stdio.h>

typedef struct student
{
	int rollno;
	char name[20];
	int std;
	float marks;
}stud_t;

void accept_student(stud_t *);
void print_student(stud_t);

int main(void)
{
	stud_t s1;

	accept_student(&s1);
	print_student(s1);

	return 0;
}

//	s1 -> by address	: 8 bytes are copied from actual to formal arguments
//  pointers are used to pass structure variables to the function efficiently

void accept_student(stud_t *ptr)
{
	// scanf("%d %s %d %f", &ptr->rollno, ptr->name, &ptr->std, &ptr->marks);
	printf("Enter student Info : \n");
	printf("Rollno : ");
	scanf("%d", &ptr->rollno);

	printf("Name : ");
	scanf("%s", ptr->name);

	printf("Std : ");
	scanf("%d", &ptr->std);
	
	printf("Marks : ");
	scanf("%f", &ptr->marks);
}

// s1 -> by value : 32 bytes are copied from actual to formal arguments
void print_student(stud_t s)
{
	printf("student info : \n");
	printf("Name : %s\nRoll No : %d\nStd : %d\nMarks : %f\n", s.name, s.rollno, s.std, s.marks);
}






























