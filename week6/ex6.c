#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){
  int states[2];	
  pid_t child1,child2;
  child1 = fork();
  if(child1 == 0){
    pid_t sc_pid = -1;
    close(states[1]);
    read(states[0], &sc_pid, sizeof(pid_t));
    close(states[0]);
    printf("Got pid of 2nd child\n");
    printf("Killing the 2nd child (noooooo)\n");
    kill(sc_pid, SIGKILL);
  } 
  else {
    child2 = fork();
    if(child2 == 0){
       while(1)
       printf("2nd child is working\n");
    } 
    else {
    close(states[0]);
    write(states[1], &child2, sizeof(pid_t));
    close(states[1]);
    waitpid(child2, NULL, 0);
    return 0;
    } 
  }
}
