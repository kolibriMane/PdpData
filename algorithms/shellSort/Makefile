COMPILER = g++
DIR = build
FLAGS = --std=c++11

build: main.o sort.o
	${COMPILER} ${DIR}/main.o ${DIR}/sort.o -o ${DIR}/build

sort.o: sort.cpp
	${COMPILER} sort.cpp ${FLAGS} -c -o ${DIR}/sort.o

main.o: main.cpp
	mkdir -p build
	${COMPILER} main.cpp ${FLAGS} -c -o ${DIR}/main.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR}

.PHONY: run
run:
	./${DIR}/build
