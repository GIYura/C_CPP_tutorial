/*
*
HTTP Client
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <unistd.h>

int main(int argc, char* argv[])
{
    char* addr;
    addr = argv[1];

    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in remoteAddr;
    remoteAddr.sin_family = AF_INET;
    remoteAddr.sin_port = htons(8090);
    inet_aton(addr, &remoteAddr.sin_addr);

    connect(clientSocket, (struct sockaddr*) &remoteAddr, sizeof(remoteAddr));

    char request[] = "GET / HTTP/1.1\r\n\n\r\n";
    char response[4096];

    send(clientSocket, request, sizeof(request), 0);

    recv(clientSocket, &response, sizeof(response), 0);

    printf("response form the server: %s", response);

    close(clientSocket);

    return 0;
}
