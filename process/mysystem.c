#include "common.h"

int mysystem(const char *command)
{
	pid_t pid;
	int status;

	if(command == NULL)
		return 1;
	
	pid = fork();
	if(pid < 0)
		status = -1;
	else if(pid == 0)
	{
		execl("/bin/sh", "sh", "-c", command, (char*)0);
		exit(127); //正常情况不会执行到这一行
	}
	else
	{
		waitpid(pid, &status, 0);
		if(WIFEXITED(status) != 0)
			return WEXITSTATUS(status);
	}
}

int main(void)
{
	int ret = mysystem("ps -l");
	printf("ret:%d\n", ret);
}
