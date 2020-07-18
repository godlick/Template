#include "common.h"

#include <sys/wait.h>

int main(void)
{
	int pid = vfork();

	if(pid < 0)
		err_sys("fork error");
	else if(pid == 0)
	{
		exit(0);
	}
	else
	{
		system("ps -l");
		exit(0);
	}

	return 0;
}
