#include<stdio.h>

typedef struct person
{
	char name[20];			// 20
	char gender;			// 1
	unsigned char age;		// 1	
	char address[20];		// 20
}person_t;					// 42

void print_person(person_t *);
void print_persons(person_t *);

int main(void)
{
	// p - array
	person_t p[4] = {
			{"abc", 'M', 27, "pune"},
			{"pqr", 'F', 54, "mumbai"},
			{"xyz", 'M', 40, "delhi"},
			{"mno", 'F', 35, "pune"}
		};

	print_persons(p);

	return 0;
}


// p - structure pointer - address of one person
void print_person(person_t *p)
{
	printf("%-20s", p->name);
	printf("%-2c", p->gender);
	printf("%-4d", p->age);
	printf("%-20s\n", p->address);
}


// p - stucture pointer - base address of array
void print_persons(person_t *p)
{
	printf("Person's Details : \n");
	for(int i = 0 ; i < 4 ; i++)
		//print_person(&p[i]);
		//print_person(&*(p + i));
		print_person(p + i);
}



























