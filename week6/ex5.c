#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
pid_t child_pid;
void kill_it(int signal){
	kill(child_pid,SIGKILL);
}
int main(){
	signal(SIGALRM,(void (*)(int))kill_it);
	child_pid=fork();
	if(child_pid==-1)
			exit(1);
	if(child_pid==0){
			while(1)
						printf("I'm alive\n");
	}
	else{
			sleep(10);
				kill_it(getpid());

	}
	return 0;
}

