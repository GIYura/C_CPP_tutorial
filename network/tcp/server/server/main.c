#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <unistd.h>

int main()
{
    char serverMessage[] = "Welcome!!! Now you are connected to the server\r\n";

// create a socket.
    int serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = (in_port_t)htons(9090);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

// bind a name to a socket
    bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

// listen for connections on a socket
    listen(serverSocket, 10);
    puts("Waiting for connection");

    while (1) {
        int clientSocket = accept(serverSocket, NULL, NULL);
        send(clientSocket, serverMessage, strlen(serverMessage), 0);
        close(clientSocket);
}
return 0;
}
