#include "common.h"
#include <pthread.h>
void cleanup_func1(void *arg)
{
	printf("in cleanup func1\n");
	printf("clean up ptr = %s\n", (char *)arg);
	free((char *)arg);
}
void cleanup_func2(void *arg)
{
	printf("in cleanup func2\n");
}
void *thread(void *arg)
{
	char *ptr = NULL;
	/*建立线程清理程序*/
	printf("this is new thread\n");
	ptr = (char*)malloc(100);
	pthread_cleanup_push(cleanup_func1, (void*)(ptr));
	pthread_cleanup_push(cleanup_func2, NULL);
	
	bzero(ptr, 100);
	strcpy(ptr, "memory from malloc");
	
	/*注意push与pop必须配对使用，即使pop执行不到*/
	printf("before pop\n");
	pthread_cleanup_pop(0);
	printf("before pop\n");
	pthread_cleanup_pop(0);
	
	pthread_exit(NULL);
	return NULL;
}
int main(int argc, char *argv[])
{
	pthread_t tid;
	int ret = 0;
	ret = pthread_create(&tid, NULL, thread, NULL);
	if(ret != 0)
		err_sys("pthread_create error");
	pthread_join(tid, NULL);
	printf("process is dying\n");
	return 0;
}
