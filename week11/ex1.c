#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
struct stat fileStat;
int file = open("ex1.txt", O_RDWR);
stat("ex1.txt", &fileStat);
off_t size = fileStat.st_size;
char * message = "This is a nice day";
char * ad = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
memcpy(ad, message, strlen(message));
return 0;
}
