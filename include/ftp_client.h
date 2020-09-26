#pragma once
#include <winsock2.h>

typedef struct ftp_client_t ftp_client_t;

struct ftp_client_t {
    char *host;
    int port;
    char *user;
    char *password;
    int fd;
};


void socket_init(ftp_client_t *init);
ftp_client_t *ftp_client_connect(char *host, int port, char *username, char *password);
void ftp_mkdir(ftp_client_t *fd, char *folders);
void socket_connect(ftp_client_t *client);
void ftp_login(ftp_client_t *client);



