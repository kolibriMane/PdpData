%include "macro.inc"

section .data
	digit db 0,10

section .text
	global _start


_start:
	printNumber 7
	printNumber 6
	printNumber 4
	printNumberSum 2, 3
	exit

_print:
	add rax, 48 ;asci code add
	mov [digit], al ;8 bites from rax
	mov rax, 1
	mov rdi, 1
	mov rsi, digit
	mov rdx, 2
	syscall
	ret

