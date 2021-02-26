#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define MAXBUFFER 1

int main(int argc, char *argv[])
{
    int fdS;
    ssize_t res;
    char buffer[MAXBUFFER];

    fdS = open(argv[1], O_RDONLY, 0600);

    if(fdS == -1){
        perror("open:");
        return -1;
    }

    while(res = read(fdS, &buffer, MAXBUFFER) != 0){
        write(1, &buffer,MAXBUFFER);
    }
    close(fdS);
    return 0;
}