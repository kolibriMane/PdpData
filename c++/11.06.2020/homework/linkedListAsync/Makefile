FLAGS = -std=c++11 -pthread
COMPILER = g++
DIR = build
INCLUDES = -I./list -I./node

build: main.o list.o node.o
	${COMPILER} ${DIR}/main.o ${DIR}/list.o ${DIR}/node.o ${FLAGS} -o ${DIR}/build

main.o: main.cpp
	mkdir -p build
	${COMPILER} ${INCLUDES} main.cpp -c ${FLAGS} -o ${DIR}/main.o

list.o: list/list.cpp
	${COMPILER} -I./node list/list.cpp -c ${FLAGS} -o ${DIR}/list.o

node.o: node/node.cpp
	${COMPILER} ./node/node.cpp -c ${FLAGS} -o ${DIR}/node.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR}

.PHONY: run
run:
	./${DIR}/build
