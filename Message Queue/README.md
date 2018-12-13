# Message Queue
Due: November 8, 2018</br>

Create a pair of programs following the producer / consumer model to pass messages between each other using a message queue.

The consumer program will be responsible for:
+ Setting up the queue with the following key: `ftok(".", 'Z')`
+ Displaying characters that are sent by the producer where the message type is `100`
+ Removing the queue and exiting once a lowercase `q` or uppercase `Q` is received

The producer will:
+ Access the queue created by the consumer
+ Prompt the user to input one keyboard character at a time followed by the enter key
+ Send the keyboard character to the consumer process via message queue
+ Once a lowercase `q` or uppercase `Q` is received, producer sends the `q` or `Q`to the consumer and then producer program terminates
    
Also implement error handling in the producer and consumer programs to account for the possibility of the queue creation failing for reasons specified in the man pages of the msgget function

The folder  `Example Executables` includes executable files that show how your programs should work. 
1. Run the consumer program in one window terminal and then run the producer program in another terminal window.
2. In the terminal window that is the producer program, type keyboard characters and they will be sent to the terminal window running the consumer program.
