#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MSG_KEY 0x00001235


typedef struct msg_Q
{
    long type;
    char name[10];
    int rollno;
}msg_t;

typedef struct msgq_path
{
    long type;
    char path[100];
}msg_path_t;


int main()
{
    int ret, s,fd[2],msg_id;

    msg_id = msgget(MSG_KEY, IPC_CREAT | 0777);
    if(msg_id < 0)
    {
        perror("msgget() failed!!");
        _exit(1);
    }

     ret = pipe(fd);
     if(ret < 0)
     {
         perror("pipe() failed!!");
         _exit(1);
    }


    ret = fork();
    if(ret == 0)
    {//child
        msg_t m1;
        msg_path_t msg_path;
        struct stat sb;
        printf("Enter name : ");
        scanf("%s",m1.name);

        printf("Enter rollno: ");
        scanf("%d",&m1.rollno);

        m1.type = 99;

        ret = msgsnd(msg_id,&m1,sizeof(msg_t),0);
        if(ret < 0)
    {
        perror("msgsnd() failed!!");
        _exit(1);
    }
        sleep(2);
        printf("Enter file path : ");
        scanf("%s",msg_path.path);


        msg_path.type = 33;
        ret = msgsnd(msg_id,&msg_path,sizeof(msg_path_t),0);
        if(ret < 0)
    {
        perror("msgsnd() failed!!");
        _exit(1);
    }

    close(fd[1]);
    read(fd[0],&sb,sizeof(sb));
    
    printf("I-node number:            %lu\n", sb.st_ino);
    printf("Mode:                     %o (octal)\n",sb.st_mode);
    printf("Link count:               %lu\n", sb.st_nlink);
    printf("Ownership:                UID=%u   GID=%u\n", sb.st_uid, sb.st_gid);
    printf("Preferred I/O block size: %lu bytes\n",sb.st_blksize);
    printf("File size:                %lu bytes\n",sb.st_size);
    printf("Blocks allocated:         %lu\n",sb.st_blocks);
    
    close(fd[0]);
    
    }

    else
    { 
    //parent
    msg_t m2;
    msg_path_t  msg_path1;
    struct stat sb;

    ret = msgrcv(msg_id, &m2,sizeof(m2),99,0);    
    if(ret < 0)
    {
        perror("msgrcv() failed!!");
        _exit(1);
    }
    
    printf("Name : %s and rollno: %d\n", m2.name, m2.rollno);
    
    ret = msgrcv(msg_id, &msg_path1,sizeof(msg_path_t),33,0);    
    if(ret < 0)
    {
        perror("msgrcv() failed!!");
        _exit(1);
    }
    printf("Path : %s\n",msg_path1.path);
    
	

    ret = stat(msg_path1.path,&sb);

    close(fd[0]);
    write(fd[1],&sb,sizeof(sb));
    close(fd[1]);

    waitpid(ret,&s,0);
    msgctl(msg_id,IPC_RMID,NULL);
   
    } 
           
    return 0;
}
