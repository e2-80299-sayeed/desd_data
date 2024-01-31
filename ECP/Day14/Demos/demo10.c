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
void write_employees(emp_t *);
void print_employees(void);


int main(void)
{
	//emp_t arr[3];

	emp_t *arr = (emp_t *)malloc(3 * sizeof(emp_t));

	//accept_employees(arr);
	//write_employees(arr);
	print_employees();

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
void write_employees(emp_t *arr)
{
	//1. open file into write
	FILE *fp = fopen("emp.txt", "w");

	//2. write records into file
	for(int i = 0 ; i < 3 ; i++)
		fprintf(fp, "%d %s %d %c %lf\n", arr[i].empid, arr[i].pinfo.name, arr[i].pinfo.age, arr[i].pinfo.gender, arr[i].salary);
	
	//3. close file
	fclose(fp);

}


void print_employees(void)
{
	emp_t emp;

	//1. open file into read mode
	FILE *fp = fopen("emp.txt", "r");

	//2. read emp from file
	while(fscanf(fp, "%d %s %d %c %lf", &emp.empid, emp.pinfo.name, &emp.pinfo.age, &emp.pinfo.gender, &emp.salary) != EOF)	
		//3. print emp on console
		printf("%d %s %d %c %lf\n", emp.empid, emp.pinfo.name, emp.pinfo.age, emp.pinfo.gender, emp.salary);

	//4. close the file
	fclose(fp);

}




















