#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
// one parent and three child processes.
int main() {
    int i, pid[5],s;

    printf("program started!!\n");

    for(i=1; i<=5; i++)
    {   
        pid[i]=fork();
        if(pid[i] == 0)
        {
            for(int cnt=1; cnt<=5; cnt++)
            {
                printf("child: %d   pid: %d count : %d\n ",i,getpid(),cnt);
                sleep(1);
            }
            _exit(2);
        }
        
    }

    
            for(int k=1; k<=10;k++)
            {
                printf("parent: %d\n",k);
                sleep(1);
                if(k == 5)
                {
                    wait(&s);
                    printf("parent: child's exit status :%d\n",WEXITSTATUS(s));

                }
            }
        
    
    printf("program completed!\n");


    /*pid1 = fork();
    if(pid1 == 0) { // first child
        for(i=1; i<=3; i++) {
            printf("dac: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }

    pid2 = fork();
    if(pid2 == 0) { // second child
        for(i=1; i<=3; i++) {
            printf("dmc: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }

    pid3 = fork();
    if(pid3 == 0) { // third child
        for(i=1; i<=3; i++) {
            printf("desd: %d\n", i);
            sleep(1);
        }
        _exit(0);
    }

    for(i=1; i<=5; i++) {
        printf("sunbeam: %d\n", i);
        sleep(1);
    }

    waitpid(pid1, &s1, 0);
    waitpid(pid2, &s2, 0);
    waitpid(pid3, &s3, 0);
*/
    return 0;
}



