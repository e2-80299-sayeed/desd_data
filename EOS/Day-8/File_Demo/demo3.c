

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    char exist[20];
    char newLink[20];
    printf("Enter orignal file : ");
    scanf("%s",exist);
    printf("Enter LinkFile file : ");
    scanf("%s",newLink);
 

    // Use the link system call to create a hard link
    if (link(exist, newLink) == -1) {
        perror("Error creating hard link");
        exit(EXIT_FAILURE);
    }

    printf("Hard link created successfully.\n");

    return 0;
}
