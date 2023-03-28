COMPILER = g++
DIR = build

build: main.o matrix.o
	${COMPILER} ${DIR}/main.o ${DIR}/matrix.o -o ${DIR}/build

matrix.o: matrix.cpp
	${COMPILER} matrix.cpp -c -o ${DIR}/matrix.o

main.o: main.cpp
	mkdir -p build
	${COMPILER} main.cpp -c -o ${DIR}/main.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR} a.out

.PHONY: run
run:
	./${DIR}/build