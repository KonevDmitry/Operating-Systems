#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void sig_handler (int signo) {
	switch(signo){
		case SIGKILL:
                 signal(SIGKILL,sig_handler);
		 printf("I got SIGKILL\n");
		 fflush(stdout);
		 break;
		case SIGSTOP:
	         signal(SIGSTOP,sig_handler);
		 printf("I got SIGSTOP\n");
		 fflush(stdout);
		 break;
	        case SIGUSR1:
	         signal(SIGUSR1,sig_handler);
		  printf("I got SIGUSR1\n");
		  fflush(stdout);
		  break;
		case SIGINT:
		signal(SIGINT,sig_handler);
	        printf("I got SIGINT\n");
		fflush(stdout);	
	         break;	 
}
}
int main (void) {
   printf("My pid is: %d\n", getpid());
   if(signal(SIGKILL,sig_handler)==SIG_IGN)
	   signal(SIGKILL,SIG_IGN);
   else if(signal(SIGSTOP,sig_handler)==SIG_IGN)
	    signal(SIGSTOP,SIG_IGN);
   else if(signal(SIGUSR1,sig_handler)==SIG_IGN)
	    signal(SIGUSR1,SIG_IGN);
   else if(signal(SIGINT,sig_handler)==SIG_IGN)
	    signal(SIGINT,SIG_IGN);
   while (1)
     sleep (10);
   return EXIT_SUCCESS;
   //output after using kill _USR1 <pid> is our printed message for SIGUSR1 case
}
