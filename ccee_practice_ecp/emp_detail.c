#include<stdio.h>
#include<stdlib.h>

typedef struct employee{
    char name[20];
    char mob[20];
    int id;
    struct date_of_birth{
        int dd;
        int mm;
        int yy;
    }dob;
}emp_t;

emp_t accept_emp(emp_t *);
void print_emp(emp_t*);
int count=4;

int main()
{
  
   
    emp_t **ptr =(emp_t**)malloc(count*sizeof(emp_t*));
    if(ptr==NULL)
    {
        printf("malloc() failed..\n");
    }

    for(int i=0; i<count; i++)
    {
        ptr[i] =(emp_t *)malloc( 1 * sizeof(emp_t)); 
    }
    

    for(int i=0; i<count; i++)
    {
        accept_emp(ptr[i]);
    }
    
    for(int i=0; i<count; i++)
    {
      print_emp(ptr[i]);
    }
    

    //free memory
    for(int i=0; i<count; i++)
    {
        free(ptr[i]);
    }

    free(ptr);
    return 0;
}

emp_t accept_emp(emp_t *ptr)
{
    printf("Enter employee detail....\n");
    
    printf("enter empid : ");
    scanf("%d",&ptr->id);
    
    printf("enter name : ");
    scanf("%s",ptr->name);

    printf("enter mob : ");
    scanf("%s",ptr->mob);

    printf("enter DOB : ");
    scanf("%d %d %d",&ptr->dob.dd, &ptr->dob.mm, &ptr->dob.yy);
}

void print_emp(emp_t *ptr)
{
        printf("employee detail....\n");
        
        printf("Name : %s\n",ptr->name);
        printf("Empid : %d\n", ptr->id);
        printf("MOB : %s\n",ptr->mob);
        printf("DOB : %d/%d/%d \n", ptr->dob.dd, ptr->dob.mm, ptr->dob.yy);
}