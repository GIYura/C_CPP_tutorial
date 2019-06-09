/*
*
HTTP server
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#include <unistd.h>

int main()
{
//open the file to send to the client and show this file in the browser
    FILE *htmlData = fopen("index.html", "r");
    if(NULL == htmlData){
        printf("Can't open file\n");
        return -1;
    }

//create a buffer to store data from file
    char responseData[1024];

//read the data fro file to send them to the client
    while(fgets(responseData, 1024, htmlData) != NULL);

    fclose(htmlData);
//create HTTP header
    char httpHeader[2048] = "HTTP/1.1 200 OK\r\n\n";

//combine HTTP header + server response
    strcat(httpHeader, responseData);

//create a socket (create an endpoint for communication)
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

//define the address of the server
    struct sockaddr_in serverAddr;

    memset((char *)&serverAddr, 0, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8090);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

//bind a name to a socket
    bind(serverSocket, (struct sockaddr*) &serverAddr, sizeof(serverAddr));

//start listening
    listen(serverSocket, 5);

    printf("Waiting for a connection...\n");

    int clientSocket;

    while(1){
        clientSocket = accept(serverSocket, NULL, NULL);
        send(clientSocket, httpHeader, sizeof(httpHeader), 0);
        close(clientSocket);
    }

    close(serverSocket);

    return 0;
}
