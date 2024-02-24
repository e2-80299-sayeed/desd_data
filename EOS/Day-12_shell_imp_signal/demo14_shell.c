#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char *ptr, cmd[512], *args[32];
    int i, ret, err, s;
    while(1) {
        printf("cmd> ");
        gets(cmd); // e.g. ls -l -a /home
        
        i=0;
        ptr = strtok(cmd, " ");
        args[i] = ptr;
        i++;
        do {
            ptr = strtok(NULL, " ");
            args[i] = ptr;
            i++;
        } while(ptr != NULL);
	
	for(i = 0; args[i]!= NULL; i++)
	printf("%s\n",args[i]);	

        if(strcmp(args[0], "exit") == 0)
            _exit(0); // exit the shell program
        else if(strcmp(args[0], "cd") == 0)
            chdir(args[1]); // change the current directory of the shell program
        else { 
            // execute external command
            ret = fork();
            if(ret == 0) {
                err = execvp(args[0], args);
                if(err < 0) {
                    perror("bad command");
                    _exit(1);
                }
            }
            else
                waitpid(-1, &s, 0);
        }
    }
    return 0;
}
