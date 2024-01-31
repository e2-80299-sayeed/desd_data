#include<stdio.h>
#include<stdlib.h>

typedef struct person
{
	char name[20];
	int age;
	char gender;
}person_t;

typedef struct employee
{
	int empid;
	person_t pinfo;
	double salary;
}emp_t;

void accept_employees(emp_t *);
void print_employees(emp_t *);


int main(void)
{
	//emp_t arr[3];

	emp_t *arr = (emp_t *)malloc(3 * sizeof(emp_t));

	accept_employees(arr);
	print_employees(arr);

	free(arr);

	return 0;
}


void accept_employees(emp_t *arr)
{
	for(int i = 0 ; i < 3 ; i++)
	{
		// arr[i] = elemets of array
		// &arr[i] = addresses of array elements
		printf("Enter employee details : \n (empid, name, age, gender, salary) : ");
		scanf("%d %s %d %c %lf", &arr[i].empid, arr[i].pinfo.name, &arr[i].pinfo.age, &arr[i].pinfo.gender, &arr[i].salary);
	}

}
void print_employees(emp_t *arr)
{
	for(int i = 0 ; i < 3 ; i++)
		printf("%d %s %d %c %lf\n", arr[i].empid, arr[i].pinfo.name, arr[i].pinfo.age, arr[i].pinfo.gender, arr[i].salary);
}























