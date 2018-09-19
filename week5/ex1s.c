#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *my_thread(void * data){
printf("Hello from thread %d\n",(int) data);
}
int main()
{
    pthread_t thread_id;
    for (int i = 0; i < 10; i++){
        pthread_create(&thread_id, NULL, my_thread, (void*)i);
        pthread_join(thread_id, NULL);}
    return 0;
}
