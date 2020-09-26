#include <stdio.h>
#include <stdlib.h>
#include "include/ftp_client.h"

int main(int argc, char **argv)
{
    ftp_client_t *ftp = ftp_client_connect("127.0.0.1", 21, "wilfreed", "jean");
    printf("fd -> %d\n", ftp->fd);
    printf("host -> %s\n", ftp->host);
    printf("user -> %s\n", ftp->user);
    printf("pass -> %s\n", ftp->password);
    printf("port -> %d\n", ftp->port);

}
