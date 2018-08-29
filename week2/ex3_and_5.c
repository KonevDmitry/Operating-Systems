#include <string.h>
#include <stdio.h>
int main(){
  char str[5];
  gets(str);
  int num;
  sscanf(str, "%d", &num);
  printf("Triangle from ex3: \n");
  ex3(num);
  printf ("rightangled_triangle:\n");
  rightangled_triangle(num);
  printf("triangle_with_two_equal_sides\n");
  triangle_with_two_equal_sides(num);
  printf("square\n");
  square(num);
  getch();
  return 0;
}
void ex3(int num){
    for(int i=1;i<=num;i++){
    for(int j=0;j<num-i;j++)
        printf(" ");
    for(int j=0;j<2*i-1;j++)
            printf("*");
    printf("\n");
  }
}
void rightangled_triangle(int *num){
    for(int i=1;i<=num;i++){
        for(int j=1;j<=i;j++)
          printf("*");
        printf("\n");
    }
    printf("\n");
}
void triangle_with_two_equal_sides(int num){
  for(int i=1;i<=num;i++){
    for(int j=0;j<i;j++)
            printf("*");
    printf("\n");
  }
  for(int i=0;i<=num/2;i++){
    for(int j=0;j<num/2+1-i;j++)
            printf("*");
    printf("\n");
  }
}
void square(int num){
for (int i=0;i<num;i++){
for(int j=0;j<num;j++)
    printf("*");
printf("\n");
}
}
