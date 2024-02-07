#include"main.h"


int movie_id = 0;
review_t review;
int main(void)
{
	int choice;
	user_t user;
	
	do
	{
		printf("0.Exit\n1.Sign Up\n2.Sign In\n");
		printf("Enter choice:	");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0: exit(0);
            case 1:
					sign_up(&user);
				break;

			case 2:
					sign_in(&user);
				break;

			default:
					printf("Invalid choice....(:");
				break;
		}

	}while(choice != 0);

	return 0;
}

void sign_up(user_t *user)
{
	int user_id = 1;

	user_t temp;

	 FILE *fptr = fopen("user_data.txt", "rb+");
	 if(fptr == NULL)
	 {
	 	perror("failed to open user data file\n");
	 	exit(1);
	 }

	 while(fread(&temp, sizeof(user_t), 1, fptr) != 0)
	 {
	 	user_id++;
	 }
	 fclose(fptr);
	
	user->user_id = user_id;
	printf("Enter First name:	");
	scanf("%*c%[^\n]s",user->f_name);
	printf("Enter Last name:	");
	scanf("%*c%[^\n]s",user->l_name);
    printf("Enter DOB(dd-mm-yyyy):	");
	scanf("%*c%[^\n]s",user->dob);
	printf("Enter Mobile:	");
	scanf("%*c%[^\n]s",user->mob_no);
	printf("Enter Email:	");
	scanf("%*c%[^\n]s",user->email);
	printf("Enter Password:	");
	scanf("%*c%[^\n]s",user->pass);

	temp = *user;	//temp variable to write into file
	fptr = fopen("user_data.txt", "ab+");
	if(fptr == NULL){
		perror("failed to open user data file\n");
	exit(1);
	}

	fwrite(&temp, sizeof(user_t), 1, fptr);
	fclose(fptr);
    
	int reg = 0;
    printf("User registered : %d\n",++reg);

	return; 

}

//****************************************************************************************************************

void sign_in(user_t *user)
{
	char email[20];
	char pass[20];
	printf("Enter Email:	");
	scanf("%*c%[^\n]s",email);
	printf("Enter Password:	");
	scanf("%*c%[^\n]s",pass);
	
	user_t temp;
	
	
	FILE *fptr = fopen("user_data.txt", "rb+");
	if(fptr == NULL)
	{
		perror("failed to open user data file\n");
		exit(1);
	}

	while(fread(&temp, sizeof(user_t), 1, fptr) != 0)
	{
	
		if((strcmp(temp.email, email) == 0 && strcmp(temp.pass, pass) == 0))
		{
			  	//get id of match user
		printf("matched id = %d\n\n", temp.user_id);
			logged_in(user, temp.user_id);		//user id passing
			return;
		}
	}
	printf("\nuser not found....  :(\n");
}
//****************************************************************************************************************


void logged_in(user_t *user, int id)
{
	int choice;
	do 
    {
		printf("0.logout\n1.Edit profile\n2.Change password\n3.Write a review\n4.Edit a review\n5.Display all movies\n6.Display all reviews\n7.Display my reviews\n8.Display review shared with me\n9.Share a review\n10.Delete a review\n11.Display profile\n");
		printf("Enter choice:	");
		scanf("%d", &choice);

	
		switch(choice)
		{
            case 0 :
                    break;
            case 1:
				edit_profile(user);
				break;
			case 2:
				change_pass(user,id);
				break;
			case 3:
				write_a_review(id);
				break;
			case 4:
				edit_review(id);
				break;
			case 5:
				display_all_movies();
				break;
			case 6:
				display_all_reviews(review);
				break;
			case 7:
				display_my_reviews(id);
				break;
			case 8:
				display_review_shared_with_me(id);
				break;
			case 9:
				share_review(id);
				break;
            case 10:
                delete_review(id);
				break;
			case 11:
				display_profile(id);
				break;
			default:
        		return;
		}

	}while(choice != 0);
}