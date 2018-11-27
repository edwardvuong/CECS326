;Lab 1 -- ToLower
;Edward Vuong
;014191981


;static data section
section .data
	userMsg: db 'Please enter an uppecase letter: '
	userMsgLen: equ $-userMsg
	char: db 0xFF
	cr_lf db 0xA, 0xD
	outputMsg: db 'The entered letter in lowercase: '
	outputMsgLen: equ $-cr_lf

;program instrution code section
section .text
	GLOBAL _start

_start:
	;Prompt user for uppercase letter
	mov eax, 4
	mov ebx, 1
	mov ecx, userMsg
	mov edx, userMsgLen
	int 0x80

	;Obtain value from user
	mov eax, 3
	mov ebx, 2
	mov ecx, char 
	mov edx, 1
	int 0x80
	
	;Convert to lowercase
	mov al, [ecx]
	add al, 0x20
	mov [ecx], al

	;Output converstion prompt
	mov eax, 4
	mov ebx, 1
	mov ecx, cr_lf
	mov edx, outputMsgLen
	int 0x80

	;Output lowerchase letter
	mov eax, 4
	mov ebx, 1
	mov ecx, char
	mov edx, 2
	int 0x80

	;Exit with code 0
	mov eax, 1
	mov ebx, 0
	int 0x80


