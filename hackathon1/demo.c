#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

typedef struct user{
	int user_id;
	char f_name[20];
	char l_name[20];
	char mob_no[12];
	char email[20];
	char pass[20];
}user_t;

typedef struct quote{
		char text[10];
		int my_id;
		int q_id;
		char  author[20];
		int like_unlike;
		int fav_quote;
}q_t;

q_t q[20];

int u_id = 0;
int quote_id = 0;

void sign_in(user_t *user);
void sign_up(user_t *user);
void logged_in(user_t *u, int temp_id);
void edit_quote(int id);
void q_file_write(q_t *q, int qid);
void new_quote(user_t *u, int id);
void q_file_read(q_t *q);
void all_quote();
void my_quote(int id);
void like_unlike_quote(int id);
void my_fav_quote(int id);
void del_quote(int id);
void edit_profile(int id);
void change_pass(user_t *user,int id);
int main(void)
{
	int choice;
	user_t user[20];
	
	do
	{
		printf("0.Exit\n1.Sign Ip\n2.Sign Up\n");
		printf("Enter choice:	");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
					sign_in(user);
				break;

			case 2:
					sign_up(user);
				break;

			default:
					printf("Invalid choice....(:");
				break;
		}

	}while(choice != 0);

	return 0;
}

void sign_in(user_t *user)
{
	char email[20];
	char pass[20];
	printf("Enter Email:	");
	scanf("%*c%[^\n]s",email);
	printf("Enter Password:	");
	scanf("%*c%[^\n]s",pass);
	
	user_t temp;
	int temp_id;
	
	FILE *fptr = fopen("user_data.txt", "a+");
	if(fptr == NULL)
	{
		perror("failed to open user data file\n");
		exit(1);
	}

	while(fread(&temp, sizeof(user_t), 1, fptr) != 0)
	{
	//	printf("email:%s\npasas:%s\n",temp.email, temp.pass);
		if((strcmp(temp.email, email) ==0 && strcmp(temp.pass, pass)==0))
		{
			temp_id = temp.user_id ;	//get id of match user
		printf("matched id = %d\n", temp_id);
			logged_in(user, temp_id);		//user id passing
			return;
		}
	}
	printf("user not found....:(");
}

void sign_up(user_t *user)
{
	printf("Enter First name:	");
	scanf("%*c%[^\n]s",user[u_id].f_name);
	printf("Enter Last name:	");
	scanf("%*c%[^\n]s",user[u_id].l_name);
	printf("Enter Mobile:	");
	scanf("%*c%[^\n]s",user[u_id].mob_no);
	printf("Enter Email:	");
	scanf("%*c%[^\n]s",user[u_id].email);
	printf("Enter Password:	");
	scanf("%*c%[^\n]s",user[u_id].pass);
	
	user[u_id].user_id = u_id;	//id assign

	user_t temp = user[u_id];	//temp variable to write into file
	FILE *fptr = fopen("user_data.txt", "a+");
	if(fptr == NULL){
		perror("failed to open user data file\n");
	exit(1);
	}

	fwrite(&temp, sizeof(user_t), 1, fptr);
	
	fread(&temp, sizeof(user_t), 1, fptr);
/*
	printf("Enter First name:	%s\n",temp.f_name);
	printf("Enter Last name:	%s\n",temp.l_name);
	printf("Enter Mobile:	%s\n",temp.mob_no);
	printf("Enter Email:	%s\n",temp.email);
	printf("Enter Password:	%s\n",temp.pass);
*/
	fclose(fptr);
	u_id++;
		//main id increment
}

void logged_in(user_t *user, int id)
{
	int choice;
	do
	{
		printf("0.Sign out\n1.All Quotes\n2.My Quotes\n3/My Favorite Quote\n4.Like/Unlike\n5.New Quote\n6.Edit Quote\n7.Delete Quote\n8.Change Password\n9.Edit Profile\n");
		printf("Enter choice:	");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1:
				all_quote();
				break;
			case 2:
				my_quote(id);
				break;
			case 3:
				my_fav_quote(id);
				break;
			case 4:
				like_unlike_quote(id);
				break;
			case 5:
				new_quote(user, id);
				break;
			case 6:
				edit_quote(id);
				break;
			case 7:
				del_quote(id);
				break;
			case 8:
				change_pass(user, id);
				break;
			case 9:
				edit_profile(id);
			default:
				return;
		}

	}while(choice != 0);
}