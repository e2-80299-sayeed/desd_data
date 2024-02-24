#include <stdio.h>
#include <unistd.h>

//unlink -syscall demo (rm command)
// detelete file using unlinc syscall

int main() {
    
    char filename[30];
    printf("Enter file to be delete : ");
    scanf("%s",filename); //file name to delete
    
    // Unlink the file
    if (unlink(filename) == 0) //unlink return 0 after success
    {
        printf("File unlinked successfully.\n");
    } else {
        perror("Error unlinking file");
        return 1;
    }

    return 0;
}
