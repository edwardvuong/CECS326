/**
 * Write a C program that will launch the programs from the
 * Fibonacci Sequence from Cons.C and Prod.C
 *
 * This is accomplished with the use of fork() and wait()
 * system calls.
 *
 * Here is a general list of what the program (parent program)
 * you write in this lab should do:
 *
 * Receive one command line argument which determines the amount
 * of Fibonacci numbers to generate and print
 *
 * Exit program with code 1 if an incorrect number of arguments is used
 *
 * Fork a child process which will execute the fibonacci sequence
 * producer program named sh_p.out and pass the command line argument
 * received by this parent program
 *
 * wait until the producer program has completed
 *
 * fork a child process which will execute the consumer program named sh_c.out
 *
 * wait until the consumer program has finished
 *
 * exit with code 0
 *
 * waiting for a child process can be accomplished using the following instruction
 *
 * wait(&status)
 *
 * where status is a signed integer
 *
 * Include error checking in your program as well. i.e. if fork() or wait() return -1
 * then the operation failed and your program should exit after displaying an error message
 */


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
	int status;
	
	pid_t pid;
	pid_t pidProducer = fork(); // Child process
	
    // Fork child process to execute Prod.C
	if(pidProducer == 0)
		int success = execl("sh_p.out", "sh_p.out", input, NULL);
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


