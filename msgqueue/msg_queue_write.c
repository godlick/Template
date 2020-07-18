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
	MSG msg;
	int i;

	key = ftok(".", 2016);
	msgid = msgget(key, IPC_CREAT|0666);
	if(msgid < 0)
		err_sys("msgget error");

	for(i = 1; i < 10; i++)
	{
		bzero(&msg, sizeof(msg));
		msg.mtype = i;
		sprintf(msg.mtext, "this is the %d msg\n", i);
		msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
	}
	return 0;
}
