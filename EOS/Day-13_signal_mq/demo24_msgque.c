#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define MQ_KEY 0x00001234

void strupr(char *s) {
    while(*s) {
        *s = (*s >= 'a' && *s <= 'z' ? (*s - 32) : *s);
        s++;
    }
}

typedef struct msg {
    long type;
    char str[32];
} msg_t;

int main() {
    int ret, s, mqid;
    // create message queue
    mqid = msgget(MQ_KEY, IPC_CREAT|0600);
    if(mqid < 0) {
        perror("msgget() failed");
        _exit(1);
    }
    ret = fork();
    if(ret == 0) {
        // child process -- receiver
        msg_t m2;
        printf("\nchild: waiting for data from parent...\n");
        // wait and then receive data from parent.
        msgrcv(mqid, &m2, sizeof(m2.str), 99, 0);
        printf("child: received - %s\n", m2.str);

        strupr(m2.str);
        m2.type = 33;
        msgsnd(mqid, &m2, sizeof(m2.str), 0);
    }
    else {
        // parent process -- sender
        msg_t m1;
        printf("parent: enter a string: ");
        scanf("%s", m1.str);
        m1.type = 99;
        // send the data to the child
        msgsnd(mqid, &m1, sizeof(m1.str), 0);

        msgrcv(mqid, &m1, sizeof(m1.str), 33, 0);
        printf("parent: received - %s\n", m1.str);

        waitpid(-1, &s, 0);
        // destroy the message queue
        msgctl(mqid, IPC_RMID, NULL);
    }
    return 0;
}
