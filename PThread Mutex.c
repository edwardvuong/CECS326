/**
 
 Race conditions can occur whenever mutiple threads or processes are accessing the same resource.
 
 Standard output can be considered a shared resource and if multiple threads/processes are writing to standard output concurrently without synchonization then garbled messages may be produced.
 
 This lab demonstrates such a scenario where multiple threads are writing to standard output with artificially inserted delays.  The thread function with artificial delay is shown below:
 
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>

pthread_mutex_t mutex;
void *runner(void *ptr){
    pthread_mutex_lock(&mutex);
    int i, threadNum = *((int*) ptr);
    char buffer[100];
    struct timespec delay, left;
    
    sprintf(buffer, "Hello from thread#%d with tid %ld\n", threadNum, syscall(__NR_gettid));
    delay.tv_sec = 0;
    
    for(i = 0; i < strlen(buffer); i++){
        printf("%c", buffer[i]);
        delay.tv_nsec = rand()%90000;
        nanosleep(&delay, &left);
    }
    
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Incorrect number of arguments entered\n");
        exit(1);
    }
    int numThreads = atoi(argv[1]);
    int MAX = 10;
    if(numThreads < 2 || numThreads > MAX){
        printf("Between 2 and %d threads should be created\n", MAX);
        exit(1);
    }
    int i;
    pthread_t threads[numThreads];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    for (i = 0; i < numThreads; i++)
        pthread_create(&threads[i], &attr, runner, &i);
    
    for (int i = 0; i < numThreads; i++)
        pthread_join(threads[i], NULL);
    
    pthread_mutex_init(&mutex, 0);
    pthread_mutex_destroy(&mutex);
    
    printf("END OF PROGRAM\n");
    exit(0);
}

