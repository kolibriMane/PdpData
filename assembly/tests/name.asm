section .data
	question db "What is your name? "
	sentence db "Hello, "

section .bss
	name resb 20

section .text
	global _start

_start:
	call _printQuestion
	call _getName
	call _printSentence
	call _printName

	mov rax, 60
	mov rdi, 0
	syscall

_printQuestion:
	mov rax, 1
	mov rdi, 1
	mov rsi, question
	mov rdx, 19
	syscall
	ret

_printSentence:
	mov rax, 1
	mov rdi, 1
	mov rsi, sentence
	mov rdx, 7
	syscall
	ret

_printName:
	mov rax, 1
	mov rdi, 1
	mov rsi, name
	mov rdx, 20
	syscall
	ret

_getName:
	mov rax, 0
	mov rdi, 0
	mov rsi, name
	mov rdx, 20
	syscall
	ret
