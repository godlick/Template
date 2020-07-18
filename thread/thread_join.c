#include "common.h"
#include <pthread.h>

void *func(void *arg)
{
	static int num = 123;

	printf("after 2 seconds, thread will return\n");
	sleep(2);

	return &num;
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
