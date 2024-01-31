#include<stdio.h>

typedef struct person
{
	char name[20];			// 20
	char gender;			// 1
	unsigned char age;		// 1	
	char address[20];		// 20
}person_t;					// 42

int main(void)
{
	person_t p[4] = {
			{"abc", 'M', 27, "pune"},
			{"pqr", 'F', 54, "mumbai"},
			{"xyz", 'M', 40, "delhi"},
			{"mno", 'F', 35, "pune"}
		};

	printf("sizeof(person_t) = %ld\n", sizeof(person_t));

	printf("Person's Details : \n");
	for(int i = 0 ; i < 4 ; i++)
	{
		printf("%-20s", p[i].name);
		printf("%-2c", p[i].gender);
		printf("%-4d", p[i].age);
		printf("%-20s\n", p[i].address);
	}
	return 0;
}































