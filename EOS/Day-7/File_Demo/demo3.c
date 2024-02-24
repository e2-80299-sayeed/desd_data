
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Hard link Demo
int main() 
{
    char exist[20];
    char newLink[20];
    printf("Enter orignal file : ");
    scanf("%s",exist); //Targeted file path
    printf("Enter LinkFile file : ");
    scanf("%s",newLink);// set to target
 

    // Use the link system call to create a hard link
    if (link(exist, newLink) == -1) {
        perror("Error creating hard link");
        exit(EXIT_FAILURE);
    }

    printf("Hard link created successfully.\n");

    return 0;
}
