#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include "../include/ftp_client.h"

void socket_init(ftp_client_t *init)
{
    WSADATA wsa;
    SOCKET s;
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    init->fd = s;
    if(init->fd < 0) {
        printf("Error socket !!!\n");
        exit(EXIT_FAILURE);
    }
    
}

void socket_connect(ftp_client_t *client)
{
    struct sockaddr_in sin;
    
    sin.sin_family = AF_INET;
    sin.sin_port = htons(client->port);
    sin.sin_addr.s_addr = inet_addr(client->host);

    int conn = connect(client->fd, (struct sockaddr *)&sin, sizeof(sin));
    if(conn < 0) {
        printf("Error connection !!!\n");
        exit(EXIT_FAILURE);
    }



}


ftp_client_t *ftp_client_connect(char *host, int port, char *password, char *username)
{
    ftp_client_t *client = malloc(sizeof(ftp_client_t));
    int res;
    char buffer[4096];

    // initialise structure ftp
    client->host = host;
    client->port = port;
    client->password = password;
    client->user = username;

    socket_init(client);
    socket_connect(client);
    send(client->fd, "HELP", 5, 0);
    recv(client->fd, buffer, 4096, 0);
    printf("%s\n", buffer);
    return (client);    

}

void ftp_mkdir(ftp_client_t *fd, char *folders)
{
    
}

