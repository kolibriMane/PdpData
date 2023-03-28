%include "macros.inc"

section .bss
    digitSpace resb 100
    digitSpacePos resb 8
    printSpace resb 8

section .data
    string db "Invalid arguments",10,0
section .text
    global _start

_exit:
    print2 string
    exit
ret

_start:
    pop rax
    cmp rax, 3
    jne _exit
    mov r10, rax
    pop rsi
    dec r10

    pop rsi
    mov ecx, 4
    toInt rsi, rax
    push rax
    print rax


    pop r13
    pop rsi
    mov ecx, 4
    toInt rsi, rax
    push rax
    print rax
    pop rax

    add rax, r13
    print rax
exit