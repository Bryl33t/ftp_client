#include <stdio.h>
#include <stdlib.h>
#include "include/ftp_client.h"

int main(int argc, char **argv)
{
    ftp_client_t *ftp = ftp_client_connect("127.0.0.1", 21, "test", "jean");
    char buffer[256];

    ftp_pwd(ftp, buffer, 256);    

    printf("%s\n", buffer);

    ftp_mkdir(ftp, "lol");
}
