#include "common.h"
#include <pthread.h>

struct message{
	int num;
	char data[10][100];
}msg; /*定义线程间共享的一个全局的消息结构，初始消息num为0*/

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *func1(void *arg){
	while(1){
		pthread_mutex_lock(&lock);
		if(msg.num > 0){
			printf("in func1 msg.num:%d is %s\n", msg.num, msg.data[msg.num -1]);
			msg.num--;
		}
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
	return NULL;
}
void *func2(void *arg){
	while(1){
		pthread_mutex_lock(&lock);
		if(msg.num > 0){
			printf("in func2 msg.num:%d is %s\n", msg.num, msg.data[msg.num -1]);
			msg.num--;
		}
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
	return NULL;
}
void *func3(void *arg){
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(msg.num < 10){
			strcpy(msg.data[msg.num], "hello");
			msg.num++;
		}
		pthread_mutex_unlock(&lock);
		sleep(1);
	}

	return NULL;
}

int main(void){
	pthread_t tid1, tid2, tid3;

	pthread_create(&tid1, NULL, func1, NULL);
	//pthread_create(&tid2, NULL, func2, NULL);
	pthread_create(&tid3, NULL, func3, NULL);

	pthread_join(tid1, NULL);
	//pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);


	return 0;
}
