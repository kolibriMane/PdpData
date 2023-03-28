FLAGS = -std=c++11
COMPILER = g++

build: main.o
	${COMPILER} main.o ${FLAGS} -o main

main.o: main.cpp
	${COMPILER} main.cpp -c ${FLAGS} -o main.o

.PHONY: clean
clean:
	rm -rf main.o main

.PHONY: run
run:
	./main
