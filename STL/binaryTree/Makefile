FLAGS = -std=c++11
COMPILER = g++
DIR = build

build: main.o
	${COMPILER} ${DIR}/main.o ${FLAGS} -o ${DIR}/build

main.o: main.cpp
	mkdir -p build
	${COMPILER} ${INCLUDES} main.cpp -c ${FLAGS} -o ${DIR}/main.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR}

.PHONY: run
run:
	./${DIR}/build