#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXBUFFER 1000

ssize_t readln(int fd, char *line, size_t size){

    ssize_t res = 0;
    ssize_t i = 0;

    while (res = read(fd, &line[i], size) > 0 &&  (char*) line[i] != '\n'){  
        i += res;
    }
    
    return i;

}

int main(int argc, char *argv[]){

    char buffer[100];
    int fd1 = open(argv[1], O_RDONLY);

    ssize_t result = readln(fd1, buffer, result);
    
    write(1, buffer, result);

    close(fd1);
}
