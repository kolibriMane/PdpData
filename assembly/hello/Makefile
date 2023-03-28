build: hello.o helloWorld.asm
	ld hello.o -o hello

hello.o:
	nasm -f elf64 -o hello.o helloWorld.asm

.PHONY: run
run:
	./hello

.PHONY: clean
clean: 
	rm -rf hello.o hello
