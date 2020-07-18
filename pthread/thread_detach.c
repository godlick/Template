#include "common.h"
#include <pthread.h>

void *func(void *arg)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("thread running :%d\n", i);
		sleep(1);
	}
	return NULL;
}

int main()
{
	int ret = 0;
	pthread_t tid;

	ret = pthread_create(&tid, NULL, func, NULL);
	if(ret != 0)
		err_sys("pthread_create error");

	pthread_detach(tid);
	pthread_join(tid, NULL);
	printf("after join\n");
	sleep(3);
	printf("main thread leaving\n");
	return 0;
}
