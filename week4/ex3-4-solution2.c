#include <stdio.h>
#include <stdlib.h>
int main(void) {
	char command[30];
        printf("enter command \n");
	fgets(command, 30, stdin);
	system(command);
        return 0; 
}
