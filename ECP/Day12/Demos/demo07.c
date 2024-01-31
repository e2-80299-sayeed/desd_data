#include<stdio.h>
#include<string.h>

// struct <name of structure>
// {
	// declaration of members	
// };
// type declaration
struct student
{
	int rollno;
	char name[20];
	int std;
	float marks;
};

int main(void)
{
	// struct student s1;
	struct student s1 = {1, "abc", 5, 56.5f};		// structure initialiser list
	struct student s2;

	s2.rollno = 2;
	strcpy(s2.name, "pqr");
	s2.std = 7;
	s2.marks = 87.0f;

	// sizeof(structure) = sum of sizes of all its members
	printf("sizeof(s1) = %ld\n", sizeof(s1));		// 32 bytes
	
	printf("student info s1 : %d %s %d %f\n", s1.rollno, s1.name, s1.std, s1.marks);
	printf("student info s2 : %d %s %d %f\n", s2.rollno, s2.name, s2.std, s2.marks);

	return 0;
}































