#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>

typedef struct user
{
    int user_id;
    char f_name[20];
    char l_name[20];
    char mob_no[12];
    char email[20];
    char pass[20];
    char dob[20];
}user_t;

typedef struct movie
{
    int id;
    char title[50];
    char release[30];
}movie_t;

typedef struct review
{
    int review_id;
    int rating;
    char review[100];
    int movie_id;
    int user_id;
    char modified[25];
}review_t;

typedef struct share{
    int review_id;
    int user_id;
}share_t;


void sign_up(user_t *user);
void sign_in(user_t *user);
void logged_in(user_t *u,int temp_id);

void edit_profile(user_t *user);
int display_profiles(int id);
void display_profile(int id);
void change_pass(user_t *user,int id);
void display_all_movies();
void write_a_review(int id);
void display_all_reviews(review_t review);
void display_my_reviews(int id);
void edit_review(int id);
void delete_review(int id);
void share_review(int id);
void display_review_shared_with_me(int id);