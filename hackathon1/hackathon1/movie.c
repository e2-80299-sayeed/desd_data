#include"main.h"


void display_all_movies()
{
    movie_t movies[10] = {{1, "Avatar", "21-02-2009"},{2, "Titanic", "09-08-1997"},{3, "Frozen", "24-07-2013"},{4, "The Lord of the Rings", "12-03-2003"},{5, "Skyfall", "26-12-2012"},{6, "Toy story", "19-07-2010"},{7, "Jurassic park", "16-06-1993"}, {8, "Alice in the Wonderland", "04-03-2010"},{9, "Zootopia", "11-04-2016"},{10, "The dark Night", "16-12-2008"}};
    for(int i = 0; i < 10 ; i ++ )
    {
        printf("[Movie ID : %d,  Title : %s,  Release : %s]\n",movies[i].id,movies[i].title,movies[i].release);
    }
    printf("\n");
}
