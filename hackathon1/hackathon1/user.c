#include"main.h"

void change_pass(user_t *user,int id)
{
	int flag = 0;
	char email[20];
	char pass[20];
	printf("enter email :	");
	scanf("%*c%[^\n]s", email);
    printf("enter current password:	");
	scanf("%*c%[^\n]s", pass);

	FILE *fptr = fopen("user_data.txt", "rb+");
	if(fptr == NULL)
    {
		perror("failed to open user data file\n");
	    exit(1);
    }
	while(fread(user, sizeof(user_t), 1, fptr) != 0)
	{
		if((strcmp(user->email, email) == 0 && strcmp(user->pass, pass) == 0))
		{
			printf("Enter new password:	");
			scanf("%*c%[^\n]s", pass);
			strcpy(user->pass, pass);
			fseek(fptr,-sizeof(user_t),SEEK_CUR);
			fwrite(user,sizeof(user_t),1,fptr);
			printf("\npassword updated successfully\n\n");
			
			flag++;
			break;
		}
         
	}
	if(flag == 0)	
		printf("\nWrong email or password\n\n");
         
    fclose(fptr);
	
}


//****************************************************************************


void edit_profile(user_t *user)
{

    char email[20];
	char pass[20];
	printf("enter email :	");
	scanf("%*c%[^\n]s", email);
    printf("enter password:	");
	scanf("%*c%[^\n]s", pass);

	FILE *fptr = fopen("user_data.txt", "rb+");
	if(fptr == NULL)
	{
		perror("failed to open user data file\n");
		exit(1);
	}
	int flag = 0;
    while(fread(user, sizeof(user_t), 1, fptr) != 0)
	{
	
		if((strcmp(user->email, email) == 0 && strcmp(user->pass,pass)== 0))
		{	int ch;
			char tmp[10];
						
		do{
			printf("What u want to change\n");
			printf("0.Exit\n1.first name\n2.last name\n3.mobile number\n4.birth_date\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 0 : break; 
                case 1:
					printf("enter new first name: ");
					scanf("%*c%[^\n]s",tmp);
					strcpy(user->f_name,tmp);
					break;
				case 2:
					printf("enter new last name: ");
					scanf("%*c%[^\n]s",tmp);
					strcpy(user->l_name,tmp);
					break;
				case 3:
					printf("enter new mobile number: ");
					scanf("%*c%[^\n]s",tmp);
					strcpy(user->mob_no,tmp);
					break;	
				case 4:
					printf("enter new birth date : ");
					scanf("%*c%[^\n]s",tmp);
					strcpy(user->dob,tmp);
					break;	

			}

		}while(ch!=0);

                    fseek(fptr,-sizeof(user_t), SEEK_CUR);
					fwrite(user, sizeof(user_t), 1, fptr);

                    fclose(fptr);
                    printf("Profile updated Successfully\n");
                    
					flag++;
					break;
		}
	}
		if(flag == 0)
        	printf("\nWrong Email or Password !!\n\n");

}

//****************************************************************************



int display_profiles(int id)
{  
	int count = 0;
	user_t user;
    FILE *fptr = fopen("user_data.txt", "rb+");
	if(fptr == NULL)
	{
		perror("failed to open user data file\n");
		exit(1);
	}
	
    while(fread(&user, sizeof(user_t), 1, fptr) != 0)
	{
	
	                //printf(" \nuser_id:	%d\n",user.user_id);
					// printf(" First name:	%s\n",user->f_name);
                    // printf(" Last name:	%s\n",user->l_name);
                    // printf(" DOB:	%s\n",user->dob);
                    // printf(" Mobile:	%s\n",user->mob_no);
                    // printf(" Email:	%s\n",user->email);
                    // printf(" Password:	%s\n\n",user->pass);
			if(user.user_id == id);
			else
				count++;
	}
                    fclose(fptr);
					return count;
}


//****************************************************************************


void display_profile(int id)
{  
	user_t user;
    
    FILE *fptr = fopen("user_data.txt", "rb+");
	if(fptr == NULL)
	{
		perror("failed to open user data file\n");
		exit(1);
	}
	int flag = 0;
    while(fread(&user, sizeof(user_t), 1, fptr) != 0)
	{
	
		if(user.user_id == id) 
        {
    
                    printf("\n user_id:	%d\n",user.user_id);
					printf(" First name:	%s\n",user.f_name);
                    printf(" Last name:	%s\n",user.l_name);
                    printf(" DOB:	%s\n",user.dob);
                    printf(" Mobile:	%s\n",user.mob_no);
                    printf(" Email:	%s\n",user.email);
                    printf(" Password:	%s\n\n",user.pass);

					flag++;
					break;
		}
	            
    }
	if(flag == 0)
			printf("\nWrong Email or password\n\n");
                    fclose(fptr);
}
