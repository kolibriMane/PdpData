COMPILER = g++
DIR = build

build: main.o fibon.o
	${COMPILER} ${DIR}/main.o ${DIR}/fibon.o -o ${DIR}/build

fibon.o: fibon.cpp
	${COMPILER} fibon.cpp -c -o ${DIR}/fibon.o

main.o: main.cpp
	mkdir -p build
	${COMPILER} main.cpp -c -o ${DIR}/main.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR} a.out

.PHONY: run
run:
	./${DIR}/build