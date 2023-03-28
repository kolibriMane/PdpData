%include "macro.inc"

section .data
    string db "What is your name? ",0
    answer db "Hello, ",0

section .bss
    name resb 20

section .text
    global _start

_start:
    mov rax, string
    print rax
    getName name
    mov rax, answer
    print rax
    mov rax, name
    print rax
    exit
