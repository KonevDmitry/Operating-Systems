#include <stdio.h>
#include <time.h>
#include <pthread.h>
#define size 10
int count = 0;
char buffer[size];
pthread_mutex_t mutex;
pthread_cond_t cond_continue, cond_pause;

void *producer(void *data)
{
 while (1) {
  pthread_mutex_lock(&mutex);
  if (count == 1){
   pthread_cond_signal(&cond_continue);
   pthread_mutex_unlock(&mutex);
  }
  if (count == size)
   pthread_cond_wait(&cond_pause, &mutex);
  buffer[count] = 'p';
  count = count + 1;
 }
}

void *consumer(void *data){
 while (1) {
  pthread_mutex_lock(&mutex);
  if (count == 0)
    pthread_cond_wait(&cond_continue, &mutex);
  buffer[count] = 'c';
  count = count - 1;
  if (count == size-1){
   pthread_cond_signal(&cond_pause);
   pthread_mutex_unlock(&mutex);
  }
 }
}


int main(int argc, char const *argv[]){
 pthread_t prod, cons;
 pthread_mutex_init(&mutex, 0);

 pthread_cond_init(&cond_continue, 0);
 pthread_cond_init(&cond_pause, 0);

 pthread_create(&cons, 0, consumer, 0);
 pthread_create(&prod, 0, producer, 0);

 pthread_join(prod, 0);
 pthread_join(cons, 0);

 pthread_cond_destroy(&cond_continue);
 pthread_cond_destroy(&cond_pause);

 pthread_mutex_destroy(&mutex);
 return 0;
}
