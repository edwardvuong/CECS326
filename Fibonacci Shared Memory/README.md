# Fibonacci Sequence in Shared Memory

## Part 1:
Due: October 16, 2018</br>

The Fibonacci sequence is a series of numbers where a number is found by adding up the two numbers before it. Starting with `1` and `1`, the sequence goes `1, 1, 2, 3, 5, 8, 13, 21, 34,` and so forth. 
Written as a rule, the expression is `xn = xn-1 + xn-2`.

Create a C program to:

1. Produce the FIbonacci sequence following the producer-consumer mode of operation.  Establish a shared-memory object named "Fibonacci" which will allow the producer to write the contents of the sequence to the shared-memory object. 
2. Create the producer program so that it receives one command line argument which specifies the amount of numbers to generate in the sequence. 
3. The consumer program can then be executed to read the contents of shared memory and output the sequence to the console.

The consumer source code is given `cons.c`. You must make the producer!

The folder  `Example Executables` includes executable files that show how your programs should work. 

## Part 2:
Due: October 25, 2018</br>

Use `fork()` and `wait()` system calls to call the child program created in **Part 1**.

Create a C program where:

1. Receive one command line argument which determines the amount of Fibonacci numbers to generate and print
2. exit program with `code 1` if an incorrect number of arguments is used.
3. Fork a child process which will execute the fibonacci sequence producer program named `sh_p.out` and pass the command line argument received by this parent program.
4. Wait until the producer program has completed.
5. Fork a child process which will execute the consumer program named `sh_c.out`
6. Wait until the consumer program has finished.
7. Exit with `code 0`.
8. Waiting for a child process can be accomplished using the following instruction `wait(&status)`
⋅⋅⋅*status is a signed integer*

Include error checking in your program as well. i.e. if `fork()` or `wait()` return -1 then the operation failed and your program should exit after displaying an error message

The folder  `Example Executables` includes executable files that show how your programs should work. 

Write your program to launch the programs:
`sh_c.out` the shared memory consumer
`sh_p.out` the shared memory producer of Fibonacci numbers
