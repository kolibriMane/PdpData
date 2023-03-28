STDIN equ 0

%macro exit 0
        mov rax, 60
        mov rdi, STDIN
        syscall
%endmacro

%macro printNumber 1
        mov rax, %1
        call _print
%endmacro

%macro printNumberSum 2
        mov rax, %1
        add rax, %2
        call _print
%endmacro
