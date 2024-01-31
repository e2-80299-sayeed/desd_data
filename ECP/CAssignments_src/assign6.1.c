/*
1. Write a program to demonstrate use of string library functions.
a. strlen() e. stricmp() i. strncpy() b. strcpy() f. strrev() j. strncat() c. strcat() g. strchr() k. strncmp() d. strcmp() h. strstr() l. strtok()
*/

#include<stdio.h>
#include<string.h>

int main(void)
{
	char str1[50] = "My name is Student. ";
	char str2[60] = "is";
	
	//printf("Enter str1 :\n");
	//scanf("%s",str1);
	
	//printf("Enter str2 :");
	//scanf("%s",str1);

	printf("str1 = %s\nstr2 = %s \n",str1,str2);
	
	printf("length of str1: %ld\n",strlen(str1));	
	printf("length of str2: %ld\n",strlen(str2));	
	
//	strcpy(str2,str1);
	
//	printf("After strcpy : \nstr1 = %s, str2 = %s\n",str1,str2);

//	strncpy(str2,str1,5);
//	printf("After strcpy : \nstr1 = %s, str2 = %s\n",str1,str2);
/*
	int ret = strcmp(str1, str2);
	if(ret == 0)
		printf("str1 and str2 are equal\n");
	else if(ret<0)
		printf("str1 is less than str2\n");
	else 
		printf("str1 is greater than str2\n");


	char c = 'm';
	
	char *ch = strchr(str1,c);
	printf("After Strchr : %s\n",ch);
	
	
	
	strcat(str1,str2);
	printf("After strcat : %s\n",str1);
	

 	int ret = strcasecmp(str1,str2);

	if(ret == 0)
		printf("str1 and str2 are equal\n");
	else if(ret<0)
		printf("str1 is less than str2\n");
	else 
		printf("str1 is greater than str2\n");


	char *ptr = strstr(str1,str2);	
	printf("ptr = %s\n",ptr);


	
	char *ptr = NULL;
	
	printf("str1 = %s\n",str1);

	ptr = strstr(str1,str2);

	printf("ptr = %s\n",ptr);
	
*/

	char *ptr = NULL;
	
	printf("str = %s\n",str1);
	
	ptr = strtok(str1, " ");
	printf("ptr = %s\n", ptr);
	
	for(int i = 0; ptr != NULL; i++)
	{
		ptr = strtok(NULL, " ");
	
		printf("ptr = %s\n",ptr);
			
	
	}
	

	return 0;


}

