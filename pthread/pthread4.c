#include "common.h"
#include <pthread.h>

struct thread_arg
{
	void* (*pfun)(void*, void*, void*, void*);
	void *arg1;
	void *arg2;
	void *arg3;
	void *arg4;
};

static void* aa(void *tmp)
{
	struct thread_arg *p = (struct thread_arg*)tmp;
	(p->pfun)(p->arg1, p->arg2, p->arg3, p->arg4);
}

void *pthread4(pthread_t *pid,
	void* (*pfun)(void*, void*, void*, void*),
	void *a, void *b, void *c, void *d)
{
	struct thread_arg arg;
	arg.pfun = pfun;
	arg.arg1 = a;
	arg.arg2 = b;
	arg.arg3 = c;
	arg.arg4 = d;
	
	pthread_create(pid, NULL, aa, &arg);
	pthread_join(*pid, NULL);
}

void *test(void *a, void *b, void *c, void *d)
{
	printf("%d\n", *(int*)a);
	printf("%d\n", *(int*)b);
	printf("%s\n", *(char**)c);
	printf("%f\n", *(float*)d);
}

int main(void)
{
	pthread_t pid;
	int a = 1;
	int b = 2;
	char *s = "hello";
	float f = 3.14;
	pthread4(&pid, test, (void*)&a, (void*)&b, (void*)&s, (void*)&f);
	return 0;
}
















