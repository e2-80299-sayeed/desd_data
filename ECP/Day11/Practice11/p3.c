#include <stdio.h>
#include<stdlib.h>

int main(void)
{
	int count;
	
	printf("Enter no of students : ");
	scanf("%d", &count);
	
	float *marks = (float *)calloc(count, sizeof(float));
	
	printf("Enter %d student marks : \n",count);
	for(int i = 0 ; i < count ; i++)
		scanf("%f", &marks[i]);
	
	printf("student marks : \n");
	for(int i = 0 ; i < count ; i++)
		printf("%-6.2f\n",marks[i]);
	printf("\n");
	
	free(marks);



	return 0;
}
