#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int count = 5;
	// create array of character pointers
	char **courses = (char **)malloc(count * sizeof(char *));
	// err check

	// create 5 arrays of characters
	for(int i = 0 ; i < count ; i++)
		courses[i] = (char *)malloc(20 * sizeof(char));

	// use allocated space
	printf("Enter courses : \n");
	for(int i = 0 ; i < count ; i++)
		scanf("%s", courses[i]);

	printf("Courses : ");
	for(int i = 0 ; i < count ; i++)
		printf("%-10s", courses[i]);
	
	// free allocated space of 5 character arrays
	for(int i = 0 ; i < count ; i++)
		free(courses[i]);

	// free allocated space of array of character pointers
	free(courses);

	return 0;
}































