build: print.o printLoop.asm
	ld print.o -o print

print.o:
	nasm -f elf64 -o print.o printLoop.asm

.PHONY: run
run:
	./print

.PHONY: clean
clean: 
	rm -rf print.o print
