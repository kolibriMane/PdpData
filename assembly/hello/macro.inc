%macro print 1
        mov rax, 1
        mov rdi, 1
        mov rsi, %1
        mov rdx, 14
        syscall
%endmacro

%macro exit 0
        mov rax, 60
        mov rdi, 0
        syscall
%endmacro
