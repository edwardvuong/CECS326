# Strict Alternation
Due: November 13, 2018</br>

The given C source code creates a race condition by which two threads read/write the variable count in an unsynchronized fashion.  
+ The count variable initially equals `5`, thread1 increments count `3` times, thread2 decrements count `3` times.  
+ The final value of count "should" equal the initial value of count but the race condition causes data corruption:

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
#include <pthread.h>
#include <stdlib.h>

int count; // Shared resouce

void *thread1(void *param){
    //Thread 1 is "fast" and increments count
    char i, tmp;
    for(i = 0; i < 3; i++){
    // Entry section:

    printf("1st thread Entry%d to critical section, count = %d\n", i+1, count);
    // Begin critical section
    tmp = count;
    sleep(1);
    count = tmp + 1;
    // End critical section
    printf("1st thread Exit#%d from critical section, count = %d\n", i+1, count);
    
    //Exit section:
    }
    pthread_exit(0);
}

void *thread2(void *param){
    char i, tmp;
    for(i = 0; i < 3; i++){
    // Entry section
    
    printf("2nd thread Entry%d to critical section, count = %d\n", i+1, count);
    // Begin critical section
    tmp = count;
    sleep(thread2Sleep);
    printf("2nd thread sleeping for %d\n", thread2Sleep);
    count = tmp - 1;
    // End critical section
    printf("2nd thread Exit#%d from critical section, count = %d\n", i+1, count);
    turn = 1; // Strict alteration
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]){
count = 5;
printf("Initial value of count = %d\n", count);
pthread_t tid1, tid2;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&tid1, &attr, thread1, NULL);
pthread_create(&tid2, &attr, thread2, NULL);
pthread_join(tid1, NULL);
pthread_join(tid2, NULL);
printf("\nAfter threads complete, count = %d\n", count);
exit(0);
}

```

Part 0
---
+ Compile the given source code, run and observe the results.
+ What do you notice about the way that the threads access the count variable concurrently? 
+ With the understanding that thread1 increments count 3 times and thread2 decrements count 3 times, after the threads complete, is the value of count correct?

Part 1
---
+ Make the following set of modifications to the program given in Part0:
+ Modify the given program so that it accepts one command line argument.  The command line argument will be converted to integer and used as a random number seed
+ Modify the threads so that they each sleep for a random amount of time between 0 and 3 seconds inside their respective critical sections

Part 2
---
+ Use strict alternation to fix the race condition
+ For your reference, sample 32-bit OS and 64-bit OS executables are attached to this dropbox.  The program you make should work exactly like these attached executables.
