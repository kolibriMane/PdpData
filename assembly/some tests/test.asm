%include "macro.inc"

section .bss
	digitSpace resb 100
	digitSpacePos resb 8
	printSpace resb 8

section .data
	newLine db 10,0

section .text
	global _start

_start:
	pop rax
	mov r10, rax

_loop:
	pop r9
	print2 r9
	print2 newLine
	dec r10
	cmp r10, 0
	jne _loop
	exit
