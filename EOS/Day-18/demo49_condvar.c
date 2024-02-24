#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t m;
pthread_cond_t c;
int sunbeam_printed = 0;

void* sunbeam(void* ptr) {
    char *str = "SUNBEAM \n";
    int i;
    pthread_mutex_lock(&m);
    for(i=0; str[i]!='\0'; i++) {
        putchar(str[i]);
        fflush(stdout);
        sleep(1);
    }
    // cond signal
    sunbeam_printed = 1;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
    // further work
    return NULL;
}

void* infotech(void* ptr) {
    char *str = "INFOTECH!\n";
    int i;
    pthread_mutex_lock(&m);
    // cond wait
    while(!sunbeam_printed)
        pthread_cond_wait(&c, &m);
    for(i=0; str[i]!='\0'; i++) {
        putchar(str[i]);
        fflush(stdout);
        sleep(1);
    }
    pthread_mutex_unlock(&m);
    return NULL;
}

int main() {
    pthread_t st, it;
    pthread_mutex_init(&m, NULL);
    pthread_cond_init(&c, NULL);
    pthread_create(&st, NULL, sunbeam, NULL);
    pthread_create(&it, NULL, infotech, NULL);
    pthread_join(st, NULL);
    pthread_join(it, NULL);
    pthread_cond_destroy(&c);
    pthread_mutex_destroy(&m);
    printf("bye!\n");
    return 0;
}







