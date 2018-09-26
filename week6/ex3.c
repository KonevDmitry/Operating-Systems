#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void sig_handler (int signo) {
     signal(SIGINT, sig_handler); 
     printf("No way :) \n"); 
     fflush(stdout); 
}
int main (void) {
	signal(SIGINT,sig_handler);
	while (1)
		sleep (10);
	return EXIT_SUCCESS;
}
