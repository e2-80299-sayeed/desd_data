#include<stdio.h>
#include<stdlib.h>

void display_matrix_in_row_major(int *);
void display_matrix_in_coloumn_major(int *);
 int i, j;

int main(void)
{	
   int choice;
	arr = (int *)malloc(9 * sizeof(int)); 
   
	for (i = 0; i < 3; i++)
     	 for (j = 0; j < 3; j++)
        scanf("%d", (arr + i * 3 + j));    
   
		
	do 
	{
	 
	printf("0.Exit\n1.Display matrix in row major order\n2.Display matrix in coloumn major order\n3.Check is matrix symmetric.\n4.Check is matrix magic square\n5.Find transpose of a matrix\n6.Calculate determinant");
   
	
	  printf("\n");
	
	printf("Enter Choice :");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1: 
			display_matrix_in_row_major(arr);
			break;

		case 2:	 
			display_matrix_in_coloumn_major(arr);
			break;
		case 3:
			break;


	}

	}while(choice != 0);

	 
	printf("\n");
	
	free(arr);
	 
   	
	return 0;
}


void display_matrix_in_row_major(int *arr )
{

	printf("matrix_in_row_major :\n");
  	 for (i = 0; i < 3; i++) 
	{
     		 for (j = 0; j < 3; j++) 	
       	 {
	         printf("%d ", *(arr + i * 3 + j)); 
     	 }	
   
 		  printf("\n");
   	}


}
	
void display_matrix_in_coloumn_major(int * arr)
{

	printf("matrix_in_coloumn_major :\n");
  	 for (i = 0; i < 3; i++ ) 
	{
     		 for (j = 0; j < 3; j++) 	
       	 {
	         printf("%d ", *(arr + j * 3 + i));
			
		
     	 }	
   
 		  printf("\n");
   	}


}











