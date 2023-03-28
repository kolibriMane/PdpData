#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <netinet/in.h>
#include <cstdio>

#define PORT 60000
#define ADDR "127.0.0.1"
#define COUNT 6
#define BUFF 1024

bool isInvalidArgs(int, char**);
bool client();
bool server();

int main(int argc, char* argv[]) {
    if (isInvalidArgs(argc, argv)) {
        return -1;
    }

    if (0 == strcmp(argv[1], "client")) {
        std::cout << "Client run!" << std::endl;
        if (!client()) {
            std::cerr << "Something went wrong with client!" << std::endl;
            return -1;
        }
    } else {
        std::cout << "Server run!" << std::endl;
        if (!server()) {
            std::cerr << "Something went wrong with server!" << std::endl;
            return -1;
        }
    }

    return 0;
}

bool isInvalidArgs(int argc, char* argv[]) {
    if (2 != argc || (0 != strcmp(argv[1], "server") && 0 != strcmp(argv[1], "client"))) {
        std::cerr << "Not valid argument!" << std::endl;
        return true;
    }
    return false;
}

bool client() {
    /* Create socket and check if it created */
    int fileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (fileDescriptor < 0) {
        std::cerr << "Can't create socket !" << std::endl;
        return false;
    }

    /* Address, port */
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    /* Use all interfaces - not just localhost */
    address.sin_addr.s_addr = INADDR_ANY;

    /* Connect with server */
    if (0 > connect(fileDescriptor, (sockaddr*) &address, sizeof(address))) {
        std::cerr << "Connection failed!" << std::endl;
        return false;
    }

    std::string string = "";
    std::cout << "Enter file name to read in newFile: " << std::endl;
    getline(std::cin, string);
    char message[string.length() + 1];
    strcpy(message, string.c_str());
    send(fileDescriptor, message, strlen(message), 0);

    /* Open the new file in write mode, and put in that received message */
    std::ofstream newFile;
    newFile.open("newFile", std::ios::out | std::ios::binary);
    char buffer[BUFF];
    int readCount = read(fileDescriptor, buffer, BUFF);
    while (0 < readCount) {
        newFile.write(buffer, readCount);
        readCount = read(fileDescriptor, buffer, BUFF);
    }
    newFile.close();
    std::cout << "New file created!" << std::endl;
    return true;
}

bool server() {
    char* message = {'\0'};
    /* Create socket and check file descriptor */
    int fileDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (0 > fileDescriptor) {
        std::cerr << "Can't create socket!" << std::endl;
        return false;
    }

    /* Custom data structure for handling internet addresses */
    sockaddr_in address;
    /* Address, port */
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    /* Bind to all interfaces - not just localhost */
    address.sin_addr.s_addr = INADDR_ANY;
    /* Attach the socket to the address and port number- specified in address */
    if (0 > bind(fileDescriptor, (sockaddr*) &address, sizeof(address))) {
        std::cerr << "Failed to bind socket on port!" << std::endl;
        return -1;
    }

    /* Put the server socket in a passive mode, where it waits for the client to make a connection
        arguments:
         socket file descriptor
         maximum length of connections for socket
    */
    if (0 > listen(fileDescriptor, 6)) {
        std::cerr << "Server can't listen!";
        return false;
    }

    int addrlen = sizeof(address);
    /* Server accept a connection request from a client */
    int socketFileDesc = accept(fileDescriptor, (sockaddr*) &address, (socklen_t*) &addrlen);
    if (0 > socketFileDesc) {
        std::cerr << "Connection is not available!" << std::endl;
        return false;
    }

    char fileName[BUFF];
    int readCount = read(socketFileDesc, fileName, BUFF);
    char f[readCount];
    for (int i = 0; i < readCount + 1; ++i) {
        f[i] = fileName[i];
    }
    /* Try open file in read mode */
    std::ifstream file;
    file.open(f, std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Can't open file with received filename!" << std::endl;
        return false;
    }

    /* Send file to client and close it */
    char buffer[1024];
    int length = file.readsome(buffer, BUFF);
    while (0 < length) {
        send(socketFileDesc, buffer, strlen(buffer), 0);
        length = file.readsome(buffer, 1024);
    }
    file.close();

    return true;
}