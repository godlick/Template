#include "common.h"
#include <signal.h>

void signal_handler(int signum)
{
	printf("recv SIGINT\n");
}

int main(void)
{
	signal(SIGINT, signal_handler);

	while(1)
		sleep(1);
	
	return 0;
}
