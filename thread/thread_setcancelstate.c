#include "common.h"
#include <pthread.h>

void *func(void *arg)
{
	//pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	while(1)
	{
		printf("this is thread_cancel\n");
		sleep(1);
	}
	return NULL;
}
int main(void)
{
	pthread_t tid;
	int ret = 0;

	ret = pthread_create(&tid, NULL, func, NULL);
	if(ret != 0)
		err_sys("pthread_create error");

	sleep(3);
	pthread_cancel(tid);
	pthread_join(tid, NULL);

	return 0;
}
