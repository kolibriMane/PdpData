build: print.o test.asm macro.inc
	ld print.o -o print

print.o:
	nasm -f elf64 -o print.o test.asm

.PHONY: run
run:
	./print

.PHONY: clean
clean: 
	rm -rf print.o print