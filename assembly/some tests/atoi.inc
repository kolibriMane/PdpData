%macro exit 0
        mov rax, 60
        mov rdi, 0
        syscall
        %endmacro

%macro atoi 0
        push r10
        mov rbx, 0

%%loop:
        inc r10
        inc rbx
        mov cl, [r10]
        cmp cl, 0
        jne %%loop

	pop r10

%%convert:
        mov cl, [r10]
        cmp cl, 48
        jl _exit

        cmp cl, 57
        jg _exit

        sub cl, 48
	mov r9, rbx
	mov rax, cl

%%getNum:
        mul rax, 10
	dec rbx
	cmp rbx, 0
	jne %%getNum

	dec r9
	inc [r10]
	cmp r9, 0
	jne %%convert
%endmacro
