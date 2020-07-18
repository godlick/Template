#include "common.h"
#include <sys/ipc.h>
#include <sys/sem.h>
#include <signal.h>

int global;

union semun{
	int val; 
	struct semid_ds *buf; 
	unsigned short *array;
};

int set_semvalue(int id);
int del_semvalue(int id);
int sem_p(int id);
int sem_v(int id);

int main()
{
	int sem_id;
	
	key_t key;
	key = ftok(".", 123);
	
	sem_id = semget(key, 1, 0666|IPC_CREAT);
	if(sem_id == -1)
		err_sys("semget error");

	set_semvalue(sem_id);

	while(1)
	{
		sem_p(sem_id);
		printf("global is %d\n", global++);
		sem_v(sem_id);
		sleep(1);
	}

	del_semvalue(sem_id);
	return 0;
}

int set_semvalue(int id)
{
	int ret;
	union semun sem_union;
	
	sem_union.val = 1;
	ret = semctl(id, 0, SETVAL, sem_union);
	if(ret == -1)
		err_sys("semctl error");
	return 1;
}

int del_semvalue(int id)
{
	int ret;
	union semun sem_union;
	ret = semctl(id, 0, IPC_RMID, sem_union);
	if(ret == -1)
		err_sys("semctl error");
	return 1;
}

int sem_p(int id)
{
	int ret;
	struct sembuf sem_buf;
	sem_buf.sem_num = 0;
	sem_buf.sem_op = -1;
	sem_buf.sem_flg = SEM_UNDO;
	
	ret = semop(id, &sem_buf, 1);
	if(ret == -1)
	{
		err_ret("semop fail");
		return 0;
	}
	return 1;
}
int sem_v(int id)
{
	int ret;
	struct sembuf sem_buf;
	sem_buf.sem_num = 0;
	sem_buf.sem_op = 1;
	sem_buf.sem_flg = SEM_UNDO;
	
	ret = semop(id, &sem_buf, 1);
	if(ret == -1)
	{
		err_ret("semop fail");
		return 0;
	}
	return 1;
}

