#include"header.h"

int main()
{
	int choice;
	do
	{
		printf("0. Exit\n1. Sign In\n2. Sign Up\n3. All User\n");
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
					sign_in();
				break;
			case 2:
					sign_up();
				break;
			case 3:
					printf("total user = %d\n",all_user());
				break;
			default:
					printf("Invalid choice....\n");
				break;
            case 0:
				break;
		}
	}while(choice != 0);
	return 0;
}

void sign_in()
{
	char email[20];
	char pass[20];
	printf("\nEnter Email:");
		scanf("%*c%[^\n]s",email);
	printf("Enter Password:	");
		scanf("%*c%[^\n]s",pass);
	user_t temp;
	FILE *fptr = fopen("user_data.txt", "ab+");
		if(fptr == NULL)
		{
			printf("failed to open user data file\n");
			return;
		}
		while(fread(&temp, sizeof(user_t), 1, fptr) != 0)
		{
		
			if((strcmp(temp.email, email) ==0 && strcmp(temp.pass, pass)==0))
			{
					printf("\nFirst name :%s\n",temp.f_name);
					printf("Last name  :%s\n",temp.l_name);
					printf("Email      :%s\n",temp.email);
					printf("Password   :%s\n",temp.pass);
					printf("Matched id :%d\n",temp.id.user_id);
			fclose(fptr);
			logged_in(temp.id.user_id,email,pass);
			return;
			}
		}
	fclose(fptr);
	printf("user not found....:\n");
}

void sign_up()
{
	int u_id=0;
	user_t temp;
    FILE *fptr = fopen("user_data.txt", "ab+");
		if(fptr == NULL)
		{
			u_id=0;
			fclose(fptr);
		}
		else
		{
			while(fread(&temp, sizeof(user_t), 1, fptr) != 0)
			u_id++;
			fclose(fptr);
		}
		
	user_t temp1;
		printf("total user =%d\n",u_id);
		printf("Enter First name :");
			scanf("%*c%[^\n]s",temp1.f_name);
		printf("Enter Last name :");
			scanf("%*c%[^\n]s",temp1.l_name);
		printf("Enter birth date (dd-mm-yy) :");
			scanf("%*c%[^\n]s",temp1.birthdate);
		printf("Enter Email :");
			scanf("%*c%[^\n]s",temp1.email);
		printf("Enter Password :");
			scanf("%*c%[^\n]s",temp1.pass);
		
		temp1.id.user_id = u_id+1;
		FILE *fptr1 = fopen("user_data.txt", "ab+");
			if(!fptr1){
				printf("failed to open user data file\n");
				return;
			}
			fwrite(&temp1, sizeof(user_t), 1, fptr1);
		fclose(fptr1);
		return;
}

int all_user()
{
	int count=0;
	user_t temp;
    FILE *fptr = fopen("user_data.txt", "rb+");
	if(fptr == NULL)
	{
		printf("failed to open user data file\n");
		return 0;
	}
    while(fread(&temp, sizeof(user_t), 1, fptr) != 0)
	{		
		printf("%d. ",temp.id.user_id);
		printf("%s ",temp.f_name);
		printf("%s ",temp.l_name);
		//printf("birthdate :%s, ",temp.birthdate);
		printf("(%s )\n",temp.email);
		//printf("Password  :%s\n",temp.pass);
		count++;
	}
	printf("\n");
	fclose(fptr);
	return count;
}

void logged_in(int u_id,char email[20],char pass[20])
{
	int choice;
	do
	{
		printf("\n0. Sign out\n1. Edit Profile\n2. Change Password\n3. Display All Movies\n4. Create Review\n5. Edit Review\n6. Delete Review\n7. Display All review\n8. Display My Reviews\n9. Display Reviews Shared With me\n10. Share Review\n");
		printf("Enter choice:	");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				edit_profile(u_id,email);
				break;
			case 2:
				change_pass(email,pass);
				break;
			case 3:
				display_movies();
				break;
			case 4:
				create_review(u_id);
				break;
			case 5:
				edit_review(u_id);
				break;
			case 6:
				delete_review(u_id);
				break;
			case 7:
				display_all_review();
				break;
			case 8:
				display_my_review(u_id);
				break;
			case 9:
				display_review_shared_with_me(u_id);
                break;
            case 10:
                share_review(u_id);
                break;
			default:
				printf("Invalid Input!!\n");
                break;
            case 0:
				break;
		}
	}while(choice != 0);
	return;
}

void edit_profile(int u_id,char email[20])
{
	char f_name[20];
	char l_name[20];
    char birthdate[15];
    int choice;
	printf("\nuser id from sign in =%d",u_id);
	printf("\nuser id from sign in =%s\n",email);

	user_t temp;
    FILE *fptr = fopen("user_data.txt", "rb+");
	if(fptr == NULL)
	{
		printf("failed to open user data file\n");
		return;
	}
    while(fread(&temp, sizeof(user_t), 1, fptr) != 0)
	{
		if((strcmp(temp.email,email) == 0 ))
		{
			fseek(fptr,-sizeof(user_t),SEEK_CUR);
            do 
            {
                printf("\nwhat u want to change\n0. Exit\n1. first name\n2. Last name\n3. birth date\nEnter the Choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                        printf("Enter First name : ");
	                    scanf("%*c%[^\n]s",f_name);
                        strcpy(temp.f_name,f_name);
						fseek(fptr,-sizeof(user_t),SEEK_CUR);
						fwrite(&temp, sizeof(user_t), 1, fptr);
						printf("data changed\n");
                        break;
                    case 2:
                        printf("Enter Last name : ");
	                    scanf("%*c%[^\n]s",l_name);
                        strcpy(temp.l_name,l_name);
						fwrite(&temp, sizeof(user_t), 1, fptr);
                        printf("data changed\n");
                        break;
                    case 3:
                        printf("Enter the birthdate : ");
                        scanf("%*c%[^\n]s",birthdate);
                        strcpy(temp.birthdate,birthdate);
						fwrite(&temp, sizeof(user_t), 1, fptr);
                        printf("data changed\n");
						break;
					case 0:
                }
            }while(choice != 0 );
			fclose(fptr);
			return;
		}		
		    // printf("First name:%s\n",temp.f_name);
	    	// printf("Last name :%s\n",temp.l_name);
        	// printf("birthdate :%s\n",temp.birthdate);
	        // printf("Email     :%s\n",temp.email);
	        // printf("Password  :%s\n",temp.pass);
			// printf("User Id   :%d\n",temp.id.user_id);
    }
}

void change_pass(char email[20],char pass[20])
{
	char u_pass[20];	
	user_t temp;
    FILE *fptr = fopen("user_data.txt", "rb+");
	if(fptr == NULL)
	{
		printf("failed to open user data file\n");
		return;
	}
    while(fread(&temp, sizeof(user_t), 1, fptr) != 0)
	{
		if((strcmp(temp.email, email) ==0 && strcmp(temp.pass, pass)==0))
		{
            printf("Enter new password:	");
	        scanf("%*c%[^\n]s",u_pass);
            strcpy(temp.pass,u_pass);
			fseek(fptr,-sizeof(user_t),SEEK_CUR);
			fwrite(&temp, sizeof(user_t), 1, fptr);	
            printf("password changed\n");
            
        }
		fclose(fptr);      
		return;
	}
}

void display_movies()
{
	moives_t movie[10];
	movie[0].id=1;
	strcpy(movie[0].title,"skyfall");
	strcpy(movie[0].relese,"01-01-1990");
	movie[1].id=2;
	strcpy(movie[1].title,"matrix");
	strcpy(movie[1].relese,"01-01-1996");
	movie[2].id=3;
	strcpy(movie[2].title,"fast and furious");
	strcpy(movie[2].relese,"01-01-1992");
	movie[3].id=4;
	strcpy(movie[3].title,"sunrise");
	strcpy(movie[3].relese,"01-01-1986");
	movie[4].id=5;
	strcpy(movie[4].title,"avenger the end game");
	strcpy(movie[4].relese,"01-01-1980");
	movie[5].id=6;
	strcpy(movie[5].title,"free fall");
	strcpy(movie[5].relese,"01-01-1976");
	movie[6].id=7;
	strcpy(movie[6].title,"bellbottam");
	strcpy(movie[6].relese,"01-01-1976");
	movie[7].id=8;
	strcpy(movie[7].title,"the court");
	strcpy(movie[7].relese,"01-01-1975");
	movie[8].id=9;
	strcpy(movie[8].title,"life of pi");
	strcpy(movie[8].relese,"01-01-1980");
	movie[9].id=10;
	strcpy(movie[9].title,"airlift");
	strcpy(movie[9].relese,"01-01-1988");

	for(int i=0;i<10;i++)
		printf("movie [ id=%-2d title= %-30s relese=%s ]\n",movie[i].id,movie[i].title,movie[i].relese);
}

void create_review(int u_id)
{
	display_movies();
	review_t review,temp;
	int review_id = 0;
	FILE *fptr = fopen("review_data.txt", "ab+");
	if(fptr == NULL)
		review_id = 0;
	while(fread(&temp, sizeof(review_t), 1, fptr))
		review_id++;
	fclose(fptr);
	printf("\nEnter Movie Id :");
	    scanf("%d",&review.movie_id);
	printf("Enter Review :");
	    scanf("%*c%[^\n]s",review.review);
	printf("Enter rating :");
	    scanf("%d",&review.rating);
	review.id.user_id=u_id;
	review.id.review_id=review_id+1;
    time_t t_stamp;
    time(&t_stamp);
    strcpy(review.modified,ctime(&t_stamp));
	temp = review;	
	FILE *fptr1 = fopen("review_data.txt", "ab+");
	if(!fptr1)
	{
		printf("failed to open user data file\n");
		return;
	}
	fwrite(&temp, sizeof(review_t), 1, fptr1);
	fclose(fptr1);
	printf("Review saved, review id =%d",temp.id.review_id);
}

void edit_review(int u_id)
{
	display_my_review(u_id);
	int u_review_id,u_rating;
	char u_review[20];
	printf("Enter Review Id : ");
		scanf("%d",&u_review_id);
	
	review_t temp;
    FILE *fptr = fopen("review_data.txt", "rb+");
	if(fptr == NULL)
	{
		printf("failed to open user data file\n");
		return;
	}
    while(fread(&temp, sizeof(review_t), 1, fptr) != 0)
	{
		if(temp.id.review_id== u_review_id)
		{
				printf("Update Review : ");
					scanf("%*c%[^\n]s",u_review);
				strcpy(temp.review,u_review);
				printf("Upadate Rating: ");
					scanf("%d",&temp.rating);
				fseek(fptr,-sizeof(review_t),SEEK_CUR);
				fwrite(&temp, sizeof(review_t), 1, fptr);
				printf("Review & Rating Updated\n");
                       
		}
    }
	fclose(fptr);
	return;
}

void delete_review(int u_id)
{
	display_my_review(u_id);
	FILE *fp;
	FILE *fp_tmp;
	review_t review;
	int rev_id,found=0;
	fp=fopen("review_data.txt", "rb");
	if (!fp)
	{
		printf("Reviews not found!\n");
		return;
	}
	fp_tmp=fopen("tmp.bin", "wb");
	if (!fp_tmp) 
	{
		printf("Unable to open file temp file.");
	}
	printf("Enter review id to delete review:");
		scanf("%d",&rev_id);
	while (fread(&review,sizeof(review_t),1,fp) != 0) 
	{
		if (review.id.review_id==rev_id ) 
		{
			printf("A record with requested name found and deleted.\n\n");
			found=1;
		} else 
		{
			fwrite(&review, sizeof(review_t), 1, fp_tmp);
		}
	}
	if (!found)
	{
		printf("No review found with the requested id");
	}
	fclose(fp);
	fclose(fp_tmp);
	remove("review_data.txt");
	rename("tmp.bin", "review_data.txt");
	return ;
}

void display_all_review()
{
	review_t review;
	FILE *fptr = fopen("review_data.txt", "rb");
	if(fptr == NULL)
	{
		printf("failed to open user data file\n");
		return;
	}
	while(fread(&review, sizeof(review_t), 1, fptr) != 0)
	{
		printf("review [ id=%-2d movieId=%-2d userId=%-2d review=%-20s rating=%-2d modified=%-20s]",
			review.id.review_id,review.movie_id,review.id.user_id,review.review,review.rating,review.modified);
	}
}

void display_my_review(int u_id)
{
	review_t review;
	FILE *fptr = fopen("review_data.txt", "rb");
	if(fptr == NULL)
	{
		printf("failed to open user data file\n");
		return;
	}
	printf("Your reviews:\n");
	while(fread(&review, sizeof(review_t), 1, fptr) != 0)
	{
	if(review.id.user_id==u_id)
		{
			printf("review [id=%-2d movieId=%-2d, userId=%-2d, review=%-15s, rating=%-2d, modified=%-20s]",
				review.id.review_id,review.movie_id,review.id.user_id,review.review,review.rating,review.modified);
		}
	}
}

void display_review_shared_with_me(int u_id)
{
	review_t review;
	share_t share;
	FILE *fptr = fopen("shared_review_data.txt", "rb+");
		if(fptr == NULL)
		{
			printf("failed to open user data file\n");
			return ;
		}
		printf("shared reviews:\n");
		while(fread(&share, sizeof(share_t), 1, fptr) != 0)
		{
			if(share.user_id==u_id)
			{
				FILE *fptr1 = fopen("review_data.txt", "rb+");
					if(fptr1 == NULL)
					{
						printf("failed to open user data file\n");
						return ;
					}
					while(fread(&review, sizeof(review_t), 1, fptr1) != 0)
					{
						if(review.id.review_id==share.review_id)
						{
							printf("review [id=%-2d movieId=%-2d userId=%-2d review=%-15s rating=%-2d modified=%-20s]",
								review.id.review_id,review.movie_id,review.id.user_id,review.review,review.rating,review.modified);
						}
					}
				fclose(fptr1);
			}		
		}
	fclose(fptr);
	return;
}

void share_review(int u_id)
{
	int review_id=0;
	char share_str[20];
	review_t review;
	share_t share;
	display_my_review(u_id);
	printf("Enter review id to be shared : ");
		scanf("%d",&review_id);
	FILE *fptr = fopen("review_data.txt", "rb+");
	if(fptr == NULL)
	{
		printf("failed to open user data file\n");
		return ;
	}
	while(fread(&review, sizeof(review_t), 1, fptr) != 0)
	{
		if(review.id.review_id==review_id)
		{
			printf("Selected review:\n");
			printf("review [id=%-2d movieId=%-2d userId=%-2d review=%-15s rating=%-2d modified=%-20s]",
				review.id.review_id,review.movie_id,review.id.user_id,review.review,review.rating,review.modified);
		}
	}
	fclose(fptr);

	int no_user=all_user();
	printf("Enter user ids to share with review with (enter 0 to end): ");
		scanf("%s",share_str);
	int count=0,i=0;
	while(i < no_user && (share_str[i]-48))
	{
		share.user_id = share_str[i]-48;
		share.review_id=review_id;
		FILE *fptr2 = fopen("shared_review_data.txt", "ab+");
			if(fptr2 == NULL)
			{
				printf("failed to open user data file\n");
				return;
			}
			fwrite(&share,sizeof(share_t),1,fptr2);
		fclose(fptr2);
		i++;
		count++;
	}
	printf("Review shared with %d user succesfully.\n",count);
	return;
}
