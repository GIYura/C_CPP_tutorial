#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <unistd.h>

int main()
{
    // create a socket
    int netSocket;
    netSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(!netSocket){
        printf("Can't create socket\r\n");
    }

    // specify an address for the socket (connect to the remote server)
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int connStatus = connect(netSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(!connStatus){
        //printf("Can't connect to server\r\n");
    }

    // receive data form server
    char serverResponse[256];
    recv(netSocket, serverResponse, sizeof(serverResponse), 0);

    // print out the data from server
    printf("The server response: %s\r\n", serverResponse);

    // close the socket
    close(netSocket);

    return 0;
}
