#include<stdio.h>

struct student
{
	int rollno;
	char name[20];
	int std;
	float marks;
};

typedef struct student stud_t;


int main(void)
{
	stud_t s1 = {
		.name = "abc",
		.std = 6,
		.rollno = 10,
		.marks = 76.5
	};
	
	stud_t *ptr = &s1;

	printf("Using s1 : \n");
	printf("Name : %s\n", s1.name);
	printf("Rollno = %d\n", s1.rollno);
	printf("Std : %d\n", s1.std);
	printf("Marks : %f\n", s1.marks);

	printf("Using ptr : \n");
	printf("Name : %s\n", ptr->name);
	printf("Rollno = %d\n", ptr->rollno);
	printf("Std : %d\n", ptr->std);
	printf("Marks : %f\n", ptr->marks);

	return 0;
}































