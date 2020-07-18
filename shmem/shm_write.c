#include "common.h"
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFSIZE 2048

int main(void)
{
	int shmid;
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

	printf("copy data to share memory\n");
	bzero(shmaddr, BUFSIZE);
	strcpy(shmaddr, "data in share memory");
	return 0;

}
