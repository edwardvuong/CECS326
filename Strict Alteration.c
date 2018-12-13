/**
    The C source code creates a race condition by which two threads read/write the variable count in a synchronized fashion by using strict alteration.  The count variable initially equals 5, thread1 increments count 3 times, thread2 decrements count 3 times.  The final value of count should equal the initial value of count.
 

The given program so that it accepts one command line argument.  The command line argument will be converted to integer and used as a random number seed
 
The threads each sleep for a random amount of time between 0 and 3 seconds inside their respective critical sections
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <pthread.h>
#include <stdlib.h>

int count; // Shared resouce
int turn = 1; // Strict alteration
int thread1Sleep; // Random sleep time for thread 1
int thread2Sleep; // Random sleep time for thread 2

void *thread1(void *param){
    char i, tmp;
    for(i = 0; i < 3; i++){
        // Entry section
        while(turn != 1); // Strict alteration
        printf("    1st thread Entry%d to critical section, count = %d\n", i+1, count);
        // Begin critical section
        tmp = count;
        sleep(thread1Sleep);
        printf("    1st thread sleeping for %d\n", thread1Sleep);
        count = tmp + 1;
        // End critical section
        printf("    1st thread Exit#%d from critical section, count = %d\n", i+1, count);
        turn = 2; // Strict alteration
    }
    pthread_exit(0);
}

void *thread2(void *param){
    char i, tmp;
    for(i = 0; i < 3; i++){
        // Entry section
        while(turn != 2); // Strict alteration
        printf("    2nd thread Entry%d to critical section, count = %d\n", i+1, count);
        // Begin critical section
        tmp = count;
        sleep(thread2Sleep);
        printf("    2nd thread sleeping for %d\n", thread2Sleep);
        count = tmp - 1;
        // End critical section
        printf("    2nd thread Exit#%d from critical section, count = %d\n", i+1, count);
        turn = 1; // Strict alteration
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]){
    // Error handeling
    if(argc < 2){
        printf("Error: Needs one argument.\n");
        exit(1);
    }
    // Random sleep times using stdin input as random seed
    srand(atoi(argv[1]));
    thread1Sleep = rand() % 4;
    thread2Sleep = rand() % 4;
    printf("Generating random sleep times with seed %d\n",atoi(argv[1]));
    printf("1st thread sleep = %d\n",thread1Sleep);
    printf("2nd thread sleep = %d\n",thread2Sleep);
    // Random amount of count trials
    count = 5 + thread1Sleep - thread2Sleep;
    printf("Initial value of count = %d\n\n", count);
    //
    pthread_t tid1, tid2;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    // Two threads that run simatamiously
    pthread_create(&tid1, &attr, thread1, NULL);
    pthread_create(&tid2, &attr, thread2, NULL);
    // Terminate the concurrent threads
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("\nAfter threads complete, count = %d\n", count);
    exit(0);
}


