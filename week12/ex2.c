#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
int main(int argc, char* argv[]){
    FILE *f1,*f2;
    char data[20];
    f1 = stdin;
    if ((strcmp(argv[1], "-a"))==0)
         f2 = fopen(argv[2], "wa");
    else
       f2 = fopen(argv[1], "wa");
    int check;
    while(check=fread(data, 1, 20, f1)){
        fwrite(data, 1 ,check, stdout);
        fwrite(data, 1, check, f2);
    }
    fclose(f2);
}

