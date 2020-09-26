#pragma once
#include <winsock2.h>

typedef struct ftp_client_t ftp_client_t;
typedef struct sys_socket_t sys_socket_t;

struct ftp_client_t {
    char *host;
    int port;
    char *user;
    char *password;
    int fd;
};


void socket_init(ftp_client_t *init);
ftp_client_t *ftp_client_connect(char *host, int port, char *password, char *username);
void ftp_mkdir(char *folders);
int socket_connect(ftp_client_t *client);



