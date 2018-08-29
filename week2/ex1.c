#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(void){
    printf("size of int:%d bytes ",sizeof(int));
    printf(" INT_MAX:%d\n ", INT_MAX);
    printf("Size of float:%d bytes",sizeof(float));
    printf(" MAX_FLOAT:%f\n ", FLT_MAX);
    printf("Size of double:%d bytes",sizeof(double));
    printf(" MAX_DOUBLE:%f\n ", DBL_MAX);
    getch();
    return 0;
}
