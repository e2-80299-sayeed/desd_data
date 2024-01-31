#include<stdio.h>

typedef struct student
{
	int rollno;
	char name[20];
	int std;
	float marks;
}stud_t;

void accept_student(stud_t *);
void print_student(stud_t *);
void add_student(stud_t *);
void print_students(void);
int search_student(int);
void update_marks(int, float);

int main(void)
{
	stud_t s;
	int choice, rollno;
	float new_marks;

	do
	{
		printf("0. Exit\n");
		printf("1. Add student\n");
		printf("2. Print students\n");
		printf("3. Search student\n");
		printf("4. Edit marks\n");

		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				accept_student(&s);
				add_student(&s);
				break;

			case 2:
				print_students();
				break;
			
			case 3:
				printf("Enter rollNo : ");
				scanf("%d", &rollno);
				search_student(rollno);
				break;

			case 4:
				printf("Enter rollno : ");
				scanf("%d", &rollno);
				printf("Enter correct marks : ");
				scanf("%f", &new_marks);
				update_marks(rollno, new_marks);
				break;
		}
	}while(choice != 0);

	return 0;
}

void accept_student(stud_t *s)
{
	printf("Enter student info : (rollno, name, std, marks) : ");
	scanf("%d %s %d %f", &s->rollno, s->name, &s->std, &s->marks);
}

void print_student(stud_t *s)
{
	printf("%-4d%-20s%-4d%-5.2f\n", s->rollno, s->name, s->std, s->marks);
}

void add_student(stud_t *s)
{
	FILE *fp = fopen("students.db", "ab");
	fwrite(s, sizeof(stud_t), 1, fp);
	fclose(fp);
}

void print_students(void)
{
	stud_t s;
	FILE *fp = fopen("students.db", "rb");
	while((fread(&s, sizeof(stud_t), 1, fp)) != 0)
		print_student(&s);
	fclose(fp);
}

int search_student(int rollno)
{
	stud_t s;
	FILE *fp = fopen("students.db", "rb");
	while((fread(&s, sizeof(stud_t), 1, fp)) != 0)
		if(rollno == s.rollno)
		{
			print_student(&s);
			fclose(fp);
			return 1;
		}
	fclose(fp);
	return 0;
}

void update_marks(int rollno, float new_marks)
{
	stud_t s;
	FILE *fp = fopen("students.db", "rb+");
	while((fread(&s, sizeof(stud_t), 1, fp)) != 0)
		if(rollno == s.rollno)
		{
			s.marks = new_marks;
			fseek(fp, -sizeof(stud_t), SEEK_CUR);
			fwrite(&s, sizeof(stud_t), 1, fp);
			fclose(fp);
			return;
		}
	fclose(fp);
}



























