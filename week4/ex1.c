#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int pid = fork();
	 if (pid > 0) 
		printf("Hello from parent [PID - %d]\n", pid);
         else if (pid == 0)  
		printf("Hello from child [PID - %d]\n", pid);
	 else 
        	 return EXIT_FAILURE;
return 0;
}
/*
 * output of program:
 * enter n for n-time unch
 * 10
 * Hello from parent [PID - 69]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 71]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 73]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 75]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 77]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 79]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 81]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 83]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 85]
 * Hello from child [PID - 0]
 * Hello from parent [PID - 87]
 * Hello from child [PID - 0]
 * it prints number of parent thread and children thread which is equal to 0
 * each time made +2 threads,because in ex1.c launches 2 threads at all
