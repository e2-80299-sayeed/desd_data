#include<stdio.h>
#include<unistd.h>

/*
stdin = standard input  -->scanf()/gets()
STDIN_FILENO = 0 (#defined)
stdout = standard output <-- printf()/puts()
STDOUT_FILENO = 1 (#defined)
stderr = standard out <--- _exit(0)/perror()
STDOUT_FILENO = 2 (#defined)
*/

/*
ret = write(fd , buffer , size);
    arg1 : file descripter of the file write in
    arg2 : base addres of the data buffer to write
    arg3 : number of bytes to write in the file
    returns : number of bytes sucessfully written
*/

int main()
{
    int count;
    count = write(STDOUT_FILENO,"Hello\n",6);
    //return count;
    printf("%d\n",count);
    return 0;
}
//terminal> gcc demo.c -o demo.out
//terminal> ./demo.out
//treminal> echo "$?"

/*
On linux shell, the exit value of the last executed program can be
accessed using $?
To print that value , use command "echo $?"
*/
