#include "common.h"
#include <pthread.h>

struct message
{
	int num;
	char data[10][100];
}msg;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t ready = PTHREAD_COND_INITIALIZER;

void *func1(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		printf("func1 locked mutex\n");
		while(msg.num <= 0)
			pthread_cond_wait(&ready, &lock);
		
		printf("func1 wait done, msg.num = %d\n", msg.num);
		msg.num--;

		pthread_mutex_unlock(&lock);
	}
}

void *func3(void *arg)
{
	while(1)
	{
		sleep(1);
		pthread_mutex_lock(&lock);
		strcpy(msg.data[msg.num], "hello");
		msg.num++;
		pthread_cond_signal(&ready);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main(void)
{
	pthread_t tid1, tid3;
	
	pthread_create(&tid1, NULL, func1, NULL);
	pthread_create(&tid3, NULL, func3, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid3, NULL);

	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&ready);

	return 0;
}
