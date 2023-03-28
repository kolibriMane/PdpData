COMPILER = g++
DIR = build

build: main.o func.o
	${COMPILER} ${DIR}/main.o ${DIR}/func.o -o ${DIR}/build

func.o: func.cpp
	${COMPILER} func.cpp -c -o ${DIR}/func.o

main.o: main.cpp
	mkdir -p build
	${COMPILER} main.cpp -c -o ${DIR}/main.o

.PHONY: clean
clean:
	rm -rf ${DIR}/*.o ${DIR}/build ${DIR} a.out

.PHONY: run
run:
	./${DIR}/build