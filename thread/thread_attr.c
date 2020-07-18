#include "common.h"
#include <pthread.h>

int thread_finished = 0;

void *func(void *arg)
{
	printf("thread function running.\n");
	sleep(4);
	printf("thread function setting finished flag.\n");
	thread_finished = 1;
	pthread_exit(NULL);
}

int main()
{
	int ret = 0;
	pthread_t tid;
	pthread_attr_t attr;

	ret = pthread_attr_init(&attr);
	if(ret != 0)
		err_sys("pthread_attr_init error");

	ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(ret != 0)
		err_sys("pthread_attr_setdetachstate error");

	ret = pthread_create(&tid, &attr, func, NULL);
	if(ret != 0)
		err_sys("pthread_create error");

	pthread_attr_destroy(&attr);

	while(!thread_finished)
	{
		printf("waiting for thread to set finished flag...\n");
		sleep(1);
	}
	
	printf("child thread finished.\n");
	return 0;
}
