/*
Write a program that compiles above multi-ﬁle project. It runs commands "gcc -c circle.c", "gcc -c square.c", "gcc -c rectangle.c", "gcc -c main.c"
concurrently.
parent
|- child1 (gcc -c circle.c)
|- child2 (gcc -c square.c)
|- child3 (gcc -c rectangle.c)
|- child4 (gcc -c main.c)
wait for all child and check exit status. If all exit status 0 (success), then link
|- child5 (gcc -o program.out circle.o square.o rectangle.o main.o)
wait for child and check exit status. If all exit status 0 (success), then run it.
|- child6 (./program.out)
wait for child and check exit status. Then print child exit status.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>

int main()
{
    int pid1, pid2, pid3,pid4, pid5, pid6,pid7,err,
    s1, s2,s3,s4,s5,s6,s7;
    pid1 = fork();
    if(pid1 == 0)
    {   // child 1
        char *cmd[] = {"gcc","-c","circle.c",NULL };
        err=execvp(cmd[0], cmd);
    
        if(err <0 )
        { 
            perror("bad command\n");
            _exit(0);                
        }
        _exit(0);
    }        
    

    pid2 = fork();
    if(pid2 == 0)
    {
        //child 2
        char *cmd[] = {"gcc","-c","square.c",NULL };
        err= execvp(cmd[0], cmd);
    
        if(err < 0)
        {
            perror("bad command\n");
            _exit(0);
        }
        _exit(0);
    } 
    
    pid3 = fork();
    if(pid3 == 0)
    {
        //child 3
        char *cmd[] = {"gcc","-c","rectangle.c",NULL};
        err= execvp(cmd[0],cmd);
        
        if(err < 0)
        {
            perror("bad command\n");
            _exit(0);
        }
        _exit(0); 
    }
    
    pid4 = fork();
    if(pid4 == 0)
    {
        //child 4
        char *cmd[] = {"gcc","-c","main.c",NULL};
        err= execvp(cmd[0],cmd);
        
        if(err < 0)
        {
            perror("bad command\n");
            _exit(0);
        } 
        _exit(0);
    }

    waitpid(pid1, &s1 ,0);
    s1  = WEXITSTATUS(s1);
    //printf("child 1 exit status: %d\n",s1);
    
    waitpid(pid2, &s2 ,0);
    s2  = WEXITSTATUS(s2);

    waitpid(pid3, &s3 ,0);
    s3 = WEXITSTATUS(s3);
    
    waitpid(pid4, &s4 ,0);
    s4  = WEXITSTATUS(s4);

    if(s1==0 && s2==0 && s3 == 0 && s4 == 0)
    {
        pid5 = fork();
        if(pid5 == 0)
        {
        //child 5
        char *cmd[] = {"gcc","-o","program.out","main.o","circle.o","rectangle.o","square.o",NULL};
        err= execvp(cmd[0],cmd);
        if(err < 0)
        {
            perror("bad command\n");
            _exit(0);
        }
        _exit(0);
        }
    }
    waitpid(pid5, &s5 ,0);
    s5  = WEXITSTATUS(s5);

    if(s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0)
    {
        pid6 = fork();
        if(pid6 == 0)
        {
        //child 6
        char *cmd[] = {"./program.out",NULL};
        err= execv("/home/sayeed/DESD/EOS/daily_practice/day12/assign4/program.out",cmd);
        if(err < 0)
        {
            perror("bad command\n");
            _exit(0);
        }
        _exit(0);
        }
    }

    waitpid(pid6, &s6 ,0);
    s6  = WEXITSTATUS(s6);
    printf("child 6 exit status: %d\n",s6);
    
    
    
    /*if(s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 0)
    {
        pid7 = fork();
        if(pid7 == 0)
        {
        //child 7
        char *cmd[] = {"rm","program.out",NULL};
        err= execvp(cmd[0],cmd);
        if(err < 0)
        {
            perror("bad command\n");
            _exit(0);
        }
        _exit(0);
        }
    }
    waitpid(pid7, &s7 ,0);
    s7  = WEXITSTATUS(s7);
    */
    return 0;
}

