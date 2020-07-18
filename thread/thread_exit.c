#include "common.h"
#include <pthread.h>

void *func(void *arg)
{
	static int test = 2;

	pthread_exit((void*)&test); // return (void*)&test;

	return NULL;
}

int main(void)
{
	pthread_t tid;
	int ret = 0;
	void *value = NULL;

	ret = pthread_create(&tid, NULL, func, NULL);
	if(ret != 0)
		err_sys("pthread_create error");

	pthread_join(tid, &value);
	
	printf("thread exit code = %d\n", *((int*)value));

	return 0;
}
