#include "common.h"
#include <pthread.h>

volatile int a = 3;

void *test(void *tmp)
{
	int *p = (int *)tmp;
	while(1)
	{
		//printf("in test:%d\n", a);
		*p = *p + 1;
		sleep(1);
	}
}

int main(void)
{
	pthread_t pid;

	pthread_create(&pid, NULL, test, (void*)&a);
	pthread_detach(pid);

	while(1)
	{
		printf("in parent:%d\n", a);
		sleep(1);
	}
	return 0;
}
