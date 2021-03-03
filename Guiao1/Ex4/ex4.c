#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXBUFFER 1000

ssize_t readln(int fd, char *line, ssize_t nbytes){

    ssize_t res = 0;
    int j = 0;
    char local[MAXBUFFER];

    while (res = read(fd, local, nbytes) > 0){

        for(int i = 0; i < res; i+=1){
            if (((char *) local)[i] != '\n'){
                line[j] = local[i];
                j+=1;
            }
            else{
                return j;
            }
            
        }
    
    }
    return j;
}

int main(int argc, char *argv[]){

    char buffer[MAXBUFFER];
    int fd1 = open(argv[1], O_RDONLY);
    ssize_t tam = (size_t) atoi(argv[2]);
    ssize_t result = readln(fd1, buffer, tam);
    printf("%s", buffer);

    return 0;
}