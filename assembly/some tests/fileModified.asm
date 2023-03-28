%macro exit 0
        mov rax, 60
        mov rdi, 0
        syscall
%endmacro

%macro print 1
    mov rcx, digitSpace
    mov rbx, 10
    mov [rcx], rbx
    inc rcx
    mov [digitSpacePos], rcx

%%printRaxLoop:
    mov rdx, 0
    mov rbx, 10
    div rbx
    push rax
    add rdx, 48

    mov rcx, [digitSpacePos]
    mov [rcx], dl
    inc rcx
    mov [digitSpacePos], rcx

    pop rax
    cmp rax, 0
    jne %%printRaxLoop

%%printRaxLoop2:
    mov rcx, [digitSpacePos]

    mov rax, 1
    mov rdi, 1
    mov rsi, rcx
    mov rdx, 1
    syscall

    mov rcx, [digitSpacePos]
    dec rcx
    mov [digitSpacePos], rcx

    cmp rcx, digitSpace
    jge %%printRaxLoop2
    %endmacro


%macro toInt 2
    mov rbx, 0
%%next_digit:
    movzx %2, byte[%1]
    inc %1
    sub al,'0'
    imul rbx, 10
    add rbx, %2
    loop %%next_digit
    mov %2, rbx
%endmacro

%macro numberSum 0
        mov r15, 3333
        print r15
        ; add r12, 7777
        ; print r12
%endmacro

section .bss
    digitSpace resb 100
    digitSpacePos resb 8
    printSpace resb 8

section .text
    global _start

_start:
    pop rax
    mov r10, rax
    pop rsi
    dec r10

    ; first number in rax
    pop rsi
    mov ecx, 4
    toInt rsi, rax

    ; second number in r11
    pop rsi
    mov ecx, 4
    toInt rsi, r11
    numberSum
exit