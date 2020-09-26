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
    
}

int socket_connect(ftp_client_t *client)
{
    struct sockaddr_in sin;
    
    sin.sin_family = AF_INET;
    sin.sin_port = htons(1337);
    sin.sin_addr.s_addr = inet_addr("localhost");
    printf("%d\n", client->fd);

    return (connect(client->fd, (struct sockaddr *)&sin, sizeof(sin)));


}


ftp_client_t *ftp_client_connect(char *host, int port, char *password, char *username)
{
    ftp_client_t *client = malloc(sizeof(ftp_client_t));
    int res;

    // initialise structure ftp
    client->host = host;
    client->port = port;
    client->password = password;
    client->user = username;

    socket_init(client);
    res = socket_connect(client);
    printf("%d\n", res);
    return (client);    

}



