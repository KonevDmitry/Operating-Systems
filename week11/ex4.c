#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd1 = open("ex1.txt", O_RDWR);
    int fdmemcpy = open("ex1.memcpy.txt", O_RDWR);
    struct stat stat1;
    struct stat statmemcpy;
    stat("ex1.txt", &stat1);
    stat("ex1.memcpy.txt", &statmemcpy);
    int size1 = stat1.st_size;
    int size2 = statmemcpy.st_size;
    char *map1 = mmap(NULL, size1, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);
    char *map2 = mmap(NULL, size2, PROT_READ | PROT_WRITE, MAP_SHARED, fdmemcpy, 0);
    memcpy(map2, map1, size1);
    msync(map2, size1, MS_SYNC);
    munmap(map1, size1);
    munmap(map2, size2);
    close(fd1);
    close(fdmemcpy);
    return 0;
}
