#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main()
{
    DIR *dp;
    struct dirent *ent;
    dp = opendir("/home/kiran/Desktop/OS-Demo");
    if(dp == NULL)
    {
        perror("Directory does not exist");
    }

    while( (ent = readdir(dp)) > 0 )
    {
        printf("Inode No : %u  User : %s \n",ent->d_ino,ent->d_name);
    }

    closedir(dp);
    return 0;
}