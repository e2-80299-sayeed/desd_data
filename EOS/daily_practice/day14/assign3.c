// 3. Find the size of pipe buﬀer in your system.
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<fcntl.h>

int main ()
{
    int ret,fd[2],count = 0;
    char ch= 'a';
    ret = pipe(fd);
    if(ret < 0)
    {
        perror("pipe() failed !!\n");
        _exit(1);
    }   
   while(1)
   { 

    write(fd[1],&ch,sizeof(char));
    count++;
    printf("char = %c\nsize of pipe buffer = %d\n",ch,count);  
}
    return 0;
}