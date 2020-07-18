#include "common.h"
#include <pthread.h>

int var;

void *func1(void *arg)
{
	while(1)
	{
		printf("this is in func1 var++\n");
		var++;
		sleep(1);
	}

	return NULL;
}

void *func2(void *arg)
{
	while(1)
	{
		printf("this is in func2 var= %d\n", var);
		sleep(2);
	}
	return NULL;
}

int main(void)
{
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, func1, NULL);
	pthread_create(&tid2, NULL, func2, NULL);
	while(1)
		sleep(1);
	return 0;
}



















