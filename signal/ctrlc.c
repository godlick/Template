#include "common.h"
#include <signal.h>

void signal_handler(int signum)
{
	printf("recv SIGINT\n");
	signal(SIGINT, SIG_DFL);
}

int main(void)
{
	signal(SIGINT, signal_handler);

	while(1)
	{
		printf("hello world\n");
		sleep(1);
	}
	return 0;
}
