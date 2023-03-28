%macro getName 1
        mov rax, 0
        mov rdi, 0
        mov rsi, %1
        mov rdx, 20
        syscall
%endmacro

%macro exit 0
        mov rax, 60
        mov rdi, 0
        syscall
%endmacro

%macro print 1
        push %1 ;set in stack
        mov rbx, 0 ;symbol count

%%loop:
        inc %1 ;increment by 1
        inc rbx ;increment by 1
        mov cl, [rax]
        cmp cl, 0 ;if not end of line
        jne %%loop

        ;print string
        mov %1, 1
        mov rdi, 1
        pop rsi ;get from stack
        mov rdx, rbx
        syscall
%endmacro
