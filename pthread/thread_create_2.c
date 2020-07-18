#include "common.h"
#include <pthread.h>

void *func1(void *arg)
{
	sleep(1);
	int value = (int)arg;
	printf("func1 arg = %d\n", value);

	return NULL;
}

void *func2(void *arg)
{
	sleep(1);
	int value = *((int *)arg);
	printf("func2 arg = %d\n", value);
	return NULL;
}

int main(void)
{
	pthread_t tid1, tid2;
	
	int test = 200;

	pthread_create(&tid1, NULL, func1, (void *)100);
	pthread_create(&tid2, NULL, func2, (void *)&test);
	while(1)
		sleep(1);
	return 0;
}



















