COMPILER = g++

run: clientServer.cpp
	${COMPILER} clientServer.cpp -o out

.PHONY : client
client: out
	./out client

.PHONY : server
server: out
	./out server

.PHONY : clean
	rm out
