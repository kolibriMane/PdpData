%include "macro.inc"

section .bss
	digitSpace resb 100
	digitSpacePos resb 8

section .text
	global _start

_start:
	mov rax, 666
	print rax
	exit
