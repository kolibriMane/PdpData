build: sum.o sum.asm macro.inc
	ld sum.o -o sum

sum.o:
	nasm -f elf64 -o sum.o sum.asm

.PHONY: run
run:
	./sum 8991 5677

.PHONY: clean
clean: 
	rm -rf sum.o sum
