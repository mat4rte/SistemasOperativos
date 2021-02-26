#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define MAXBUFFER 1

int main(int argc, char *argv[])
{
    int fdS, fdD;
    ssize_t res;
    char buffer[MAXBUFFER];

    fdS = open(argv[1], O_RDONLY, 0600);

    if(fdS == -1){
        perror("open:");
        return -1;
    }
    
    fdD = open(argv[2], O_CREAT | O_WRONLY, 0600);  

    while(res = read(fdS, &buffer, MAXBUFFER) != 0){
        write(fdD, &buffer,MAXBUFFER);
    }
    close(fdS);
    close(fdD);
    return 0;
}
