#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
    // Error handeling
    if(argc != 2){
        printf("ERROR! requires user to input one arg\n");
        exit(1);
    }
    
    // Amount of Fibonacci numbers to print
    char *input = argv[1];
    
    pid_t pid;
    pid_t pidProducer = fork(); // Child process
    
    // Fork child process to execute Prod.C
    if(pidProducer == 0)
        execl("sh_p.out", "sh_p.out", input, NULL);
    // Wait for process to finish
    else if(pidProducer > 0){
        if((pid = wait(&status)) < 0){
            perror("Prod");
            exit(1);
        }
    }
    // Error handeling
    else if(pidProducer < 0){
        printf("Fork failed");
        exit(1);
    }
    
    
    pid_t pidConsumer = fork(); // Child process
    // Error handeling
    if(pidConsumer == 0)
        execl("sh_c.out", "sh_c.out", NULL, (char*) NULL);
    // Wait for process to finish
    else if(pidConsumer > 0){
        if((pid = wait(&status)) < 0){
            perror("Cons");
            exit(1);
        }
    }
    // Error handeling
    else if(pidConsumer < 0){
        printf("Fork failed");
        exit(1);
    }
    return 0;
}
