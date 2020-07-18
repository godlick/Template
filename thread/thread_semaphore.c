#include "common.h"
#include <pthread.h>
#include <semaphore.h>
sem_t sem;

void *func1(void *arg)
{
	while(1)
	{
		sem_wait(&sem);
		int i = 0;
		while(i++ < 2)
		{
			printf("in func1\n");
			sleep(1);
		}
		sem_post(&sem);
		sleep(1);
	}
	return NULL;
}
void *func2(void *arg)
{
	while(1)
	{
		sem_wait(&sem);
		int i = 0;
		while(i++ < 2)
		{
			printf("in func2\n");
			sleep(1);
		}
		sem_post(&sem);
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	int ret = 0;
	pthread_t tid1, tid2;

	ret = sem_init(&sem, 0, 1);
	if(ret == -1)
		err_sys("sem_init failed");
	
	pthread_create(&tid1, NULL, func1, NULL);
	pthread_create(&tid2, NULL, func2, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	sem_destroy(&sem);
	
	return 0;
}



















