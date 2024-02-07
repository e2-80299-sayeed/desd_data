#include"main.h"



void write_a_review(int id)
{
    display_all_movies();
    review_t review;
    int review_id = 1;

    
    review_t temp;

	FILE *fptr = fopen("reviews.txt", "rb+");
	if(fptr == NULL)
	{
	 	perror("failed to open reviews file\n");
	 	exit(1);
	}

	while(fread(&temp, sizeof(review_t), 1, fptr) != 0)
	{
	 	review_id++;
	}
	fclose(fptr);
    

    fptr = fopen("reviews.txt","ab+");
    char choice;
    do
    {
        printf("\nDo you want to add a new review? y/n : ");
        scanf(" %c", &choice);
        switch(choice)
        {
            case 'y':
            review.review_id = review_id;
            review.user_id = id;
            //printf("\nEnter review ID: ");
            //scanf("%d",&review.review_id);
            printf("\nEnter the movie ID : ");
            scanf("%d",&review.movie_id);
            printf("\nRate the movie from 1-5: ");
            scanf("%d",&review.rating);
            printf("\nWrite your review here: ");
            scanf("%*c%[^\n]s",review.review);
            
            time_t t_stamp;
            time(&t_stamp);
            strncpy(review.modified,ctime(&t_stamp),25);
            strcat(review.modified,"\0");      

            fseek(fptr,sizeof(review_t),SEEK_END);
            fwrite(&review,sizeof(review_t),1,fptr);
            printf("\nReview added Successfully!\n\n");
            fclose(fptr);
            break;
            default:
            printf("\nYou have chosen not to add any reviews.");
            return;
         }
    }while(choice =='y');
            
            
    
}

//****************************************************************************

void display_all_reviews(review_t temp) 
{
    
    
    FILE *fptr=fopen("reviews.txt","rb+");
    if(fptr==NULL)
    {
        printf("failed to open reviews file \n");
        exit(1);

    }
    while(fread(&temp,sizeof(review_t),1,fptr)!= 0)
    {
        printf("review_id :%d \t",temp.review_id );
        printf("user_id :%d \t",temp.user_id );
        printf("movie_id :%d\t",temp.movie_id );
        printf("rating : %d\t",temp.rating ); 
        printf("review : %s\t",temp.review );
        printf("modified : %s\t",temp.modified);
        printf("\n");    
    }
    fclose(fptr);   
}

//****************************************************************************

void display_my_reviews(int id)
{
    review_t temp;
    
    FILE *fptr=fopen("reviews.txt","rb+");
    if(fptr==NULL)
    {
        printf("failed to open reviews file \n");
        exit(1);

    }
    int flag = 0;
    while(fread(&temp,sizeof(review_t),1,fptr)!= 0)
    {
        if(id == temp.user_id)
        {
        printf("review_id :%d \t",temp.review_id );
        printf("user_id :%d \t",temp.user_id );
        printf("movie_id :%d\t",temp.movie_id );
        printf("rating : %d\t",temp.rating ); 
        printf("review : %s\t",temp.review );
        printf("modified : %s\t",temp.modified);
        printf("\n");    
        }
        flag++;
    
    }
    if(flag == 0)
        printf("No reviews found for this user !!\n");

        fclose(fptr);
}

//****************************************************************************

void edit_review(int id)
{
    display_my_reviews(id);

    int flag = 0;
    review_t review;
    int review_id;
    printf("Enter review_id to be edited :");
    scanf("%d",&review_id);

    FILE *fptr = fopen("reviews.txt", "rb+");
	if(fptr == NULL)
	{
		perror("failed to open user data file\n");
		exit(1);
	}

    while(fread(&review, sizeof(review_t), 1, fptr) != 0)
	{
	
		if(review.user_id == id  && review.review_id == review_id)
		{	
            printf("\nreview_id :%d \t",review.review_id );
            printf("user_id :%d \t",review.user_id );
            printf("movie_id :%d\t",review.movie_id );
            printf("rating : %d\t",review.rating ); 
            printf("review : %s\t",review.review );
            printf("modified : %s\t",review.modified);
            printf("\n\n");  
                
            int ch;
			char tmp[10];
            int rating;
						
		do{
			printf("What u want to change\n");
			printf("0.Exit\n1.rating\n2.review\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 0 : break; 
                case 1:
					printf("enter new rating\n");
					scanf("%d",&rating);
                    review.rating = rating;
					
					break;
				case 2:
					printf("enter new review \n");
					scanf("%*c%[^\n]s",tmp);
					strcpy(review.review,tmp);
					break;
			
			}

		}while(ch!=0);
                    
                    time_t t_stamp;
                    time(&t_stamp);
                    strncpy(review.modified,ctime(&t_stamp),25);
                    strcat(review.modified,"\0");

                    fseek(fptr,-sizeof(review_t), SEEK_CUR);
					fwrite(&review, sizeof(review_t), 1, fptr);

                    fclose(fptr);
                    printf("\nReview updated Successfully\n\n");
                    flag++;
                    break;
		}
	}
        if(flag == 0)
            printf("Invalid review_id !!\n");

}

//****************************************************************************


void delete_review(int id)
{
    display_my_reviews(id);
    review_t review;
    int rev_id,found = 0;
    
    FILE *fp;
    FILE *fp_temp;

    fp = fopen("reviews.txt" ,"rb+");
    if(fp==NULL)
    {
        printf("failed to open reviews file \n");
        exit(1);

    }

    fp_temp = fopen("temp.txt","wb+");
    if(fp_temp==NULL)
    {
        printf("failed to open reviews file \n");
        exit(1);

    }

    printf("Enter review_id to be deleted :");
    scanf("%d",&rev_id);

    while(fread(&review,sizeof(review_t),1,fp)!= 0)
    {
        if (review.review_id == rev_id && review.user_id == id)
        {            
            printf("A review with requested review_id found and deleted\n\n");
            found++;
        }
        else
        {
            fwrite(&review,sizeof(review_t),1,fp_temp);
        }
    }    
        if(!found)
        {
            printf("No review found with requested id\n");    
        }    
    
    fclose(fp);
    fclose(fp_temp);
    remove("reviews.txt");
    rename("temp.txt","reviews.txt");
    return;
}

//****************************************************************************

void share_review(int id)
{
	int review_id=0;
	char share_str[20];
	review_t review;
	share_t share;
	display_my_reviews(id);
	printf("Enter review id to be shared : ");
		scanf("%d",&review_id);
	
	/* FILE *fptr = fopen("reviews.txt", "rb+");
	if(fptr == NULL)
	{
		printf("failed to open reviews file\n");
		return ;
	}
	while(fread(&review, sizeof(review_t), 1, fptr) != 0)
	{
		if(review.review_id==review_id)
		{
			printf("Selected review:\n");
			printf("review [id=%-2d movieId=%-2d userId=%-2d review=%-15s rating=%-2d modified=%-20s]",
				review.review_id,review.movie_id,review.user_id,review.review,review.rating,review.modified);
		}
	}
	fclose(fptr);
	*/
	
	int no_user = display_profiles(id);
	printf("Enter user ids to share with review with (enter 0 to end): ");
	scanf("%s",share_str);
	int count=0,i=0;
	while(i < no_user && (share_str[i]-'0'))
	{
		share.user_id = share_str[i]-'0';
		share.review_id=review_id;
		FILE *fptr2 = fopen("shared_review_data.txt", "ab+");
			if(fptr2 == NULL)
			{
				printf("failed to open shared_reviews_data file\n");
				return;
			}
			fwrite(&share,sizeof(share_t),1,fptr2);
		    fclose(fptr2);
		    i++;
		    count++;
	}
	printf("Review shared with user(s) succesfully.\n");
	return;
}

//****************************************************************************

void display_review_shared_with_me(int id)
{
	review_t review;
	share_t share;
	FILE *fptr = fopen("shared_review_data.txt", "rb+");
		if(fptr == NULL)
		{
			printf("failed to open reviews file\n");
			return ;
		}
		printf("shared reviews:\n");
		while(fread(&share, sizeof(share_t), 1, fptr) != 0)
		{
			if(share.user_id==id)
			{
				FILE *fptr1 = fopen("reviews.txt", "rb+");
					if(fptr1 == NULL)
					{
						printf("failed to open reviews file\n");
						return ;
					}
					while(fread(&review, sizeof(review_t), 1, fptr1) != 0)
					{
						if(review.review_id == share.review_id)
						{
							printf("review_id =%-2d movie_Id =%-2d userId=%-2d review=%-15s rating=%-2d modified=%-20s",
								review.review_id,review.movie_id,review.user_id,review.review,review.rating,review.modified);
						}
					}
				fclose(fptr1);
			}		
		}
	fclose(fptr);
	return;
}
