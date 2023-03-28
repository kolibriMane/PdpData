COMPILER = g++
DIR = build
FLAG = --std=c++11

build: main.o graph.o
	${COMPILER} ${FLAG} ${DIR}/main.o ${DIR}/graph.o -o ${DIR}/build

graph.o: graph.cpp
	${COMPILER} ${FLAG} graph.cpp -c -o ${DIR}/graph.o

main.o: main.cpp
	mkdir -p build
	${COMPILER} ${FLAG} main.cpp -c -o ${DIR}/main.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR} a.out

.PHONY: run
run:
	./${DIR}/build
