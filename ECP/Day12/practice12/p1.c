
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int len;
	
	printf("Enter length of Array : ");
	scanf("%d",&len);
	
	//long *mobile_no = (long *)malloc(len * sizeof(long));
		
	long *mobile_no = (long *)calloc(len,sizeof(long));
	
	printf("Enter Mobile number : ");
	scanf("%ld", mobile_no);
	
	printf("Mobile Number : %ld\n",*(mobile_no));
	
	free(mobile_no);

	return 0;
}
