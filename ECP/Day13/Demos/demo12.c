#include<stdio.h>

typedef struct student
{
	int rollno;
	char name[20];
	int std;
	union result
	{
		float percent;
		char grade;
	} res;
}stud_t;

void accept_student(stud_t *);
void print_student(stud_t *);

int main(void)
{
	stud_t s;

	accept_student(&s);
	print_student(&s);
	
	printf("sizeof(stud_t) : %ld\n", sizeof(stud_t));

	return 0;
}

void accept_student(stud_t *s)
{
	printf("Enter student info : (rollno, name, std) : ");
	scanf("%d %s %d", &s->rollno, s->name, &s->std);
	if(s->std > 5)
	{
		printf("Enter percentage : ");
		scanf("%f", &s->res.percent);
	}
	else
	{
		printf("Enter grade : ");
		scanf("%*c%c", &s->res.grade);
	}
}
void print_student(stud_t *s)
{
	printf("Rollno : %d\n", s->rollno);
	printf("Name : %s\n", s->name);
	printf("Std : %d\n", s->std);
	s->std > 5 ? printf("Percentage : %f\n", s->res.percent) : printf("Grade : %c\n", s->res.grade);
}






























