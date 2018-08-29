#include <string.h>
#include <stdio.h>
int main(){
    printf("Write two integer numbers in one line\n");
    char str[99];
    gets(str);
    int num1,num2;
    sscanf(str, "%d" "%d", &num1,&num2);
    swap(num1,num2);
    getch();
    return 0;
}
void swap(int *num1,int *num2){
    int tmp=num1;
    num1=num2;
    num2=tmp;
    printf("Swapped: %d %d",num1,num2);
}
