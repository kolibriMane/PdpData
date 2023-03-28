build: print.o printNum.asm macro.inc
	ld print.o -o print

print.o:
	nasm -f elf64 -o print.o printNum.asm

.PHONY: run
run:
	./print

.PHONY: clean
clean: 
	rm -rf print.o print
