#include "common.h"
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct _msg
{
	long mtype;
	char mtext[100];
}MSG;

int main(void)
{
	key_t key;
	int msgid;
	MSG msg = {0};

	key = ftok(".", 2016);

	msgid = msgget(key, IPC_CREAT|0666);
	if(msgid == -1)
		err_sys("msgget error");

	while((msgrcv(msgid, &msg, sizeof(msg.mtext), 0, IPC_NOWAIT)) != -1 )
	{
		printf("msg.mtext:%s\n", msg.mtext);
	}

	if(msgctl(msgid, IPC_RMID, NULL) == -1)
		err_sys("msgctl error");

	return 0;
}
