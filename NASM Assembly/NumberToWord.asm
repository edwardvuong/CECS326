;Lab 2 -- NumberToWord
;Edward Vuong
;014191981

;writes a string given 2 arguments
%macro write_string 2
	;saving register contents on run-time stack
	push eax
	push ebx
	push ecx
	push edx

	;output string values
	mov eax, 4
	mov ebx, 1
	mov ecx, %1	;first parameter in macro usuage, label referring to message
	mov edx, %2	;second parameter, size of message in bytes
	int 0x80

	;register values restored from stack
	pop edx
	pop ecx
	pop ebx
	pop eax
%endmacro

%macro read_string 2
	;saving register contents on run-time stack
	push eax
	push ebx
	push ecx
	push edx

	;output string values
	mov eax, 3
	mov ebx, 2
	mov ecx, %1	;first parameter in macro usuage, label referring to message
	mov edx, %2	;second parameter, size of message in bytes
	int 0x80

	;register values restored from stack
	pop edx
	pop ecx
	pop ebx
	pop eax
%endmacro


;static data section
section .data
	Prompt1: db 'Please enter a number: '
	lenPrompt1: equ $-Prompt1

	crlf: db 0xA, 0xD
	lenCrlf: equ $-crlf

	num: db 0xFF

	showZero: db 'Zero'
	lenZero: equ $-showZero

	showOne: db 'One'
	lenOne: equ $-showOne

	showTwo: db 'Two'
	lenTwo: equ $-showTwo

	showThree: db 'Three'
	lenThree: equ $-showThree

	showFour: db 'Four'
	lenFour: equ $-showFour

	showFive: db 'Five'
	lenFive: equ $-showFive

	showSix: db 'Six'
	lenSix: equ $-showSix

	showSeven: db 'Seven'
	lenSeven: equ $-showSeven

	showEight: db 'Eight'
	lenEight: equ $-showEight

	showNine: db 'Nine'
	lenNine: equ $-showNine

	theEnd: db 'The End'
	lenTheEnd: equ $-theEnd


;program instrution code section
section .text
	global _start
	_start:
	write_string crlf, lenCrlf	;output carriage return and line feed
	write_string Prompt1, lenPrompt1;User Prompt1 -'Please enter a number: '
	read_string num, 1		;read and store 1-byte of the user input
	write_string crlf, lenCrlf	;output carriage return and line feed
	mov ah, [num]			;put recieved character in AH register
	
	cmp ah, '0'			;check if 0 was entered
	jne cmp1
		write_string showZero, lenZero
		jmp _start
cmp1: 
	cmp ah, '1'
	jne cmp2
		write_string showOne, lenOne
		jmp _start
cmp2: 
	cmp ah, '2'
	jne cmp3
		write_string showTwo, lenTwo
		jmp _start
cmp3: 
	cmp ah, '3'
	jne cmp4
		write_string showThree, lenThree
		jmp _start
cmp4: 
	cmp ah, '4'
	jne cmp5
		write_string showFour, lenFour
		jmp _start
cmp5: 
	cmp ah, '5'
	jne cmp6
		write_string showFive, lenFive
		jmp _start
cmp6: 
	cmp ah, '6'
	jne cmp7
		write_string showSix, lenSix
		jmp _start
cmp7: 
	cmp ah, '7'
	jne cmp8
		write_string showSeven, lenSeven
		jmp _start
cmp8: 
	cmp ah, '8'
	jne cmp9
		write_string showEight, lenEight
		jmp _start
cmp9: 
	cmp ah, '9'
	jne _default
		write_string showNine, lenNine
		jmp _start

_default:
	write_string theEnd, lenTheEnd	;show 'The End'
	write_string crlf, lenCrlf	;output carriage reutrn and line feed

	;Exit to operating system
	mov eax, 1
	mov ebx, 0
	int 0x80

