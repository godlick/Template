#include "common.h"
#include <pthread.h>

int global;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *func1(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		printf("in func1 global = %d\n", global);
		global++;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return NULL;
}

void *func2(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		printf("in func2 global = %d\n", global);
		global++;
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	pthread_t tid1, tid2;
	//pthread_mutex_init(&mutex, NULL);

	pthread_create(&tid1, NULL, func1, NULL);
	pthread_create(&tid2, NULL, func2, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
