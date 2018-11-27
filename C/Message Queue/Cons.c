/**
*
* Cons.C sets up the queue with the following key:
*                ftok(".", 'Z')
* and displays characters that are sent by the producer
* where the message type is 100 removing the queue and
* exiting once a lowercase q or uppercase Q is received
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
    // Create a message queue to be shared between Prod.C
    int qid = msgget(ftok(".", 'Z'), IPC_EXCL | IPC_CREAT | 0666);
    //Error handeling
    if(qid < 0){
        printf("Error creating shared message queue.\n");
        exit(1);
    }
    printf("Message queue created.\n");
    // Message struct
    struct buf{
        long mtype; // Message type
        char msgBuffer[50]; // Message content
    };
    struct buf msg; // Initilize an instance of buffer
    const int SIZE = sizeof(msg) - sizeof(long); // Message size
    // Infinite loop to send messages though the queue
    do {
        // Send message using message queue
        msgrcv(qid, (struct msgbuf *)&msg, SIZE, 100, 0);
        printf("%s", msg.msgBuffer);
    } while (msg.msgBuffer[0] != 'q' || msg.msgBuffer[0] == 'Q'); // Break loop

    // Delete the message queue
    msgctl(qid, IPC_RMID, NULL);
    exit(0);
}
