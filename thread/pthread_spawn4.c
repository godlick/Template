#include "common.h"
#include <pthread.h>
#include <errno.h>
typedef void *(*START_ROUTINE)(void *);
typedef void *(*pfunc_t)(void*, void*, void*, void*);

typedef struct 
{
	pfunc_t entry;
	void *arg[4];
}WRAPPER;

static void *threadWrapper2(void *arg)
{
	WRAPPER func = *((WRAPPER *)arg);	
	free((char *)arg);

	(*(func.entry))(func.arg[0], func.arg[1], func.arg[2], func.arg[3]);

	return NULL;
}

int pthread_spawn4(pthread_t *pid, pfunc_t funcptr, void *arg1, void *arg2, void *arg3, void *arg4)
{
	if(funcptr == NULL)
		return EINVAL;
	
	int ret = 0;
	START_ROUTINE start;
	WRAPPER *wrapper;
	
	wrapper = (WRAPPER *)malloc(sizeof(WRAPPER));
	if(wrapper == NULL)
		return ENOMEM;
	
	start = threadWrapper2;
	memset(wrapper, 0, sizeof(WRAPPER));
	wrapper->entry = funcptr;
	wrapper->arg[0] = arg1;
	wrapper->arg[1] = arg2;
	wrapper->arg[2] = arg3;
	wrapper->arg[3] = arg4;
	
	ret = pthread_create(pid, NULL, start, (void *)wrapper);
	if(ret != 0)
	{
		free(wrapper);
	}
	return ret;
}

void *test(void *arg1, void *arg2, void *arg3, void *arg4)
{
	printf("thread start\n");
	printf("arg1:%d\n", *((int*)arg1));
	printf("arg2:%s\n", *((char **)arg2));
	printf("arg3:%f\n", *((double*)arg3));
	printf("arg4:%s\n", (char *)arg4);
	
	return NULL;
}

int main()
{
	int a = 1;
	char *p = "hello world";
	double d = 3.14;
	char str[] = "hello string";
	
	pthread_t tid;
	pthread_spawn4(&tid, test, &a, &p, &d, &str);
	
	pthread_join(tid, NULL);
	return 0;
}
