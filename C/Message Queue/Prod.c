/**
*
* Prod.c accesses the queue created by the consumer
* then prompts the user to input one keyboard character
* at a time followed by the enter key then sends the keyboard
* character to the consumer process via message queue
* Once a lowercase q or uppercase Q is received, producer sends
* the q or Q to the consumer and then producer program terminates
*
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    //Access the queue created by Cons.C
    int qid = msgget(ftok(".", 'Z'), 0);
    //Error handeling
    if(qid < 0){
        printf("Error accessing queue.\n");
        exit(1);
    }
    printf("Message queue accessed.\n");
    // Message struct
    struct buf{
        long mtype; // Message type
        char msgBuffer[50]; // Message content
    };
    struct buf msg; // Initilize an instance of buffer
    int size = sizeof(msg) - sizeof(long); // Message size 
    char c; // Character to hold a single input character
    // Loop program taking infinite amount of input
    while(qid > 0){
        // Obtain character to send from stdin
        c = getchar();
        printf("\nEnter a character.\nEnter q or Q to quit.\nCharater: ");
        // Add the character to the message buffer
        sprintf(msg.msgBuffer, "%c", c);
        // Assign message type to 100
        msg.mtype = 100;
        // Send message
        msgsnd(qid, (struct msgbuf *)&msg, size, 0);
        // Break loop
        if (c == 'q' || c == 'Q')
            break;
    }
    exit(0);
}
