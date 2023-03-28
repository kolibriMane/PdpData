COMPILER = g++
DIR = build
FLAG = --std=c++11

build: main.o possibleWays.o
	${COMPILER} ${DIR}/main.o ${DIR}/possibleWays.o -o ${DIR}/build

possibleWays.o: possibleWays.cpp
	${COMPILER} possibleWays.cpp -c -o ${DIR}/possibleWays.o

main.o: main.cpp
	mkdir -p build
	${COMPILER} main.cpp -c -o ${DIR}/main.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR} a.out

.PHONY: run
run:
	./${DIR}/build