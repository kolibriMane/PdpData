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

%macro print2 1
	mov rax, %1
	mov [printSpace], rax
	mov rbx, 0
%%printLoop:
	mov cl, [rax]
	cmp cl, 0
	je %%endPrintLoop
	inc rbx
	inc rax
	jmp %%printLoop

%%endPrintLoop:
	mov rax, 1
	mov rdi, 1
	mov rsi, [printSpace]
	mov rdx, rbx
	syscall
	%endmacro