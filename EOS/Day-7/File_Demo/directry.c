#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

//Demo of print directory entry (inode and name)
//Use of opendir() , readdir(dp) , closedir(dp) 

int main()
{
    DIR *dp;
    struct dirent *ent;

    //Here we Open Directry
    dp = opendir("/home/kiran/Desktop/OS-Demo");
    if(dp == NULL)
    {
        //When opendir fails it return NULL
        perror("Directory does not exist");
        //Here we check Error
    }

    // read one by directry entry
    while( (ent = readdir(dp)) > 0 )
    {
        printf("Inode No : %u  User : %s \n",ent->d_ino,ent->d_name);
    }

    //Here close directry after reading entry
    closedir(dp);
    return 0;
}