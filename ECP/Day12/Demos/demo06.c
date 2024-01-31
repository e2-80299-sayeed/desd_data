#include<stdio.h>

int main(void)
{
	int rollnos[4];
	char names[4][20];
	int stds[4];
	float marks[4];

	printf("Enter students info (rollno, name, std, marks) : ");
	for(int i = 0 ; i < 4 ; i++)
		scanf("%d %s %d %f", &rollnos[i], names[i], &stds[i], &marks[i]);

	printf("Student records : \n");
	for(int i = 0 ; i < 4 ; i++)
		printf("%-4d %-20s %-4d %-6.2f\n", rollnos[i], names[i], stds[i], marks[i]);
	return 0;
}































