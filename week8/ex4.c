#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define MB 1024*1024

int main(){
    struct rusage* resource = malloc(sizeof(struct rusage));
    for(int i = 0; i < 10; i++){
        int *arr = malloc(10*MB);
        memset(arr, 0, 10*MB);
        getrusage(RUSAGE_SELF, resource);
        printf("now we have %ld MB\n",
        resource->ru_maxrss / 1024);
        sleep(1);
    }
}
