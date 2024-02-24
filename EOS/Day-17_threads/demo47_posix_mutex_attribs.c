#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t m; // declare mutex
int count = 0;

void* inc_count(void *param) {
    int i, ret;
    for(i=1; i<=10; i++) {
        ret = pthread_mutex_lock(&m); // lock mutex
        #ifdef DEBUG
        if(ret != 0) {
            perror("pthread_mutex_lock() failed");
            _exit(1);
        }
        #endif
        count++;
        printf("incr count: %d\n", count);
        ret = pthread_mutex_unlock(&m); // unlock mutex
        #ifdef DEBUG
        if(ret != 0) {
            perror("pthread_mutex_unlock() failed");
            _exit(1);
        }
        #endif
        //sleep(1);
    }
    return NULL;
}

void* dec_count(void *param) {
    int i, ret;
    for(i=1; i<=10; i++) {
        ret = pthread_mutex_lock(&m); // lock mutex
        #ifdef DEBUG
        if(ret != 0) {
            perror("pthread_mutex_lock() failed");
            _exit(1);
        }
        #endif

        count--;
        printf("decr count: %d\n", count);
        ret = pthread_mutex_unlock(&m); // unlock mutex
        #ifdef DEBUG
        if(ret != 0) {
            perror("pthread_mutex_lock() failed");
            _exit(1);
        }
        #endif

        //sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t it, dt;
    pthread_mutexattr_t ma;
    int ret;
    pthread_mutexattr_init(&ma); // init default mutex attrs
    pthread_mutexattr_setpshared(&ma, PTHREAD_PROCESS_PRIVATE); // default -- shared among threads of same process.
        // PTHREAD_PROCESS_SHARED -- shared among threads across the processes -- mutex must be in shared memory.
    #ifdef DEBUG
        pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_ERRORCHECK); 
        printf("Using ERRORCHECK mutex!\n");
    #else
        pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_NORMAL);
        printf("Using NORMAL mutex!\n");
    #endif
    pthread_mutex_init(&m, &ma); // init mutex
    ret = pthread_create(&it, NULL, inc_count, NULL);
    ret = pthread_create(&dt, NULL, dec_count, NULL);
    pthread_join(it, NULL);
    pthread_join(dt, NULL);
    printf("final count: %d\n", count);
    pthread_mutex_destroy(&m); // destroy mutex
    pthread_mutexattr_destroy(&ma);
    return 0;
}

// DEBUG build
//  cmd> gcc demo47_posix_mutex_attribs.c -DDEBUG -o demo.out -lpthread

// RELEASE build
//  cmd> gcc demo47_posix_mutex_attribs.c -o demo.out -lpthread

