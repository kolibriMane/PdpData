FLAGS = -std=c++11
COMPILER = g++

main: main.cpp iterator.cpp vector.cpp
	${COMPILER} main.cpp ${FLAGS} -o main

.PHONY: clean
clean:
	rm -rf main

.PHONY: run
run:
	./main
