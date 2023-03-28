%include "atoi.inc"

section .text
	global _start

_start:
	pop rax
	mov r10, rax

_loop:
	pop rax
	atoi rax

	pop rax
	atoi rax

	
	print2 newLine
	dec r10
	cmp r10, 0
	jne _loop
	exit
