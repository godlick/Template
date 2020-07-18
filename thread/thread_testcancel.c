#include "common.h"
#include <pthread.h>

void *func(void *arg)
{
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	//pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

	while(1)
	{
		pthread_testcancel();
	}
	return 0;
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
