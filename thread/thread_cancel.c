#include "common.h"
#include <pthread.h>

void *test(void *tmp)
{
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
	
	while(1)
	{
		printf("a;dflajflkadj1\n");
		printf("adsfadfafafdfd2\n");
		//pthread_testcancel();
		printf("adfadfadfasdfafd3\n");
	}
	
	return NULL;
}

int main(void)
{
	pthread_t pid;
	
	pthread_create(&pid, NULL, test, NULL);
	sleep(1);
	
	pthread_cancel(pid);
	pthread_join(pid, NULL);
	
	return 0;
}
