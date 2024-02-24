#include <stdio.h>
#include <unistd.h>

//unlink -syscall demo (rm command)

int main() {
    
    char filename[30];
    printf("Enter file to be delete : ");
    scanf("%s",filename);
    
    // Unlink the file
    if (unlink(filename) == 0) {
        printf("File unlinked successfully.\n");
    } else {
        perror("Error unlinking file");
        return 1;
    }

    return 0;
}
