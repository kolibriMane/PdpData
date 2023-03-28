COMPILER = g++
DIR = build
INCLUDES = -I./queue -I./list -I./node

build: main.o list.o node.o queue.o
	${COMPILER} ${DIR}/main.o ${DIR}/node.o ${DIR}/list.o ${DIR}/queue.o -o ${DIR}/build

main.o: main.cpp
	mkdir -p build
	${COMPILER} ${INCLUDES} main.cpp -c -o ${DIR}/main.o

list.o: list/list.cpp
	${COMPILER}  -I./node list/list.cpp -c -o ${DIR}/list.o

queue.o: queue/queue.cpp
	${COMPILER} -I./list -I./node queue/queue.cpp -c -o ${DIR}/queue.o

node.o: node/node.cpp
	${COMPILER} node/node.cpp -c -o ${DIR}/node.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR}

.PHONY: run
run:
	./${DIR}/build
