#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define MAXBUFFER 1

int main(){

    char byte;
    ssize_t res;

    while((res=read(0, &byte, 1) != 0)){
        write(1, &byte, res);
    }
    return 0;
}