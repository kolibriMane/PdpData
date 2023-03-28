%include "macro.inc"

section .bss
    ;For print number
    digitSpace resb 100
    digitSpacePos resb 8
    ;For print string
    printSpace resb 8

section .data
    ;My error message
    string db "Invalid arguments!",10,0

section .text
    global _start

;Exit program if arguments are invalid
_exit:
    print2 string
    exit
ret

_start:
    ;Get count of arguments check is valid
    pop rax
    cmp rax, 3
    jne _exit
    mov r10, rax

    ;Delete from stack useless argument(filename)
    pop rsi
    dec r10

    ;Get first argument, convert to int, and print
    ; mov ecx, 8

    pop rsi
    mov ecx, FIRST
    toInt rsi, rax
    push rax
    print rax

    ;Get second argument, convert to int, and print
    pop r13
    pop rsi
    mov ecx, SECOND
    toInt rsi, rax
    push rax
    print rax
    pop rax

    ;Print sum of 2 arguments
    add rax, r13
    print rax
exit