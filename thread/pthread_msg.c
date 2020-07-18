#include "common.h"
#include <pthread.h>

struct message{
	int num;
	char data[10][100];
}msg;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;

void *func1(void *arg){
	while(1){
		pthread_mutex_lock(&lock);
		printf("func1 before\n");
		pthread_cond_wait(&cond, &lock);
		if(msg.num > 0){
			printf("in func1 msg.num:%d is %s\n", msg.num, msg.data[msg.num - 1]);
			msg.num--;
		}
		pthread_mutex_unlock(&lock);
	}
}

void *func2(void *arg){
	while(1){
		pthread_mutex_lock(&lock);
		printf("func2 before pthred_cond_wait\n");
		pthread_cond_wait(&cond, &lock);//解锁，睡眠
		if(msg.num > 0){
			printf("in func2 msg.num:%d is %s\n", msg.num, msg.data[msg.num - 1]);
			msg.num--;
		}
		pthread_mutex_unlock(&lock);
	}
}
void *func3(void *arg){
	while(1){
		int i = 0;
		pthread_mutex_lock(&lock);
		if(msg.num < 10){
			i++;
			fgets(msg.data[msg.num], 100, stdin);
			printf("write data\n");
			msg.num++;
		}
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&cond);
		sleep(5);
	}
}

int main(void)
{
	pthread_t tid1, tid2, tid3;

	pthread_create(&tid1, NULL, func1, NULL);
	pthread_create(&tid2, NULL, func2, NULL);
	pthread_create(&tid3, NULL, func3, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	return 0;
}
