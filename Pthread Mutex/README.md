# Pthread Mutex
Due: November 15, 2018</br>

Race conditions can occur whenever mutiple threads or processes are accessing the same resource.

Standard output can be considered a shared resource and if multiple threads/processes are writing to standard output concurrently without synchonization then garbled messages may be produced.

This lab demonstrates such a scenario where multiple threads are writing to standard output with artificially inserted delays.

The thread function with artificial delay is shown below:
```c
void *runner(void *ptr){
    int i, threadNum = *((int *)ptr); 
    char buffer[30]; 
    struct timespec delay, left;
    
    sprintf(buffer, "Hello from threadfld with tid %ld\n", threadNum, syscall( NR_gettid)); 
    delay.tv_sec = 0;
    
    for(i = 0; i < strlen(buffer); i++){ 
        printf("%c",buffer[i]); 
        delay.tv_nsec = rand()%90000; 
        nanosleep(&delay,&left);
    } 
    pthread_exit(0);
}
```

Main function is shown below:
```c
int main(int argc, char *argv[]){
    if (argc != 2){ 
        printf("Incorrect number of arguments entered\n"); 
        exit(1);
    } 
    numThreads = atoi(argv[1]); 
    if(numThreads < 2 || numThreads > MAX){
        printf("Between 2 and %d threads should be created\n", MAX);
        exit(1); 
    } 
    int i; 
    pthread_t threads[numThreads]; 
    pthread_attr_t attr; 
    pthread_attr_init(&atts);
    
    for(i = 0; i < numThreads; i++)
        pthread_create(&threads[i], &attr, runner, &i);
    
    for(int i = 0; i < numThreads; i++)pthreadjoin(threads[i], NULL);
        printf("END OF PROGRAM\n");
```

The folder  `Example Executables` includes executable files that show how your programs should work. 

Assignment:
1. Determine the library files that must be included in your program as well
2. Fix any syntax errors in the example program
3. Use the given portions of code to create a program that works like the executable named `RacePrint.out`.
4. Use a pthread mutex to ensure that only one process writes to the console at a time.  The goal of this lab is to use pthread mutex to create an executable that works like `MutexPrintSOLUTION.out`
