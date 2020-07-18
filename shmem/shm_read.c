#include "common.h"
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFSIZE 2048

int main(void)
{
	int shmid;
	int ret;
	key_t key;
	char *shmaddr;

	key = ftok("./", 2016);
	if(key == -1)
		err_sys("ftok error");

	shmid = shmget(key, BUFSIZE, IPC_CREAT|0666);
	if(shmid < 0)
		err_sys("shmget error");
	
	shmaddr = shmat(shmid, NULL, 0);
	if(shmaddr < 0)
		err_sys("shmat error");
	
	printf("shmaddr:%p\n", shmaddr);
	printf("data = [%s]\n", shmaddr);

	ret = shmdt(shmaddr);
	if(ret < 0)
		err_sys("shmdt error");
	else
		printf("deleted share memory\n");

	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
