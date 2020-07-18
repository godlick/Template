#include "common.h"
#include <signal.h>

void signal_handler(int signum)
{
	printf("recv SIGINT\n");
}

int main(void)
{
	struct sigaction act;
	act.sa_handler = signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);

	while(1)
		sleep(1);
	
	return 0;
}
