#include "common.h"
#include <semaphore.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	
	if(pid < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		sleep(1);
		sem_t *sem = sem_open("tmp_sem", 0);
		sem_wait(sem);
		int i = 0;
		while(i++ < 5)
		{
			printf("in child\n");
			sleep(1);
		}
		sem_post(sem);
		sem_close(sem);
		sem_unlink("tmp_sem");
		exit(0);
	}
	else
	{
		sem_t *sem = sem_open("tmp_sem", O_CREAT, 0666, 1);
		sem_wait(sem);
		int i = 0;
		while(i++ < 5)
		{
			printf("in parent\n");
			sleep(1);
		}
		sem_post(sem);
		sem_close(sem);
		wait(NULL);
	}

	return 0;
}
