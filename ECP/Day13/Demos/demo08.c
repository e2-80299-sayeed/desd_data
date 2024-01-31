#include<stdio.h>
#include<stdlib.h>

typedef struct person
{
	char name[20];			// 20
	char gender;			// 1
	unsigned char age;		// 1	
	char address[20];		// 20
}person_t;					// 42

void accept_person(person_t *);
void print_person(person_t *);

int main(void)
{
	person_t *ptr = (person_t *)malloc(1 * sizeof(person_t));
	//person_t *ptr = (person_t *)calloc(1, sizeof(person_t));
	// err check

	accept_person(ptr);
	print_person(ptr);

	free(ptr);

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

void accept_person(person_t *p)
{
	printf("Enter person Info (name, gender, age, address) : ");
	scanf("%s %c %d %s", p->name, &p->gender, &p->age, p->address);
}



























