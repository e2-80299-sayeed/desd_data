#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct shares{
    int review_id;
    int user_id;
}share_t;

typedef struct user{
	share_t id;
	char f_name[20];
	char l_name[20];
	char birthdate[15];
	char email[20];
	char pass[20];
}user_t;

typedef struct reviews{
		share_t id;
		int movie_id;
		int rating;
		char review[20];
		char modified[30];
}review_t;

typedef struct movies{
    int id;
    char title[50];
    char relese[15];
}moives_t;

void sign_in();
void sign_up();
void logged_in(int U_id,char email[20],char pass[20]);
void edit_profile(int u_id,char email[20]);
void change_pass(char email[20],char pass[20]);
void display_movies();
void create_review(int u_id);
void edit_review(int u_id);
void delete_review(int u_id);
void display_all_review();
void display_my_review(int u_id);
void display_review_shared_with_me(int u_id);
void share_review(int u_id);
int all_user();