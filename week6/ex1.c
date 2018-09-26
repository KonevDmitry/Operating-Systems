#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int main()
{
   int states[2],bytes_number;
   pid_t child_pid;
   char first[]="Some string";
   char second[50];
   pipe(states);
    if(child_pid ==0)
      close(0);
   if(fork()!=0){
    close(states[0]);
    write(states[1],first,(strlen(first)+1));
    close(states[1]);
    }
 else{
   close(states[1]);
   bytes_number=read(states[0],second,sizeof(second));
   printf("Second string is: %s",second);
   close(states[0]);
    }
  return 0;
}
