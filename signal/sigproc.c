#include "common.h"
#include <signal.h>

int global;

void signal_handler(int signum)
{
	if(signum == SIGALRM)
	{
		global = 5;
	}
	else if(signum == SIGINT)
	{
		global = 0;
		sleep(10);
	}
}

int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		while(1)
		{
			sleep(3);
			kill(getppid(), SIGALRM);
		}
	}
	else
	{
		struct sigaction act;
		act.sa_handler = signal_handler;
		act.sa_flags = 0;
		sigemptyset(&act.sa_mask);
		sigaddset(&act.sa_mask, SIGALRM);
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGALRM, &act, NULL);

		while(1)
		{
			printf("global:%d\n", global);
			sleep(1);
		}
	}
}
