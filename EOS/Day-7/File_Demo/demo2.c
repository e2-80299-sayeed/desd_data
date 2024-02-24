#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Soft-Link Demo

int main() 
{
    char orig[20];
    char link[20];
    printf("Enter orignal file : ");
    scanf("%s",orig); //Targeted file path
    printf("Enter LinkFile file : ");
    scanf("%s",link); // set to target
    

    // Creating a symbolic link
    if (symlink(orig, link) != 0) 
    {
        perror("symlink");
        exit(EXIT_FAILURE);
    }

    printf("Symbolic link created: %s -> %s\n", orig, link);

    return 0;
}
