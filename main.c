#include <stdio.h>
#include <stdlib.h>
#include "include/ftp_client.h"

int main(int argc, char **argv)
{
    ftp_client_t *ftp = ftp_client_connect("localhost", 1337, "wilfreed", "jean");
    printf("fd -> %d\n", ftp->fd);
    printf("fd -> %s\n", ftp->host);
    printf("fd -> %s\n", ftp->user);
    printf("fd -> %s\n", ftp->password);
    printf("fd -> %d\n", ftp->port);

}
