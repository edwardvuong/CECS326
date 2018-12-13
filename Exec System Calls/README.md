# System Calls
Due: October 4, 2018</br>

Enter the bash command info exec for complete documentation of exec.  

*There are 6 variants of the exec system call.*

Syscall Name | Argument | Pass Environment Variables | Search Path
--- | --- | --- | ---
execl | list | yes | no
execv | array | yes | no
execle | list | no | no
execve | array | no | no
execlp | list | yes | yes
execvp | array | yes | yes

When the process issues any exec call, if the call is successful, the existing process is overlaid with a new set of program code.  Otherwise the exec function returns.

```c
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
void main(int argc, char *argv[]) {
    if(argc > 1){
        execlp("bin/cat", "cat", argv[1], (char *)NULL); 
        perror("exec failure"); 
        exit(1); 
    }
    printf("\n Usage: is text_file\n", *argv); 
    exit(1); 
} 
```

1. Fix any errors and compile the above program into an executable named `exec1.out`.  This program can be used to display the contents of your C source file or some other file i.e. if the above source code is entered into a file named `exec1.c` then the command to output the contents of this file would be `./exec1.out exec1.c`.

2. Replace `cat` with another command like `ls`

3. Replace contents of the main function with:

```c
if(argc > 1){
execvp(argv[1], &argv[1]);
perror("exec failure"); 
exit(1); 
}
printf("\n Usage: %s <bash command>\n", *argv);
exit(1); 
```

Compile, run, experiment with different commands.

4. Replace contents of main function with:

```c
static char *new_argv[] = ("cat", "text_file.txt", (char *)NULL);
execvp("/bin/cat", new_argv);
perror("exec failure\n"); 
exit(1); 
```

Compile, run, and observe the results.  Experiment with other commands.

5. Create a C program where:
+ If the argument equals 1 then your program creates a folder named STUFF.
+ If the argument equals 2 then your program displays the contents of a file named stuff.txt.
+ If an incorrect number of arguments is entered or an invalid option is entered then display an error message.
*NOTE:  stuff.txt must exist in the same directory as your program.*

Run the following executable. The program should work identically to the demo.
```
./demo.out
```
