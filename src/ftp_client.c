#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include "../include/ftp_client.h"
#define BUFFER_SIZE 1000
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

void ftp_login(ftp_client_t *client)
{
    char username[256];
    char password[256];

    char buffer[BUFFER_SIZE];

    strcpy(username, "USER ");
    strcat(username, client->user);
    strcat(username, "\r\n");

    strcpy(password, "PASS ");
    strcat(password, client->password);
    strcat(password, "\r\n");
    
    send(client->fd, username, strlen(username), 0);
    recv(client->fd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
    
    send(client->fd, password, strlen(password), 0);
    recv(client->fd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);
}


ftp_client_t *ftp_client_connect(char *host, int port, char *username, char *password)
{
    ftp_client_t *client = malloc(sizeof(ftp_client_t));
    int res;
    char buffer[BUFFER_SIZE];

    // initialise structure ftp
    client->host = host;
    client->port = port;
    client->password = password;
    client->user = username;

    socket_init(client);
    socket_connect(client);
    recv(client->fd, buffer, BUFFER_SIZE, 0);
    printf("%s\n", buffer);

    ftp_login(client);

    return (client);    

}

void ftp_pwd(ftp_client_t *client, char *buffer, int buffer_size)
{
    send(client->fd, "PWD\r\n", strlen("PWD\r\n"), 0);
    recv(client->fd, buffer, buffer_size, 0);
}



void ftp_mkdir(ftp_client_t *fd, char *folders)
{

    char folders_crlf[256];
    char buffer[BUFFER_SIZE];
    
    strcpy(folders_crlf, "MKD ");

    strcat(folders_crlf, folders);

    strcat(folders_crlf, "\r\n");

    send(fd->fd, folders_crlf, strlen(folders_crlf), 0);

    recv(fd->fd, buffer, BUFFER_SIZE, 0);

    printf("%s\n", buffer);
}

