#include "common.h"
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int i = 0;

	while(++i < argc)
	{
		pid_t pid = fork();
		if(pid < 0)
			err_sys("fork error");
		else if(pid == 0)
		{
			sleep(atoi(argv[i]));
			printf("%d\n", atoi(argv[i]));
			exit(0);
		}
	}

	i = 0;
	while(++i < argc)
		wait(NULL);

	return 0;
}
