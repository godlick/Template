#include "common.h"
#include <signal.h>

void signal_handler(int signum)
{
	printf("recv SIGALRM\n");
}

int main(void)
{
	pid_t pid;
	pid = fork();

	if(pid < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		sleep(5);
		kill(getppid(), SIGALRM);
		exit(0);
	}
	else
	{
		signal(SIGALRM, signal_handler);
		pause();
		exit(0);
	}
}
