# Number to Word
Due: September 11, 2018</br>

+ Write a NASM program that will read a single character through standard input and if the character is a single digit number then the word for that number will be displayed in standard output. 
+ The program will keep asking for a number until a non-numeric character is received through standard input in which case the program prints The End and terminates.

Sample program run:
```
Please enter a number: 4 
Four 
Please enter a number: 8 
Eight 
Please enter a number: 0 
Zero 
Please enter a number: ! 
The End sh-4.2$ 
```

The C code that is shown below demonstrates how the program will be structured:
```c
#include <stdio.h>

char num = Oxff;

    int main(1){
        while(1){
            printf("\nPlease enter a number: ");
            num = getchar();
            printf("\n");
            switch(num){
                case 'O': printf("Zero");break;
                case '1': printf("One"); break;
                case '2': printf("Two"); break;
                case '3': printf("Three"); break;
                case '4': printf("Four"); break;
                case '5': printf("Five"); break;
                case '6': printf("Six"); break;
                case '7': printf("Seven"); break;
                case '8': printf("Eight"); break;
                case '9': printf("Nine"); break;
                default: printf("The End\n"); return 0;
            }
        }
}
```

A sample portion of how the main program section can be created is shown below for your reference:
```nasm
;;;;;;;;;;;;;;;;;;;;;;;;;;; TEXT SEGMENT ;;;;;;;;;;;;;;;;;;;;;;;;;;;
section .text 
    global _start 
    start: write_string crlf, lencrlf   ;Output carriage return and line feed 
    write_string Promptl, lenPromptl    ;User Promptl - 'Please enter a number: ' 
    read_string num, 1                  ;Read and store 1-byte of the user input 
    write_string crlf, lencrlf          ;Output carriage return and line feed 
    mov ah, [num]                       ;Put received character in All register 

    cmp ah, '0'                         ;Check if 0 was entered 
    jne cmpl                            ;If not 0 then go to check if 1 was entered 
        write_string showZero, lenZero  ;Display 'Zero' 
        jmp _start                      ;restart program
cmp1:
    cmp ah, '1'
    jne cmp2
        write_string showOne, lenOne
        jmp _start
    
    jmp _start showOne, lenOne 
    
cmp2: 
    ;...
    ;Fill in missing code to check for digit 2,3,4,5,6,7,8,9 
    ;...
    
_default: 
    write_string theend, lentheend     ;Show 'The End' 
    write_string crlf, lencrlf         ;Output carriage return and line feed 

    ;Exit to operating system 
    mov eax, 1
    mov ebx, 0 
    int Ox8O 
;;;;;;;;;;;;;;;;;;;;;;;;;;; END OF PROGRAM ;;;;;;;;;;;;;;;;;;;;;;;;;;;
```
