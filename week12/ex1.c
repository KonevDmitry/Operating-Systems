#include <stdio.h>

int main() {
    FILE *f = fopen("/dev/random", "r");
    char random[21];
    fgets(random, 21, f);
    printf("%s", random);
    fflush(stdout);
    return 0;
}

