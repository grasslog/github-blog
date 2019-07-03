#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
//#include <stdlib.h>

sem_t empty, full;
pthread_mutex_t mutex;
int buffer_count = 0;
static int pd = 0;
static int con = 0;

void *producer(void *arg);
void *consumer(void *arg);

int main(int argc, char *argv[]){
	pthread_t thrd_prod, thrd_cons;

	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, 1);
	sem_init(&full, 0, 0);
	// create producer thread
	if(pthread_create(&thrd_prod, NULL, producer, NULL) != 0)
		printf("thrd_prod create failed.\n");
	//create consumer thread
	if(pthread_create(&thrd_cons, NULL, consumer, NULL) != 0)
		printf("thrd_cons create failed.");

	// join threads
	if(pthread_join(thrd_prod, NULL) != 0)
		printf("wait thread failed.");
	if(pthread_join(thrd_cons, NULL) != 0)
		printf("wait thread failed.");
	sem_destroy(&full);
	sem_destroy(&empty);
	pthread_mutex_destroy(&mutex);
}

void *producer(void *arg)
{
	while(1){
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		printf("produce task %d\n", pd);
		//system("time");
		//Sleep(1000);
		buffer_count++;
		pd++;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumer(void *arg)
{
	while(1){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		printf("consume task %d\n",con);
		//system("time");
		//Sleep(1000);
		buffer_count--;
		con++;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}
