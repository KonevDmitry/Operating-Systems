#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB 1024*1024

int main(){
    for(int i = 0; i < 10; i++){
        int *arr = malloc(10*MB);
        memset(arr, 0, 10*MB);
        sleep(1);
    }
}

